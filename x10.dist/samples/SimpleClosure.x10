import SimpleLib;

struct Vector3(x:Double, y:Double, z:Double) {

        public def getX () = x; 
        public def getY () = y;
        public def getZ () = z;

	public def this(x:Double, y:Double, z:Double) {
		property(x,y,z);
	}

        public def add (other:Vector3) = Vector3(this.x+other.x, this.y+other.y, this.z+other.z);

        public def neg () = Vector3(-this.x, -this.y, -this.z);

        public def sub (other:Vector3) = add(other.neg());

        public def length () = length2();

        public def length2 () = x*x + y*y + z*z;

	public def print() {
		SimpleLib.print(666);
		SimpleLib.print(getX());
		SimpleLib.print(getY());
		SimpleLib.print(getZ());
		SimpleLib.print(length());
		SimpleLib.print(666);
	}
}

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

		}
	}
	
	public var d : Int = 1;
	public var e : Int = 2;
	public var f : Int = 3;
	public var zzz: Vector3 = Vector3(7.0, 8.0, 9.0);
	
	def mI(val hh: Int) {
		val g: Int = 4;
		val h: Int = 5;
		val xxx: Vector3 = Vector3(1.0, 2.0, 3.0);
		xxx.print();
		val yyy: Vector3 = Vector3(4.0, 5.0, 6.0);
		val closure = (val t: Int, val f: Int) => {
			val i: Int = 6;
			val j: Int = 7;
			SimpleLib.print(5);
			SimpleLib.print(d);
			SimpleLib.print(e);
			e = 44444;
			SimpleLib.print(f);
			SimpleLib.print(8888);
			xxx.print();
			yyy.print();
			SimpleLib.print(8888);
			val k: Int = 6;
			val closure2 = (val r: int, val s: Int) => {
				SimpleLib.print(999);
				SimpleLib.print(d);
				SimpleLib.print(e);
				val closure3 = (val xyz: Vector3, val s: Double) => {
					SimpleLib.print(222);					
					SimpleLib.print(d);
					SimpleLib.print(s);
					SimpleLib.print(f);
					val uu: Vector3 = xyz.neg();
					uu.print();
					(Vector3(1.0, 2.0, 3.0)).print();
					return 6.0;
				};
				e = 3234;
				SimpleLib.print(f);
				SimpleLib.print(g);
				SimpleLib.print(3333);
				SimpleLib.print(h);
				SimpleLib.print(3333);
				SimpleLib.print(999);
				xxx.print();
				zzz.print();
				SimpleLib.print(closure3(xxx, xxx.length2()));
				return 1 + 3;
			};
			val ew = closure2(k, i + j);
			val u : Int = 13;
			SimpleLib.print(123456);
			SimpleLib.print(e);
			
			return i + j + d + 15 + k + 16 + 17 + 23;
		};
		return closure;
	}

	public static uu : Int = 233;
	
	public def start() {
		SimpleLib.print("Hello");
		val closure1 = mI(e);
		SimpleLib.print(666);
		SimpleLib.print(closure1(2,3));
		SimpleLib.print(666);
	
		val x = new MySimpleClosureInner();
		x.doIt();
		SimpleLib.print(uu);
	}

	public static def main(Array[String]) : void {
		val c = new SimpleClosure();
		c.start();
	}
}
