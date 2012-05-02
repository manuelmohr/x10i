package x10firm.visit;

import firm.nodes.Block;
import firm.nodes.Node;
import firm.nodes.OOConstruction;

/**
 * Firm code templates.
 */
public final class FirmCodeTemplate {
	/** this is a utiltiy class. */
	private FirmCodeTemplate() {
	}

	/**
	 * Code template for conditions.
	 */
	interface CondTemplate {
		/**
		 * Generates condition code.
		 * @param trueBlock True block
		 * @param falseBlock False block
		 */
		void genCode(final Block trueBlock, final Block falseBlock);
	}

	/**
	 * Code template for statements.
	 */
	interface StmtTemplate {
		/**
		 * Generates body code.
		 */
		void genCode();
	}

	/**
	 * Code template for expressions.
	 */
	interface ExprTemplate {
		/**
		 * Generates expression code.
		 */
		Node genCode();
	}

	/**
	 * Generate firm nodes for a conditional expression.
	 * @param con The construction object
	 * @param cond The condition template
	 * @param trueExpr The true expression template
	 * @param falseExpr The false expression template
	 * @return Phi node
	 */
	public static Node genConditional(final MethodConstruction con, final CondTemplate cond,
			final ExprTemplate trueExpr, final ExprTemplate falseExpr) {

		final Block bTrue    = con.newBlock();
		final Block bFalse   = con.newBlock();
		final Block curBlock = con.getCurrentBlock();

		con.setCurrentBlock(bTrue);

		final Node trueNode  = trueExpr.genCode();
		final Node endIf     = con.newJmp();

		con.setCurrentBlock(bFalse);

		final Node falseNode = falseExpr.genCode();
		final Node endElse   = con.newJmp();

		con.setCurrentBlock(curBlock);

		cond.genCode(bTrue, bFalse);

		bFalse.mature();

		// add a common phi block for the true and false expressions.
		final Block phiBlock = con.newBlock();
		phiBlock.addPred(endIf);
		phiBlock.addPred(endElse);

		con.setCurrentBlock(phiBlock);

		phiBlock.mature();

		return con.newPhi(new Node[]{trueNode, falseNode}, falseNode.getMode());
	}

	/**
	 * Generates code for an if statement.
	 * @param con The construction object
	 * @param cond The condition template
	 * @param ifStmt The if statement template
	 * @param elseStmt The else statement template
	 */
	public static void genIfStatement(final OOConstruction con,
			final CondTemplate cond, final StmtTemplate ifStmt, final StmtTemplate elseStmt) {
		final Block bTrue  = con.newBlock();
		final Block bAfter = con.newBlock();

		Block bFalse = null; // block will only be created if we have an else stmt.
		if (elseStmt != null) {
			bFalse = con.newBlock();
		} else {
			bFalse = bAfter;
		}

		cond.genCode(bTrue, bFalse);

		con.setCurrentBlock(bTrue);

		ifStmt.genCode();

		Node endIf = null;
		if (con.isUnreachable()) {
			con.setCurrentBlock(bTrue);
		} else {
			endIf = con.newJmp();
		}

		bTrue.mature();

		if (elseStmt != null) {
			bFalse.mature();
			con.setCurrentBlock(bFalse);
			elseStmt.genCode();

			if (!con.isUnreachable())
				bAfter.addPred(con.newJmp());
		}

		if (endIf != null)
			bAfter.addPred(endIf);

		if (!con.isUnreachable())
			con.setCurrentBlock(bAfter);
	}
}
