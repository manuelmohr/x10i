/*
 *  This file is part of the X10 project (http://x10-lang.org).
 *
 *  This file is licensed to You under the Eclipse Public License (EPL);
 *  You may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *      http://www.opensource.org/licenses/eclipse-1.0.php
 *
 *  (C) Copyright IBM Corporation 2006-2010.
 */

package x10.ast;

import polyglot.ast.Expr;
import polyglot.ast.Node;
import polyglot.ast.Stmt;
import polyglot.ast.While_c;
import polyglot.types.SemanticException;
import polyglot.types.TypeSystem;
import polyglot.util.Position;
import polyglot.visit.ContextVisitor;

/**
 * @author VijaySaraswat
 *
 */
public class X10While_c extends While_c {

	/**
	 * @param pos
	 * @param cond
	 * @param body
	 */
	public X10While_c(Position pos, Expr cond, Stmt body) {
		super(pos, cond, body);
		// TODO Auto-generated constructor stub
	}

	/** Type check the statement. */
	public Node typeCheck(ContextVisitor tc) throws SemanticException {
		TypeSystem ts = tc.typeSystem();

		if (! ts.isSubtype(cond.type(), ts.Boolean(), tc.context())) {
		    throw new SemanticException("Condition of while statement must have boolean type, and not " + cond.type() + ".",cond.position());
		}

		return this;
	}

}
