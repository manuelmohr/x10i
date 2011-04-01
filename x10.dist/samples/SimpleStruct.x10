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
		SimpleLib.print("Pair print start");
		SimpleLib.print(first);
		SimpleLib.print(second);
		SimpleLib.print("Pair print end");
		myTestPair.print();
	}

	public def print(x: Pair2) {
		SimpleLib.print("Pair print2 start");
		SimpleLib.print(x.first);
		SimpleLib.print(x.second);
		SimpleLib.print("Pair print2 end");
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
		SimpleLib.print("Pair2 print start");
		SimpleLib.print(first);
		SimpleLib.print(second);
		SimpleLib.print("Pair2 print end");
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
		SimpleLib.print("TestPair print start");
		SimpleLib.print(first);
		SimpleLib.print(second);
		SimpleLib.print("TestPair print end");
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

		SimpleLib.print("HelloWorld".length());

		val y: TestPair = x.copy(x);
		y.print();
		x.print(Pair2(123, 456));
		val z: SimpleStruct = new SimpleStruct();
		z.print(Pair(987, 654));
	}
}


