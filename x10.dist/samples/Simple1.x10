class Simple1 {
	public static def getX(x : int, y : int) : int {
		var z : Boolean =  true;
		while(z) {
			var u: Boolean = false;
			do {
				if(true) { z = false; }
				else if(u) { z = true; }
				else { 
					z = false;
					var a: Boolean = true;
					while(a) {
						a = false;
					}
				}
			} while(u);
		}
		return x;

/*		var z: Boolean = x * y >= 666 && x * y != 44 || true != false; 
		if(1 == 2 || (2 != 6 && true == z) || 1 <= 4) {
			return y;
		}
		return x;
*/
/*
		var z: Int = 1 + 3;
		*/
	//	return 1;
	}
}
