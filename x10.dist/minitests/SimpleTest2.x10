import SimpleLib;

class SimpleTest2 {

	def this() {
		SimpleLib.print(123);
	}

	public def doItInst() {
		val x = null;
	}	

	public static def doIt(x: SimpleTest2) : void {
		SimpleLib.print(343);
		val y = staticObject;
		SimpleLib.print(staticInt);
		SimpleLib.print(342);
	}

 	public static def main(Array[String]) : void {
		SimpleLib.print(12331);		
		doIt(staticObject);		
		SimpleLib.print(4456);
		val x = staticObject;
		SimpleLib.print(4345);
		SimpleLib.print(staticInt);
		val y = staticObject;
		SimpleLib.print(1234);
	}

	public static staticNull = null;
	public static staticBoolean : Boolean = (1 > 43) ? true : false;
	public static staticInt : Long = 3443;
	public static staticObjectTmp = new SimpleTest2();
	public static staticObject = staticObjectTmp;
}