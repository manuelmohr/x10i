package x10firm.visit;

import java.nio.charset.Charset;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;

import polyglot.ast.Allocation_c;
import polyglot.ast.ArrayAccess_c;
import polyglot.ast.ArrayInit_c;
import polyglot.ast.Assert_c;
import polyglot.ast.Assign_c;
import polyglot.ast.Binary_c;
import polyglot.ast.Block_c;
import polyglot.ast.BooleanLit_c;
import polyglot.ast.Branch;
import polyglot.ast.Branch_c;
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
import polyglot.ast.FloatLit_c;
import polyglot.ast.ForInit;
import polyglot.ast.ForUpdate;
import polyglot.ast.For_c;
import polyglot.ast.Formal_c;
import polyglot.ast.Id;
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
import polyglot.types.ConstructorInstance;
import polyglot.types.Context;
import polyglot.types.FieldInstance;
import polyglot.types.Flags;
import polyglot.types.LocalDef;
import polyglot.types.LocalInstance;
import polyglot.types.LocalInstance_c;
import polyglot.types.Name;
import polyglot.types.Ref_c;
import polyglot.types.Type;
import polyglot.types.Types;
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
import x10.ast.X10CanonicalTypeNode_c;
import x10.ast.X10Cast_c;
import x10.ast.X10ClassDecl;
import x10.ast.X10ClassDecl_c;
import x10.ast.X10ConstructorCall_c;
import x10.ast.X10FieldDecl;
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
import x10.types.X10FieldDef;
import x10.types.X10FieldInstance;
import x10.types.X10LocalDef_c;
import x10.types.X10MethodDef;
import x10.types.checker.Converter;
import x10.types.checker.Converter.ConversionType;
import x10.visit.X10DelegatingVisitor;
import x10firm.CompilerOptions;
import x10firm.types.FirmTypeSystem;
import x10firm.types.GenericTypeSystem;
import x10firm.types.NameMangler;
import x10firm.types.ParameterTypeMapping;
import x10firm.visit.FirmCodeTemplate.CondTemplate;
import x10firm.visit.FirmCodeTemplate.ExprTemplate;
import x10firm.visit.FirmCodeTemplate.StmtTemplate;
import x10firm.visit.builtins.Builtins;
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
import firm.SwitchTable;
import firm.TargetValue;
import firm.bindings.binding_ircons.ir_linkage;
import firm.bindings.binding_ircons.ir_where_alloc;
import firm.bindings.binding_irprog.ir_segment_t;
import firm.bindings.binding_typerep.ir_type_state;
import firm.bindings.binding_typerep.ir_visibility;
import firm.nodes.Alloc;
import firm.nodes.Block;
import firm.nodes.Call;
import firm.nodes.CopyB;
import firm.nodes.Load;
import firm.nodes.Node;
import firm.nodes.OOConstruction;
import firm.nodes.Store;
import firm.nodes.Switch;

/**
 * creates a firm-program (a collection of firm-graphs) from an X10-AST.
 */
public class FirmGenerator extends X10DelegatingVisitor {
	private static final String X10_THROW_STUB         = "x10_throw_stub";
	private static final String X10_ASSERT             = "x10_assert";
	private static final String X10_STATIC_INITIALIZER = "x10_static_initializer";
	private static final Charset UTF8 = Charset.forName("UTF8");

	private final Builtins builtins = new Builtins();

	/** The current method construction object. */
	private MethodConstruction con;

	private List<ClassMember> initClassMembers;

	/** This is the "return-value" of visitor functions handling expressions. */
	private Node returnNode;

	/** X10 Context. */
	private Context x10Context;

	/** Our firm type system. */
	private final FirmTypeSystem firmTypeSystem;

	/** The X10 type system. */
	private final GenericTypeSystem x10TypeSystem;

	/** Our node factory. */
	private final X10NodeFactory_c xnf;

	/** Our own AST query. */
	private final ASTQuery query;

	/** Command-line options. */
	private CompilerOptions options;

	/** Holds all static initializer blocks. */
	private static List<polyglot.ast.Initializer> staticInitBlocks = new LinkedList<polyglot.ast.Initializer>();

	private Set<ClassMember> staticMonGenericMembers = new HashSet<ClassMember>();
	private X10ConstructorInstance stringLiteralConstructor;

	/**
	 * Constructs a new X10FirmCodeGenerator.
	 */
	public FirmGenerator(final FirmTypeSystem firmTypeSystem,
			final GenericTypeSystem x10TypeSystem,
			final X10NodeFactory_c nodeFactory,
			final CompilerOptions options) {

		this.firmTypeSystem = firmTypeSystem;
		this.x10TypeSystem  = x10TypeSystem;
		this.xnf            = nodeFactory;
		this.query          = new ASTQuery(x10TypeSystem);
		this.x10Context     = new Context(x10TypeSystem);
		this.options        = options;
	}

	/** Performs all post compile tasks. */
	public void genPostCompile() {
		genGenericCode();
		genStaticInitializationSupportCode();
	}

	/** Generates the static initialization constructor. */
	private void genStaticInitializationSupportCode() {
		// get the "constructor" segment and then put the static initialization code in the "constructor" segment.
		final ClassType conSegment = Program.getSegmentType(ir_segment_t.IR_SEGMENT_CONSTRUCTORS.val);

		final firm.Type[] parameterTypes = new firm.Type[0];
		final firm.Type[] resultTypes = new firm.Type[0];

		final firm.Type methodType = new MethodType(parameterTypes, resultTypes);
		final String name = NameMangler.mangleKnownName(X10_STATIC_INITIALIZER);
		final Entity methodEntity = new Entity(Program.getGlobalType(), name, methodType);
		final firm.Type ptrMethodType = new PointerType(methodType);

		final Entity conEntity = new Entity(conSegment, "$ctor", ptrMethodType);
		final Graph graph = Program.getConstCodeGraph();
		final Node val = graph.newSymConst(methodEntity);

		conEntity.setLdIdent(name);
		conEntity.setCompilerGenerated(true);
		conEntity.setVisibility(ir_visibility.ir_visibility_private);
		conEntity.setLinkage(ir_linkage.IR_LINKAGE_HIDDEN_USER.val | ir_linkage.IR_LINKAGE_CONSTANT.val);
		conEntity.setAtomicValue(val);

		final MethodConstruction savedConstruction
			= initConstruction(methodEntity,  Collections.<LocalInstance>emptyList(),
				Collections.<LocalInstance>emptyList(), x10TypeSystem.Void(), null);

		for (final polyglot.ast.Initializer n : staticInitBlocks) {
			visitAppropriate(n.body());
		}

		finishConstruction(methodEntity, savedConstruction);
	}

	/** This queue holds a list of nodes (either MethodDecls or ClassDecls)
	 * and their corresponding mapping of parameter types. */
	private static List<GenericNodeInstance> workList = new LinkedList<GenericNodeInstance>();
	/** Set of generic nodes instances in the worklist for faster checking of duplicates. */
	private static Set<GenericNodeInstance> workListSet = new HashSet<GenericNodeInstance>();

	private static void addToWorklist(final GenericNodeInstance other) {
		// Check for duplicates.
		if (workListSet.contains(other)) return;

		workListSet.add(other);
		workList.add(other);
	}

	private void genGenericCode() {
		/* The list can increase while we are iterating over it!
		 * (When we have a new generic method in another generic method) */
		for (int i = 0; i < workList.size(); i++) {
			final GenericNodeInstance gi = workList.get(i);
			final ParameterTypeMapping ptm = gi.getMapping();

			firmTypeSystem.pushTypeMapping(ptm);
			visitAppropriate(gi.getNode());
			firmTypeSystem.popTypeMapping(ptm);
		}
	}

	/**
	 * Evaluates a given expression and creates the appropriate firm nodes.
	 * @param e The expression
	 * @param trueBlock The true block
	 * @param falseBlock The false block
	 */
	void evaluateCondition(final Expr e, final Block trueBlock, final Block falseBlock) {
		final ConditionEvaluationCodeGenerator codegen
			= new ConditionEvaluationCodeGenerator(trueBlock, falseBlock, this);
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

	/** Resets the remembered value of the returned node of an expression. */
	private void resetReturnNode() {
		setReturnNode(null);
	}

	/**
	 * Remember this node as holding the returned value of the current expression.
	 */
	private void setReturnNode(final Node retNode) {
		returnNode = retNode;
	}

	/**
	 * Returns the Firm node holding the returned value of the current expression.
	 */
	private Node getReturnNode() {
		assert returnNode != null;
		return returnNode;
	}

	@Override
	public void visit(final polyglot.ast.Node n) {
		/* X10DelegatingVisitor does not handle all node types, thus we need to
		 * dispatch the rest here.
		 */
		if (n instanceof X10ClassDecl_c) {
			visit((X10ClassDecl_c) n);
			return;
		} else if (n instanceof X10SourceFile_c) {
			visit((X10SourceFile_c) n);
			return;
		}

		throw new CodeGenError("Unhandled node type" + n.getClass(), n);
	}

	/**
	 * Represents an Instance of a generic native method, field or class
	 * a Node + TypeParameterMapping pair.
	 */
	private static final class GenericNodeInstance {
		private final polyglot.ast.Node node;
		private final ParameterTypeMapping mapping;

		public GenericNodeInstance(final polyglot.ast.Node node, final ParameterTypeMapping mapping) {
			assert node != null && mapping != null;
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

			throw new CodeGenError("getDef called on unexpected thing", node);
		}

		@Override
		public int hashCode() {
			int hash = node.toString().hashCode();

			for (final ParameterType paramType : mapping.getKeySet()) {
				hash ^= mapping.getMappedType(paramType).hashCode();
			}

			return hash;
		}

		@Override
		public boolean equals(final Object other) {
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

	private void visit(final X10SourceFile_c sourceFile) {
		for (TopLevelDecl topLevelDeclaration : sourceFile.decls()) {
			if (topLevelDeclaration instanceof X10ClassDecl) {
				final X10ClassDecl decl = (X10ClassDecl) topLevelDeclaration;
				if (decl.typeParameters().isEmpty())
					visit(decl);
			}
		}
	}

	@Override
	public void visit(final X10ClassDecl_c n) {
		final X10ClassDef def = n.classDef();

		final X10ClassType classType = def.asType();

		if (classType.isX10Struct()) {
			visitStruct(n);
		} else if (classType.isClass() || classType.flags().isInterface()) {
			visitClass(n);
		} else {
			throw new CodeGenError("Unexpected class declaration", n);
		}
	}

	/**
	 * Create the implicit typeName() function of a struct.
	 */
	private void createStructTypeNameMethodBody(final X10ClassDecl clazz,
			final X10MethodDecl meth) {
		final X10MethodDef def = meth.methodDef();
		final MethodInstance methInstance = def.asInstance();
		final Position pos = Position.COMPILER_GENERATED;

		// remove the native flag
		def.setFlags(def.flags().clearNative());

		final List<Stmt> statements = new ArrayList<Stmt>();

		// generate -> return "[packageName].ClassName";
		final Expr str = xnf.StringLit(pos,
				clazz.classDef().fullName().toString()).type(
				x10TypeSystem.String());
		final Return ret = xnf.X10Return(pos, str, false);
		statements.add(ret);

		final polyglot.ast.Block block = xnf.Block(pos, statements);

		final Entity entity = firmTypeSystem.getMethodEntity(methInstance);

		final X10ClassType owner = clazz.classDef().asType();
		final Type thisType = def.flags().isStatic() ? null : owner;
		final MethodConstruction savedConstruction = initConstruction(entity,
				methInstance.formalNames(), new LinkedList<LocalInstance>(),
				methInstance.returnType(), thisType);

		// Now generate the firm graph
		visitAppropriate(block);

		finishConstruction(entity, savedConstruction);
	}

	private void visitStruct(final X10ClassDecl n) {

		final ClassBody body = n.body();
		final List<ClassMember> members = body.members();
		if (!members.isEmpty()) {
			final List<ClassMember> inits = query.extractInits(members);

			final List<ClassMember> oldInitClassMembers = initClassMembers;
			initClassMembers = inits;

			for (ClassMember member : body.members()) {
				if (member instanceof MethodDecl_c) {
					final X10MethodDecl md = (X10MethodDecl)member;
					final X10MethodDef def = md.methodDef();
					final MethodInstance methodInstance = def.asInstance();
					final String name = methodInstance.name().toString();

					// Special case for typeName method -> must be created manually
					if (name.equals("typeName") && def.formalNames().size() == 0) {
						createStructTypeNameMethodBody(n, md);
						continue;
					}
				}

				visitMember(member);
			}

			assert initClassMembers == inits;
			initClassMembers = oldInitClassMembers;
		}
	}

	private void visitMember(final ClassMember member) {

		if (member instanceof MethodDecl_c) {
			final X10MethodDecl md = (X10MethodDecl)member;
			final X10MethodDef def = md.methodDef();
			// don`t visit generic method declarations yet, because we don`t know the concrete type parameters.
			// See X10Call_c
			if (def.typeParameters().isEmpty()) {
				if (def.flags().isStatic()) {
					// visit static non generic methods in generic classes only once
					if (!staticMonGenericMembers.contains(member)) {
						staticMonGenericMembers.add(member);
						visitAppropriate(member);
						return;
					}
				} else {
					visitAppropriate(member);
				}
			}
		} else if (member instanceof FieldDecl_c) {
			final X10FieldDecl fd = (X10FieldDecl)member;
			final X10FieldDef def = fd.fieldDef();
			if (def.flags().isStatic()) {
				if (!staticMonGenericMembers.contains(member)) {
					staticMonGenericMembers.add(member);
					visitAppropriate(member);
				}
			} else {
				visitAppropriate(member);
			}
		} else {
			visitAppropriate(member);
		}
	}

	private void visitClass(final X10ClassDecl n) {
		final ClassBody body = n.body();
		final List<ClassMember> members = body.members();
		if (!members.isEmpty()) {
			final List<ClassMember> inits = query.extractInits(members);

			final List<ClassMember> oldInitClassMembers = initClassMembers;
			initClassMembers = inits;

			for (final ClassMember member : body.members()) {
				visitMember(member);
			}

			assert initClassMembers == inits;
			initClassMembers = oldInitClassMembers;
		}
	}

	/** Finds all locals in the given method.
	 *  @param code    method/constructor code
	 *  @param locals  Will hold all found locals.
	 */
	private static List<LocalInstance> getAllLocalInstancesInCodeBlock(final CodeBlock code) {
		final List<LocalInstance> ret = new LinkedList<LocalInstance>();

		if (code.body() == null)
			return ret;

		final LocalDeclVisitor xLocalsVisitor = new LocalDeclVisitor();
		xLocalsVisitor.visitAppropriate(code.body());

		final List<LocalDecl_c> matchesList = xLocalsVisitor.getLocals();

		if (matchesList.size() == 0)
			return ret;

		for (final LocalDecl_c c : matchesList) {
			// extract the local instances from the found "LocalDecl_c`s"
			final LocalInstance locInstance = c.localDef().asInstance();

			ret.add(locInstance);
		}

		return ret;
	}

	/**
	 * Checks if a given local instanced needs an explicit entity.
	 * @param type The type which should be checked
	 * @return True if the given type needs an entity
	 */
	private boolean needEntityForLocalInstance(final LocalInstance loc) {
		return firmTypeSystem.isFirmStructType(loc.type());
	}

	/**
	 * Starts construction of a new firm graph for a method.
	 * @param entity The method entities for which the a new construction should be initialized
	 * @param formals The formals of the given method entity
	 * @param locals The locals of the given method entity
	 * @return A reference to the current (saved) construction
	 */
	public MethodConstruction initConstruction(final Entity entity, final List<LocalInstance> formals,
			final List<LocalInstance> locals, final Type retType, final Type thisType) {

		int nLocalFirmVars = 0;
		/* locals which live on the frame type do not need
		 * firm variables numbers */
		for (LocalInstance loc : locals) {
			if (!needEntityForLocalInstance(loc))
				nLocalFirmVars++;
		}

		final int nFirmVars = formals.size() + nLocalFirmVars + (thisType != null ? 1 : 0);
		final Graph graph = new Graph(entity, nFirmVars);
		final MethodConstruction savedConstruction = con;
		con = new MethodConstruction(graph);
		con.returnType = retType;
		final firm.Type frameType = con.getGraph().getFrameType();

		final Node args = graph.getArgs();
		int idx = 0;
		if (thisType != null) {
			/* Create a new formal for "this" */
			final Position pos = Position.COMPILER_GENERATED;
			final Name name = Name.make("$this");
			final Flags thisFlags  = Flags.NONE;
			final Ref_c<Type> type = new Ref_c<Type>(thisType);
			final X10LocalDef_c thisDef = new X10LocalDef_c(x10TypeSystem, pos, thisFlags, type, name);
			final LocalInstance_c thisInstance = new LocalInstance_c(x10TypeSystem, pos, new Ref_c<LocalDef>(thisDef));

			if (firmTypeSystem.isFirmStructType(thisType)) {
				final firm.Type firmType = firmTypeSystem.asType(thisType);
				final Entity paramEntity = Entity.createParameterEntity(frameType, idx, firmType);
				final Node node = getEntityFromCurrentFrame(paramEntity);
				con.setVariable(idx, node);
			} else {
				final Mode mode = firmTypeSystem.getFirmMode(thisType);
				final Node projParam = con.newProj(args, mode, idx);
				con.setVariable(idx, projParam);
			}
			con.setVarEntry(VarEntry.newVarEntryForLocalVariable(thisInstance, idx));
			con.thisInstance = thisInstance;
			++idx;
		}

		// init and map all parameters.
		for (final LocalInstance loc : formals) {
			final Type type = loc.type();

			if (firmTypeSystem.isFirmStructType(type)) {
				final firm.Type firmType = firmTypeSystem.asType(type);
				final Entity paramEntity = Entity.createParameterEntity(frameType, idx, firmType);
				final Node node = getEntityFromCurrentFrame(paramEntity);
				con.setVariable(idx, node);
			} else {
				final Mode mode = firmTypeSystem.getFirmMode(loc.type());
				final Node projParam = con.newProj(args, mode, idx);
				con.setVariable(idx, projParam);
			}

			// map the local instance with the appropriate idx.
			con.setVarEntry(VarEntry.newVarEntryForLocalVariable(loc, idx));
			++idx;
		}

		// map all local variables.
		for (final LocalInstance loc : locals) {
			if (needEntityForLocalInstance(loc)) {
				final Entity ent = new Entity(frameType, loc.name().toString(), firmTypeSystem.asClass(loc.type()));
				con.setVarEntry(VarEntry.newVarEntryForStructVariable(loc, ent));
			} else {
				// a normal local variable
				con.setVarEntry(VarEntry.newVarEntryForLocalVariable(loc, idx));
				++idx;
			}
		}
		assert idx == nFirmVars;

		return savedConstruction;
	}

	/**
	 * Finishes a firm graph construction.
	 * @param entity The method entity for which the construction should be finished
	 * @param savedConstruction A reference to the previous construction
	 */
	public void finishConstruction(final Entity entity, final MethodConstruction savedConstruction) {
		/* create Return node if there was no explicit return statement yet */
		if (!con.getCurrentBlock().isBad()) {
			genReturn(null, null);
		}

		con.finish();
		con = savedConstruction;
	}

	private TypeParamSubst buildSubst() {
		final Map<ParameterType, Type> mapping = x10TypeSystem.getMapping();
		final List<Type> actualTypes = new ArrayList<Type>(mapping.values());
		final List<ParameterType> paramTypes = new ArrayList<ParameterType>(mapping.keySet());

		return new TypeParamSubst(x10TypeSystem, actualTypes, paramTypes);
	}

	@Override
	public void visit(final MethodDecl_c dec) {
		final X10MethodDef def = (X10MethodDef) dec.methodDef();
		final MethodInstance defInstance = def.asInstance();

		final boolean hasTypeParameters = !def.typeParameters().isEmpty();
		MethodInstance methodInstance;
		if (!hasTypeParameters) {
			methodInstance = defInstance;
		} else {
			// If we compile a generic method, asInstance() will give
			// us a method instance where generic types are used.  But we know
			// better at this point, because we can substitute the real types.
			final TypeParamSubst subst = buildSubst();
			methodInstance = subst.reinstantiate(def.asInstance());

			// Substitute type parameters manually.  Why doesn't X10 do this?!
			final List<Type> typeArguments = new ArrayList<Type>();
			for (final ParameterType paramType : def.typeParameters()) {
				typeArguments.add(x10TypeSystem.getConcreteType(paramType));
			}

			methodInstance = (MethodInstance) methodInstance.typeParameters(typeArguments);
		}

		final Flags flags = methodInstance.flags();
		final List<LocalInstance> formals = defInstance.formalNames();
		final Entity entity = firmTypeSystem.getMethodEntity(methodInstance);
		final X10ClassType owner = (X10ClassType) methodInstance.container();

		if (flags.isAbstract())
			return;
		if (flags.isNative()) {
			/* for builtins we might need to dynamically create the code now */
			builtins.generate(this, methodInstance, formals);
			/* native code is defined elsewhere, so nothing left to do */
			return;
		}

		// extract all formals and locals from the method.
		final List<LocalInstance> locals = getAllLocalInstancesInCodeBlock(dec);
		final Type retType = defInstance.returnType();
		final Type thisType = flags.isStatic() ? null : owner;
		final MethodConstruction savedConstruction = initConstruction(entity, formals, locals, retType, thisType);

		// Walk body and construct graph
		visitAppropriate(dec.body());

		finishConstruction(entity, savedConstruction);

		if (query.isMainMethod(def)) {
			processMainMethod(entity);
		}
	}

	private void processMainMethod(final Entity mainEntity) {
		/* let's create a simple "main" function which just calls the other main */
		final firm.Type global = Program.getGlobalType();
		/* let's hope the X10 int type is compatible to the C int-type */
		final firm.Type intType = firmTypeSystem.asType(x10TypeSystem.Int());
		final firm.Type[] returnTypes = new firm.Type[] {intType};
		final firm.Type[] parameterTypes = new firm.Type[] {};
		final MethodType mainType = new MethodType(parameterTypes, returnTypes);
		String name = "main";
		name = NameMangler.mangleKnownName(name);
		final Entity entity = new Entity(global, name, mainType);
		entity.setLdIdent(name);
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
		final Node call = construction.newCall(mem, symConst, new Node[] {args}, type);
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
	public void visit(final ConstructorDecl_c dec) {
		final X10ConstructorDef      def      = (X10ConstructorDef) dec.constructorDef();
		final Flags                  flags    = def.flags();
		final X10ConstructorInstance instance = (X10ConstructorInstance) def.asInstance();
		final Entity                 entity   = firmTypeSystem.getConstructorEntity(instance);

		if (flags.isNative()) {
			/* native code is defined elsewhere, so nothing left to do */
			return;
		}

		final List<LocalInstance> formals = instance.formalNames();
		final X10ClassType        owner   = (X10ClassType) instance.container();

		// extract all formals and locals from the method.
		final List<LocalInstance> locals = getAllLocalInstancesInCodeBlock(dec);

		final boolean isStruct = x10TypeSystem.isStructType0(owner);
		final Type returnType;
		final Type thisType;
		final LocalInstance_c thisInstance;
		if (isStruct) {
			final Position pos = Position.COMPILER_GENERATED;
			final Name name = Name.make("$this");
			final Flags thisFlags  = Flags.NONE;
			final Ref_c<Type> type = new Ref_c<Type>(owner);
			final X10LocalDef_c thisDef = new X10LocalDef_c(x10TypeSystem, pos, thisFlags, type, name);
			thisInstance = new LocalInstance_c(x10TypeSystem, pos, new Ref_c<LocalDef>(thisDef));
			locals.add(thisInstance);
			returnType = instance.returnType();
			thisType = null;
		} else {
			returnType = null;
			thisType = owner;
			thisInstance = null;
		}
		final MethodConstruction savedConstruction = initConstruction(entity, formals, locals, returnType, thisType);
		if (isStruct) {
			con.thisInstance = thisInstance;
			con.inStructConstructor = true;
		}

		// The instance variables must be initialized first
		for (ClassMember member : initClassMembers) {
			if (member instanceof FieldDecl_c) {
				final FieldDecl_c fieldDecl = (FieldDecl_c)member;
				assert fieldDecl.init() != null;

				final Flags fieldFlags = fieldDecl.flags().flags();
				assert !fieldFlags.isStatic();

				final FieldInstance fieldInst = fieldDecl.fieldDef().asInstance();
				final Node objectPointer = getThis();
				final Expr expr = fieldDecl.init();
				final Node node = uncheckedCast(expr, fieldInst.type(), dec.position());
				genFieldInstanceAssign(objectPointer, fieldInst, node);
			} else {
				throw new CodeGenError("Illegal class member", dec);
			}
		}

		visitAppropriate(dec.body());

		finishConstruction(entity, savedConstruction);
	}

	/**
	 * Creates a target value for a given constant expr.
	 * @param expr The constant expr
	 * @return The target value of the given constant expr
	 */
	private TargetValue constantToTargetValue(final Expr expr) {
		assert expr != null && expr.isConstant();

		final Object obj = expr.constantValue();

		TargetValue targetValue = null;

		// all unsigned types can`t be evaluated at compile time, because they use an "implicit operator as"
		// to convert the datatype to long, integer etc.

		if (obj instanceof Integer || obj instanceof Long || obj instanceof Byte || obj instanceof Short) {
			final Mode mode;
			final long value;
			if (obj instanceof Integer) {
				mode = firmTypeSystem.getFirmMode(x10TypeSystem.Int());
				value = ((Integer)obj).longValue();
			} else if (obj instanceof Long) {
				mode = firmTypeSystem.getFirmMode(x10TypeSystem.Long());
				value = ((Long)obj).longValue();
			} else if (obj instanceof Byte) {
				mode = firmTypeSystem.getFirmMode(x10TypeSystem.Byte());
				value = ((Byte)obj).longValue();
			} else { // SHORT
				mode = firmTypeSystem.getFirmMode(x10TypeSystem.Short());
				value = ((Short)obj).longValue();
			}
			targetValue = new TargetValue(value, mode);
		} else if (obj instanceof Float || obj instanceof Double) {
			final Mode mode;
			final double value;
			if (obj instanceof Float) {
				mode = firmTypeSystem.getFirmMode(x10TypeSystem.Float());
				value = ((Float)obj).doubleValue();
			} else {
				mode = firmTypeSystem.getFirmMode(x10TypeSystem.Double());
				value = ((Double)obj).doubleValue();
			}
			targetValue = new TargetValue(value, mode);
		} else if (obj instanceof Boolean) {
			final Mode mode = firmTypeSystem.getFirmMode(x10TypeSystem.Boolean());
			final boolean value = ((Boolean)obj).booleanValue();
			targetValue = value ? mode.getOne() : mode.getNull();
		}

		return targetValue;
	}

	/**
	 * Creates an initializer for a given constant expr.
	 * @param expr The constant expr
	 * @return The initializer for the given constant expr
	 */
	private Initializer constantExprToInitializer(final Expr expr) {
		final TargetValue targetValue = constantToTargetValue(expr);
		if (targetValue == null) return null;
		return new Initializer(targetValue);
	}

	private Initializer expr2Initializer(final Expr expr) {
		final Initializer result;
		assert expr.isConstant();

		if (expr instanceof IntLit_c) {
			final TargetValue targetValue = getIntLitTarval((IntLit_c) expr);
			result = new Initializer(targetValue);
		} else if (expr instanceof BooleanLit_c) {
			final TargetValue targetValue = getBooleanLitTargetValue((BooleanLit_c) expr);
			result = new Initializer(targetValue);
		} else if (expr instanceof FloatLit_c) {
			final TargetValue targetValue = getFloatLitTargetValue((FloatLit_c) expr);
			result = new Initializer(targetValue);
		} else if (expr instanceof CharLit_c) {
			final TargetValue targetValue = getCharLitTargetValue((CharLit_c) expr);
			result = new Initializer(targetValue);
		} else if (expr instanceof NullLit_c) {
			result = Initializer.getNull();
		} else {
			// Now we will try the constant evaluation of expr
			result = constantExprToInitializer(expr);
			if (result != null)
				return result;

			throw new CodeGenError("unimplemented initializer expression", expr);
		}
		return result;
	}

	private Node getFieldAddress(final Node objectPointer, final FieldInstance instance) {
		final Entity entity = firmTypeSystem.getEntityForField(instance);
		assert entity != null;
		if (objectPointer != null) {
			return con.newSel(objectPointer, entity);
		}
		return con.newSymConst(entity);
	}

	private Node genFieldLoad(final Node objectPointer, final FieldInstance fInst) {
		final Node fieldPointer = getFieldAddress(objectPointer, fInst);
		return genFieldLoadHelp(fieldPointer, fInst);
	}

	private Node genFieldLoadHelp(final Node fieldPointer, final FieldInstance fInst) {
		if (firmTypeSystem.isFirmStructType(fInst.type())) // structs
			return fieldPointer;

		final firm.Type type = firmTypeSystem.asType(fInst.type());
		final Node mem = con.getCurrentMem();
		final Mode loadMode = type.getMode();
		final Node load = con.newLoad(mem, fieldPointer, loadMode);
		final Node newMem = con.newProj(load, Mode.getM(), Load.pnM);
		final Node result = con.newProj(load, loadMode, Load.pnRes);
		con.setCurrentMem(newMem);

		return result;
	}

	private void assignToAddress(final Node address, final Type type, final Node value) {
		if (firmTypeSystem.isFirmStructType(type)) {
			final firm.Type firmType = firmTypeSystem.asType(type);
			final Node mem = con.getCurrentMem();
			final Node copyB = con.newCopyB(mem, address, value, firmType);
			final Node curMem = con.newProj(copyB, Mode.getM(), CopyB.pnM);
			con.setCurrentMem(curMem);
		} else {
			final Node mem = con.getCurrentMem();
			final Node store = con.newStore(mem, address, value);
			final Node newMem = con.newProj(store, Mode.getM(), Store.pnM);
			con.setCurrentMem(newMem);
		}
	}

	private void genFieldAssign(final Field_c field, final Node value) {
		final FieldInstance instance = field.fieldInstance().def().asInstance();
		Node objectAddress = null;
		if (!field.flags().isStatic())
			objectAddress = visitExpression((Expr)field.target());
		genFieldInstanceAssign(objectAddress, instance, value);
	}

	private void genFieldInstanceAssign(final Node objectAddress, final FieldInstance instance, final Node value) {
		final Node address = getFieldAddress(objectAddress, instance);
		final Type type = instance.type();
		assignToAddress(address, type, value);
	}

	@Override
	public void visit(final FieldDecl_c dec) {
		final Flags flags = dec.flags().flags();
		final FieldInstance instance = dec.fieldDef().asInstance();

		/* static fields may have initializers */
		if (flags.isStatic()) {
			final Expr init = dec.init();
			// Check for in place initializer
			if (init != null && query.isGlobalInit(dec)) {
				final Initializer initializer = expr2Initializer(init);
				final Entity entity = firmTypeSystem.getEntityForField(instance);
				entity.setInitializer(initializer);
			}
		}
	}

	@Override
	public void visit(final Switch_c n) {
		boolean     hasDefaultCase = false;
		final Block curBlock       = con.getCurrentBlock();
		final Node  expr           = visitExpression(n.expr());

		int numCases = 0;
		for (SwitchElement elem : n.elements()) {
			if (!(elem instanceof Case))
				continue;
			final Case c = (Case)elem;
			if (c.isDefault()) {
				hasDefaultCase = true;
				continue;
			}
			numCases++;
		}

		final SwitchTable tbl = new SwitchTable(con.getGraph(), numCases);
		final HashMap<Case, Integer> casePNs = new HashMap<Case, Integer>();
		int nextPn = Switch.pnMax;
		int entry = 0;
		for (SwitchElement elem : n.elements()) {
			if (!(elem instanceof Case))
				continue;
			final Case c = (Case)elem;
			if (c.isDefault()) {
				casePNs.put(c, Switch.pnDefault);
				continue;
			}
			final long value = c.value();
			assert value == (int)value;
			tbl.setEntry(entry, (int)value, (int)value, nextPn);
			casePNs.put(c, nextPn);
			++entry;
			++nextPn;
		}
		assert entry == numCases;

		final Node switchNode = con.newSwitch(expr, nextPn, tbl.ptr);
		final Block breakBlock = con.newBlock();
		con.setCurrentBlockBad();

		final Block oldBreak = con.breakBlock;
		con.breakBlock = breakBlock;
		final Node oldSwitch = con.switchNode;
		con.switchNode = switchNode;
		final Map<Case, Integer> oldCasePNs = con.casePNs;
		con.casePNs = casePNs;

		for (SwitchElement elem : n.elements()) {
			visitAppropriate(elem);
		}

		assert con.breakBlock == breakBlock;
		con.breakBlock = oldBreak;
		assert con.switchNode == switchNode;
		con.switchNode = oldSwitch;
		assert con.casePNs == casePNs;
		con.casePNs = oldCasePNs;

		if (!con.getCurrentBlock().isBad()) {
			final Node jmp = con.newJmp();
			breakBlock.addPred(jmp);
		}

		if (!hasDefaultCase) {
			con.setCurrentBlock(curBlock);
			final Node proj = con.newProj(switchNode, Mode.getX(), Switch.pnDefault);
			breakBlock.addPred(proj);
		}

		breakBlock.mature();
		con.setCurrentBlock(breakBlock);
	}

	@Override
	public void visit(final SwitchBlock_c n) {
		for (final Stmt stmt : n.statements()) {
			visitAppropriate(stmt);
		}
	}

	@Override
	public void visit(final Case_c n) {
		final Block block      = con.newBlock();
		final Node  switchNode = con.switchNode;

		final int pn = con.casePNs.get(n);
		final Node proj = con.newProj(switchNode, Mode.getX(), pn);
		block.addPred(proj);

		final Block current = con.getCurrentBlock();
		if (!current.isBad()) {
			final Node jmp = con.newJmp();
			block.addPred(jmp);
		}

		block.mature();
		con.setCurrentBlock(block);
	}

	@Override
	public void visit(final Branch_c br) {
		if (con.getCurrentBlock().isBad())
			return;

		final Block target;
		final Id targetId = br.labelNode();
		if (targetId != null) {
			if (br.kind() == Branch.CONTINUE) {
				target = con.labeledContinues.get(targetId.toString());
			} else {
				target = con.labeledBreaks.get(targetId.toString());
			}
		} else {
			if (br.kind() == Branch.CONTINUE) {
				target = con.continueBlock;
			} else {
				target = con.breakBlock;
			}
		}

		final Node jmp = con.newJmp();
		target.addPred(jmp);

		con.setCurrentBlockBad();
	}

	@Override
	public void visit(final Labeled_c label) {
		final Stmt stmt = label.statement();
		final Id labelId = label.labelNode();

		con.lastLabel = labelId;
		con.labeledStmt = stmt;

		final Block labeledBlock = con.newBlock();
		if (!con.getCurrentBlock().isBad()) {
			final Node jmp = con.newJmp();
			labeledBlock.addPred(jmp);
		}
		con.labeledBreaks.put(labelId.toString(), labeledBlock);

		visitAppropriate(stmt);
		labeledBlock.mature();
	}

	@Override
	public void visit(final Assign_c asgn) {
		final Expr lhs = asgn.left();
		final Expr right = asgn.right();

		final Type destType = lhs.type();
		final Node casted = uncheckedCast(right, destType, asgn.position());

		/* Assignment to a local variable
		 * -> Assignments to saved variables are not allowed in closures.
		 *  -> so we will not handle them.
		 */
		if (lhs instanceof Local_c) {
			final Local_c lhsLocal = (Local_c)lhs;
			final LocalInstance loc = lhsLocal.localInstance();
			final VarEntry var = con.getVarEntry(loc);

			if (var.getType() == VarEntry.STRUCT) {
				// local struct variable
				final Entity entity = var.getEntity();
				final Node mem = con.getCurrentMem();
				final Node destAddr = visitExpression(lhs);
				final Node copyB = con.newCopyB(mem, destAddr, casted, entity.getType());
				final Node curMem = con.newProj(copyB, Mode.getM(), CopyB.pnM);
				con.setCurrentMem(curMem);
			} else {
				// local normal variable
				final int idx = var.getIdx();
				con.setVariable(idx, casted);
			}
		} else if (lhs instanceof Field_c) {
			final Field_c field = (Field_c) lhs;
			genFieldAssign(field, casted);
		} else {
			throw new CodeGenError("Unexpected assignment target", asgn);
		}
		setReturnNode(casted);
	}

	private void genReturn(final Type returnType, final Expr expr) {
		final Node[] retValues;
		if (con.inStructConstructor) {
			assert expr == null;
			final Node value = getLocalValue(con.thisInstance);
			retValues = new Node[] {value};
		} else if (expr != null) {
			final Expr casted = x10Cast(expr, returnType);
			final Node value = visitExpression(casted);
			retValues = new Node[] {value};
		} else {
			retValues = new Node[0];
		}
		final Node mem     = con.getCurrentMem();
		final Node retNode = con.newReturn(mem, retValues);
		con.getGraph().getEndBlock().addPred(retNode);
		con.setCurrentBlockBad();
	}

	@Override
	public void visit(final Return_c n) {
		/* nothing to do in unreachable code */
		if (con.getCurrentBlock().isBad())
			return;

		genReturn(con.returnType, n.expr());
	}

	@Override
	public void visit(final LocalDecl_c n) {
		final Expr expr = n.init();

		if (expr != null) {
			// autoboxing
			final Expr initExpr = x10Cast(expr, n.type().type());
			final LocalInstance loc = n.localDef().asInstance();

			final VarEntry var = con.getVarEntry(loc);
			assert var != null : "Instance '" + loc + "' not found in FirmContext";

			if (var.getType() == VarEntry.STRUCT) {
				final Entity entity = var.getEntity();
				final Node sel = getEntityFromCurrentFrame(entity);

				// Hmm not a "new" call -> we must copy the return node of the initExpr.
				final Node initNode = visitExpression(initExpr);
				final Node mem = con.getCurrentMem();
				final Node copyB = con.newCopyB(mem, sel, initNode, entity.getType());
				final Node curMem = con.newProj(copyB, Mode.getM(), CopyB.pnM);
				con.setCurrentMem(curMem);
			} else {
				final Node initNode = visitExpression(initExpr);
				final int idx = var.getIdx();
				con.setVariable(idx, initNode);
			}
		}
	}

	@Override
	public void visit(final Block_c b) {
		for (final Stmt statement : b.statements()) {
			visitAppropriate(statement);
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
		// visit the children
		for (final Stmt statement : n.statements()) {
			visitAppropriate(statement);
		}

		// evaluate the stmt expr
		final Expr e = n.result();
		if (e != null)
			visitAppropriate(e);
	}

	@Override
	public void visit(final Do_c n) {
		final Id label = con.lastLabel;
		con.lastLabel = null;

		final Block bTrue  = con.newBlock();
		final Block bCond  = con.newBlock();
		final Block bFalse = con.newBlock();

		bTrue.addPred(con.newJmp());
		con.setCurrentBlock(bTrue);

		final Block oldBreak = con.breakBlock;
		con.breakBlock = bFalse;
		final Block oldContinue = con.continueBlock;
		con.continueBlock = bCond;
		if (label != null && con.labeledStmt == n) {
			con.labeledBreaks.put(label.toString(), bFalse);
			con.labeledContinues.put(label.toString(), bCond);
		}

		final Stmt body = n.body();
		visitAppropriate(body);

		assert con.breakBlock == bFalse;
		con.breakBlock = oldBreak;
		assert con.continueBlock == bCond;
		con.continueBlock = oldContinue;

		if (con.getCurrentBlock().isBad()) {
			return;
		}

		bCond.addPred(con.newJmp());

		bCond.mature();

		con.setCurrentBlock(bCond);

		/* argh! X10 does not check for missing return statements behind
		 * loops that it can prove to be endless
		 * let's hope we can prove the same here... */
		if (n.condIsConstantTrue()) {
			final Node jmp = con.newJmp();
			bTrue.addPred(jmp);
			con.getGraph().keepAlive(bCond);
		} else {
			evaluateCondition(n.cond(), bTrue, bFalse);
		}

		bTrue.mature();
		bFalse.mature();

		/* more fixup for X10 endless loop detection */
		if (bFalse.getPredCount() == 0) {
			con.setCurrentBlockBad();
		} else {
			con.setCurrentBlock(bFalse);
		}
	}

	@Override
	public void visit(final While_c n) {
		final Id label = con.lastLabel;
		con.lastLabel = null;

		final Block bCond  = con.newBlock();
		final Block bTrue  = con.newBlock();
		final Block bFalse = con.newBlock();

		bCond.addPred(con.newJmp());
		con.setCurrentBlock(bCond);

		/* argh! X10 does not check for missing return statements behind
		 * loops that it can prove to be endless
		 * let's hope we can prove the same here... */
		if (n.condIsConstantTrue()) {
			final Node jmp = con.newJmp();
			bTrue.addPred(jmp);
			con.getGraph().keepAlive(bCond);
		} else {
			evaluateCondition(n.cond(), bTrue, bFalse);
		}
		bTrue.mature();

		con.setCurrentBlock(bTrue);

		final Block oldBreak = con.breakBlock;
		con.breakBlock = bFalse;
		final Block oldContinue = con.continueBlock;
		con.continueBlock = bCond;
		if (label != null && con.labeledStmt == n) {
			con.labeledBreaks.put(label.toString(), bFalse);
			con.labeledContinues.put(label.toString(), bCond);
		}

		final Stmt body = n.body();
		visitAppropriate(body);

		assert con.breakBlock == bFalse;
		con.breakBlock = oldBreak;
		assert con.continueBlock == bCond;
		con.continueBlock = oldContinue;

		bFalse.mature();

		if (!con.getCurrentBlock().isBad())
			bCond.addPred(con.newJmp());
		bCond.mature();

		/* more fixup for X10 endless loop detection */
		if (bFalse.getPredCount() == 0) {
			con.setCurrentBlockBad();
		} else {
			con.setCurrentBlock(bFalse);
		}
	}

	@Override
	public void visit(final For_c n) {
		final Id label = con.lastLabel;
		con.lastLabel = null;

		if (n.inits() != null) {
			for (final ForInit f: n.inits()) {
				visitAppropriate(f);
			}
		}

		final Block bCond  = con.newBlock();
		final Block bTrue  = con.newBlock();
		final Block bFalse = con.newBlock();

		bCond.addPred(con.newJmp());
		con.setCurrentBlock(bCond);

		/* argh! X10 does not check for missing return statements behind
		 * loops that it can prove to be endless
		 * let's hope we can prove the same here... */
		if (n.cond() == null || n.condIsConstantTrue()) {
			final Node jmp = con.newJmp();
			bTrue.addPred(jmp);
			con.getGraph().keepAlive(bCond);
		} else {
			evaluateCondition(n.cond(), bTrue, bFalse);
		}
		bTrue.mature();

		con.setCurrentBlock(bTrue);

		final Block oldBreak = con.breakBlock;
		con.breakBlock = bFalse;
		final Block oldContinue = con.continueBlock;
		con.continueBlock = bCond;
		if (label != null && con.labeledStmt == n) {
			con.labeledBreaks.put(label.toString(), bFalse);
			con.labeledContinues.put(label.toString(), bCond);
		}

		final Stmt body = n.body();
		visitAppropriate(body);

		assert con.breakBlock == bFalse;
		con.breakBlock = oldBreak;
		assert con.continueBlock == bCond;
		con.continueBlock = oldContinue;

		bFalse.mature();

		if (n.iters() != null) {
			for (ForUpdate f: n.iters()) {
				visitAppropriate(f);
			}
		}

		if (!con.getCurrentBlock().isBad())
			bCond.addPred(con.newJmp());

		bCond.mature();

		/* more fixup for X10 endless loop detection */
		if (bFalse.getPredCount() == 0) {
			con.setCurrentBlockBad();
		} else {
			con.setCurrentBlock(bFalse);
		}
	}

	@Override
	public void visit(final Conditional_c n) {

		// check if we have a constant condition
		if (n.cond().isConstant()) {
			@SuppressWarnings("boxing")
			final boolean cond = (Boolean)n.cond().constantValue().toJavaObject();
			if (cond) {
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
			public void genCode(final Block trueBlock, final Block falseBlock) {
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

		final Node ret = FirmCodeTemplate.genConditional(con, cond, trueExpr, falseExpr);
		setReturnNode(ret);
	}

	@Override
	public void visit(final If_c n) {

		final If_c ifAst = n;
		final CondTemplate cond = new CondTemplate() {
			@Override
			public void genCode(final Block trueBlock, final Block falseBlock) {
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
		if (n.alternative() != null) {
			Stmt alternative = n.alternative();
			if (alternative instanceof Block_c) {
				final Block_c block = (Block_c) alternative;
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

		FirmCodeTemplate.genIfStatement(con, cond, ifStmt, elseStmt);
	}

	@Override
	public void visit(final Empty_c n) {
		/* empty statements are irrelevant for Firm construction */
	}

	@Override
	public void visit(final Eval_c n) {
		/* Polyglot Eval captures an expression and is a statement.
		 * Just process the expression and throw away its value. */
		visitAppropriate(n.expr());
		resetReturnNode();
	}

	private void addToMapping(final ParameterTypeMapping ptm,
			final List<ParameterType> paramTypes, final List<Type> actualTypes) {
		for (int i = 0; i < paramTypes.size(); ++i) {
			Type t = actualTypes.get(i);
			if (x10TypeSystem.isParameterType(t))
				t = x10TypeSystem.getConcreteType(Types.baseType(t));

			ptm.add(paramTypes.get(i), Types.stripConstraints(t));
		}
	}

	@Override
	public void visit(final X10Call_c n) {
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
            assert actualTypes.size() == decl.typeParameters().size();

            // Watch out for recursive generic types.
            for (int i = 0; i < actualTypes.size(); i++) {
               actualTypes.set(i, x10TypeSystem.getConcreteType(actualTypes.get(i)));
            }

			final ParameterTypeMapping ptm = new ParameterTypeMapping();
			addToMapping(ptm, paramTypes, actualTypes);

			final X10ClassType ct = (X10ClassType) Types.stripConstraints(n.target().type());
			final X10ClassDef def = ct.def();

			// If this is a generic method defined inside a generic class,
			// also save the type mapping for the generic class.
			// We do not have to remember to instantiate this class
			// with the given type argument here, because this must have already
			// happened before when someone created the object that we call the
			// method on.
			if (!def.typeParameters().isEmpty()) {
				/*
				    static generic method calls of static generic classes will be handled as following:
					GeneriClass[T_i].genericMethod[U_j](...) ->
					GeneriClass.genericMethod[[U_j/"actualType"]](...)
					-> The T_i generic parameters of the generic class will not be mapped because the
					static generic method can`t use the T_i`s of the generic class. We would also get
					a serious problem, if one of the T_i`s will be equal to one of the U_j`s.
				*/

				/*
				   non static generic method calls of generic classes will be handled as following:
				   GenericClass[T_i].genericMethod[U_j](...) ->
				   GenericClass[T_i/"actualType"].genericMethod[[U_i/"actualType"]](...)
				   -> The T_i generic parameters of the generic class will be mapped with the actual types.
				*/

				if (!methodInstance.flags().isStatic()) {
					final List<ParameterType> cParamTypes = def.typeParameters();
					final List<Type> cActualTypes = ct.typeArguments();
					addToMapping(ptm, cParamTypes, cActualTypes);
				}
			}

			// Remember the parameter type configuration to generate code later.
			addToWorklist(new GenericNodeInstance(decl, ptm));
		}
		final Node ret = genX10Call(methodInstance, n.arguments(), n.target());
		setReturnNode(ret);
	}

	@Override
	public void visit(final X10ConstructorCall_c n) {
		/* determine called function */
		final X10ConstructorInstance instance = n.constructorInstance();
		final Entity entity = firmTypeSystem.getConstructorEntity(instance);
		final MethodType type = (MethodType) entity.getType();
		final Node address = con.newSymConst(entity);
		final List<Expr> arguments = wrapArguments(instance.formalTypes(), n.arguments());

		final int argumentCount = arguments.size() + 1;
		assert argumentCount == type.getNParams();
		final Node[] argumentNodes = new Node[argumentCount];
		int p = 0;
		argumentNodes[p++] = getThis();

		for (Expr expr : arguments) {
			argumentNodes[p++] = visitExpression(expr);
		}

		assert p == argumentCount;

		final Node mem = con.getCurrentMem();
		final Node call = con.newCall(mem, address, argumentNodes, type);
		final Node newMem = con.newProj(call, Mode.getM(), Call.pnM);

		con.setCurrentMem(newMem);
	}

	/**
	 * @param expr an X10 expression node
	 * @return a Firm node containing the result value of the expression
	 */
	public Node visitExpression(final Expr expr) {
		resetReturnNode();
		visitAppropriate(expr);
		return getReturnNode();
	}

	@Override
	public void visit(final Field_c n) {
		final FieldInstance instance = n.fieldInstance();
		final Node objectPointer;
		final Flags flags = instance.flags();
		if (flags.isStatic()) {
			objectPointer = null;
		} else {
			objectPointer = visitExpression((Expr)n.target());
		}
		final Node ret = genFieldLoad(objectPointer, instance);
		setReturnNode(ret);
	}

	/**
	 * Returns the appropriate sel node from the current frame for a given entity.
	 * @param entity The entity for which the sel node from the current frame should be returned
	 * @return The sel node for the given entity
	 */
	public Node getEntityFromCurrentFrame(final Entity entity) {
		final Node frame = con.getGraph().getFrame();
		final Node sel = con.newSel(frame, entity);
		return sel;
	}

	private Node getLocalValue(final LocalInstance loc) {
		final VarEntry var = con.getVarEntry(loc);

		if (var.getType() == VarEntry.STRUCT) {
			return getEntityFromCurrentFrame(var.getEntity());
		}
		final int idx = var.getIdx();
		final Type type = loc.type();
		final Mode mode = firmTypeSystem.getFirmMode(type);
		return con.getVariable(idx, mode);
	}

	@Override
	public void visit(final Local_c n) {
		final LocalInstance loc = n.localInstance();
		final Node node = getLocalValue(loc);
		setReturnNode(node);
	}

	private Node genAlloc(final firm.Type type, final ir_where_alloc where) {
		final Node mem = con.getCurrentMem();
		final Node count = con.newConst(1, Mode.getIu());
		final Node alloc = con.newAlloc(mem, count, type, where);
		final Node newMem = con.newProj(alloc, Mode.getM(), Alloc.pnM);
		final Node res = con.newProj(alloc, Mode.getP(), Alloc.pnRes);
		con.setCurrentMem(newMem);
		return res;
	}

	/**
	 * Create the appropriate firm nodes for a heap allocation.
	 * @param x10Type The x10 type of the object
	 * @return A proj node to the allocated memory.
	 */
	public Node genHeapAlloc(final Type x10Type) {
		final firm.Type firmType = firmTypeSystem.asClass(x10Type);
		return genAlloc(firmType, ir_where_alloc.heap_alloc);
	}

	/**
	 * Create the appropriate firm nodes for a stack allocation.
	 * @param x10Type The x10 type of the object
	 *
	 * @return A proj node to the allocated memory.
	 */
	public Node genStackAlloc(final Type x10Type) {
		final firm.Type firmType = firmTypeSystem.asClass(x10Type);
		return genAlloc(firmType, ir_where_alloc.stack_alloc);
	}

	private Node genConstructorCall(final X10ConstructorInstance instance,
			final Node[] arguments) {
		final Entity entity = firmTypeSystem.getConstructorEntity(instance);
		final firm.MethodType entityType = (MethodType) entity.getType();
		final Node address = con.newSymConst(entity);
		final Node mem = con.getCurrentMem();
		final Node call = con.newCall(mem, address, arguments, entityType);
		final Node newMem = con.newProj(call, Mode.getM(), Call.pnM);

		con.setCurrentMem(newMem);
		return call;
	}

	/**
	 * Generate the appropriate nodes for a constructor call.
	 * @param objectThisNode The this pointer for the constructor call (implicit first parameter)
	 *        may be null if no this pointer is necessary.
	 * @param instance The constructor instance
	 * @param args The arguments of the constructor call (without the implicit this pointer)
	 */
	private void genClassConstructorCall(final Node objectThisNode,
			final X10ConstructorInstance instance,
			final List<Expr> args) {
		final List<Expr> arguments = wrapArguments(instance.formalTypes(), args);
		final int        argumentCount = arguments.size() + 1;
		final Node[]     argumentNodes = new Node[argumentCount];

		int p = 0;
		argumentNodes[p++] = objectThisNode;

		for (final Expr arg : arguments) {
			argumentNodes[p++] = visitExpression(arg);
		}
		assert p == argumentNodes.length;

		genConstructorCall(instance, argumentNodes);
	}

	private Node genStructConstructorCall(final X10ConstructorInstance instance, final List<Expr> args) {
		final List<Expr> arguments = wrapArguments(instance.formalTypes(), args);
		final int argumentCount = arguments.size();
		final Node[] argumentNodes = new Node[argumentCount];
		int p = 0;
		for (final Expr arg : arguments) {
			argumentNodes[p++] = visitExpression(arg);
		}

		final Node call = genConstructorCall(instance, argumentNodes);
		final Node ress = con.newProj(call, Mode.getT(), Call.pnTResult);
		final Type resType = instance.returnType();
		final Mode mode = firmTypeSystem.getFirmMode(resType);
		final Node res  = con.newProj(ress, mode, 0);
		return res;
	}

	@Override
	public void visit(final New_c n) {
		final Type baseType = Types.baseType(n.objectType().type());
		final X10ClassType type = (X10ClassType)baseType;
		final X10ConstructorInstance constructor = n.constructorInstance();

		final boolean hasTypeArguments = type.typeArguments() != null && !type.typeArguments().isEmpty();

		if (hasTypeArguments) {
			// Find the class declaration.
			final ClassDeclFetcher fetcher = new ClassDeclFetcher(x10TypeSystem, xnf);
			final X10ClassDecl decl = fetcher.getDecl(n);

			// Construct type mapping.
			final X10ClassType ct = (X10ClassType) constructor.container();
			final List<ParameterType> paramTypes = ct.def().typeParameters();
			final List<Type> actualTypes = ct.typeArguments();
			assert actualTypes.size() == decl.typeParameters().size();
			final ParameterTypeMapping ptm = new ParameterTypeMapping();
			addToMapping(ptm, paramTypes, actualTypes);

			// Remember the parameter type configuration to generate code later.
			addToWorklist(new GenericNodeInstance(decl, ptm));
		}

		final List<Expr> arguments = n.arguments();
		if (!x10TypeSystem.isStructType0(n.type())) {
			final Node objectNode = genHeapAlloc(type);
			genClassConstructorCall(objectNode, constructor, arguments);
			setReturnNode(objectNode);
		} else {
			final Node result = genStructConstructorCall(constructor, arguments);
			setReturnNode(result);
		}
	}

	private TargetValue getFloatLitTargetValue(final FloatLit_c literal) {
		final Mode mode = firmTypeSystem.getFirmMode(literal.type());
		final double value = literal.value();
		return new TargetValue(value, mode);
	}

	@Override
	public void visit(final FloatLit_c literal) {
		final TargetValue targetValue = getFloatLitTargetValue(literal);
		final Node ret = con.newConst(targetValue);
		setReturnNode(ret);
	}

	private TargetValue getIntLitTarval(final IntLit_c literal) {
		final Mode mode = firmTypeSystem.getFirmMode(literal.type());
		final long value = literal.value();
		return new TargetValue(value, mode);
	}

	@Override
	public void visit(final IntLit_c n) {
		final TargetValue targetValue = getIntLitTarval(n);
		final Node ret = con.newConst(targetValue);
		setReturnNode(ret);
	}

	@Override
	public void visit(final NullLit_c n) {
		final Mode mode = firmTypeSystem.getFirmMode(n.type());
		final Node result = con.newConst(mode.getNull());
		setReturnNode(result);
	}

	private Entity createStringEntity(final String value) {
		final ClassType globalType = Program.getGlobalType();
		final firm.Type elemType = firmTypeSystem.asType(x10TypeSystem.Char());
		final ArrayType type = new ArrayType(1, elemType);

		final Ident id = Ident.createUnique("x10str.%u");
		final Entity ent = new Entity(globalType, id, type);
		ent.setLdIdent(id);

		ent.setVisibility(ir_visibility.ir_visibility_private);
		ent.addLinkage(ir_linkage.IR_LINKAGE_CONSTANT.val);

		type.setBounds(0, 0, value.length() - 1);
		type.setSizeBytes(value.length() * elemType.getSizeBytes());
		type.setTypeState(ir_type_state.layout_fixed);

		final Initializer init = new Initializer(value.length());
		final byte[] bytes = value.getBytes(UTF8);
		final Mode mode = elemType.getMode();
		for (int i = 0; i < bytes.length; ++i) {
			final TargetValue tv = new TargetValue(bytes[i], mode);
			final Initializer val = new Initializer(tv);
			init.setCompoundValue(i, val);
		}
		ent.setInitializer(init);

		return ent;
	}

	private X10ConstructorInstance getStringLiteralConstructor() {
		if (stringLiteralConstructor == null) {
			final X10ClassType classType = x10TypeSystem.String();
			for (ConstructorInstance constructor : classType.constructors()) {
				final List<Type> paramTypes = constructor.formalTypes();
				if (paramTypes.size() != 2)
					continue;
				if (!x10TypeSystem.isInt(paramTypes.get(0)))
					continue;
				if (!x10TypeSystem.isPointer(paramTypes.get(1)))
					continue;
				stringLiteralConstructor = (X10ConstructorInstance)constructor;
				break;
			}
			if (stringLiteralConstructor == null) {
				throw new CodeGenError("Couldn't find String.this(Int,Pointer):String constructor",
						Position.COMPILER_GENERATED);
			}
		}
		return stringLiteralConstructor;
	}

	private Node createStringLiteral(final String value) {
		/* Construct call to builtin function, which creates an X10 string struct. */
		final Entity entity = createStringEntity(value);

		/* search for String.this(Pointer,Int): String */
		final Type type = x10TypeSystem.String();
		final Node object = genHeapAlloc(type);
		final Mode sizeMode = firmTypeSystem.getFirmMode(x10TypeSystem.Int());
		final Node sizeNode = con.newConst(value.length(), sizeMode);
		final Node stringConst = con.newSymConst(entity);
		final Node[] constructorArguments = new Node[] {object, sizeNode, stringConst};
		final X10ConstructorInstance stringConstructor = getStringLiteralConstructor();
		genConstructorCall(stringConstructor, constructorArguments);

		return object;
	}

	@Override
	public void visit(final StringLit_c n) {
		setReturnNode(createStringLiteral(n.value()));
	}

	private TargetValue getCharLitTargetValue(final CharLit_c literal) {
		final Mode mode = firmTypeSystem.getFirmMode(literal.type());
		final long value = literal.value();
		return new TargetValue(value, mode);
	}

	@Override
	public void visit(final CharLit_c literal) {
		final TargetValue targetValue = getCharLitTargetValue(literal);
		final Node ret = con.newConst(targetValue);
		setReturnNode(ret);
	}

	private TargetValue getBooleanLitTargetValue(final BooleanLit_c literal) {
		final Mode mode = firmTypeSystem.getFirmMode(x10TypeSystem.Boolean());
		return literal.value() ? mode.getOne() : mode.getNull();
	}

	@Override
	public void visit(final BooleanLit_c literal) {
		final TargetValue targetValue = getBooleanLitTargetValue(literal);
		final Node ret = con.newConst(targetValue);
		setReturnNode(ret);
	}

	private Node getThis() {
		return getLocalValue(con.thisInstance);
	}

	@Override
	public void visit(final X10Special_c n) {
		if (n.kind() == Special.THIS) {
			final Node thisPointer = getThis();
			setReturnNode(thisPointer);
		} else {
			throw new CodeGenError("Special not implemented yet", n);
		}
	}

	@Override
	public void visit(final ClosureCall_c c) {
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
		if (!x10TypeSystem.typeDeepBaseEquals0(fType, expr.type(), x10Context)) {
			final Position pos = expr.position();
			Converter.ConversionType convType = Converter.ConversionType.UNCHECKED;

			if (x10TypeSystem.isSubtype(expr.type(), fType, x10Context)) {
				convType = Converter.ConversionType.SUBTYPE;
			}

			ret = xnf.X10Cast(pos, xnf.CanonicalTypeNode(pos, fType), expr, convType).type(fType);
        }
		return ret;
	}

	private Expr wrapArgument(final Type fType, final Expr arg) {
		Expr ret = arg;
		if (!x10TypeSystem.typeEquals0(fType, arg.type(), x10Context))
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
		assert formalTypes.size() == args.size();
		final List<Expr> ret = new LinkedList<Expr>();

		int i = 0;
		for (final Expr arg : args) {
		    final Type fType = formalTypes.get(i);

		    final Expr wrappedArg = wrapArgument(fType, arg);

		    ret.add(wrappedArg);
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
	private Node genX10Call(final MethodInstance mi, final List<Expr> args, final Receiver target) {
		final Flags flags = mi.flags();
		final boolean isStatic = flags.isStatic();
		final boolean isFinal  = flags.isFinal();
		final boolean isStruct = x10TypeSystem.isStructType0(mi.container());
		final boolean isStaticBinding = (isStatic || isFinal || isStruct);
		final Entity entity = firmTypeSystem.getMethodEntity(mi);

		final MethodType type = (MethodType) entity.getType();
		final int paramCount = type.getNParams();

		final List<Expr> arguments = new LinkedList<Expr>();

		// add the other arguments
		arguments.addAll(wrapArguments(mi.formalTypes(), args));

		// add implicit this pointer
		if (!isStatic) {
			assert target != null && target instanceof Expr : mi.toString();
			final Expr receiver = (Expr)target;
			arguments.add(0, wrapArgument(mi.container(), receiver));
		}

		assert arguments.size() == paramCount : "parameters are off : " + arguments.size() + " vs " + paramCount;
		final Node[] parameters = new Node[paramCount];

		for (int i = 0; i < paramCount; i++) {
			parameters[i] = visitExpression(arguments.get(i));
		}

		final Node address = (isStaticBinding) ? con.newSymConst(entity) : con.newSel(parameters[0], entity);

		final Node mem = con.getCurrentMem();
		final Node call = con.newCall(mem, address, parameters, type);
		final Node newMem = con.newProj(call, Mode.getM(), Call.pnM);
		con.setCurrentMem(newMem);

		if (type.getNRess() == 0) {
			return null; /* no return value, we're done */
		}

		assert type.getNRess() == 1; /* X10 does not support multiple return values */

		final firm.Type retType = type.getResType(0);
		final Node allResults = con.newProj(call, Mode.getT(), Call.pnTResult);
		Mode mode = retType.getMode();

		if (mode == null) {
			/* classes do not have modes assigned, use pointer mode */
			mode = Mode.getP();
		}

		final Node ret = con.newProj(allResults, mode, 0);

		return ret;
	}

	@Override
	public void visit(final X10Binary_c b) {
		final Node n = produceBooleanValue(b);
		setReturnNode(n);
	}

	@Override
	public void visit(final Binary_c b) {
		final Node n = produceBooleanValue(b);
		setReturnNode(n);
	}

	@Override
	public void visit(final AssignPropertyCall_c n) {
		/* Properties can only be called in a constructor; so we can generate the following
		 * simple code for a property "property(a,b,c,..)" ->
		 * this->a = a;
		 * this->b = b;
		 * this->c = c;
		 * ...
		 */
		final List<X10FieldInstance> properties = n.properties();
		final List<Expr> args = n.arguments();
		assert properties.size() == args.size();

		final Node thisPointer = getThis();
		for (int i = 0; i < properties.size(); i++) {
			final FieldInstance field = properties.get(i);
			final Expr expr = args.get(i);
			final Node node = uncheckedCast(expr, field.type(), n.position());
			genFieldInstanceAssign(thisPointer, field, node);
		}
	}

	/**
	 * Initializes a given boxing type -> creates methods etc.
	 * @param boxedType The type of the boxed field
	 * @param boxType The boxing type which should be initialized
	 */
	private void initBoxingType(final X10ClassType boxedType, final X10ClassType boxType) {

		final FieldInstance boxedField = boxType.fieldNamed(Name.make(FirmTypeSystem.BOXED_VALUE));
		assert boxedField != null;

		final Position pos = Position.COMPILER_GENERATED;
		for (final MethodInstance m : boxType.methods()) {
			final Flags flags = m.flags();
			final Entity entity = firmTypeSystem.getMethodEntity(m);

	        final List<Stmt> statements = new ArrayList<Stmt>();

	        /* We will generate the following code
	         *
	         * def BoxingType:"MethodName"(param1, param2, param3, ...) {
	         *    return this.boxValue."MethodName"(param1, param2, param3, ...);
	         * }
	         *
	         * To avoid unnecessary dynamic delegation calls we can and will do a static method call on the boxed field.
	         */

	        final Type thisType = flags.isStatic() ? null : boxType;
			final MethodConstruction savedConstruction = initConstruction(entity,
					m.formalNames(), new LinkedList<LocalInstance>(),
					m.returnType(), thisType);

	        // The receiver of the delegated method call -> the boxed value
			final Id id = xnf.Id(pos, boxedField.name());
			final Expr typeExpr = xnf.This(pos).type(boxType);
	        final Expr bxdField = xnf.Field(pos, typeExpr, id).fieldInstance(boxedField).type(boxedType);

	        // the arguments.
	        final List<Expr> args = new LinkedList<Expr>();
			for (final LocalInstance loc : m.formalNames()) {
				final Expr rval = xnf.Local(pos, xnf.Id(pos, loc.name())).localInstance(loc).type(loc.type());
				args.add(rval);
			}
			// find the appropriate method instance (concrete method) -> to
			// avoid unnecessary dynamic delegation calls.
			MethodInstance method = null;
			for (final MethodInstance meth : boxedType.methods(m.name(), m.formalTypes(), x10Context)) {
				if (meth.isSameMethod(m, x10Context)) {
					method = meth;
					break;
				}
			}

	        assert method != null;
			@SuppressWarnings("null")
			final Name imName = method.name();

	        // create the call
			final Id imID = xnf.Id(pos, imName);
			final List<TypeNode> typeArgs = Collections.<TypeNode>emptyList();
			final Expr call = xnf.X10Call(pos, bxdField, imID, typeArgs, args)
					.methodInstance(method).type(m.returnType());

			// append an optional return
			if (method.returnType() != x10TypeSystem.Void()) {
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

	/** Holds initialized boxing types -> boxing types will be inited only once. */
	private static Set<Type> initedBoxingTypes = new HashSet<Type>();

	/** Returns the type used when boxing values of type @p type. */
	public X10ClassType getBoxingType(final X10ClassType type) {
		final X10ClassType boxType = firmTypeSystem.getBoxingType(type);

		if (!initedBoxingTypes.contains(boxType)) {
			// init the boxing type only once
			initBoxingType(type, boxType);
			initedBoxingTypes.add(boxType);
		}

		return boxType;
	}

	/**
	 * Creates the appropriate firm graph for an autoboxing.
	 */
	private Node genBoxing(final Expr value) {
		final X10ClassType type = x10TypeSystem.toClass(value.type());
		final X10ClassType boxType = getBoxingType(type);

		// Generate the box
		final Node box = genHeapAlloc(boxType);

		// save the boxed value in the box
		final FieldInstance boxValue = boxType.fieldNamed(Name.make(FirmTypeSystem.BOXED_VALUE));
		final Node valueNode = visitExpression(value);
		genFieldInstanceAssign(box, boxValue, valueNode);

		return box;
	}

	private Node genUnboxing(final Node value, final X10ClassType toType) {
		final X10ClassType boxType = getBoxingType(toType);
		final FieldInstance boxValue = boxType.fieldNamed(Name.make(FirmTypeSystem.BOXED_VALUE));
		final Node boxedValue = genFieldLoad(value, boxValue);
		return boxedValue;
	}

	/**
	 * Returns a throw statement with the given text message.
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
	 * Generates firm code for sub type checks.
	 * @param node The node which should be checked
	 * @param fromType The from type
	 * @param toType The to type
	 */
	void genSubtypeCheck(final Node node, final Type fromType, final Type toType) {

		final Type from = x10TypeSystem.getConcreteType(fromType);
		final Type to   = x10TypeSystem.getConcreteType(toType);

		assert to instanceof X10ClassType;
		final Type compType = x10TypeSystem.isStructType0(to) ? firmTypeSystem.getBoxingType((X10ClassType)to) : to;

		final CondTemplate condTemplate = new CondTemplate() {
			@Override
			public void genCode(final Block trueBlock, final Block falseBlock) {
				final Node ret = ConditionEvaluationCodeGenerator.genInstanceOf(
						node, from, compType, FirmGenerator.this, x10TypeSystem, firmTypeSystem, con);
				ConditionEvaluationCodeGenerator.makeJumps(ret, falseBlock, trueBlock, con);
			}
		};

		final StmtTemplate ifStmt = new StmtTemplate() {
			@Override
			public void genCode() {
				final Stmt throwStmt = getThrowNewExceptionStmt(x10TypeSystem.ClassCastException(),
						"Cannot cast " + from + " to " + to);
				visitAppropriate(throwStmt);
			}
		};

		FirmCodeTemplate.genIfStatement(con, condTemplate, ifStmt, null);
	}

	private void genCastNullCheck(final Node node, final Type t) {

		final Type type = x10TypeSystem.getConcreteType(t);

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

		FirmCodeTemplate.genIfStatement(con, condTemplate, ifStmt, null);
	}

	private Node genCheckedRefToRefCast(final Expr expr, final Type fromType, final Type toType) {
		final Type from = x10TypeSystem.getConcreteType(fromType);
		final Type to   = x10TypeSystem.getConcreteType(toType);
		final Node node = visitExpression(expr);

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
				genSubtypeCheck(node, from, to);
				return node;
			}
		};

		return FirmCodeTemplate.genConditional(con, cond, trueExpr, falseExpr);
	}

	private Node checkedCast(final Expr value, final Type to, final Position pos) {
		/* shortcut */
		final Type from = x10TypeSystem.getConcreteType(value.type());
		if (x10TypeSystem.typeEquals0(from, to, x10Context)) {
			return visitExpression(value);
		}

		if (x10TypeSystem.isRefType(from) && x10TypeSystem.isRefType(to)) {
			return genCheckedRefToRefCast(value, from, to);
		} else if (x10TypeSystem.isRefType(from) && x10TypeSystem.isStructType0(to)) {
			/* unboxing */
			final Node valueNode = visitExpression(value);
			genCastNullCheck(valueNode, from);
			genSubtypeCheck(valueNode, from, to);
			return genUnboxing(valueNode, x10TypeSystem.toClass(to));
		} else {
			throw new CodeGenError("Unsupported cast", pos);
		}
	}

	private Node uncheckedCast(final Expr value, final Type to, final Position pos) {
		final Type from = x10TypeSystem.getConcreteType(value.type());
		/* shortcut */
		if (x10TypeSystem.typeEquals0(from, to, x10Context)) {
			return visitExpression(value);
		}

		if (x10TypeSystem.isRefType(from) && x10TypeSystem.isRefType(to)) {
			return visitExpression(value);
		} else if (x10TypeSystem.isStructType0(from) && x10TypeSystem.isRefType(to)) {
			return genBoxing(value);
		} else if (x10TypeSystem.isRefType(from) && x10TypeSystem.isStructType0(to)) {
			final Node valueNode = visitExpression(value);
			return genUnboxing(valueNode, x10TypeSystem.toClass(to));
		} else {
			throw new CodeGenError("Unsupported unchecked cast", pos);
		}
	}

	@Override
	public void visit(final X10Cast_c c) {
		final Expr arg = c.expr();
		final TypeNode tn = c.castType();
		final Type to = x10TypeSystem.getConcreteType(tn.type());

		final Node ret;
		final ConversionType conversionType = c.conversionType();
		if (conversionType == ConversionType.UNCHECKED || conversionType == ConversionType.SUBTYPE) {
			ret = uncheckedCast(arg, to, c.position());
		} else if (conversionType == ConversionType.CHECKED) {
			ret = checkedCast(arg, to, c.position());
		} else {
			throw new CodeGenError("Unsupported cast type: " + conversionType, c);
		}
		setReturnNode(ret);
	}

	@Override
	public void visit(final X10Instanceof_c n) {
		final Node node = produceBooleanValue(n);
		setReturnNode(node);
	}

	@Override
	public void visit(final SubtypeTest_c n) {
		final Type subType = n.subtype().type();
		final Type superType = n.supertype().type();
		final Mode mode = firmTypeSystem.getFirmMode(x10TypeSystem.Boolean());
		final boolean res;

		if (n.equals()) {
			res = x10TypeSystem.typeBaseEquals(subType, superType, x10Context);
		} else {
			res = x10TypeSystem.isSubtype(subType, superType);
		}

		setReturnNode(con.newConst(res ? mode.getOne() : mode.getNull()));
	}

	@Override
	public void visit(final ParExpr_c n) {
		visitAppropriate(n.expr());
	}

	@Override
	public void visit(final TypeDecl_c n) {
		// DO NOTHING
	}

	@Override
	public void visit(final LocalTypeDef_c n) {
		// DO NOTHING
	}

	@Override
	public void visit(final Assert_c n) {
		if (!options.assertions) {
			setReturnNode(null);
			return;
		}

		final Node cond = visitExpression(n.cond());

		final Node errMsg;
		if (n.errorMessage() != null) {
			errMsg = visitExpression(n.errorMessage());
		} else {
			errMsg = con.newConst(0, firmTypeSystem.getFirmMode(x10TypeSystem.String()));
		}

		final Node position;
		if (n.position() != null) {
			position = createStringLiteral(n.position().nameAndLineString());
		} else {
			position = con.newConst(0, firmTypeSystem.getFirmMode(x10TypeSystem.String()));
		}

		final firm.Type[] parameterTypes = new firm.Type[] {
			firmTypeSystem.asType(x10TypeSystem.Boolean()),
			firmTypeSystem.asType(x10TypeSystem.String()),
			firmTypeSystem.asType(x10TypeSystem.String()),
		};
		final firm.Type[] resultTypes = new firm.Type[] {};
		final MethodType type = new firm.MethodType(parameterTypes, resultTypes);
		final String name = NameMangler.mangleKnownName(X10_ASSERT);
		final Entity funcEnt = new Entity(Program.getGlobalType(), name, type);
		final Node address = con.newSymConst(funcEnt);

		final Node[] parameters = new Node[] {cond, errMsg, position};
		final Node mem = con.getCurrentMem();
		final Node call = con.newCall(mem, address, parameters, type);
		final Node newMem = con.newProj(call, Mode.getM(), Call.pnM);
		con.setCurrentMem(newMem);

		setReturnNode(call);
	}

	@Override
	public void visit(final Initializer_c n) {
		if (n.flags().flags().isStatic()) {
			staticInitBlocks.add(n);
		} else {
			throw new CodeGenError("Non-static initializer not implemented yet", n);
		}
	}

	/**
	 * Just a stub implementation for now.
	 */
	@Override
	public void visit(final Throw_c n) {
		final firm.Type[] parameterTypes = new firm.Type[0];
		final firm.Type[] resultTypes = new firm.Type[0];
		final MethodType type = new firm.MethodType(parameterTypes, resultTypes);
		final String name = NameMangler.mangleKnownName(X10_THROW_STUB);
		final Entity funcEnt = new Entity(Program.getGlobalType(), name, type);
		final Node address = con.newSymConst(funcEnt);

		final Node[] parameters = new Node[0];
		final Node mem = con.getCurrentMem();
		final Node call = con.newCall(mem, address, parameters, type);
		final Node newMem = con.newProj(call, Mode.getM(), Call.pnM);
		con.setCurrentMem(newMem);

		con.getGraph().keepAlive(call);
		con.getGraph().keepAlive(con.getCurrentBlock());
		con.setCurrentBlockBad();
	}

	@Override
	public void visit(final PropertyDecl_c n) {
		throw new CodeGenError("Not implemented yet", n);
	}

	@Override
	public void visit(final Formal_c n) {
		throw new CodeGenError("Not implemented yet", n);
	}

	@Override
	public void visit(final X10CanonicalTypeNode_c n) {
		throw new CodeGenError("Not implemented yet", n);
	}

	@Override
	public void visit(final Id_c n) {
		throw new CodeGenError("Not implemented yet", n);
	}

	@Override
	public void visit(final Try_c n) {
		/* no exception handling yet, just build contents of try block,
		 * ignore later catch blocks */
		final polyglot.ast.Block block = n.tryBlock();
		visitAppropriate(block);
		final polyglot.ast.Block finallyBlock = n.finallyBlock();
		if (finallyBlock != null)
			visitAppropriate(finallyBlock);
	}

	@Override
	public void visit(final Catch_c n) {
		/* ignore catch blocks for now */
	}

	@Override
	public void visit(final Atomic_c a) {
		throw new CodeGenError("Not implemented yet", a);
	}

	@Override
	public void visit(final Next_c n) {
		throw new CodeGenError("Not implemented yet", n);
	}

	@Override
	public void visit(final ForLoop_c n) {
		throw new CodeGenError("Not implemented yet", n);
	}

	@Override
	public void visit(final AtEach_c n) {
		throw new CodeGenError("Not implemented yet", n);
	}

	@Override
	public void visit(final Finish_c n) {
		throw new CodeGenError("Not implemented yet", n);
	}

	@Override
	public void visit(final ArrayAccess_c n) {
		throw new CodeGenError("Not implemented yet", n);
	}

	@Override
	public void visit(final Here_c n) {
		throw new CodeGenError("Not implemented yet", n);
	}

	@Override
	public void visit(final Async_c n) {
		throw new CodeGenError("Not implemented yet", n);
	}

	@Override
	public void visit(final Tuple_c n) {
		final Type concreteType = x10TypeSystem.getConcreteType(n.type());
		if (!concreteType.fullName().toString().equals("x10.array.Array"))
			throw new CodeGenError("Tuple does not have Array-Type", n);
		if (!(concreteType instanceof X10ClassType))
			throw new CodeGenError("Tuple type is not a class type", n);
		final X10ClassType classType = (X10ClassType) concreteType;
		final Type elementType = classType.typeArguments().get(0);
		final firm.Type firmType = firmTypeSystem.asType(elementType);

		final List<Expr> arguments = n.arguments();
		final int size = arguments.size();
		final Node mem = con.getCurrentMem();
		final Node count = con.newConst(size, Mode.getIu());
		final Node alloc = con.newAlloc(mem, count, firmType, ir_where_alloc.heap_alloc);
		final Node newMem = con.newProj(alloc, Mode.getM(), Alloc.pnM);
		final Node baseAddr = con.newProj(alloc, Mode.getP(), Alloc.pnRes);
		con.setCurrentMem(newMem);

		/* construct elements */
		final int elementSize = firmType.getSizeBytes();
		for (int i = 0; i < size; ++i) {
			final Expr expr = arguments.get(i);
			Node addr = baseAddr;
			if (i > 0) {
				final int offset = elementSize * i;
				final Node offsetC = con.newConst(offset, Mode.getIu());
				addr = con.newAdd(baseAddr, offsetC, Mode.getP());
			}
			final Node node = uncheckedCast(expr, elementType, n.position());
			assignToAddress(addr, elementType, node);
		}

		/* construct Array object */

		/* search for this(Pointer,Int) */
		X10ConstructorInstance arrayConstructor = null;
		for (final ConstructorInstance constructor : classType.constructors()) {
			final List<Type> paramTypes = constructor.formalTypes();
			if (paramTypes.size() != 2)
				continue;
			if (!x10TypeSystem.isPointer(paramTypes.get(0)))
				continue;
			if (!x10TypeSystem.isInt(paramTypes.get(1)))
				continue;
			arrayConstructor = (X10ConstructorInstance)constructor;
			break;
		}
		if (arrayConstructor == null) {
			throw new CodeGenError("Couldn't find Array.this(Pointer,Int) constructor", n);
		}
		final Node arrayAddr = genHeapAlloc(concreteType);
		final Mode sizeMode = firmTypeSystem.getFirmMode(x10TypeSystem.Int());
		final Node sizeNode = con.newConst(size, sizeMode);
		final Node[] constructorArguments = new Node[] {arrayAddr, baseAddr, sizeNode};
		genConstructorCall(arrayConstructor, constructorArguments);

		setReturnNode(arrayAddr);
	}

	@Override
	public void visit(final Allocation_c n) {
		/* the frontend seems to only build this node type with -OPTIMIZE */
		final Type baseType = Types.baseType(n.objectType().type());
		final X10ClassType type = (X10ClassType)baseType;

		Node objectNode;
		if (x10TypeSystem.isStructType0(n.type())) {
			objectNode = genStackAlloc(type);
		} else {
			objectNode = genHeapAlloc(type);
		}

		setReturnNode(objectNode);
	}

	private static void throwNotLoweredException(final polyglot.ast.Node n) {
		throw new CodeGenError("Node should have been lowered earlier", n);
	}

	@Override
	public void visit(final Closure_c n) {
		throwNotLoweredException(n);
	}

	@Override
	public void visit(final LocalClassDecl_c n) {
		throwNotLoweredException(n);
	}

	@Override
	public void visit(final X10Unary_c n) {
		throwNotLoweredException(n);
	}

	@Override
	public void visit(final Unary_c n) {
		throwNotLoweredException(n);
	}

	@Override
	public void visit(final ArrayInit_c n) {
		throwNotLoweredException(n);
	}

	@Override
	public void visit(final SettableAssign_c n) {
		throwNotLoweredException(n);
	}

	@Override
	public void visit(final When_c n) {
		throwNotLoweredException(n);
	}

	@Override
	public void visit(final AtStmt_c n) {
		throw new CodeGenError("At statements are deprecated", n);
	}

	@Override
	public void visit(final AtExpr_c n) {
		throwNotLoweredException(n);
	}

	@Override
	public void visit(final PackageNode_c n) {
		throwNotLoweredException(n);
	}

	@Override
	public void visit(final Import_c n) {
		throwNotLoweredException(n);
	}

	/** Returns current construction object. */
	public MethodConstruction getFirmConstruction() {
		return con;
	}

	/** Returns compiler options. */
	public CompilerOptions getOptions() {
		return options;
	}

	/** Returns current X10 Type System. */
	public GenericTypeSystem getX10TypeSystem() {
		return x10TypeSystem;
	}

	/** Returns current node factory. */
	public X10NodeFactory_c getNodeFactory() {
		return xnf;
	}

	/** Returns FIRM type system. */
	public FirmTypeSystem getFirmTypeSystem() {
		return firmTypeSystem;
	}
}
