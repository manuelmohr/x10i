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
	}
}
