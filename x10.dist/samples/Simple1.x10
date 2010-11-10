class Simple1 {
	public static def getX(x : int, y : int) : int {
/*		var z : Boolean = (1 < 3 && 5 - 4 == 12) ? ((3 * 4 == 12 || 5 - 3 != 3) ? 1 == 2 : 4 * 4 != 3) : true;
		while(z) {
			var u: Boolean = false;
			do {
				if(true) { z = false; }
				else if(u) { return 4; }
				else { 
					z = false;
					var a: Boolean = true;
					while(a) {
						a = false;
						return 2;
					}
				}
			} while(u);
		}
*/
		var a: Int = 3;
		var b: Int = 3;
		a = b = 2 * 4;
		return a * b;
/*
		var u: Int = (x * y >= 666 && x * y != 44 || true != false) ? 1 : 0; 
		if(1 == 2 || (2 != 6 && true == z) || 1 <= 4) {
			return y;
		}
		return u;
*/

	}
}
