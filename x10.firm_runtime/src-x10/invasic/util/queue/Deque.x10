package invasic.util.queue;

import x10.util.ArrayList;

public interface Deque[T] {
	
	/**
	 * Steal from this deque using the local stealing policy.
	 */
	public def localSteal():ArrayList[T];
	
	/**
	 * Steal from this deque using the remote stealing policy.
	 */
	public def remoteSteal():ArrayList[T];
	
	/**
	 * Push the given element to the bottom of this deque.
	 * This must only be used by the 'owning' activity!
	 */
	public def pushBottom(T):void;
	
	/**
	 * Pop the bottommost element of this deque.
	 * This must only be used by the 'owning' activity!
	 */
	public def popBottom():T;
	
	/**
	 * Steal all elements from this deque.
	 * This must only be used by the 'owning' activity!
	 */
	public def stealAll():ArrayList[T];
	
	/**
	 * Add the given stolen elements to the bottom of this deque. 
	 * This must only be used by the 'owning' activity!
	 */
	public def stoleWork(work:ArrayList[T]):void;
	
	/**
	 * Terminate this deque.
	 */
	public def terminate():void;

	/**
	 * Returns if this queue is empty.
	 */
	public def isEmpty():Boolean;
	
	/**
	 * Returns the number of returned elements.
	 */
	public def getElementCount():Int;
	
	/**
	 * Returns the number of available jobs for stealing.
	 */
	public def getAvailableJobs():Int;
	
	/**
	 * Reset this deque for parallel reuse after a reinvade was done.
	 * This must only be used by the 'owning' activity!
	 */
	public def reset():void;
	
	/**
	 * Close this deque and free all TLM.
	 */
	public def close():void;
	
	/**
	 * Update this deque's estimated waiting time.
	 */
	public def updateWaitingTime(time:Float):void;
	
	/**
	 * Get this deque's estimated waiting time.
	 */
	public def getEstimatedWaitingTime():Float;
}
