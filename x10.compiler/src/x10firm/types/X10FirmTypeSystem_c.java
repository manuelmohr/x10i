package x10firm.types;

import polyglot.types.Context;
import x10.types.X10TypeSystem_c;

public class X10FirmTypeSystem_c extends X10TypeSystem_c {
	public Context emptyContext() {
		return new X10FirmContext_c(this);
	}
}
