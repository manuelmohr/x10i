package x10firm.visit;

import static x10cpp.visit.ASTQuery.assertNumberOfInitializers;
import static x10cpp.visit.ASTQuery.getStringPropertyInit;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import polyglot.ast.ArrayAccess_c;
import polyglot.ast.ArrayInit_c;
import polyglot.ast.Assert_c;
import polyglot.ast.Assign_c;
import polyglot.ast.Binary_c;
import polyglot.ast.Block_c;
import polyglot.ast.BooleanLit_c;
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
import polyglot.ast.Node;
import polyglot.ast.NullLit_c;
import polyglot.ast.PackageNode_c;
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
import polyglot.types.LocalInstance;
import polyglot.types.QName;
import polyglot.types.SemanticException;
import polyglot.types.Type;
import polyglot.util.ErrorInfo;
import polyglot.util.InternalCompilerError;
import polyglot.frontend.Compiler;
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
import x10.ast.X10Local_c;
import x10.ast.X10NodeFactory;
import x10.ast.X10SourceFile_c;
import x10.ast.X10Special_c;
import x10.ast.X10Unary_c;
import x10.types.X10ClassDef;
import x10.types.X10ClassType;
import x10.types.X10Context;
import x10.types.X10Context_c;
import x10.types.X10Flags;
import x10.types.X10MethodDef;
import x10.types.X10MethodInstance;
import x10.types.X10TypeSystem;
import x10.visit.X10DelegatingVisitor;
import x10cpp.visit.ASTQuery;
import x10cpp.visit.X10SearchVisitor;
import x10firm.types.TypeSystem;
import firm.TargetValue;
import java.util.*;

/**
 * TODO:
 *  - keep Context up-to-date while traversing the AST 
 */
public class X10FirmCodeGenerator extends X10DelegatingVisitor {
	private firm.Construction con;
	private firm.Graph currentGraph;
	private X10ClassType currentClass;

	/** To return Firm nodes for constructing expressions */
	private firm.nodes.Node return_node;
	
	private final Compiler compiler;
	private final TypeSystem typeSystem;
	
	
	private final X10NodeFactory nodeFactory;
	private final X10Context context;
	private final ASTQuery query;
	
	// following getters are needed for avoiding compiler errors. (never read locally attributes)
	public X10NodeFactory getNodeFactory() {
		return nodeFactory;
	}
	
	public X10Context getX10Context() {
		return context;
	}
	
	public ASTQuery getASTQuery() {
		return query;
	}
	
	class FirmScope {
		private firm.nodes.Block []blocks;
		
		public FirmScope(firm.nodes.Block []blocks) {
			this.blocks = blocks;
		}
		
		public void setBlocks(firm.nodes.Block []blocks) {
			this.blocks = blocks;
		}
		
		public firm.nodes.Block []getBlocks() {
			return blocks;
		}
	}
	
	class FirmContext {
		private FirmContext prev;
		private Stack<FirmScope> firmScopes = new Stack<FirmScope>();
		// Maps "LocalInstances" to the appropriate IDs.
		private Map<LocalInstance, Integer> localInstanceMapper = new HashMap<LocalInstance, Integer>();
		
		public FirmContext(FirmContext prev) {
			this.prev = prev;
		}
		
		public FirmContext pushFirmContext() {
			return new FirmContext(this);
		}
		
		public FirmContext popFirmContext() {
			return prev;
		}
		
		public boolean hasIdxForLocalInstance(LocalInstance loc) {
			return localInstanceMapper.containsKey(loc);
		}
		
		@SuppressWarnings("boxing")
		public void putIdxForLocalInstance(LocalInstance loc, int idx) {
			assert !localInstanceMapper.containsKey(loc);
			localInstanceMapper.put(loc, idx);
		}
		
		public int getIDForLocalInstance(LocalInstance loc) {
			assert localInstanceMapper.containsKey(loc) : "Loc " + loc + " not found";
			return localInstanceMapper.get(loc).intValue();
		}
		
		public FirmScope pushFirmScope(FirmScope scope) {
			return firmScopes.push(scope);
		}
		
		public FirmScope popFirmScope() {
			assert !firmScopes.isEmpty();
			return firmScopes.pop();
		}
		
		public FirmScope getTopScope() {
			assert !firmScopes.isEmpty();
			return firmScopes.peek();
		}
	}
	
	// current firm context
	private FirmContext firmContext = new FirmContext(null);
	
	private firm.nodes.Node makeCondition(firm.nodes.Node n) {
		if(!(n instanceof firm.nodes.Cond)) {
			FirmScope scope = firmContext.getTopScope();
			
			firm.nodes.Block []blocks = scope.getBlocks();
			
			firm.nodes.Node c    = con.newConst(1, typeSystem.getFirmMode(typeSystem.Boolean()));
			firm.nodes.Node cmp  = con.newCmp(n, c);
			firm.nodes.Node proj = con.newProj(cmp, firm.Mode.getb(), firm.nodes.Cmp.pnEq);
			firm.nodes.Node cond = con.newCond(proj);
			
			firm.nodes.Node projTrue  = con.newProj(cond, firm.Mode.getX(), firm.nodes.Cond.pnTrue);
			firm.nodes.Node projFalse = con.newProj(cond, firm.Mode.getX(), firm.nodes.Cond.pnFalse);
			
			firm.nodes.Block bTrue  = blocks[0];
			firm.nodes.Block bFalse = blocks[1];
			
			bTrue.addPred(projTrue);
			bFalse.addPred(projFalse);
			
			return cond;
		}
		return n;
	}
	
	public X10FirmCodeGenerator(Compiler compiler, TypeSystem typeSystem, X10NodeFactory nodeFactory) {
		this.compiler 		= compiler;
		this.typeSystem 	= typeSystem;
		this.nodeFactory 	= nodeFactory;
		this.context 		= new X10Context_c(typeSystem);
		
		NoTranslator translator = new NoTranslator(typeSystem, nodeFactory);
		this.query 				= new ASTQuery(translator);
		
		// We can only initialize our type system after
		// the system resolver has been run. 
		typeSystem.init();
	}
	
	private void setReturnNode(firm.nodes.Node returnNode) {
		return_node = returnNode;
	}
	
	private firm.nodes.Node getReturnNode() {
		return return_node;
	}

	@Override
	public void visit(Node n) {
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
		assert false;
	}

	@Override
	public void visit(LocalTypeDef_c n) {
		assert false;
	}

	@Override
	public void visit(X10ClassDecl_c n) {
		X10ClassDef def = (X10ClassDef) n.classDef();
		boolean isStruct = typeSystem.isStructType(def.asType());
		// X10Ext ext = (X10Ext) n.ext();
		ClassBody_c body = (ClassBody_c) n.body();

		// TODO: how do we treat native rep classes ?
		assert (!def.isNested()) : ("Nested class alert!");
		
		// decl a new FirmClassType
		if (!isStruct)
			typeSystem.declFirmClass(def.asType());
		else
			typeSystem.declFirmStruct(def.asType());

		// visit the node children (class body)
		List<ClassMember> members = body.members();

		for (ClassMember member : members) {
			visitAppropriate(member);
		}
	}

	// returns the first argument in a native rep
	public static String getNativeRep(X10ClassDef def) {
		return getNativeRepParam(def, 1);
	}

	// returns the second argument in a native box
	public static String getNativeBoxRep(X10ClassDef def) {
		return getNativeRepParam(def, 2);
	}

	// returns the third argument in a native rtt rep
	public static String getCppRTTRep(X10ClassDef def) {
		return getNativeRepParam(def, 3);
	}
	
	private static final String FIRM_NATIVE_STRING = "firm";
	
	// returns the i argument in a native annotation
	public static String getNativeRepParam(X10ClassDef def, int i) {
		try {
			X10TypeSystem xts = (X10TypeSystem) def.typeSystem();
			Type rep = (Type) xts.systemResolver().find(QName.make("x10.compiler.NativeRep"));
			List<Type> as = def.annotationsMatching(rep);
			for (Type at : as) {
				assertNumberOfInitializers(at, 4);
				String lang = getStringPropertyInit(at, 0);
				if (lang != null && lang.equals(FIRM_NATIVE_STRING)) {
					return getStringPropertyInit(at, i);
				}
			}
		} catch (SemanticException e) {
			// TODO what now?
		}
		return null;
	}
	
	void processClass(X10ClassDecl_c n) {
		X10ClassDef def = (X10ClassDef) n.classDef();
		boolean isStruct = typeSystem.isStructType(def.asType());
		// X10Ext ext = (X10Ext) n.ext();
		ClassBody_c body = (ClassBody_c) n.body();

		// TODO: how do we treat native rep classes ?
		assert (!def.isNested()) : ("Nested class alert!");

		// decl a new FirmClassType
		if (!isStruct)
			typeSystem.declFirmClass(def.asType());
		else
			typeSystem.declFirmStruct(def.asType());

		// visit the node children (class body)
		List<ClassMember> members = body.members();

		for (ClassMember member : members) {
			visitAppropriate(member);
		}
	}

	@Override
	public void visit(LocalClassDecl_c n) {
		assert (false) : ("Local classes should have been removed by a separate pass");
	}

	@Override
	public void visit(ClassBody_c n) {
		
		if (currentClass.flags().isInterface()) {
			// TODO: Implement me
		} else if (currentClass.isX10Struct()) {
			// TODO: Implement me
		} else {
			for (ClassMember member : n.members()) {
				visitAppropriate(member);
			}
		}
	}

	@Override
	public void visit(PackageNode_c n) {
		assert false;
	}

	@Override
	public void visit(Import_c n) {
		assert false;
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
			// Search the body of the method declaration for X10Local_c`s
			X10SearchVisitor<X10Local_c> xLocals = new X10SearchVisitor<X10Local_c>(X10Local_c.class);
			dec.body().visit(xLocals);
			
			if(!xLocals.found()) 
				return;
			
			List<X10Local_c> matchesList  = xLocals.getMatches();
			
			for(X10Local_c c : matchesList) {
				// extract the local instances from the found "X10Local_c`s"
				LocalInstance locInstance = c.localInstance();
				// don`t include the local instances from the formals. 
				if(formals.contains(locInstance)) 
					continue;
				
				locals.add(locInstance);
			}
		}
	}
	
	private void openMethod(List<LocalInstance> params, List<LocalInstance> vars, boolean isStatic) {
		// Push a new firm context
		firmContext = firmContext.pushFirmContext();
		
		firm.nodes.Node args = currentGraph.getArgs();
		if(!isStatic) {
			// map 'this'
			firm.nodes.Node projThis = con.newProj(args, typeSystem.getFirmMode(currentClass), 0);
			con.setVariable(0, projThis);
		}
		
		int idx = isStatic ? 0 : 1;
		
		// init and map all parameters. 
		for(LocalInstance loc : params) {
			firm.nodes.Node projParam = con.newProj(args, typeSystem.getFirmMode(loc.type()), idx);
			con.setVariable(idx, projParam);
			
			if(firmContext.hasIdxForLocalInstance(loc))
				continue;
			
			// map the local instance with the appropriate idx. 
			firmContext.putIdxForLocalInstance(loc, idx);
			idx++;
		}

		// map all local variables. 
		for(LocalInstance loc : vars) {
			if(firmContext.hasIdxForLocalInstance(loc))
				continue;
			
			// map the local instance with the appropriate idx. 
			firmContext.putIdxForLocalInstance(loc, idx);
			idx++;
		}
	}
	
	private void closeMethod() {
		firmContext = firmContext.popFirmContext();
		
		// Dump the created graph
		firm.Dump.dumpGraph(currentGraph, "-fresh");
	}

	@Override
	public void visit(MethodDecl_c dec) {
		X10Flags flags = X10Flags.toX10Flags(dec.flags().flags());
		
		if (flags.isNative()) {
			// TODO Firm must handle this!
			return;
		}
		
		X10MethodDef def 	  = (X10MethodDef) dec.methodDef();
		X10MethodInstance mi  = (X10MethodInstance)def.asInstance();
		
		// container is the owner class type of the current method
		X10ClassType ownerClassType = (X10ClassType) mi.container();
		
		assert (con == null);
		
		firm.Entity methEnt = typeSystem.declFirmMethod(def, flags, ownerClassType);
		
		List<LocalInstance> formals = new ArrayList<LocalInstance>();
		List<LocalInstance> locals  = new ArrayList<LocalInstance>();
		
		// extract all formals and locals from the method. 
		findAllLocalInstancesInMethod(dec, formals, locals);
		
		int nVars = formals.size() + locals.size();
		
		if(!flags.isStatic()) {
			// Add 'this'
			nVars++;
		}
		
		currentGraph 	= new firm.Graph(methEnt, nVars);
		con 			= new firm.Construction(currentGraph);
		
		openMethod(formals, locals, flags.isStatic());
		
		if ((ownerClassType.x10Def().typeParameters().size() != 0) && flags.isStatic()) {
			// handle static method decl.
			assert false;
			return;
		}
		
		if (dec.body() != null) {
			if (!flags.isStatic()) {
				// add local vars for closure realisation.
				/*
				VarInstance<?> ti = typeSystem.localDef(Position.COMPILER_GENERATED,
						Flags.FINAL, Types.ref(container), Name.make(THIS))
						.asInstance();
				context.addVariable(ti);
				*/
			}
			visitAppropriate(dec.body());
		} else {
			/*
			// Define property getter methods.
			if (flags.isProperty() && flags.isAbstract() && mi.formalTypes().size() == 0 && mi.typeParameters().size() == 0) {
				X10FieldInstance fi = (X10FieldInstance) ownerClassType.fieldNamed(mi.name());
				if (fi != null) {
					String fieldName = fi.name().toString();
				}
			}
			*/
		}
		
		closeMethod();
	}

	@Override
	public void visit(ConstructorDecl_c dec) {
		
	}

	@Override
	public void visit(FieldDecl_c dec) {
		assert false;
	}

	@Override
	public void visit(PropertyDecl_c n) {
		assert false;
	}

	@Override
	public void visit(Initializer_c n) {
		assert false;
	}

	@Override
	public void visit(AssignPropertyBody_c n) {
		assert false;
	}

	@Override
	public void visit(Assert_c n) {
		assert false;
	}

	@Override
	public void visit(Switch_c n) {
		assert false;
	}

	@Override
	public void visit(SwitchBlock_c n) {
		assert false;
	}

	@Override
	public void visit(Case_c n) {
		assert false;
	}

	@Override
	public void visit(Branch_c br) {
		assert false;
	}

	@Override
	public void visit(Labeled_c label) {
		assert false;
	}

	@Override
	public void visit(Assign_c asgn) {
		Expr lhs = asgn.left();
		Expr rhs = asgn.right();
		
		visitAppropriate(lhs);
		visitAppropriate(rhs);
	}

	@Override
	public void visit(Return_c ret) {
		firm.nodes.Node retNode;
		
		Expr e = ret.expr();
		if (e != null) {
			visitAppropriate(e);
			assert (getReturnNode() != null);
			
			firm.nodes.Node retValue = getReturnNode();
			retNode = con.newReturn(con.getCurrentMem(), new firm.nodes.Node[]{retValue});
		} else {
			retNode = con.newReturn(con.getCurrentMem(), new firm.nodes.Node[]{});
		}

		/* for error detection */
		currentGraph.getEndBlock().addPred(retNode);
		con.setCurrentBlockBad();
		con.finish();
	}

	@Override
	public void visit(Formal_c n) {
		assert false;
	}

	@Override
	public void visit(LocalDecl_c dec) {
		Expr initexpr = dec.init();
		
		if (initexpr != null) 
			visitAppropriate(initexpr);
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
		assert false;
	}

	@Override
	public void visit(Do_c n) {
		
		firm.nodes.Block bCond  = con.newBlock();
		firm.nodes.Block bTrue  = con.newBlock();
		firm.nodes.Block bAfter = con.newBlock();
		
		bTrue.addPred(con.newJmp());
		con.setCurrentBlock(bTrue);
		
		Stmt body = n.body();
		visitAppropriate(body);
		
		firm.nodes.Block []blocks = new firm.nodes.Block[]{bTrue, bAfter};
		firmContext.pushFirmScope(new FirmScope(blocks));
		{
			bCond.addPred(con.newJmp());
			con.setCurrentBlock(bCond);
			
			visitAppropriate(n.cond());
			firm.nodes.Node retNode = getReturnNode();
			makeCondition(retNode);
		}
		firmContext.popFirmScope();
		
		con.setCurrentBlock(bAfter);
	}

	@Override
	public void visit(While_c n) {
		firm.nodes.Block bCond  = con.newBlock();
		firm.nodes.Block bTrue  = con.newBlock();
		firm.nodes.Block bAfter = con.newBlock();
		
		bCond.addPred(con.newJmp());
		con.setCurrentBlock(bCond);
		
		firm.nodes.Block []blocks = new firm.nodes.Block[]{bTrue, bAfter};
		FirmScope newScope = new FirmScope(blocks);
		firmContext.pushFirmScope(newScope);
		{
			visitAppropriate(n.cond());
			firm.nodes.Node retNode = getReturnNode();
			makeCondition(retNode);
		}
		firmContext.popFirmScope();
		
		con.setCurrentBlock(bTrue);
		
		Stmt body = n.body();
		visitAppropriate(body);
		
		if(!con.getCurrentBlock().isBad())
			bCond.addPred(con.newJmp());
		
		con.setCurrentBlock(bAfter);
	}

	@Override
	public void visit(If_c n) {
		firm.nodes.Block bTrue  = con.newBlock();
		firm.nodes.Block bAfter = con.newBlock();
		
		firm.nodes.Block bFalse = null; // block will only be created if we have an else stmt.
		
		firm.nodes.Block[] blocks = new firm.nodes.Block[2];
		blocks[0] = bTrue;
		if (n.alternative() != null) {
			bFalse = con.newBlock();
			blocks[1] = bFalse;
		} else {
			blocks[1] = bAfter;
		}

		FirmScope newScope = new FirmScope(blocks);
		firmContext.pushFirmScope(newScope);
		{
			visitAppropriate(n.cond());
			firm.nodes.Node retNode = getReturnNode();
			makeCondition(retNode);
		}
		firmContext.popFirmScope();
		
		con.setCurrentBlock(bTrue);

		visitAppropriate(n.consequent());

		firm.nodes.Node endIf = null;
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
		assert false;
	}

	@Override
	public void visit(Eval_c n) {
		visitAppropriate(n.expr());
	}

	protected String[] getCurrentNativeStrings() {
		return new String[] { FIRM_NATIVE_STRING };
	}

	/*
	// returns true if the given X10Def has a native annotation
	private String getNativeFirmExpressionForDef(X10Def o) {
		X10TypeSystem xts = (X10TypeSystem) o.typeSystem();
		try {
			Type annotation = (Type) xts.systemResolver().find(QName.make("x10.compiler.Native"));
			String[] our_langs = getCurrentNativeStrings();
			for (String our_lang : our_langs) {
				List<Type> as = o.annotationsMatching(annotation);
				for (Type at : as) {
					assertNumberOfInitializers(at, 2);
					String lang = getStringPropertyInit(at, 0);
					if (lang != null && lang.equals(our_lang)) {
						String lit = getStringPropertyInit(at, 1);
						return lit;
					}
				}
			}
		} catch (SemanticException e) {
			// TODO what now?
		}
		return null;
	}
	*/

	@Override
	public void visit(X10Call_c n) {
		assert false;
	}

	@Override
	public void visit(RegionMaker_c n) {
		assert false;
	}

	@Override
	public void visit(ConstantDistMaker_c n) {
		assert false;
	}

	@Override
	public void visit(Field_c n) {
		assert false;
	}

	@Override
	public void visit(Local_c n) {
		LocalInstance loc = n.localInstance();
		int id = firmContext.getIDForLocalInstance(loc);
		
		firm.nodes.Node ret = con.getVariable(id, typeSystem.getFirmMode(loc.type()));
		
		setReturnNode(ret);
	}

	@Override
	public void visit(New_c n) {
		assert false;
	}

	@Override
	public void visit(FloatLit_c n) {
		
		firm.Mode mode = null;

		if (n.kind() == FloatLit.FLOAT)
			mode = typeSystem.getFirmMode(typeSystem.Float());
		else if (n.kind() == FloatLit.DOUBLE)
			mode = typeSystem.getFirmMode(typeSystem.Double());
		else
			throw new InternalCompilerError("Unrecognized FloatLit kind " + n.kind());

		setReturnNode(con.newConst(TargetValue.newFromDouble(n.value(), mode)));
	}

	@Override
	public void visit(IntLit_c n) {
		
		firm.Mode mode = null;
		
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
		
		setReturnNode(con.newConst(new TargetValue(n.value(), mode)));
	}

	@Override
	public void visit(NullLit_c n) {
		assert false;
	}

	@Override
	public void visit(StringLit_c n) {
		assert false;
	}

	@Override
	public void visit(CharLit_c lit) {
		assert false;
	}

	@Override
	public void visit(BooleanLit_c lit) {
		int val = (lit.value() ? 1 : 0);

		setReturnNode(con.newConst(val, typeSystem.getFirmMode(typeSystem.Boolean())));
	}

	@Override
	public void visit(Id_c n) {
		assert false;
	}

	@Override
	public void visit(X10Cast_c c) {
		assert false;
	}

	@Override
	public void visit(SubtypeTest_c n) {
		assert false;
	}

	@Override
	public void visit(X10Instanceof_c n) {
		assert false;
	}

	@Override
	public void visit(Throw_c n) {
		assert false;
	}

	@Override
	public void visit(Try_c n) {
		assert false;
	}

	@Override
	public void visit(Catch_c n) {
		assert false;
	}

	@Override
	public void visit(Atomic_c a) {
		assert false;
	}

	@Override
	public void visit(Await_c n) {
		assert false;
	}

	@Override
	public void visit(Next_c n) {
		assert false;
	}

	@Override
	public void visit(ForLoop_c n) {
		assert false;
	}

	@Override
	public void visit(ForEach_c n) {
		assert false;
	}

	@Override
	public void visit(AtEach_c n) {
		assert false;
	}

	@Override
	public void visit(Finish_c n) {
		assert false;
	}

	@Override
	public void visit(ArrayAccess_c n) {
		assert false;
	}

	@Override
	public void visit(ParExpr_c n) {
		assert false;
	}

	@Override
	public void visit(Conditional_c n) {
		assert false;
	}

	@Override
	public void visit(Here_c n) {
		assert false;
	}

	@Override
	public void visit(Async_c n) {
		assert false;
	}

	@Override
	public void visit(X10Special_c n) {
		assert false;
	}

	@Override
	public void visit(Closure_c n) {
		assert false;
	}

	@Override
	public void visit(ClosureCall_c c) {
		assert false;
	}

	@Override
	public void visit(X10CanonicalTypeNode_c n) {
		assert false;
	}

	@Override
	public void visit(X10Unary_c n) {
		assert false;
	}

	@Override
	public void visit(Unary_c n) {
		assert false;
	}

	@Override
	public void visit(X10Binary_c n) {
		assert false;
	}

	@Override
	public void visit(Binary_c n) {
		String opString = n.operator().toString();

		// Boolean short-circuiting operators are ok
		assert (opString.equals("&&") || opString.equals("||")) : "visiting " + n.getClass() + " at " + n.position() + ": " + n;
		
		visitAppropriate(n.left());
		visitAppropriate(n.right());
	}

	@Override
	public void visit(ArrayInit_c n) {
		throw new InternalCompilerError("Should not be invoked");
	}

	@Override
	public void visit(SettableAssign_c n) {
		assert (false) : ("Function assign should have been desugared earlier");
	}

	@Override
	public void visit(Tuple_c c) {
		assert false;
	}

	@Override
	public void visit(When_c n) {
		assert (false) : ("When should have been desugared earlier");
	}

	@Override
	public void visit(Future_c n) {
		assert (false) : ("Future should have been desugared earlier");
	}

	@Override
	public void visit(AtStmt_c n) {
		assert (false) : ("At statements are deprecated");
	}

	@Override
	public void visit(AtExpr_c n) {
		assert (false) : ("At expression should have been desugared earlier");
	}
}
