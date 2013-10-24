package invasic.util;

import x10.util.Collection;
import x10.util.Container;
import x10.util.ArrayList;
import x10.util.Box;

/** A thread-safe (but not efficient) queue */
public interface Queue[T] {
	/** Inserts the specified element into this queue.
		Bounded queues might return false, if it fails. */
	def enqueue(e:T):boolean;

	/** Retrieves the (boxed) head of this queue, returning null if this queue is empty. */
	def dequeue():Box[T];

	/** Retrieves, but does not remove, the (boxed) head of this queue, returning null if this queue is empty. */
	def peek():Box[T];
}
