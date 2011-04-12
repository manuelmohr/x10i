import SimpleLib;

struct Simple3(r: Double, theta: Double) {
	def this(r: Double, theta: Double) { property(r, theta); }

 	public static def main(Array[String]) : void {
		SimpleLib.print("START");
		for(var i: Int = 0; ; ) {
			SimpleLib.print(i);
			break;
		}

		SimpleLib.print("END");
	//	val x = Simple3(1.0, 2.0);
	}
}
