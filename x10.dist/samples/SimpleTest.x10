class Simple1 {
	public static def m() {
		var x: Int = 33;
		var y: Int = 33333;
		var a: Int = 333322;
		var b: Int = 22222;
		var c: Int = 4442234;
/*			var z: Boolean = true;
			do {
				z = (1 < 3 && 5 - 4 == 12) ? ((3 * 4 == 12 || 5 - 3 != 3) ? 1 == 2 : 4 * 4 != 3) : true;
				return 123;
			} while(z);
  			//return 12333;
*/

		var z : Boolean = (1 < 3 && 5 - 4 == 12) ? ((3 * 4 == 12 || 5 + 3 != 3) ? 1 == 2 : 4 + 4 != 3) : true;
		if(z) {
			z = true;
		}
		
		while(z) {
			var u: Boolean = false;
			do {
				if(true) { z = false; }
				else if(u) { continue; }
				else { 
					z = false;
					var m: Boolean = true;
					while(m) {
						m = false;
						continue;
					}
				}
				
			} while(u);
			if(u == true) {
				continue;
			}
			u = z == true ? 2 + 3 < 30 : 666 - 333 != 333;
		}
		a = b = c = (x + y + 5 < 666 || a + b - c < 123) ? (z == true && a + b - c != 333) ? 23 + 4 : 555 - 4 : 333 + 333;

		var u: Int = (x + y == 666 && x + y != 44 || true != false) ? 1 : 0; 
		while(1 == 2 || (2 != 6 && true == z) || 1 < 4) {
			if((a + b + c - (z == true ? 1 : -2)) < 100) 
				continue;
			a = a + 1;
			b = b + 2;
			c = c + 3;
		}

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



		switch(c) { case 1: case 2: case 3: c = c + 3; default: b = b + 1; case 5: return 33; case 7: c = c - 4; case 8: b = b + 44; }

		return 1 + 3 + 4;
	}
	public var a : Int;
	public var b : Int;
	public var c : Int;
}
