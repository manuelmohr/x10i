import SimpleLib;

class SimpleClosure {
	
	def mF(val d: Float) {
		val closure = (var i: Float, val j: Float) => {
			SimpleLib.print(42);
		};
		return closure;
	}
	
	
	def mI(val d: Int) {
		val closure = (val i: Int, val j: Int) => {
			val xxx: Int = 4;
			SimpleLib.print(5);

			val closure2 = (val w: int, val e: Int) => {
				val a: Int = 6;
				val b: Int = 7 + 8 + 9 + 10;
				SimpleLib.print(222);
				return 11 + 12 + b + w + e;
			};
			val ew = closure2(xxx, i + j);
			val u : Int = 13;
			return i + j + 14 + 15 + xxx + 16 + 17 + ew;
		};
		return closure;
	}
	
	public def start() {
		val closure1 = mI(1);
		SimpleLib.print(666);
		SimpleLib.print(closure1(2,3));
		SimpleLib.print(666);
	
		SimpleLib.print(111);
		val closure2 = mF(123.03f);
		closure2(1.0f, 2.0f);
		SimpleLib.print(111);
	}

	public static def main(Array[String]) : Void {
		val c = new SimpleClosure();
		c.start();
	}
}
