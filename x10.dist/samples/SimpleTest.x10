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

		var a: Int = 1;
		var b: Int = 2;
		var c: Int = 3;

		lbl: do {
			lbl2: while(1 + 2 < 3) {
				c = c + 1;
				switch(c) { case 1: case 2: case 3: c = c + 3; default: b = b + 1; case 5: return 33; case 7: c = c -4; continue lbl2; case 9: switch(a + b) {
					case 3: continue lbl; case 5: a = a+ 3; break; case 2: continue lbl; case 6: break lbl; case 9: return 444; case 10: continue lbl2; 
					case 33: break lbl2; default: c = a + b;
				} }
				if(c + b < 2) break; 
			}
		} while(c - 5 < 55); 

		switch(a + b) {
			case 1: case 2: case 3: c = c + 3; case 7: b = b + 1;  switch(c + b) { case 1: c = c - 1; break; } 
			default: c = c + 1; 
		}

		switch(c) { case 1: case 2: case 3: c = c + 3; default: b = b + 1; case 5: return 33; case 7: c = c -4; case 8: b = b + 44; }

		return a + b + c;
	}
}
