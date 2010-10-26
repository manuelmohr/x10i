package x10firm.visit;

import polyglot.ast.Node;
import polyglot.ast.NodeFactory;
import polyglot.types.Context;
import polyglot.types.TypeSystem;
import polyglot.util.CodeWriter;
import polyglot.visit.Translator;

/**
 * Really, we don't need or want a Translator. But some X10 APIs assume
 * you always have one around to query TypeSystem and Context from...
 * So this implementation does nothing except returning TypeSystem
 * and Context.
 * @author matze
 */
public class NoTranslator extends Translator {
	public NoTranslator(TypeSystem ts, NodeFactory nf) {
		super(null, ts, nf, null);
	}
	
	@Override
	public Context context() {
		throw new RuntimeException("Not implemented");
	}
	
	@Override
	public Translator context(Context c) {
		throw new RuntimeException("Not implemented");
	}
	
	@Override
	public boolean translate(Node ast) {
		throw new RuntimeException("Not implemented");
	}
	
	@Override
	public void print(Node parent, Node child, CodeWriter w) {
		throw new RuntimeException("Not implemented");
	}
	
	@Override
	public String toString() {
		return "NoTranslator";
	}
}
