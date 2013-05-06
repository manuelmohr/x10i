package x10firm.visit;

import java.util.List;

import polyglot.ast.Binary;
import polyglot.ast.Binary_c;
import polyglot.ast.BooleanLit_c;
import polyglot.ast.Expr;
import polyglot.ast.Expr_c;
import polyglot.ast.NullLit;
import polyglot.types.Name;
import polyglot.types.Type;
import x10.ast.X10Binary_c;
import x10.ast.X10Instanceof_c;
import x10.types.MethodInstance;
import x10.types.X10ClassType;
import x10.visit.X10DelegatingVisitor;
import x10cpp.visit.SharedVarsMethods;
import x10firm.types.FirmTypeSystem;
import x10firm.types.GenericTypeSystem;
import firm.Backend;
import firm.Entity;
import firm.MethodType;
import firm.Mode;
import firm.Relation;
import firm.nodes.Block;
import firm.nodes.Call;
import firm.nodes.Cond;
import firm.nodes.Node;
import firm.oo.nodes.InstanceOf;

/**
 * Generates code which "evaluates" a boolean condition.
 * This generates code that jumps to a true/false block depending
 * on the value of the condition expression.
 */
public class ConditionEvaluationCodeGenerator extends X10DelegatingVisitor {
	private Block trueBlock;
	private Block falseBlock;
	private MethodConstruction con;
	private FirmGenerator codeGenerator;
	private final GenericTypeSystem typeSystem;
	private final FirmTypeSystem firmTypeSystem;

	/**
	 * Creates a new code generator.
	 */
	public ConditionEvaluationCodeGenerator(final Block trueBlock, final Block falseBlock,
			final FirmGenerator codeGenerator) {
		this.trueBlock = trueBlock;
		this.falseBlock = falseBlock;
		this.codeGenerator = codeGenerator;
		this.con = codeGenerator.getFirmConstruction();
		this.typeSystem = codeGenerator.getTypeSystem();
		this.firmTypeSystem = codeGenerator.getFirmTypeSystem();
	}

	/**
	 * Creates conditional jump to true/false Block.
	 */
	public static void makeJumps(final Node node, final Block trueBlock,
			final Block falseBlock, final MethodConstruction con) {
		final Node     cond      = con.newCond(node);
		final Node     projTrue  = con.newProj(cond, Mode.getX(), Cond.pnTrue);
		final Node     projFalse = con.newProj(cond, Mode.getX(), Cond.pnFalse);
		trueBlock.addPred(projTrue);
		falseBlock.addPred(projFalse);
		con.setUnreachable();
	}

	@Override
	public void visit(final BooleanLit_c literal) {
		final Node jmp = con.newJmp();

		if (literal.value()) {
			trueBlock.addPred(jmp);
		} else {
			falseBlock.addPred(jmp);
		}

		con.setUnreachable();
	}

	@Override
	public void visit(final Binary_c binop) {
		final Binary.Operator op = binop.operator();
		final Block middleBlock = con.newBlock();

		if (op == Binary.COND_AND) {
			final ConditionEvaluationCodeGenerator subGenerator
				= new ConditionEvaluationCodeGenerator(middleBlock, falseBlock, codeGenerator);
			subGenerator.visitAppropriate(binop.left());
		} else if (op == Binary.COND_OR) {
			final ConditionEvaluationCodeGenerator subGenerator
				= new ConditionEvaluationCodeGenerator(trueBlock, middleBlock, codeGenerator);
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

	private Node handleStructEquals(final X10Binary_c b, final Node retLeft, final Node retRight) {
		final Expr left = b.left();

		// Find the correct _struct_equals to call.  We want S._struct_equals(S), not
		// S._struct_equals(Any).
		final X10ClassType ct = (X10ClassType) typeSystem.getConcreteType(left.type());
		final List<MethodInstance> instances = ct.methodsNamed(Name.make(SharedVarsMethods.STRUCT_EQUALS_METHOD));
		MethodInstance instance = null;
		for (final MethodInstance mi : instances) {
			if (typeSystem.typeEquals(mi.formalTypes().get(0), ct))
				instance = mi;
		}
		assert instance != null;

		// Get the method entity for our _struct_equals.
		final Entity funcEnt = firmTypeSystem.getMethodEntity(instance);
		final MethodType type = (MethodType) funcEnt.getType();
		final Node address = con.newSymConst(funcEnt);

		// Create the call.
		final Node[] parameters = new Node[] {retLeft, retRight};
		final Node mem = con.getCurrentMem();
		final Node call = con.newCall(mem, address, parameters, type);
		final Node newMem = con.newProj(call, Mode.getM(), Call.pnM);
		con.setCurrentMem(newMem);

		// _struct_equals returns a Boolean, so project it out of the call.
		assert type.getNRess() == 1;
		final firm.Type retType = type.getResType(0);
		final Node allResults = con.newProj(call, Mode.getT(), Call.pnTResult);
		final Mode mode = retType.getMode();
		assert mode != null;
		return con.newProj(allResults, mode, 0);
	}

	@Override
	public void visit(final X10Binary_c b) {
		final Binary.Operator op = b.operator();
		final Relation relation;
		/* only '==', '!=' are allowed operators.
		 * all other operators are implemented by native calls. */
		if (op == Binary.EQ) {
			relation = Relation.Equal;
		} else if (op == Binary.NE) {
			relation = Relation.LessGreater;
		} else if (op == Binary.LT) {
			/* in theory this should never happen in X10, as < is actually a function call to
			 * the < operator function. In practice the StaticInitializer lowering code is lazy and
			 * uses it anyway. */
			relation = Relation.Less;
		} else {
			visit((Binary_c)b);
			return;
		}

		final Expr     left      = b.left();
		final Expr     right     = b.right();
		Node           retLeft   = codeGenerator.visitExpression(left);
		Node           retRight  = codeGenerator.visitExpression(right);
		final Type     leftType  = left.type();
		final Type     rightType = right.type();

		// Special case:  For non-firm-primitive structs we want to generate a call to _struct_equals.
		// "Non-firm-primitive" means these are structs that are not mapped directly to machine types.
		final boolean leftIsNonPrimitiveStruct = firmTypeSystem.isFirmStructType(leftType);
		final boolean rightIsNonPrimitiveStruct = firmTypeSystem.isFirmStructType(rightType);

		if (leftIsNonPrimitiveStruct && rightIsNonPrimitiveStruct) {
			final Node ret = handleStructEquals(b, retLeft, retRight);
			// We get a boolean out of handleStructEquals() but makeJumps() expects a Cmp, so compare
			// the result of handleStructEquals() with true.
			final Node toCmp = con.newConst(Mode.getBu().getOne());
			final Node cmp = con.newCmp(ret, toCmp, relation);
			makeJumps(cmp, trueBlock, falseBlock, con);
		} else {
			/* special case: there may be struct == null (I guess it's a bug,
			 * reported it in XTENLANG-3044) */
			if ((left instanceof NullLit && typeSystem.isStructType(rightType))
				|| (right instanceof NullLit && typeSystem.isStructType(leftType))) {
				final Node jmp = con.newJmp();
				if (relation == Relation.Equal) {
					falseBlock.addPred(jmp);
					con.setUnreachable();
				} else {
					trueBlock.addPred(jmp);
					con.setUnreachable();
				}
				return;
			}

			final Mode mode = retLeft.getMode();
			if (mode.isFloat()) {
				final Mode floatArithMode = Backend.getFloatArithmeticMode();
				if (floatArithMode != null) {
					retLeft = con.newConv(retLeft, floatArithMode);
					retRight = con.newConv(retRight, floatArithMode);
				}
			}
			final Node cmp = con.newCmp(retLeft, retRight, relation);
			makeJumps(cmp, trueBlock, falseBlock, con);
		}
	}

	/** Creates code for instanceof check. */
	public static Node genInstanceOf(final Node objPtr, final Type eType, final Type cmpType,
			final FirmGenerator codeGenerator, final GenericTypeSystem typeSystem,
			final FirmTypeSystem firmTypeSystem, final MethodConstruction con) {

		final Type exprType = typeSystem.getConcreteType(eType);
		final Type compType = typeSystem.getConcreteType(cmpType);
		firm.Type firmType = null;

		/* struct-types can be evaluated statically */
		if (typeSystem.isStructType(exprType)) {
			final boolean subtype = typeSystem.isSubtype(exprType, compType);
			final Mode modeB = Mode.getb();
			return con.newConst(subtype ? modeB.getOne() : modeB.getNull());
		}

		/* If the compare type is a struct type we must compare against the boxing type of the struct type */
		if (typeSystem.isStructType(compType)) {
			final Type tmp = codeGenerator.getBoxingType((X10ClassType)compType);
			firmType = firmTypeSystem.asClass(tmp);
		} else {
			firmType = firmTypeSystem.asClass(compType);
		}
		assert firmType != null;

		final Node mem = con.getCurrentMem();
		final Node instanceOf = InstanceOf.create(con, mem, objPtr, firmType);
		final Node projM = con.newProj(instanceOf, Mode.getM(), InstanceOf.pnM);
		con.setCurrentMem(projM);
		final Node projRes = con.newProj(instanceOf, Mode.getb(), InstanceOf.pnRes);
		return projRes;
	}

	@Override
	public void visit(final X10Instanceof_c n) {
		final Type exprType = n.expr().type();
		final Expr objExpr = n.expr();
		final Node objPtr = codeGenerator.visitExpression(objExpr);
		final Type compareType = n.compareType().type();

		final Node node = genInstanceOf(objPtr, exprType, compareType,
		                                codeGenerator, typeSystem, firmTypeSystem, con);
		makeJumps(node, trueBlock, falseBlock, con);
	}

	@Override
	public void visit(final Expr_c expr) {
		/* normal expressions produce a 0 or 1 value if we want to jump
		 * based on that we have to compare the value */
		final Node node = codeGenerator.visitExpression(expr);
		final Mode mode = node.getMode();
		final Node one = con.newConst(mode.getOne());
		final Node cmp = con.newCmp(node, one, Relation.Equal);
		makeJumps(cmp, trueBlock, falseBlock, con);
	}
}
