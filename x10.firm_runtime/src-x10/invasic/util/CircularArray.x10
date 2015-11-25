package invasic.util;

import x10.util.IndexedMemoryChunk;

/**
 * Implementation of a circular array after Chase and Lev.
 */
public class CircularArray[T] {T haszero} {
	
	private val logSize:Int;
	private val segment:IndexedMemoryChunk[T];
	private val smallerArray:CircularArray[T];
	private var lowerWaterMark:Int = 0;
	
	private def this(val logSize:Int, val array:CircularArray[T]) {
		this.logSize = logSize;
		segment = IndexedMemoryChunk.allocateUninitialized[T](1 << logSize);
		this.smallerArray = array;
	}
	
	/**
	 * Create a new CircularArray with the given logarithmic size.
	 */
	public def this(val logSize:Int) {
		this(logSize, null);
	}
	
	/**
	 * Returns the size of this CircularArray.
	 */
	public def size() : Int {
		return 1 << logSize;
	}
	
	/**
	 * Returns the i's element.
	 */
	public def get(val i:Int) : T {
		return segment(i % size());
	}
	
	/**
	 * Puts the element value at the i's position.
	 */
	public def put(val i:Int, val value:T) {
		segment(i % size()) = value;
		lowerWaterMark = Math.min(lowerWaterMark, i);
	}
	
	/**
	 * Returns a new CircularArray twice the size of this and copies all values ranging from t to b.
	 */
	public def grow(val b:Int, val t:Int) : CircularArray[T] {
		val array = new CircularArray[T](logSize + 1, this);
		
		for(var i:Int = t; i < b; i++) {
			array.put(i, get(i));
		}
		return array;
	}
	
	/**
	 * Returns a CircularArray half the size of this and copies all values from t to b if necessary.
	 */
	public def shrink(val b:Int, val t:Int) {
		val array:CircularArray[T];
		if(smallerArray == null) {
			array = new CircularArray[T](logSize - 1);
			for(var i:Int = t; i < b; i++) {
				array.put(i, get(i));
			}		
		} else {
			array = smallerArray;
			for(var i:Int = lowerWaterMark; i < b; i++) {
				array.put(i, get(i));
			}
		}
		array.lowerWaterMark = Math.min(array.lowerWaterMark, lowerWaterMark);
		return array;
	}
}
