package invasic.util.queue;

import invasic.util.CircularArray;
import octopos.Memory;
import x10.compiler.TLMAllocate;
import x10.util.ArrayList;
import x10.util.concurrent.Lock;

/**
 * Implementation of split deque after Dinan, Larkins, Sadayappan
 * Krishnamoorthy and Nieplocha.
 * See: https://dl.acm.org/citation.cfm?id=1654113
 * http://ieeexplore.ieee.org/xpl/login.jsp?reload=true&tp=&arnumber=4625897&url=http%3A%2F%2Fieeexplore.ieee.org%2Fxpls%2Fabs_all.jsp%3Farnumber%3D4625897
 */
public class SplitDeque[T] {T isref, T haszero} implements Deque[T] {

	private static val INITIAL_SIZE:Int = 5;
	private static val SHRINK = 20;
	private var deque:CircularArray[T] = new CircularArray[T](INITIAL_SIZE);

	private val lock = @TLMAllocate new Lock();
	private var split:Int = 0;
	private var head:Int = 0;
	private var nlocal:Int = 0;
	private val localStealPolicy:Int;
	private val remoteStealPolicy:Int;
	private var elementCount:Int = 0;
	private var stolen:Int = 0;
	private var sent:Int = 0;
	private var estimatedWaitingTime:Float = 0f;
	private var inactive:Boolean = false;

	/**
	 * Creates a new deque with the given local and remote stealing policies.
	 * Initializes the queue with the given work.
	 */
	public def this(localStealPolicy:Int, remoteStealPolicy:Int, initialWork:ArrayList[T]) {
		this.localStealPolicy = localStealPolicy;
		this.remoteStealPolicy = remoteStealPolicy;
		lock.lock();
		val array = deque;
		for(work in initialWork) {
			array.put(split++, work);
		}
		lock.unlock();
	}

	/**
	 * Creates a new deque with the given local and remote stealing policies
	 */
	public def this(localStealPolicy:Int, remoteStealPolicy:Int) {
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

	private def steal(stealPolicy:Int):ArrayList[T] {
		lock.lock();
		val h = head;
		val size = split - h;
		if(size <= 0)  {
			lock.unlock();
			return null;
		}
		val array = deque;
		val stolen = new ArrayList[T]();
		val steal = stealPolicy == 0 ? Math.max(size/2, 1) : Math.min(stealPolicy, size);
		for(var i:Int = h; i < h + steal; i++) {
			stolen.add(array.get(i));
		}
		val stolenSize = stolen.size();
		if(stolenSize > 0) {
			sent += stolenSize;
			head += stolenSize;
			lock.unlock();
			return stolen;
		}
		lock.unlock();
		return null;
	}

	/**
	 * Push the given element to the bottom of this deque.
	 * This must only be used by the 'owning' activity!
	 */
	public def pushBottom(value:T):void {
		val h = head;
		val t = split + nlocal;
		var array:CircularArray[T] = deque;
		val size = t - h;
	
		if(size >= array.size() - 1) {
			// double the size of the array
			lock.lock();
			array = array.grow(t, h);
			deque = array;
			lock.unlock();
		}
		array.put(t, value);
		nlocal++;
		perhapsRelease();
	}

	/**
	 * Pop the bottommost element of this deque.
	 * This must only be used by the 'owning' activity!
	 */
	public def popBottom() : T {
		do {
			val size = nlocal;
			if(size <= 0) {
				val reaquired = reaquire();
				if(!reaquired)
					return Zero.get[T]();
			} else {
				val t = split + size - 1;
				val value = deque.get(t);
				perhapsShrink(t, head);
				elementCount++;
				nlocal--;
				estimatedWaitingTime *= 0.8f;
				return value;
			}
		} while(true);
	}

	/**
	 * Steal all elements from this deque.
	 * This must only be used by the 'owning' activity!
	 */
	public def stealAll():ArrayList[T] {
		lock.lock();
		val h = head;
		val size = split - head + nlocal;
		if(size <= 0) {
			lock.unlock();
			return null;
		}
		val array = deque;
		val t = size + h;
		val stolen = new ArrayList[T]();
		for(var i:Int = t; i >= h; i--) {
			stolen.add(array.get(i));
		}
		val stolenSize = stolen.size();
		if(stolenSize > 0) {
			sent += stolenSize;
			nlocal = 0;
			split = head;
			lock.unlock();
			return stolen;
		}
		lock.unlock();
		return null;
	}

	/**
	 * Updates the estimated waiting time with the given measured time.
	 */
	public def updateWaitingTime(time:Float) {
		if(time < 0) return;
		estimatedWaitingTime = 0.8f * estimatedWaitingTime + 0.2f * time;
	}

	private def reaquire():Boolean {
		lock.lock();
		val npublic = split - head;
		inactive = false;
		if(npublic <= 0) {
			lock.unlock();
			return false;
		} else {
			val shift = npublic/2 + 1;
			split -= shift;
			nlocal += shift;
		}
		lock.unlock();
		return true;
	}

	private def perhapsRelease() {
		val barrier = localStealPolicy == 0 ? Int.MAX_VALUE : localStealPolicy;
		val local = nlocal;
		if(local > Math.max(localStealPolicy, 2) && (split - head) < barrier) {
			val shift = local/2;
			lock.lock();
			split += shift;
			nlocal -= shift;
			lock.unlock();
		}
	}

	private def perhapsShrink(t:Int, h:Int) {
		// shrink the array if it is less than 1/SHRINK populated
		val array = deque;
		if((t-h) < (array.size() / SHRINK)) {
			lock.lock();
			if((t-h) < (array.size() / SHRINK)) {
				val a = array.shrink(t, h);
				deque = a;
			}
			lock.unlock();
		}
	}

	/**
	 * Returns whether this deque is empty.
	 */
	public def isEmpty():Boolean {
		return nlocal + (split - head) <= 0;
	}

	/**
	 * Terminate this deque.
	 */
	public def terminate() {
		elementCount = 0;
		stolen = 0;
		sent = 0;
		head = 0;
		split = 0;
		nlocal = 0;
		estimatedWaitingTime = 0f;
	}

	/**
	 * Add the given stolen elements to the bottom of this deque.
	 * This must only be used by the 'owning' activity!
	 */
	public def stoleWork(work:ArrayList[T]):void {
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
	 * Returns the number of available jobs for stealing.
	 */
	public def getAvailableJobs():Int {
		return split - head;
	}

	/**
	 * Returns the estimated waiting time.
	 */
	public def getEstimatedWaitingTime():Float {
		return inactive ? 0f : estimatedWaitingTime;
	}

	/**
	 * Reset this deque for parallel reuse after a reinvade was done.
	 * This must only be used by the 'owning' activity!
	 */
	public def reset() {
		lock.lock();
		split += nlocal;
		nlocal = 0;
		inactive = true;
		lock.unlock();
	}

	/**
	 * Close this deque and free all TLM.
	 */
	public def close() {
		Memory.freeTLM(lock as Pointer);
	}

}
