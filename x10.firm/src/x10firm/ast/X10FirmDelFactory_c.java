package x10firm.ast;

import polyglot.util.CodeWriter;
import polyglot.visit.Translator;
import x10.visit.X10DelegatingVisitor;
import x10firm.visit.X10FirmCodeGenerator;

public class X10FirmDelFactory_c extends x10.ast.X10DelFactory_c {

	@Override
	protected X10DelegatingVisitor makeCodeGenerator(CodeWriter w, Translator tr) {
		// We don`t need the CodeWriter
		return new X10FirmCodeGenerator(tr);
	}
}
