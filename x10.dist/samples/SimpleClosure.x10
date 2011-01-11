import SimpleLib;

class SimpleClosure {
	/*
	def mF(val d: Float) {
		val closure = (var i: Float, val j: Float) => {
			SimpleLib.print(d);
		};
		return closure;
	}
	*/
	
	var b: Int = 2;
	var a: Int = 1;
	
	def mI(val d: Int) {
		val u: Int = this.b;
		val m: Int = 2;
		val closure = (val i: Int, val j: Int) => {
			val xxx: Int = u;
/*
			val closure2 = (val w: int, val e: Int) => {
				val a: Int = u;
				val b: Int = u + u + u + m;
				SimpleLib.print(666);
				return xxx + a + b + w + e;
			};
			closure2(xxx, a);
			val u : Int = a;
			a = 445;
*/
			return i + j + d + u + xxx + b + m;
		};
		return closure;
	}
	
	def u() {
		val closure = mI(3);
		val x  = closure(4,5);
		SimpleLib.print(x);
		SimpleLib.print(a);
/*		
		val closure2 = mF(33.f);
		closure2(33.04f, 223.f);
*/
	}

	/*
	public static def main(Array[String]) {
		val c = new SimpleClosure();
		c.u();
	}
	*/
	public static def m() {
		val c = new SimpleClosure();
		c.u();
	}
}
