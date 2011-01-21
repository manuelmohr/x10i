package x10firm.visit;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;

import polyglot.ast.ArrayAccess_c;
import polyglot.ast.ArrayInit_c;
import polyglot.ast.Assert_c;
import polyglot.ast.Assign_c;
import polyglot.ast.Binary;
import polyglot.ast.Binary_c;
import polyglot.ast.Block_c;
import polyglot.ast.BooleanLit_c;
import polyglot.ast.Branch;
import polyglot.ast.Branch_c;
import polyglot.ast.Case;
import polyglot.ast.Case_c;
import polyglot.ast.Catch_c;
import polyglot.ast.CharLit_c;
import polyglot.ast.ClassBody_c;
import polyglot.ast.ClassMember;
import polyglot.ast.CodeBlock;
import polyglot.ast.Conditional_c;
import polyglot.ast.ConstructorDecl_c;
import polyglot.ast.Do_c;
import polyglot.ast.Empty_c;
import polyglot.ast.Eval_c;
import polyglot.ast.Expr;
import polyglot.ast.FieldDecl_c;
import polyglot.ast.Field_c;
import polyglot.ast.FloatLit;
import polyglot.ast.FloatLit_c;
import polyglot.ast.For_c;
import polyglot.ast.Formal_c;
import polyglot.ast.Id_c;
import polyglot.ast.If_c;
import polyglot.ast.Import_c;
import polyglot.ast.Initializer_c;
import polyglot.ast.IntLit;
import polyglot.ast.IntLit_c;
import polyglot.ast.Labeled_c;
import polyglot.ast.LocalClassDecl_c;
import polyglot.ast.LocalDecl_c;
import polyglot.ast.Local_c;
import polyglot.ast.MethodDecl;
import polyglot.ast.MethodDecl_c;
import polyglot.ast.New_c;
import polyglot.ast.NullLit_c;
import polyglot.ast.PackageNode_c;
import polyglot.ast.Receiver;
import polyglot.ast.Return_c;
import polyglot.ast.Special;
import polyglot.ast.Stmt;
import polyglot.ast.StringLit_c;
import polyglot.ast.SwitchBlock_c;
import polyglot.ast.SwitchElement;
import polyglot.ast.Switch_c;
import polyglot.ast.Throw_c;
import polyglot.ast.TopLevelDecl;
import polyglot.ast.Try_c;
import polyglot.ast.Unary_c;
import polyglot.ast.While_c;
import polyglot.frontend.Compiler;
import polyglot.types.ClassDef;
import polyglot.types.Context;
import polyglot.types.FieldDef;
import polyglot.types.FieldInstance;
import polyglot.types.Flags;
import polyglot.types.LocalDef;
import polyglot.types.LocalInstance;
import polyglot.types.MethodInstance;
import polyglot.types.Name;
import polyglot.types.Named;
import polyglot.types.QName;
import polyglot.types.Ref;
import polyglot.types.Type;
import polyglot.types.Types;
import polyglot.types.VarInstance;
import polyglot.util.ErrorInfo;
import polyglot.util.InternalCompilerError;
import polyglot.util.Position;
import x10.ast.Async_c;
import x10.ast.AtEach_c;
import x10.ast.AtExpr_c;
import x10.ast.AtStmt_c;
import x10.ast.Atomic_c;
import x10.ast.Await_c;
import x10.ast.ClosureCall;
import x10.ast.ClosureCall_c;
import x10.ast.Closure_c;
import x10.ast.ConstantDistMaker_c;
import x10.ast.Finish_c;
import x10.ast.ForLoop_c;
import x10.ast.Future_c;
import x10.ast.Here_c;
import x10.ast.LocalTypeDef_c;
import x10.ast.Next_c;
import x10.ast.ParExpr_c;
import x10.ast.PropertyDecl_c;
import x10.ast.RegionMaker_c;
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
import x10.ast.X10IntLit_c;
import x10.ast.X10SourceFile_c;
import x10.ast.X10Special_c;
import x10.ast.X10Unary_c;
import x10.constraint.XFailure;
import x10.constraint.XLocal;
import x10.constraint.XName;
import x10.constraint.XNameWrapper;
import x10.constraint.XTerms;
import x10.constraint.XVar;
import x10.types.ClosureDef;
import x10.types.ClosureInstance;
import x10.types.ClosureType_c;
import x10.types.FunctionType;
import x10.types.ParameterType;
import x10.types.ParameterType_c;
import x10.types.X10ClassDef;
import x10.types.X10ClassDef_c;
import x10.types.X10ClassType;
import x10.types.X10ConstructorDef;
import x10.types.X10ConstructorInstance;
import x10.types.X10ConstructorInstance_c;
import x10.types.X10Flags;
import x10.types.X10MethodDef;
import x10.types.X10MethodInstance;
import x10.types.X10TypeSystem_c;
import x10.types.constraints.CConstraint;
import x10.visit.X10DelegatingVisitor;
import x10cpp.Configuration;
import x10firm.types.TypeSystem;
import x10firm.types.X10NameMangler;

import com.sun.jna.Platform;

import firm.ArrayType;
import firm.ClassType;
import firm.Construction;
import firm.Entity;
import firm.Graph;
import firm.Ident;
import firm.Initializer;
import firm.MethodType;
import firm.Mode;
import firm.OO;
import firm.PointerType;
import firm.Program;
import firm.TargetValue;
import firm.bindings.binding_ircons.ir_linkage;
import firm.bindings.binding_ircons.ir_where_alloc;
import firm.bindings.binding_oo.ddispatch_binding;
import firm.bindings.binding_typerep.ir_type_state;
import firm.bindings.binding_typerep.ir_visibility;
import firm.nodes.Alloc;
import firm.nodes.Block;
import firm.nodes.Call;
import firm.nodes.Cmp;
import firm.nodes.Cond;
import firm.nodes.Load;
import firm.nodes.Node;
import firm.nodes.Proj;
import firm.nodes.Store;

/**
 * creates a firm-program (a collection of firm-graphs) from an X10-AST.
 */
public class X10FirmCodeGenerator extends X10DelegatingVisitor {
	/** names of builtin functions */
	private static final String X10_STRING_LITERAL = "x10_string_literal";
	
	/** name of saved this pointer in closure */
	private static final String X10_SAVED_THIS_LITERAL = "saved_this";
	
	/** The current firm construction object */
	private Construction con;

	/** To return Firm nodes for constructing expressions */
	private Node returnNode;

	/** Main Compiler object */
	private final Compiler compiler;

	/** typeSystem is used to map X10 types to Firm types (and modes) */
	final TypeSystem typeSystem;

	/** Mapping between X10MethodInstances and firm entities. */
	private final HashMap<X10MethodInstance, Entity> methodEntities = new HashMap<X10MethodInstance, Entity>();
	/** mapping between X10ConstructorInstances and firm entities */
	private final HashMap<X10ConstructorInstance, Entity> constructorEntities = new HashMap<X10ConstructorInstance, Entity>();

	/**
	 * Closure id for generating unique closure names
	 */
	private static long closureId = 1;
	
	/**
	 * Returns a unique closure name
	 * @return A unique closure name
	 */
	private static String getUniqueClosureName() {
		return "Firm_Closure_" + closureId++;
	}
	
	/** current firm context */
	private FirmContext firmContext = new FirmContext();

	/**
	 * Holds the corresponding target blocks for labeled continue and break statements.
	 */
	private class FirmLabel {

		/**
		 * Holds the target block for a labeled continue statement
		 */
		private Block continueBlock;

		/**
		 * Holds the target block for a labeled break statement
		 */
		private Block breakBlock;

		/** Constructor */
		public FirmLabel() {
			
		}

		/**
		 * Sets the target block for a labeled continue statement
		 * @param block The target block
		 */
		public void setContinueBlock(Block block) {
			continueBlock = block;
		}

		/**
		 * Returns the target block for a labeled continue statement
		 * @return The target block
		 */
		public Block getContinueBlock() {
			assert continueBlock != null;
			return continueBlock;
		}

		/**
		 * Sets the target block for a labeled break statement
		 * @param block The target block
		 */
		public void setBreakBlock(Block block) {
			breakBlock = block;
		}

		/**
		 * Returns the target block for a labeled break statement
		 * @return The target block
		 */
		public Block getBreakBlock() {
			assert breakBlock != null;
			return breakBlock;
		}
	}

	/**
	 * Class that holds attributes (true and false blocks, continue blocks, break blocks etc.) for a new scope.
	 * For every new scope we will clone the current (top) scope and set the adequate attributes for the new scope.
	 */
	private class FirmScope {

		/**
		 * Holds a reference to the upper FirmScope.
		 */
		FirmScope prev;

		/**
		 * Mapping between Labels (String) and the corresponding FirmLabels.
		 */
		private Map<String, FirmLabel> firmLabelMapper = new HashMap<String, FirmLabel>();

		/** Block we will jump into if an expression evaluates to true */
		private Block trueBlock;
		
		/** Block we will jump into if an expression evaluates to false */
		private Block falseBlock;
		
		/** Block we will jump into if we reach a continue statement */
		private Block continueBlock;
		
		/** Block we will jump into if we reach a break statement */
		private Block breakBlock;
		
		/** Reference to the current switch cond node -> null if we are not in a switch statement */
		private Node curSwitchCond;
		
		/** Proj number for the 'default' statement in a switch statement */
		private long curSwitchDefaultProjNr;

		/** constructor */
		public FirmScope() {
			
		}

		/** Sets the true block.
		 * @param block The block to set */
		public void setTrueBlock(Block block) {
			trueBlock = block;
		}

		/** Returns the true block.
		 * @return The true block */
		public Block getTrueBlock() {
			return trueBlock;
		}

		/** Sets the false block.
		 * @param block The block to set */
		public void setFalseBlock(Block block) {
			falseBlock = block;
		}

		/** Returns the false block.
		 * @return The false block */
		public Block getFalseBlock() {
			return falseBlock;
		}

		/** Sets the continue block.
		 * @param block The block to set */
		public void setContinueBlock(Block block) {
			continueBlock = block;
		}

		/** Returns the continue block.
		 * @return The continue block */
		public Block getContinueBlock() {
			assert continueBlock != null;
			return continueBlock;
		}

		/** Sets the break block.
		 * @param block The block to set */
		public void setBreakBlock(Block block) {
			breakBlock = block;
		}

		/** Returns the break block. Creates a new block, if the break block was
		 * not previously set.
		 * @return The break block */
		public Block getBreakBlock() {
			return breakBlock;
		}

		/** Returns true if the break block is set.
		 *  @return True or false
		 */
		public boolean isBreakBlockSet() {
			return breakBlock != null;
		}

		/** Sets the current switch condition node.
		 * @param cond The condition to set
		 */
		public void setCurSwitchCond(Node cond) {
			curSwitchCond = cond;
		}

		/** Returns the current switch condition node
		 * @return The current switch condition node
		 */
		public Node getCurSwitchCond() {
			assert curSwitchCond != null;
			return curSwitchCond;
		}

		/** Sets the projection number for the 'default' statement in the current switch statement
		 * @param projNr The projection number for the 'default' statement.
		 */
		public void setCurSwitchDefaultProjNr(long projNr) {
			curSwitchDefaultProjNr = projNr;
		}

		/**
		 * Returns the projection number of the 'default' label in the current switch statement
		 * @return The projection number of the 'default' statement
		 */
		public long getCurSwitchDefaultProjNr() {
			return curSwitchDefaultProjNr;
		}

		/**
		 * Sets the target block for a labeled continue statement.
		 * @param label The label of the continue statement.
		 * @param block The target block for the continue statement
		 */
		public void setBlockForLabeledContinue(String label, Block block) {
			FirmLabel firmLabel = getFirmLabel(label);
			firmLabel.setContinueBlock(block);
		}

		/**
		 * Returns the corresponding target block for a labeled continue block
		 * @param label The label of the continue statement
		 * @return The target block for the continue statement
		 */
		public Block getBlockForLabeledContinue(String label) {
			FirmLabel firmLabel = getFirmLabel(label);
			return firmLabel.getContinueBlock();
		}

		/**
		 * Sets the target block for a labeled break statement.
		 * @param label The label of the break statement.
		 * @param block The target block for the break statement
		 */
		public void setBlockForLabeledBreak(String label, Block block) {
			FirmLabel firmLabel = getFirmLabel(label);
			firmLabel.setBreakBlock(block);
		}

		/**
		 * Returns the corresponding target block for a labeled break block
		 * @param label The label of the break statement
		 * @return The target block for the break statement
		 */
		public Block getBlockForLabeledBreak(String label) {
			FirmLabel firmLabel = getFirmLabel(label);
			return firmLabel.getBreakBlock();
		}

		/**
		 * Helper function. Traverse all FirmScopes upwards and try to find the
		 * corresponding FirmLabel for the given string label.
		 * @param label The label we are searching for
		 * @return The corresponding FirmLabel or null if the given string label could not be found
		 */
		private FirmLabel getFirmLabelHelp(String label) {
			if(!firmLabelMapper.containsKey(label)) {
				if(prev != null) {
					return prev.getFirmLabelHelp(label);
				}
				return null;

			}
			return firmLabelMapper.get(label);
		}

		/**
		 * Returns the corresponding FirmLabel for the given string label
		 * @param label The label we are searching for
		 * @return The corresponding FirmLabel for the given string label
		 */
		private FirmLabel getFirmLabel(String label) {
			FirmLabel firmLabel = getFirmLabelHelp(label);
			assert firmLabel != null;

			return firmLabel;
		}

		/**
		 * Declare (Create) a new FirmLabel for the given string label in the current firm scope.
		 * @param label The string label
		 */
		public void declFirmLabel(String label) {
			assert !firmLabelMapper.containsKey(label);
			firmLabelMapper.put(label, new FirmLabel());
		}

		@Override
		public Object clone() {
			FirmScope clonedScope  		= new FirmScope();
			clonedScope.trueBlock     	= this.trueBlock;
			clonedScope.falseBlock		= this.falseBlock;
			clonedScope.continueBlock   = this.continueBlock;
			clonedScope.breakBlock      = this.breakBlock;
			// The local mapper needn`t be cloned

			return clonedScope;
		}
	}
	
	/** 
	 * Class for saving variable instances (locals and fields) and the appropriate "firm" indices. 
	 */
	private static class VarEntry {
		private int idx;
		private VarInstance<?> var;
		
		private VarEntry(final VarInstance<?> var_, final int idx_) {
			assert(var_ != null);
			var = var_;
			idx = idx_;
		}
		
		/**
		 * Creates a new var entry for a local instance
		 * @param loc_ The local instance
		 * @param idx_ The "local" index (firm) for the local variable
		 * @return The created var entry. 
		 */
		public static VarEntry newVarEntryForLocalInstance(final LocalInstance loc_, final int idx_) {
			return new VarEntry(loc_, idx_);
		}
		
		/**
		 * Creates a new var entry for a field instance
		 * @param field_ The field instance
		 * @return The created var entry.
		 */
		public static VarEntry newVarEntryForFieldInstance(final FieldInstance field_) {
			return new VarEntry(field_, -1);
		}
		
		/**
		 * The index of the var entry -> -1 if the var entry is actually a field instance
		 * @return The index of the local instance.
		 */
		public int getIdx() {
			return idx;
		}
		
		/**
		 * Returns the var instance of the var key
		 * @return The var instance
		 */
		public VarInstance<?> getVarInstance() {
			return var;
		}
	}

	/**
	 * Class that holds attributes (scopes, mapping of local instance variables etc.) for a new method.
	 * For every new method entry we will create a new firm context.
	 */
	private class FirmContext {
		/** Holds the topmost firmScope. -> Push a dummy frame in the current FirmContext */
		private FirmScope topFirmScope = new FirmScope();

		/** Maps VarInstances to the appropriate "VarEntry" entries */
		private Map<VarInstance<?>, VarEntry> varEntryMapper = new HashMap<VarInstance<?>, VarEntry>();
		
		/**
		 * Reference to the current class type
		 */
		private X10ClassType curClass;

		/**
		 * Will hold the corresponding statement if we have reached a labeled statement. Otherwise null.
		 */
		private Stmt stmt;

		/**
		 * Will hold the corresponding label if we have reached a labeled statement. Otherwise null.
		 */
		private String label;
		
		/**
		 * Reference to the upper firm context
		 */
		private FirmContext outer;
		
		/**
		 * True if we are currently in a closure
		 */
		private boolean inClosure = false;

		/**
		 * Create a new Firm context
		 */
		public FirmContext() {
			
		}
		
		/**
		 * Sets the current class
		 */
		public void setCurClass(X10ClassType curClass) {
			this.curClass = curClass;
		}
		
		/**
		 * Returns the current class
		 */
		public X10ClassType getCurClass() {
			assert curClass != null;
			return curClass;
		}
		
		/**
		 * Pushes a new firm context
		 * @param newContext The new firm context which should be pushed
		 * @return The new firm context which was pushed.
		 */
		public FirmContext pushFirmContext(FirmContext newContext) {
			assert newContext != null;
			newContext.outer = this;
			return newContext;
		}
		
		/**
		 * Pops the topmost firm context
		 * @return The upper firm context
		 */
		public FirmContext popFirmContext() {
			assert outer != null;
			return outer;
		}
		
		/**
		 * Saves that we are currently in a closure
		 */
		public void enterClosure() {
			inClosure = true;
		}
		
		/**
		 * Checks if we are currently in a closure
		 * @return True if we are currently in a closure
		 */
		public boolean isInClosure() {
			return inClosure;
		}
		
		/** Sets the "VarEntry" for a given local variable
		 * @param entry The "VarEntry" for the given local variable
		 */
		public void setVarEntry(VarEntry entry) {
			assert !varEntryMapper.containsKey(entry.getVarInstance());
			varEntryMapper.put(entry.getVarInstance(), entry);
		}

		/** Returns the "VarEntry" for a given instance variable
		 * @return The "VarEntry" of the given instance variable or null if the instance 
		 * variable could not be found
		 */
		public VarEntry getVarEntry(VarInstance<?> var) {
			VarEntry ret = varEntryMapper.get(var);
			if(ret == null) {
				if(outer != null) 
					return outer.getVarEntry(var);
				assert(false);
				return null;
			}
			
			return ret;
		}
		
		/** Returns the "VarEntry" for a given instance variable in the current scope
		 * @return The "VarEntry" of the given instance variable in the current scope or 
		 * null if the instance variable could not be found.
		 */
		public VarEntry getVarEntryInThisScope(VarInstance<?> var) {
			return varEntryMapper.get(var);
		}

		/** Pushes a new firm scope
		 * @param scope The firm scope which should be pushed
		 * @return The new firm scope
		 */
		public FirmScope pushFirmScope(FirmScope scope) {
			scope.prev = topFirmScope;
			topFirmScope = scope;
			return scope;
		}

		/** Pops the topmost firm scope
		 * @return The upper firm scope of the topmost firm scope
		 */
		public FirmScope popFirmScope() {
			assert topFirmScope != null;
			topFirmScope = topFirmScope.prev;
			return topFirmScope;
		}

		/** Returns the topmost firm scope
		 * @return Topmost firm scope
		 */
		public FirmScope getTopScope() {
			assert topFirmScope != null;
			return topFirmScope;
		}

		/**
		 * Set the statement and label in a labeled statement
		 * @param label The label of the labeled statement
		 * @param stmt The statement of the labeled statement
		 */
		public void setLabeledStmt(String label, Stmt stmt) {
			this.label = label;
			this.stmt  = stmt;
		}

		/**
		 * Resets the saved statement and label in the last seen labeled statement
		 */
		public void resetLabeledStmt() {
			this.label = null;
			this.stmt  = null;
		}

		/**
		 * Returns the statement of the last seen labeled statement
		 * @return The statement
		 */
		public Stmt getLabeledStmt() {
			return stmt;
		}

		/**
		 * Returns the label of the last seen labeled statement
		 * @return The label
		 */
		public String getLabel() {
			assert label != null;
			return label;
		}
	}

	/**
	 * If n is not already a condition node, build an extra compare and condition node.
	 * If n is a projection node create only a new condition node
	 * @param n	a Firm node
	 * @return a condition Firm node
	 */
	private Node makeCondition(Node n) {
		if(n instanceof Proj || !n.getMode().equals(Mode.getT())) {
			FirmScope topScope = firmContext.getTopScope();

			Block bTrue  = topScope.getTrueBlock();
			Block bFalse = topScope.getFalseBlock();

			Node proj = n;
			if(!(n instanceof Proj)) { // No projection, create an explicit compare and projection node.
				Node one  = con.newConst(1, n.getMode());
				Node cmp  = con.newCmp(n, one);
				proj 	  = con.newProj(cmp, Mode.getb(), Cmp.pnEq);
			}

			Node cond = con.newCond(proj);

			Node projTrue  = con.newProj(cond, Mode.getX(), Cond.pnTrue);
			Node projFalse = con.newProj(cond, Mode.getX(), Cond.pnFalse);

			bTrue.addPred(projTrue);
			bFalse.addPred(projFalse);

			return cond;
		}
		return n;
	}
	
	private Node makeExpressionCondition(final Expr e) {
		Node ret = visitExpression(e);
		return makeCondition(ret);
	}
	
	/**
	 * Evaluates the given expression and creates the appropriate firm nodes. Afterwards
	 * it creates a new true (holds the value 1) and false (holds the value 0) block for
	 * the results of the expression. Finally the true and false blocks are combined with
	 * a common phi node.
	 * @param E		A polyglot expression
	 * @return		A Phi firm node
	 */
	private Node makeConditionalPhiTrailer(final Expr E) {

	    Block cur    = con.getCurrentBlock();
		Block bTrue  = con.newBlock();
		Block bFalse = con.newBlock();

		con.setCurrentBlock(bTrue);
		Node jmp1 = con.newJmp();
		Node one  = con.newConst(1, Mode.getb());

		con.setCurrentBlock(bFalse);
		Node jmp2 = con.newJmp();
		Node zero = con.newConst(0, Mode.getb());

		con.setCurrentBlock(cur);

		FirmScope topScope = firmContext.getTopScope();
		FirmScope newScope = (FirmScope)topScope.clone();

		firmContext.pushFirmScope(newScope);
		{
			// TODO: Swap jmps if we are in an unary ! expr.
			newScope.setTrueBlock(bTrue);
			newScope.setFalseBlock(bFalse);

			makeExpressionCondition(E);
		}
		firmContext.popFirmScope();
		
		bTrue.mature();
		bFalse.mature();
		
		Block phiBlock = con.newBlock();
		phiBlock.addPred(jmp1);
		phiBlock.addPred(jmp2);

		con.setCurrentBlock(phiBlock);
		
		phiBlock.mature();

		return con.newPhi(new Node[]{one, zero}, Mode.getb());
	}

	/**
	 * Constructor for creating a new X10FirmCodeGenerator
	 *
	 * @param compiler The main compiler
	 * @param typeSystem The main type system
	 */
	public X10FirmCodeGenerator(Compiler compiler, TypeSystem typeSystem) {
		this.compiler   = compiler;
		this.typeSystem = typeSystem;
	}

	/** reset the remembered value of the returned node of an expression */
	private void resetReturnNode() {
		setReturnNode(null);
	}

	/**
	 * @param retNode	remember this node as holding the returned value of the current expression
	 */
	private void setReturnNode(Node retNode) {
		returnNode = retNode;
	}

	/**
	 * @return	the Firm node holding the returned value of the current expression
	 */
	private Node getReturnNode() {
		assert returnNode != null;
		return returnNode;
	}

	@Override
	public void visit(polyglot.ast.Node n) {
		/*
		 * X10DelegatingVisitor does not handle all node types, thus we need to
		 * dispatch the rest here.
		 */
		if (n instanceof X10ClassDecl_c) {
			visit((X10ClassDecl_c) n);
			return;
		} else if (n instanceof X10SourceFile_c) {
			visit((X10SourceFile_c) n);
			return;
		}

		throw new RuntimeException("Unhandled node type: " + n.getClass());
	}

	private void visit(X10SourceFile_c sourceFile) {
		for (TopLevelDecl top_level_declaration : sourceFile.decls()) {
			visit(top_level_declaration);
		}
	}

	@Override
	public void visit(X10ClassDecl_c n) {
		X10ClassDef def = n.classDef();
		ClassBody_c body = (ClassBody_c) n.body();
		X10ClassType classType = (X10ClassType)def.asType();

		assert (!def.isNested()) : ("Nested class alert!");
		
		firmContext.setCurClass(classType);

		// visit the node children (class body)
		List<ClassMember> members = body.members();

		for (ClassMember member : members) {
			visitAppropriate(member);
		}
	}

	@Override
	public void visit(ClassBody_c n) {
		X10ClassType currentClass = firmContext.getCurClass();
		if (currentClass.flags().isInterface()) {
			// nothing todo
		} else if (currentClass.isX10Struct()) {
			// TODO: Implement me
		} else {
			for (ClassMember member : n.members())
				visitAppropriate(member);
		}
	}

	private Entity getConstructorEntity(X10ConstructorInstance instance) {
		Entity entity = constructorEntities.get(instance);
		if (entity == null) {
			X10ClassType owner = (X10ClassType) instance.container();
			String name = "this";
			X10Flags flags = X10Flags.toX10Flags(instance.flags());

			firm.Type ownerFirm = typeSystem.asFirmCoreType(owner);
			firm.Type type      = typeSystem.asFirmType(instance);
			entity = new Entity(ownerFirm, name, type);
			if (flags.isAbstract()) {
				OO.setMethodAbstract(entity, true);
			}
			if (flags.isNative()) {
				entity.setVisibility(ir_visibility.ir_visibility_external);
			}
			OO.setMethodConstructor(entity, true);
			OO.setMethodExcludeFromVTable(entity, true);
			/* the binding of a constructor is static as we will not use the
			 * vtable to determine which method to call.
			 * (Note that we still have a "this" pointer anyway) */
			OO.setEntityBinding(entity, ddispatch_binding.bind_static);

			constructorEntities.put(instance, entity);
		}
		return entity;
	}

	/**
	 * Return entity for an X10 method
	 */
	private Entity getMethodEntity(X10MethodInstance instance) {
		Entity entity = methodEntities.get(instance);
		if (entity == null) {
			X10ClassType owner = (X10ClassType) instance.container();
			// TODO: mangle the complete method signature (but without the name of the defining class)
			//       This entity name is used during interface method lookups.
			String name = instance.name().toString();
			X10Flags flags = X10Flags.toX10Flags(instance.flags());

			firm.Type owningClass = typeSystem.asFirmCoreType(owner);
			firm.Type ownerFirm = flags.isStatic() ? Program.getGlobalType() : owningClass;
			firm.Type type = typeSystem.asFirmType(instance);
			entity = new Entity(ownerFirm, name, type);
			if (flags.isStatic()) {
				OO.setEntityBinding(entity, ddispatch_binding.bind_static);
				OO.setEntityAltNamespace(entity, owningClass);
			} else if (owner.flags().isInterface()) {
				OO.setEntityBinding(entity, ddispatch_binding.bind_interface);
			} else {
				OO.setEntityBinding(entity, ddispatch_binding.bind_dynamic);
			}
			if (flags.isAbstract()) {
				OO.setMethodAbstract(entity, true);
			}
			if (flags.isNative()) {
				entity.setVisibility(ir_visibility.ir_visibility_external);
			}
			
			// TODO: lookup the overwritten method and tell Firm about this relation. (add_entity_overwrites(..))
			//       - Needed during the vtable construction.
			
			methodEntities.put(instance, entity);
		}

		return entity;
	}

	/** Finds all locals in the given method.
	 *  @param code    method/constructor code
	 *  @param locals  Will hold all found locals.
	 */
	private List<LocalInstance> getAllLocalInstancesInCodeBlock(CodeBlock code) {
		List<LocalInstance> ret = new LinkedList<LocalInstance>();
		
		if (code.body() == null)
			return ret;
		 
		X10LocalDeclVisitor xLocalsVisitor = new X10LocalDeclVisitor();
		xLocalsVisitor.visit(code.body());
	
		List<LocalDecl_c> matchesList = xLocalsVisitor.getLocals();
		
		if(matchesList.size() == 0)
			return ret;
			
		for (LocalDecl_c c : matchesList) {
			// extract the local instances from the found "LocalDecl_c`s"
			LocalInstance locInstance = c.localDef().asInstance();
			
			ret.add(locInstance);
		}
		
		return ret;
	}

	private void constructGraph(Entity entity, CodeBlock code, boolean closure, List<LocalInstance> formals, List<LocalInstance> locals, boolean isStatic, X10ClassType owner) {		
		int nVars = formals.size() + locals.size();
		if (!isStatic) {
			nVars++;
		}
			
		Graph graph = new Graph(entity, nVars);
		Construction savedConstruction = con;
		con = new Construction(graph);
		
		FirmContext newFirmContext = new FirmContext();
		if(closure) {
			/* mark that we are currently in a closure */
			newFirmContext.enterClosure();
		}
		
		newFirmContext.setCurClass(owner);
		
		firmContext = firmContext.pushFirmContext(newFirmContext);

		Node args = graph.getArgs();
		if(!isStatic) {
			firm.Type ownerFirm = typeSystem.asFirmType(owner);

			/* map 'this' */
			Node projThis = con.newProj(args, ownerFirm.getMode(), 0);
			con.setVariable(0, projThis);
		}

		int idx = isStatic ? 0 : 1;

		// init and map all parameters.
		for (LocalInstance loc : formals) {
			Mode mode = typeSystem.getFirmMode(loc.type());
			Node projParam = con.newProj(args, mode, idx);
			con.setVariable(idx, projParam);
			
			// map the local instance with the appropriate idx.
			firmContext.setVarEntry(VarEntry.newVarEntryForLocalInstance(loc, idx));
			idx++;
		}

		// map all local variables.
		for (LocalInstance loc : locals) {
			// map the local instance with the appropriate idx.
			firmContext.setVarEntry(VarEntry.newVarEntryForLocalInstance(loc, idx));
			idx++;
		}
		
		// Walk body and construct graph
		visitAppropriate(code.body());
		
		// create Return node if there was no explicit return statement yet
		if (!con.getCurrentBlock().isBad()) {
			assert ((MethodType)entity.getType()).getNRess() == 0;
			Node mem = con.getCurrentMem();
			Node returnn = con.newReturn(mem, new Node[0]);
			con.getGraph().getEndBlock().addPred(returnn);
		}
		
		con.finish();
			
		con = savedConstruction;
		
		firmContext = firmContext.popFirmContext();
	}

	@Override
	public void visit(MethodDecl_c dec) {
		X10MethodDef      def            = (X10MethodDef) dec.methodDef();
		X10MethodInstance methodInstance = (X10MethodInstance) def.asInstance();
		X10Flags          flags          = X10Flags.toX10Flags(methodInstance.flags());
		Entity            entity         = getMethodEntity(methodInstance);

		if (flags.isNative() || flags.isAbstract()) { 
			/* native code is defined elsewhere, so nothing left to do */
			return;
		}

		List<LocalInstance> formals = methodInstance.formalNames();
		boolean isStatic = flags.isStatic();
		X10ClassType owner = (X10ClassType) methodInstance.container();
		
		// extract all formals and locals from the method.
		List<LocalInstance> locals = getAllLocalInstancesInCodeBlock(dec);
		constructGraph(entity, dec, false, formals, locals, isStatic, owner);

		if (isMainMethod(dec)) {
			processMainMethod(entity);
		}
	}

    private boolean seenMain = false;
    private boolean warnedAboutMain = false;
    /** test if a method is the main method (the one we start first when the
     * program runs)
     * Note: This code is copied from the ASTQuery class. (It doesn't have the
     * public modifier there so we can't use it directly. Also ASTQuery
     * unnecessarily depends on a Translator which we don't have)
     */
	private boolean isMainMethod(MethodDecl dec) {
		X10ClassType container = (X10ClassType) dec.methodDef().asInstance()
				.container();
		Context context = null;
		assert (container.isClass());
		boolean result = (Configuration.MAIN_CLASS == null || container
				.fullName().toString().equals(Configuration.MAIN_CLASS))
				&& dec.name().toString().equals("main")
				&& dec.flags().flags().isPublic()
				&& dec.flags().flags().isStatic()
				&& dec.returnType().type().isVoid()
				&& (dec.formals().size() == 1)
				&& typeSystem.isSubtype(dec.formals().get(0).type()
						.type(), typeSystem.Array(typeSystem.String()), context);
		if (result) {
			boolean dash_c = compiler.sourceExtension().getOptions().post_compiler == null;
			if (seenMain && !warnedAboutMain && !dash_c
					&& Configuration.MAIN_CLASS == null) {
				compiler.errorQueue().enqueue(
						ErrorInfo.SEMANTIC_ERROR,
						"Multiple main() methods encountered.  "
								+ "Please specify MAIN_CLASS.");
				warnedAboutMain = true;
			}
			seenMain = true;
		}
		return result;
	}

	private void processMainMethod(Entity mainEntity) {
		/* let's create a simple "main" function which just calls the other main */
		firm.Type global = Program.getGlobalType();
		/* let's hope the X10 int type is compatible to the C int-type */
		firm.Type intType = typeSystem.asFirmType(typeSystem.Int());
		firm.Type[] returnTypes = new firm.Type[] { intType };
		firm.Type[] parameterTypes = new firm.Type[] {};
		MethodType mainType = new MethodType(parameterTypes, returnTypes);
		Entity entity = new Entity(global, "main", mainType);
		String ldIdent = "main";
		if (Platform.isMac() || Platform.isWindows()) {
			ldIdent = "_" + ldIdent;
		}
		entity.setLdIdent(ldIdent);
		entity.setVisibility(ir_visibility.ir_visibility_default);
		entity.addLinkage(ir_linkage.IR_LINKAGE_HIDDEN_USER.val);

		Graph graph = new Graph(entity, 0);
		Construction construction = new Construction(graph);
		Node symConst = construction.newSymConst(mainEntity);
		Node mem = construction.getCurrentMem();
		firm.Type type = mainEntity.getType();
		firm.Type paramType = ((MethodType) type).getParamType(0);
		/* TODO: convert the arguments passed to the Array[String] */
		Node args = construction.newConst(paramType.getMode().getNull());
		Node call = construction.newCall(mem, symConst, new Node[] { args }, type);
		Node newMem = construction.newProj(call, Mode.getM(), Call.pnM);
		construction.setCurrentMem(newMem);

		Node returnMem = construction.getCurrentMem();
		Node zero = construction.newConst(intType.getMode().getNull());
		Node returnn = construction.newReturn(returnMem, new Node[] {zero});
		construction.getGraph().getEndBlock().addPred(returnn);
		construction.setCurrentBlockBad();

		construction.finish();
		Program.setMainGraph(graph);
	}

	@Override
	public void visit(ConstructorDecl_c dec) {
		X10ConstructorDef      def      = (X10ConstructorDef) dec.constructorDef();
		X10Flags               flags    = X10Flags.toX10Flags(def.flags());
		X10ConstructorInstance instance = (X10ConstructorInstance) def.asInstance();
		Entity                 entity   = getConstructorEntity(instance);

		if (flags.isNative()) {
			/* native code is defined elsewhere, so nothing left to do */
			return;
		}

		List<LocalInstance> formals = instance.formalNames();
		boolean isStatic = flags.isStatic();
		X10ClassType owner = (X10ClassType) instance.container();
		
		// extract all formals and locals from the method.
		List<LocalInstance> locals = getAllLocalInstancesInCodeBlock(dec);
		constructGraph(entity, dec, false, formals, locals, isStatic, owner);
	}

	private Initializer expr2Initializer(Expr expr) {
		final Initializer result;
		if (expr instanceof IntLit_c) {
			TargetValue targetValue = getIntLitTarval((IntLit_c) expr);
			result = new Initializer(targetValue);
		} else if (expr instanceof BooleanLit_c) {
			TargetValue targetValue = getBooleanLitTargetValue((BooleanLit_c) expr);
			result = new Initializer(targetValue);
		} else if (expr instanceof FloatLit_c) {
			TargetValue targetValue = getFloatLitTargetValue((FloatLit_c) expr);
			result = new Initializer(targetValue);
		} else if (expr instanceof CharLit_c) {
			TargetValue targetValue = getCharLitTargetValue((CharLit_c) expr);
			result = new Initializer(targetValue);
		} else {
			throw new RuntimeException("unimplemented initializer expression");
		}
		return result;
	}

	@Override
	public void visit(FieldDecl_c dec) {
		X10Flags flags = X10Flags.toX10Flags(dec.flags().flags());

		/* make sure enclosing classtype has been created */
		FieldInstance instance = dec.fieldDef().asInstance();
		typeSystem.asFirmType(instance.container());
		
		firmContext.setVarEntry(VarEntry.newVarEntryForFieldInstance(instance));

		/* static fields may have initializers */
		if (flags.isStatic()) {
			Expr init = dec.init();
			if (init != null) {
				Initializer initializer = expr2Initializer(init);
				Entity entity = typeSystem.getEntityForField(dec.fieldDef().asInstance());
				entity.setInitializer(initializer);
			}
		}
	}

	@Override
	public void visit(Switch_c n) {

		boolean hasExplicitDefaultCase = false;
		final Block curBlock           = con.getCurrentBlock();
		final Node expr                = visitExpression(n.expr());
		final Node switchCond          = con.newCond(expr);

		long defNr    = 0;
		long numCases = 0;
		for(SwitchElement elem : n.elements()) {
			if(elem instanceof Case) {
				Case c = (Case)elem;
				if(c.isDefault()) {
					hasExplicitDefaultCase = true;
					continue;
				}

				if(c.value() > defNr)
					defNr = c.value();

				numCases++;
			}
		}

		if(defNr == Integer.MAX_VALUE) { // TODO: Adjust it to Long.MAX_VALUE -> Firm only supports Int (32 Bit) as projection numbers.
			Set<Long> vals = new HashSet<Long>();
			for(SwitchElement elem : n.elements()) {
				if(elem instanceof Case) {
					Case c = (Case)elem;
					if(c.isDefault())
						continue;

					vals.add(Long.valueOf(c.value()));
				}
			}

			int i;
			for(i = 0; i < Integer.MAX_VALUE; i++)
				if(!vals.contains(Long.valueOf(i)))
					break;

			defNr = i;
		} else {
			defNr++;
		}
		/* if Cond is not a Bad node yet, set defaultProj number */
		if (switchCond instanceof Cond) {
			Cond cond = (Cond) switchCond;
			cond.setDefaultProj((int)defNr); // TODO: Adjust the defNr (Long)
		}

		con.setCurrentBlockBad();

		FirmScope topScope = firmContext.getTopScope();
		FirmScope newScope = (FirmScope)topScope.clone();

		Block bBreak = null;

		firmContext.pushFirmScope(newScope);
		{
			// Reset the break block -> Break block will be automatically created in the evaluation of the
			// switch statement if we need one. (getBreakBlock())
			newScope.setBreakBlock(null);
			newScope.setCurSwitchCond(switchCond);
			newScope.setCurSwitchDefaultProjNr(defNr);

			for(SwitchElement elem : n.elements())
				visitAppropriate(elem);

			// Check if a new break block was created.
			if(newScope.isBreakBlockSet()) {
				bBreak = newScope.getBreakBlock();
			}
		}
		firmContext.popFirmScope();

		if(!con.getCurrentBlock().isBad()) {
			Node jmp = con.newJmp();
			if(bBreak == null)
				bBreak = con.newBlock();

			bBreak.addPred(jmp);
		}

		if(!hasExplicitDefaultCase && !curBlock.isBad()) {
			con.setCurrentBlock(curBlock);
			Node proj = con.newProj(switchCond, Mode.getX(), (int)defNr);	// TODO: Adjust the defNr (Long)

			if(bBreak == null)
				bBreak = con.newBlock();

			bBreak.addPred(proj);
		}
		
		if(bBreak != null)
			bBreak.mature();

		if(bBreak == null)
			con.setCurrentBlockBad();
		else
			con.setCurrentBlock(bBreak);
	}

	@Override
	public void visit(SwitchBlock_c n) {
		for(Stmt stmt : n.statements())
			visitAppropriate(stmt);
	}

	@Override
	public void visit(Case_c n) {
		Node fallthrough 	= con.getCurrentBlock().isBad() ? null : con.newJmp();
		Block block 		= con.newBlock();

		FirmScope topScope 	  = firmContext.getTopScope();
		Node switchCond       = topScope.getCurSwitchCond();
		Block switchCondBlock = (Block)switchCond.getBlock();

		con.setCurrentBlock(switchCondBlock);
		if(!n.isDefault()) {
			// Case label
			long val = n.value();
			Node proj = con.newProj(switchCond, Mode.getX(), (int)val); // TODO: Adjust the val (Long)
			block.addPred(proj);
		} else {
			// default label
			long projNr = topScope.getCurSwitchDefaultProjNr();
			Node proj = con.newProj(switchCond, Mode.getX(), (int)projNr); // TODO: Adjust the projNr (Long)
			block.addPred(proj);
		}

		if(fallthrough != null)
			block.addPred(fallthrough);
		
		block.mature();

		con.setCurrentBlock(block);
	}

	@Override
	public void visit(Branch_c br) {
		if(con.getCurrentBlock().isBad())
			return;

		FirmScope topScope = firmContext.getTopScope();
		Block target = null;
		if (br.labelNode() != null) {
			// labeled continue or break
			String label = br.labelNode().id().toString();

			if(br.kind() == Branch.CONTINUE)
				target = topScope.getBlockForLabeledContinue(label);
			else
				target = topScope.getBlockForLabeledBreak(label);
		} else {
			// unlabeled continue or break
			if (br.kind() == Branch.CONTINUE) {
				target = topScope.getContinueBlock();
			} else {
				target = topScope.getBreakBlock();
				if (target == null) {
					target = con.newBlock();
					topScope.setBreakBlock(target);
				}
			}
		}

		Node jmp = con.newJmp();
		target.addPred(jmp);

		con.setCurrentBlockBad();
	}


	@Override
	public void visit(Labeled_c label) {

		Stmt stmt 	= label.statement();
		String lab 	= label.labelNode().id().toString();

		// Mark the corresponding statement with the appropriate label
		firmContext.setLabeledStmt(lab, stmt);

		// Declare the label in the current firm scope
		FirmScope topScope = firmContext.getTopScope();
		FirmScope newScope = (FirmScope)topScope.clone();

		firmContext.pushFirmScope(newScope);
		{
			newScope.declFirmLabel(lab);
			visitAppropriate(stmt);
		}
		firmContext.popFirmScope();
	}

	@Override
	public void visit(Assign_c asgn) {
		Expr lhs = asgn.left();
		Expr rhs = asgn.right();

		if(lhs instanceof Local_c) { // Assignment to a local variable -> Assignments to saved variables are not allowed in closures. 
			Node leftRet  = visitExpression(lhs);
			Node rightRet = visitExpression(rhs);

			Local_c lhsLocal = (Local_c)lhs;
			LocalInstance loc = lhsLocal.localInstance();
			VarEntry var = firmContext.getVarEntry(loc);

			int idx = var.getIdx();
			con.setVariable(idx, rightRet);
			setReturnNode(con.getVariable(idx, leftRet.getMode()));
		} else if (lhs instanceof Field_c) {
			Field_c field = (Field_c) lhs;
			FieldInstance instance = field.fieldInstance();
			FieldInstance def = instance.def().asInstance();
			
			Node savedThisPointer = null;
			if(firmContext.isInClosure()) {
				savedThisPointer = doClosureFieldRead(X10_SAVED_THIS_LITERAL, firmContext.getCurClass());
			}
			
			X10Flags flags = X10Flags.toX10Flags(def.flags());
			/* make sure the entity container type has been constructed */
			typeSystem.asFirmCoreType(def.container());
			Entity entity = typeSystem.getEntityForField(def);

			Node address;
			if (flags.isStatic()) {
				address = con.newSymConst(entity);
			} else {
				Receiver target = field.target();
				Node objectPointer = null;
				if(savedThisPointer != null) { /* for closures */
					objectPointer = savedThisPointer;
				} else {
					objectPointer = visitExpression((Expr)target);
				}
				
				address = con.newSel(objectPointer, entity);
			}
			Node rightRet = visitExpression(rhs);

			firm.Type type = typeSystem.asFirmType(def.type());
			assert rightRet.getMode().equals(type.getMode());

			Node mem = con.getCurrentMem();
			Node store = con.newStore(mem, address, rightRet);
			Node newMem = con.newProj(store, Mode.getM(), Store.pnM);
			con.setCurrentMem(newMem);
			setReturnNode(rightRet);
		} else {
			throw new RuntimeException("Unexpected assignment target");
		}
	}

	@Override
	public void visit(Return_c ret) {
		Node retNode;

		Node mem = con.getCurrentMem();
		Expr e = ret.expr();
		if (e != null) {
			Node retValue = visitExpression(e);
			retNode = con.newReturn(mem, new Node[]{retValue});
		} else {
			retNode = con.newReturn(mem, new Node[]{});
		}

		/* for error detection */
		con.getGraph().getEndBlock().addPred(retNode);
		con.setCurrentBlockBad();
	}

	@Override
	public void visit(LocalDecl_c n) {
		Expr initexpr = n.init();

		if (initexpr != null) {
			LocalInstance loc = n.localDef().asInstance();
			
			Node initNode = visitExpression(initexpr);
			VarEntry var = firmContext.getVarEntry(loc);
			int idx = var.getIdx();

			con.setVariable(idx, initNode);
		}
	}

	@Override
	public void visit(Block_c b) {
		List<Stmt> stmts = b.statements();

		for (Stmt s : stmts)
			visitAppropriate(s);
	}

	@Override
	public void visit(StmtSeq_c n) {
		List<Stmt> stmts = n.statements();

		for (Stmt s : stmts)
			visitAppropriate(s);
	}

	@Override
	public void visit(StmtExpr_c n) {
		// visit the children
		List<Stmt> stmts = n.statements();

		for (Stmt stmt : stmts)
			visitAppropriate(stmt);

		// evaluate the stmt expr
		Expr e = n.result();
		if (e != null)
			visitAppropriate(e);
	}

	@Override
	public void visit(Do_c n) {

		String label = null;
		if(firmContext.getLabeledStmt() == n) {
			label = firmContext.getLabel();
			firmContext.resetLabeledStmt();
		}

		Block bTrue  = con.newBlock();
		Block bCond  = con.newBlock();
		Block bFalse = con.newBlock();

		bTrue.addPred(con.newJmp());
		con.setCurrentBlock(bTrue);

		FirmScope topScope  = firmContext.getTopScope();
		FirmScope newScope  = (FirmScope)topScope.clone();

		firmContext.pushFirmScope(newScope);
		{
			newScope.setBreakBlock(bFalse);
			newScope.setContinueBlock(bCond);

			if(label != null) {
				newScope.setBlockForLabeledBreak(label, bFalse);
				newScope.setBlockForLabeledContinue(label, bCond);
			}

			Stmt body = n.body();
			visitAppropriate(body);
		}
		firmContext.popFirmScope();

		if(con.getCurrentBlock().isBad()) {
			return;
			/* The stmt:
			 * do {
			 * 		'STMT`s'
			 *      return 'EXPR';
			 * } while(booleanExpr);
			 * // "no return stmt"
			without an explicit return at the end of the do ... while stmt seems to be a valid
			stmt in a method with an explicit return value. -> So we will stop the firm generation
			if we are currently in a bad block.
			*/
		}

		bCond.addPred(con.newJmp());
		
		bCond.mature();

		con.setCurrentBlock(bCond);

		topScope  = firmContext.getTopScope();
		newScope  = (FirmScope)topScope.clone();

		firmContext.pushFirmScope(newScope);
		{
			newScope.setTrueBlock(bTrue);
			newScope.setFalseBlock(bFalse);

			makeExpressionCondition(n.cond());
		}
		firmContext.popFirmScope();
		
		bTrue.mature();
		bFalse.mature();

		con.setCurrentBlock(bFalse);
	}

	@Override
	public void visit(While_c n) {

		// condition evaluates to false -> nothing to do
		// TODO: Something is wrong with the method condIsConstantTrue
//		if(!n.condIsConstantTrue())
//			return;

		String label = null;
		if(firmContext.getLabeledStmt() == n) {
			label = firmContext.getLabel();
			firmContext.resetLabeledStmt();
		}

		Block bCond  = con.newBlock();
		Block bTrue  = con.newBlock();
		Block bFalse = con.newBlock();

		bCond.addPred(con.newJmp());
		con.setCurrentBlock(bCond);

		FirmScope topScope = firmContext.getTopScope();
		FirmScope newScope = (FirmScope)topScope.clone();

		firmContext.pushFirmScope(newScope);
		{
			newScope.setTrueBlock(bTrue);
			newScope.setFalseBlock(bFalse);

			makeExpressionCondition(n.cond());
		}
		firmContext.popFirmScope();
		
		bTrue.mature();

		con.setCurrentBlock(bTrue);

		topScope = firmContext.getTopScope();
		newScope = (FirmScope)topScope.clone();

		firmContext.pushFirmScope(newScope);
		{
			newScope.setBreakBlock(bFalse);
			newScope.setContinueBlock(bCond);

			if(label != null) {
				newScope.setBlockForLabeledBreak(label, bFalse);
				newScope.setBlockForLabeledContinue(label, bCond);
			}

			Stmt body = n.body();
			visitAppropriate(body);
		}
		firmContext.popFirmScope();
		
		bFalse.mature();

		if(!con.getCurrentBlock().isBad())
			bCond.addPred(con.newJmp());
		
		bCond.mature();

		con.setCurrentBlock(bFalse);
	}

	@Override
	public void visit(Conditional_c n) {

		// check if we have a constant condition
		if(n.cond().isConstant()) {
			@SuppressWarnings("boxing")
			boolean cond = (Boolean)n.cond().constantValue();
			if(cond) {
				visitExpression(n.consequent());
				// return node is automatically set.
				return;
			}

			visitExpression(n.alternative());
			return;
		}

		Block bTrue    = con.newBlock();
		Block bFalse   = con.newBlock();
		Block curBlock = con.getCurrentBlock();

		con.setCurrentBlock(bTrue);

		Node trueExpr  = visitExpression(n.consequent());
		Node endIf     = con.newJmp();

		con.setCurrentBlock(bFalse);

		Node falseExpr = visitExpression(n.alternative());
		Node endElse   = con.newJmp();

		con.setCurrentBlock(curBlock);

		FirmScope topScope = firmContext.getTopScope();
		FirmScope newScope = (FirmScope)topScope.clone();

		firmContext.pushFirmScope(newScope);
		{
			newScope.setTrueBlock(bTrue);
			newScope.setFalseBlock(bFalse);

			makeExpressionCondition(n.cond());
		}
		firmContext.popFirmScope();
		
		bFalse.mature();
		
		// add a common phi block for the true and false expressions.
		Block phiBlock = con.newBlock();
		phiBlock.addPred(endIf);
		phiBlock.addPred(endElse);

		con.setCurrentBlock(phiBlock);
		
		phiBlock.mature();

		Node ret = con.newPhi(new Node[]{trueExpr, falseExpr}, falseExpr.getMode());
		setReturnNode(ret);
	}

	@Override
	public void visit(If_c n) {
		Block bTrue  = con.newBlock();
		Block bAfter = con.newBlock();
		Block bFalse = null; // block will only be created if we have an else stmt.

		FirmScope topScope = firmContext.getTopScope();
		FirmScope newScope = (FirmScope)topScope.clone();

		firmContext.pushFirmScope(newScope);
		{
			newScope.setTrueBlock(bTrue);

			if (n.alternative() != null) {
				bFalse = con.newBlock();
				newScope.setFalseBlock(bFalse);
			} else {
				newScope.setFalseBlock(bAfter);
			}

			makeExpressionCondition(n.cond());
		}
		firmContext.popFirmScope();

		con.setCurrentBlock(bTrue);

		resetReturnNode();
		visitAppropriate(n.consequent());

		Node endIf = null;
		if(con.getCurrentBlock().isBad())
			con.setCurrentBlock(bTrue);
		else
			endIf = con.newJmp();
		
		bTrue.mature();

		if (n.alternative() != null) {
			Stmt alternative = n.alternative();
			if (alternative instanceof Block_c) {
				Block_c block = (Block_c) alternative;
				if (block.statements().size() == 1 && block.statements().get(0) instanceof If_c)
					alternative = block.statements().get(0);
			}

			con.setCurrentBlock(bFalse);
			visitAppropriate(alternative);

			if(con.getCurrentBlock().isBad())
				con.setCurrentBlock(bFalse);
			else {
				bAfter.addPred(con.newJmp());
			}
			
			if(bFalse != null)
				bFalse.mature();
		}

		con.setCurrentBlock(bAfter);

		if(endIf != null)
			bAfter.addPred(endIf);
		
		bAfter.mature();
	}

	@Override
	public void visit(Empty_c n) {
		/* empty statements are irrelevant for Firm construction */
	}

	@Override
	public void visit(Eval_c n) {
		/* Polyglot Eval captures an expression and is a statement.
		 * Just process the expression and throw away its value. */
		visitAppropriate(n.expr());
		resetReturnNode();
	}

	@Override
	public void visit(X10Call_c n) {
		/* determine called function */
		X10MethodInstance methodInstance = (X10MethodInstance)n.methodInstance().def().asInstance();

		/* Primitive types are represented as structs in X10.
		 * We lower the calls to operations here.
		 */
		final String signature = methodInstance.signature();
		if (signature.startsWith("operator")) {
			X10ClassType owner = (X10ClassType) methodInstance.container();
			if (owner.toString().startsWith("x10.lang.Int")) { /* an int */
				final char opChar = signature.charAt(8);
				resetReturnNode();
				switch (opChar) {
				case '+':
					createPlus(n);
					return;
				case '-':
					createMinus(n);
					return;
				case '<':
					createLessThan(n);
					return;
				default:
					break;
				}
			}
		}

		/* Not a primitive type. Construct Call. */
		Entity entity = getMethodEntity(methodInstance);
		
		firm.MethodType type = (MethodType) entity.getType();
		int param_count = type.getNParams();
		List<Expr> arguments = n.arguments();
			
		if (arguments.size()+1 == param_count) {
			/* arguments is immutable, so we construct a new list */
			List<Expr> na = new LinkedList<Expr>();
			na.add(0, (Expr)n.target());
			na.addAll(arguments);
			arguments = na;
		}
		assert arguments.size() == param_count : "parameters are off : "+arguments.size()+" vs "+param_count;
		Node[] parameters = new Node[param_count];
		for (int i=0; i<param_count; i++) {
			parameters[i] = visitExpression(arguments.get(i));
		}
		
		Node address;
		if (methodInstance.flags().isStatic()) {
			address = con.newSymConst(entity);			
		} else {
			address = con.newSel(parameters[0], entity);
		}
		
		Node mem = con.getCurrentMem();
		Node call = con.newCall(mem, address, parameters, type);
		Node newMem = con.newProj(call, Mode.getM(), Call.pnM);
		con.setCurrentMem(newMem);

		if (type.getNRess() == 0) {
			return; /* no return value, we're done */
		}
		assert (type.getNRess() == 1); /* X10 does not support multiple return values */
		firm.Type ret_type = type.getResType(0);
		Node all_results = con.newProj(call, Mode.getT(), Call.pnTResult);
		Mode mode = ret_type.getMode();
		if (mode == null) {
			/* classes do not have modes assigned, use pointer mode */
			mode = Mode.getP();
			// TODO structs have value semantics
		}
		Node ret = con.newProj(all_results, mode, 0);
		setReturnNode(ret);
	}

	@Override
	public void visit(X10ConstructorCall_c n) {
		/* TODO: check for this or super */

		/* determine called function */
		X10ConstructorInstance instance = n.constructorInstance();
		Entity entity = getConstructorEntity(instance);
		firm.MethodType type = (MethodType) entity.getType();
		Node address = con.newSymConst(entity);

		int param_count = type.getNParams();
		Node[] parameters = new Node[param_count];
		int p = 0;
		parameters[p++] = getThis(Mode.getP());
		for (Expr expr : n.arguments()) {
			parameters[p++] = visitExpression(expr);
		}
		assert(p == param_count);
		Node mem = con.getCurrentMem();
		Node call = con.newCall(mem, address, parameters, type);
		Node newMem = con.newProj(call, Mode.getM(), Call.pnM);
		con.setCurrentMem(newMem);
	}

	/**
	 * Creates a Firm Add node corresponding to n
	 * @param n		a operator+ call on x10.lang.Int
	 */
	private void createPlus(X10Call_c n) {
		Node leftFirm = visitExpression(n.arguments().get(0));
		Node rightFirm = visitExpression(n.arguments().get(1));

		Node add = con.newAdd(leftFirm, rightFirm, Mode.getIs());
		setReturnNode(add);
	}

	/**
	 * Creates a Firm Sub node corresponding to n
	 * @param n		a operator- call on x10.lang.Int
	 */
	private void createMinus(X10Call_c n) {
		Node rightFirm;
		Node leftFirm;
		if (n.arguments().size() == 2) {
			leftFirm = visitExpression(n.arguments().get(0));
			rightFirm = visitExpression(n.arguments().get(1));
		} else {
			assert (n.arguments().size() == 1);
			leftFirm = con.newConst(0, Mode.getIs());
			rightFirm = visitExpression(n.arguments().get(0));
		}

		Node sub = con.newSub(leftFirm, rightFirm, Mode.getIs());
		setReturnNode(sub);
	}

	/**
	 * @param expr	an X10 Expr node
	 * @return a Firm node containing the result value of the expression
	 */
	private Node visitExpression(Expr expr) {
		resetReturnNode();
		visitAppropriate(expr);
		Node ret = getReturnNode();
		return ret;
	}

	/**
	 * Creates a comparison corresponding to n
	 * @param n		a operator< call on x10.lang.Int
	 */
	private void createLessThan(X10Call_c n) {
		Node leftFirm = visitExpression(n.arguments().get(0));
		Node rightFirm = visitExpression(n.arguments().get(1));

		Node cmp = con.newCmp(leftFirm, rightFirm);
		Node projLT = con.newProj(cmp, Mode.getb(),	Cmp.pnLt);
		setReturnNode(projLT);
	}

	@Override
	public void visit(Field_c n) {
		FieldInstance instance = n.fieldInstance();
		FieldInstance def = instance.def().asInstance();
		
		Node savedThisPointer = null;
		if(firmContext.isInClosure()) {
			savedThisPointer = doClosureFieldRead(X10_SAVED_THIS_LITERAL, firmContext.getCurClass());
		}
		
		X10Flags flags = X10Flags.toX10Flags(def.flags());
		/* make sure enclosing class-type has been created */
		typeSystem.asFirmType(def.container());
		Entity entity = typeSystem.getEntityForField(def);

		Node address;
		if (flags.isStatic()) {
			address = con.newSymConst(entity);
		} else {
			Receiver target = n.target();
			Node objectPointer = visitExpression((Expr)target);
			if(savedThisPointer != null) { // for closure 
				address = con.newSel(savedThisPointer, entity);
			} else {
				address = con.newSel(objectPointer, entity);
			}
		}

		firm.Type type = typeSystem.asFirmType(def.type());
		Node mem = con.getCurrentMem();
		Mode loadMode = type.getMode();
		Node load = con.newLoad(mem, address, loadMode);
		Node newMem = con.newProj(load, Mode.getM(), Load.pnM);
		Node result = con.newProj(load, loadMode, Load.pnRes);
		con.setCurrentMem(newMem);
		setReturnNode(result);
	}
	
	/**
	 * Returns the appropriate field instance from a given class type and field name (Only for closure implementation)
	 * @param closureType The class type of the closure
	 * @param name The name of the field (only the name, no type names etc.) 
	 * @return The appropriate field instance
	 */
	private FieldInstance getClosureFieldInstance(X10ClassType closureType, String name) {
		X10ClassDef closureDef = closureType.x10Def();			
     	FieldInstance fInst = null;
     	for(FieldDef fDef : closureDef.fields()) {
     		if(fDef.name().toString().equals(name)) {
     			fInst = fDef.asInstance();
     			break;
     		}
     	}
     	assert(fInst != null);
     	
     	return fInst;
	}
	
	/**
	 * Generate the appropriate firm nodes for a field read operation in a closure
	 * @param fieldName The name of the field
	 * @param closureType The class type of the closure
	 * @return The proj node (result) of the generated firm graph
	 */
	private Node doClosureFieldRead(String fieldName, X10ClassType closureType) {
		FieldInstance fInst = getClosureFieldInstance(closureType, fieldName);
		Entity entity = typeSystem.getEntityForField(fInst);
		
		firm.Mode mode = typeSystem.getFirmMode(closureType);
		Node thisPointer = getThis(mode);
		Node address = con.newSel(thisPointer, entity);

		firm.Type type = typeSystem.asFirmType(fInst.type());
		Node mem = con.getCurrentMem();
		Mode loadMode = type.getMode();
		Node load = con.newLoad(mem, address, loadMode);
		Node newMem = con.newProj(load, Mode.getM(), Load.pnM);
		Node result = con.newProj(load, loadMode, Load.pnRes);
		con.setCurrentMem(newMem);
		
		return result;
	}
	
	/**
	 * Generate the appropriate firm nodes for a field write operation in a closure
	 * @param objectPointer The appropriate "this" node
	 * @param fieldName The name of the field
	 * @param closureType The class type of the closure
	 * @param rhs The rhs of the write operation
	 */
	private void doClosureFieldWrite(Node objectPointer, String fieldName, X10ClassType closureType, Node rhs) {
    	FieldInstance fInst = getClosureFieldInstance(closureType, fieldName);
    	Entity entity = typeSystem.getEntityForField(fInst);

		Node address = con.newSel(objectPointer, entity);
		firm.Type type = typeSystem.asFirmType(fInst.type());
		assert rhs.getMode().equals(type.getMode());

		Node mem = con.getCurrentMem();
		Node store = con.newStore(mem, address, rhs);
		Node newMem = con.newProj(store, Mode.getM(), Store.pnM);
		con.setCurrentMem(newMem);
	}

	@Override
	public void visit(Local_c n) {
		LocalInstance loc = n.localInstance();
		VarEntry var = null;
		
		if(firmContext.isInClosure()) {
			var = firmContext.getVarEntryInThisScope(loc);
			if(var == null) {
				/* it`s a field of the closure */
				Node ret = doClosureFieldRead(loc.def().name().toString(), firmContext.getCurClass());
				setReturnNode(ret);
				return;
			}
			// it`s actually a local instance in the closure 
			// generate code for a normal local instance. 
		} else {
			var = firmContext.getVarEntry(loc);
		}
		
		int idx = var.getIdx();
		Node ret = con.getVariable(idx, typeSystem.getFirmMode(loc.type()));
		setReturnNode(ret);
	}

	@Override
	public void visit(New_c n) {
		Type type = n.objectType().type();
		Node res = doNewAlloc(n.type(), type);

		/* invoke class constructor */
		X10ConstructorInstance_c instance = (X10ConstructorInstance_c) n.constructorInstance();
		if (instance != null) {
			Entity entity = getConstructorEntity(instance);
			firm.MethodType entityType = (MethodType) entity.getType();
			Node address = con.newSymConst(entity);

			int param_count = entityType.getNParams();
			Node[] parameters = new Node[param_count];

			List<Expr> arguments = n.arguments();
			int p = 0;
			parameters[p++] = res; /* this argument */
			for (int i=0; i<arguments.size(); i++) {
				parameters[p++] = visitExpression(arguments.get(i));
			}
			assert arguments.size()+1 == param_count;

			Node mem = con.getCurrentMem();
			Node call = con.newCall(mem, address, parameters, entityType);
			Node newMem = con.newProj(call, Mode.getM(), Call.pnM);
			con.setCurrentMem(newMem);
		} else {
			/* no constructor */
		}

		setReturnNode(res);
	}

	private TargetValue getFloatLitTargetValue(FloatLit_c literal) {
		final Mode mode;

		polyglot.ast.FloatLit.Kind kind = literal.kind();
		if (kind == FloatLit.FLOAT)
			mode = typeSystem.getFirmMode(typeSystem.Float());
		else if (kind == FloatLit.DOUBLE)
			mode = typeSystem.getFirmMode(typeSystem.Double());
		else
			throw new InternalCompilerError("Unrecognized FloatLit kind " + kind);

		double value = literal.value();
		return new TargetValue(value, mode);
	}

	@Override
	public void visit(FloatLit_c literal) {
		TargetValue targetValue = getFloatLitTargetValue(literal);
		Node ret = con.newConst(targetValue);
		setReturnNode(ret);
	}

	private TargetValue getIntLitTarval(IntLit_c literal) {
		final Mode mode;

		polyglot.ast.IntLit.Kind kind = literal.kind();
		if (kind == X10IntLit_c.ULONG) {
			mode = typeSystem.getFirmMode(typeSystem.ULong());
		} else if (literal.kind() == X10IntLit_c.UINT) {
			mode = typeSystem.getFirmMode(typeSystem.UInt());
		} else if (literal.kind() == IntLit.LONG) {
			mode = typeSystem.getFirmMode(typeSystem.Long());
		} else if (literal.kind() == IntLit.INT) {
			mode = typeSystem.getFirmMode(typeSystem.Int());
		} else {
			throw new InternalCompilerError("Unrecognized IntLit kind " + kind);
		}
		long value = literal.value();
		return new TargetValue(value, mode);
	}

	@Override
	public void visit(IntLit_c n) {
		TargetValue targetValue = getIntLitTarval(n);
		Node ret = con.newConst(targetValue);
		setReturnNode(ret);
	}

	@Override
	public void visit(NullLit_c n) {
		final firm.Type type = typeSystem.asFirmType(n.type());
		final Mode mode = type.getMode();
		Node result = con.newConst(mode.getNull());
		setReturnNode(result);
	}

	@Override
	public void visit(StringLit_c n) {
		/* Construct call to builtin function, which creates an X10 string struct. */

		Node string_const = createStringSymConst(n.value());

		final firm.Type[] parameterTypes = new firm.Type[2];
		parameterTypes[0] = typeSystem.asFirmType(typeSystem.UInt());
		parameterTypes[1] = new PointerType(parameterTypes[0]); /* XXX Pointer to uint is not quite correct */
		final firm.Type[] resultTypes = new firm.Type[1];
		resultTypes[0] = typeSystem.asFirmType(typeSystem.String());
		MethodType type = new firm.MethodType(parameterTypes, resultTypes);

		Entity func_ent = new Entity(Program.getGlobalType(), X10_STRING_LITERAL, type);
		Node address = con.newSymConst(func_ent);

		Node[] parameters = new Node[2];
		parameters[0] = con.newConst(n.value().length(), Mode.getIu());
		parameters[1] = string_const;
		Node mem = con.getCurrentMem();
		Node call = con.newCall(mem, address, parameters, type);
		Node newMem = con.newProj(call, Mode.getM(), Call.pnM);
		con.setCurrentMem(newMem);

		assert (type.getNRess() == 1);
		firm.Type ret_type = type.getResType(0);
		Node all_results = con.newProj(call, Mode.getT(), Call.pnTResult);
		Mode mode = ret_type.getMode();
		assert (mode != null);
		Node ret = con.newProj(all_results, mode, 0);
		setReturnNode(ret);
	}

	private Node createStringSymConst(String value) {
		ClassType global_type = Program.getGlobalType();
		firm.Type elem_type = typeSystem.asFirmType(typeSystem.Int()); /* XXX always wide chars */
		ArrayType type = new ArrayType(1, elem_type);

		Ident id = Ident.createUnique("str.%u");
		Entity ent = new Entity(global_type, id, type);
		ent.setLdIdent(id);

		ent.setVisibility(ir_visibility.ir_visibility_private);
		ent.addLinkage(ir_linkage.IR_LINKAGE_CONSTANT.val);

		type.setBounds(0, 0, value.length()-1);
		type.setSizeBytes(4 * value.length());
		type.setTypeState(ir_type_state.layout_fixed);

		Initializer init = new Initializer(value.length());
		char[] chars = value.toCharArray();
		for (int i = 0; i < chars.length; ++i) {
			TargetValue tv = new TargetValue(chars[i], elem_type.getMode());
			Initializer val = new Initializer(tv);
			init.setCompoundValue(i, val);
		}
		ent.setInitializer(init);

		return con.newSymConst(ent);
	}

	private TargetValue getCharLitTargetValue(CharLit_c literal) {
		Mode mode = typeSystem.getFirmMode(literal.type());
		long value = literal.value();
		return new TargetValue(value, mode);
	}

	@Override
	public void visit(CharLit_c literal) {
		TargetValue targetValue = getCharLitTargetValue(literal);
		Node ret = con.newConst(targetValue);
		setReturnNode(ret);
	}

	private TargetValue getBooleanLitTargetValue(BooleanLit_c literal) {
		Mode mode = typeSystem.getFirmMode(typeSystem.Boolean());
		return literal.value() ? mode.getOne() : mode.getNull();
	}

	@Override
	public void visit(BooleanLit_c literal) {
		TargetValue targetValue = getBooleanLitTargetValue(literal);
		Node ret = con.newConst(targetValue);
		setReturnNode(ret);
	}

	private Node getThis(Mode mode) {
		return con.getVariable(0, mode);
	}

	@Override
	public void visit(X10Special_c n) {
		
		if (n.kind() == Special.THIS) {
			firm.Mode mode = typeSystem.getFirmMode(n.type());
			Node thisPointer = getThis(mode);
			setReturnNode(thisPointer);
		} else {
			throw new RuntimeException("Not implemented yet");
		}
	}
	
	/* WORKAROUND START -> The following code is only a workaround because firm doesn`t support interfaces yet.
	 * The workaround transforms interfaces into abstract classes. 
	 * -> [Code will be deleted] 
	 */
	
	/** Mapping between the concatenation of the types of the "apply" method and the appropriate abstract base class */
	private final Map<String, X10ClassDef> closureBaseDefs = new HashMap<String, X10ClassDef>();
	
	/** Creates a new mapping */
	private void putClosureBaseDef(String name, X10ClassDef def) {
		closureBaseDefs.put(name, def);
	}
	
	/**
	 * Returns the appropriate class def for a given signature name
	 */
	private X10ClassDef getClosureBaseDef(String name) {
		return closureBaseDefs.get(name);
	}
	
	/** For the definition of unique closure base names */
	private static int closureCounter = 0;
	
	/**
	 * Creates a new abstract base class for closures. 
	 * @param closureDefName Concatenation of the types of the "apply" method -> Used for the identification of the base classes. 
	 * @param xts Type system 
	 * @param numTypeParams 
	 * @param numValueParams
	 * @param isVoid
	 * @return
	 */
    private X10ClassDef newClosureBaseClass(final String closureDefName, final X10TypeSystem_c xts, final int numTypeParams, 
    		final int numValueParams, 
    		final boolean isVoid) {
    	
    	// Check if the base class was also defined
    	X10ClassDef ret = getClosureBaseDef(closureDefName);
    	if(ret != null) {
    		return ret;
    	}
    	    	
        final Position pos = Position.COMPILER_GENERATED;

        String name = "Fun_" + numTypeParams + "_" + numValueParams + "_" + closureCounter++;

        if (isVoid) {
            name = "Void" + name;
        }
        
        X10ClassDef cd = new X10ClassDef_c(xts, null) {
            private static final long serialVersionUID = -2035251841478824351L;
            @Override
            public boolean isFunction() { 
                return true;
            }
            @Override
            public polyglot.types.ClassType asType() {
                if (asType == null) {
                    asType = new ClosureType_c(xts, pos, this);
                }
                return asType;
            }
        };
        
        // Get "Object" class and set it as the super class
        QName fullName = QName.make("x10.lang", "Object");
        Named n = xts.systemResolver().check(fullName);
        assert(n != null && n instanceof X10ClassType);
        X10ClassType objectType = (X10ClassType)n;
        
        cd.position(pos);
        cd.name(Name.make(name));
        cd.setPackage(null);
        cd.kind(ClassDef.TOP_LEVEL);
        cd.superType(Types.ref(objectType));
        cd.flags(X10Flags.toX10Flags(Flags.PUBLIC.Abstract()));

        final List<ParameterType> typeParams = new ArrayList<ParameterType>();
        final List<Ref<? extends Type>> argTypes = new ArrayList<Ref<? extends Type>>();

        for (int i = 0; i < numTypeParams; i++) {
            ParameterType t = new ParameterType_c(xts, pos, Name.make("X" + i), Types.ref(cd));
            typeParams.add(t);
        }

        for (int i = 0; i < numValueParams; i++) {
            ParameterType t = new ParameterType_c(xts, pos, Name.make("Z" + (i + 1)), Types.ref(cd));
            argTypes.add(Types.ref(t));
            cd.addTypeParameter(t, ParameterType.Variance.CONTRAVARIANT);
        }

        Type rt = null;

        if (!isVoid) {
            ParameterType returnType = new ParameterType_c(xts, pos, Name.make("U"), Types.ref(cd));
            cd.addTypeParameter(returnType, ParameterType.Variance.COVARIANT);
            rt = returnType;
        }
        else {
            rt = xts.Void();
        }

        // NOTE: don't call cd.asType() until after the type parameters are
        // added.
        FunctionType ct = (FunctionType) cd.asType();

        String fullNameWithThis = "#this";
        XName thisName = new XNameWrapper<Object>(new Object(), fullNameWithThis);
        XVar thisVar = XTerms.makeLocal(thisName);

        List<LocalDef> formalNames = xts.dummyLocalDefs(argTypes);
        X10MethodDef mi = xts.methodDef(pos, Types.ref(ct),
        		Flags.PUBLIC.Abstract(), Types.ref(rt),
        		ClosureCall.APPLY, 
        		typeParams, 
        		argTypes, 
        		thisVar,
        		formalNames, 
        		null,
        		null, 
        	
        		null,
        		null);
        cd.addMethod(mi);

        putClosureBaseDef(closureDefName, cd);
        
        return cd;
    }
    
    /**
     * Returns a unique name of the "apply" method for the identification of the correct abstract base class of a closure class
     * @param def The closure def
     * @return The concatenation of the tpyes of the "apply" method. 
     */
    private static String getClosureDefIdName(final ClosureDef def) {
        StringBuffer buf = new StringBuffer();
        for(LocalDef d : def.formalNames()) 
        	buf.append(d.type().toString());
        return buf.toString();
    }
    
    /* WORKAROUND END */
    
    /**
     * Mapping between the signature (!!!) of the "apply" method in a closure and the appropriate
     * entity of the super class (interface)
     */
	private static final Map<String, Entity> closureEntities = new HashMap<String, Entity>();
	
	/** 
	 * Create a new mapping between the signature of the "apply" method and the appropriate entity
	 * of the super class (interface)
	 */
	private static void putClosureEntity(String sig, Entity ent) {
		closureEntities.put(sig, ent);
	}
	
	/**
	 * Returns the appropriate entity for a given signature. 
	 * @param sig The signature of the "apply" method
	 * @return The appropriate entity
	 */
	private static Entity getClosureEntity(String sig) {
		return closureEntities.get(sig);
	}
    
	/**
	 * Creates a new class definition for a closure
	 * @param def The ClosureDef from which the closure class definition should be created
	 * @param savedFields The field which should be saved in the closure class
	 * @param needSavedThis True if a reference to the current class (upper) should be saved in the closure class
	 * @return The created closure class definition. 
	 */
	private X10ClassDef newClosureDef(final ClosureDef def, Set<LocalInstance> savedFields,
			boolean needSavedThis) {
        final Position pos = Position.COMPILER_GENERATED;
        
        // Create a new closure class definition
        X10ClassDef cd = new X10ClassDef_c(typeSystem, null) { 	
            private static final long serialVersionUID = 4543620040069882230L;
            
            @Override
            public boolean isFunction() { 
                return true;
            }
            
            @Override
            public polyglot.types.ClassType asType() {
                if (asType == null) {
                    asType = new ClosureType_c(typeSystem, pos, this);
                }
                return asType;
            }
        };
        
        int numTypeParams = def.typeParameters().size();
        int numValueParams = def.formalTypes().size();
        ClosureInstance ci = def.asInstance();
        
        String closureDefId = getClosureDefIdName(def);
        
        // Instantiate the super type on the new parameters.
        X10ClassType sup = (X10ClassType)newClosureBaseClass(closureDefId, typeSystem, numTypeParams, 
        		numValueParams,
        		ci.returnType().isVoid())
        		.asType();
        
        // use a unique name for the closure class
        String name = getUniqueClosureName();

        cd.position(pos);
        cd.name(Name.make(name));
        cd.setPackage(null);
        cd.kind(ClassDef.TOP_LEVEL);
        cd.flags(Flags.FINAL);

        // Add type parameters.
        List<Type> typeArgs = new ArrayList<Type>();

        typeArgs.addAll(ci.formalTypes());
        
        if (!ci.returnType().isVoid()) {
            typeArgs.add(ci.returnType());
        }

        assert sup.x10Def().typeParameters().size() == typeArgs.size() : def + ", " + sup + ", " + typeArgs;
        sup = sup.typeArguments(typeArgs);

        // Adding the method guard
        Ref<CConstraint> guard = def.guard();
        if (guard!=null) {
            CConstraint constraint = guard.get();
            // need to rename the guard variables according to the method parameters
            List<LocalDef> fromNames = def.formalNames();
            MethodInstance instance = sup.methods().get(0);
            List<LocalDef> toNames = ((X10MethodDef) instance.def()).formalNames();
            for (int i=0; i<fromNames.size(); i++) {
                LocalDef fromName = fromNames.get(i);
                LocalDef toName = toNames.get(i);
                try {
                    XLocal fromLocal = new XLocal(new XNameWrapper<LocalDef>(fromName,fromName.name().toString()));
                    XLocal toLocal = new XLocal(new XNameWrapper<LocalDef>(toName,toName.name().toString()));
                    constraint = constraint.substitute(toLocal,fromLocal);
                } catch (XFailure xFailure) {
                    assert false;
                }
            }
            try {
                ((ClosureType_c)sup).getXClause().addIn(constraint);
            } catch (XFailure xFailure) {
                assert false;
            }
        }
        cd.superType(Types.ref(sup));
        
        assert(sup.methods().size() == 1);
        
        // apply method of the super class !!!
        X10MethodInstance applyMethodInst = (X10MethodInstance)sup.methods().get(0);
        X10MethodDef applyMethodDef = (X10MethodDef)applyMethodInst.def();
                
        Entity ent = getMethodEntity(applyMethodInst);
        // save the apply method of the super class !
        putClosureEntity(applyMethodInst.signature(), ent);
                
        String thisName = "#this";
        XName thisNameName = new XNameWrapper<Object>(new Object(), thisName);
        XVar thisVar = XTerms.makeLocal(thisNameName);
        
        final List<Ref<? extends Type>> argTypes = new ArrayList<Ref<? extends Type>>();
        for(Type t : applyMethodInst.formalTypes())
        	argTypes.add(Types.ref(t));
        final List<ParameterType> typeParams = applyMethodDef.typeParameters();

        FunctionType ct = (FunctionType)cd.asType();
        
        // create the "apply" method. 
        X10MethodDef mi = typeSystem.methodDef(pos, Types.ref(ct),
        		Flags.PUBLIC, Types.ref(applyMethodInst.returnType()),
        		ClosureCall.APPLY, 
        		typeParams, 
        		argTypes, 
        		thisVar,
        		applyMethodDef.formalNames(), 
        		null,//todo: it was guard1
        		null,
        		null, // offerType
        		null);
        
        cd.addMethod(mi);
        
        // create the context of the closure
        for(LocalInstance loc : savedFields) {
            FieldDef fdef = typeSystem.fieldDef(pos, Types.ref(ct), Flags.PUBLIC, Types.ref(loc.type()), loc.name());
            cd.addField(fdef);
        }
        
        if(needSavedThis) {
        	FieldDef fdef = typeSystem.fieldDef(pos, Types.ref(ct), Flags.PUBLIC, Types.ref(firmContext.getCurClass()), Name.make(X10_SAVED_THIS_LITERAL));
        	cd.addField(fdef);
        }
        
        return cd;
	}
	
	@Override
	public void visit(Closure_c n) {
		ClosureDef def = n.closureDef();
		ClosureInstance closureInstance = def.asInstance();
		
		List<LocalInstance> formals = closureInstance.formalNames();
		
		X10ClosureVisitor closureVisitor = new X10ClosureVisitor(formals);
		closureVisitor.visit(n.body());
		
		final List<LocalInstance> locals = closureVisitor.getLocals();
		final Set<LocalInstance> savedLocals = closureVisitor.getSavedLocalInstances();
		final boolean needSavedThis = closureVisitor.needSavedThis();
		
		/*
		System.out.println("Closure Locals");
		for(LocalInstance loc : locals)
			System.out.println("Local: " + loc);
		System.out.println();
		
		System.out.println("Closure Saved Locals");
		for(LocalInstance loc : savedLocals)
			System.out.println("Saved Local: " + loc);
		System.out.println();
		*/
		
		X10ClassDef closureClassDef = newClosureDef(def, savedLocals, needSavedThis);
		FunctionType closureType = (FunctionType)closureClassDef.asType();
        X10MethodInstance applyMethod = closureType.applyMethod();
        
		Entity ent = getMethodEntity(applyMethod);
        
		/* Create an instance of the closure and save the current context. */
        Node objectPointer = doNewAlloc(closureType, closureType);
        for(LocalInstance loc : savedLocals) {
    		VarEntry var = firmContext.getVarEntry(loc);
    		assert var.getIdx() != -1; /* must be a local var */
    		
    		Node rhs = con.getVariable(var.getIdx(), typeSystem.getFirmMode(var.getVarInstance().type()));
        	doClosureFieldWrite(objectPointer, loc.def().name().toString(), closureType, rhs);
        }
        
        if(needSavedThis) {
			Node rhs = getThis(Mode.getP());
        	doClosureFieldWrite(objectPointer, X10_SAVED_THIS_LITERAL, closureType, rhs);
        }
        
		constructGraph(ent, n, true, formals, locals, false, closureType);
		
		setReturnNode(objectPointer);
	}
	
	@Override
	public void visit(ClosureCall_c c) {
		/* determine called function */
		X10MethodInstance applyMethodInstance = c.closureInstance();
		Entity ent = getClosureEntity(applyMethodInstance.signature());
		assert ent != null;
				
		doX10Call(applyMethodInstance.flags().isStatic(), ent, c.arguments(), c.target());
	}

	/**
	 * Create the appropriate firm nodes for a "new" alloc. 
	 */
	private Node doNewAlloc(Type x10ResType, Type x10Type) {
		firm.Type resType  = typeSystem.asFirmType(x10ResType);
		firm.Type firmType = typeSystem.asFirmCoreType(x10Type);
		Node mem = con.getCurrentMem();
		Node count = con.newConst(1, Mode.getIu());
		Node alloc = con.newAlloc(mem, count, firmType, ir_where_alloc.heap_alloc);
		Node newMem = con.newProj(alloc, Mode.getM(), Alloc.pnM);
		Node res = con.newProj(alloc, resType.getMode(), Alloc.pnRes);
		con.setCurrentMem(newMem);
		
		return res;
	}
	
	/**
	 * Creates the appropriate firm graph for a call. 
	 * @param isStatic True if the called method is static (-> static binding)
	 * @param entity The entity of the method
	 * @param args The arguments of the method
	 * @param target The target of the method call. 
	 */
	private void doX10Call(final boolean isStatic, final Entity entity, final List<Expr> args, final Expr target) {
		
		firm.MethodType type = (MethodType) entity.getType();
		int param_count = type.getNParams();
		List<Expr> arguments = args;

		if (arguments.size()+1 == param_count) {
			/* arguments is immutable, so we construct a new list */
			List<Expr> na = new LinkedList<Expr>();
			na.add(0, target);
			na.addAll(arguments);
			arguments = na;
		}
		assert arguments.size() == param_count : "parameters are off : "+arguments.size()+" vs "+param_count;
		Node[] parameters = new Node[param_count];
		for (int i=0; i<param_count; i++) {
			parameters[i] = visitExpression(arguments.get(i));
		}
		
		Node address;
		if (isStatic) {
			address = con.newSymConst(entity);			
		} else {
			address = con.newSel(parameters[0], entity);
		}
		
		Node mem = con.getCurrentMem();
		Node call = con.newCall(mem, address, parameters, type);
		Node newMem = con.newProj(call, Mode.getM(), Call.pnM);
		con.setCurrentMem(newMem);

		if (type.getNRess() == 0) {
			return; /* no return value, we're done */
		}
		assert (type.getNRess() == 1); /* X10 does not support multiple return values */
		firm.Type ret_type = type.getResType(0);
		Node all_results = con.newProj(call, Mode.getT(), Call.pnTResult);
		Mode mode = ret_type.getMode();
		if (mode == null) {
			/* classes do not have modes assigned, use pointer mode */
			mode = Mode.getP();
			// TODO structs have value semantics
		}
		Node ret = con.newProj(all_results, mode, 0);
		setReturnNode(ret);
	}

	@Override
	public void visit(X10Binary_c B) {

		// only '==', '!=', '&&' or '||' are allowed operators.
		// all other operators are implemented by native calls.

	    Expr left 			= B.left();
	    Type l 				= left.type();
	    Expr right 			= B.right();
	    Type r 				= right.type();
	    Binary.Operator op 	= B.operator();

	    if (op == Binary.EQ || op == Binary.NE) { // Added for testing purposes.
	    	int modus = (op == Binary.EQ) ? Cmp.pnEq : Cmp.pnLg;

	    	FirmScope curScope = firmContext.getTopScope();
	    	if(curScope.getTrueBlock() != null && curScope.getFalseBlock() != null ) {
				Block bTrue  = curScope.getTrueBlock();
				Block bFalse = curScope.getFalseBlock();

	    		Node retLeft  = visitExpression(left);
	    		Node retRight = visitExpression(right);

	    		// no new firm scope needed

				Node cmp  = con.newCmp(retLeft, retRight);
				Node proj = con.newProj(cmp, Mode.getb(), modus);

				Node cond = con.newCond(proj);

				Node projTrue  = con.newProj(cond, Mode.getX(), Cond.pnTrue);
				Node projFalse = con.newProj(cond, Mode.getX(), Cond.pnFalse);

				bTrue.addPred(projTrue);
				bFalse.addPred(projFalse);

				setReturnNode(cond);

	    	} else {
	    		Node ret = makeConditionalPhiTrailer(B);
	    		setReturnNode(ret);
	    	}

	    	return;
	    } else if ((l.isNumeric() && r.isNumeric()) || (l.isBoolean() && r.isBoolean())) {
	    	// delegate it to Binary_c
	        visit((Binary_c)B);
	        return;
	    }

	    throw new RuntimeException("User-defined binary operators should have been desugared earier");
	}

	@Override
	public void visit(Binary_c B) {
		Binary.Operator op = B.operator();

		// Boolean short-circuiting operators are ok
		assert (op == Binary.COND_AND || op == Binary.COND_OR) : "visiting " + B.getClass() + " at " + B.position() + ": " + B;

		// only '&&' and '||' are valid
		// TODO: Add constant value evaluation

		FirmScope curScope = firmContext.getTopScope();

		if(curScope.getTrueBlock() != null && curScope.getFalseBlock() != null) {
			Block bCurTrue  = curScope.getTrueBlock();
			Block bCurFalse = curScope.getFalseBlock();

			Block bTrue, bFalse;

			if(op == Binary.COND_AND) { // '&&'
				bTrue  = con.newBlock();
				bFalse = curScope.getFalseBlock();
			} else { // '||'
				bTrue  = curScope.getTrueBlock();
				bFalse = con.newBlock();
			}

			FirmScope topScope = firmContext.getTopScope();
			FirmScope newScope = (FirmScope)topScope.clone();

			firmContext.pushFirmScope(newScope);
			{
				newScope.setTrueBlock(bTrue);
				newScope.setFalseBlock(bFalse);

				makeExpressionCondition(B.left());
			}
			firmContext.popFirmScope();

			if(op == Binary.COND_AND)
				con.setCurrentBlock(bTrue);
			else
				con.setCurrentBlock(bFalse);

			topScope = firmContext.getTopScope();
			newScope = (FirmScope)topScope.clone();

			Node ret = null;
			firmContext.pushFirmScope(newScope);
			{
				newScope.setTrueBlock(bCurTrue);
				newScope.setFalseBlock(bCurFalse);

				ret = makeExpressionCondition(B.right());
			}
			firmContext.popFirmScope();
			
			if(op == Binary.COND_AND) {
				bTrue.mature();
			} else {
				bFalse.mature();
			}

			setReturnNode(ret);
		} else {
			Node ret = makeConditionalPhiTrailer(B);
			setReturnNode(ret);
		}
	}
	
	@Override
	public void visit(ParExpr_c n) {
		visitAppropriate(n.expr());
	}
	
	@Override
	public void visit(TypeDecl_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(LocalTypeDef_c n) {
		throw new RuntimeException("Not implemented yet");
	}
	
	@Override
	public void visit(LocalClassDecl_c n) {
		throw new RuntimeException("Local classes should have been removed by a separate pass");
	}
	
	@Override
	public void visit(PackageNode_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(Import_c n) {
		throw new RuntimeException("Not implemented yet");
	}
	
	@Override
	public void visit(PropertyDecl_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(Initializer_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(Assert_c n) {
		throw new RuntimeException("Not implemented yet");
	}
	
	@Override
	public void visit(Formal_c n) {
		throw new RuntimeException("Not implemented yet");
	}
	
	@Override
	public void visit(For_c n) {
		throw new RuntimeException("Not implemented yet");
	}
	
	@Override
	public void visit(RegionMaker_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(ConstantDistMaker_c n) {
		throw new RuntimeException("Not implemented yet");
	}
	
	@Override
	public void visit(X10CanonicalTypeNode_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(X10Unary_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(Unary_c n) {
		throw new RuntimeException("Not implemented yet");
	}
	
	@Override
	public void visit(Id_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(X10Cast_c c) {
		visitAppropriate(c.expr()); // FIXME need real implementation
	}

	@Override
	public void visit(SubtypeTest_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(X10Instanceof_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(Throw_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(Try_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(Catch_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(Atomic_c a) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(Await_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(Next_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(ForLoop_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(AtEach_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(Finish_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(ArrayAccess_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(Here_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(Async_c n) {
		throw new RuntimeException("Not implemented yet");
	}


	@Override
	public void visit(ArrayInit_c n) {
		throw new InternalCompilerError("Should not be invoked");
	}

	@Override
	public void visit(SettableAssign_c n) {
		throw new RuntimeException("Function assign should have been desugared earlier");
	}

	@Override
	public void visit(Tuple_c c) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(When_c n) {
		throw new RuntimeException("When should have been desugared earlier");
	}

	@Override
	public void visit(Future_c n) {
		throw new RuntimeException("Future should have been desugared earlier");
	}

	@Override
	public void visit(AtStmt_c n) {
		throw new RuntimeException("At statements are deprecated");
	}

	@Override
	public void visit(AtExpr_c n) {
		throw new RuntimeException("At expression should have been desugared earlier");
	}
}