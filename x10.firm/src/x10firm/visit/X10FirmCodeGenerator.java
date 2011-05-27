package x10firm.visit;

import java.util.ArrayList;
import java.util.Collections;
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
import polyglot.ast.Formal;
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
import polyglot.types.ContainerType;
import polyglot.types.FieldDef;
import polyglot.types.FieldInstance;
import polyglot.types.Flags;
import polyglot.types.LocalInstance;
import polyglot.types.MethodDef;
import polyglot.types.Name;
import polyglot.types.Ref;
import polyglot.types.Type;
import polyglot.types.TypeObject;
import polyglot.types.Types;
import polyglot.util.CollectionUtil;
import polyglot.util.InternalCompilerError;
import polyglot.util.Position;
import polyglot.visit.NodeVisitor;
import polyglot.visit.Translator;
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
import x10.ast.TypeParamNode;
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
import x10.ast.X10MethodDecl_c;
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
import x10.types.X10Context_c;
import x10.types.X10FieldInstance;
import x10.types.X10MethodDef;
import x10.types.X10ProcedureInstance;
import x10.types.checker.Converter;
import x10.visit.TypeParamSubstTransformer;
import x10.visit.X10DelegatingVisitor;
import x10c.types.X10CTypeSystem_c;
import x10firm.types.FirmTypeSystem;
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
import firm.Relation;
import firm.TargetValue;
import firm.bindings.binding_ircons.ir_linkage;
import firm.bindings.binding_ircons.ir_where_alloc;
import firm.bindings.binding_oo.ddispatch_binding;
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

	/** The current firm construction object */
	private OOConstruction con;

	/** To return Firm nodes for constructing expressions */
	private Node returnNode;

	/** X10 Context */
	private X10Context_c x10Context = null;

	/** Our firm type system */
	private final FirmTypeSystem firmTypeSystem;

	/** The X10 type system */
	private final X10CTypeSystem_c x10TypeSystem;

	/** Our node factory */
	private final X10NodeFactory_c xnf;

	/** Our own AST query */
	private final X10ASTQuery query;

	/** Mapping between MethodDefs and firm entities. */
	private final HashMap<MethodDef, Entity> methodEntities = new HashMap<MethodDef, Entity>();
	/** Mapping between X10ConstructorDefs and firm entities */
	private final HashMap<X10ConstructorDef, Entity> constructorEntities = new HashMap<X10ConstructorDef, Entity>();

	/** current firm context */
	private X10FirmContext firmContext = new X10FirmContext();

	private void evaluateCondition(final Expr e, final Block trueBlock, final Block falseBlock) {
		ConditionEvaluationCodeGenerator codegen
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

	/**
	 * Calculates a unique mapping between local instances and firm entities.
	 * @param locals A list with local instances
	 * @return The unique mapping between local instances and firm enities.
	 */
	private Map<LocalInstance, Entity> calculatEntityMappingForLocals(final List<LocalInstance> locals) {
		Map<LocalInstance, Entity> map = new HashMap<LocalInstance, Entity>();
		final firm.Type frameType = con.getGraph().getFrameType();
		for(LocalInstance loc : locals) {
			if(needEntityForLocalInstance(loc) && !map.containsKey(loc)) {
				Entity ent = new Entity(frameType, loc.name().toString(), firmTypeSystem.asFirmCoreType(loc.type()));
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

	/**
	 * Constructor for creating a new X10FirmCodeGenerator
	 *
	 * @param compiler The main compiler
	 * @param firmTypeSystem The FIRM type system
	 * @param x10TypeSystem The X10 type system
	 */
	public X10FirmCodeGenerator(final Compiler compiler,
			final FirmTypeSystem firmTypeSystem,
			final X10CTypeSystem_c x10TypeSystem,
			final X10NodeFactory_c nodeFactory,
			final Translator translator) {

		this.firmTypeSystem = firmTypeSystem;
		this.x10TypeSystem = x10TypeSystem;
		this.xnf = nodeFactory;
		this.query      = new X10ASTQuery(translator);
		this.x10Context = new X10Context_c(x10TypeSystem);

		X10NameMangler.setup(x10TypeSystem);
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
		final X10ClassDef def = n.classDef();
		final X10ClassType classType = def.asType();

		final X10FirmContext newFirmContext = new X10FirmContext();
		firmContext = firmContext.pushFirmContext(newFirmContext);

		firmContext.setCurClass(classType);

		if(classType.flags().isInterface()) {
			// NOTHING TO DO
		} else if(classType.isX10Struct()) {
			visitStruct(n);
		} else {
			visitClass(n);
		}

		firmContext = firmContext.popFirmContext();
	}
	
	private void createStructTypeNameMethodBody(final X10ClassDecl clazz, final MethodDecl_c meth) {
		X10MethodDef def              = (X10MethodDef)meth.methodDef();
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
        
        final Entity entity = getMethodEntity(methInstance);

        final OOConstruction savedConstruction = initConstruction(entity, methInstance.formalNames(), 
        		new LinkedList<LocalInstance>(),
				def.flags().isStatic(), methInstance, clazz.classDef().asType());
        
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

			for (ClassMember member : body.members()) {
				/* DELETE ME START: "following methods are not supported yet" */
				if(member instanceof MethodDecl_c) {
					final MethodDecl_c meth = (MethodDecl_c)member;
					final X10MethodDef def              = (X10MethodDef)meth.methodDef();
					final MethodInstance methodInstance = def.asInstance();
					final String name = methodInstance.name().toString();
					
					if(name.equals("typeName") && def.formalNames().size() == 0) {
						createStructTypeNameMethodBody(n, meth);
						continue;
					}
					
					if(name.equals("toString")) {
						continue;
					}
				}
				
				/* DELETE ME END: */
				visitAppropriate(member);
			}
		}
	}

	private void visitClass(X10ClassDecl n) {

		final ClassBody body = n.body();
		final List<ClassMember> members = body.members();
		if(!members.isEmpty()) {
			final List<ClassMember> inits = query.extractInits(members);
			firmContext.setInitClassMembers(inits);

			for (ClassMember member : body.members())
				visitAppropriate(member);
		}
	}

	private Entity getConstructorEntity(X10ConstructorInstance instance) {
		Entity entity = constructorEntities.get(instance.x10Def());
		if (entity == null) {
			final String name = X10NameMangler.mangleTypeObjectWithDefClass(instance);
			final Flags flags = instance.flags();

			final firm.Type type      = firmTypeSystem.asFirmType(instance);

			entity = new Entity(Program.getGlobalType(), name, type);
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

			constructorEntities.put(instance.x10Def(), entity);
		}
		return entity;
	}

	/**
	 * Returns the firm entity of a method which a given method instance maybe overwrites.
	 * @param instance The method instance which should be checked
	 * @return The set of the appropriate firm entities
	 */
	private Set<Entity> getMethodOverride(MethodInstance instance) {
		final Flags flags = instance.flags();
		// static methods can`t override other methods.
		if(flags.isStatic() || flags.isAbstract()) return Collections.<Entity>emptySet();

		final List<MethodInstance> overrides = new LinkedList<MethodInstance>();
		
		overrides.addAll(instance.implemented(x10Context));
		overrides.addAll(instance.overrides(x10Context));
		
		final Set<Entity> ret = new HashSet<Entity>();
		
		final ContainerType me_cont = instance.container();
		for(final MethodInstance meth: overrides) {
			if(x10TypeSystem.equals((TypeObject)me_cont, (TypeObject)meth.container())) continue;
			final Entity entity = getMethodEntity(meth); 
			ret.add(entity);
		}
		
		return ret;
	}

	/**
	 * Return entity for an X10 method
	 */
	private Entity getMethodEntity(final MethodInstance instance) {
		Entity entity = methodEntities.get(instance.def());
		if (entity == null) {
			final X10ClassType owner = (X10ClassType) instance.container();
			final String nameWithoutDefiningClass = X10NameMangler.mangleTypeObjectWithoutDefClass(instance);
			final String nameWithDefiningClass = X10NameMangler.mangleTypeObjectWithDefClass(instance);

			final Flags flags = instance.flags();

			final firm.Type owningClass = firmTypeSystem.asFirmCoreType(owner);
			final firm.Type ownerFirm = flags.isStatic() ? Program.getGlobalType() : owningClass;
			final firm.Type type = firmTypeSystem.asFirmType(instance);
			entity = new Entity(ownerFirm, nameWithoutDefiningClass, type);
			entity.setLdIdent(nameWithDefiningClass);

			if (flags.isStatic()) {
				OO.setEntityBinding(entity, ddispatch_binding.bind_static);
			} else if (owner.flags().isInterface()) {
				OO.setEntityBinding(entity, ddispatch_binding.bind_interface);
			} else if(x10TypeSystem.isStructType(owner)) {
				// struct methods needn`t be dynamic
				OO.setEntityBinding(entity, ddispatch_binding.bind_static);
			} else {
				OO.setEntityBinding(entity, ddispatch_binding.bind_dynamic);
			}

			if (flags.isAbstract()) {
				OO.setMethodAbstract(entity, true);
			}
			if (flags.isNative()) {
				entity.setVisibility(ir_visibility.ir_visibility_external);
			}

			for(final Entity overwrite: getMethodOverride(instance))
				entity.addEntityOverwrites(overwrite);

			methodEntities.put(instance.def(), entity);
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
	 * @param entity The method entities for which the a new construction should be inited.
	 * @param formals The formals of the given method entity
	 * @param locals The locals of the given method entity
	 * @param isStatic True if the method is static
	 * @param proc The procedure instance
	 * @param The owner of the procedure
	 * @return A reference to the current (saved) construction
	 */
	private OOConstruction initConstruction(final Entity entity, final List<LocalInstance> formals,
			final List<LocalInstance> locals, final boolean isStatic, final X10ProcedureInstance<?> proc, final X10ClassType owner) {
		final int nVars = formals.size() + locals.size() + (isStatic ? 0 : 1);

		final Graph graph = new Graph(entity, nVars);
		final OOConstruction savedConstruction = con;
		con = new OOConstruction(graph);

		X10FirmContext newFirmContext = new X10FirmContext();

		final Map<LocalInstance, Entity> map = calculatEntityMappingForLocals(locals);

		newFirmContext.setCurProcedure(proc);
		newFirmContext.setCurClass(owner);

		firmContext = firmContext.pushFirmContext(newFirmContext);

		final Node args = graph.getArgs();
		if(!isStatic) {
			final firm.Type ownerFirm = firmTypeSystem.asFirmType(owner);

			/* map 'this' */
			final Node projThis = con.newProj(args, ownerFirm.getMode(), 0);
			con.setVariable(0, projThis);
		}

		int idx = isStatic ? 0 : 1;

		// init and map all parameters.
		for (LocalInstance loc : formals) {
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
		for (LocalInstance loc : locals) {
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
	private void finishConstruction(Entity entity, OOConstruction savedConstruction) {
		// create Return node if there was no explicit return statement yet
		if (!con.getCurrentBlock().isBad()) {
			assert((MethodType)entity.getType()).getNRess() == 0;
			Node mem = con.getCurrentMem();
			Node ret = con.newReturn(mem, new Node[0]);
			con.getGraph().getEndBlock().addPred(ret);
		}

		con.finish();

		con = savedConstruction;

		firmContext = firmContext.popFirmContext();
	}

	private void constructGraph(final Entity entity, final CodeBlock code, final List<LocalInstance> formals,
			final List<LocalInstance> locals, final boolean isStatic, final X10ProcedureInstance<?> proc, final X10ClassType owner) {

		OOConstruction savedConstruction = initConstruction(entity, formals, locals, isStatic, proc, owner);

		// Walk body and construct graph
		visitAppropriate(code.body());

		finishConstruction(entity, savedConstruction);
	}

	@Override
	public void visit(MethodDecl_c dec) {
		final X10MethodDef def = (X10MethodDef) dec.methodDef();

		final MethodInstance methodInstance = def.asInstance();

		for (Type typeParam : methodInstance.typeParameters())
			if (typeParam instanceof ParameterType)
				return;

		final Entity         entity         = getMethodEntity(methodInstance);
		final Flags          flags          = methodInstance.flags();

		if (flags.isNative() || flags.isAbstract()) {
			// native code is defined elsewhere, so nothing left to do
			return;
		}

		final List<LocalInstance> formals = methodInstance.formalNames();
		final boolean isStatic = flags.isStatic();
		final X10ClassType owner = (X10ClassType) methodInstance.container();

		// extract all formals and locals from the method.
		final List<LocalInstance> locals = getAllLocalInstancesInCodeBlock(dec);
		constructGraph(entity, dec, formals, locals, isStatic, methodInstance, owner);

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
		final Entity                 entity   = getConstructorEntity(instance);

		if (flags.isNative()) {
			/* native code is defined elsewhere, so nothing left to do */
			return;
		}

		final List<LocalInstance> formals = instance.formalNames();
		final boolean isStatic = flags.isStatic();
		final X10ClassType owner = (X10ClassType) instance.container();

		// extract all formals and locals from the method.
		final List<LocalInstance> locals = getAllLocalInstancesInCodeBlock(dec);
		final List<ClassMember> initClassMembers = firmContext.getInitClassMembers();

		final OOConstruction savedConstruction = initConstruction(entity, formals, locals, isStatic, instance, owner);

		// The instance variables must be initialized first
		for(ClassMember member : initClassMembers) {
			// TODO: How we will handle Initializer_c ???
			if(member instanceof FieldDecl_c) {
				final FieldDecl_c fieldDecl = (FieldDecl_c)member;
				assert(fieldDecl.init() != null);

				final Flags fieldFlags = fieldDecl.flags().flags();
				assert(!fieldFlags.isStatic());

				final FieldInstance fieldInst = fieldDecl.fieldDef().asInstance();
				final Node objectPointer = getThis(Mode.getP());
				genFieldAssign(objectPointer, fieldInst, fieldDecl.init());
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

	private static final String X10_STATIC_FIELD_STATUS_SUFFIX = "__status";
	private static final String X10_STATIC_FIELD_ACCESSOR_SUFFIX = "__get";

	private static final int    X10_STATIC_FIELD_STATUS_UNITIALIZED = 0;
	private static final int    X10_STATIC_FIELD_STATUS_INITIALIZED = 1;

	private Node getFieldAddress(final Node objectPointer, final FieldInstance instance) {
		final FieldInstance def = instance.def().asInstance();
		final Flags flags = def.flags();
		/* make sure enclosing class-type has been created */
		firmTypeSystem.asFirmType(def.container());
		final Entity entity = firmTypeSystem.getEntityForField(def);
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

	private Node genFieldAssign(final Node objectPointer, final FieldInstance instance, final Expr expr) {
		final Node rightRet = visitExpression(expr);
		genFieldAssign(objectPointer, instance, rightRet);

		return rightRet;
	}

	private Node genStaticFieldAssign(final FieldInstance instance, final Expr expr) {
		return genFieldAssign(null, instance, expr);
	}

	private Node genStaticFieldAssign(final FieldInstance instance, final Node rightRet) {
		return genFieldAssign(null, instance, rightRet);
	}

	/**
	 * Mapping between static non const fields and the appropriate getter method entities.
	 */
	private Map<FieldInstance, MethodInstance> staticFieldGetterMethodMap = new HashMap<FieldInstance, MethodInstance>();

	/**
	 * Returns the getter method for a given static non constant field
	 * @param field The field for which the appropriate getter method should be returned
	 * @return The appropriate getter method for the given field
	 */
	private MethodInstance getGetterMethodForStaticField(final FieldInstance field) {
		assert(field.flags().isStatic() && !field.isConstant());
		final MethodInstance meth = staticFieldGetterMethodMap.get(field);
		if(meth != null)
			return meth;

		final X10ClassType contType = (X10ClassType)field.container();
		final X10ClassDef contDef = (X10ClassDef)contType.def();

		final Position pos = Position.COMPILER_GENERATED;
		// Create the method for accessing the field
		final X10MethodDef mi = x10TypeSystem.methodDef(pos, Types.ref(contType),
				x10TypeSystem.Public().Static(), Types.ref(field.type()),
				Name.make(field.name().toString() + X10_STATIC_FIELD_ACCESSOR_SUFFIX),
				new LinkedList<Ref<? extends Type>>());
		contDef.addMethod(mi);

		final MethodInstance staticAccMeth = mi.asInstance();

		staticFieldGetterMethodMap.put(field, staticAccMeth);

		return staticAccMeth;
	}

	/**
	 * Creates a new getter method for a static non const field
	 * @param dec The field declaration for which the getter method should be created.
	 */
	private void generateStaticNonConstFieldDecl(final FieldDecl_c dec) {
		assert(!dec.init().isConstant());
		final FieldDef fieldDef = dec.fieldDef();
		final FieldInstance fieldInst = fieldDef.asInstance();
		final X10ClassType contType = (X10ClassType)fieldInst.container();
		final X10ClassDef contDef = (X10ClassDef)contType.def();

		final Position pos = Position.COMPILER_GENERATED;
		// Create a new static value for the given field for holding the status of the initialization
    	final FieldDef statusField = x10TypeSystem.fieldDef(pos, Types.ref(contType), x10TypeSystem.Public().Static(),
    			Types.ref(x10TypeSystem.Int()), Name.make(fieldDef.name().toString() + X10_STATIC_FIELD_STATUS_SUFFIX));
    	contDef.addField(statusField);

    	final FieldInstance statusFieldInst = statusField.asInstance();

    	firmTypeSystem.addExtraStaticField(statusFieldInst);

    	final MethodInstance staticFieldGetterMethod = getGetterMethodForStaticField(fieldInst);
        final Entity staticFieldGetterEntity = getMethodEntity(staticFieldGetterMethod);
        final OOConstruction savedConstruction = initConstruction(staticFieldGetterEntity, new LinkedList<LocalInstance>(),
        		new LinkedList<LocalInstance>(), true, staticFieldGetterMethod, (X10ClassType)staticFieldGetterMethod.container());
        final Entity statusFieldEnt = firmTypeSystem.getEntityForField(statusFieldInst);

        // Set the default "UNITIALIZED" value for "field".__status;
        final Initializer staticFieldStatusInitializer = new Initializer(new TargetValue(X10_STATIC_FIELD_STATUS_UNITIALIZED, firmTypeSystem.getFirmMode(x10TypeSystem.Int())));
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

		final Block bTrue  = con.newBlock();
		final Block bAfter = con.newBlock();

		final Node retLeft  = genStaticFieldLoad(statusFieldInst);
		final Node retRight = con.newConst(new TargetValue(X10_STATIC_FIELD_STATUS_INITIALIZED, firmTypeSystem.getFirmMode(x10TypeSystem.Int())));

		final Node c  = con.newCmp(retLeft, retRight, Relation.LessGreater);

		final Node cond = con.newCond(c);

		final Node projTrue  = con.newProj(cond, Mode.getX(), Cond.pnTrue);
		final Node projFalse = con.newProj(cond, Mode.getX(), Cond.pnFalse);

		bTrue.addPred(projTrue);
		bAfter.addPred(projFalse);

		con.setCurrentBlock(bTrue);
		genStaticFieldAssign(fieldInst, dec.init());

		final Node nodeInitialized = con.newConst(new TargetValue(X10_STATIC_FIELD_STATUS_INITIALIZED, firmTypeSystem.getFirmMode(x10TypeSystem.Int())));
		genStaticFieldAssign(statusFieldInst, nodeInitialized);

		bAfter.addPred(con.newJmp());
		bTrue.mature();
		con.setCurrentBlock(bAfter);

		final Node mem = con.getCurrentMem();
		final Node retValue = genStaticFieldLoad(fieldInst);
		final Node retNode = con.newReturn(mem, new Node[]{retValue});

		/* for error detection */
		con.getGraph().getEndBlock().addPred(retNode);
		con.setCurrentBlockBad();

		bAfter.mature();

        finishConstruction(staticFieldGetterEntity, savedConstruction);
	}

	@Override
	public void visit(FieldDecl_c dec) {
		final Flags flags = dec.flags().flags();

		/* make sure enclosing classtype has been created */
		final FieldInstance instance = dec.fieldDef().asInstance();
		firmTypeSystem.asFirmType(instance.container());

		/* static fields may have initializers */
		if (flags.isStatic()) {
			final Expr init = dec.init();
			if (init != null) {
				if(dec.init().isConstant()) {
					final Initializer initializer = expr2Initializer(init);
					final Entity entity = firmTypeSystem.getEntityForField(dec.fieldDef().asInstance());
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
			final FieldInstance instance = field.fieldInstance().def().asInstance();
			final Node objectPointer = visitExpression((Expr)field.target());
			final Node ret = genFieldAssign(objectPointer, instance, rhs);
			setReturnNode(ret);
		} else {
			throw new RuntimeException("Unexpected assignment target");
		}
	}

	@Override
	public void visit(Return_c n) {
		Node ret = null;

		if(n.expr() != null) {
			final X10ProcedureInstance<?> curProc = firmContext.getCurProcedure();
			assert(curProc != null);

			// autoboxing
			final Expr expr = x10Cast(n.expr(), curProc.returnType());
			ret = visitExpression(expr);
		}

		Node retNode = null;
		if (ret != null) {
			final Node mem = con.getCurrentMem();
			retNode = con.newReturn(mem, new Node[]{ret});
		} else {
			final Node mem = con.getCurrentMem();
			retNode = con.newReturn(mem, new Node[]{});
		}
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
					genConstructorCall(sel, new_c.constructorInstance(), new_c.arguments());
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
			boolean cond = (Boolean)n.cond().constantValue();
			if(cond) {
				visitExpression(n.consequent());
				// return node is automatically set.
				return;
			}

			visitExpression(n.alternative());
			return;
		}

		final Block bTrue    = con.newBlock();
		final Block bFalse   = con.newBlock();
		final Block curBlock = con.getCurrentBlock();

		con.setCurrentBlock(bTrue);

		final Node trueExpr  = visitExpression(n.consequent());
		final Node endIf     = con.newJmp();

		con.setCurrentBlock(bFalse);

		final Node falseExpr = visitExpression(n.alternative());
		final Node endElse   = con.newJmp();

		con.setCurrentBlock(curBlock);

		evaluateCondition(n.cond(), bTrue, bFalse);

		bFalse.mature();

		// add a common phi block for the true and false expressions.
		final Block phiBlock = con.newBlock();
		phiBlock.addPred(endIf);
		phiBlock.addPred(endElse);

		con.setCurrentBlock(phiBlock);

		phiBlock.mature();

		final Node ret = con.newPhi(new Node[]{trueExpr, falseExpr}, falseExpr.getMode());
		setReturnNode(ret);
	}

	@Override
	public void visit(If_c n) {
		final Block bTrue  = con.newBlock();
		final Block bAfter = con.newBlock();

		Block bFalse = null; // block will only be created if we have an else stmt.
		if (n.alternative() != null) {
			bFalse = con.newBlock();
		} else {
			bFalse = bAfter;
		}
		evaluateCondition(n.cond(), bTrue, bFalse);
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
			bFalse.mature();
			Stmt alternative = n.alternative();
			if (alternative instanceof Block_c) {
				Block_c block = (Block_c) alternative;
				if (block.statements().size() == 1 && block.statements().get(0) instanceof If_c)
					alternative = block.statements().get(0);
			}

			con.setCurrentBlock(bFalse);
			visitAppropriate(alternative);

			if(!con.getCurrentBlock().isBad())
				bAfter.addPred(con.newJmp());
		}

		if(endIf != null)
			bAfter.addPred(endIf);

		bAfter.mature();
		
		if(!con.getCurrentBlock().isBad())
			con.setCurrentBlock(bAfter);
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




	/**
	 *  Needed because TypeParamSubstTransformer's constructor is protected.
	 */
	public static class GenericTypesRewritingVisitor extends NodeVisitor {
		private class GenericTypeTransformer extends TypeParamSubstTransformer {
			public GenericTypeTransformer(TypeParamSubst subst) {
				super(subst);
			}
		}

		private GenericTypeTransformer transformer;

		/**
		 * @param subst The substitution that shall be applied.
		 */
		public GenericTypesRewritingVisitor(TypeParamSubst subst) {
			this.transformer = new GenericTypeTransformer(subst);
		}

        @Override
        public polyglot.ast.Node leave(polyglot.ast.Node old, polyglot.ast.Node n, NodeVisitor v) {
        	return transformer.transform(n, old, null);
        }
	}

	private Set<String> alreadyCompiledMethods = new HashSet<String>();

	private String buildHashString(final MethodInstance mi) {
		final StringBuilder sb = new StringBuilder();

		sb.append(mi.designator());
		sb.append(" ");
		sb.append(mi.flags().prettyPrint());
		sb.append(Types.baseType(mi.container()).fullName().toString());
		sb.append(".");
		sb.append(mi.name().toString());

		List<String> params = new ArrayList<String>();
		List<Type> typeParameters = mi.typeParameters();
		if (typeParameters != null) {
			for (int i = 0; i < typeParameters.size(); i++) {
				params.add(Types.baseType(typeParameters.get(i)).toString());
			}
		}
		else {
			for (int i = 0; i < mi.x10Def().typeParameters().size(); i++) {
				params.add(Types.baseType(mi.x10Def().typeParameters().get(i)).toString());
			}
		}
		if (params.size() > 0) {
			sb.append("[");
			sb.append(CollectionUtil.listToString(params));
			sb.append("]");
		}

		List<String> formals = new ArrayList<String>();
		List<Type> formalTypes = mi.formalTypes();
		if (formalTypes != null) {
			List<LocalInstance> formalNames = mi.formalNames();
			for (int i = 0; i < formalTypes.size(); i++) {
				String s = "";
				String t = Types.baseType(formalTypes.get(i)).toString();
				if (formalNames != null && i < formalNames.size()) {
					LocalInstance a = formalNames.get(i);
					if (a != null && ! a.name().toString().equals(""))
						s = a.name() + ": " + t;
					else
						s = t;
				}
				else {
					s = t;
				}
				formals.add(s);
			}
		}
		else {
			for (int i = 0; i < mi.def().formalTypes().size(); i++) {
				formals.add(Types.baseType(mi.def().formalTypes().get(i).get()).toString());
			}
		}
		sb.append("(");
		sb.append(CollectionUtil.listToString(formals));
		sb.append(")");

		// TODO:  Do we need the return type here?
		Ref<? extends Type> returnType = mi.returnTypeRef();
		if (returnType != null && returnType.known()) {
			sb.append(": ");
			sb.append(Types.baseType(returnType.get()));
		}

		return sb.toString();
	}

	@Override
	public void visit(X10Call_c n) {
		// Determine called method.
		final MethodInstance oldMethodInstance = n.methodInstance();
		final Flags oldFlags = oldMethodInstance.flags();

		if (oldFlags.isNative() || oldFlags.isAbstract() || oldMethodInstance.typeParameters().isEmpty()) {
			final Node ret = genX10Call(oldMethodInstance, n.arguments(), n.target());
			setReturnNode(ret);
			return;
		}

		final MethodInstance newMethodInstance = oldMethodInstance;
		final String hashName = buildHashString(newMethodInstance);

		if (alreadyCompiledMethods.contains(hashName)) {
			final Node ret = genX10Call(newMethodInstance, n.arguments(), n.target());
			setReturnNode(ret);
			return;
		}

		// Add eagerly to allow recursion.
		alreadyCompiledMethods.add(hashName);

		// Find the method declaration.
		final MethodDeclFetcher fetcher = new MethodDeclFetcher(x10TypeSystem, xnf);
		final X10MethodDecl oldDecl = fetcher.getDecl(n);

		// Build substitution object that substitutes actual types for type parameters.
		final List<Type> actualTypes = oldMethodInstance.typeParameters();
		final List<ParameterType> formalTypes = new ArrayList<ParameterType>();
		for (TypeParamNode tpn : oldDecl.typeParameters())
			formalTypes.add(tpn.type());
		final TypeParamSubst subst = new TypeParamSubst(x10TypeSystem, actualTypes, formalTypes);

		// Apply substitution to AST.
		final GenericTypesRewritingVisitor visitor = new GenericTypesRewritingVisitor(subst);
		final polyglot.ast.Node newAst = oldDecl.body().visit(visitor);

		// Rewrite types.
		final TypeNode newReturnTypeNode = oldDecl.returnType().typeRef(subst.reinstantiate(oldDecl.returnType().typeRef()));
		final List<Formal> newFormals = new ArrayList<Formal>();
		for (Formal oldFormal : oldDecl.formals()) {
			final Ref<? extends Type> newTypeRef = subst.reinstantiate(oldFormal.type().typeRef());
			final Formal newFormal = oldFormal.type(oldFormal.type().typeRef(newTypeRef));
			newFormals.add(newFormal);
		}

		final X10MethodDecl_c newMethodDecl = new X10MethodDecl_c(
				xnf,
				oldDecl.position(),
				oldDecl.flags(),
				newReturnTypeNode,
				oldDecl.name(),
				new ArrayList<TypeParamNode>(),
				newFormals,
				oldDecl.guard(),
				oldDecl.offerType(),
				(polyglot.ast.Block) newAst);

		final Entity entity = getMethodEntity(newMethodInstance);
		final List<LocalInstance> formals = newMethodInstance.formalNames();
		final List<LocalInstance> nFormals = new ArrayList<LocalInstance>();
		for (LocalInstance inst : formals)
			nFormals.add(inst.type(subst.reinstantiate(inst.type())));
		final boolean isStatic = newMethodInstance.flags().isStatic();
		final X10ClassType owner = (X10ClassType) newMethodInstance.container();

		// Extract all locals from the method.
		final List<LocalInstance> locals = getAllLocalInstancesInCodeBlock(newMethodDecl);
		constructGraph(entity, newMethodDecl, nFormals, locals, isStatic, newMethodInstance, owner);

		final Node ret = genX10Call(newMethodInstance, n.arguments(), n.target());
		setReturnNode(ret);
	}

	@Override
	public void visit(X10ConstructorCall_c n) {
		/* TODO: check for this or super */

		/* determine called function */
		final X10ConstructorInstance instance = n.constructorInstance();
		final Entity entity = getConstructorEntity(instance);
		final MethodType type = (MethodType) entity.getType();
		final Node address = con.newSymConst(entity);

		final int param_count = type.getNParams();
		final Node[] parameters = new Node[param_count];
		int p = 0;
		parameters[p++] = getThis(Mode.getP());

		final List<Expr> arguments = transformArguments(instance.formalTypes(), n.arguments());

		for(Expr expr : arguments)
			parameters[p++] = visitExpression(expr);

		assert(p == param_count);

		final Node mem = con.getCurrentMem();
		final Node call = con.newCall(mem, address, parameters, type);
		final Node newMem = con.newProj(call, Mode.getM(), Call.pnM);

		con.setCurrentMem(newMem);
	}

	/**
	 * @param expr	an X10 Expr node
	 * @return a Firm node containing the result value of the expression
	 */
	public Node visitExpression(Expr expr) {
		resetReturnNode();
		visitAppropriate(expr);
		final Node ret = getReturnNode();

		return ret;
	}

	@Override
	public void visit(Field_c n) {
		final FieldInstance instance = n.fieldInstance();

		final Flags flags = instance.flags();

		if(flags.isStatic() && !instance.isConstant()) {
			// a static non constant field -> do a static method call to the "field".__get method
			final MethodInstance staticGetterMethod = getGetterMethodForStaticField(instance);

			final Node ret = genX10Call(staticGetterMethod, new ArrayList<Expr>(), null);
			setReturnNode(ret);
		} else if(flags.isStatic()) {
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
	private Node getEntityFromCurrentFrame(final Entity entity) {
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
			// FIXME:  Check if it is correct to use n.type() instead of loc.type() here.
			final Node ret = con.getVariable(idx, firmTypeSystem.getFirmMode(n.type()));
			setReturnNode(ret);
		}
	}

	/**
	 * Create the appropriate firm nodes for a heap allocation.
	 * @param x10ResType The result type (reference)
	 * @param x10Type The type of object which should be allocated
	 *
	 * @return A proj node to the allocated memory.
	 */
	private Node genNewAlloc(final Type x10ResType, final Type x10Type) {
		final firm.Type resType  = firmTypeSystem.asFirmType(x10ResType);
		final firm.Type firmType = firmTypeSystem.asFirmCoreType(x10Type);
		return genNewAlloc(resType, firmType);
	}

	/**
	 * Create the appropriate firm nodes for a heap allocation.
	 * @param resType The result type (reference)
	 * @param type The type of object which should be allocated
	 *
	 * @return A proj node to the allocated memory.
	 */
	private Node genNewAlloc(final firm.Type resType, final firm.Type type) {
		return genAlloc(resType, type, ir_where_alloc.heap_alloc);
	}

	/**
	 * Create the appropriate firm nodes for a stack allocation.
	 * @param x10ResType The result type (reference)
	 * @param x10Type The type of object which should be allocated
	 *
	 * @return A proj node to the allocated memory.
	 */
	private Node genStackAlloc(final Type x10ResType, final Type x10Type) {
		final firm.Type resType  = firmTypeSystem.asFirmType(x10ResType);
		final firm.Type firmType = firmTypeSystem.asFirmCoreType(x10Type);
		return genAlloc(resType, firmType, ir_where_alloc.stack_alloc);
	}

	private Node genAlloc(final firm.Type resType, final firm.Type firmType, final ir_where_alloc where) {
		final Node mem = con.getCurrentMem();
		final Node count = con.newConst(1, Mode.getIu());
		final Node alloc = con.newAlloc(mem, count, firmType, where);
		final Node newMem = con.newProj(alloc, Mode.getM(), Alloc.pnM);
		final Node res = con.newProj(alloc, resType.getMode(), Alloc.pnRes);

		con.setCurrentMem(newMem);

		return res;
	}

	/**
	 * Generate the appropriate nodes for a constructor call
	 * @param objectThisNode The this pointer for the constructor call (implicit first parameter)
	 * @param instance The constructor instance
	 * @param args The arguments of the constructor call (without the implicit this pointer)
	 */
	private void genConstructorCall(final Node objectThisNode, final X10ConstructorInstance instance, final List<Expr> args) {
		/* invoke class constructor */
		if (instance != null) {
			final Entity entity = getConstructorEntity(instance);
			final firm.MethodType entityType = (MethodType) entity.getType();
			final Node address = con.newSymConst(entity);

			final int param_count = entityType.getNParams();
			final Node[] parameters = new Node[param_count];

			final List<Expr> arguments = transformArguments(instance.formalTypes(), args);

			int p = 0;
			parameters[p++] = objectThisNode; /* this argument */

			for(Expr arg : arguments) {
				parameters[p++] = visitExpression(arg);
			}
			assert args.size()+1 == param_count;

			final Node mem = con.getCurrentMem();
			final Node call = con.newCall(mem, address, parameters, entityType);
			final Node newMem = con.newProj(call, Mode.getM(), Call.pnM);

			con.setCurrentMem(newMem);

		} else {
			assert(false): "No constructor given";
			/* no constructor */
		}
	}

	@Override
	public void visit(New_c n) {
		final Type type = n.objectType().type();
		Node objectThisNode = null;

		if(x10TypeSystem.isStructType(n.type())) {
			objectThisNode = genStackAlloc(n.type(), type);
		} else {
			objectThisNode = genNewAlloc(n.type(), type);
		}
		assert(objectThisNode != null);

		genConstructorCall(objectThisNode, n.constructorInstance(), n.arguments());
		setReturnNode(objectThisNode);
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
		if (kind == IntLit.ULONG) {
			mode = firmTypeSystem.getFirmMode(x10TypeSystem.ULong());
		} else if (literal.kind() == IntLit.UINT) {
			mode = firmTypeSystem.getFirmMode(x10TypeSystem.UInt());
		} else if (literal.kind() == IntLit.LONG) {
			mode = firmTypeSystem.getFirmMode(x10TypeSystem.Long());
		} else if (literal.kind() == IntLit.INT) {
			mode = firmTypeSystem.getFirmMode(x10TypeSystem.Int());
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

	@Override
	public void visit(StringLit_c n) {
		/* Construct call to builtin function, which creates an X10 string struct. */

		final Node string_const = createStringSymConst(n.value());

		final firm.Type[] parameterTypes = new firm.Type[2];
		parameterTypes[0] = firmTypeSystem.asFirmType(x10TypeSystem.UInt());
		parameterTypes[1] = new PointerType(parameterTypes[0]); /* XXX Pointer to uint is not quite correct */
		final firm.Type[] resultTypes = new firm.Type[1];
		resultTypes[0] = firmTypeSystem.asFirmType(x10TypeSystem.String());
		final MethodType type = new firm.MethodType(parameterTypes, resultTypes);

		final Entity func_ent = new Entity(Program.getGlobalType(), X10_STRING_LITERAL, type);
		final Node address = con.newSymConst(func_ent);

		Node[] parameters = new Node[2];
		parameters[0] = con.newConst(n.value().length(), Mode.getIu());
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
		final Node ret = con.newProj(all_results, mode, 0);

		setReturnNode(ret);
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
	
	private Expr transformArgument(final Type fType, final Expr arg) {
		Expr ret = arg;
		if(!x10TypeSystem.typeEquals(fType, arg.type(), x10Context) && !(x10TypeSystem.isParameterType(fType) && arg.type().isNull()))
			ret = x10Cast(arg, fType);
		return ret;
	}

	/**
	 * Transforms a list of expressions to another list of expressions where types are adjusted by explicit casts.
	 * (Adjustment is done by wrapping the expressions into cast nodes)
	 *
	 * @param formalTypes A list with the formal types.
	 * @param args The list with the expressions.
	 * @return A list of expressions where improper types are adjusted by explicit casts.
	 */
	private List<Expr> transformArguments(final List<Type> formalTypes, final List<Expr> args) {
		List<Expr> ret = new LinkedList<Expr>();

		int i = 0;
		for (Expr arg : args) {
		    final Type fType = formalTypes.get(i);

		    arg = transformArgument(fType, arg);

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
		final boolean isNative = flags.isNative();
		final boolean isStruct = x10TypeSystem.isStructType(mi.container());
		final boolean isStaticBinding = (isStatic || isFinal || isNative || isStruct);
		final Entity entity = getMethodEntity(mi);

		final MethodType type = (MethodType) entity.getType();
		final int paramCount = type.getNParams();

		List<Expr> arguments = new LinkedList<Expr>();

		// add the other arguments
		arguments.addAll(transformArguments(mi.formalTypes(), args));

		// add implicit this pointer
		if (!isStatic) {
			assert(target != null && target instanceof Expr);
			final Expr receiver = (Expr)target;
			arguments.add(0, transformArgument(mi.container(), receiver));
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
			genFieldAssign(thisPointer, field, args.get(i));
		}
	}

	/**
	 * Initializes a given boxing type -> creates method etc.
	 * @param boxedType The type of the boxed field
	 * @param boxType The boxing type which should be initialized
	 */
	private void initBoxingType(final X10ClassType boxedType, final X10ClassType boxType) {

		final FieldInstance boxedField = boxType.fieldNamed(Name.make(FirmTypeSystem.BOXED_VALUE));
		assert(boxedField != null);

		final Position pos = Position.COMPILER_GENERATED;
		for(MethodInstance m : boxType.methods()) {
			final Flags flags = m.flags();
			final Entity entity = getMethodEntity(m);

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
	        														  flags.isStatic(), m, boxType);

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
	private Set<Type> initedBoxingTypes = new HashSet<Type>();

	/**
	 * Creates the appropriate firm graph for an autoboxing
	 * @param fromType The type which should be boxed
	 * @param expr The expression which should be boxed
	 * @return A
	 */
	private Node genAutoboxing(final X10ClassType fromType, final Expr expr) {
		final X10ClassType boxType = firmTypeSystem.getBoxingType(fromType);

		if(!initedBoxingTypes.contains(boxType)) {
			// init the boxing type only once
			initBoxingType(fromType, boxType);
			initedBoxingTypes.add(boxType);
		}

		// Generate the box
		final firm.Type firmBoxType = firmTypeSystem.asFirmType(boxType);
		final firm.Type firmCoreBoxType = firmTypeSystem.asFirmCoreType(boxType);
		final Node box = genNewAlloc(firmBoxType, firmCoreBoxType);

		// save the boxed value in the box
		final FieldInstance boxValue = boxType.fieldNamed(Name.make(FirmTypeSystem.BOXED_VALUE));
		genFieldAssign(box, boxValue, expr);

		return box;
	}

	@Override
	public void visit(X10Cast_c c) {

		final TypeNode tn = c.castType();
		assert tn instanceof CanonicalTypeNode;

		switch (c.conversionType()) {
		case CHECKED:
		case PRIMITIVE:
		case SUBTYPE:
        case UNCHECKED:

			if(tn instanceof X10CanonicalTypeNode) {
				final X10CanonicalTypeNode xtn = (X10CanonicalTypeNode) tn;

                final Type tooType = Types.baseType(xtn.type());
                final Type fromType = Types.baseType(c.expr().type());

                final Type too = Types.stripConstraints(tooType);
                final Type from = Types.stripConstraints(fromType);

                if (x10TypeSystem.typeEquals(from, too, x10Context)) {
                	// types are statically equal no type conversion needed.
                    visitAppropriate(c.expr());
                } else if (c.conversionType()==Converter.ConversionType.SUBTYPE && x10TypeSystem.isSubtype(from, too, x10Context)) {
                    // TODO: Add class cast checking
                	if (too.isClass() && too.toClass().flags().isInterface() && from.isClass() && ((X10ClassType)from.toClass()).isX10Struct()) {
                        // An upcast of a struct to an implemented interface -> Need boxing
                		final Node ret = genAutoboxing((X10ClassType)from, c.expr());
                		setReturnNode(ret);
                    } else {
                    	// TODO: no casting needed yet.
                    	visitAppropriate(c.expr());
                    }
                } else {
                	// An unchecked class cast.
				    visitAppropriate(c.expr());
				}
			} else {
				throw new InternalCompilerError("Ambiguous TypeNode survived type-checking.", tn.position());
			}
			break;

        case CALL_CONVERSION:
        	throw new InternalCompilerError("Unknown conversion type after type-checking.", c.position());
		case UNBOXING:
			throw new InternalCompilerError("Unknown conversion type after type-checking.", c.position());
		case UNKNOWN_IMPLICIT_CONVERSION:
			throw new InternalCompilerError("Unknown conversion type after type-checking.", c.position());
		case UNKNOWN_CONVERSION:
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
	public void visit(Closure_c n) {
		throw new RuntimeException("Closure should have been desugared earlier");
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
	public void visit(SubtypeTest_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(Throw_c n) {
		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(Try_c n) {
//		throw new RuntimeException("Not implemented yet");
	}

	@Override
	public void visit(Catch_c n) {
//		throw new RuntimeException("Not implemented yet");
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
	public void visit(ArrayInit_c n) {
		throw new InternalCompilerError("Should not be invoked");
	}

	@Override
	public void visit(SettableAssign_c n) {
		throw new RuntimeException("Function assign should have been desugared earlier");
	}

	@Override
	public void visit(Tuple_c c) {
//		throw new RuntimeException("Not implemented yet");
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

	/**
	 * return current construction object
	 */
	OOConstruction getFirmConstruction() {
		return con;
	}

	/**
	 * return FIRM type system
	 */
	FirmTypeSystem getFirmTypeSystem() {
		return firmTypeSystem;
	}
}