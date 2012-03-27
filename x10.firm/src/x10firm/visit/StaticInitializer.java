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
import polyglot.types.TypeSystem_c;
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
import x10.ast.X10NodeFactory_c;
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

/**
 * Lowering of all non const static initializer.
 */
public class StaticInitializer extends ContextVisitor {
	private final TypeSystem_c xts;
	private final X10NodeFactory_c xnf;

	private final WeakHashMap<X10ProcedureDef, ProcedureDecl> procDeclCache
		= new WeakHashMap<X10ProcedureDef, ProcedureDecl>();
	private final WeakHashMap<Block, Boolean> procBodyCache = new WeakHashMap<Block, Boolean>();
	/** caches shadow classes. */
	private static Map<X10ClassDef, X10ClassDef> shadowClassMap = new HashMap<X10ClassDef, X10ClassDef>();

	private final X10CompilerOptions opts = (X10CompilerOptions) job.extensionInfo().getOptions();

	private static final String INITIALIZER_PREFIX = "getInitialized$";
	private static final String INIT_STATUS_PREFIX = "initStatus$";
	private static final String NESTED_SHADOW_CLASS4INTERFACE = "Shadow";
	private static final String INIT_DIPSPATCHER_UNINITIALIZED = "UNINITIALIZED";
	private static final String INIT_DISPATCHER_INITIALIZED = "INITIALIZED";

	/** maps static fields to corresponding initializer method. */
	private final Map<Pair<Type, Name>, StaticFieldInfo> staticFinalFields = CollectionFactory.newHashMap();

	/** Constructs a new StaticInitializer. */
	public StaticInitializer(final Job job, final TypeSystem_c ts, final X10NodeFactory_c nf) {
		super(job, ts, nf);
		xts = ts;
		xnf = nf;
	}

	@Override
	protected Node leaveCall(final Node parent, final Node old, final Node n,
			final NodeVisitor v) throws SemanticException {
		if (!(parent instanceof X10ClassDecl_c))
			return n;

		final X10ClassDecl_c ct = (X10ClassDecl_c) parent;
		if (old != ct.body())
			return n;

		ClassBody classBody = (ClassBody) n;
		final X10ClassDef classDef = ct.classDef();
		assert classDef != null;

		final Context cntxt = ct.enterChildScope(classBody, ((ContextVisitor) v).context());

		// collect static fields to deal with
		staticFinalFields.clear();
		// classBody.dump(System.err);
		// System.out.println("StaticInitilizer for "+classDef);
		classBody = checkStaticFields(classBody, cntxt);

		if (staticFinalFields.isEmpty())
			// nothing to do
			return classBody;

		final List<ClassMember> currMembers = new ArrayList<ClassMember>();
		currMembers.addAll(classBody.members());

		if (!ct.flags().flags().isInterface()) {
			// create a new member list for initializer/deserializer methods of
			// each static field
			final List<ClassMember> newMembers = createNewMembers(classDef);
			currMembers.addAll(newMembers);
		} else {

			// create a nested shadow class
			X10ClassDecl shadowDecl = createNestedShadowClass(ct);

			// create a new member list for the shadow class just created
			final List<ClassMember> newMembers = createNewMembers(shadowDecl.classDef());

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

	private List<ClassMember> createNewMembers(final X10ClassDef classDef) {
		final Position pos = Position.compilerGenerated(null);
		final List<ClassMember> members = new ArrayList<ClassMember>();
		final List<Stmt> initStmts = new ArrayList<Stmt>();

		// we must collect all needed static field infos, because we
		// can`t modify the staticFinalFields field while iterating over it
		// (ConcurrentModificationException)
		final List<StaticFieldInfo> initFields = new LinkedList<StaticFieldInfo>();

		for (final Map.Entry<Pair<Type, Name>, StaticFieldInfo> entry : staticFinalFields.entrySet()) {
			final Name fName = entry.getKey().snd();
			final StaticFieldInfo fieldInfo = entry.getValue();

			if (fieldInfo.right == null && fieldInfo.fieldDef == null)
				continue;

			MethodDecl md = null;
			if (fieldInfo.right != null) {

				// gen new field var
				final FieldDecl fdCond = makeFieldVar4Guard(pos, fName, classDef);
				classDef.addField(fdCond.fieldDef());
				// add in the top
				members.add(0, fdCond);

				if (fieldInfo.left != null) {
					// interface case: add field declaration to the shadow class
					final FieldDef fd = fieldInfo.left.fieldDef();
					final Flags newFlags = fd.container().get().toClass().flags().clearInterface();
					final Ref<X10ClassType> typeRef = Types.ref(classDef.asType());
					final FieldDef newFd = xts.fieldDef(pos, typeRef, newFlags, fd.type(), fd.name());
					members.add(0, fieldInfo.left.fieldDef(newFd));
				}

				// gen new initialize method
				md = makeInitMethod(pos, fName, fieldInfo, fdCond.fieldDef(), classDef);

				initFields.add(fieldInfo);
			} else {
				// gen a fake initialization method
				md = makeFakeInitMethod(pos, fName, fieldInfo, classDef);
			}
			classDef.addMethod(md.methodDef());
			// add in the bottom
			members.add(md);
		}

		for (final StaticFieldInfo sfi : initFields) {
			// register in the table for x10-level static initialization later
			initStmts.add(makeAddInitializer(pos, sfi, classDef));
		}

		if (!initStmts.isEmpty()) {
			// gen initializer block
			final Block initBlockBody = xnf.Block(pos, initStmts);
			Initializer initBlock = xnf.Initializer(pos, xnf.FlagsNode(pos, Flags.STATIC), initBlockBody);
			// create InitializerDef
			final InitializerDef id = xts.initializerDef(pos, Types.ref(classDef.asType()), Flags.STATIC);
			initBlock = initBlock.initializerDef(id);
			members.add(initBlock);
		}
		return members;
	}

	private X10ClassDecl createNestedShadowClass(final ClassDecl_c interfaceClass) {
		// create ClassDef first
		final X10ClassDef cDef = getShadowClassDef(interfaceClass.classDef());

		// create ClassDecl
		final Position pos = Position.compilerGenerated(null);
		final FlagsNode fNode = xnf.FlagsNode(pos, cDef.flags());
		final Id id = xnf.Id(pos, cDef.name());
		final TypeNode superTN = xnf.CanonicalTypeNode(pos, cDef.superType());
		final List<ClassMember> cmembers = new ArrayList<ClassMember>();
		final ClassBody body = xnf.ClassBody(pos, cmembers);
		final List<TypeNode> interfaceTN = Collections.<TypeNode>emptyList();
		final X10ClassDecl cDecl = xnf.ClassDecl(pos, fNode, id, superTN, interfaceTN, body).classDef(cDef);
		return cDecl;
	}

	private X10ClassDef getShadowClassDef(final X10ClassDef interfaceClassDef) {
		X10ClassDef cDef = shadowClassMap.get(interfaceClassDef);
		if (cDef != null)
			return cDef;

		cDef = xts.createClassDef(interfaceClassDef.sourceFile());
		cDef.superType(Types.ref(xts.Any()));
		final List<Ref<? extends Type>> interfacesRef = Collections.<Ref<? extends Type>>emptyList();
		cDef.setInterfaces(interfacesRef);
		cDef.name(Name.make(NESTED_SHADOW_CLASS4INTERFACE));
		cDef.setFlags(Flags.PUBLIC.Abstract());
		cDef.kind(ClassDef.MEMBER);
		cDef.outer(Types.ref(interfaceClassDef));

		shadowClassMap.put(interfaceClassDef, cDef);

		return cDef;
	}

	private ClassBody checkStaticFields(final ClassBody body, final Context cntxt) {
		final X10ClassDef cd = cntxt.currentClassDef();
		// one pass scan of class body and collect vars for static
		// initialization
		final ClassBody c = (ClassBody) body.visit(new NodeVisitor() {
			@Override
			public Node override(final Node parent, final Node n) {
				if (n instanceof X10ClassDecl_c) {
					// should not visit subtree of inner class (already done)
					return n;
				}
				return null;
			}

			@Override
			public Node leave(final Node parent, final Node old, final Node n, final NodeVisitor v) {
				if (n instanceof X10FieldDecl) {
					final X10FieldDecl fd = (X10FieldDecl) n;
					final Flags flags = fd.fieldDef().flags();
					if (ASTQuery.isPerProcess(xts, fd.fieldDef()))
						return n;
					if (flags.isFinal() && flags.isStatic()) {
						// static final field
						final StaticFieldInfo fieldInfo = checkFieldDeclRHS(fd, cd);
						if (fieldInfo.right != null) {
							final FlagsNode fn = xnf.FlagsNode(fd.position(), flags.clearFinal());
							final Expr init = getDefaultValue(fd.position(), fd.init().type());
							final FieldDecl newDecl = xnf.FieldDecl(fd.position(), fn, fd.type(), fd.name(), init)
									.fieldDef(fd.fieldDef());
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
					final X10Field_c f = (X10Field_c) n;
					if (ASTQuery.isPerProcess(xts, f.fieldInstance().x10Def()))
						return n;
					if (f.flags().isFinal() && f.flags().isStatic()) {
						// found reference to static field
						if (checkFieldRefReplacementRequired(f)) {
							// replace with a static method call
							Type targetType = f.target().type();
							if (targetType instanceof ParsedClassType) {
								final X10ClassDef targetClassDef = ((ParsedClassType) targetType).def();
								if (targetClassDef.flags().isInterface())
									// target nested shadow class within
									// interface
									targetType = getShadowClassDef(targetClassDef).asType();
							} else if (targetType instanceof ConstrainedType) {
								targetType = ((ConstrainedType) targetType).baseType().get();
							}

							final X10ClassType receiver = (X10ClassType) targetType;
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
		final Id leftName = fd.name();

		// true means
		// "found something not suitable for per-place initialization"
		final AtomicBoolean found = new AtomicBoolean(false);
		final boolean deepAnalysis = opts.x10_config.STATICS_PER_PLACE_ANALYSIS;
		fd.init().visit(new NodeVisitor() {
			@Override
			public Node override(final Node parent, final Node n) {
				if (found.get())
					// already found
					return n;

				if (n instanceof Expr) {
					if (ASTQuery.isGlobalInit(xts, fd)) {
						// initialization can be done in all places -- do not
						// visit subtree further
						// System.out.println("isGlobalInit true in checkFieldDeclRHS: "+(Expr)n);
						return n;
					}
				}
				if (n instanceof X10Call_c) {
					final X10Call call = (X10Call) n;
					final MethodInstance mi = call.methodInstance();
					if (deepAnalysis && mi.flags().isStatic()) {
						// found reference to static method
						final X10MethodDecl mdecl = getMethodDeclaration(mi);
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
					final X10Field_c f = (X10Field_c) n;
					if (f.flags().isFinal() && f.flags().isStatic()) {
						// found reference to static field
						if (checkFieldRefReplacementRequired(f)) {
							found.set(true);
							return n;
						}
					}
				} else if (n instanceof X10New_c) {
					if (deepAnalysis) {
						final X10New_c neu = (X10New_c) n;
						final X10ConstructorInstance ci = neu.constructorInstance();
						// get declaration of constructor
						final X10ConstructorDecl cdecl = getConstructorDeclaration(ci);
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
					// else if (!opts.x10_config.MULTI_NODE &&
					// checkMultiplexRequiredSingleVM(ci)) {
					// found.set(true);
					// }
				}
				// continue traversal
				return null;
			}
		});

		// register original rhs
		final X10ClassType receiver = cd.asType();
		final StaticFieldInfo fieldInfo = getFieldEntry(receiver, leftName.id());

		fieldInfo.right = ASTQuery.isGlobalInit(xts, fd) ? null : fd.init();
		fieldInfo.fieldDef = fd.fieldDef();

		return fieldInfo;
	}

	private Call makeStaticCall(final Position pos, final X10ClassType receiver, final Id id, final Type returnType) {
		// create MethodDef
		final Name name = Name.make(INITIALIZER_PREFIX + id);
		final StaticFieldInfo fieldInfo = getFieldEntry(receiver, id.id());
		MethodDef md = fieldInfo.methodDef;
		if (md == null) {
			md = makeMethodDef(receiver, name, returnType);
			fieldInfo.methodDef = md;
		}

		// create static call for initialization
		final List<TypeNode> typeArgsN = Collections.<TypeNode>emptyList();
		final List<Expr> args = Collections.<Expr>emptyList();
		final MethodInstance mi = xts.createMethodInstance(pos, Types.ref(md));
		final Call result = (Call) xnf
				.X10Call(pos, xnf.CanonicalTypeNode(pos, receiver), xnf.Id(pos, name), typeArgsN, args)
				.methodInstance(mi).type(returnType);
		return result;
	}

	private MethodDef makeMethodDef(final X10ClassType receiver, final Name name, final Type returnType) {
		final Position pos = Position.compilerGenerated(null);
		final List<Ref<? extends Type>> argTypes = Collections.<Ref<? extends Type>>emptyList();
		final MethodDef md = xts.methodDef(pos, Types.ref(receiver), Flags.STATIC, Types.ref(returnType), name,
				argTypes);
		return md;
	}

	private FieldDecl makeFieldVar4Guard(final Position pos, final Name fName, final X10ClassDef classDef) {
		// make FieldDef of AtomicInteger
		final ClassType type = xts.Int();
		final Flags flags = Flags.PRIVATE.Static();

		final Name name = Name.make(INIT_STATUS_PREFIX + fName);
		final FieldDef fd = xts.fieldDef(pos, Types.ref(classDef.asType()), flags, Types.ref(type), name);

		// create right hand side: InitDispatcher.UNINITIALIZED
		final TypeNode tn = xnf.X10CanonicalTypeNode(pos, type);
		final Expr init = getInitDispatcherConstant(pos, INIT_DIPSPATCHER_UNINITIALIZED).type(xts.Int());

		// fieldDecl and its association with fieldDef
		FieldDecl result = xnf.FieldDecl(pos, xnf.FlagsNode(pos, flags), tn, xnf.Id(pos, name), init);
		result = result.fieldDef(fd);
		return result;
	}

	private Expr getDefaultValue(final Position pos, final Type type) {
		if (type.isBoolean()) {
			return xnf.BooleanLit(pos, false).type(type);
		} else if (type.isChar()) {
			return xnf.CharLit(pos, ' ').type(type);
		} else if (type.isByte() || type.isShort() || type.isInt()) {
			return xnf.IntLit(pos, IntLit.INT, 0).type(type);
		} else if (type.isLong()) {
			return xnf.IntLit(pos, IntLit.LONG, 0).type(type);
		} else if (type.isFloat()) {
			return xnf.FloatLit(pos, FloatLit.FLOAT, 0.0).type(type);
		} else if (type.isDouble()) {
			return xnf.FloatLit(pos, FloatLit.DOUBLE, 0.0).type(type);
		} else if (type == xts.String()) {
			return xnf.NullLit(pos).type(type);
		} else if (xts.isSubtype(type, xts.UByte()) || xts.isSubtype(type, xts.UShort())
				|| xts.isSubtype(type, xts.UInt()) || xts.isSubtype(type, xts.ULong())) {
			final ConstructorDef cd = xts.defaultConstructor(pos, Types.ref((ClassType) type));
			final ConstructorInstance ci = xts.createConstructorInstance(pos, Types.ref(cd));
			final List<Expr> args = new ArrayList<Expr>();
			args.add(xnf.IntLit(pos, IntLit.INT, 0).type(type));
			return xnf.New(pos, xnf.X10CanonicalTypeNode(pos, type), args).constructorInstance(ci).type(type);
		} else {
			return null;
		}
	}

	private static final int SEARCH_CUT = 7;

	private boolean checkProcedureBody(final Block body, final int count) {
		final Boolean r = procBodyCache.get(body);
		if (r != null)
			return r == Boolean.TRUE;

		// Cut the search tree to avoid overly long compilation time.
		// True means centralized place-0 initialization is necessary,
		// which is a safe conservative assumption.
		if (count > SEARCH_CUT)
			return true;

		// check static field references in the body of constructor or method
		final AtomicBoolean found = new AtomicBoolean(false);
		body.visit(new NodeVisitor() {
			@Override
			public Node override(final Node n) {
				if (found.get())
					// already found
					return n;
				if (n instanceof X10Call) {
					final X10Call call = (X10Call) n;
					final MethodInstance mi = call.methodInstance();
					if (!mi.container().isClass() || call.target().type().isNumeric()) {
						// allow method calls on non-objects or numerics
					} else if (mi.flags().isStatic()) {
						// found reference to special initializer method
						final X10MethodDecl mdecl = getMethodDeclaration(mi);
						if (mdecl == null || checkProcedureBody(mdecl.body(), count + 1)) {
							// target method is unsafe include static field
							// references
							found.set(true);
							return n;
						}
					} else {
						// we consider non-static method call as unsafe
						found.set(true);
						return n;
					}
				} else if (n instanceof X10Field_c) {
					final X10Field_c f = (X10Field_c) n;
					if (f.flags().isFinal() && f.flags().isStatic()) {
						if (checkFieldRefReplacementRequired(f)) {
							// found reference to static field to be replaced
							found.set(true);
							return n;
						}
					}
				} else if (n instanceof X10New_c) {
					final X10New_c neu = (X10New_c) n;
					final X10ConstructorInstance ci = neu.constructorInstance();
					// get declaration of constructor
					final X10ConstructorDecl cdecl = getConstructorDeclaration(ci);
					if (cdecl != null && !cdecl.body().equals(body) && checkProcedureBody(cdecl.body(), count + 1)) {
						// constructor include static field references to be
						// replaced
						found.set(true);
						return n;
					}
					// else if (!opts.x10_config.MULTI_NODE &&
					// checkMultiplexRequiredSingleVM(ci)) {
					// found.set(true);
					// }
				}
				// continue traversal
				return null;
			}
		});
		procBodyCache.put(body, found.get() ? Boolean.TRUE : Boolean.FALSE);
		return found.get();
	}

	private Node getAST(final X10ClassDef container) {
		// obtain the job for containing the constructor declaration
		final Job cjob = container.job();
		if (cjob == null || cjob.ast() == null)
			return null;

		if (cjob == this.job())
			// current class
			return cjob.ast();

		// run the preliminary compilation phases on the job's AST
		Node ast = cjob.ast();
		assert ast instanceof X10SourceFile_c;
		if (!((X10SourceFile_c) ast).hasBeenTypeChecked())
			ast = ast.visit(new X10TypeChecker(cjob, ts, nf, cjob.nodeMemo()).begin());
		if (ast == null)
			return null;
		if (!((X10Ext) ast.ext()).subtreeValid())
			return null;

		ast = ast.visit(new Desugarer(cjob, ts, nf).begin());
		return ast;
	}

	private ProcedureDecl getProcedureDeclaration(final X10ProcedureDef candidate, final X10ClassDef container) {
		final ProcedureDecl r = procDeclCache.get(candidate);
		if (r != null)
			return r;

		// obtain X10SourceFile ast of the target class that already runs
		// preliminary compilation phases
		final Node ast = getAST(container);
		if (ast == null)
			return null;

		// find the target declaration of constructor or method
		final ProcedureDecl[] decl = new ProcedureDecl[1];
		ast.visit(new NodeVisitor() {
			@Override
			public Node override(final Node n) {
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

	private X10ConstructorDecl getConstructorDeclaration(final X10ConstructorInstance ci) {
		final X10ConstructorDef cd = ci.x10Def();
		final X10ClassType containerBase = (X10ClassType) Types.get(cd.container());
		final X10ClassDef container = containerBase.x10Def();
		if (container == null)
			return null;
		return (X10ConstructorDecl) getProcedureDeclaration(cd, container);
	}

	private X10MethodDecl getMethodDeclaration(final MethodInstance mi) {
		final X10MethodDef md = mi.x10Def();
		// get container and declaration for method
		final X10ClassType containerBase = (X10ClassType) Types.get(md.container());
		final X10ClassDef container = containerBase.x10Def();
		if (container == null)
			return null;
		return (X10MethodDecl) getProcedureDeclaration(md, container);
	}

	private MethodDecl makeInitMethod(final Position pos, final Name fName, final StaticFieldInfo fieldInfo,
			final FieldDef fdCond, final X10ClassDef classDef) {
		// get MethodDef
		final Name name = Name.make(INITIALIZER_PREFIX + fName);
		final Type type = fieldInfo.right.type();
		MethodDef md = fieldInfo.methodDef;
		if (md == null)
			md = makeMethodDef(classDef.asType(), name, type);

		// create a method declaration node
		final List<TypeParamNode> typeParamNodes = Collections.<TypeParamNode>emptyList();
		final List<Formal> formals = Collections.<Formal>emptyList();

		final TypeNode returnType = xnf.X10CanonicalTypeNode(pos, type);
		final Block body = makeInitMethodBody(pos, fieldInfo, fdCond, classDef);
		MethodDecl result = xnf.X10MethodDecl(pos, xnf.FlagsNode(pos, Flags.STATIC), returnType, xnf.Id(pos, name),
				typeParamNodes, formals, null, null, body);
		// associate methodDef with methodDecl
		result = result.methodDef(md);
		return result;
	}

	private Block makeInitMethodBody(final Position pos, final StaticFieldInfo initInfo, final FieldDef fdCond,
			final X10ClassDef classDef) {

		final TypeNode receiver = xnf.X10CanonicalTypeNode(pos, classDef.asType());
		final Expr ifCond = genGuard(pos, receiver, fdCond);

		final FieldInstance fi = initInfo.fieldDef.asInstance();
		final Expr right = initInfo.right;
		final Name name = initInfo.fieldDef.name();
		final Expr left = xnf.Field(pos, receiver, xnf.Id(pos, name)).fieldInstance(fi).type(right.type());

		// make statement block of initialization
		List<Stmt> stmts = new ArrayList<Stmt>();
		stmts.add(xnf.Eval(
				pos,
				xnf.FieldAssign(pos, receiver, xnf.Id(pos, name), Assign.ASSIGN, right).fieldInstance(fi)
						.type(right.type())));

		stmts.add(xnf.Eval(pos, genStatusSet(pos, receiver, fdCond)));
		final Block initBody = xnf.Block(pos, stmts);

		stmts = new ArrayList<Stmt>();

		// make statement block of the entire method body
		stmts = new ArrayList<Stmt>();
		stmts.add(xnf.If(pos, ifCond, initBody));
		final Expr returnVal = left;
		stmts.add(xnf.X10Return(pos, returnVal, false));
		final Block body = xnf.Block(pos, stmts);
		return body;
	}

	private Expr genGuard(final Position pos, final TypeNode receiver, final FieldDef fdCond) {
		final FieldInstance fi = fdCond.asInstance();
		final Expr ai = xnf.Field(pos, receiver, xnf.Id(pos, fdCond.name())).fieldInstance(fi).type(fi.type());
		final Expr ar = getInitDispatcherConstant(pos, INIT_DISPATCHER_INITIALIZED).type(xts.Int());
		final Expr neq = xnf.Binary(pos, ai, Operator.NE, ar);
		return neq;
	}

	private Expr genStatusSet(final Position pos, final TypeNode receiver, final FieldDef fdCond) {
		final Expr ar = getInitDispatcherConstant(pos, INIT_DISPATCHER_INITIALIZED).type(xts.Int());
		return xnf.FieldAssign(pos, receiver, xnf.Id(pos, fdCond.name()), Assign.ASSIGN, ar)
				.fieldInstance(fdCond.asInstance()).type(xts.Int());
	}

	private Expr getInitDispatcherConstant(final Position pos, final String name) {
		final FieldInstance fi = initDispatcher().fieldNamed(Name.make(name));
		final Id id = xnf.Id(pos, Name.make(name));
		final Receiver receiver = xnf.CanonicalTypeNode(pos, initDispatcher());
		return xnf.Field(pos, receiver, id).fieldInstance(fi);
	}

	private MethodDecl makeFakeInitMethod(final Position pos, final Name fName, final StaticFieldInfo fieldInfo,
			final X10ClassDef classDefParam) {
		// get MethodDef
		final Name name = Name.make(INITIALIZER_PREFIX + fName);
		final FieldInstance fi = fieldInfo.fieldDef.asInstance();
		final MethodDef md = makeMethodDef(classDefParam.asType(), name, fi.type());

		// create a method declaration node
		final List<TypeParamNode> typeParamNodes = Collections.<TypeParamNode>emptyList();
		final List<Formal> formals = Collections.<Formal>emptyList();

		// get field reference
		X10ClassDef classDef = classDefParam;
		if (classDef.isMember() && classDef.outer().get().flags().isInterface())
			// should refer to fields in the outer interface
			classDef = classDef.outer().get();
		final TypeNode receiver = xnf.X10CanonicalTypeNode(pos, classDef.asType());
		final Id id = xnf.Id(pos, fieldInfo.fieldDef.name());
		final Expr left = xnf.Field(pos, receiver, id).fieldInstance(fi).type(fi.type());

		// make statement block
		final List<Stmt> stmts = new ArrayList<Stmt>();
		stmts.add(xnf.X10Return(pos, left, false));
		final Block body = xnf.Block(pos, stmts);

		// create method declaration
		final TypeNode returnType = xnf.X10CanonicalTypeNode(pos, fi.type());
		MethodDecl result = xnf.X10MethodDecl(pos, xnf.FlagsNode(pos, Flags.STATIC), returnType, xnf.Id(pos, name),
				typeParamNodes, formals, null, null, body);
		// associate methodDef with methodDecl
		result = result.methodDef(md);
		return result;
	}

	private Stmt makeAddInitializer(final Position pos, final StaticFieldInfo fieldInfo, final X10ClassDef classDef) {
		final FieldDef def = fieldInfo.fieldDef;
		final Id id = xnf.Id(pos, def.name());
		// replace with a static method call
		Type targetType = classDef.asType();
		if (targetType instanceof ParsedClassType) {
			final X10ClassDef targetClassDef = ((ParsedClassType) targetType).def();
			if (targetClassDef.flags().isInterface())
				// target nested shadow class within interface
				targetType = getShadowClassDef(targetClassDef).asType();
		} else if (targetType instanceof ConstrainedType)
			targetType = ((ConstrainedType) targetType).baseType().get();

		final X10ClassType receiver = (X10ClassType) targetType;
		final Type retType = def.type().get();
		return xnf.Eval(pos, makeStaticCall(pos, receiver, id, retType));
	}

	private StaticFieldInfo getFieldEntry(final Type target, final Name name) {
		final Pair<Type, Name> key = new Pair<Type, Name>(target, name);
		StaticFieldInfo fieldInfo = staticFinalFields.get(key);
		if (fieldInfo == null) {
			fieldInfo = new StaticFieldInfo();
			staticFinalFields.put(key, fieldInfo);
		}
		return fieldInfo;
	}

	private boolean checkFieldRefReplacementRequired(final X10Field_c f) {
		final Pair<Type, Name> key = new Pair<Type, Name>(f.target().type(), f.name().id());
		final StaticFieldInfo fieldInfo = staticFinalFields.get(key);
		// not yet registered, or registered as replacement required
		return fieldInfo == null || fieldInfo.right != null || fieldInfo.methodDef != null;
	}

	private ClassType initDispatcher;

	private ClassType initDispatcher() {
		if (initDispatcher == null)
			initDispatcher = xts.load("x10.compiler.InitDispatcher");
		return initDispatcher;
	}

	/** Information about a static field. */
	private static class StaticFieldInfo {
		/** RHS expression, if replaced with initialization method. */
		private Expr right;
		/** getInitialized methodDef to be replaced. */
		private MethodDef methodDef;
		private FieldDef fieldDef;
		/** field declaration to be moved from interface to a shadow class. */
		private FieldDecl left;
	}
}
