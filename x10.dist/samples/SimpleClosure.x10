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

	public var d : Int = 1;
	public var e : Int = 2;
	public var f : Int = 3;
	
	def mI(val hh: Int) {
		val g: Int = 4;
		val h: Int = 5;
		val closure = (val t: Int, val f: Int) => {
			val i: Int = 6;
			val j: Int = 7;
			SimpleLib.print(5);
			SimpleLib.print(d);
			SimpleLib.print(e);
			e = 44444;
			SimpleLib.print(f);
			val k: Int = 6;
			val closure2 = (val r: int, val s: Int) => {
				SimpleLib.print(999);
				SimpleLib.print(d);
				SimpleLib.print(e);
				e = 3234;
				SimpleLib.print(f);
				SimpleLib.print(999);
				return 1 + 3;
			};
			val ew = closure2(k, i + j);
			val u : Int = 13;
			SimpleLib.print(e);
			return i + j + d + 15 + k + 16 + 17 + 23;
		};
		return closure;
	}
	
	public def start() {
		val closure1 = mI(e);
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
