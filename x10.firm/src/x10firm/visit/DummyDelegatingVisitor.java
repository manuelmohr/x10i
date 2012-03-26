package x10firm.visit;

import polyglot.ast.Allocation_c;
import polyglot.ast.ArrayAccess_c;
import polyglot.ast.ArrayInit_c;
import polyglot.ast.Assert_c;
import polyglot.ast.Assign_c;
import polyglot.ast.Binary_c;
import polyglot.ast.Block_c;
import polyglot.ast.BooleanLit_c;
import polyglot.ast.Branch_c;
import polyglot.ast.Case_c;
import polyglot.ast.Catch;
import polyglot.ast.Catch_c;
import polyglot.ast.CharLit_c;
import polyglot.ast.ClassBody_c;
import polyglot.ast.ClassMember;
import polyglot.ast.Conditional_c;
import polyglot.ast.ConstructorDecl_c;
import polyglot.ast.Do_c;
import polyglot.ast.Empty_c;
import polyglot.ast.Eval_c;
import polyglot.ast.Expr;
import polyglot.ast.FieldDecl_c;
import polyglot.ast.Field_c;
import polyglot.ast.FloatLit_c;
import polyglot.ast.ForInit;
import polyglot.ast.ForUpdate;
import polyglot.ast.For_c;
import polyglot.ast.Formal;
import polyglot.ast.Formal_c;
import polyglot.ast.Id_c;
import polyglot.ast.If_c;
import polyglot.ast.Import_c;
import polyglot.ast.Initializer_c;
import polyglot.ast.IntLit_c;
import polyglot.ast.Labeled_c;
import polyglot.ast.LocalClassDecl_c;
import polyglot.ast.LocalDecl_c;
import polyglot.ast.Local_c;
import polyglot.ast.MethodDecl_c;
import polyglot.ast.New_c;
import polyglot.ast.Node;
import polyglot.ast.NullLit_c;
import polyglot.ast.PackageNode_c;
import polyglot.ast.Return_c;
import polyglot.ast.Stmt;
import polyglot.ast.StringLit_c;
import polyglot.ast.SwitchBlock_c;
import polyglot.ast.SwitchElement;
import polyglot.ast.Switch_c;
import polyglot.ast.Throw_c;
import polyglot.ast.Try_c;
import polyglot.ast.Unary_c;
import polyglot.ast.While_c;
import x10.ast.AssignPropertyCall_c;
import x10.ast.Async_c;
import x10.ast.AtEach_c;
import x10.ast.AtExpr_c;
import x10.ast.AtStmt_c;
import x10.ast.Atomic_c;
import x10.ast.ClosureCall_c;
import x10.ast.Closure_c;
import x10.ast.Finish_c;
import x10.ast.ForLoop_c;
import x10.ast.Here_c;
import x10.ast.LocalTypeDef_c;
import x10.ast.Next_c;
import x10.ast.ParExpr_c;
import x10.ast.PropertyDecl_c;
import x10.ast.SettableAssign_c;
import x10.ast.StmtExpr_c;
import x10.ast.StmtSeq_c;
import x10.ast.SubtypeTest_c;
import x10.ast.Tuple_c;
import x10.ast.TypeDecl_c;
import x10.ast.When_c;
import x10.ast.X10Binary_c;
import x10.ast.X10Call_c;
import x10.ast.X10CanonicalTypeNode_c;
import x10.ast.X10Cast_c;
import x10.ast.X10ClassDecl_c;
import x10.ast.X10ConstructorCall_c;
import x10.ast.X10Instanceof_c;
import x10.ast.X10Special_c;
import x10.ast.X10Unary_c;
import x10.visit.X10DelegatingVisitor;

/**
 * A "dummy" visitor which contains code for traversing all nodes of an "AST".
 * It does not contain any behaviour.
 */
public abstract class DummyDelegatingVisitor extends X10DelegatingVisitor {

	@Override
	public void visit(final Node n) {
		assert false : "Stop at the beginning of an infinite loop for class " + n.getClass();
	}

	@Override
	public void visit(final TypeDecl_c n) {
		for (final Formal f : n.formals()) {
			visitAppropriate(f);
		}
	}

	@Override
	public void visit(final LocalTypeDef_c n) {
		visitAppropriate(n.typeDef());
	}

	@Override
	public void visit(final X10ClassDecl_c n) {
		for (final ClassMember member : n.body().members()) {
			visitAppropriate(member);
		}
	}

	@Override
	public void visit(final LocalClassDecl_c n) {
		throw new RuntimeException("Local classes should have been removed by a separate pass");
	}

	@Override
	public void visit(final ClassBody_c n) {
		for (final ClassMember member : n.members()) {
			visitAppropriate(member);
		}
	}

	@Override
	public void visit(final PackageNode_c n) {

	}

	@Override
	public void visit(final Import_c n) {

	}

	@Override
	public void visit(final AssignPropertyCall_c n) {
		for (final Expr arg : n.arguments()) {
			visitAppropriate(arg);
		}
	}

	@Override
	public void visit(final MethodDecl_c dec) {
		visitAppropriate(dec.body());
	}

	@Override
	public void visit(final ConstructorDecl_c dec) {
		visitAppropriate(dec.body());
	}

	@Override
	public void visit(final FieldDecl_c dec) {
		if (dec.init() != null) {
			visitAppropriate(dec.init());
		}
	}

	@Override
	public void visit(final PropertyDecl_c n) {
		if (n.init() != null) {
			visitAppropriate(n.init());
		}
	}

	@Override
	public void visit(final Initializer_c n) {
		visitAppropriate(n.body());
	}

	@Override
	public void visit(final Assert_c n) {
		visitAppropriate(n.cond());
		if (n.errorMessage() != null) {
			visitAppropriate(n.errorMessage());
		}
	}

	@Override
	public void visit(final Switch_c n) {
		for (final SwitchElement elem : n.elements()) {
			visitAppropriate(elem);
		}
	}

	@Override
	public void visit(final SwitchBlock_c n) {
		for (final Stmt stmt : n.statements()) {
			visitAppropriate(stmt);
		}
	}

	@Override
	public void visit(final Case_c n) {
		if (n.expr() != null) {
			visitAppropriate(n.expr());
		}
	}

	@Override
	public void visit(final Branch_c br) {

	}

	@Override
	public void visit(final Labeled_c n) {
		visitAppropriate(n.statement());
	}

	@Override
	public void visit(final Assign_c n) {
		visitAppropriate(n.left());
		visitAppropriate(n.right());
	}

	@Override
	public void visit(final Return_c ret) {
		if (ret.expr() != null) {
			visitAppropriate(ret.expr());
		}
	}

	@Override
	public void visit(final Formal_c n) {

	}

	@Override
	public void visit(final LocalDecl_c dec) {
		if (dec.init() != null) {
			visitAppropriate(dec.init());
		}
	}

	@Override
	public void visit(final Block_c b) {
		for (final Stmt s : b.statements()) {
			visitAppropriate(s);
		}
	}

	@Override
	public void visit(final StmtSeq_c n) {
		for (final Stmt s : n.statements()) {
			visitAppropriate(s);
		}
	}

	@Override
	public void visit(final StmtExpr_c n) {
		for (final Stmt stmt : n.statements()) {
			visitAppropriate(stmt);
		}

		// evaluate the stmt expr
		final Expr e = n.result();
		if (e != null) {
			visitAppropriate(e);
		}
	}

	@Override
	public void visit(final For_c n) {
		if (n.inits() != null) {
			for (final ForInit i : n.inits()) {
				visitAppropriate(i);
			}
		}
		if (n.cond() != null) {
			visitAppropriate(n.cond());
		}
		if (n.iters() != null) {
			for (final ForUpdate i : n.iters()) {
				visitAppropriate(i);
			}
		}
		visitAppropriate(n.body());
	}

	@Override
	public void visit(final Do_c n) {
		visitAppropriate(n.body());
		visitAppropriate(n.cond());
	}

	@Override
	public void visit(final While_c n) {
		visitAppropriate(n.cond());
		visitAppropriate(n.body());
	}

	@Override
	public void visit(final Conditional_c n) {
		visitAppropriate(n.cond());
		visitAppropriate(n.consequent());
		visitAppropriate(n.alternative());
	}

	@Override
	public void visit(final If_c n) {
		visitAppropriate(n.consequent());
		if (n.alternative() != null) {
			Stmt alternative = n.alternative();
			if (alternative instanceof Block_c) {
				final Block_c block = (Block_c) alternative;
				if (block.statements().size() == 1 && block.statements().get(0) instanceof If_c) {
					alternative = block.statements().get(0);
				}
			}
			visitAppropriate(alternative);
		}
	}

	@Override
	public void visit(final Empty_c n) {

	}

	@Override
	public void visit(final Eval_c n) {
		visitAppropriate(n.expr());
	}

	@Override
	public void visit(final X10Call_c n) {
		visitAppropriate(n.target());
		for (final Expr e : n.arguments()) {
			visitAppropriate(e);
		}
	}

	@Override
	public void visit(final X10ConstructorCall_c n) {
		for (final Expr e : n.arguments()) {
			visitAppropriate(e);
		}
	}

	@Override
	public void visit(final Field_c n) {
		visitAppropriate(n.target());
	}

	@Override
	public void visit(final Local_c n) {

	}

	@Override
	public void visit(final New_c n) {
		if (n.qualifier() != null) {
			visitAppropriate(n.qualifier());
		}
		for (final Expr e : n.arguments()) {
			visitAppropriate(e);
		}
		if (n.body() != null) {
			visitAppropriate(n.body());
		}
	}

	@Override
	public void visit(final FloatLit_c literal) {

	}

	@Override
	public void visit(final IntLit_c n) {

	}

	@Override
	public void visit(final NullLit_c n) {

	}

	@Override
	public void visit(final StringLit_c n) {

	}

	@Override
	public void visit(final CharLit_c literal) {

	}


	@Override
	public void visit(final BooleanLit_c literal) {

	}

	@Override
	public void visit(final Id_c n) {

	}

	@Override
	public void visit(final X10Cast_c c) {

	}

	@Override
	public void visit(final SubtypeTest_c n) {

	}

	@Override
	public void visit(final X10Instanceof_c n) {

	}

	@Override
	public void visit(final Throw_c n) {
		visitAppropriate(n.expr());
	}

	@Override
	public void visit(final Try_c n) {
		visitAppropriate(n.tryBlock());
		for (final Catch c : n.catchBlocks()) {
			visitAppropriate(c);
		}
		if (n.finallyBlock() != null) {
			visitAppropriate(n.finallyBlock());
		}
	}

	@Override
	public void visit(final Catch_c n) {
		visitAppropriate(n.formal());
		visitAppropriate(n.body());
	}

	@Override
	public void visit(final Atomic_c n) {
		visitAppropriate(n.body());
	}

	@Override
	public void visit(final Next_c n) {

	}

	@Override
	public void visit(final ForLoop_c n) {
		if (n.formal() != null) {
			visitAppropriate(n.formal());
		}
		if (n.domain() != null) {
			visitAppropriate(n.domain());
		}

		visitAppropriate(n.body());

		for (final Stmt s : n.locals()) {
			visitAppropriate(s);
		}
	}

	@Override
	public void visit(final AtEach_c n) {
		visitAppropriate(n.body());
	}

	@Override
	public void visit(final Finish_c n) {
		visitAppropriate(n.body());
	}

	@Override
	public void visit(final ArrayAccess_c n) {
		visitAppropriate(n.array());
		visitAppropriate(n.index());
	}

	@Override
	public void visit(final ParExpr_c n) {
		visitAppropriate(n.expr());
	}

	@Override
	public void visit(final Here_c n) {

	}

	@Override
	public void visit(final Async_c n) {
		visitAppropriate(n.body());
	}

	@Override
	public void visit(final X10Special_c n) {

	}

	@Override
	public void visit(final Closure_c n) {
		visitAppropriate(n.body());
	}

	@Override
	public void visit(final ClosureCall_c n) {
		visitAppropriate(n.target());
		for (final Expr e : n.arguments()) {
			visitAppropriate(e);
		}
	}

	@Override
	public void visit(final X10CanonicalTypeNode_c n) {

	}

	@Override
	public void visit(final X10Unary_c n) {
		visitAppropriate(n.expr());
	}

	@Override
	public void visit(final Unary_c n) {
		visitAppropriate(n.expr());
	}

	@Override
	public void visit(final X10Binary_c n) {
		visitAppropriate(n.left());
		visitAppropriate(n.right());
	}

	@Override
	public void visit(final Binary_c b) {
		visitAppropriate(b.left());
		visitAppropriate(b.right());
	}

	@Override
	public void visit(final ArrayInit_c n) {
		for (final Expr e : n.elements()) {
			visitAppropriate(e);
		}
	}

	@Override
	public void visit(final SettableAssign_c n) {
		if (n.array() != null) {
			visitAppropriate(n.array());
		}
		for (final Expr e : n.index()) {
			visitAppropriate(e);
		}
	}

	@Override
	public void visit(final Tuple_c n) {
		for (final Expr e : n.arguments()) {
			visitAppropriate(e);
		}
	}

	@Override
	public void visit(final When_c n) {
		for (final Expr e : n.exprs()) {
			visitAppropriate(e);
		}
		for (final Stmt s : n.stmts()) {
			visitAppropriate(s);
		}
	}

	@Override
	public void visit(final AtStmt_c n) {
		if (n.place() != null) {
			visitAppropriate(n.place());
		}
		if (n.body() != null) {
			visitAppropriate(n.body());
		}
	}

	@Override
	public void visit(final AtExpr_c n) {
		if (n.place() != null) {
			visitAppropriate(n.place());
		}
	}

	@Override
	public void visit(final Allocation_c n) {
		visitAppropriate(n.objectType());
	}
}
