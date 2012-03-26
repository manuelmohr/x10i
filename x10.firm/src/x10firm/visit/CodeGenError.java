package x10firm.visit;

import polyglot.ast.Node;
import polyglot.util.InternalCompilerError;
import polyglot.util.Position;

/**
 * Exception thrown when no code can be generated for a specific AST-node.
 */
public class CodeGenError extends InternalCompilerError {
	/** Constructs new exception. */
	public CodeGenError(final String message, final Node node) {
		super(message + " (node " + node + ")", node.position());
	}

	/** Constructs new exception. */
	public CodeGenError(final String message, final Position position) {
		super(message, position);
	}
}
