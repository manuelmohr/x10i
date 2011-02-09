import SimpleLib;

class Simple2 {

	def this() {
		SimpleLib.print(123);
	}

	public static def doIt(x: Simple2) : Void {
		SimpleLib.print(343);
		val y = staticObject;
		SimpleLib.print(staticInt);
		SimpleLib.print(342);
	}

 	public static def main(Array[String]) : Void {
		SimpleLib.print(12331);		
		doIt(staticObject);		
		SimpleLib.print(4456);
		val x = staticObject;
		SimpleLib.print(4345);
		SimpleLib.print(staticInt);
		val y = staticObject;
		SimpleLib.print(1234);
	}

	public static staticInt : Int = 123;
	public static staticObjectTmp = new Simple2();
	public static staticObject = staticObjectTmp;
}
