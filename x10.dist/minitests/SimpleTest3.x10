import SimpleLib;

struct Simple3(r: Double, theta: Double) {
	def this(r: Double, theta: Double) { property(r, theta); }

 	public static def main(Array[String]) : void {
		val x = Simple3(1.0, 2.0);
	}
}
