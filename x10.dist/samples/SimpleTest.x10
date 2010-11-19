class Simple1 {
	public static def getX(x : int, y : int) : int {
/*			var z: Boolean = true;
			do {
				z = (1 < 3 && 5 - 4 == 12) ? ((3 * 4 == 12 || 5 - 3 != 3) ? 1 == 2 : 4 * 4 != 3) : true;
				return 123;
			} while(z);
  			//return 12333;
*/
/*
		var z : Boolean = (1 < 3 && 5 - 4 == 12) ? ((3 * 4 == 12 || 5 + 3 != 3) ? 1 == 2 : 4 + 4 != 3) : true;
		
		while(z) {
			var u: Boolean = false;
			do {
				if(true) { z = false; }
				else if(u) { continue; }
				else { 
					z = false;
					var a: Boolean = true;
					while(a) {
						a = false;
						continue;
					}
				}
				
			} while(u);
			if(u == true) {
				continue;
			}
			u = z == true ? 2 + 3 < 30 : 666 - 333 != 333;
		}

		var a: Int = 3;
		var b: Int = 3;
		var c: Int = 6;
		a = b = c = (x + y + 5 < 666 || a + b - c < 123) ? (z == true && a + b - c != 333) ? 23 + 4 : 555 - 4 : 333 + 333;

		var u: Int = (x + y == 666 && x + y != 44 || true != false) ? 1 : 0; 
		while(1 == 2 || (2 != 6 && true == z) || 1 < 4) {
			if((a + b + c - (z == true ? 1 : -2)) < 100) 
				continue;
			a = a + 1;
			b = b + 2;
			c = c + 3;
		}
		
		return a + b + c - x - y;
*/
		var i: Int = 0;
		var j: Int = 0;
		lbl1 : do {
			 lbl2: while(j < 100) {
				if (i == 0) break lbl1;
				if (j == 1) continue lbl2;
				if (i == 4) break lbl2;
				if (j == 3) continue lbl1;
			}
		} while(i < 100);
		return 42;
	}
}
