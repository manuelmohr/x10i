class Simple1 {
	public static def getX(x : int, y : int) : int {
			var z: Boolean = true;
			do {
				z = (1 < 3 && 5 - 4 == 12) ? ((3 * 4 == 12 || 5 - 3 != 3) ? 1 == 2 : 4 * 4 != 3) : true;
				return 123;
			} while(z);
  			//return 12333;
/*
		var z : Boolean = (1 < 3 && 5 - 4 == 12) ? ((3 * 4 == 12 || 5 - 3 != 3) ? 1 == 2 : 4 * 4 != 3) : true;
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
			do {
				return 123;
			} while(z);
		}

		var a: Int = 3;
		var b: Int = 3;
		var c: Int = 6;
		a = b = c = (x + y * 5 < 666 || a * b - c >= 123) ? (z == true && a / b - c != 333) ? 23 * 4 : 555 - 4 : 333 + 333;

		var u: Int = (x * y >= 666 && x * y != 44 || true != false) ? 1 : 0; 
		if(1 == 2 || (2 != 6 && true == z) || 1 <= 4) {
			return y;
		}
		return a * b * c - x * y;
*/

	}
}
