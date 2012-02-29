package x10firm.visit;

import polyglot.ast.Node;
import polyglot.util.InternalCompilerError;

/**
 * Exception thrown when no code can be generated for a specific AST-node
 */
public class CodeGenError extends InternalCompilerError {
	/** Construct new exception */
	public CodeGenError(String message, Node node) {
		super(message + " (node " + node + ")", node.position());
	}
}