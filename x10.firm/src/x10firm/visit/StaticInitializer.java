package x10firm.visit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.WeakHashMap;
import java.util.concurrent.atomic.AtomicBoolean;

import polyglot.ast.Assign;
import polyglot.ast.Binary.Operator;
import polyglot.ast.Block;
import polyglot.ast.Call;
import polyglot.ast.ClassBody;
import polyglot.ast.ClassDecl_c;
import polyglot.ast.ClassMember;
import polyglot.ast.Expr;
import polyglot.ast.FieldDecl;
import polyglot.ast.FlagsNode;
import polyglot.ast.FloatLit;
import polyglot.ast.Formal;
import polyglot.ast.Id;
import polyglot.ast.Initializer;
import polyglot.ast.IntLit;
import polyglot.ast.MethodDecl;
import polyglot.ast.Node;
import polyglot.ast.NodeFactory;
import polyglot.ast.ProcedureDecl;
import polyglot.ast.Receiver;
import polyglot.ast.Stmt;
import polyglot.ast.TypeNode;
import polyglot.frontend.Job;
import polyglot.types.ClassDef;
import polyglot.types.ClassType;
import polyglot.types.ConstructorDef;
import polyglot.types.ConstructorInstance;
import polyglot.types.Context;
import polyglot.types.FieldDef;
import polyglot.types.FieldInstance;
import polyglot.types.Flags;
import polyglot.types.InitializerDef;
import polyglot.types.MethodDef;
import polyglot.types.Name;
import polyglot.types.ParsedClassType;
import polyglot.types.Ref;
import polyglot.types.SemanticException;
import polyglot.types.Type;
import polyglot.types.TypeSystem;
import polyglot.types.Types;
import polyglot.util.Pair;
import polyglot.util.Position;
import polyglot.visit.ContextVisitor;
import polyglot.visit.NodeVisitor;
import x10.X10CompilerOptions;
import x10.ast.TypeParamNode;
import x10.ast.X10Call;
import x10.ast.X10Call_c;
import x10.ast.X10ClassDecl;
import x10.ast.X10ClassDecl_c;
import x10.ast.X10ConstructorDecl;
import x10.ast.X10FieldDecl;
import x10.ast.X10Field_c;
import x10.ast.X10MethodDecl;
import x10.ast.X10New_c;
import x10.ast.X10SourceFile_c;
import x10.extension.X10Ext;
import x10.types.ConstrainedType;
import x10.types.MethodInstance;
import x10.types.X10ClassDef;
import x10.types.X10ClassType;
import x10.types.X10ConstructorDef;
import x10.types.X10ConstructorInstance;
import x10.types.X10MethodDef;
import x10.types.X10ProcedureDef;
import x10.util.CollectionFactory;
import x10.visit.Desugarer;
import x10.visit.X10TypeChecker;
import x10c.ast.X10CNodeFactory_c;
import x10c.types.X10CTypeSystem_c;

/**
 * Lowering of all non const static initializer
 */
public class StaticInitializer extends ContextVisitor {

    private final X10CTypeSystem_c xts;
    private final X10CNodeFactory_c xnf;
    private final ASTQuery query;

    private final WeakHashMap<X10ProcedureDef,ProcedureDecl> procDeclCache = new WeakHashMap<X10ProcedureDef,ProcedureDecl>();
    private final WeakHashMap<Block,Boolean> procBodyCache = new WeakHashMap<Block,Boolean>();
    /** caching of shadow classes */
    private static Map<X10ClassDef, X10ClassDef> shadow_class_map = new HashMap<X10ClassDef, X10ClassDef>();

    private X10CompilerOptions opts = (X10CompilerOptions) job.extensionInfo().getOptions();

    private static final String initializerPrefix = "getInitialized$";
    private static final String initStatusPrefix = "initStatus$";
    private static final String nestedShadowClass4Interface = "Shadow";
    private static final String INIT_DIPSPATCHER_UNINITIALIZED = "UNINITIALIZED";
    private static final String INIT_DISPATCHER_INITIALIZED = "INITIALIZED";

    /** mapping static field and corresponding initializer method */
    private Map<Pair<Type,Name>, StaticFieldInfo> staticFinalFields = CollectionFactory.newHashMap();

    /** Constructor */
    public StaticInitializer(Job job, TypeSystem ts, NodeFactory nf) {
        super(job, ts, nf);
        xts = (X10CTypeSystem_c) ts;
        xnf = (X10CNodeFactory_c) nf;
        query = new ASTQuery(ts);
    }

    @Override
    protected Node leaveCall(Node parent, Node old, Node n, NodeVisitor v) throws SemanticException {
        if (!(parent instanceof X10ClassDecl_c))
            return n;

        X10ClassDecl_c ct = (X10ClassDecl_c)parent;
        if (old != ct.body())
            return n;

        ClassBody classBody = (ClassBody) n;
        X10ClassDef classDef = ct.classDef();
        assert(classDef != null);

        Context cntxt = ct.enterChildScope(classBody, ((ContextVisitor) v).context());

        // collect static fields to deal with
        staticFinalFields.clear();
        // classBody.dump(System.err);
        // System.out.println("StaticInitilizer for "+classDef);
        classBody = checkStaticFields(classBody, cntxt);

        if (staticFinalFields.isEmpty())
            // nothing to do
            return classBody;

        List<ClassMember> currMembers = new ArrayList<ClassMember>();
        currMembers.addAll(classBody.members());

        if (!ct.flags().flags().isInterface()) {
            // create a new member list for initializer/deserializer methods of each static field
            List<ClassMember> newMembers = createNewMembers(classDef);
            currMembers.addAll(newMembers);
        } else {

            // create a nested shadow class
            X10ClassDecl shadowDecl = createNestedShadowClass(ct);

            // create a new member list for the shadow class just created
            List<ClassMember> newMembers = createNewMembers(shadowDecl.classDef());

            // add members into the body of the shadow class
            ClassBody shadowBody = shadowDecl.body();
            shadowBody = shadowBody.members(newMembers);
            shadowDecl = shadowDecl.body(shadowBody);

            // add the shadow class in the original interface body
            currMembers.add(shadowDecl);
        }

        classBody = classBody.members(currMembers);
        // classBody.dump(System.err);
        return classBody;
    }

    private List<ClassMember> createNewMembers(X10ClassDef classDef) {
        Position CG = Position.compilerGenerated(null);
        List<ClassMember> members = new ArrayList<ClassMember>();
        List<Stmt> initStmts = new ArrayList<Stmt>();

        // we must collect all needed static field infos, because we
        // can`t modify the staticFinalFields field while iterating over it (ConcurrentModificationException)
        List<StaticFieldInfo> initFields = new LinkedList<StaticFieldInfo>();

        for (Map.Entry<Pair<Type,Name>, StaticFieldInfo> entry : staticFinalFields.entrySet()) {
            Name fName = entry.getKey().snd();
            StaticFieldInfo fieldInfo = entry.getValue();

            if (fieldInfo.right == null && fieldInfo.fieldDef == null)
                continue;

            MethodDecl md = null;
            if (fieldInfo.right != null) {

                // gen new field var
                FieldDecl fdCond = makeFieldVar4Guard(CG, fName, classDef);
                classDef.addField(fdCond.fieldDef());
                // add in the top
                members.add(0, fdCond);

                if (fieldInfo.left != null) {
                    // interface case: add field declaration to the shadow class
                    FieldDef fd = fieldInfo.left.fieldDef();
                    Flags newFlags = fd.container().get().toClass().flags().clearInterface();
                    FieldDef newFd = xts.fieldDef(CG, Types.ref(classDef.asType()), newFlags, fd.type(), fd.name());
                    members.add(0, fieldInfo.left.fieldDef(newFd));
                }

                // gen new initialize method
                md = makeInitMethod(CG, fName, fieldInfo, fdCond.fieldDef(), classDef);

                initFields.add(fieldInfo);
            } else {
                // gen a fake initialization method
                md = makeFakeInitMethod(CG, fName, fieldInfo, classDef);
            }
            classDef.addMethod(md.methodDef());
            // add in the bottom
            members.add(md);
        }

        for(final StaticFieldInfo sfi: initFields) {
            // register in the table for x10-level static initialization later
            initStmts.add(makeAddInitializer(CG, sfi, classDef));
        }

        if (!initStmts.isEmpty()) {
            // gen initializer block
            Block initBlockBody = xnf.Block(CG, initStmts);
            Initializer initBlock = xnf.Initializer(CG, xnf.FlagsNode(CG, Flags.STATIC), initBlockBody);
            // create InitializerDef
            InitializerDef id = xts.initializerDef(CG, Types.ref(classDef.asType()), Flags.STATIC);
            initBlock = initBlock.initializerDef(id);
            members.add(initBlock);
        }
        return members;
    }

    private X10ClassDecl createNestedShadowClass(ClassDecl_c interfaceClass) {
        // create ClassDef first
        X10ClassDef cDef = getShadowClassDef(interfaceClass.classDef());

        // create ClassDecl
        Position CG = Position.compilerGenerated(null);
        FlagsNode fNode = xnf.FlagsNode(CG, cDef.flags());
        Id id = xnf.Id(CG, cDef.name());
        TypeNode superTN = xnf.CanonicalTypeNode(CG, cDef.superType());
        List<ClassMember> cmembers = new ArrayList<ClassMember>();
        ClassBody body = xnf.ClassBody(CG, cmembers);
        List<TypeNode> interfaceTN = Collections.<TypeNode>emptyList();
        X10ClassDecl cDecl = xnf.ClassDecl(CG, fNode, id, superTN, interfaceTN,
                                                          body).classDef(cDef);
        return cDecl;
    }

	private X10ClassDef getShadowClassDef(final X10ClassDef interfaceClassDef) {
		X10ClassDef cDef = shadow_class_map.get(interfaceClassDef);
		if (cDef != null)
			return cDef;

		cDef = xts.createClassDef(interfaceClassDef.sourceFile());
		cDef.superType(Types.ref(xts.Any()));
		List<Ref<? extends Type>> interfacesRef
			= Collections.<Ref<? extends Type>> emptyList();
		cDef.setInterfaces(interfacesRef);
		cDef.name(Name.make(nestedShadowClass4Interface));
		cDef.setFlags(Flags.PUBLIC.Abstract());
		cDef.kind(ClassDef.MEMBER);
		cDef.outer(Types.ref(interfaceClassDef));

		shadow_class_map.put(interfaceClassDef, cDef);

		return cDef;
	}

    private ClassBody checkStaticFields(ClassBody body, Context cntxt) {
        final X10ClassDef cd = cntxt.currentClassDef();
        // one pass scan of class body and collect vars for static initialization
        ClassBody c = (ClassBody)body.visit(new NodeVisitor() {
            @Override
            public Node override(Node parent, Node n) {
                if (n instanceof X10ClassDecl_c) {
                    // should not visit subtree of inner class (already done)
                    return n;
                }
                return null;
            }

            @Override
            public Node leave(Node parent, Node old, Node n, NodeVisitor v) {
                if (n instanceof X10FieldDecl) {
                    X10FieldDecl fd = (X10FieldDecl)n;
                    Flags flags = fd.fieldDef().flags();
                    if (query.isPerProcess(fd.fieldDef())) return n;
                    if (flags.isFinal() && flags.isStatic()) {
                        // static final field
                        StaticFieldInfo fieldInfo = checkFieldDeclRHS(fd, cd);
                        if (fieldInfo.right != null) {
                            FlagsNode fn = xnf.FlagsNode(fd.position(), flags.clearFinal());
                            Expr init = getDefaultValue(fd.position(), fd.init().type());
                            FieldDecl newDecl = xnf.FieldDecl(fd.position(), fn, fd.type(), fd.name(),
                                                 init).fieldDef(fd.fieldDef());
                            if (cd.flags().isInterface()) {
                                // move the field declaration to a shadow class
                                fieldInfo.left = newDecl;
                                return null;
                            }
                            return newDecl;
                        }
                    }
                }
                if (n instanceof X10Field_c) {
                    X10Field_c f = (X10Field_c)n;
                    if (query.isPerProcess(f.fieldInstance().x10Def())) return n;
                    if (f.flags().isFinal() && f.flags().isStatic()) {
                        // found reference to static field
                        if (checkFieldRefReplacementRequired(f)) {
                            // replace with a static method call
                            Type targetType = f.target().type();
                            if (targetType instanceof ParsedClassType) {
                                X10ClassDef targetClassDef = ((ParsedClassType)targetType).def();
                                if (targetClassDef.flags().isInterface())
                                    // target nested shadow class within interface
                                    targetType = getShadowClassDef(targetClassDef).asType();
                            }
                            else if (targetType instanceof ConstrainedType)
                                targetType = ((ConstrainedType)targetType).baseType().get();

                            X10ClassType receiver = (X10ClassType)targetType;
                            return makeStaticCall(n.position(), receiver, f.name(), f.type());
                        }
                    }
                }
                return n;
            }
        });
        return c;
    }

    private StaticFieldInfo checkFieldDeclRHS(final X10FieldDecl fd, final X10ClassDef cd) {
        // traverse nodes in RHS
        Id leftName = fd.name();

        // true means "found something not suitable for per-place initialization"
        final AtomicBoolean found = new AtomicBoolean(false);
        final boolean deep_analysis = opts.x10_config.STATICS_PER_PLACE_ANALYSIS;
        fd.init().visit(new NodeVisitor() {
            @Override
            public Node override(Node parent, Node n) {
                if (found.get())
                    // already found
                    return n;

                if (n instanceof Expr) {
                    if (query.isGlobalInit(fd)) {
                        // initialization can be done in all places -- do not visit subtree further
                        // System.out.println("isGlobalInit true in checkFieldDeclRHS: "+(Expr)n);
                        return n;
                    }
                }
                if (n instanceof X10Call_c) {
                    X10Call call = (X10Call)n;
                    MethodInstance mi = call.methodInstance();
                    if (deep_analysis && mi.flags().isStatic()) {
                        // found reference to static method
                        X10MethodDecl mdecl = getMethodDeclaration(mi);
                        if (mdecl == null || checkProcedureBody(mdecl.body(), 0)) {
                            // unsafe method call
                            found.set(true);
                            return n;
                        }
                    } else {
                        // non-static method call or no deep analysis
                        found.set(true);
                        return n;
                    }
                } else if (n instanceof X10Field_c) {
                    X10Field_c f = (X10Field_c)n;
                    if (f.flags().isFinal() && f.flags().isStatic()) {
                        // found reference to static field
                        if (checkFieldRefReplacementRequired(f)) {
                            found.set(true);
                            return n;
                        }
                    }
                } else if (n instanceof X10New_c) {
                    if (deep_analysis) {
                        X10New_c neu = (X10New_c)n;
                        X10ConstructorInstance ci = neu.constructorInstance();
                        // get declaration of constructor
                        X10ConstructorDecl cdecl = getConstructorDeclaration(ci);
                        if (cdecl == null || checkProcedureBody(cdecl.body(), 0)) {
                            // unsafe constructor
                            found.set(true);
                            return n;
                        }
                    } else {
                        // deep analysis disabled
                        found.set(true);
                        return n;
                    }
//                    else if (!opts.x10_config.MULTI_NODE && checkMultiplexRequiredSingleVM(ci)) {
//                        found.set(true);
//                    }
                }
                // continue traversal
                return null;
            }
        });

        // register original rhs
        X10ClassType receiver = cd.asType();
        StaticFieldInfo fieldInfo = getFieldEntry(receiver, leftName.id());

        fieldInfo.right = query.isGlobalInit(fd) ? null : fd.init();
        fieldInfo.fieldDef = fd.fieldDef();

        return fieldInfo;
    }

    private Call makeStaticCall(Position pos, X10ClassType receiver, Id id, Type returnType) {
        // create MethodDef
        Name name = Name.make(initializerPrefix+id);
        StaticFieldInfo fieldInfo = getFieldEntry(receiver, id.id());
        MethodDef md = fieldInfo.methodDef;
        if (md == null) {
            md = makeMethodDef(receiver, name, returnType);
            fieldInfo.methodDef = md;
        }

        // create static call for initialization
        List<TypeNode> typeArgsN = Collections.<TypeNode>emptyList();
        List<Expr> args = Collections.<Expr>emptyList();
        MethodInstance mi = xts.createMethodInstance(pos, Types.ref(md));
        Call result = (Call) xnf.X10Call(pos, xnf.CanonicalTypeNode(pos, receiver),
                                        xnf.Id(pos, name), typeArgsN, args)
                                        .methodInstance(mi).type(returnType);
        return result;
    }

    private MethodDef makeMethodDef(X10ClassType receiver, Name name, Type returnType) {
        Position CG = Position.compilerGenerated(null);
        List<Ref<? extends Type>> argTypes = Collections.<Ref<? extends Type>>emptyList();
        MethodDef md = xts.methodDef(CG, Types.ref(receiver),
                                     Flags.STATIC, Types.ref(returnType), name, argTypes);
        return md;
    }

    private FieldDecl makeFieldVar4Guard(Position pos, Name fName, X10ClassDef classDef) {
        // make FieldDef of AtomicInteger
        ClassType type = xts.Int();
        Flags flags = Flags.PRIVATE.Static();

        Name name = Name.make(initStatusPrefix+fName);
        FieldDef fd = xts.fieldDef(pos, Types.ref(classDef.asType()), flags, Types.ref(type), name);

        // create right hand side: InitDispatcher.UNINITIALIZED
        TypeNode tn = xnf.X10CanonicalTypeNode(pos, type);
        Expr init = getInitDispatcherConstant(pos, INIT_DIPSPATCHER_UNINITIALIZED).type(xts.Int());

        // fieldDecl and its association with fieldDef
        FieldDecl result = xnf.FieldDecl(pos, xnf.FlagsNode(pos, flags), tn, xnf.Id(pos, name), init);
        result = result.fieldDef(fd);
        return result;
    }

    private Expr getDefaultValue(Position pos, Type type) {
        if (type.isBoolean())
            return xnf.BooleanLit(pos, false).type(type);
        else if (type.isChar())
            return xnf.CharLit(pos, ' ').type(type);
        else if (type.isByte() || type.isShort() || type.isInt())
            return xnf.IntLit(pos, IntLit.INT, 0).type(type);
        else if (type.isLong())
            return xnf.IntLit(pos, IntLit.LONG, 0).type(type);
        else if (type.isFloat())
            return xnf.FloatLit(pos, FloatLit.FLOAT, 0.0).type(type);
        else if (type.isDouble())
            return xnf.FloatLit(pos, FloatLit.DOUBLE, 0.0).type(type);
        else if (type == xts.String())
            return xnf.NullLit(pos).type(type);
        else if (xts.isSubtype(type, xts.UByte()) || xts.isSubtype(type, xts.UShort()) ||
                 xts.isSubtype(type, xts.UInt()) || xts.isSubtype(type, xts.ULong())) {
            ConstructorDef cd = xts.defaultConstructor(pos, Types.ref((ClassType)type));
            ConstructorInstance ci = xts.createConstructorInstance(pos, Types.ref(cd));
            List<Expr> args = new ArrayList<Expr>();
            args.add(xnf.IntLit(pos, IntLit.INT, 0).type(type));
            return xnf.New(pos, xnf.X10CanonicalTypeNode(pos, type), args).constructorInstance(ci).type(type);
        }
        else
            return null;
    }

    private boolean checkProcedureBody(final Block body, final int count) {
        Boolean r = procBodyCache.get(body);
        if (r != null)
            return (r == Boolean.TRUE);

        // Cut the search tree to avoid overly long compilation time.
        // True means centralized place-0 initialization is necessary,
        // which is a safe conservative assumption.
        if (count > 7) return true;

        // check static field references in the body of constructor or method
        final AtomicBoolean found = new AtomicBoolean(false);
        body.visit(new NodeVisitor() {
            @Override
			public Node override(Node n) {
                if (found.get())
                    // already found
                    return n;
                if (n instanceof X10Call) {
                    X10Call call = (X10Call)n;
                    MethodInstance mi = call.methodInstance();
                    if (!mi.container().isClass() || call.target().type().isNumeric()) {
                        // allow method calls on non-objects or numerics
                    } else if (mi.flags().isStatic()) {
                        // found reference to special initializer method
                        X10MethodDecl mdecl = getMethodDeclaration(mi);
                        if (mdecl == null || checkProcedureBody(mdecl.body(), count+1)) {
                            // target method is unsafe include static field references
                            found.set(true);
                            return n;
                        }
                    } else {
                        // we consider non-static method call as unsafe
                        found.set(true);
                        return n;
                    }
                } else if (n instanceof X10Field_c) {
                    X10Field_c f = (X10Field_c)n;
                    if (f.flags().isFinal() && f.flags().isStatic()) {
                        if (checkFieldRefReplacementRequired(f)) {
                            // found reference to static field to be replaced
                            found.set(true);
                            return n;
                        }
                    }
                } else if (n instanceof X10New_c) {
                    X10New_c neu = (X10New_c)n;
                    X10ConstructorInstance ci = neu.constructorInstance();
                    // get declaration of constructor
                    X10ConstructorDecl cdecl = getConstructorDeclaration(ci);
                    if (cdecl != null && !cdecl.body().equals(body) && checkProcedureBody(cdecl.body(), count+1)) {
                        // constructor include static field references to be replaced
                        found.set(true);
                        return n;
                    }
//                    else if (!opts.x10_config.MULTI_NODE && checkMultiplexRequiredSingleVM(ci)) {
//                        found.set(true);
//                    }
                }
                // continue traversal
                return null;
            }
        });
        procBodyCache.put(body, found.get() ? Boolean.TRUE : Boolean.FALSE);
        return found.get();
    }

    private Node getAST(X10ClassDef container) {
        // obtain the job for containing the constructor declaration
        Job cjob = container.job();
        if (cjob == null || cjob.ast() == null)
            return null;

        if (cjob == this.job())
            // current class
            return cjob.ast();

        // run the preliminary compilation phases on the job's AST
        Node ast = cjob.ast();
        assert (ast instanceof X10SourceFile_c);
        if (!((X10SourceFile_c) ast).hasBeenTypeChecked())
            ast = ast.visit(new X10TypeChecker(cjob, ts, nf, cjob.nodeMemo()).begin());
        if (ast == null)
            return null;
        if (!((X10Ext)ast.ext()).subtreeValid())
            return null;

        ast = ast.visit(new Desugarer(cjob, ts, nf).begin());
        return ast;
    }

    private ProcedureDecl getProcedureDeclaration(final X10ProcedureDef candidate, X10ClassDef container) {
        ProcedureDecl r = procDeclCache.get(candidate);
        if (r != null) return r;

        // obtain X10SourceFile ast of the target class that already runs preliminary compilation phases
        final Node ast = getAST(container);
        if (ast == null)
            return null;

        // find the target declaration of constructor or method
        final ProcedureDecl[] decl = new ProcedureDecl[1];
        ast.visit(new NodeVisitor() {
            @Override
			public Node override(Node n) {
                if (decl[0] != null)
                    // already found the decl, short-circuit search
                    return n;
                if (n instanceof X10FieldDecl)
                    // not contain ctor decls, short-circuit search
                    return n;
                if (n instanceof X10MethodDecl) {
                    if (candidate == ((X10MethodDecl) n).methodDef()) {
                        // found it!!
                        decl[0] = (X10MethodDecl) n;
                    }
                    return n;
                }
                if (n instanceof X10ConstructorDecl) {
                    if (candidate == ((X10ConstructorDecl) n).constructorDef()) {
                        // found it!!
                        decl[0] = (X10ConstructorDecl) n;
                    }
                    return n;
                }
                // continue traversal
                return null;
            }
        });
        if (decl[0] == null || decl[0].body() == null) {
            return null;
        }
        procDeclCache.put(candidate, decl[0]);
        return decl[0];
    }

    private X10ConstructorDecl getConstructorDeclaration(X10ConstructorInstance ci) {
        X10ConstructorDef cd = ci.x10Def();
        X10ClassType containerBase = (X10ClassType) Types.get(cd.container());
        X10ClassDef container = containerBase.x10Def();
        if (container == null)
            return null;
        return (X10ConstructorDecl)getProcedureDeclaration(cd, container);
    }

    private X10MethodDecl getMethodDeclaration(MethodInstance mi) {
        X10MethodDef md = mi.x10Def();
        // get container and declaration for method
        X10ClassType containerBase = (X10ClassType) Types.get(md.container());
        X10ClassDef container = containerBase.x10Def();
        if (container == null)
            return null;
        return (X10MethodDecl)getProcedureDeclaration(md, container);
    }

    private MethodDecl makeInitMethod(Position pos, Name fName, StaticFieldInfo fieldInfo,
                                      FieldDef fdCond, X10ClassDef classDef) {
        // get MethodDef
        Name name = Name.make(initializerPrefix+fName);
        Type type = fieldInfo.right.type();
        MethodDef md = fieldInfo.methodDef;
        if (md == null)
            md = makeMethodDef(classDef.asType(), name, type);

        // create a method declaration node
        List<TypeParamNode> typeParamNodes = Collections.<TypeParamNode>emptyList();
        List<Formal> formals = Collections.<Formal>emptyList();

        TypeNode returnType = xnf.X10CanonicalTypeNode(pos, type);
        Block body = makeInitMethodBody(pos, fieldInfo, fdCond, classDef);
        MethodDecl result = xnf.X10MethodDecl(pos, xnf.FlagsNode(pos, Flags.STATIC), returnType, xnf.Id(pos, name),
                                              typeParamNodes, formals, null, null, body);
        // associate methodDef with methodDecl
        result = result.methodDef(md);
        return result;
    }

    private Block makeInitMethodBody(Position pos, StaticFieldInfo initInfo, FieldDef fdCond,
                                     X10ClassDef classDef) {

        TypeNode receiver = xnf.X10CanonicalTypeNode(pos, classDef.asType());
        Expr ifCond = genGuard(pos, receiver, fdCond);

        FieldInstance fi = initInfo.fieldDef.asInstance();
        Expr right = initInfo.right;
        Name name = initInfo.fieldDef.name();
        Expr left = xnf.Field(pos, receiver, xnf.Id(pos, name)).fieldInstance(fi).type(right.type());

        // make statement block of initialization
        List<Stmt> stmts = new ArrayList<Stmt>();
        stmts.add(xnf.Eval(pos, xnf.FieldAssign(pos, receiver, xnf.Id(pos, name), Assign.ASSIGN,
                                                right).fieldInstance(fi).type(right.type())));

        stmts.add(xnf.Eval(pos, genStatusSet(pos, receiver, fdCond)));
        Block initBody = xnf.Block(pos, stmts);

        stmts =  new ArrayList<Stmt>();

        // make statement block of the entire method body
        stmts =  new ArrayList<Stmt>();
        stmts.add(xnf.If(pos, ifCond, initBody));
        Expr returnVal = left;
        stmts.add(xnf.X10Return(pos, returnVal, false));
        Block body = xnf.Block(pos, stmts);
        return body;
    }

    private Expr genGuard(Position pos, TypeNode receiver, FieldDef fdCond) {
        FieldInstance fi = fdCond.asInstance();
        Expr ai  = xnf.Field(pos, receiver, xnf.Id(pos, fdCond.name())).fieldInstance(fi).type(fi.type());
        Expr ar  = getInitDispatcherConstant(pos, INIT_DISPATCHER_INITIALIZED).type(xts.Int());
        Expr neq = xnf.Binary(pos, ai, Operator.NE, ar);
        return neq;
    }

    private Expr genStatusSet(Position pos, TypeNode receiver, FieldDef fdCond) {
        Expr ar = getInitDispatcherConstant(pos, INIT_DISPATCHER_INITIALIZED).type(xts.Int());
        return xnf.FieldAssign(pos, receiver, xnf.Id(pos, fdCond.name()),
                Assign.ASSIGN, ar).fieldInstance(fdCond.asInstance()).type(xts.Int());
    }

	private Expr getInitDispatcherConstant(Position pos, String name) {
		FieldInstance fi = InitDispatcher().fieldNamed(Name.make(name));
		Id id = xnf.Id(pos, Name.make(name));
		Receiver receiver = xnf.CanonicalTypeNode(pos, InitDispatcher());
		return xnf.Field(pos, receiver, id).fieldInstance(fi);
	}

    private MethodDecl makeFakeInitMethod(Position pos, Name fName, StaticFieldInfo fieldInfo, X10ClassDef classDefParam) {
        // get MethodDef
        Name name = Name.make(initializerPrefix+fName);
        FieldInstance fi = fieldInfo.fieldDef.asInstance();
        MethodDef md = makeMethodDef(classDefParam.asType(), name, fi.type());

        // create a method declaration node
        List<TypeParamNode> typeParamNodes = Collections.<TypeParamNode>emptyList();
        List<Formal> formals = Collections.<Formal>emptyList();

        // get field reference
        X10ClassDef classDef = classDefParam;
        if (classDef.isMember() && classDef.outer().get().flags().isInterface())
            // should refer to fields in the outer interface
            classDef = classDef.outer().get();
        TypeNode receiver = xnf.X10CanonicalTypeNode(pos, classDef.asType());
        Expr left = xnf.Field(pos, receiver, xnf.Id(pos, fieldInfo.fieldDef.name())).fieldInstance(fi).type(fi.type());

        // make statement block
        List<Stmt> stmts = new ArrayList<Stmt>();
        stmts.add(xnf.X10Return(pos, left, false));
        Block body = xnf.Block(pos, stmts);

        // create method declaration
        TypeNode returnType = xnf.X10CanonicalTypeNode(pos, fi.type());
        MethodDecl result = xnf.X10MethodDecl(pos, xnf.FlagsNode(pos, Flags.STATIC), returnType, xnf.Id(pos, name),
                                              typeParamNodes, formals, null, null, body);
        // associate methodDef with methodDecl
        result = result.methodDef(md);
        return result;
    }

	private Stmt makeAddInitializer(Position pos, StaticFieldInfo fieldInfo, X10ClassDef classDef) {
		FieldDef def = fieldInfo.fieldDef;
		Id id = xnf.Id(pos, def.name());
		// replace with a static method call
		Type targetType = classDef.asType();
		if (targetType instanceof ParsedClassType) {
			X10ClassDef targetClassDef = ((ParsedClassType) targetType).def();
			if (targetClassDef.flags().isInterface())
				// target nested shadow class within interface
				targetType = getShadowClassDef(targetClassDef).asType();
		} else if (targetType instanceof ConstrainedType)
			targetType = ((ConstrainedType) targetType).baseType().get();

		X10ClassType receiver = (X10ClassType) targetType;
		Type retType = def.type().get();
		return xnf.Eval(pos, makeStaticCall(pos, receiver, id, retType));
	}

    private StaticFieldInfo getFieldEntry(Type target, Name name) {
        Pair<Type,Name> key = new Pair<Type,Name>(target, name);
        StaticFieldInfo fieldInfo = staticFinalFields.get(key);
        if (fieldInfo == null) {
            fieldInfo = new StaticFieldInfo();
            staticFinalFields.put(key, fieldInfo);
        }
        return fieldInfo;
    }

    private boolean checkFieldRefReplacementRequired(X10Field_c f) {
        Pair<Type,Name> key = new Pair<Type,Name>(f.target().type(), f.name().id());
        StaticFieldInfo fieldInfo = staticFinalFields.get(key);
        // not yet registered, or registered as replacement required
        return fieldInfo == null || fieldInfo.right != null || fieldInfo.methodDef != null;
    }

    private ClassType InitDispatcher_;
    private ClassType InitDispatcher() {
        if (InitDispatcher_ == null)
            InitDispatcher_ = xts.load("x10.compiler.InitDispatcher");
        return InitDispatcher_;
    }

    private static class StaticFieldInfo {
        protected Expr right;             // RHS expression, if replaced with initialization method
        protected MethodDef methodDef;    // getInitialized methodDef to be replaced
        protected FieldDef fieldDef;
        protected FieldDecl left;         // field declaration to be moved from interface to a shadow class
    }
}
