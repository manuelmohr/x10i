package invasic.util.queue;

import invasic.util.CircularArray;
import octopos.Memory;
import x10.util.concurrent.AtomicInteger;
import x10.util.ArrayList;
import x10.util.Box;
import x10.compiler.TLMAllocate;
import x10.compiler.Volatile;

/** 
 * Implementation of Dynamic Circular Work-Stealing Deque after Chase and Lev.
 * Modified to allow stealing of more than 1 element per steal and to use two different
 * stealing policies.
 * 
 * See: https://dl.acm.org/citation.cfm?id=1073974
 */
public class DynamicCircularWorkStealingDeque[T] {T isref, T haszero} implements Deque[T] {
	
	private static val INITIAL_SIZE:Int = 7;
	private static val SHRINK = 20;
	private @Volatile var deque:CircularArray[T] = new CircularArray[T](INITIAL_SIZE);
	
	private @Volatile var bottom:Int = 0;
	private val top = @TLMAllocate new AtomicInteger(0);
	private var stolen:Int = 0;
	private val sent = @TLMAllocate new AtomicInteger(0);
	private val localStealPolicy:Int;
	private val remoteStealPolicy:Int;
	private var elementCount:Int = 0;
	private @Volatile var finished:Boolean = false;
	private var estimatedWaitingTime:Float = 0f;
	
	/**
	 * Creates a new deque with the given local and remote stealing policies.
	 */
	public def this(val localStealPolicy:Int, val remoteStealPolicy:Int) {
		assert(localStealPolicy > 0);
		this.localStealPolicy = localStealPolicy;
		this.remoteStealPolicy = remoteStealPolicy;
	}
	
	/**
	 * Steal from this deque using the local stealing policy.
	 */
	public def localSteal():ArrayList[T] {
		return steal(localStealPolicy);
	}
	
	/**
	 * Steal from this deque using the remote stealing policy.
	 */
	public def remoteSteal():ArrayList[T] {
		return steal(remoteStealPolicy);
	}
	
	private def steal(val stealPolicy:Int):ArrayList[T] {
		val b = bottom;
		val t = top.get();
		val size = b - t;
		if(size <= 0) return null;
		val stolen = new ArrayList[T]();
		val steal = stealPolicy == 0 ? size/2 : (size > stealPolicy ? stealPolicy : size);
		for(var i:Int = 0; i < steal; i++) {
			val item = stealOne();
			if(item == Zero.get[T]()) {
				if(bottom - top.get() > 0) continue;
				break;
			}
			stolen.add(item);
		}
		if(stolen.size() > 0) {
			sent.addAndGet(stolen.size());
			return stolen;
		}
		return null;
	}
	
	private def stealOne():T {
		val b = bottom;
		val t = top.get();
		val array = deque;
		val size = b - t;
		if(size <= 0) return Zero.get[T]();
		val stolen = array.get(t);
		if(!top.compareAndSet(t, t + 1))
			return Zero.get[T]();
		return stolen;
	}

	/**
	 * Push the given element to the bottom of this deque.
	 * This must only be used by the 'owning' activity!
	 */
	public def pushBottom(val value:T):void {
		val b = bottom;
		val t = top.get();
		var array:CircularArray[T] = deque;
		val size = b - t;
		
		if(size >= array.size() - 1) {
			// double the size of the array
			array = array.grow(b, t);
			deque = array;
		}
		array.put(b, value);
		bottom = b + 1;
	}
	
	/**
	 * Pop the bottommost element of this deque.
	 * This must only be used by the 'owning' activity!
	 */
	public def popBottom() : T {
		var b:Int = bottom;
		val array = deque;
		b = b - 1;
		bottom = b;
		val t = top.get();
		val size = b - t;	
		if(size < 0) {
			bottom = t;
			finished = true;
			return Zero.get[T]();
		}
		val value = array.get(b);
		if(size > 0) {
			perhapsShrink(b, t);
			elementCount++;
			estimatedWaitingTime *= 0.8f;
			return value;
		}
		if(!top.compareAndSet(t, t + 1)) {
			bottom = t + 1;
			finished = true;
			return Zero.get[T]();
		}
		bottom = t + 1;
		elementCount++;
		estimatedWaitingTime *= 0.8f;
		return value;
	}
	
	/**
	 * Steal all elements from this deque.
	 */
	public def stealAll():ArrayList[T] {
		val t = top.get();
		val b = bottom;
		val size = b - t;
		if(size <= 0 && finished) return null;
		val stolen = new ArrayList[T]();
		while(!finished) {
			val item = stealOne();
			if(item == Zero.get[T]())
				continue;
			stolen.add(item);
		}
		if(stolen.size() > 0) {
			sent.addAndGet(stolen.size());
			return stolen;
		}
		return null;
	}
	
	/**
	 * Updates the estimated waiting time with the given measured time.
	 */
	public def updateWaitingTime(val time:Float) {
		estimatedWaitingTime = 0.8f * estimatedWaitingTime + 0.2f * time;
	}
	
	private def perhapsShrink(val b:Int, val t:Int) {
		// shrink the array if it is less than 1/SHRINK populated
		val array = deque;
		if((b-t) < (array.size() / SHRINK)) {
			val a = array.shrink(b, t);
			deque = a;
		}
	}
	
	/**
	 * Returns whether this deque is empty.
	 */
	public def isEmpty():Boolean {
		return bottom - top.get() <= 0;
	}
	
	/**
	 * Terminate this deque.
	 */
	public def terminate() {
		elementCount = 0;
		stolen = 0;
		sent.set(0);
	}

	/**
	 * Add the given stolen elements to the bottom of this deque. 
	 * This must only be used by the 'owning' activity!
	 */
	public def stoleWork(val work:ArrayList[T]):void {
		finished = false;
		stolen += work.size();
	    for(w in work) {
	    	pushBottom(w);
	    }
	}
	
	/**
	 * Returns the number of returned elements.
	 */
	public def getElementCount():Int {
		return elementCount;
	}
	
	/**
	 * Returns the estimated waiting time.
	 */
	public def getEstimatedWaitingTime():Float {
		return estimatedWaitingTime;
	}
	
	/**
	 * Reset this deque.
	 */
	public def reset() {}
	
	/**
	 * Close this deque and free all TLM.
	 */
	public def close() {
		Memory.freeTLM(top as Pointer);
		Memory.freeTLM(sent as Pointer);
	}

	/**
	 * Returns the number of available jobs for stealing.
	 */	public def getAvailableJobs():Int {
	    return bottom-top.get();
	}
}
