package x10firm.visit;

import polyglot.ast.Binary;
import polyglot.ast.Binary_c;
import polyglot.ast.BooleanLit_c;
import polyglot.ast.Expr;
import polyglot.ast.Expr_c;
import polyglot.types.Type;
import polyglot.types.Types;
import x10.ast.X10Binary_c;
import x10.ast.X10Instanceof_c;
import x10.types.X10ClassType;
import x10.visit.X10DelegatingVisitor;
import x10firm.types.GenericTypeSystem;
import firm.Mode;
import firm.Relation;
import firm.nodes.Block;
import firm.nodes.Cond;
import firm.nodes.InstanceOf;
import firm.nodes.Node;
import firm.nodes.OOConstruction;

/**
 * Generates code which "evaluates" a boolean condition.
 * This generates code that jumps to a true/false block depending
 * on the value of the condition expression.
 */
public class ConditionEvaluationCodeGenerator extends X10DelegatingVisitor {
	private Block trueBlock;
	private Block falseBlock;
	private OOConstruction con;
	private X10FirmCodeGenerator codeGenerator;
	private final GenericTypeSystem typeSystem;

	/**
	 * Creates a new code generator
	 */
	public ConditionEvaluationCodeGenerator(Block trueBlock, Block falseBlock, X10FirmCodeGenerator codeGenerator, GenericTypeSystem typeSystem) {
		this.trueBlock = trueBlock;
		this.falseBlock = falseBlock;
		this.codeGenerator = codeGenerator;
		this.con = codeGenerator.getFirmConstruction();
		this.typeSystem = typeSystem;
	}

	/**
	 * Create conditional jump to true/false Block.
	 */
	private void makeJumps(Node node) {
		final Node     cond      = con.newCond(node);
		final Node     projTrue  = con.newProj(cond, Mode.getX(), Cond.pnTrue);
		final Node     projFalse = con.newProj(cond, Mode.getX(), Cond.pnFalse);
		trueBlock.addPred(projTrue);
		falseBlock.addPred(projFalse);
		con.setCurrentBlockBad();
	}

	@Override
	public void visit(BooleanLit_c literal) {
		Node jmp = con.newJmp();
		if (literal.booleanValue()) {
			trueBlock.addPred(jmp);
		} else {
			falseBlock.addPred(jmp);
		}
		con.setCurrentBlockBad();
	}

	@Override
	public void visit(Binary_c binop) {
		final Binary.Operator op = binop.operator();
		final Block middleBlock = con.newBlock();

		if (op == Binary.COND_AND) {
			ConditionEvaluationCodeGenerator subGenerator
				= new ConditionEvaluationCodeGenerator(middleBlock, falseBlock, codeGenerator, typeSystem);
			subGenerator.visitAppropriate(binop.left());
		} else if (op == Binary.COND_OR) {
			ConditionEvaluationCodeGenerator subGenerator
				= new ConditionEvaluationCodeGenerator(trueBlock, middleBlock, codeGenerator, typeSystem);
			subGenerator.visitAppropriate(binop.left());
		} else {
			/* all the other binary ops like the relational and other ops should
			 * be calls to the standard library */
			throw new RuntimeException("Unexpected binary op");
		}
		middleBlock.mature();
		con.setCurrentBlock(middleBlock);
		visitAppropriate(binop.right());
	}

	@Override
	public void visit(X10Binary_c B) {
		final Binary.Operator op = B.operator();
		if (op != Binary.EQ && op != Binary.NE) {
			visit((Binary_c)B);
			return;
		}

		/* only '==', '!=' are allowed operators.
		 * all other operators are implemented by native calls. */

		final Expr     left      = B.left();
		final Expr     right     = B.right();
		final Relation relation  = (op == Binary.EQ) ? Relation.Equal : Relation.LessGreater;
		final Node     retLeft   = codeGenerator.visitExpression(left);
		final Node     retRight  = codeGenerator.visitExpression(right);
		final Node     cmp       = con.newCmp(retLeft, retRight, relation);
		makeJumps(cmp);
	}

	@Override
	public void visit(X10Instanceof_c n) {
		final Type exprType = n.expr().type();
		Node objPtr;

		if (typeSystem.isStructType(exprType)) {
			final X10ClassType ct = (X10ClassType) Types.stripConstraints(exprType);
			objPtr = codeGenerator.genAutoboxing(ct, n.expr());
		}
		else
			objPtr = codeGenerator.visitExpression(n.expr());

		final Type type = n.compareType().typeRef().get();
		final firm.Type firmType = codeGenerator.getFirmTypeSystem().asFirmCoreType(type);
		final Node mem = con.getCurrentMem();
		final Node instanceOf = con.newInstanceOf(mem, objPtr, firmType);
		final Node projM = con.newProj(instanceOf, Mode.getM(), InstanceOf.pnM);
		con.setCurrentMem(projM);
		final Node projRes = con.newProj(instanceOf, Mode.getb(), InstanceOf.pnRes);
		makeJumps(projRes);
	}

	@Override
	public void visit(Expr_c expr) {
		/* normal expressions produce a 0 or 1 value if we want to jump
		 * based on that we have to compare the value */
		final Node node = codeGenerator.visitExpression(expr);
		final Mode mode = codeGenerator.getFirmTypeSystem().getFirmMode(expr.type());
		final Node one = con.newConst(mode.getOne());
		final Node cmp = con.newCmp(node, one, Relation.Equal);
		makeJumps(cmp);
	}
}
