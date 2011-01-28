package x10firm;

import x10firm.types.TypeSystem;
import firm.OO;

/**
 * helper class with functions for implementing object-orientation
 * specifics.
 * @author matze
 */
public final class OOSupport {
	private OOSupport() { }


	/** 
	 * lowers object oriented constructs 
	 */
	@SuppressWarnings("unused")
	public static void lowerOO(TypeSystem typeSystem) {
		OO.lowerProgram();
	}
}
