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
 * A "dummy" visitor which visits all "AST" nodes.
 */
public class X10DummyDelegatingVisitor extends X10DelegatingVisitor {

	@Override
	public void visit(Node n) {
		assert false : "Stop at the beginning of an infinite loop for class "+n.getClass();
	}

	@Override
	public void visit(TypeDecl_c n) {
		for(Formal f : n.formals())
			visitAppropriate(f);
	}

	@Override
	public void visit(LocalTypeDef_c n) {
		visitAppropriate(n.typeDef());
	}

	@Override
	public void visit(X10ClassDecl_c n) {
		for (ClassMember member : n.body().members())
			visitAppropriate(member);
	}

	@Override
	public void visit(LocalClassDecl_c n) {
		throw new RuntimeException("Local classes should have been removed by a separate pass");
	}

	@Override
	public void visit(ClassBody_c n) {
		for (ClassMember member : n.members())
			visitAppropriate(member);
	}

	@Override
	public void visit(PackageNode_c n) {

	}

	@Override
	public void visit(Import_c n) {

	}

	@Override
	public void visit(AssignPropertyCall_c n) {
		for(Expr arg : n.arguments())
			visitAppropriate(arg);
	}

	@Override
	public void visit(MethodDecl_c dec) {
		visitAppropriate(dec.body());
	}

	@Override
	public void visit(ConstructorDecl_c dec) {
		visitAppropriate(dec.body());
	}

	@Override
	public void visit(FieldDecl_c dec) {
		if(dec.init() != null)
			visitAppropriate(dec.init());
	}

	@Override
	public void visit(PropertyDecl_c n) {
		if(n.init() != null)
			visitAppropriate(n.init());
	}

	@Override
	public void visit(Initializer_c n) {
		visitAppropriate(n.body());
	}

	@Override
	public void visit(Assert_c n) {
		visitAppropriate(n.cond());
		if(n.errorMessage() != null)
			visitAppropriate(n.errorMessage());
	}

	@Override
	public void visit(Switch_c n) {
		for(SwitchElement elem : n.elements())
			visitAppropriate(elem);
	}

	@Override
	public void visit(SwitchBlock_c n) {
		for(Stmt stmt : n.statements())
			visitAppropriate(stmt);
	}

	@Override
	public void visit(Case_c n) {
		if(n.expr() != null)
			visitAppropriate(n.expr());
	}

	@Override
	public void visit(Branch_c br) {

	}

	@Override
	public void visit(Labeled_c n) {
		visitAppropriate(n.statement());
	}

	@Override
	public void visit(Assign_c n) {
		visitAppropriate(n.left());
		visitAppropriate(n.right());
	}

	@Override
	public void visit(Return_c ret) {
		if(ret.expr() != null)
			visitAppropriate(ret.expr());
	}

	@Override
	public void visit(Formal_c n) {

	}

	@Override
	public void visit(LocalDecl_c dec) {
		if(dec.init() != null)
			visitAppropriate(dec.init());
	}

	@Override
	public void visit(Block_c b) {
		for (Stmt s : b.statements())
			visitAppropriate(s);
	}

	@Override
	public void visit(StmtSeq_c n) {
		for (Stmt s : n.statements())
			visitAppropriate(s);
	}

	@Override
	public void visit(StmtExpr_c n) {
		for (Stmt stmt : n.statements())
			visitAppropriate(stmt);

		// evaluate the stmt expr
		Expr e = n.result();
		if (e != null)
			visitAppropriate(e);
	}

	@Override
	public void visit(For_c n) {
		if(n.inits() != null) {
			for(ForInit i : n.inits())
				visitAppropriate(i);
		}
		if(n.cond() != null) {
			visitAppropriate(n.cond());
		}
		if(n.iters() != null) {
			for(ForUpdate i : n.iters())
				visitAppropriate(i);
		}
		visitAppropriate(n.body());
	}

	@Override
	public void visit(Do_c n) {
		visitAppropriate(n.body());
		visitAppropriate(n.cond());
	}

	@Override
	public void visit(While_c n) {
		visitAppropriate(n.cond());
		visitAppropriate(n.body());
	}

	@Override
	public void visit(Conditional_c n) {
		visitAppropriate(n.cond());
		visitAppropriate(n.consequent());
		visitAppropriate(n.alternative());
	}

	@Override
	public void visit(If_c n) {
		visitAppropriate(n.consequent());
		if (n.alternative() != null) {
			Stmt alternative = n.alternative();
			if (alternative instanceof Block_c) {
				Block_c block = (Block_c) alternative;
				if (block.statements().size() == 1 && block.statements().get(0) instanceof If_c)
					alternative = block.statements().get(0);
			}
			visitAppropriate(alternative);
		}
	}

	@Override
	public void visit(Empty_c n) {

	}

	@Override
	public void visit(Eval_c n) {
		visitAppropriate(n.expr());
	}

	@Override
	public void visit(X10Call_c n) {
		visitAppropriate(n.target());
		for(Expr e : n.arguments())
			visitAppropriate(e);
	}

	@Override
	public void visit(X10ConstructorCall_c n) {
		for(Expr e : n.arguments())
			visitAppropriate(e);
	}

	@Override
	public void visit(Field_c n) {
		visitAppropriate(n.target());
	}

	@Override
	public void visit(Local_c n) {

	}

	@Override
	public void visit(New_c n) {
		if(n.qualifier() != null)
			visitAppropriate(n.qualifier());
		for(Expr e : n.arguments())
			visitAppropriate(e);
		if(n.body() != null)
			visitAppropriate(n.body());
	}

	@Override
	public void visit(FloatLit_c literal) {

	}

	@Override
	public void visit(IntLit_c n) {

	}

	@Override
	public void visit(NullLit_c n) {

	}

	@Override
	public void visit(StringLit_c n) {

	}

	@Override
	public void visit(CharLit_c literal) {

	}


	@Override
	public void visit(BooleanLit_c literal) {

	}

	@Override
	public void visit(Id_c n) {

	}

	@Override
	public void visit(X10Cast_c c) {

	}

	@Override
	public void visit(SubtypeTest_c n) {

	}

	@Override
	public void visit(X10Instanceof_c n) {

	}

	@Override
	public void visit(Throw_c n) {
		visitAppropriate(n.expr());
	}

	@Override
	public void visit(Try_c n) {
		visitAppropriate(n.tryBlock());
		for(Catch c : n.catchBlocks())
			visitAppropriate(c);
		if(n.finallyBlock() != null)
			visitAppropriate(n.finallyBlock());
	}

	@Override
	public void visit(Catch_c n) {
		visitAppropriate(n.formal());
		visitAppropriate(n.body());
	}

	@Override
	public void visit(Atomic_c n) {
		visitAppropriate(n.body());
	}

	@Override
	public void visit(Next_c n) {

	}

	@Override
	public void visit(ForLoop_c n) {
		if(n.formal() != null)
			visitAppropriate(n.formal());
		if(n.domain() != null)
			visitAppropriate(n.domain());

		visitAppropriate(n.body());

		for(Stmt s : n.locals())
			visitAppropriate(s);
	}

	@Override
	public void visit(AtEach_c n) {
		visitAppropriate(n.body());
	}

	@Override
	public void visit(Finish_c n) {
		visitAppropriate(n.body());
	}

	@Override
	public void visit(ArrayAccess_c n) {
		visitAppropriate(n.array());
		visitAppropriate(n.index());
	}

	@Override
	public void visit(ParExpr_c n) {
		visitAppropriate(n.expr());
	}

	@Override
	public void visit(Here_c n) {

	}

	@Override
	public void visit(Async_c n) {
		visitAppropriate(n.body());
	}

	@Override
	public void visit(X10Special_c n) {

	}

	@Override
	public void visit(Closure_c n) {
		visitAppropriate(n.body());
	}

	@Override
	public void visit(ClosureCall_c n) {
		visitAppropriate(n.target());
		for(Expr e : n.arguments())
			visitAppropriate(e);
	}

	@Override
	public void visit(X10CanonicalTypeNode_c n) {

	}

	@Override
	public void visit(X10Unary_c n) {
		visitAppropriate(n.expr());
	}

	@Override
	public void visit(Unary_c n) {
		visitAppropriate(n.expr());
	}

	@Override
	public void visit(X10Binary_c n) {
		visitAppropriate(n.left());
		visitAppropriate(n.right());
	}

	@Override
	public void visit(Binary_c B) {
		visitAppropriate(B.left());
		visitAppropriate(B.right());
	}

	@Override
	public void visit(ArrayInit_c n) {
		for(Expr e : n.elements())
			visitAppropriate(e);
	}

	@Override
	public void visit(SettableAssign_c n) {
		if(n.array() != null)
			visitAppropriate(n.array());
		for(Expr e : n.index())
			visitAppropriate(e);
	}

	@Override
	public void visit(Tuple_c n) {
		for(Expr e : n.arguments())
			visitAppropriate(e);
	}

	@Override
	public void visit(When_c n) {
		for(Expr e : n.exprs())
			visitAppropriate(e);
		for(Stmt s : n.stmts())
			visitAppropriate(s);
	}

	@Override
	public void visit(AtStmt_c n) {
		if(n.place() != null)
			visitAppropriate(n.place());
		if(n.body() != null)
			visitAppropriate(n.body());
	}

	@Override
	public void visit(AtExpr_c n) {
		if(n.place() != null)
			visitAppropriate(n.place());
	}

	@Override
	public void visit(Allocation_c n) {
		visitAppropriate(n.objectType());
	}
}