package x10firm.visit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

import polyglot.ast.ArrayAccess_c;
import polyglot.ast.ArrayInit_c;
import polyglot.ast.Assert_c;
import polyglot.ast.Assign_c;
import polyglot.ast.Binary_c;
import polyglot.ast.Block_c;
import polyglot.ast.BooleanLit_c;
import polyglot.ast.Branch;
import polyglot.ast.Branch_c;
import polyglot.ast.CanonicalTypeNode;
import polyglot.ast.Case;
import polyglot.ast.Case_c;
import polyglot.ast.Catch_c;
import polyglot.ast.CharLit_c;
import polyglot.ast.ClassBody;
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
import polyglot.ast.ForInit;
import polyglot.ast.ForUpdate;
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
import polyglot.ast.Return;
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
import polyglot.ast.TypeNode;
import polyglot.ast.Unary_c;
import polyglot.ast.While_c;
import polyglot.frontend.Compiler;
import polyglot.types.ConstructorInstance;
import polyglot.types.Context;
import polyglot.types.FieldInstance;
import polyglot.types.Flags;
import polyglot.types.LocalInstance;
import polyglot.types.Name;
import polyglot.types.Type;
import polyglot.types.Types;
import polyglot.util.InternalCompilerError;
import polyglot.util.Position;
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
import x10.ast.X10CanonicalTypeNode;
import x10.ast.X10CanonicalTypeNode_c;
import x10.ast.X10Cast_c;
import x10.ast.X10ClassDecl;
import x10.ast.X10ClassDecl_c;
import x10.ast.X10ConstructorCall_c;
import x10.ast.X10Instanceof_c;
import x10.ast.X10MethodDecl;
import x10.ast.X10NodeFactory_c;
import x10.ast.X10SourceFile_c;
import x10.ast.X10Special_c;
import x10.ast.X10Unary_c;
import x10.types.MethodInstance;
import x10.types.ParameterType;
import x10.types.TypeParamSubst;
import x10.types.X10ClassDef;
import x10.types.X10ClassType;
import x10.types.X10ConstructorDef;
import x10.types.X10ConstructorInstance;
import x10.types.X10Def;
import x10.types.X10FieldInstance;
import x10.types.X10MethodDef;
import x10.types.checker.Converter;
import x10.types.checker.Converter.ConversionType;
import x10.visit.X10DelegatingVisitor;
import x10firm.CompilerOptions;
import x10firm.types.FirmTypeSystem;
import x10firm.types.GenericTypeSystem;
import x10firm.types.ParameterTypeMapping;
import x10firm.visit.FirmCodeTemplate.CondTemplate;
import x10firm.visit.FirmCodeTemplate.ExprTemplate;
import x10firm.visit.FirmCodeTemplate.StmtTemplate;
import x10firm.visit.x10lib.X10NativeGenericSupport;

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
import firm.PointerType;
import firm.Program;
import firm.Relation;
import firm.TargetValue;
import firm.bindings.binding_ircons.ir_linkage;
import firm.bindings.binding_ircons.ir_where_alloc;
import firm.bindings.binding_irprog.ir_segment_t;
import firm.bindings.binding_typerep.ir_type_state;
import firm.bindings.binding_typerep.ir_visibility;
import firm.nodes.Alloc;
import firm.nodes.Block;
import firm.nodes.Call;
import firm.nodes.Cond;
import firm.nodes.CopyB;
import firm.nodes.Load;
import firm.nodes.Node;
import firm.nodes.OOConstruction;
import firm.nodes.Store;

/**
 * creates a firm-program (a collection of firm-graphs) from an X10-AST.
 */
public class X10FirmCodeGenerator extends X10DelegatingVisitor {
	/** names of builtin functions */
	private static final String X10_STRING_LITERAL = "x10_string_literal";
	private static final String X10_THROW_STUB     = "x10_throw_stub";
	private static final String X10_ASSERT         = "x10_assert";
	private static final String X10_STATIC_INITIALIZER = "x10_static_initializer";
	
	private static final X10NativeGenericSupport gen_support = new X10NativeGenericSupport();
	
	/** The current firm construction object */
	OOConstruction con;

	/** To return Firm nodes for constructing expressions */
	private Node returnNode;

	/** X10 Context */
	private Context x10Context = null;

	/** Our firm type system */
	final FirmTypeSystem firmTypeSystem;

	/** The X10 type system */
	final GenericTypeSystem x10TypeSystem;

	/** Our node factory */
	final X10NodeFactory_c xnf;

	/** Our own AST query */
	private final X10ASTQuery query;

	/** current firm context */
	private X10FirmContext firmContext = new X10FirmContext();

	/** Command-line options */
	private CompilerOptions options;
	
	/** firm code templates */
	private FirmCodeTemplate fct = new FirmCodeTemplate();
	
	/** holds all static initializer blocks */
	private static List<polyglot.ast.Initializer> static_init_blocks = new LinkedList<polyglot.ast.Initializer>();

	/**
	 * Constructor for creating a new X10FirmCodeGenerator
	 *
	 * @param compiler The main compiler
	 * @param firmTypeSystem The FIRM type system
	 * @param x10TypeSystem The X10 type system
	 */
	public X10FirmCodeGenerator(final Compiler compiler,
			final FirmTypeSystem firmTypeSystem,
			final GenericTypeSystem x10TypeSystem,
			final X10NodeFactory_c nodeFactory,
			final CompilerOptions options) {

		this.firmTypeSystem = firmTypeSystem;
		this.x10TypeSystem  = x10TypeSystem;
		this.xnf            = nodeFactory;
		this.query          = new X10ASTQuery(x10TypeSystem);
		this.x10Context     = new Context(x10TypeSystem);
		this.options        = options;
	}
	
	/** Do all post compile tasks */
	public void genPostCompile() {
		genGenericCode();
		genStaticInitializationSupportCode();
	}

	/** Generate the static initialization constructor */
	private void genStaticInitializationSupportCode() {
		// get the "constructor" segment and then put the static initialization code in the "constructor" segment. 
		ClassType con_segment = Program.getSegmentType(ir_segment_t.IR_SEGMENT_CONSTRUCTORS.val);
		
		final firm.Type[] parameterTypes = new firm.Type[0];
		final firm.Type[] resultTypes = new firm.Type[0];
		
		firm.Type method_type  		= new MethodType(parameterTypes, resultTypes);
		Entity method_entity 		= new Entity(Program.getGlobalType(), X10_STATIC_INITIALIZER, method_type);
		firm.Type ptr_method_type 	= new PointerType(method_type);
		
		Entity con_entity = new Entity(con_segment, "$ctor", ptr_method_type);
		final Graph graph = Program.getConstCodeGraph();
		final Node val = graph.newSymConst(method_entity);
		
		con_entity.setLdIdent(X10_STATIC_INITIALIZER);
		con_entity.setCompilerGenerated(true);
		con_entity.setVisibility(ir_visibility.ir_visibility_private);
		con_entity.setLinkage(ir_linkage.IR_LINKAGE_HIDDEN_USER.val | ir_linkage.IR_LINKAGE_CONSTANT.val);
		con_entity.setAtomicValue(val);
		
		OOConstruction savedConstruction = initConstruction(method_entity,  Collections.<LocalInstance>emptyList(), 
				Collections.<LocalInstance>emptyList(), Flags.STATIC, x10TypeSystem.Void(), null);
		
		for(polyglot.ast.Initializer n : static_init_blocks)
			visitAppropriate(n.body());
		
		finishConstruction(method_entity, savedConstruction);
	}
	
	// This queue holds a list of nodes (either MethodDecls or ClassDecls)
	// and their corresponding mapping of parameter types.
	private static Queue<GenericNodeInstance> workList = new LinkedList<GenericNodeInstance>();

	private void addToWorklist(GenericNodeInstance other) {
		// Check for duplicates.
		for (GenericNodeInstance gi : workList)
			if (gi.equals(other))
				return;

		workList.add(other);
	}
	
	private void genGenericCode() {
		
		while (!workList.isEmpty()) {
			final GenericNodeInstance head = workList.peek();
			final ParameterTypeMapping ptm = head.getMapping();

			firmTypeSystem.pushTypeMapping(ptm);
			visitAppropriate(head.getNode());
			firmTypeSystem.popTypeMapping(ptm);
			
			workList.poll();
		}
		
	}
	
	/**
	 * Evaluates a given expression and creates the appropriate firm nodes
	 * @param e The expression
	 * @param trueBlock The true block
	 * @param falseBlock The false block
	 */
	void evaluateCondition(final Expr e, final Block trueBlock, final Block falseBlock) {
		ConditionEvaluationCodeGenerator codegen
			= new ConditionEvaluationCodeGenerator(trueBlock, falseBlock, this, x10TypeSystem, firmTypeSystem);
		codegen.visitAppropriate(e);
	}

	private Node produceBooleanValue(final Expr e) {
	    final Block cur    = con.getCurrentBlock();
		final Block bTrue  = con.newBlock();
		final Block bFalse = con.newBlock();
		final Mode  mode   = firmTypeSystem.getFirmMode(e.type());

		con.setCurrentBlock(bTrue);
		final Node jmp1 = con.newJmp();
		final Node one  = con.newConst(mode.getOne());

		con.setCurrentBlock(bFalse);
		final Node jmp2 = con.newJmp();
		final Node zero = con.newConst(mode.getNull());

		con.setCurrentBlock(cur);
		evaluateCondition(e, bTrue, bFalse);
		bTrue.mature();
		bFalse.mature();

		final Block phiBlock = con.newBlock();
		phiBlock.addPred(jmp1);
		phiBlock.addPred(jmp2);
		phiBlock.mature();

		con.setCurrentBlock(phiBlock);
		return con.newPhi(new Node[]{one, zero}, mode);
	}

	/**
	 * Calculates a unique mapping between local instances and firm entities.
	 * @param locals A list with local instances
	 * @return The unique mapping between local instances and firm entities.
	 */
	private Map<LocalInstance, Entity> calculateEntityMappingForLocals(final List<LocalInstance> locals) {
		Map<LocalInstance, Entity> map = new HashMap<LocalInstance, Entity>();
		final firm.Type frameType = con.getGraph().getFrameType();
		for (LocalInstance loc : locals) {
			if (needEntityForLocalInstance(loc) && !map.containsKey(loc)) {
				final Entity ent = new Entity(frameType, loc.name().toString(), firmTypeSystem.asFirmCoreType(loc.type()));
				map.put(loc, ent);
			}
		}
		return map;
	}

	/**
	 * Checks if a given local instanced needs an explicit entity
	 * @param type The type which should be checked
	 * @return True if the given type needs an entity
	 */
	private boolean needEntityForLocalInstance(final LocalInstance loc) {
		return firmTypeSystem.isFirmStructType(loc.type());
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

	private static final class GenericNodeInstance {
		private final polyglot.ast.Node node;
		private final ParameterTypeMapping mapping;

		public GenericNodeInstance(final polyglot.ast.Node node, final ParameterTypeMapping mapping) {
			this.node = node;
			this.mapping = mapping;
		}

		public polyglot.ast.Node getNode() {
			return node;
		}

		public ParameterTypeMapping getMapping() {
			return mapping;
		}

		private X10Def getDef() {
			if (node instanceof X10ClassDecl)
				return ((X10ClassDecl) node).classDef();
			else if (node instanceof X10MethodDecl)
				return ((X10MethodDecl) node).methodDef();

			assert (false);
			return null;
		}

		// TODO:  Obviously, this will create collisions for different
		//        instances of the same generic method/class.
		//        Think of a better hashing approach.
		@Override
		public int hashCode() {
			return node.hashCode();
		}

		@Override
		public boolean equals(Object other) {
			if (other.getClass() != this.getClass())
				return false;

			final GenericNodeInstance rhs = (GenericNodeInstance) other;
			return getDef() == rhs.getDef() && mapping.equals(rhs.mapping);
		}

		@Override
		public String toString() {
			return node.toString() + " WITH " + mapping.toString();
		}
	}

	private void visit(X10SourceFile_c sourceFile) {
		for (TopLevelDecl topLevelDeclaration : sourceFile.decls()) {
			if (topLevelDeclaration instanceof X10ClassDecl) {
				final X10ClassDecl decl = (X10ClassDecl) topLevelDeclaration;
				if (decl.typeParameters().isEmpty())
					visit(decl);
			}
		}
	}

	@Override
	public void visit(X10ClassDecl_c n) {
		final X10ClassDef def = n.classDef();
		
		final X10ClassType classType = def.asType();

		final X10FirmContext newFirmContext = new X10FirmContext();
		firmContext = firmContext.pushFirmContext(newFirmContext);
		
		if(classType.isX10Struct()) {
			visitStruct(n);
		} else if (classType.isClass() || classType.flags().isInterface()) {
			visitClass(n);
		} else {
			assert(false) : "Unknown class declaration";
		}

		firmContext = firmContext.popFirmContext();
	}

	private void createStructTypeNameMethodBody(final X10ClassDecl clazz, final X10MethodDecl meth) {
		X10MethodDef def = meth.methodDef();
		final MethodInstance methInstance = def.asInstance();
		final Position pos = Position.COMPILER_GENERATED;

		// remove the native flag
		def.setFlags(def.flags().clearNative());

        List<Stmt> statements = new ArrayList<Stmt>();

        // generate -> return "[packageName].ClassName";
        final Expr str = xnf.StringLit(pos, clazz.classDef().fullName().toString()).type(x10TypeSystem.String());
        final Return ret = xnf.X10Return(pos, str, false);
        statements.add(ret);

        final polyglot.ast.Block block = xnf.Block(pos, statements);

        final Entity entity = firmTypeSystem.getMethodEntity(methInstance);

        final OOConstruction savedConstruction = initConstruction(entity, methInstance.formalNames(),
        		new LinkedList<LocalInstance>(),
				def.flags(), methInstance.returnType(), clazz.classDef().asType());

        // Now generate the firm graph
        visitAppropriate(block);

        finishConstruction(entity, savedConstruction);
	}

	private void visitStruct(X10ClassDecl n) {

		final ClassBody body = n.body();
		final List<ClassMember> members = body.members();
		if(!members.isEmpty()) {
			final List<ClassMember> inits = query.extractInits(members);
			firmContext.setInitClassMembers(inits);

			for(ClassMember member : body.members()) {
				if(member instanceof MethodDecl_c) {
					final X10MethodDecl md = (X10MethodDecl)member;
					final X10MethodDef def = md.methodDef();
					final MethodInstance methodInstance = def.asInstance();
					final String name = methodInstance.name().toString();

					// Special case for typeName method -> must be created manually
					if(name.equals("typeName") && def.formalNames().size() == 0) {
						createStructTypeNameMethodBody(n, md);
						continue;
					}
					
					// don`t visit generic method declarations yet, because we don`t know the concrete type parameters. 
					// See X10Call_c
					if(md.typeParameters().isEmpty()) {
						visitAppropriate(member);
					}
				} else {
					visitAppropriate(member);
				}
			}
		}
	}

	private void visitClass(X10ClassDecl n) {
		final ClassBody body = n.body();
		final List<ClassMember> members = body.members();
		if(!members.isEmpty()) {
			final List<ClassMember> inits = query.extractInits(members);
			firmContext.setInitClassMembers(inits);

			for (ClassMember member : body.members()) {
				if (member instanceof X10MethodDecl) {
					final X10MethodDecl md = (X10MethodDecl) member;
					if (md.typeParameters().isEmpty()) {
						visitAppropriate(member);
					}
				} else {
					visitAppropriate(member);
				}
			}
		}
	}

	/** Finds all locals in the given method.
	 *  @param code    method/constructor code
	 *  @param locals  Will hold all found locals.
	 */
	private List<LocalInstance> getAllLocalInstancesInCodeBlock(CodeBlock code) {
		List<LocalInstance> ret = new LinkedList<LocalInstance>();

		if (code.body() == null)
			return ret;

		final X10LocalDeclVisitor xLocalsVisitor = new X10LocalDeclVisitor();
		xLocalsVisitor.visit(code.body());

		final List<LocalDecl_c> matchesList = xLocalsVisitor.getLocals();

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
	 * @param entity The method entities for which the a new construction should be initialized
	 * @param formals The formals of the given method entity
	 * @param locals The locals of the given method entity
	 * 
	 * @param owner The owner of the procedure
	 * @return A reference to the current (saved) construction
	 */
	public OOConstruction initConstruction(final Entity entity, final List<LocalInstance> formals,
			final List<LocalInstance> locals, final Flags flags, final Type retType, final X10ClassType owner) {
		
		final boolean isStatic = flags.isStatic();
		final int nVars = formals.size() + locals.size() + (isStatic ? 0 : 1);

		final Graph graph = new Graph(entity, nVars);
		final OOConstruction savedConstruction = con;
		con = new OOConstruction(graph);

		X10FirmContext newFirmContext = new X10FirmContext();

		final Map<LocalInstance, Entity> map = calculateEntityMappingForLocals(locals);

		newFirmContext.setReturnType(retType);

		firmContext = firmContext.pushFirmContext(newFirmContext);

		final Node args = graph.getArgs();
		if(!isStatic) {
			assert(owner != null);
			final firm.Type ownerFirm = firmTypeSystem.asFirmType(owner);

			/* map 'this' */
			final Node projThis = con.newProj(args, ownerFirm.getMode(), 0);
			con.setVariable(0, projThis);
		}

		int idx = isStatic ? 0 : 1;

		// init and map all parameters.
		for (final LocalInstance loc : formals) {
			final Type type = loc.type();

			if (firmTypeSystem.isFirmStructType(type)) {
				final MethodType methodType = (MethodType)entity.getType();
				final Entity paramEntity = methodType.getValueParamEnt(idx);
				final Node node = getEntityFromCurrentFrame(paramEntity);
				con.setVariable(idx, node);
			} else {
				final Mode mode = firmTypeSystem.getFirmMode(loc.type());
				final Node projParam = con.newProj(args, mode, idx);
				con.setVariable(idx, projParam);
			}

			// map the local instance with the appropriate idx.
			firmContext.setVarEntry(X10VarEntry.newVarEntryForLocalVariable(loc, idx));
			idx++;
		}

		// map all local variables.
		for (final LocalInstance loc : locals) {
			// map the local instance with the appropriate idx.
			final Entity ent = map.get(loc);
			if(ent != null) {
				// a local struct
				firmContext.setVarEntry(X10VarEntry.newVarEntryForStructVariable(loc, ent));
			} else {
				// a normal local variable
				firmContext.setVarEntry(X10VarEntry.newVarEntryForLocalVariable(loc, idx));
				idx++;
			}
		}

		return savedConstruction;
	}

	/**
	 * Finishes a construction
	 * @param entity The method entity for which the construction should be finished
	 * @param savedConstruction A reference to the previous construction
	 */
	public void finishConstruction(Entity entity, OOConstruction savedConstruction) {
		// create Return node if there was no explicit return statement yet
		if (!con.getCurrentBlock().isBad()) {
			final MethodType meth = (MethodType)entity.getType();
			if(meth.getNRess() == 0) {
				Node mem = con.getCurrentMem();
				Node ret = con.newReturn(mem, new Node[0]);
				con.getGraph().getEndBlock().addPred(ret);
			}
		}

		con.finish();

		con = savedConstruction;

		firmContext = firmContext.popFirmContext();
	}

	private void constructGraph(final Entity entity, final CodeBlock code, final List<LocalInstance> formals,
			final List<LocalInstance> locals, final Flags flags, final Type retType, final X10ClassType owner) {

		final OOConstruction savedConstruction = initConstruction(entity, formals, locals, flags, retType, owner);

		// Walk body and construct graph
		visitAppropriate(code.body());

		finishConstruction(entity, savedConstruction);
	}

	private TypeParamSubst buildSubst() {
		final Map<ParameterType, Type> mapping = x10TypeSystem.getMapping();
		final List<Type> actualTypes = new ArrayList<Type>(mapping.values());
		final List<ParameterType> paramTypes = new ArrayList<ParameterType>(mapping.keySet());

		return new TypeParamSubst(x10TypeSystem, actualTypes, paramTypes);
	}

	@Override
	public void visit(MethodDecl_c dec) {
		final X10MethodDef def = (X10MethodDef) dec.methodDef();
		final MethodInstance defInstance = def.asInstance();

		boolean hasTypeParameters = !def.typeParameters().isEmpty();
		MethodInstance methodInstance;
		if (!hasTypeParameters)
			methodInstance = defInstance;
		else {
			// If we compile a generic method, asInstance() will give
			// us a method instance where generic types are used.  But we know
			// better at this point, because we can substitute the real types.
			final TypeParamSubst subst = buildSubst();
			methodInstance = subst.reinstantiate(def.asInstance());

			// Substitute type parameters manually.  Why doesn't X10 do this?!
			final List<Type> typeArguments = new ArrayList<Type>();
			for (ParameterType paramType : def.typeParameters())
				typeArguments.add(x10TypeSystem.getConcreteType(paramType));

			methodInstance = (MethodInstance) methodInstance.typeParameters(typeArguments);
		}

		final Flags flags = methodInstance.flags();
		final List<LocalInstance> formals = defInstance.formalNames();
		final Entity entity = firmTypeSystem.getMethodEntity(methodInstance);
		final X10ClassType owner = (X10ClassType) methodInstance.container();
		
		if (flags.isNative() || flags.isAbstract()) {
			if(flags.isNative() && hasTypeParameters) {
				boolean dispatch_ok = gen_support.dispatch(this, methodInstance, formals);
				assert(dispatch_ok);
			}
			// native code is defined elsewhere, so nothing left to do
			return;
		}

		// extract all formals and locals from the method.
		final List<LocalInstance> locals = getAllLocalInstancesInCodeBlock(dec);
		constructGraph(entity, dec, formals, locals, flags, defInstance.returnType(), owner);

		if (query.isMainMethod(def)) {
			processMainMethod(entity);
		}
	}

	private void processMainMethod(Entity mainEntity) {
		/* let's create a simple "main" function which just calls the other main */
		final firm.Type global = Program.getGlobalType();
		/* let's hope the X10 int type is compatible to the C int-type */
		final firm.Type intType = firmTypeSystem.asFirmType(x10TypeSystem.Int());
		final firm.Type[] returnTypes = new firm.Type[] { intType };
		final firm.Type[] parameterTypes = new firm.Type[] {};
		final MethodType mainType = new MethodType(parameterTypes, returnTypes);
		final Entity entity = new Entity(global, "main", mainType);
		String ldIdent = "main";
		if (Platform.isMac() || Platform.isWindows()) {
			ldIdent = "_" + ldIdent;
		}

		entity.setLdIdent(ldIdent);
		entity.setVisibility(ir_visibility.ir_visibility_default);
		entity.addLinkage(ir_linkage.IR_LINKAGE_HIDDEN_USER.val);

		final Graph graph = new Graph(entity, 0);
		final Construction construction = new OOConstruction(graph);
		final Node symConst = construction.newSymConst(mainEntity);
		final Node mem = construction.getCurrentMem();
		final firm.Type type = mainEntity.getType();
		final firm.Type paramType = ((MethodType) type).getParamType(0);
		/* TODO: convert the arguments passed to the Array[String] */
		final Node args = construction.newConst(paramType.getMode().getNull());
		final Node call = construction.newCall(mem, symConst, new Node[] { args }, type);
		final Node newMem = construction.newProj(call, Mode.getM(), Call.pnM);
		construction.setCurrentMem(newMem);

		final Node returnMem = construction.getCurrentMem();
		final Node zero = construction.newConst(intType.getMode().getNull());
		final Node returnn = construction.newReturn(returnMem, new Node[] {zero});
		construction.getGraph().getEndBlock().addPred(returnn);
		construction.setCurrentBlockBad();

		construction.finish();
		Program.setMainGraph(graph);
	}

	@Override
	public void visit(ConstructorDecl_c dec) {
		final X10ConstructorDef      def      = (X10ConstructorDef) dec.constructorDef();
		final Flags                  flags    = def.flags();
		final X10ConstructorInstance instance = (X10ConstructorInstance) def.asInstance();
		final Entity                 entity   = firmTypeSystem.getConstructorEntity(instance);

		if (flags.isNative()) {
			/* native code is defined elsewhere, so nothing left to do */
			return;
		}

		final List<LocalInstance> formals = instance.formalNames();
		final X10ClassType owner = (X10ClassType) instance.container();

		// extract all formals and locals from the method.
		final List<LocalInstance> locals = getAllLocalInstancesInCodeBlock(dec);
		final List<ClassMember> initClassMembers = firmContext.getInitClassMembers();

		final OOConstruction savedConstruction = initConstruction(entity, formals, locals, flags, instance.returnType(), owner);

		// The instance variables must be initialized first
		for(ClassMember member : initClassMembers) {
			if(member instanceof FieldDecl_c) {
				final FieldDecl_c fieldDecl = (FieldDecl_c)member;
				assert(fieldDecl.init() != null);

				final Flags fieldFlags = fieldDecl.flags().flags();
				assert(!fieldFlags.isStatic());

				final FieldInstance fieldInst = fieldDecl.fieldDef().asInstance();
				final Node objectPointer = getThis(Mode.getP());
				final Node expr = visitExpression(fieldDecl.init());
				genFieldAssign(objectPointer, fieldInst, expr);
			} else {
				assert(false): "Illegal class member";
			}
		}

		visitAppropriate(dec.body());

		finishConstruction(entity, savedConstruction);
	}

	/**
	 * Creates a target value for a given constant expr
	 * @param expr The constant expr
	 * @return The target value of the given constant expr
	 */
	private TargetValue constantToTargetValue(Expr expr) {
		assert(expr != null && expr.isConstant());

		final Object obj = expr.constantValue();

		TargetValue targetValue = null;

		// all unsigned types can`t be evaluated at compile time, because they use an "implicit operator as"
		// to convert the datatype to long, integer etc.

		if(obj instanceof Integer || obj instanceof Long || obj instanceof Byte || obj instanceof Short) {
			final Mode mode;
			long value;
			if(obj instanceof Integer) {
				mode = firmTypeSystem.getFirmMode(x10TypeSystem.Int());
				value = ((Integer)obj).longValue();
			} else if(obj instanceof Long) {
				mode = firmTypeSystem.getFirmMode(x10TypeSystem.Long());
				value = ((Long)obj).longValue();
			} else if(obj instanceof Byte) {
				mode = firmTypeSystem.getFirmMode(x10TypeSystem.Byte());
				value = ((Byte)obj).longValue();
			} else { // SHORT
				mode = firmTypeSystem.getFirmMode(x10TypeSystem.Short());
				value = ((Short)obj).longValue();
			}
			targetValue = new TargetValue(value, mode);
		} else if(obj instanceof Float || obj instanceof Double) {
			final Mode mode;
			double value;
			if(obj instanceof Float) {
				mode = firmTypeSystem.getFirmMode(x10TypeSystem.Float());
				value = ((Float)obj).doubleValue();
			} else {
				mode = firmTypeSystem.getFirmMode(x10TypeSystem.Double());
				value = ((Double)obj).doubleValue();
			}
			targetValue = new TargetValue(value, mode);
		} else if(obj instanceof Boolean) {
			final Mode mode = firmTypeSystem.getFirmMode(x10TypeSystem.Boolean());
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
		final TargetValue targetValue = constantToTargetValue(expr);
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

	private Node getFieldAddress(final Node objectPointer, final FieldInstance instance) {
		final FieldInstance def = instance.def().asInstance();
		final Flags flags = def.flags();
		/* make sure enclosing class-type has been created */
		firmTypeSystem.asFirmType(instance.container());
		final Entity entity = firmTypeSystem.getEntityForField(instance);
		Node address = null;
		if (flags.isStatic()) {
			address = con.newSymConst(entity);
		} else {
			assert(objectPointer != null);
			address = con.newSel(objectPointer, entity);
		}

		return address;
	}

	private Node genFieldLoad(final Node objectPointer, final FieldInstance fInst) {
		final Node fieldPointer = getFieldAddress(objectPointer, fInst);
		return genFieldLoadHelp(fieldPointer, fInst);
	}

	private Node genFieldLoadHelp(final Node fieldPointer, final FieldInstance fInst) {
		if (firmTypeSystem.isFirmStructType(fInst.type())) // structs
			return fieldPointer;

		final firm.Type type = firmTypeSystem.asFirmType(fInst.type());
		final Node mem = con.getCurrentMem();
		final Mode loadMode = type.getMode();
		final Node load = con.newLoad(mem, fieldPointer, loadMode);
		final Node newMem = con.newProj(load, Mode.getM(), Load.pnM);
		final Node result = con.newProj(load, loadMode, Load.pnRes);
		con.setCurrentMem(newMem);

		return result;
	}

	private Node genStaticFieldLoad(final FieldInstance instance) {
		return genFieldLoad(null, instance);
	}
	
	private Node genFieldAssign(final Field_c field, final Expr expr) {
		final FieldInstance instance = field.fieldInstance().def().asInstance();
		Node objectNode = null;
		if(field.target() instanceof Expr)
			objectNode = visitExpression((Expr)field.target());
		final Node rightRet = visitExpression(expr);
		final Node ret = genFieldAssign(objectNode, instance, rightRet);
		return ret;
	}

	private Node genFieldAssign(final Node objectPointer, final FieldInstance fInst, final Node rightRet) {
		final Node address = getFieldAddress(objectPointer, fInst);

		if (firmTypeSystem.isFirmStructType(fInst.type())) {
			final Entity ent = firmTypeSystem.getEntityForField(fInst);
			final Node mem = con.getCurrentMem();
			final Node copyB = con.newCopyB(mem, address, rightRet, ent.getType());
			final Node curMem = con.newProj(copyB, Mode.getM(), CopyB.pnM);
			con.setCurrentMem(curMem);
		} else {
			final firm.Type type = firmTypeSystem.asFirmType(fInst.type());
			assert rightRet.getMode().equals(type.getMode());
			final Node mem = con.getCurrentMem();
			final Node store = con.newStore(mem, address, rightRet);
			final Node newMem = con.newProj(store, Mode.getM(), Store.pnM);
			con.setCurrentMem(newMem);
		}

		return rightRet;
	}

	@Override
	public void visit(FieldDecl_c dec) {
		final Flags flags = dec.flags().flags();

		/* make sure enclosing class type has been created */
		final FieldInstance instance = dec.fieldDef().asInstance();
		firmTypeSystem.asFirmType(instance.container());

		/* static fields may have initializers */
		if (flags.isStatic()) {
			final Expr init = dec.init();
			// Check for in place initializer
			if (init != null && query.isGlobalInit(dec)) {
				final Initializer initializer = expr2Initializer(init);
				final Entity entity = firmTypeSystem.getEntityForField(dec.fieldDef().asInstance());
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

		final X10FirmScope topScope = firmContext.getTopScope();
		X10FirmScope newScope = (X10FirmScope)topScope.clone();

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
			final Node jmp = con.newJmp();
			if(bBreak == null)
				bBreak = con.newBlock();

			bBreak.addPred(jmp);
		}

		if(!hasExplicitDefaultCase && !curBlock.isBad()) {
			con.setCurrentBlock(curBlock);
			final Node proj = con.newProj(switchCond, Mode.getX(), (int)defNr);	// TODO: Adjust the defNr (Long)

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
		final Node fallthrough 	= con.getCurrentBlock().isBad() ? null : con.newJmp();
		final Block block 		= con.newBlock();

		final X10FirmScope topScope = firmContext.getTopScope();
		final Node switchCond       = topScope.getCurSwitchCond();
		final Block switchCondBlock = (Block)switchCond.getBlock();

		con.setCurrentBlock(switchCondBlock);
		if(!n.isDefault()) {
			// Case label
			final long val = n.value();
			final Node proj = con.newProj(switchCond, Mode.getX(), (int)val); // TODO: Adjust the val (Long)
			block.addPred(proj);
		} else {
			// default label
			final long projNr = topScope.getCurSwitchDefaultProjNr();
			final Node proj = con.newProj(switchCond, Mode.getX(), (int)projNr); // TODO: Adjust the projNr (Long)
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

		final X10FirmScope topScope = firmContext.getTopScope();
		Block target = null;
		if (br.labelNode() != null) {
			// labeled continue or break
			final String label = br.labelNode().id().toString();

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

		final Node jmp = con.newJmp();
		target.addPred(jmp);

		con.setCurrentBlockBad();
	}

	@Override
	public void visit(Labeled_c label) {

		final Stmt stmt 	= label.statement();
		final String lab 	= label.labelNode().id().toString();

		// Mark the corresponding statement with the appropriate label
		firmContext.setLabeledStmt(lab, stmt);

		// Declare the label in the current firm scope
		final X10FirmScope topScope = firmContext.getTopScope();
		X10FirmScope newScope = (X10FirmScope)topScope.clone();

		firmContext.pushFirmScope(newScope);
		{
			newScope.declFirmLabel(lab);
			visitAppropriate(stmt);
		}
		firmContext.popFirmScope();
	}

	@Override
	public void visit(Assign_c asgn) {
		final Expr lhs = asgn.left();

		// autoboxing
		final Expr rhs = x10Cast(asgn.right(), lhs.type());

		if(lhs instanceof Local_c) { // Assignment to a local variable -> Assignments to saved variables are not allowed in closures. -> so we will not handle them.
			final Node leftRet  = visitExpression(lhs);
			final Node rightRet = visitExpression(rhs);

			final Local_c lhsLocal = (Local_c)lhs;
			final LocalInstance loc = lhsLocal.localInstance();

			final X10VarEntry var = firmContext.getVarEntry(loc);

			if(var.getType() == X10VarEntry.STRUCT) {
				// local struct variable
				final Entity entity = var.getEntity();
				final Node mem = con.getCurrentMem();
				final Node copyB = con.newCopyB(mem, leftRet, rightRet, entity.getType());
				final Node curMem = con.newProj(copyB, Mode.getM(), CopyB.pnM);
				con.setCurrentMem(curMem);
				setReturnNode(rightRet);
			} else {
				// local normal variable
				final int idx = var.getIdx();
				con.setVariable(idx, rightRet);
				setReturnNode(con.getVariable(idx, leftRet.getMode()));
			}
		} else if (lhs instanceof Field_c) {
			final Field_c field = (Field_c) lhs;
			final Node ret = genFieldAssign(field, rhs);
			setReturnNode(ret);
		} else {
			throw new RuntimeException("Unexpected assignment target");
		}
	}

	@Override
	public void visit(Return_c n) {
		Node ret = null;

		if(n.expr() != null) {
			final Type retType = firmContext.getReturnType();
			assert(retType != null);

			// autoboxing
			final Expr expr = x10Cast(n.expr(), retType);
			ret = visitExpression(expr);
		}

		final Node mem = con.getCurrentMem();
		final Node retNode = ret != null ? con.newReturn(mem, new Node[]{ret}) : con.newReturn(mem, new Node[]{});
		assert(retNode != null);

		/* for error detection */
		con.getGraph().getEndBlock().addPred(retNode);
		con.setCurrentBlockBad();
	}

	@Override
	public void visit(LocalDecl_c n) {
		final Expr expr = n.init();

		if (expr != null) {
			// autoboxing
			final Expr initExpr = x10Cast(expr, n.type().type());
			final LocalInstance loc = n.localDef().asInstance();

			final X10VarEntry var = firmContext.getVarEntry(loc);

			if(var.getType() == X10VarEntry.STRUCT) {

				final Entity entity = var.getEntity();
				final Node sel = getEntityFromCurrentFrame(entity);

				if(initExpr instanceof New_c) {
					// Optimization: initExpr is a constructor call
					// Do a direct constructor call without copying the return value of the constructor call */
					final New_c new_c = (New_c)initExpr;
					genNew(sel, new_c);
				} else {
					// Hmm not a "new" call -> we must copy the return node of the initExpr.
					final Node initNode = visitExpression(initExpr);
					final Node mem = con.getCurrentMem();
					final Node copyB = con.newCopyB(mem, sel, initNode, entity.getType());
					final Node curMem = con.newProj(copyB, Mode.getM(), CopyB.pnM);
					con.setCurrentMem(curMem);
				}
			} else {
				final Node initNode = visitExpression(initExpr);
				final int idx = var.getIdx();
				con.setVariable(idx, initNode);
			}
		}
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
		// visit the children
		for (Stmt stmt : n.statements())
			visitAppropriate(stmt);

		// evaluate the stmt expr
		final Expr e = n.result();
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

		final Block bTrue  = con.newBlock();
		final Block bCond  = con.newBlock();
		final Block bFalse = con.newBlock();

		bTrue.addPred(con.newJmp());
		con.setCurrentBlock(bTrue);

		final X10FirmScope topScope  = firmContext.getTopScope();
		X10FirmScope newScope  = (X10FirmScope)topScope.clone();

		firmContext.pushFirmScope(newScope);
		{
			newScope.setBreakBlock(bFalse);
			newScope.setContinueBlock(bCond);

			if(label != null) {
				newScope.setBlockForLabeledBreak(label, bFalse);
				newScope.setBlockForLabeledContinue(label, bCond);
			}

			final Stmt body = n.body();
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

		final X10FirmScope topScope2  = firmContext.getTopScope();
		newScope  = (X10FirmScope)topScope2.clone();

		evaluateCondition(n.cond(), bTrue, bFalse);

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

		final Block bCond  = con.newBlock();
		final Block bTrue  = con.newBlock();
		final Block bFalse = con.newBlock();

		bCond.addPred(con.newJmp());
		con.setCurrentBlock(bCond);

		final X10FirmScope topScope = firmContext.getTopScope();
		X10FirmScope newScope = (X10FirmScope)topScope.clone();

		evaluateCondition(n.cond(), bTrue, bFalse);
		bTrue.mature();

		con.setCurrentBlock(bTrue);

		final X10FirmScope topScope2 = firmContext.getTopScope();
		newScope = (X10FirmScope)topScope2.clone();

		firmContext.pushFirmScope(newScope);
		{
			newScope.setBreakBlock(bFalse);
			newScope.setContinueBlock(bCond);

			if(label != null) {
				newScope.setBlockForLabeledBreak(label, bFalse);
				newScope.setBlockForLabeledContinue(label, bCond);
			}

			final Stmt body = n.body();
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
	public void visit(For_c n) {
		// condition evaluates to false -> nothing to do
		// TODO: Something is wrong with the method condIsConstantTrue
//		if(!n.condIsConstantTrue())
//			return;

		String label = null;
		if(firmContext.getLabeledStmt() == n) {
			label = firmContext.getLabel();
			firmContext.resetLabeledStmt();
		}

		if(n.inits() != null) {
			for(ForInit f: n.inits())
				visitAppropriate(f);
		}

		final Block bCond  = con.newBlock();
		final Block bTrue  = con.newBlock();
		final Block bFalse = con.newBlock();

		bCond.addPred(con.newJmp());
		con.setCurrentBlock(bCond);

		final X10FirmScope topScope = firmContext.getTopScope();
		X10FirmScope newScope = (X10FirmScope)topScope.clone();

		Expr cond = n.cond();
		if(cond == null) {
			cond = xnf.BooleanLit(Position.COMPILER_GENERATED, true);
		}
		evaluateCondition(cond, bTrue, bFalse);
		bTrue.mature();

		con.setCurrentBlock(bTrue);

		final X10FirmScope topScope2 = firmContext.getTopScope();
		newScope = (X10FirmScope)topScope2.clone();

		firmContext.pushFirmScope(newScope);
		{
			newScope.setBreakBlock(bFalse);
			newScope.setContinueBlock(bCond);

			if(label != null) {
				newScope.setBlockForLabeledBreak(label, bFalse);
				newScope.setBlockForLabeledContinue(label, bCond);
			}

			final Stmt body = n.body();
			visitAppropriate(body);
		}
		firmContext.popFirmScope();

		bFalse.mature();

		if(n.iters() != null) {
			for(ForUpdate f: n.iters()) {
				visitAppropriate(f);
			}
		}

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
			boolean cond = (Boolean)n.cond().constantValue().toJavaObject();
			if(cond) {
				visitExpression(n.consequent());
				// return node is automatically set.
				return;
			}

			visitExpression(n.alternative());
			return;
		}
		
		final Conditional_c c = n;
		final CondTemplate cond = new CondTemplate() {
			@Override
			public void genCode(Block trueBlock, Block falseBlock) {
				evaluateCondition(c.cond(), trueBlock, falseBlock);
			}
		};
		
		final ExprTemplate trueExpr = new ExprTemplate() {
			@Override
			public Node genCode() {
				return visitExpression(c.consequent());
			}
		};
		
		final ExprTemplate falseExpr = new ExprTemplate() {
			@Override
			public Node genCode() {
				return visitExpression(c.alternative());
			}
		};
		
		final Node ret = fct.genConditional(con, cond, trueExpr, falseExpr);
		setReturnNode(ret);
	}

	@Override
	public void visit(If_c n) {
		
		final If_c ifAst = n;
		final CondTemplate cond = new CondTemplate() {
			@Override
			public void genCode(Block trueBlock, Block falseBlock) {
				evaluateCondition(ifAst.cond(), trueBlock, falseBlock);
			}
		};

		final StmtTemplate ifStmt = new StmtTemplate() {
			@Override
			public void genCode() {
				visitAppropriate(ifAst.consequent());
			}
		};
		
		StmtTemplate elseStmt = null;
		if(n.alternative() != null) {
			Stmt alternative = n.alternative();
			if (alternative instanceof Block_c) {
				Block_c block = (Block_c) alternative;
				if (block.statements().size() == 1 && block.statements().get(0) instanceof If_c)
					alternative = block.statements().get(0);
			}
			final Stmt elseBlock = alternative;
			elseStmt = new StmtTemplate() {
				@Override
				public void genCode() {
					visitAppropriate(elseBlock);
				}
			};
		}
		
		fct.genIfStatement(con, cond, ifStmt, elseStmt);
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

	private void addToMapping(final ParameterTypeMapping ptm, final List<ParameterType> paramTypes, final List<Type> actualTypes) {
		for (int i = 0; i < paramTypes.size(); ++i) {
			Type t = actualTypes.get(i);
			if (x10TypeSystem.isParameterType(t))
				t = x10TypeSystem.getConcreteType(Types.baseType(t));

			ptm.add(paramTypes.get(i), Types.stripConstraints(t));
		}
	}

	@Override
	public void visit(X10Call_c n) {
		final MethodInstance methodInstance = n.methodInstance();

		// If this is a call to a generic method, record the type arguments and remember to
		// generate code later.
		if (!methodInstance.typeParameters().isEmpty()) {
			// Find the method declaration.
			final MethodDeclFetcher fetcher = new MethodDeclFetcher(x10TypeSystem, xnf);
			final X10MethodDecl decl = fetcher.getDecl(n);

			// Construct type mapping.
			final List<ParameterType> paramTypes = ((X10MethodDef) methodInstance.def()).typeParameters();
			final List<Type> actualTypes = methodInstance.typeParameters();
			assert (actualTypes.size() == decl.typeParameters().size());

			ParameterTypeMapping ptm = new ParameterTypeMapping();
			addToMapping(ptm, paramTypes, actualTypes);

			X10ClassType ct = (X10ClassType) Types.stripConstraints(n.target().type());
			X10ClassDef def = ct.def();
			
			// If this is a generic method defined inside a generic class,
			// also save the type mapping for the generic class.
			// We do not have to remember to instantiate this class
			// with the given type argument here, because this must have already
			// happened before when someone created the object that we call the
			// method on.
			if (!def.typeParameters().isEmpty()) {
				final List<ParameterType> cParamTypes = def.typeParameters();
				final List<Type> cActualTypes = ct.typeArguments();

				addToMapping(ptm, cParamTypes, cActualTypes);
			}

			// Remember the parameter type configuration to generate code later.
			addToWorklist(new GenericNodeInstance(decl, ptm));
		} 
		final Node ret = genX10Call(methodInstance, n.arguments(), n.target());
		setReturnNode(ret);
	}

	@Override
	public void visit(X10ConstructorCall_c n) {
		/* TODO: check for this or super */

		/* determine called function */
		final X10ConstructorInstance instance = n.constructorInstance();
		final Entity entity = firmTypeSystem.getConstructorEntity(instance);
		final MethodType type = (MethodType) entity.getType();
		final Node address = con.newSymConst(entity);

		final int param_count = type.getNParams();
		final Node[] parameters = new Node[param_count];
		int p = 0;
		parameters[p++] = getThis(Mode.getP());

		final List<Expr> arguments = wrapArguments(instance.formalTypes(), n.arguments());

		for(Expr expr : arguments)
			parameters[p++] = visitExpression(expr);

		assert(p == param_count);

		final Node mem = con.getCurrentMem();
		final Node call = con.newCall(mem, address, parameters, type);
		final Node newMem = con.newProj(call, Mode.getM(), Call.pnM);

		con.setCurrentMem(newMem);
	}

	/**
	 * @param expr	an X10 expression node
	 * @return a Firm node containing the result value of the expression
	 */
	public Node visitExpression(Expr expr) {
		resetReturnNode();
		visitAppropriate(expr);
		return getReturnNode();
	}

	@Override
	public void visit(Field_c n) {
		final FieldInstance instance = n.fieldInstance();

		final Flags flags = instance.flags();
		
		if(flags.isStatic()) {
			final Node ret = genStaticFieldLoad(instance);
			setReturnNode(ret);
		} else {
			final Node objectPointer = visitExpression((Expr)n.target());
			final Node ret = genFieldLoad(objectPointer, instance);
			setReturnNode(ret);
		}
	}

	/**
	 * Returns the appropriate sel node from the current frame for a given entity
	 * @param entity The entity for which the sel node from the current frame should be returned
	 * @return The sel node for the given entity
	 */
	public Node getEntityFromCurrentFrame(final Entity entity) {
		final Node frame = con.getGraph().getFrame();
		final Node sel = con.newSel(frame, entity);
		return sel;
	}

	@Override
	public void visit(Local_c n) {
		final LocalInstance loc = n.localInstance();

		final X10VarEntry var = firmContext.getVarEntry(loc);
		
		assert(var != null);

		if(var.getType() == X10VarEntry.STRUCT) {
			final Node ret = getEntityFromCurrentFrame(var.getEntity());
			setReturnNode(ret);
		} else {
			final int idx = var.getIdx();
			final Node ret = con.getVariable(idx, firmTypeSystem.getFirmMode(loc.type()));
			setReturnNode(ret);
		}
	}

	/**
	 * Create the appropriate firm nodes for a heap allocation.
	 * @param x10ResType The x10 type of the object
	 *
	 * @return A proj node to the allocated memory.
	 */
	private Node genHeapAlloc(final Type x10Type) {
		final firm.Type refType  = firmTypeSystem.asFirmType(x10Type);
		final firm.Type coreType = firmTypeSystem.asFirmCoreType(x10Type);
		return genAlloc(refType, coreType, ir_where_alloc.heap_alloc);
	}

	/**
	 * Create the appropriate firm nodes for a stack allocation.
	 * @param x10ResType The x10 type of the object
	 *
	 * @return A proj node to the allocated memory.
	 */
	private Node genStackAlloc(final Type x10Type) {
		final firm.Type refType  = firmTypeSystem.asFirmType(x10Type);
		final firm.Type coreType = firmTypeSystem.asFirmCoreType(x10Type);
		return genAlloc(refType, coreType, ir_where_alloc.stack_alloc);
	}

	private Node genAlloc(final firm.Type refType, final firm.Type coreType, final ir_where_alloc where) {
		final Node mem = con.getCurrentMem();
		final Node count = con.newConst(1, Mode.getIu());
		final Node alloc = con.newAlloc(mem, count, coreType, where);
		final Node newMem = con.newProj(alloc, Mode.getM(), Alloc.pnM);
		final Node res = con.newProj(alloc, refType.getMode(), Alloc.pnRes);
		con.setCurrentMem(newMem);
		return res;
	}
	
	/**
	 * Generate the appropriate nodes for a constructor call
	 * @param objectThisNode The this pointer for the constructor call (implicit first parameter)
	 * @param instance The constructor instance
	 * @param args The arguments of the constructor call (without the implicit this pointer)
	 */
	private void genConstructorCall(final Node objectThisNode, 
			final X10ConstructorInstance instance, 
			final List<Expr> args) {
		assert (instance != null);
		
		/* invoke class constructor */
		final Entity entity = firmTypeSystem.getConstructorEntity(instance);
		final firm.MethodType entityType = (MethodType) entity.getType();
		final Node address = con.newSymConst(entity);

		final int paramCount = entityType.getNParams();
		final Node[] parameters = new Node[paramCount];

		final List<Expr> arguments = wrapArguments(instance.formalTypes(), args);

		int p = 0;
		parameters[p++] = objectThisNode; /* this argument */

		for (Expr arg : arguments)
			parameters[p++] = visitExpression(arg);

		assert args.size() + 1 == paramCount;

		final Node mem = con.getCurrentMem();
		final Node call = con.newCall(mem, address, parameters, entityType);
		final Node newMem = con.newProj(call, Mode.getM(), Call.pnM);

		con.setCurrentMem(newMem);
	}

	private Node genNativeConstructorCall(final X10ConstructorInstance instance, 
			final List<Expr> args) {
		assert (instance != null);

		final Entity entity = firmTypeSystem.getConstructorEntity(instance);
		final firm.MethodType entityType = (MethodType) entity.getType();
		final Node address = con.newSymConst(entity);

		final int paramCount = entityType.getNParams();
		// Native constructors do not have a this parameter.
		final Node[] parameters = new Node[paramCount];

		final List<Expr> arguments = wrapArguments(instance.formalTypes(), args);

		int p = 0;
		for (Expr arg : arguments)
			parameters[p++] = visitExpression(arg);

		assert args.size() == paramCount;

		final Node mem = con.getCurrentMem();
		final Node call = con.newCall(mem, address, parameters, entityType);
		final Node newMem = con.newProj(call, Mode.getM(), Call.pnM);
		con.setCurrentMem(newMem);

		assert (entityType.getNRess() == 1);
		final firm.Type retType = entityType.getResType(0);
		final Node allResults = con.newProj(call, Mode.getT(), Call.pnTResult);
		final Mode mode = retType.getMode();
		assert (mode != null);
		final Node ret = con.newProj(allResults, mode, 0);

		return ret;
	}
	
	/**
	 * Generate firm graph for a new call 
	 * @param objectThisNode The firm node of the "this" pointer. "null" if the "this" pointer was not allocated yet.
	 * 		  1.) var x: MyStruct = new MyStruct(); -> "x" will be used as the "this" pointer. 
	 * 		  2.) new MyStruct(); -> no preallocated "this" pointer -> create a new one.  
	 * @param n The "new" node
	 */
	private void genNew(final Node objectThisNode, final New_c n) {
		final Type base_type = Types.baseType(n.objectType().type());
		final X10ClassType type = (X10ClassType)base_type;
		
		final boolean hasTypeArguments = type.typeArguments() != null && !type.typeArguments().isEmpty();
			
		if (hasTypeArguments) {
			final ConstructorInstance ci = n.constructorInstance();

			// Find the class declaration.
			final ClassDeclFetcher fetcher = new ClassDeclFetcher(x10TypeSystem, xnf);
			final X10ClassDecl decl = fetcher.getDecl(n);

			// Construct type mapping.
			final X10ClassType ct = (X10ClassType) ci.container();
			final List<ParameterType> paramTypes = ct.def().typeParameters();
			final List<Type> actualTypes = ct.typeArguments();
			assert (actualTypes.size() == decl.typeParameters().size());
			final ParameterTypeMapping ptm = new ParameterTypeMapping();
			addToMapping(ptm, paramTypes, actualTypes);

			// Remember the parameter type configuration to generate code later.
			addToWorklist(new GenericNodeInstance(decl, ptm));
		}
		
		if (n.constructorInstance().container() == x10TypeSystem.String()) {
			assert(objectThisNode == null);
			final Node obj = genNativeConstructorCall(n.constructorInstance(), n.arguments());
			setReturnNode(obj);
		} else {
			Node objectNode = objectThisNode;
			if (objectNode == null) {
				if (x10TypeSystem.isStructType(n.type()))
					objectNode = genStackAlloc(type);
				else
					objectNode = genHeapAlloc(type);
			}
			assert (objectNode != null);

			genConstructorCall(objectNode, n.constructorInstance(), n.arguments());
			setReturnNode(objectNode);
		}
	}

	@Override
	public void visit(New_c n) {
		genNew(null, n);
	}

	private TargetValue getFloatLitTargetValue(FloatLit_c literal) {
		final Mode mode;

		final polyglot.ast.FloatLit.Kind kind = literal.kind();
		if (kind == FloatLit.FLOAT)
			mode = firmTypeSystem.getFirmMode(x10TypeSystem.Float());
		else if (kind == FloatLit.DOUBLE)
			mode = firmTypeSystem.getFirmMode(x10TypeSystem.Double());
		else
			throw new InternalCompilerError("Unrecognized FloatLit kind " + kind);

		final double value = literal.value();

		return new TargetValue(value, mode);
	}

	@Override
	public void visit(FloatLit_c literal) {
		final TargetValue targetValue = getFloatLitTargetValue(literal);
		final Node ret = con.newConst(targetValue);

		setReturnNode(ret);
	}

	private TargetValue getIntLitTarval(IntLit_c literal) {
		final Mode mode;

		final polyglot.ast.IntLit.Kind kind = literal.kind();
		if (literal.kind() == IntLit.INT) {
			mode = firmTypeSystem.getFirmMode(x10TypeSystem.Int());
		} else if (literal.kind() == IntLit.UINT) {
			mode = firmTypeSystem.getFirmMode(x10TypeSystem.UInt());
		} else if (literal.kind() == IntLit.LONG) {
			mode = firmTypeSystem.getFirmMode(x10TypeSystem.Long());
		} else if (kind == IntLit.ULONG) {
			mode = firmTypeSystem.getFirmMode(x10TypeSystem.ULong());
		} else if (kind == IntLit.SHORT) {
			mode = firmTypeSystem.getFirmMode(x10TypeSystem.Short());
		} else if (kind == IntLit.USHORT) {
			mode = firmTypeSystem.getFirmMode(x10TypeSystem.UShort());
		} else if (kind == IntLit.BYTE) {
			mode = firmTypeSystem.getFirmMode(x10TypeSystem.Byte()); 
		} else if (kind == IntLit.UBYTE) {
			mode = firmTypeSystem.getFirmMode(x10TypeSystem.UByte());
		} else {
			throw new InternalCompilerError("Unrecognized IntLit kind " + kind);
		}

		final long value = literal.value();

		return new TargetValue(value, mode);
	}

	@Override
	public void visit(IntLit_c n) {
		final TargetValue targetValue = getIntLitTarval(n);
		final Node ret = con.newConst(targetValue);

		setReturnNode(ret);
	}

	private Node getStaticNullLitNode(NullLit_c n) {
		// Create a new local construction and use it to create a new null const node
		final Graph graph = Program.getConstCodeGraph();
		final Construction c = new OOConstruction(graph);
		final firm.Type type = firmTypeSystem.asFirmType(n.type());
		final Mode mode = type.getMode();
		Node result = c.newConst(mode.getNull());

		return result;
	}

	@Override
	public void visit(NullLit_c n) {
		final firm.Type type = firmTypeSystem.asFirmType(n.type());
		final Mode mode = type.getMode();
		final Node result = con.newConst(mode.getNull());
		setReturnNode(result);
	}

	private Node createStringLiteral(String value) {
		/* Construct call to builtin function, which creates an X10 string struct. */
		final Node string_const = createStringSymConst(value);

		final firm.Type[] parameterTypes = new firm.Type[2];
		parameterTypes[0] = firmTypeSystem.asFirmType(x10TypeSystem.UInt());
		parameterTypes[1] = new PointerType(parameterTypes[0]); /* XXX Pointer to uint is not quite correct */
		final firm.Type[] resultTypes = new firm.Type[1];
		resultTypes[0] = firmTypeSystem.asFirmType(x10TypeSystem.String());
		final MethodType type = new firm.MethodType(parameterTypes, resultTypes);

		final Entity func_ent = new Entity(Program.getGlobalType(), X10_STRING_LITERAL, type);
		final Node address = con.newSymConst(func_ent);

		Node[] parameters = new Node[2];
		parameters[0] = con.newConst(value.length(), Mode.getIu());
		parameters[1] = string_const;
		final Node mem = con.getCurrentMem();
		final Node call = con.newCall(mem, address, parameters, type);
		final Node newMem = con.newProj(call, Mode.getM(), Call.pnM);
		con.setCurrentMem(newMem);

		assert (type.getNRess() == 1);
		final firm.Type ret_type = type.getResType(0);
		final Node all_results = con.newProj(call, Mode.getT(), Call.pnTResult);
		final Mode mode = ret_type.getMode();
		assert (mode != null);
		return con.newProj(all_results, mode, 0);
	}

	@Override
	public void visit(StringLit_c n) {
		setReturnNode(createStringLiteral(n.value()));
	}

	private Node createStringSymConst(String value) {
		final ClassType global_type = Program.getGlobalType();
		final firm.Type elem_type = firmTypeSystem.asFirmType(x10TypeSystem.Char());
		final ArrayType type = new ArrayType(1, elem_type);

		final Ident id = Ident.createUnique("str.%u");
		final Entity ent = new Entity(global_type, id, type);
		ent.setLdIdent(id);

		ent.setVisibility(ir_visibility.ir_visibility_private);
		ent.addLinkage(ir_linkage.IR_LINKAGE_CONSTANT.val);

		type.setBounds(0, 0, value.length()-1);
		type.setSizeBytes(4 * value.length());
		type.setTypeState(ir_type_state.layout_fixed);

		final Initializer init = new Initializer(value.length());
		final char[] chars = value.toCharArray();
		for (int i = 0; i < chars.length; ++i) {
			final TargetValue tv = new TargetValue(chars[i], elem_type.getMode());
			final Initializer val = new Initializer(tv);
			init.setCompoundValue(i, val);
		}
		ent.setInitializer(init);

		return con.newSymConst(ent);
	}

	private TargetValue getCharLitTargetValue(CharLit_c literal) {
		final Mode mode = firmTypeSystem.getFirmMode(literal.type());
		final long value = literal.value();
		return new TargetValue(value, mode);
	}

	@Override
	public void visit(CharLit_c literal) {
		final TargetValue targetValue = getCharLitTargetValue(literal);
		final Node ret = con.newConst(targetValue);
		setReturnNode(ret);
	}

	private TargetValue getBooleanLitTargetValue(BooleanLit_c literal) {
		final Mode mode = firmTypeSystem.getFirmMode(x10TypeSystem.Boolean());
		return literal.value() ? mode.getOne() : mode.getNull();
	}

	@Override
	public void visit(BooleanLit_c literal) {
		final TargetValue targetValue = getBooleanLitTargetValue(literal);
		final Node ret = con.newConst(targetValue);
		setReturnNode(ret);
	}

	private Node getThis(Mode mode) {
		return con.getVariable(0, mode);
	}

	@Override
	public void visit(X10Special_c n) {
		if (n.kind() == Special.THIS) {
			firm.Mode mode = firmTypeSystem.getFirmMode(n.type());
			final Node thisPointer = getThis(mode);
			setReturnNode(thisPointer);
		} else {
			throw new RuntimeException("Not implemented yet");
		}
	}

	@Override
	public void visit(ClosureCall_c c) {
		/* determine called function */
		final MethodInstance applyMethodInstance = c.closureInstance();
		final Node ret = genX10Call(applyMethodInstance, c.arguments(), c.target());
		setReturnNode(ret);
	}

	/**
	 * Creates a wrapping cast node for a given expression if the expression must be casted.
	 * @param expr The expression which should be wrapped
	 * @param fType The type too which the given expression should be casted
	 * @return The given expression if no cast must be done or a wrapping cast node.
	 */
	private Expr x10Cast(final Expr expr, final Type fType) {
		Expr ret = expr;
		if(!x10TypeSystem.typeDeepBaseEquals(fType, expr.type(), x10Context)) {
			final Position pos = expr.position();
			Converter.ConversionType convType = Converter.ConversionType.UNCHECKED;

			if(x10TypeSystem.isSubtype(expr.type(), fType, x10Context)) {
				convType = Converter.ConversionType.SUBTYPE;
			}

			ret = xnf.X10Cast(pos, xnf.CanonicalTypeNode(pos, fType), expr, convType).type(fType);
        }
		return ret;
	}

	private Expr wrapArgument(final Type fType, final Expr arg) {
		Expr ret = arg;
		if (!x10TypeSystem.typeEquals(fType, arg.type(), x10Context))
			ret = x10Cast(arg, fType);
		return ret;
	}

	/**
	 * Wraps a list of expressions into another list of expressions where types are adjusted by explicit casts.
	 * (Adjustment is done by wrapping the expressions into cast nodes)
	 *
	 * @param formalTypes A list with the formal types.
	 * @param args The list with the expressions.
	 * @return A list of expressions where improper types are adjusted by explicit casts.
	 */
	private List<Expr> wrapArguments(final List<Type> formalTypes, final List<Expr> args) {
		assert(formalTypes.size() == args.size());
		List<Expr> ret = new LinkedList<Expr>();

		int i = 0;
		for (Expr arg : args) {
		    final Type fType = formalTypes.get(i);

		    arg = wrapArgument(fType, arg);

		    ret.add(arg);
		    i++;
		}

		return ret;
	}

	/**
	 * Creates the appropriate firm graph for a call.
	 * @param mi The method instance
	 * @param args The arguments of the method
	 * @param target The target of the method call.
	 * @return The return node or null if the call doesn`t have a return value
	 */
	private Node genX10Call(final MethodInstance mi, final List<Expr> args, Receiver target) {
		final Flags flags = mi.flags();
		final boolean isStatic = flags.isStatic();
		final boolean isFinal  = flags.isFinal();
		final boolean isStruct = x10TypeSystem.isStructType(mi.container());
		final boolean isStaticBinding = (isStatic || isFinal || isStruct);
		final Entity entity = firmTypeSystem.getMethodEntity(mi);

		final MethodType type = (MethodType) entity.getType();
		final int paramCount = type.getNParams();

		List<Expr> arguments = new LinkedList<Expr>();

		// add the other arguments
		arguments.addAll(wrapArguments(mi.formalTypes(), args));

		// add implicit this pointer
		if (!isStatic) {
			assert(target != null && target instanceof Expr) : mi.toString();
			final Expr receiver = (Expr)target;
			arguments.add(0, wrapArgument(mi.container(), receiver));
		}

		assert arguments.size() == paramCount : "parameters are off : "+ arguments.size() + " vs " + paramCount;
		Node[] parameters = new Node[paramCount];

		for (int i = 0; i < paramCount; i++)
			parameters[i] = visitExpression(arguments.get(i));

		final Node address = (isStaticBinding) ? con.newSymConst(entity) : con.newSel(parameters[0], entity);

		final Node mem = con.getCurrentMem();
		final Node call = con.newCall(mem, address, parameters, type);
		final Node newMem = con.newProj(call, Mode.getM(), Call.pnM);
		con.setCurrentMem(newMem);

		if (type.getNRess() == 0) {
			return null; /* no return value, we're done */
		}

		assert (type.getNRess() == 1); /* X10 does not support multiple return values */

		firm.Type ret_type = type.getResType(0);
		final Node all_results = con.newProj(call, Mode.getT(), Call.pnTResult);
		Mode mode = ret_type.getMode();

		if (mode == null) {
			/* classes do not have modes assigned, use pointer mode */
			mode = Mode.getP();
		}

		final Node ret = con.newProj(all_results, mode, 0);

		return ret;
	}

	@Override
	public void visit(X10Binary_c B) {
		final Node n = produceBooleanValue(B);
		setReturnNode(n);
	}

	@Override
	public void visit(Binary_c B) {
		final Node n = produceBooleanValue(B);
		setReturnNode(n);
	}

	@Override
	public void visit(AssignPropertyCall_c n) {
		/* Properties can only be called in a constructor; so we can generate the following
		 * simple code for a property "property(a,b,c,..)" ->
		 * this->a = a;
		 * this->b = b;
		 * this->c = c;
		 * ...
		 */
		final List<X10FieldInstance> properties = n.properties();
		final List<Expr> args = n.arguments();
		assert(properties.size() == args.size());

		final Node thisPointer = getThis(Mode.getP());
		for(int i = 0; i < properties.size(); i++) {
			final FieldInstance field = properties.get(i);
			final Node node = visitExpression(args.get(i));
			genFieldAssign(thisPointer, field, node);
		}
	}

	/**
	 * Initializes a given boxing type -> creates methods etc.
	 * @param boxedType The type of the boxed field
	 * @param boxType The boxing type which should be initialized
	 */
	private void initBoxingType(final X10ClassType boxedType, final X10ClassType boxType) {

		final FieldInstance boxedField = boxType.fieldNamed(Name.make(FirmTypeSystem.BOXED_VALUE));
		assert(boxedField != null);

		final Position pos = Position.COMPILER_GENERATED;
		for(final MethodInstance m : boxType.methods()) {
			final Flags flags = m.flags();
			final Entity entity = firmTypeSystem.getMethodEntity(m);

	        List<Stmt> statements = new ArrayList<Stmt>();

	        /* We will generate the following code
	         *
	         * def BoxingType:"MethodName"(param1, param2, param3, ...) {
	         *    return this.boxValue."MethodName"(param1, param2, param3, ...);
	         * }
	         *
	         * To avoid unnecessary dynamic delegation calls we can and will do a static method call on the boxed field.
	         */

	        final OOConstruction savedConstruction = initConstruction(entity, m.formalNames(), new LinkedList<LocalInstance>(),
	        														  flags, m.returnType(), boxType);

	        // The receiver of the delegated method call -> the boxed value
	        final Expr bxdField = xnf.Field(pos, xnf.This(pos).type(boxType), xnf.Id(pos, boxedField.name())).fieldInstance(boxedField).type(boxedType);

	        // the arguments.
	        List<Expr> args = new LinkedList<Expr>();
	        for(LocalInstance loc : m.formalNames()) {
	        	final Expr rval = xnf.Local(pos, xnf.Id(pos, loc.name())).localInstance(loc).type(loc.type());
	        	args.add(rval);
	        }
	        

	        // find the appropriate method instance (concrete method) -> to avoid unnecessary dynamic delegation calls.
	        MethodInstance im = null;
	        for(final MethodInstance meth : boxedType.methods(m.name(), m.formalTypes(), x10Context)) {
	        	if(meth.isSameMethod(m, x10Context)) {
	        		im = meth;
	        		break;
	        	}
	        }
	        assert(im != null);

	        // create the call
	        final Expr call = xnf.X10Call(pos, bxdField, xnf.Id(pos, im.name()), Collections.<TypeNode>emptyList(), args)
	        					.methodInstance(im).type(m.returnType());

	        // append an optional return
	        if(im.returnType() != x10TypeSystem.Void()) {
	        	final Return ret = xnf.X10Return(pos, call, false);
	        	statements.add(ret);
	        } else {
	        	statements.add(xnf.Eval(pos, call));
	        }

	        final polyglot.ast.Block block = xnf.Block(pos, statements);
	        // Now generate the firm graph
	        visitAppropriate(block);

	        finishConstruction(entity, savedConstruction);
		}
	}

	/**
	 * Set which holds initialized boxing types -> boxing types will be inited only once.
	 */
	private static Set<Type> initedBoxingTypes = new HashSet<Type>();
	
	private X10ClassType getBoxingType(final X10ClassType type) {
		final X10ClassType boxType = firmTypeSystem.getBoxingType(type);

		if(!initedBoxingTypes.contains(boxType)) {
			// init the boxing type only once
			initBoxingType(type, boxType);
			initedBoxingTypes.add(boxType);
		}
		
		return boxType;
	}

	/**
	 * Creates the appropriate firm graph for an autoboxing
	 * @param fromType The type which should be boxed
	 * @param node The expression which should be boxed
	 * @return A
	 */
	public Node genBoxing(final X10ClassType fromType, final Node node) {
		final X10ClassType boxType = getBoxingType(fromType);

		// Generate the box
		final Node box = genHeapAlloc(boxType);

		// save the boxed value in the box
		final FieldInstance boxValue = boxType.fieldNamed(Name.make(FirmTypeSystem.BOXED_VALUE));
		assert(boxValue != null);
		genFieldAssign(box, boxValue, node);

		return box;
	}
	
	private Node genUnboxing(final Node node, final X10ClassType fromType, final X10ClassType toType) {
		final X10ClassType boxType = getBoxingType(toType);
		
        genCastNullCheck(node, fromType);
		final FieldInstance boxValue = boxType.fieldNamed(Name.make(FirmTypeSystem.BOXED_VALUE));
		assert(boxValue != null);
		genSubtypeCheck(node, fromType, toType);
		final Node boxedValue = genFieldLoad(node, boxValue);
		return boxedValue;
	}
	
	/**
	 * Returns a throw statement with the given text message
	 * @param msg The text message
	 * @return A throw statement
	 */
	Stmt getThrowNewExceptionStmt(final Type excType, final String msg) {
		final Position pos = Position.COMPILER_GENERATED;
        final Expr excStr = xnf.StringLit(pos, msg);
        final List<Expr> excArgs = new ArrayList<Expr>();
        excArgs.add(excStr);
        final Expr newClassCastExc = xnf.New(pos, xnf.CanonicalTypeNode(pos, excType), excArgs);
        final Stmt throwStmt = xnf.Throw(pos, newClassCastExc);
        return throwStmt;
	}
	
	/**
	 * Generate firm code for sub type checks. 
	 * @param node The node which should be checked
	 * @param fromType The from type
	 * @param toType The to type
	 */
	void genSubtypeCheck(final Node node, final Type fromType, final Type toType) {
		assert(toType instanceof X10ClassType);
		final Type compType = x10TypeSystem.isStructType(toType) ? firmTypeSystem.getBoxingType((X10ClassType)toType) : toType;

		final CondTemplate condTemplate = new CondTemplate() {
			@Override
			public void genCode(final Block trueBlock, final Block falseBlock) {
				final Node ret = ConditionEvaluationCodeGenerator.genInstanceOf(node, fromType, compType, X10FirmCodeGenerator.this, x10TypeSystem, firmTypeSystem, con);
				ConditionEvaluationCodeGenerator.makeJumps(ret, falseBlock, trueBlock, con);
			}
		};

		final StmtTemplate ifStmt = new StmtTemplate() {
			@Override
			public void genCode() {
				final Stmt throwStmt = getThrowNewExceptionStmt(x10TypeSystem.ClassCastException(), 
						"Cannot cast " + fromType + " to " + toType);
				visitAppropriate(throwStmt);
			}
		};
		
		fct.genIfStatement(con, condTemplate, ifStmt, null);
	}

	private void genCastNullCheck(final Node node, final Type type) {
		
		final CondTemplate condTemplate = new CondTemplate() {
			@Override
			public void genCode(final Block trueBlock, final Block falseBlock) {
				final Position pos = Position.COMPILER_GENERATED;
				final Node nullNode = visitExpression(xnf.NullLit(pos).type(x10TypeSystem.Null()));
				final Node cmp = con.newCmp(node, nullNode, Relation.Equal);
				ConditionEvaluationCodeGenerator.makeJumps(cmp, trueBlock, falseBlock, con);
			}
		};
		
		final StmtTemplate ifStmt = new StmtTemplate() {
			@Override
			public void genCode() {
				final Stmt throwStmt = getThrowNewExceptionStmt(x10TypeSystem.ClassCastException(), 
						"null cannot be cast to struct " + type);
				visitAppropriate(throwStmt);
			}
		};
		
		fct.genIfStatement(con, condTemplate, ifStmt, null);
	}
	
	private Node genRefToRefCast(final Node node, final Type fromType, final Type tooType, final boolean checked) {
		final CondTemplate cond = new CondTemplate() {
			@Override
			public void genCode(final Block trueBlock, final Block falseBlock) {
				final Position pos = Position.COMPILER_GENERATED;
				final Node nullNode = visitExpression(xnf.NullLit(pos).type(x10TypeSystem.Null()));
				final Node cmp = con.newCmp(node, nullNode, Relation.Equal);
				ConditionEvaluationCodeGenerator.makeJumps(cmp, trueBlock, falseBlock, con);
			}
		};
		
		final ExprTemplate trueExpr = new ExprTemplate() {
			@Override
			public Node genCode() {
				final Position pos = Position.COMPILER_GENERATED;
				return visitExpression(xnf.NullLit(pos).type(x10TypeSystem.Null()));
			}
		};
		
		final ExprTemplate falseExpr = new ExprTemplate() {
			@Override
			public Node genCode() {
				// can have checked and unchecked casts 
				if(checked)
					genSubtypeCheck(node, fromType, tooType);
				
				return node;
			}
		};
		
		return fct.genConditional(con, cond, trueExpr, falseExpr);
	}
	
	@Override
	public void visit(X10Cast_c c) {
		
		final TypeNode tn = c.castType();
		assert (tn instanceof CanonicalTypeNode);
		
		switch (c.conversionType()) {
		case CHECKED:
		case PRIMITIVE:
		case SUBTYPE:
		case UNCHECKED:
			final X10CanonicalTypeNode xtn = (X10CanonicalTypeNode) tn;
			
			final Type toType 	= Types.baseType(xtn.type());
			final Type fromType = Types.baseType(c.expr().type());
			
			final Type to   = Types.stripConstraints(toType);
			final Type from = Types.stripConstraints(fromType);
			
			if (x10TypeSystem.typeEquals(from, to, x10Context)) {
				// types are statically equal no type conversion needed.
				visitAppropriate(c.expr());
				break;
			} else if(x10TypeSystem.isRefType(from) && x10TypeSystem.isRefType(to)) {
				// ref -> ref
				final Node node = visitExpression(c.expr());
				final Node ret = genRefToRefCast(node, c.expr().type(), to, c.conversionType() == Converter.ConversionType.CHECKED);
				setReturnNode(ret);
				break;
			} else if(x10TypeSystem.isStructType(from) && x10TypeSystem.isRefType(to)) {
				// struct -> ref
				// Check for boxing
				if (c.conversionType() == Converter.ConversionType.SUBTYPE && x10TypeSystem.isSubtype(from, to, x10Context)) {
					if (x10TypeSystem.isInterfaceType(to) && x10TypeSystem.isStructType(from)) {
						// An upcast of a struct to an implemented interface -> Need boxing
						final Node node = visitExpression(c.expr());
						final Node ret = genBoxing((X10ClassType) x10TypeSystem.toClass(from), node);
						setReturnNode(ret);
						break;
					}
				}
				assert(false);
				break;
			} else if(x10TypeSystem.isRefType(from) && x10TypeSystem.isStructType(to)) {
				// ref -> struct
				// Unboxing -> must be a checked cast !!!
				assert(c.conversionType() == ConversionType.CHECKED);
				final Node box = visitExpression(c.expr());
				final Node ret = genUnboxing(box, (X10ClassType)x10TypeSystem.toClass(from), (X10ClassType)x10TypeSystem.toClass(to));
				setReturnNode(ret);
				break;
			}

			assert(false);
			//$FALL-THROUGH$
		case CALL_CONVERSION:
		case UNBOXING:
		case UNKNOWN_IMPLICIT_CONVERSION:
		case UNKNOWN_CONVERSION:
		case DESUGAR_LATER:
			throw new InternalCompilerError("Unknown conversion type after type-checking.", c.position());

		case BOXING:
			throw new InternalCompilerError("Boxing conversion should have been rewritten.", c.position());
		}
	}

	@Override
	public void visit(X10Instanceof_c n) {
		final Node node = produceBooleanValue(n);
		setReturnNode(node);
	}

	@Override
	public void visit(SubtypeTest_c n) {
		final Type subType = n.subtype().type();
		final Type superType = n.supertype().type();
		final Mode mode = firmTypeSystem.getFirmMode(x10TypeSystem.Boolean());
		boolean res;

		if (n.equals())
			res = x10TypeSystem.typeBaseEquals(subType, superType, x10Context);
		else
			res = x10TypeSystem.isSubtype(subType, superType);

		setReturnNode(con.newConst(res ? mode.getOne() : mode.getNull()));
	}

	@Override
	public void visit(ParExpr_c n) {
		visitAppropriate(n.expr());
	}

	@Override
	public void visit(TypeDecl_c n) {
		// DO NOTHING
	}

	@Override
	public void visit(LocalTypeDef_c n) {
		// DO NOTHING
	}

	@Override
	public void visit(Assert_c n) {
		if (!options.assertions) {
			setReturnNode(null);
			return;
		}

		final Node cond = visitExpression(n.cond());

		Node errMsg = null;
		if (n.errorMessage() != null)
			errMsg = visitExpression(n.errorMessage());
		else
			errMsg = con.newConst(0, firmTypeSystem.getFirmMode(x10TypeSystem.String()));

		Node position = null;
		if (n.position() != null)
			position = createStringLiteral(n.position().nameAndLineString());
		else
			position = con.newConst(0, firmTypeSystem.getFirmMode(x10TypeSystem.String()));

		final firm.Type[] parameterTypes = new firm.Type[3];
		parameterTypes[0] = firmTypeSystem.asFirmType(x10TypeSystem.Boolean());
		parameterTypes[1] = firmTypeSystem.asFirmType(x10TypeSystem.String());
		parameterTypes[2] = firmTypeSystem.asFirmType(x10TypeSystem.String());
		final firm.Type[] resultTypes = new firm.Type[0];
		final MethodType type = new firm.MethodType(parameterTypes, resultTypes);
		final Entity funcEnt = new Entity(Program.getGlobalType(), X10_ASSERT, type);
		final Node address = con.newSymConst(funcEnt);

		Node[] parameters = new Node[] { cond, errMsg, position };
		final Node mem = con.getCurrentMem();
		final Node call = con.newCall(mem, address, parameters, type);
		final Node newMem = con.newProj(call, Mode.getM(), Call.pnM);
		con.setCurrentMem(newMem);

		setReturnNode(call);
	}
	
	@Override
	public void visit(Initializer_c n) {
	    if (n.flags().flags().isStatic()) {
	    	static_init_blocks.add(n);
	    } else {
	    	throw new RuntimeException("Not implemented yet");
	    }
	}

	//
	//  TODO:  Implement.
	//

	// Just a stub implementation for now.
	@Override
	public void visit(Throw_c n) {
		final firm.Type[] parameterTypes = new firm.Type[0];
		final firm.Type[] resultTypes = new firm.Type[0];
		final MethodType type = new firm.MethodType(parameterTypes, resultTypes);
		final Entity funcEnt = new Entity(Program.getGlobalType(), X10_THROW_STUB, type);
		final Node address = con.newSymConst(funcEnt);

		Node[] parameters = new Node[0];
		final Node mem = con.getCurrentMem();
		final Node call = con.newCall(mem, address, parameters, type);
		final Node newMem = con.newProj(call, Mode.getM(), Call.pnM);
		con.setCurrentMem(newMem);

		con.getGraph().keepAlive(call);
		con.getGraph().keepAlive(con.getCurrentBlock());
	}

	@Override
	public void visit(PropertyDecl_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(Formal_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(X10CanonicalTypeNode_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(Id_c n) {
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
	public void visit(Tuple_c c) {
		throw new RuntimeException("Not implemented yet");
	}

	//
	//  Will never be implemented.
	//

	@Override
	public void visit(Closure_c n) {
		throw new RuntimeException("Closures should have been desugared earlier");
	}

	@Override
	public void visit(LocalClassDecl_c n) {
		throw new RuntimeException("Local classes should have been removed by a separate pass");
	}

	@Override
	public void visit(X10Unary_c n) {
		throw new RuntimeException("Unary expressions should have been desugared earlier");
	}

	@Override
	public void visit(Unary_c n) {
		throw new RuntimeException("Unary expressions should have been desugared earlier");
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
	public void visit(When_c n) {
		throw new RuntimeException("When should have been desugared earlier");
	}

	@Override
	public void visit(AtStmt_c n) {
		throw new RuntimeException("At statements are deprecated");
	}

	@Override
	public void visit(AtExpr_c n) {
		throw new RuntimeException("At expression should have been desugared earlier");
	}

	@Override
	public void visit(PackageNode_c n) {
		throw new RuntimeException("Package nodes should have been handled by an earlier pass");
	}

	@Override
	public void visit(Import_c n) {
		throw new RuntimeException("Imports should have been handled by an earlier pass");
	}

	/**
	 * return current construction object
	 */
	public OOConstruction getFirmConstruction() {
		return con;
	}
	
	public X10FirmContext getFirmContext() {
		return firmContext;
	}
	
	public GenericTypeSystem getX10TypeSystem() {
		return x10TypeSystem;
	}
	
	public X10NodeFactory_c getNodeFactory() {
		return xnf;
	}

	/**
	 * return FIRM type system
	 */
	public FirmTypeSystem getFirmTypeSystem() {
		return firmTypeSystem;
	}
}