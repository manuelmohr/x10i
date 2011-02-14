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
import polyglot.types.FieldDef;
import polyglot.types.FieldInstance;
import polyglot.types.Flags;
import polyglot.types.LocalInstance;
import polyglot.types.MethodInstance;
import polyglot.types.Name;
import polyglot.types.Named;
import polyglot.types.ObjectType;
import polyglot.types.QName;
import polyglot.types.Ref;
import polyglot.types.StructType;
import polyglot.types.Type;
import polyglot.types.Types;
import polyglot.types.VarInstance;
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
import x10.types.ClosureDef;
import x10.types.ClosureInstance;
import x10.types.X10ClassDef;
import x10.types.X10ClassDef_c;
import x10.types.X10ClassType;
import x10.types.X10ConstructorDef;
import x10.types.X10ConstructorInstance;
import x10.types.X10ConstructorInstance_c;
import x10.types.X10Context_c;
import x10.types.X10Flags;
import x10.types.X10MethodDef;
import x10.types.X10MethodInstance;
import x10.util.ClosureSynthesizer;
import x10.visit.X10DelegatingVisitor;
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
	
	/** X10 Context */
	private X10Context_c x10Context = null;

	/** typeSystem is used to map X10 types to Firm types (and modes) */
	private final TypeSystem typeSystem;
	
	/** Our own AST query */
	private final X10ASTQuery query;

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
		 * List with the class members which must be initialised explicitly in a constructor etc. 
		 */
		private List<ClassMember> initClassMembers = null;

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
			return curClass;
		}
		
		/**
		 * Sets the class members which must be intialised explicitly
		 */
		public void setInitClassMembers(List<ClassMember> members) {
			assert(initClassMembers == null); // method should only be called once
			if(initClassMembers != null) {
				System.out.println("YES");
			}
			initClassMembers = members;
		}
		
		public List<ClassMember> getInitClassMembers() {
			assert(initClassMembers != null);
			return initClassMembers;
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
		 * Marking that we are currently in a closure
		 * @param in True if we are currently in a closure 
		 */
		public void setInClosure(boolean in) {
			inClosure = in;
		}
		
		/**
		 * Checks if we are currently in a closure
		 * @return True if we are currently in a closure
		 */
		public boolean isInClosure() {
			return inClosure;
		}
		
		/** Sets the "VarEntry" for a given variable (local variable or field instance)
		 * @param entry The "VarEntry" for the given variable
		 */
		public void setVarEntry(VarEntry entry) {
			assert !varEntryMapper.containsKey(entry.getVarInstance());
			varEntryMapper.put(entry.getVarInstance(), entry);
		}

		/** Returns the "VarEntry" for a given variable (local variable or field instance)
		 * @return The "VarEntry" of the given variable or null if the variable could not be found
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
		this.typeSystem = typeSystem;
		this.query      = new X10ASTQuery(typeSystem, compiler);
		this.x10Context = new X10Context_c(typeSystem);
		
		X10NameMangler.setup(typeSystem);
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
		
		FirmContext newFirmContext = new FirmContext();
		firmContext = firmContext.pushFirmContext(newFirmContext);
		
		firmContext.setCurClass(classType);
		
		visitAppropriate(body);
		
		firmContext = firmContext.popFirmContext();
	}

	@Override
	public void visit(ClassBody_c n) {
		X10ClassType currentClass = firmContext.getCurClass();
		if (currentClass.flags().isInterface()) {
			// nothing todo
		} else if (currentClass.isX10Struct()) {
			// TODO: Implement me
		} else {
			visitClassBody(n);
		}
	}
	
	/** 
	 * Visits a class body
	 * @param n A reference to the class body
	 */
	private void visitClassBody(ClassBody_c n) {
		
		final List<ClassMember> members = n.members();
		if(!members.isEmpty()) {
			final List<ClassMember> inits = extractInits(members);
			firmContext.setInitClassMembers(inits);
			
			for (ClassMember member : n.members())
				visitAppropriate(member);
		}
	}

	private List<ClassMember> extractInits(List<ClassMember> members)
	{
		final List<ClassMember> ret = new LinkedList<ClassMember>();

	    for(ClassMember member : members) {
	        if(member.memberDef().flags().isStatic())
	            continue;
	        if(!(member instanceof Initializer_c) && !(member instanceof FieldDecl_c))
	            continue;
	        if(member instanceof FieldDecl_c && (((FieldDecl_c)member).init() == null ||
	            query.isSyntheticField(((FieldDecl_c)member).name().id().toString())))
	            continue;
	        if (member instanceof FieldDecl_c) {
	            FieldDecl_c dec = (FieldDecl_c) member;
	            if(dec.flags().flags().isStatic()) {
	                X10ClassType container = (X10ClassType)dec.fieldDef().asInstance().container();
	                if(((X10ClassDef)container.def()).typeParameters().size() != 0)
	                    continue;
	                if(query.isGlobalInit(dec))
	                    continue;
	            }
	        }
	        
	        // This class members must be initialised
	        ret.add(member);
	    }
	    
	    return ret;
	}
	

	private Entity getConstructorEntity(X10ConstructorInstance instance) {
		Entity entity = constructorEntities.get(instance);
		if (entity == null) {
			X10ClassType owner = (X10ClassType) instance.container();
			String name = X10NameMangler.mangleTypeObjectWithDefClass(instance);
			X10Flags flags = X10Flags.toX10Flags(instance.flags());

			firm.Type ownerFirm = typeSystem.asFirmCoreType(owner);
			firm.Type type      = typeSystem.asFirmType(instance);
			entity = new Entity(ownerFirm, name, type);
			entity.setLdIdent(name);
			if (flags.isAbstract()) {
				OO.setMethodAbstract(entity, true);
			}
			if (flags.isNative()) {
				entity.setVisibility(ir_visibility.ir_visibility_external);
			}
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
	 * Returns the firm entity of a method which a given method instance maybe overwrites. 
	 * @param instance The method instance which should be checked
	 * @return The appropriate firm method entity or null if the given method instance doesn`t overwrite any other methods 
	 * in the class hierarchy. 
	 */
	private Entity getMethodOverride(X10MethodInstance instance) {
		X10Flags flags = X10Flags.toX10Flags(instance.flags());
		// static methods can`t override other methods. 
		if(flags.isStatic()) return null;
		
		StructType cont = instance.container();
		
		boolean firstRun = true;
		while(cont != null) {
			if(!firstRun) {
				for(MethodInstance meth: cont.methods()) {
		        	if(typeSystem.canOverride(meth, instance, x10Context)) {
		        		return getMethodEntity((X10MethodInstance)meth);
		        	}
				}
			}

			firstRun = false;
			
			StructType sup = null;
			
			// check if we have a super class. 
			if(cont instanceof ObjectType) {
				ObjectType objType = (ObjectType)cont;
				if(objType.superClass() instanceof StructType) {
					sup = (StructType)objType.superClass();
				}
			}
			
			cont = sup;
		}
		
		return null;
	}

	/**
	 * Return entity for an X10 method
	 */
	private Entity getMethodEntity(X10MethodInstance instance) {
		Entity entity = methodEntities.get(instance);
		if (entity == null) {
			X10ClassType owner = (X10ClassType) instance.container();
			String nameWithoutDefiningClass = X10NameMangler.mangleTypeObjectWithoutDefClass(instance);
			String nameWithDefiningClass = X10NameMangler.mangleTypeObjectWithDefClass(instance);

			X10Flags flags = X10Flags.toX10Flags(instance.flags());

			firm.Type owningClass = typeSystem.asFirmCoreType(owner);
			firm.Type ownerFirm = flags.isStatic() ? Program.getGlobalType() : owningClass;
			firm.Type type = typeSystem.asFirmType(instance);
			entity = new Entity(ownerFirm, nameWithoutDefiningClass, type);
			entity.setLdIdent(nameWithDefiningClass);
			if (flags.isStatic()) {
				OO.setEntityBinding(entity, ddispatch_binding.bind_static);
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
			
			Entity overwritten = getMethodOverride(instance);
			if(overwritten != null) 
				entity.addEntityOverwrites(overwritten);
			
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
	
	/**
	 * Initializes a new construction
	 * @param entity The method entities for which the a new construction should be inited. 
	 * @param closure True if the construction should be inited for a closure 
	 * @param formals The formals of the given method entity
	 * @param locals The locals of the given method entity
	 * @param isStatic True if the method is static
	 * @param owner The owner of the method
	 * @return A reference to the current (saved) construction 
	 */
	private Construction initConstruction(Entity entity, boolean closure, List<LocalInstance> formals, List<LocalInstance> locals, boolean isStatic, X10ClassType owner) {
		int nVars = formals.size() + locals.size();
		if (!isStatic) {
			nVars++;
		}
		
		Graph graph = new Graph(entity, nVars);
		Construction savedConstruction = con;
		con = new Construction(graph);
		
		FirmContext newFirmContext = new FirmContext();
		
		newFirmContext.setInClosure(closure);
		
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

		return savedConstruction;
	}
	
	/**
	 * Finishes a construction 
	 * @param entity The method entity for which the construction should be finished
	 * @param savedConstruction A reference to the previous construction 
	 */
	private void finishConstruction(Entity entity, Construction savedConstruction) {
		// create Return node if there was no explicit return statement yet
		if (!con.getCurrentBlock().isBad()) {
			assert ((MethodType)entity.getType()).getNRess() == 0;
			Node mem = con.getCurrentMem();
			Node ret = con.newReturn(mem, new Node[0]);
			con.getGraph().getEndBlock().addPred(ret);
		}
		
		con.finish();
			
		con = savedConstruction;
		
		firmContext = firmContext.popFirmContext();
	}

	private void constructGraph(Entity entity, CodeBlock code, boolean closure, List<LocalInstance> formals, List<LocalInstance> locals, boolean isStatic, X10ClassType owner) {		
		Construction savedConstruction = initConstruction(entity, closure, formals, locals, isStatic, owner);
		
		// Walk body and construct graph
		visitAppropriate(code.body());
		
		finishConstruction(entity, savedConstruction);
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

		if (query.isMainMethod(dec)) {
			processMainMethod(entity);
		}
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
		List<ClassMember> initClassMembers = firmContext.getInitClassMembers();
		
		Construction savedConstruction = initConstruction(entity, false, formals, locals, isStatic, owner);
		
		// The instance variables must be initialized first
		for(ClassMember member : initClassMembers) {
			// TODO: How we will handler Initializer_c ???
			if(member instanceof FieldDecl_c) {
				FieldDecl_c fieldDecl = (FieldDecl_c)member;
				assert(fieldDecl.init() != null);
				X10Flags fieldFlags = X10Flags.toX10Flags(fieldDecl.flags().flags());
				assert(!fieldFlags.isStatic());
				FieldInstance fieldInst = fieldDecl.fieldDef().asInstance();
				Node objectPointer = getThis(Mode.getP());
				doFieldAssign(objectPointer, fieldInst, fieldDecl.init());
			} else {
				assert(false): "Illegal class member";
			}
		}
		
		visitAppropriate(dec.body());
		
		finishConstruction(entity, savedConstruction);
	}
	
	/**
	 * Createas a target value for a given constant expr
	 * @param expr The constant expr
	 * @return The target value of the given constant expr
	 */
	private TargetValue constantToTargetValue(Expr expr) {
		assert(expr != null && expr.isConstant());
		
		Object obj = expr.constantValue();
		
		TargetValue targetValue = null;
		
		// all unsigned types can`t be evaluated at compile time, because they use an "implicit operator as" 
		// to convert the datatype to long, integer etc. 
		
		if(obj instanceof Integer || obj instanceof Long || obj instanceof Byte || obj instanceof Short) {
			final Mode mode;
			long value;
			if(obj instanceof Integer) {
				mode = typeSystem.getFirmMode(typeSystem.Int());
				value = ((Integer)obj).longValue();
			} else if(obj instanceof Long) {
				mode = typeSystem.getFirmMode(typeSystem.Long());
				value = ((Long)obj).longValue();
			} else if(obj instanceof Byte) {
				mode = typeSystem.getFirmMode(typeSystem.Byte());
				value = ((Byte)obj).longValue();
			} else { // SHORT
				mode = typeSystem.getFirmMode(typeSystem.Short());
				value = ((Short)obj).longValue();
			}
			targetValue = new TargetValue(value, mode);
		} else if(obj instanceof Float || obj instanceof Double) {
			final Mode mode;
			double value;
			if(obj instanceof Float) {
				mode = typeSystem.getFirmMode(typeSystem.Float());
				value = ((Float)obj).doubleValue();
			} else {
				mode = typeSystem.getFirmMode(typeSystem.Double());
				value = ((Double)obj).doubleValue();
			}
			targetValue = new TargetValue(value, mode);
		} else if(obj instanceof Boolean) {
			final Mode mode = typeSystem.getFirmMode(typeSystem.Boolean());
			boolean value = ((Boolean)obj).booleanValue();
			targetValue = value ? mode.getOne() : mode.getNull();
		}
		
		return targetValue;
	}
	
	/**
	 * Creates an initializer for a given constant expr
	 * @param expr The constant expr
	 * @return The initializer for the given constant expr
	 */
	private Initializer constantExprToInitializer(Expr expr) {
		TargetValue targetValue = constantToTargetValue(expr);
		if(targetValue == null) return null;
		return new Initializer(targetValue);
	}

	private Initializer expr2Initializer(Expr expr) {
		final Initializer result;
		assert(expr.isConstant());
		
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
		} else if (expr instanceof NullLit_c) {
			Node nullNode = getStaticNullLitNode((NullLit_c)expr);
			result = new Initializer(nullNode);
		} else {
			// Now we will try the constant evaluation of expr
			result = constantExprToInitializer(expr);
			if(result != null)
				return result;

			throw new RuntimeException("unimplemented initializer expression");
		}
		return result;
	}
	
	private static final String X10_STATIC_FIELD_STATUS_SUFFIX = "__status";
	private static final String X10_STATIC_FIELD_ACCESSOR_SUFFIX = "__get";
	
	private static final int    X10_STATIC_FIELD_STATUS_UNITIALIZED = 0;
	private static final int    X10_STATIC_FIELD_STATUS_INITIALIZED = 1;
	
	private Node getFieldAddress(Node objectPointer, FieldInstance instance) {
		FieldInstance def = instance.def().asInstance();
		X10Flags flags = X10Flags.toX10Flags(def.flags());
		/* make sure enclosing class-type has been created */
		typeSystem.asFirmType(def.container());
		Entity entity = typeSystem.getEntityForField(def);
		Node address = null;
		if (flags.isStatic()) {
			address = con.newSymConst(entity);
		} else {
			assert(objectPointer != null);
			address = con.newSel(objectPointer, entity);
		}
		return address;
	}
	
	private Node doFieldLoad(Node objectPointer, FieldInstance instance) {
		FieldInstance def = instance.def().asInstance();
		Node address = getFieldAddress(objectPointer, instance);
		firm.Type type = typeSystem.asFirmType(def.type());
		Node mem = con.getCurrentMem();
		Mode loadMode = type.getMode();
		Node load = con.newLoad(mem, address, loadMode);
		Node newMem = con.newProj(load, Mode.getM(), Load.pnM);
		Node result = con.newProj(load, loadMode, Load.pnRes);
		con.setCurrentMem(newMem);
		return result;
	}
	
	private Node doStaticFieldLoad(FieldInstance instance) {
		return doFieldLoad(null, instance);
	}
	
	private Node doFieldAssign(Node objectPointer, FieldInstance instance, Node rightRet) {
		FieldInstance def = instance.def().asInstance();
		Node address = getFieldAddress(objectPointer, instance);
		firm.Type type = typeSystem.asFirmType(def.type());
		assert rightRet.getMode().equals(type.getMode());
		Node mem = con.getCurrentMem();
		Node store = con.newStore(mem, address, rightRet);
		Node newMem = con.newProj(store, Mode.getM(), Store.pnM);
		con.setCurrentMem(newMem);
		return rightRet;
	}
	
	private Node doFieldAssign(Node objectPointer, FieldInstance instance, Expr expr) {
		Node rightRet = visitExpression(expr);
		doFieldAssign(objectPointer, instance, rightRet);
		return rightRet;
	}
	
	private Node doStaticFieldAssign(FieldInstance instance, Expr expr) {
		return doFieldAssign(null, instance, expr);
	}
	
	private Node doStaticFieldAssign(FieldInstance instance, Node rightRet) {
		return doFieldAssign(null, instance, rightRet);
	}
	
	/**
	 * Mapping between static non const fields and the appropriate getter method entities. 
	 */
	private Map<FieldInstance, Entity> staticFieldGetterMethodMap = new HashMap<FieldInstance, Entity>();
	
	/**
	 * Returns the getter method for a given static non constant field
	 * @param field The field for which the appropriate getter method should be returned
	 * @return The appropriate getter method for the given field
	 */
	private Entity getGetterMethodForStaticField(FieldInstance field) {
		assert(field.flags().isStatic() && !field.isConstant());
		Entity ent = staticFieldGetterMethodMap.get(field);
		if(ent != null)
			return ent;
		
		X10ClassType contType = (X10ClassType)field.container();
		X10ClassDef contDef = (X10ClassDef)contType.def();
		
		Position pos = Position.COMPILER_GENERATED;
    	// Create the method for accessing the field
        final X10MethodDef mi = typeSystem.methodDef(pos, Types.ref(contType),
        		typeSystem.Public().Static(), Types.ref(field.type()),
        		Name.make(field.name().toString() + X10_STATIC_FIELD_ACCESSOR_SUFFIX), 
        		new LinkedList<Ref<? extends Type>>());
        contDef.addMethod(mi);
        
        X10MethodInstance staticAccMeth = (X10MethodInstance)mi.asInstance();
        Entity entity = getMethodEntity(staticAccMeth);
        
        staticFieldGetterMethodMap.put(field, entity);
        
        return entity;
	}
	
	/**
	 * Creates a new getter method for a static non const field 
	 * @param dec The field declaration for which the getter method should be created. 
	 */
	private void generateStaticNonConstFieldDecl(FieldDecl_c dec) {
		assert(!dec.init().isConstant());
		FieldDef fieldDef = dec.fieldDef();
		FieldInstance fieldInst = fieldDef.asInstance();
		X10ClassType contType = (X10ClassType)fieldInst.container();
		X10ClassDef contDef = (X10ClassDef)contType.def();
		
		Position pos = Position.COMPILER_GENERATED;
		// Create a new static value for the given field for holding the status of the initialization
    	FieldDef statusField = typeSystem.fieldDef(pos, Types.ref(contType), typeSystem.Public().Static(), 
    			Types.ref(typeSystem.Int()), Name.make(fieldDef.name().toString() + X10_STATIC_FIELD_STATUS_SUFFIX));
    	contDef.addField(statusField);
    	
    	FieldInstance statusFieldInst = statusField.asInstance();
    	
    	typeSystem.addExtraStaticField(statusFieldInst);

        Entity staticFieldGetterMethod = getGetterMethodForStaticField(fieldInst);
        Construction savedConstruction = initConstruction(staticFieldGetterMethod, false, new LinkedList<LocalInstance>(), new LinkedList<LocalInstance>(), true, contType);
        Entity statusFieldEnt = typeSystem.getEntityForField(statusFieldInst);
        
        // Set the default "UNITIALIZED" value for "field".__status;
        Initializer staticFieldStatusInitializer = new Initializer(new TargetValue(X10_STATIC_FIELD_STATUS_UNITIALIZED, typeSystem.getFirmMode(typeSystem.Int())));
        statusFieldEnt.setInitializer(staticFieldStatusInitializer);
        
        /** Generate the following code for the "field"__get method
         *  #define INITIALIZED 1
         *  #define UNITIALIZED 0
         *  
         *  "field".__status is initialized with UNITIALIZED
         *  
         *  if("field".__status != INITIALIZED) {
         *      "field" = "field".init();
         *      "field".__status = INITIALIZED;
         *  }
         *  return "field";
         */
        
		Block bTrue  = con.newBlock();
		Block bAfter = con.newBlock();
		
		Node retLeft  = doStaticFieldLoad(statusFieldInst);
		Node retRight = con.newConst(new TargetValue(X10_STATIC_FIELD_STATUS_INITIALIZED, typeSystem.getFirmMode(typeSystem.Int())));
		
		Node cmp  = con.newCmp(retLeft, retRight);
		Node proj = con.newProj(cmp, Mode.getb(), Cmp.pnLg);

		Node cond = con.newCond(proj);

		Node projTrue  = con.newProj(cond, Mode.getX(), Cond.pnTrue);
		Node projFalse = con.newProj(cond, Mode.getX(), Cond.pnFalse);
		
		bTrue.addPred(projTrue);
		bAfter.addPred(projFalse);
		
		con.setCurrentBlock(bTrue);
		doStaticFieldAssign(fieldInst, dec.init());
		
		Node nodeInitialized = con.newConst(new TargetValue(X10_STATIC_FIELD_STATUS_INITIALIZED, typeSystem.getFirmMode(typeSystem.Int())));
		doStaticFieldAssign(statusFieldInst, nodeInitialized);
		
		bAfter.addPred(con.newJmp());
		bTrue.mature();
		con.setCurrentBlock(bAfter);
		
		Node mem = con.getCurrentMem();
		Node retValue = doStaticFieldLoad(fieldInst);
		Node retNode = con.newReturn(mem, new Node[]{retValue});

		/* for error detection */
		con.getGraph().getEndBlock().addPred(retNode);
		con.setCurrentBlockBad();
		
		bAfter.mature();
        
        finishConstruction(staticFieldGetterMethod, savedConstruction);
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
				if(dec.init().isConstant()) {
					Initializer initializer = expr2Initializer(init);
					Entity entity = typeSystem.getEntityForField(dec.fieldDef().asInstance());
					entity.setInitializer(initializer);
				} else {
					generateStaticNonConstFieldDecl(dec);
				}
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
			Node objectPointer = visitExpression((Expr)field.target());
			Node ret = doFieldAssign(objectPointer, instance, rhs);
			setReturnNode(ret);
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
	 * @param expr	an X10 Expr node
	 * @return a Firm node containing the result value of the expression
	 */
	private Node visitExpression(Expr expr) {
		resetReturnNode();
		visitAppropriate(expr);
		Node ret = getReturnNode();
		return ret;
	}

	@Override
	public void visit(Field_c n) {
		FieldInstance instance = n.fieldInstance();
		FieldInstance def = instance.def().asInstance();
		
		X10Flags flags = X10Flags.toX10Flags(def.flags());
		
		if(flags.isStatic() && !n.isConstant()) {
			// a static constant field -> do a static method call to the "field".__get method
			Entity staticGetterMethod = getGetterMethodForStaticField(instance);
			assert staticGetterMethod != null;
			
			doX10Call(true, staticGetterMethod, new ArrayList<Expr>(), null);
			// setReturnNode is set in doX10Call
		} else if(flags.isStatic()) {
			Node ret = doStaticFieldLoad(instance);
			setReturnNode(ret);
		} else {
			Node objectPointer = visitExpression((Expr)n.target());
			Node ret = doFieldLoad(objectPointer, instance);
			setReturnNode(ret);
		}
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
			/* it`s actually a local instance in the closure 
			   generate code for a normal local instance. 
			   -> below else block 
			*/ 
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
	
	private Node getStaticNullLitNode(NullLit_c n) {
		// Create a new local construction and use it to create a new null const node
		Graph graph = Program.getConstCodeGraph();
		Construction c = new Construction(graph);
		final firm.Type type = typeSystem.asFirmType(n.type());
		final Mode mode = type.getMode();
		Node result = c.newConst(mode.getNull());
		return result;
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
			Node thisPointer = null;
			if(firmContext.isInClosure()) {
				thisPointer = doClosureFieldRead(X10_SAVED_THIS_LITERAL, firmContext.getCurClass());
			} else {
				firm.Mode mode = typeSystem.getFirmMode(n.type());
				thisPointer = getThis(mode);
			}
			setReturnNode(thisPointer);
		} else {
			throw new RuntimeException("Not implemented yet");
		}
	}
    
    
    /**
     * Mapping between the signature (!!!) of the "apply" method in a closure and the appropriate
     * entity of the super interface
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
	 * Helper function to create a new closure def class (see newClosureDef)
	 * @param def The ClosureDef from which the closure class definition should be created
	 * @return The created closure class definition.
	 */
	private X10ClassDef newClosureDefHelp(final ClosureDef def) {
        final Position pos = def.position();

        X10ClassDef cd = new X10ClassDef_c(typeSystem, null) { 	
            private static final long serialVersionUID = 4543620040069882230L;
            @Override
            public boolean isFunction() { 
                return true;
            }
        };
        
        // use a unique name for the closure class
        final String name = getUniqueClosureName();
        
        // Get "Object" class and set it as the super class
        QName fullName = QName.make("x10.lang", "Object");
        Named n = typeSystem.systemResolver().check(fullName);
        assert(n != null && n instanceof X10ClassType);
        X10ClassType objectType = (X10ClassType)n;

        cd.position(pos);
        cd.name(Name.make(name));
        cd.setPackage(null);
        cd.kind(ClassDef.TOP_LEVEL);
        cd.flags(Flags.FINAL);
        cd.superType(Types.ref(objectType));

        final int numTypeParams = def.typeParameters().size();
        final int numValueParams = def.formalTypes().size();

        // Add type parameters.
        List<Type> typeArgs = new ArrayList<Type>();

        ClosureInstance ci = def.asInstance();
        typeArgs.addAll(ci.formalTypes());

        if (!ci.returnType().isVoid()) {
            typeArgs.add(ci.returnType());
        }

        // Instantiate the super type on the new parameters.
        X10ClassType sup = (X10ClassType)ClosureSynthesizer.closureBaseInterfaceDef(typeSystem, numTypeParams, 
        		numValueParams, 
        		ci.returnType().isVoid(),
        		def.formalNames(),
        		def.guard())
        		.asType();

        assert sup.x10Def().typeParameters().size() == typeArgs.size() : def + ", " + sup + ", " + typeArgs;
        sup = sup.typeArguments(typeArgs);
        
        cd.addInterface(Types.ref(sup));
        
        return cd;
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
		
		X10ClassDef cd = newClosureDefHelp(def);
		X10ClassType ct = (X10ClassType)cd.asType();
		Position pos = cd.position();
		
		X10ClassType supInt = (X10ClassType)cd.interfaces().get(0).get();
		X10MethodInstance supApplyMethInst = (X10MethodInstance)supInt.methods().get(0);
		
		Entity ent = getMethodEntity(supApplyMethInst);
		putClosureEntity(supApplyMethInst.signature(), ent);
		
		// Copy the formal types from the method instance !!! and not from the method def. 
		// Method def can have unresolved types. 
		List<Ref<? extends Type>> types = new LinkedList<Ref<? extends Type>>();
		for(Type t : supApplyMethInst.formalTypes())
			types.add(Types.ref(t));
        
        // create the "apply" method.
        final X10MethodDef mi = typeSystem.methodDef(pos, Types.ref(ct),
        		Flags.PUBLIC, Types.ref(supApplyMethInst.returnType()),
        		ClosureCall.APPLY, 
        		types);
        
        cd.addMethod(mi);
		
        // create the context of the closure
        for(LocalInstance loc : savedFields) {
            FieldDef fdef = typeSystem.fieldDef(pos, Types.ref(ct), Flags.PUBLIC, Types.ref(loc.type()), loc.name());
            cd.addField(fdef);
        }
        
        if(needSavedThis) {
        	// We need a reference to the outer class. 
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
		
		List<LocalInstance> locals = closureVisitor.getLocals();
		Set<LocalInstance> savedLocals = closureVisitor.getSavedLocalInstances();
		boolean needSavedThis = closureVisitor.needSavedThis();
		
		X10ClassDef closureClassDef = newClosureDef(def, savedLocals, needSavedThis);
		X10ClassType closureType = (X10ClassType)closureClassDef.asType();
        X10MethodInstance applyMethod = (X10MethodInstance)closureType.methods().get(0);
        
		Entity entity = getMethodEntity(applyMethod);
        
		/* Create an instance of the closure and save the current context. */
        final Node objectPointer = doNewAlloc(closureType, closureType);
        for(LocalInstance loc : savedLocals) {
    		VarEntry var = firmContext.getVarEntry(loc);
    		assert var.getIdx() != -1; /* must be a local var */
    		
    		Node rhs = con.getVariable(var.getIdx(), typeSystem.getFirmMode(var.getVarInstance().type()));
        	doClosureFieldWrite(objectPointer, loc.def().name().toString(), closureType, rhs);
        }
        
        if(needSavedThis) {
        	Node thisPointer = null;
        	if(firmContext.isInClosure()) {
        		// if we are currently in a closure we will use the saved this reference from the current closure
        		// for the new closure
        		thisPointer = doClosureFieldRead(X10_SAVED_THIS_LITERAL, firmContext.getCurClass());
        	} else {
    			thisPointer = getThis(Mode.getP());
        	}

        	doClosureFieldWrite(objectPointer, X10_SAVED_THIS_LITERAL, closureType, thisPointer);
        }
        
		constructGraph(entity, n, true, formals, locals, false, closureType);
		
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
