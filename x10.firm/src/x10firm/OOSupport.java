package x10firm;

import x10firm.types.TypeSystem;
import firm.NameMangling;

/**
 * helper class with functions for implementing object-orientation
 * specifics.
 * @author matze
 */
public final class OOSupport {
	private OOSupport() { }

	/** lowers object oriented constructs */
	public static void lowerOO(TypeSystem typeSystem) {
		NameMangling mangler = new NameMangling();
		mangler.beginMangling();

		typeSystem.setupNameMangler(mangler);
		/* the following substitutions should be the same as in the C++ (itanium) ABI */

		mangler.addNameSubstitution("operator~",   "co");
		mangler.addNameSubstitution("operator+",   "pl");
		mangler.addNameSubstitution("operator-",   "mi");
		mangler.addNameSubstitution("operator*",   "ml");
		mangler.addNameSubstitution("operator/",   "dv");
		mangler.addNameSubstitution("operator%",   "rm");
		mangler.addNameSubstitution("operator&",   "an");
		mangler.addNameSubstitution("operator|",   "or");
		mangler.addNameSubstitution("operator^",   "eo");
		mangler.addNameSubstitution("operator=",   "aS");
		mangler.addNameSubstitution("operator+=",  "pL");
		mangler.addNameSubstitution("operator-=",  "mI");
		mangler.addNameSubstitution("operator*=",  "mL");
		mangler.addNameSubstitution("operator/=",  "dV");
		mangler.addNameSubstitution("operator%=",  "rM");
		mangler.addNameSubstitution("operator&=",  "aN");
		mangler.addNameSubstitution("operator|=",  "oR");
		mangler.addNameSubstitution("operator^=",  "eO");
		mangler.addNameSubstitution("operator<<",  "ls");
		mangler.addNameSubstitution("operator>>",  "rs");
		mangler.addNameSubstitution("operator<<=", "lS");
		mangler.addNameSubstitution("operator>>=", "rS");
		mangler.addNameSubstitution("operator==",  "eq");
		mangler.addNameSubstitution("operator!=",  "ne");
		mangler.addNameSubstitution("operator<",   "lt");
		mangler.addNameSubstitution("operator>",   "gt");
		mangler.addNameSubstitution("operator<=",  "le");
		mangler.addNameSubstitution("operator>=",  "ge");
		mangler.addNameSubstitution("operator!",   "nt");
		mangler.addNameSubstitution("operator&&",  "aa");
		mangler.addNameSubstitution("operator||",  "oo");
		mangler.addNameSubstitution("operator++",  "pp");
		mangler.addNameSubstitution("operator--",  "mm");

		/* TODO: the following does not work as the spec requires the name of the type behind the 'cv' */
		mangler.addNameSubstitution("operator_as", "cv");

		/* TODO: unary +, -
		 * The problem here is that we cannot identify them by name alone
		 * (it's still "operator+" in X10). */

		/* this is our addition */
		mangler.addNameSubstitution("operator>>>", "v3rbs");

		mangler.lowerOO();

		mangler.endMangling();
	}
}
