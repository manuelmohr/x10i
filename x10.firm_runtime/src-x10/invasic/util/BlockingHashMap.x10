package invasic.util;

import x10.util.Map;
import x10.util.Box;
import x10.util.Set;
import x10.util.HashMap;
import x10.util.concurrent.Lock;

/** A thread-safe hash map */
public class BlockingHashMap[K,V] implements Map[K,V] {
	private val data = new HashMap[K,V]();
	private val lock = new Lock();

	public def containsKey(k:K):boolean {
		try {
			this.lock.lock();
			return this.data.containsKey(k);
		} finally {
			this.lock.unlock();
		}
	}

	public def get(k:K):Box[V] {
		try {
			this.lock.lock();
			return this.data.get(k);
		} finally {
			this.lock.unlock();
		}
	}

	public def getOrElse(k:K, orelse:V):V {
		try {
			this.lock.lock();
			return this.data.getOrElse(k,orelse);
		} finally {
			this.lock.unlock();
		}
	}

	public def getOrThrow(k:K):V {
		try {
			this.lock.lock();
			return this.data.getOrThrow(k);
		} finally {
			this.lock.unlock();
		}
	}

	public def put(k:K, v:V):Box[V] {
		try {
			this.lock.lock();
			return this.data.put(k,v);
		} finally {
			this.lock.unlock();
		}
	}

	public def remove(k:K):Box[V] {
		try {
			this.lock.lock();
			return this.data.remove(k);
		} finally {
			this.lock.unlock();
		}
	}

	public def keySet():Set[K] {
		try {
			this.lock.lock();
			return this.data.keySet();
		} finally {
			this.lock.unlock();
		}
	}

	public def clear():void {
		try {
			this.lock.lock();
			this.data.clear();
		} finally {
			this.lock.unlock();
		}
	}

	public def entries():Set[Map.Entry[K,V]] {
		try {
			this.lock.lock();
			return this.data.entries();
		} finally {
			this.lock.unlock();
		}
	}

	public static def main(a:Array[String]) {
		val m = new BlockingHashMap[int,int]();
		m.put(5,11);
		m.put(6,42);
		val r1 = m.getOrElse(5,2);
		Console.OUT.println("r1: "+r1+" (11)");
		val r2 = m.getOrElse(2,2);
		Console.OUT.println("r2: "+r2+" (2)");
		m.remove(5);
		val r3 = m.getOrElse(5,2);
		Console.OUT.println("r3: "+r3+" (2)");
		val r4 = m.getOrElse(6,2);
		Console.OUT.println("r4: "+r4+" (42)");
	}
}
