class Simple1 {
	public static def getX(x : int, y : int) : int {
/*		var z : Boolean =  true;
		while(z) {
			var u: Boolean = false;
			while(u) {
				if(true) { z = false; }
				else if(u) { z = true; }
				else { z = false; }
			}
		}
*/
		var z: Boolean = true;
		do {
			z = true;
		} while(z);
		return x;
	}
}
