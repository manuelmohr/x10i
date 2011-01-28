import SimpleLib;


class Poly {
	public operator this + (var p: Poly) = new Poly(); 
	public operator (var n: Int) + this = new Poly();
	public operator + this = new Poly();
	public static operator (p: Poly) + (q: Poly) = new Poly();
	public static operator (c:Int) : Poly = new Poly();
	public static operator(var a:Int) as Poly = new Poly();
}

class PolyOverrider extends Poly {
	public operator this + (var p: PolyOverrider) = new Poly(); 
	public operator (var n: Int) + this = new Poly();
	public operator + this = new Poly();
	public static operator (p: Poly) + (q: Poly) = new Poly();
	public static operator (c:Int) : Poly = new Poly();
	public static operator(var a:Int) as Poly = new Poly();
}


abstract class Choice {
	def this() { }
	private def choose(b: Boolean) { if(b) this.yes(); else this.no(); }
	abstract def yes(): Void;
	abstract def no(): Void;
}

class Choice_c extends Choice {
	public def choose(b: Boolean) { if(b) this.yes(); else this.no(); }
	def yes(): Void = { }
	public def no(): Void  = { }
	def yes(a: Int) : Void = { }
}


class Simple1 {
	public def m(f: (Int) => Boolean, absent: Float): Int = {
		{ class MySimpleLocalClass { } }
		{ class MySimpleLocalClass { } }
		val c = new Choice() {
			def yes() { }
			def no() { }
		};
		val c2 = new Choice() {
			def yes() { }
			def no() { }
		};
		return 123;
	}

/*
	public static def m12() {
		var x: Int = 1;
		var y: Int = 2;
		var a: Int = 3;
		var b: Int = 4;
		var c: Int = 5;
		var z : Boolean = true;
		a = b = c = (x + y + 5 < 666 || a + b - c < 123) ? (z == true && a + b - c != 333) ? 23 + 4 : 555 - 4 : 333 + 333;

		while(z) {
			var u: Boolean = false;
			do {
				if(true) { z = false; }
				else if(u) { continue; }
				else { 
					z = false;
					var m: Boolean = true;
					while(m) {
						m = false;
						continue;
					}
				}
				
			} while(u);
			if(u == true) {
				continue;
			}
			u = z == true ? 2 + 3 < 30 : 666 - 333 != 333;
		}

		var u: Int = (x + y == 666 && x + y != 44 || true != false) ? 1 : 0; 
		while(1 == 2 || (2 != 6 && true == z) || 1 < 4) {
			if((a + b + c - (z == true ? 1 : -2)) < 100) 
				continue;
			a = a + 1;
			b = b + 2;
			c = c + 3;
		}

		lbl: do {
			lbl2: while(1  < 3) {
				c = c + 1;
				switch(c) { case 1: case 2: case 3: c = c + 3; default: b = b + 1; case 5: return 33; case 7: c = c -4; continue lbl2; case 9: switch(a + b) {
					case 3: continue lbl; case 5: a = a+ 3; break; case 2: continue lbl; case 6: break lbl; case 9: return 444; case 10: continue lbl2; 
					case 33: break lbl2; default: c = a + b;
				} }
				if(c + b < 2) break; 
			}
		} while(c - 5 < 55); 

		switch(c) { case 1: case 2: case 3: c = c + 3; default: b = b + 1; case 5: return 33; case 7: c = c - 4; case 8: b = b + 44; }
		return 2 + 3 +4;
	}
*/

 	public static def main(Array[String]) : Void {
		
	}

	public val a : Int = 1233;
	public var b : Int;
	public var c : Int;

}
