import SimpleLib;

struct Pair {
	public val myTestPair: TestPair = new TestPair(1,2);

	public val first: Int;
	public val second: Int;

	public def this(f: Int, s: Int) {
		first = f;
		second = s;
	}

	public def print() {
		SimpleLib.print(666);
		SimpleLib.print(first);
		SimpleLib.print(second);
		SimpleLib.print(666);
		myTestPair.print();
	}

	public def print(x: Pair2) {
		SimpleLib.print(555);
		SimpleLib.print(x.first);
		SimpleLib.print(x.second);
		SimpleLib.print(555);
	}

	public def copy(x: Pair) : TestPair {
		return new TestPair(123, 456);
	}
}

struct Pair2 {
	public val first: Int;
	public val second: Int;

	public def this(f: Int, s: Int) {
		first = f;
		second = s;
	}

	public def print() {
		SimpleLib.print(111);
		SimpleLib.print(first);
		SimpleLib.print(second);
		SimpleLib.print(111);
	}

	public def copy(x: Pair) {
		return Pair2(x.first, x.second);
	}
}

class TestPair {
	public var pair: Pair2 = Pair2(5,6);

	public val first: Int;
	public val second: Int;

	public def this(f: Int, s: Int) {
		first = f;
		second = s;
	}

	public def print() {
		SimpleLib.print(777);
		SimpleLib.print(first);
		SimpleLib.print(second);
		SimpleLib.print(777);
		pair.print();
	}
}

class SimpleStruct {

	public var pair: Pair = Pair(1,2);
	
	public def print(x: Pair) {
		x.print();
		pair = Pair(4,5);
		pair.print();
	}

	public static def main(Array[String]) : void {
		val x: Pair = Pair(8,9);
		x.print();

		val y: TestPair = x.copy(x);
		y.print();
		x.print(Pair2(123, 456));
		val z: SimpleStruct = new SimpleStruct();
		z.print(Pair(987, 654));
	}
}


