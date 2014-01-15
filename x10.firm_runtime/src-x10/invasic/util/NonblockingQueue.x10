package invasic.util;

import x10.compiler.TLMAllocate;

import x10.util.Container;
import x10.util.ArrayList;
import x10.util.Box;
import x10.util.concurrent.AtomicReference;

import invasic.util.Queue;

/** An unbounded queue for a parallel multi-producer multi-consumer scenario.
	Based on the non-blocking algorithm from
	<a href="http://dl.acm.org/citation.cfm?id=248106">Simple, Fast, and Practical Non-Blocking and Blocking Concurrent Queue Algorithms</a>.
	Due to the implementation of X10 Activities, starvation of producers can be a problem.
*/
public class NonblockingQueue[T] implements Queue[T] {
	private static class Cons[T] {
		public val nxt = @TLMAllocate new AtomicReference[Cons[T]]();
		public var value:Box[T] = null;
	}

	/* head always contains a dummy node */
	private val head = @TLMAllocate new AtomicReference[Cons[T]]();
	private val tail = @TLMAllocate new AtomicReference[Cons[T]]();

	/** Create an empty queue */
	public def this() {
		val node = new Cons[T]();
		this.head.set(node);
		this.tail.set(node);
	}

	/** Insert an element into the queue. Always returns true. */
	public def enqueue(data:T):boolean {
		val end = new Cons[T]();
		end.value = new Box[T](data);
		while (true) {
			val tl = this.tail.get();
			val cur = tl.nxt.get();
			if (cur != null) {
				/* obsolete tail, try update */
				this.tail.compareAndSet(tl,cur);
				continue;
			}
			if (tl.nxt.compareAndSet(null, end)) {
				/* Successfully enqueued new end node. */
				break;
			}
		}
		/* TODO try tail update? */
		return true;
	}

	/** Remove and return the head element of the queue, or null if empty */
	public def dequeue():Box[T] {
		while (true) {
			val dummy = this.head.get();
			val tl = this.tail.get();
			val nxt = dummy.nxt.get();
			if (dummy == tl) {
				if (nxt == null) { /* queue empty */
					return null;
				} else { /* tail is obsolete */
					this.tail.compareAndSet(tl,nxt);
				}
			} else {
				if (this.head.compareAndSet(dummy,nxt)) {
					return nxt.value;
				}
			}
		}
	}

	/** Return, but not remove, the head element of the queue, or null if empty */
	public def peek():Box[T] {
			val hd = this.head.get();
			val tl = this.tail.get();
			if (hd == tl) return null;
			val nxt = hd.nxt.get();
			if (nxt == null) return null;
			return nxt.value;
	}
}
