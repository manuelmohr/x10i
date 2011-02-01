import SimpleLib;

class SimpleClosure {
	/*
	class MySimpleClosureInner {
		class MySimpleClosureInner2 {
			def mF(val d: Float) {
				val closure = (var i: Float, val j: Float) => {
					SimpleLib.print(f);
				};
				return closure;
			}
		}
	}
	*/

	public val d : Int = 1;
	public var e : Int = 2;
	public var f : Int = 3;
	
	def mI(val d: Int) {
		val g: Int = 4;
		val h: Int = 5;
		val closure = (val i: Int, val j: Int) => {
			SimpleLib.print(5);
			SimpleLib.print(d);
			SimpleLib.print(e);
			SimpleLib.print(f);
			val k: Int = 6;
			val closure2 = (val r: int, val s: Int) => {
				SimpleLib.print(999);
				val a: Int = 6;
				val b: Int = 7 + s + r + 10;
				SimpleLib.print(e);
				SimpleLib.print(999);
				return f + 12 + d + r + e;
			};
			val ew = closure2(k, i + j);
			val u : Int = 13;

			return i + j + d + 15 + k + 16 + 17 + 23;
		};
		return closure;
	}
	
	public def start() {
		val closure1 = mI(1);
		SimpleLib.print(666);
		SimpleLib.print(closure1(2,3));
		SimpleLib.print(666);
	/*
		SimpleLib.print(111);
		val closure2 = mF(123.03f);
		closure2(1.0f, 2.0f);
		SimpleLib.print(111);
*/
	}

	public static def main(Array[String]) : Void {
		val c = new SimpleClosure();
		c.start();
	}
}
