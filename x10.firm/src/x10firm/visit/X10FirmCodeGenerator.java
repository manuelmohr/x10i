package x10firm.visit;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

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
import polyglot.ast.Case_c;
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
import polyglot.ast.Stmt;
import polyglot.ast.StringLit_c;
import polyglot.ast.SwitchBlock_c;
import polyglot.ast.Switch_c;
import polyglot.ast.Throw_c;
import polyglot.ast.TopLevelDecl;
import polyglot.ast.Try_c;
import polyglot.ast.Unary_c;
import polyglot.ast.While_c;
import polyglot.frontend.Compiler;
import polyglot.types.FieldInstance;
import polyglot.types.LocalInstance;
import polyglot.types.Type;
import polyglot.util.ErrorInfo;
import polyglot.util.InternalCompilerError;
import x10.ast.AssignPropertyBody_c;
import x10.ast.Async_c;
import x10.ast.AtEach_c;
import x10.ast.AtExpr_c;
import x10.ast.AtStmt_c;
import x10.ast.Atomic_c;
import x10.ast.Await_c;
import x10.ast.ClosureCall_c;
import x10.ast.Closure_c;
import x10.ast.ConstantDistMaker_c;
import x10.ast.Finish_c;
import x10.ast.ForEach_c;
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
import x10.ast.X10Instanceof_c;
import x10.ast.X10IntLit_c;
import x10.ast.X10SourceFile_c;
import x10.ast.X10Special_c;
import x10.ast.X10Unary_c;
import x10.types.X10ClassDef;
import x10.types.X10ClassType;
import x10.types.X10Flags;
import x10.types.X10MethodDef;
import x10.types.X10MethodInstance;
import x10.visit.X10DelegatingVisitor;
import x10cpp.visit.X10SearchVisitor;
import x10firm.types.TypeSystem;
import firm.ArrayType;
import firm.ClassType;
import firm.CompoundType;
import firm.Construction;
import firm.Entity;
import firm.Graph;
import firm.Ident;
import firm.Initializer;
import firm.MethodType;
import firm.Mode;
import firm.PrimitiveType;
import firm.Program;
import firm.TargetValue;
import firm.bindings.binding_ircons.ir_linkage;
import firm.bindings.binding_typerep;
import firm.bindings.binding_typerep.ir_type_state;
import firm.bindings.binding_typerep.ir_visibility;
import firm.nodes.Block;
import firm.nodes.Call;
import firm.nodes.Cmp;
import firm.nodes.Cond;
import firm.nodes.Load;
import firm.nodes.Node;
import firm.nodes.Proj;

/**
 * TODO:
 *  - keep Context up-to-date while traversing the AST
 */
public class X10FirmCodeGenerator extends X10DelegatingVisitor {
	/** The current firm construction object */
	private Construction con;

	/** contains a reference to the class we are currently in (with respect to the AST) */
	private X10ClassType currentClass;

	/** To return Firm nodes for constructing expressions */
	private Node returnNode;

	/** Main Compiler object */
	private final Compiler compiler;

	/** typeSystem is used to map X10 types to Firm types (and modes) */
	private final TypeSystem typeSystem;

	/** Mapping between X10MethodInstances and firm entities. */
	private final HashMap<X10MethodInstance, Entity> methodEntities = new HashMap<X10MethodInstance, Entity>();

	/**
	 * Holds the corresponding target blocks for labeled continue and break statements. 
	 */
	private static class FirmLabel {
		
		/**
		 * Holds the target block for a labeled continue statement
		 */
		private Block continueBlock;
		
		/**
		 * Holds the target block for a labeled break statement
		 */
		private Block breakBlock;
		
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
	private static class FirmScope {
		
		/**
		 * Holds a reference to the upper FirmScope. 
		 */
		private FirmScope prev;
		
		/** 
		 * Mapping between Labels (String) and the corresponding FirmLabels. 
		 */
		private Map<String, FirmLabel> firmLabelMapper     = new HashMap<String, FirmLabel>();
		
		/** Block we will jump into if an expression evaluates to true */
		private Block trueBlock;
		/** Block we will jump into if an expression evaluates to false */
		private Block falseBlock;
		/** Block we will jump into if we reach a continue statement */
		private Block continueBlock;
		/** Block we will jump into if we reach a break statement */
		private Block breakBlock;
		
		/** 
		 * Sets the upper FirmScope for the current FirmScope
		 * 
		 * @param prev The upper FirmScope
		 */
		public void setPrev(FirmScope prev) {
			this.prev = prev;
		}
		
		/**
		 * Returns the upper FirmScope of the current FirmScope
		 * @return The upper FirmScope
		 */
		public FirmScope getPrev() {
			return prev;
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
		
		/** Returns the break block.
		 * @return The break block */
		public Block getBreakBlock() {
			assert breakBlock != null;
			return breakBlock;
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
				if(getPrev() != null)
					return getPrev().getFirmLabelHelp(label);
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
	 * Class that holds attributes (scopes, mapping of local instance variables etc.) for a new method. 
	 * For every new method entry we will create a new firm context. 
	 */
	private static class FirmContext {
		/** Holds the topmost firmScope. -> Push a dummy frame in the current FirmContext */
		private FirmScope topFirmScope = new FirmScope();
		
		/** Maps "LocalInstances" to the appropriate idx`s */
		private Map<LocalInstance, Integer> localInstanceMapper = new HashMap<LocalInstance, Integer>();
		
		/**
		 * Will hold the corresponding statement if we have reached a labeled statement. Otherwise null. 
		 */
		private Stmt stmt;
		
		/**
		 * Will hold the corresponding label if we have reached a labeled statement. Otherwise null. 
		 */
		private String label;

		/**
		 * Create a new Firm context
		 */
		public FirmContext() {
			
		}

		/** Sets the idx for a given local variable
		 * @param loc The local variable for which the index should be set
		 * @param idx The idx for the given local variable
		 */
		public void setIdxForLocalInstance(LocalInstance loc, int idx) {
			assert !localInstanceMapper.containsKey(loc);
			localInstanceMapper.put(loc, new Integer(idx));
		}
		
		/** Returns the idx for a given local variable
		 * @param loc The local variable for which the index should be returned
		 * @return The idx of the given local variable 
		 */
		public int getIdxForLocalInstance(LocalInstance loc) {
			assert localInstanceMapper.containsKey(loc) : "Loc " + loc + " not found";
			return localInstanceMapper.get(loc).intValue();
		}
		
		/** Pushes a new firm scope 
		 * @param scope The firm scope which should be pushed
		 * @return The new firm scope
		 */
		public FirmScope pushFirmScope(FirmScope scope) {
			scope.setPrev(topFirmScope);
			topFirmScope = scope;
			return scope;
		}
		
		/** Pops the topmost firm scope
		 * @return The upper firm scope of the topmost firm scope
		 */
		public FirmScope popFirmScope() {
			assert topFirmScope != null;
			topFirmScope = topFirmScope.getPrev();
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
		 * @param stmt  The statement of the labeled statemt
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
	

	/** current firm context */
	private FirmContext firmContext;

	/**
	 * If n is not already a Cond node, build a Cmp-with-1 and Cond
	 * If n is a Proj node, build a Cond Node
	 * @param n		a Firm node
	 * @return		a Cond Firm node
	 */
	private Node makeCondition(Node n) {
		if(n instanceof Proj || !(n instanceof Cond)) {
			FirmScope topScope = firmContext.getTopScope();

			Block bTrue  = topScope.getTrueBlock();
			Block bFalse = topScope.getFalseBlock();

			Node proj = n;
			if(!(n instanceof Proj)) { // No projection, create an explicit cmp and proj node.
				Node one  = con.newConst(1, n.getMode());
				Node cmp  = con.newCmp(n, one);
				proj = con.newProj(cmp, Mode.getb(), Cmp.pnEq);
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

	/**
	 * Evaluates the given expression and creates the appropriate firm nodes. Afterwards
	 * it creates a new true (holds the value 1) and false (holds the value 0) block for
	 * the results of the expression. Finally the true and false blocks are combined with
	 * a common phi node.
	 * @param E		A polyglot expression
	 * @return		A Phi firm node
	 */
	private Node makeConditionalPhiTrailer(Expr E) {

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
			
			Node ret = visitExpression(E);
			makeCondition(ret);
		}
		firmContext.popFirmScope();

		Block phiBlock = con.newBlock();
		phiBlock.addPred(jmp1);
		phiBlock.addPred(jmp2);

		con.setCurrentBlock(phiBlock);

		Node ret = con.newPhi(new Node[]{one, zero}, Mode.getb());
		return ret;
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
			X10SourceFile_c sf = (X10SourceFile_c) n;
			for (TopLevelDecl top_level_declaration : sf.decls()) {
				visit(top_level_declaration);
			}
			return;
		}

		compiler.errorQueue().enqueue(ErrorInfo.SEMANTIC_ERROR,"Unhandled node type: " + n.getClass(), n.position());
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
	public void visit(X10ClassDecl_c n) {
		X10ClassDef def = (X10ClassDef) n.classDef();
		ClassBody_c body = (ClassBody_c) n.body();

		// TODO: how do we treat native rep classes ?
		assert (!def.isNested()) : ("Nested class alert!");

		// visit the node children (class body)
		List<ClassMember> members = body.members();

		for (ClassMember member : members) {
			visitAppropriate(member);
		}
	}

	@Override
	public void visit(LocalClassDecl_c n) {
		throw new RuntimeException("Local classes should have been removed by a separate pass");
	}

	@Override
	public void visit(ClassBody_c n) {
		if (currentClass.flags().isInterface()) {
			// TODO: Implement me
		} else if (currentClass.isX10Struct()) {
			// TODO: Implement me
		} else {
			for (ClassMember member : n.members())
				visitAppropriate(member);
		}
	}

	@Override
	public void visit(PackageNode_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(Import_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	/**
	 * Return entity for an X10 method
	 */
	private Entity getMethodEntity(X10MethodInstance methodInstance) {
		Entity entity = methodEntities.get(methodInstance);
		if (entity == null) {
			X10ClassType owner = (X10ClassType) methodInstance.container();
			String name = methodInstance.name().toString();
			X10Flags flags = X10Flags.toX10Flags(methodInstance.flags());

			firm.Type ownerFirm = typeSystem.asFirmCoreType(owner);
			firm.Type type = typeSystem.asFirmType(methodInstance);
			entity = new Entity(ownerFirm, name, type);
			if (flags.isStatic()) {
				/* set_entity_allocation is deprecated firm API, but we use
				 * it anyway for now... */
				binding_typerep.set_entity_allocation(entity.ptr, binding_typerep.ir_allocation.allocation_static.val);
			}
			methodEntities.put(methodInstance, entity);
		}

		return entity;
	}

	/** Finds all locals and formals in the given method.
	 *  @param dec The method declaration
	 *  @param formals Will hold all found formals.
	 *  @param locals  Will hold all found locals.
	 */
	private void findAllLocalInstancesInMethod(MethodDecl_c dec, List<LocalInstance> formals, List<LocalInstance> locals) {
		// extract all formal parameters from the given method
		X10MethodDef def      = (X10MethodDef)dec.methodDef();
		X10MethodInstance mi  = (X10MethodInstance)def.asInstance();

		// add the formal local instances.
		formals.addAll(mi.formalNames());

		if(dec.body() != null) {
			// Search the body of the method declaration for LocalDecl_c`s
			X10SearchVisitor<LocalDecl_c> xLocals = new X10SearchVisitor<LocalDecl_c>(LocalDecl_c.class);
			dec.body().visit(xLocals);

			if(!xLocals.found())
				return;

			List<LocalDecl_c> matchesList  = xLocals.getMatches();

			for(LocalDecl_c c : matchesList) {
				// extract the local instances from the found "LocalDecl_c`s"
				LocalInstance locInstance = c.localDef().asInstance();
				// don`t include the local instances from the formals or duplicate local instances.
				if(formals.contains(locInstance) || locals.contains(locInstance))
					continue;

				locals.add(locInstance);
			}
		}
	}

	@Override
	public void visit(MethodDecl_c dec) {
		X10Flags flags 						= X10Flags.toX10Flags(dec.flags().flags());
		X10MethodDef def 					= (X10MethodDef) dec.methodDef();
		X10MethodInstance methodInstance 	= (X10MethodInstance) def.asInstance();
		Entity entity 						= getMethodEntity(methodInstance);

		if (flags.isNative()) {
			assert def.body() == null;
			/* native code is defined elsewhere, so nothing left to do */
			return;
		}

		List<LocalInstance> formals = new ArrayList<LocalInstance>();
		List<LocalInstance> locals  = new ArrayList<LocalInstance>();

		// extract all formals and locals from the method.
		findAllLocalInstancesInMethod(dec, formals, locals);

		int nVars = formals.size() + locals.size();

		boolean isStatic = flags.isStatic();
		if (!isStatic) {
			// Add 'this'
			nVars++;
		}

		Graph graph = new Graph(entity, nVars);
		con 		= new Construction(graph);
		firmContext = new FirmContext();

		Node args = graph.getArgs();
		if(!isStatic) {
			X10ClassType owner = (X10ClassType) methodInstance.container();
			firm.Type ownerFirm = typeSystem.asFirmType(owner);

			// map 'this'
			Node projThis = con.newProj(args, ownerFirm.getMode(), 0);
			con.setVariable(0, projThis);
		}

		int idx = isStatic ? 0 : 1;

		// init and map all parameters.
		for (LocalInstance loc : formals) {
			Node projParam = con.newProj(args, typeSystem.getFirmMode(loc.type()), idx);
			con.setVariable(idx, projParam);

			// map the local instance with the appropriate idx.
			firmContext.setIdxForLocalInstance(loc, idx);
			idx++;
		}

		// map all local variables.
		for (LocalInstance loc : locals) {
			// map the local instance with the appropriate idx.
			firmContext.setIdxForLocalInstance(loc, idx);
			idx++;
		}

		// Walk body and construct graph
		visitAppropriate(dec.body());

		// create Return node if there was no explicit return statement yet
		if (!con.getCurrentBlock().isBad()) {
			assert ((MethodType)entity.getType()).getNRess() == 0;
			Node mem = con.getCurrentMem();
			Node returnn = con.newReturn(mem, new Node[0]);
			con.getGraph().getEndBlock().addPred(returnn);
		}

		con.finish();

		// Dump the created graph
		firm.Dump.dumpGraph(con.getGraph(), "-fresh");
	}

	@Override
	public void visit(ConstructorDecl_c dec) {
		// TODO: Implement me
	}

	@Override
	public void visit(FieldDecl_c dec) {
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
	public void visit(AssignPropertyBody_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(Assert_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(Switch_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(SwitchBlock_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(Case_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(Branch_c br) {
		if(con.getCurrentBlock().isBad())
			return;
		
		FirmScope topScope = firmContext.getTopScope();
		if (br.labelNode() != null) {
			Block target = null;
			String label = br.labelNode().id().toString();
			if(br.kind() == Branch.CONTINUE) {
				target = topScope.getBlockForLabeledContinue(label);
			} else {
				target = topScope.getBlockForLabeledBreak(label);
			}
			Node jmp = con.newJmp();
			target.addPred(jmp);
		} else {
			// unlabeled continue or break; 
			Block target = null;
			if (br.kind() == Branch.CONTINUE) {
				target = topScope.getContinueBlock();
			} else {
				target = topScope.getBreakBlock();
			}
			
			Node jmp = con.newJmp();
			target.addPred(jmp);
		}
		
		con.setCurrentBlockBad();
	}


	@Override
	public void visit(Labeled_c label) {   
		
		Stmt stmt 	= label.statement();
		String lab 	= label.labelNode().id().toString(); 
		
		// Mark the corresponding stmt with the appropriate label
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

		if(lhs instanceof Local_c) { // Assignment to a local variable
			Node leftRet = visitExpression(lhs);
			Node rightRet = visitExpression(rhs);

			Local_c lhsLocal  	= (Local_c)lhs;
			LocalInstance loc 	= lhsLocal.localInstance();
			int idx 			= firmContext.getIdxForLocalInstance(loc);

			con.setVariable(idx, rightRet);
			setReturnNode(con.getVariable(idx, leftRet.getMode()));
		} else {
			// TODO: Implement me
			throw new RuntimeException("Not implemented yet");
		}
	}

	@Override
	public void visit(Return_c ret) {
		Node retNode;

		Expr e = ret.expr();
		if (e != null) {
			Node retValue = visitExpression(e);
			retNode = con.newReturn(con.getCurrentMem(), new Node[]{retValue});
		} else {
			retNode = con.newReturn(con.getCurrentMem(), new Node[]{});
		}

		/* for error detection */
		con.getGraph().getEndBlock().addPred(retNode);
		con.setCurrentBlockBad();
	}

	@Override
	public void visit(Formal_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(LocalDecl_c dec) {
		Expr initexpr = dec.init();

		if (initexpr != null) {
			LocalInstance loc = dec.localDef().asInstance();

			Node initNode = visitExpression(initexpr);

			int idx = firmContext.getIdxForLocalInstance(loc);
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
	public void visit(For_c n) {
		throw new RuntimeException("Not implemented yet");
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
			newScope.setContinueBlock(bCond);
			newScope.setBreakBlock(bFalse);
			
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

		con.setCurrentBlock(bCond);
		
		topScope  = firmContext.getTopScope();
		newScope  = (FirmScope)topScope.clone();
		
		firmContext.pushFirmScope(newScope);
		{
			newScope.setTrueBlock(bTrue);
			newScope.setFalseBlock(bFalse);
			
			Node retNode = visitExpression(n.cond());
			makeCondition(retNode);
		}
		firmContext.popFirmScope();
		
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
			
			Node retNode = visitExpression(n.cond());
			makeCondition(retNode);
		}
		firmContext.popFirmScope();
		
		con.setCurrentBlock(bTrue);
		
		topScope = firmContext.getTopScope();
		newScope = (FirmScope)topScope.clone();
		
		firmContext.pushFirmScope(newScope); 
		{
			newScope.setContinueBlock(bCond);
			newScope.setBreakBlock(bFalse);
			
			if(label != null) {
				newScope.setBlockForLabeledBreak(label, bFalse);
				newScope.setBlockForLabeledContinue(label, bCond);
			}
			
			Stmt body = n.body();
			visitAppropriate(body);
		}
		firmContext.popFirmScope();
		
		if(!con.getCurrentBlock().isBad())
			bCond.addPred(con.newJmp());
		
		con.setCurrentBlock(bFalse);
	}

	@Override
	public void visit(Conditional_c n) {

		// check if we have an constant condition
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
			
			Node ret = visitExpression(n.cond());

			makeCondition(ret);
		}
		firmContext.popFirmScope();

		bTrue.mature();
		bFalse.mature();

		// add a common phi block for the true and false expressions.
		Block phiBlock = con.newBlock();
		phiBlock.addPred(endIf);
		phiBlock.addPred(endElse);

		con.setCurrentBlock(phiBlock);

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
			
			Node retNode = visitExpression(n.cond());
			makeCondition(retNode);
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
			else
				bAfter.addPred(con.newJmp());
		}

		con.setCurrentBlock(bAfter);

		if(endIf != null)
			bAfter.addPred(endIf);
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
		Node address = con.newSymConst(entity);

		int param_count = type.getNParams();
		List<Expr> arguments = n.arguments();
		if (arguments.size()+1 == param_count) {
			/* arguments is immutable, so we construct a new list */
			List<Expr> na = new LinkedList<Expr>();
			na.add(0, (Expr) n.target());
			na.addAll(arguments);
			arguments = na;
		}
		assert arguments.size() == param_count : "parameters are off : "+arguments.size()+" vs "+param_count;
		Node[] parameters = new Node[param_count];
		for (int i=0; i<param_count; i++) {
			parameters[i] = visitExpression(arguments.get(i));
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
	public void visit(RegionMaker_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(ConstantDistMaker_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	private Entity getFieldEntity(FieldInstance field) {
		polyglot.types.Type owner = field.container();
		firm.Type ownerFirm = typeSystem.asFirmCoreType(owner);

		/* search the entity */
		CompoundType compoundType = (CompoundType) ownerFirm;
		for (Entity member : compoundType.getMembers()) {
			if (member.getName().equals(field.name().toString()))
				return member;
		}
		throw new RuntimeException(String.format("Entity for field '%s' not found", field));
	}

	@Override
	public void visit(Field_c n) {
		FieldInstance instance = n.fieldInstance();
		FieldInstance def = instance.def().asInstance();
		X10Flags flags = (X10Flags) def.flags();
		Entity entity = getFieldEntity(def);

		Node address;
		if (flags.isStatic()) {
			address = con.newSymConst(entity);
		} else {
			Receiver target = n.target();
			Node objectPointer = visitExpression((Expr)target);
			address = con.newSel(objectPointer, entity);
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

	@Override
	public void visit(Local_c n) {
		LocalInstance loc = n.localInstance();
		int idx = firmContext.getIdxForLocalInstance(loc);

		Node ret = con.getVariable(idx, typeSystem.getFirmMode(loc.type()));

		setReturnNode(ret);
	}

	@Override
	public void visit(New_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(FloatLit_c n) {

		Mode mode = null;

		if (n.kind() == FloatLit.FLOAT)
			mode = typeSystem.getFirmMode(typeSystem.Float());
		else if (n.kind() == FloatLit.DOUBLE)
			mode = typeSystem.getFirmMode(typeSystem.Double());
		else
			throw new InternalCompilerError("Unrecognized FloatLit kind " + n.kind());

		Node ret = con.newConst(TargetValue.newFromDouble(n.value(), mode));
		setReturnNode(ret);
	}

	@Override
	public void visit(IntLit_c n) {

		Mode mode = null;

		if (n.kind() == X10IntLit_c.ULONG) {
			mode = typeSystem.getFirmMode(typeSystem.ULong());
		} else if (n.kind() == X10IntLit_c.UINT) {
			mode = typeSystem.getFirmMode(typeSystem.UInt());
		} else if (n.kind() == IntLit.LONG) {
			mode = typeSystem.getFirmMode(typeSystem.Long());
		} else if (n.kind() == IntLit.INT) {
			mode = typeSystem.getFirmMode(typeSystem.Int());
		} else {
			throw new InternalCompilerError("Unrecognized IntLit kind " + n.kind());
		}

		Node ret = con.newConst(new TargetValue(n.value(), mode));
		setReturnNode(ret);
	}

	@Override
	public void visit(NullLit_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(StringLit_c n) {
		/* Construct call to builtin function, which creates an X10 string struct. */

		Node string_const = createStringSymConst(n.value());

		final String name = "x10_string_literal";

		final firm.Type[] parameterTypes = new firm.Type[2];
		parameterTypes[0] = new PrimitiveType(Mode.getIu());
		parameterTypes[1] = new PrimitiveType(string_const.getMode());
		final firm.Type[] resultTypes = new firm.Type[1];
		resultTypes[0] = typeSystem.asFirmType(typeSystem.String());
		MethodType type = new firm.MethodType(parameterTypes, resultTypes);

		Entity func_ent = new Entity(Program.getGlobalType(), name, type);
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
		firm.Type elem_type = typeSystem.asFirmType(typeSystem.Int());
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

	@Override
	public void visit(CharLit_c lit) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(BooleanLit_c lit) {
		int val = (lit.value() ? 1 : 0);

		Node ret = con.newConst(val, typeSystem.getFirmMode(typeSystem.Boolean()));
		setReturnNode(ret);
	}

	@Override
	public void visit(Id_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(X10Cast_c c) {
		throw new RuntimeException("Not implemented yet");
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
	public void visit(ForEach_c n) {
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
	public void visit(ParExpr_c n) {
		visitAppropriate(n.expr());
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
	public void visit(X10Special_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(Closure_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(ClosureCall_c c) {
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

	    		Node retLeft  = null;
	    		Node retRight = null;

	    		// no new firm scope needed
	    		retLeft  = visitExpression(left);
	    		retRight = visitExpression(right);

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
	    } else if ((l.isNumeric() && r.isNumeric()) ||
	    	(l.isBoolean() && r.isBoolean())) {
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
				
				Node r = visitExpression(B.left());
				makeCondition(r);
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
				
				Node r = visitExpression(B.right());
				ret = makeCondition(r);
			}
			firmContext.popFirmScope();

			setReturnNode(ret);
		} else {
			Node ret = makeConditionalPhiTrailer(B);
			setReturnNode(ret);
		}
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
