
interface VectorFace {
	public def print() : void;
	public def giveX() : Double;
	public def giveY() : Double;
	public def giveZ() : Double;
}


struct Vector3(x:Double, y:Double, z:Double) implements VectorFace {

        public def getX () = 1.0 + 2.0; 
        public def getY () = y;
        public def getZ () = z;

	public def giveX() = getX();
	public def giveY() = getY();
	public def giveZ() = getZ();

	public def this(x:Double, y:Double, z:Double) {
		property(x,y,z);
	}

	public def this(x: VectorFace, y: VectorFace, z: VectorFace) {
		property(x.giveX(), y.giveY(), z.giveZ());
	}

        public def add (other:Vector3) = Vector3(this.x+other.x, this.y+other.y, this.z+other.z);

        public def neg () = Vector3(-this.x, -this.y, -this.z);

        public def sub (other:Vector3) = add(other.neg());

        public def length () = length2();

        public def length2 () = x*x + y*y + z*z;

	public def print() {
		SimpleLib.print("Vector3 print start");
		SimpleLib.print(getX());
		SimpleLib.print(getY());
		SimpleLib.print(getZ());
		SimpleLib.print(length());
		SimpleLib.print("Vector3 print end");
	}
}

class Vector3Class(x:Double, y:Double, z:Double) implements VectorFace {

        public def getX () = x; 
        public def getY () = y;
        public def getZ () = z;

	public static myField: Vector3 = Vector3(1.0, 2.0, 3.0);

	public def giveX() = getX() + xxx.giveX();
	public def giveY() = getY() + xxx.giveY();
	public def giveZ() = getZ() + xxx.giveZ();

	xxx: Vector3 = Vector3(1.0, 2.0, 3.0);

	public def this(x:Double, y:Double, z:Double) {
		property(x,y,z);
	}

        public def add (other:Vector3) = new Vector3Class(this.x+other.x, this.y+other.y, this.z+other.z);

        public def neg () = new Vector3Class(-this.x, -this.y, -this.z);

        public def sub (other:Vector3) = add(other.neg());

        public def length () = length2();

        public def length2 () = x*x + y*y + z*z;

	public def print() {
		SimpleLib.print("Vector3Class print start");
		SimpleLib.print(getX());
		SimpleLib.print(getY());
		SimpleLib.print(getZ());
		SimpleLib.print(length());
		SimpleLib.print("Vector3Class print end");
	}
}

class SimpleStruct2 {

	public var vec: Vector3 = Vector3(1.0, 2.0, 3.0);

	public static def doAutoboxing(x: VectorFace) {
		SimpleLib.print(1233);
		x.print();
	}

	public static def giveVectorFace() : VectorFace {
		// autoboxing return value
		return Vector3(1.0, 2.0, 3.0);
	}

	public static def doIt(x: VectorFace) : VectorFace {
		// autoboxing parameter
		x.print();
		return Vector3(4.0, 5.0, 6.0);
	}

 	public static def main(Array[String]) : void {
		val vector  = Vector3(1.0, 2.0, 3.0);
		val vector2 = Vector3(vector.x, vector.y, vector.z);
		val vector3 = vector.add(vector2);

		var vv: VectorFace = null;
		var v2: Vector3 = Vector3(4.0, 5.0, 6.0);
		var v3: Vector3 = Vector3(6.0, 7.0, 8.0);
		var v4: Vector3 = Vector3(3.0, 4.0, 5.0);

		// assignment copying and autoboxing
		vv = v2 = v3 = v4;
		SimpleLib.print("Assignment autoboxing vv.print start");
		vv.print();
		SimpleLib.print("Assignment autoboxing vv.print end");
		SimpleLib.print("Assignment autoboxing v2.print start");
		v2.print();
		SimpleLib.print("Assignment autoboxing v2.print end");
		SimpleLib.print("Assignment autoboxing v3.print start");
		v3.print();
		SimpleLib.print("Assignment autoboxing v3 print end");
		SimpleLib.print("Assignment autoboxing v4.print start");
		v4.print();
		SimpleLib.print("Assignment autoboxing v4 print end");

		// constructor autoboxing
		val vector4 = Vector3(vector.sub(Vector3(3.0, 4.0, .5)), vector2.neg(), vector2.add(vector3));
		vector4.print();

		// primitive autoboxing
		val xx: Any = 123;
		
		val yyy: Char = 'A';
		val zzz: Char = 'b';

		if(yyy.compareTo(zzz) < 0) {
			SimpleLib.print("Kleiner");
		} else {
			SimpleLib.print("Groesser");
		}

		SimpleLib.print("Class assignment");
		val y: VectorFace = new Vector3Class(1.0, 2.0, 3.0);

		var u: VectorFace = null;
		// assign autoboxing
		u = Vector3(1.0, 2.0, 3.0);
		u.print();
		// local decl autoboxing
		val c: VectorFace = Vector3(4.0, 5.0, 6.0);

		c.print();
		// return value autoboxing
		val z: VectorFace = doIt(y);
		z.print();
		SimpleLib.print(456);

		// parameter autoboxing
		doAutoboxing(vector);

	}
}

