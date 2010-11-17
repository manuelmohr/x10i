package x10firm;

import x10firm.types.TypeSystem;
import firm.NameMangling;

public final class OOSupport {
	private OOSupport() { }
	
	public static void prepareOO(TypeSystem typeSystem) {
		NameMangling mangler = new NameMangling();
		mangler.beginMangling();
		
		typeSystem.setupNameMangler(mangler);
		/* TODO: complete + check these */
		mangler.addNameSubstitution("operator+", "pl");
		mangler.addNameSubstitution("operator-", "mi");
		mangler.addNameSubstitution("operator*", "ml");
		mangler.addNameSubstitution("operator/", "dv");
		mangler.addNameSubstitution("operator%", "rm");
		mangler.addNameSubstitution("operator&", "an");
		mangler.addNameSubstitution("operator<", "lt");
		mangler.addNameSubstitution("operator>", "gt");
		mangler.addNameSubstitution("operator<=", "le");
		mangler.addNameSubstitution("operator>=", "ge");
		mangler.addNameSubstitution("operator>>", "rs");
		mangler.addNameSubstitution("operator<<", "ls");
		mangler.addNameSubstitution("operator>>=", "rS");
		mangler.addNameSubstitution("operator<<=", "lS");
		mangler.addNameSubstitution("operator==", "eq");
		mangler.addNameSubstitution("operator!=", "ne");
		
		//mangler.addNameSubstitution("operator", mangled)
		
		mangler.lowerOO();
		
		mangler.endMangling();
	}
}
