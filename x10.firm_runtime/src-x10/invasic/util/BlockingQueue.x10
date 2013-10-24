package invasic.util;

import x10.util.Container;
import x10.util.ArrayList;
import x10.util.Box;
import x10.util.concurrent.Lock;

import invasic.util.Queue;

/** An unbounded queue for a parallel multi-producer multi-consumer scenario.
	Based on the blocking algorithm from
	<a href="http://dl.acm.org/citation.cfm?id=248106">Simple, Fast, and Practical Non-Blocking and Blocking Concurrent Queue Algorithms</a>.
	In contrast to NonblockingQueue, this is livelock/starvation-free.
*/
public class BlockingQueue[T] implements Queue[T] {
	private static class Cons[T] {
		public var nxt:Cons[T] = null;
		public var value:Box[T] = null;
	}

	private var head:Cons[T];
	private var tail:Cons[T];
	private val head_lock = new Lock();
	private val tail_lock = new Lock();

	/** Create an empty queue */
	public def this() {
		val node = new Cons[T]();
		this.head = node;
		this.tail = node;
	}

	/** Insert an element into the queue. Always returns true. */
	public def enqueue(data:T):boolean {
		val end = new Cons[T]();
		val v = new Box[T](data);
		try {
			this.tail_lock.lock();
			val tl = this.tail;
			this.tail = end;
			tl.value = v;
			/* memory model?! fence? */
			tl.nxt = end; // makes it accessible to dequeue
		} finally {
			this.tail_lock.unlock();
		}
		return true;
	}

	/** Remove and return the head element of the queue, or null if empty */
	public def dequeue():Box[T] {
		var ret:Box[T] = null;
		try {
			this.head_lock.lock();
			val hd = this.head;
			val scnd = hd.nxt;
			if (scnd != null) { /* otherwise queue empty */
				this.head = scnd;
				ret = hd.value;
			}
		} finally {
			this.head_lock.unlock();
		}
		return ret;
	}

	/** Return, but not remove, the head element of the queue, or null if empty */
	public def peek():Box[T] {
		/* end node has null value */
		return this.head.value;
	}
}
