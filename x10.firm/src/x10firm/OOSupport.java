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

	private static boolean nameSubstitutionsInitialized;

	private static void setupNameSubstitutions() {
		/* the following substitutions should be the same as in the C++ (itanium) ABI */
		OO.addNameSubstitution("operator~",   "co");
		OO.addNameSubstitution("operator+",   "pl");
		OO.addNameSubstitution("operator-",   "mi");
		OO.addNameSubstitution("operator*",   "ml");
		OO.addNameSubstitution("operator/",   "dv");
		OO.addNameSubstitution("operator%",   "rm");
		OO.addNameSubstitution("operator&",   "an");
		OO.addNameSubstitution("operator|",   "or");
		OO.addNameSubstitution("operator^",   "eo");
		OO.addNameSubstitution("operator=",   "aS");
		OO.addNameSubstitution("operator+=",  "pL");
		OO.addNameSubstitution("operator-=",  "mI");
		OO.addNameSubstitution("operator*=",  "mL");
		OO.addNameSubstitution("operator/=",  "dV");
		OO.addNameSubstitution("operator%=",  "rM");
		OO.addNameSubstitution("operator&=",  "aN");
		OO.addNameSubstitution("operator|=",  "oR");
		OO.addNameSubstitution("operator^=",  "eO");
		OO.addNameSubstitution("operator<<",  "ls");
		OO.addNameSubstitution("operator>>",  "rs");
		OO.addNameSubstitution("operator<<=", "lS");
		OO.addNameSubstitution("operator>>=", "rS");
		OO.addNameSubstitution("operator==",  "eq");
		OO.addNameSubstitution("operator!=",  "ne");
		OO.addNameSubstitution("operator<",   "lt");
		OO.addNameSubstitution("operator>",   "gt");
		OO.addNameSubstitution("operator<=",  "le");
		OO.addNameSubstitution("operator>=",  "ge");
		OO.addNameSubstitution("operator!",   "nt");
		OO.addNameSubstitution("operator&&",  "aa");
		OO.addNameSubstitution("operator||",  "oo");
		OO.addNameSubstitution("operator++",  "pp");
		OO.addNameSubstitution("operator--",  "mm");

		/* TODO: the following does not work as the spec requires the name of the type behind the 'cv' */
		OO.addNameSubstitution("operator_as", "cv");

		/* TODO: unary +, -
		 * The problem here is that we cannot identify them by name alone
		 * (it's still "operator+" in X10). */

		/* this is our addition */
		OO.addNameSubstitution("operator>>>", "v3rbs");

		/* constructor */
		OO.addNameSubstitution("this", "C1");
	}

	/** lowers object oriented constructs */
	public static void lowerOO(TypeSystem typeSystem) {
		/* setup primitives */
		typeSystem.setupNameMangler();

		if (!nameSubstitutionsInitialized) {
			setupNameSubstitutions();
			nameSubstitutionsInitialized = true;
		}

		OO.lowerProgram();
	}
}
