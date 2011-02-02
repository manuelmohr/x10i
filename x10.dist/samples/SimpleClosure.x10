import SimpleLib;

class SimpleClosure {
	
	class MySimpleClosureInner {
		public val d: Int = 344;
		public var e: Int = 123;
		class MySimpleClosureInner2 {
			def mF(val d: Float) {
				val closure = (var i: Float, val j: Float) => {
					SimpleLib.print(f);
					f = 7744422;
				};
				return closure;
			}
		}
		public def doIt() {
			SimpleLib.print(888);
			SimpleLib.print(f);
			SimpleLib.print(888);
			f = 555555;
			val y = new MySimpleClosureInner2();
			val closure = y.mF(123.034f);
			closure(1.03f, 42.42f);
			SimpleLib.print(f);
		}
	}
	
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
	
		val x = new MySimpleClosureInner();
		x.doIt();
	}

	public static def main(Array[String]) : Void {
		val c = new SimpleClosure();
		c.start();
	}
}
