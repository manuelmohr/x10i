/*
 *  This file is part of the X10 project (http://x10-lang.org).
 *
 *  This file is licensed to You under the Eclipse Public License (EPL);
 *  You may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *      http://www.opensource.org/licenses/eclipse-1.0.php
 *
 *  (C) Copyright IBM Corporation 2006-2010.
 */
package x10firm.visit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.WeakHashMap;
import java.util.concurrent.atomic.AtomicBoolean;

import polyglot.ast.Assign;
import polyglot.ast.Binary;
import polyglot.ast.Binary.Operator;
import polyglot.ast.Block;
import polyglot.ast.BooleanLit;
import polyglot.ast.Call;
import polyglot.ast.Cast;
import polyglot.ast.Catch;
import polyglot.ast.CharLit;
import polyglot.ast.ClassBody;
import polyglot.ast.ClassMember;
import polyglot.ast.Conditional;
import polyglot.ast.Expr;
import polyglot.ast.FieldDecl;
import polyglot.ast.FlagsNode;
import polyglot.ast.FloatLit;
import polyglot.ast.Formal;
import polyglot.ast.Id;
import polyglot.ast.IntLit;
import polyglot.ast.MethodDecl;
import polyglot.ast.Node;
import polyglot.ast.NodeFactory;
import polyglot.ast.NullLit;
import polyglot.ast.ProcedureDecl;
import polyglot.ast.Receiver;
import polyglot.ast.Return;
import polyglot.ast.Stmt;
import polyglot.ast.StringLit;
import polyglot.ast.TypeNode;
import polyglot.ast.Unary;
import polyglot.frontend.Job;
import polyglot.types.ClassDef;
import polyglot.types.ClassType;
import polyglot.types.ConstructorDef;
import polyglot.types.ConstructorInstance;
import polyglot.types.Context;
import polyglot.types.FieldDef;
import polyglot.types.FieldInstance;
import polyglot.types.Flags;
import polyglot.types.LocalDef;
import polyglot.types.MethodDef;
import polyglot.types.Name;
import polyglot.types.ParsedClassType;
import polyglot.types.QName;
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
import x10.ast.AnnotationNode;
import x10.ast.Closure;
import x10.ast.ClosureCall;
import x10.ast.ParExpr;
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
import x10.constraint.XTerm;
import x10.extension.X10Del;
import x10.extension.X10Ext;
import x10.types.ConstrainedType;
import x10.types.MethodInstance;
import x10.types.X10ClassDef;
import x10.types.X10ClassType;
import x10.types.X10ConstructorDef;
import x10.types.X10ConstructorInstance;
import x10.types.X10Def;
import x10.types.X10MethodDef;
import x10.types.X10ProcedureDef;
import x10.types.constraints.CConstraint;
import x10.util.CollectionFactory;
import x10.visit.Desugarer;
import x10.visit.X10TypeChecker;
import x10c.ast.X10CNodeFactory_c;

/**
 * lowers static initializer code to function calls with on-demand initialization
 * as required by the language specification.
 * (This is a rewritten/fixed version of the StaticInitializer class from the java
 * backend)
 *
 * @author matze
 */
public class StaticInitializer extends ContextVisitor {

	// XTENLANG-3081(part2)
	private static final boolean CHECKEXCEPTIONINCONSTANTEXPRESSION = true; // should be true

	private final TypeSystem xts;
	private final X10NodeFactory_c xnf;
	private final WeakHashMap<X10ProcedureDef, ProcedureDecl> procDeclCache;
	private final WeakHashMap<Block, Boolean> procBodyCache;

	private ClassType initDispatcher;
	private ClassType exceptionInInitializer;

	private MethodInstance compareAndSet;
	private MethodInstance lockInitialized;
	private MethodInstance unlockInitialized;
	private MethodInstance awaitInitialized;
	private MethodInstance notifyInitialized;

	private static final String INITIALIZERPREFIX = "get$";

	private static final String NESTEDSHADOWCLASS4INTERFACE = "$Shadow";

	// mapping static field and corresponding initializer method
	private final Map<Pair<Type, Name>, StaticFieldInfo> staticFinalFields =
			CollectionFactory.newHashMap();
	// for checking single vm mode
	private final X10CompilerOptions opts = (X10CompilerOptions) job.extensionInfo().getOptions();

	/** Initializes new StaticInitializer transformation visitor. */
	public StaticInitializer(final Job job, final TypeSystem ts, final NodeFactory nf) {
		super(job, ts, nf);
		xts = ts;
		xnf = (X10CNodeFactory_c) nf;
		procBodyCache = new WeakHashMap<Block, Boolean>();
		procDeclCache = new WeakHashMap<X10ProcedureDef, ProcedureDecl>();
	}

	private MethodInstance getMethodVoidNoarg(final String nameString) {
		final Name name = Name.make(nameString);
		final List<Type> argTypes = Collections.<Type>emptyList();
		final List<MethodInstance> mis = initDispatcher.methods(name, argTypes, xts.emptyContext());
		if (mis.size() != 1)
			throw new RuntimeException(String.format("Couldn't find method InitDispatcher.%s", name));
		return mis.get(0);
	}

	/** Search for some method(instances) used by all initializer functions. */
	private void initMethodInstances() {
		if (compareAndSet != null)
			return;

		initDispatcher = xts.load("x10.compiler.InitDispatcher");
		exceptionInInitializer = xts.load("x10.lang.ExceptionInInitializer");

		final List<Type> argTypes = new ArrayList<Type>();
		argTypes.add(xts.Int());
		argTypes.add(xts.Int());
		final X10ClassType atomicInteger = xts.AtomicInteger();
		final Name csName = Name.make("compareAndSet");
		final List<MethodInstance> mis = atomicInteger.methods(csName, argTypes, xts.emptyContext());
		if (mis.size() != 1)
			throw new RuntimeException("Couldn't find method AtomicInteger.compareAndSet");
		compareAndSet = mis.get(0);

		lockInitialized = getMethodVoidNoarg("lockInitialized");
		unlockInitialized = getMethodVoidNoarg("unlockInitialized");
		awaitInitialized = getMethodVoidNoarg("awaitInitialized");
		notifyInitialized = getMethodVoidNoarg("notifyInitialized");
	}

	@Override
	protected Node leaveCall(final Node parent, final Node old, final Node n, final NodeVisitor v)
		throws SemanticException {
		if (!(parent instanceof X10ClassDecl_c))
			return n;

		final X10ClassDecl_c ct = (X10ClassDecl_c) parent;
		if (old != ct.body())
			return n;

		ClassBody classBody = (ClassBody) n;
		final X10ClassDef classDef = ct.classDef();
		assert (classDef != null);

		final Context myContext = ct.enterChildScope(classBody, ((ContextVisitor) v).context());

		// collect static fields to deal with
		staticFinalFields.clear();
		// classBody.dump(System.err);
		// System.out.println("StaticInitilizer for "+classDef);
		classBody = checkStaticFields(classBody, myContext);

		if (staticFinalFields.isEmpty())
			// nothing to do
			return classBody;

		initMethodInstances();

		final List<ClassMember> currMembers = new ArrayList<ClassMember>();
		currMembers.addAll(classBody.members());

		if (!ct.flags().flags().isInterface()) {
			// create a new member list for initializer methods of each static field
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
		final Position cgPos = Position.compilerGenerated(null);
		final List<ClassMember> members = new ArrayList<ClassMember>();

		for (final Map.Entry<Pair<Type, Name>, StaticFieldInfo> entry : staticFinalFields.entrySet()) {
			final Name fName = entry.getKey().snd();
			final StaticFieldInfo fieldInfo = entry.getValue();

			if (fieldInfo.right == null && fieldInfo.fieldDef == null)
				continue;

			MethodDecl md = null;
			if (fieldInfo.right != null) {
				// gen new field var
				final FieldDecl fdExcept = makeFieldVar4Except(cgPos, fName, classDef);
				classDef.addField(fdExcept.fieldDef());
				// add in the top
				members.add(0, fdExcept);

				final FieldDecl fdCond = makeFieldVar4Guard(cgPos, fName, classDef);
				classDef.addField(fdCond.fieldDef());
				// add in the top
				members.add(0, fdCond);

				final FieldDecl fdId = makeFieldVar4Id(cgPos, fName, classDef);
				classDef.addField(fdId.fieldDef());
				// add in the top
				members.add(0, fdId);

				if (fieldInfo.left != null) {
					// interface case: add field declaration to the shadow class
					final FieldDef fd = fieldInfo.left.fieldDef();
					final Flags newFlags = fd.container().get().toClass().flags().clearInterface();
					final Ref<X10ClassType> classRef = Types.ref(classDef.asType());
					final FieldDef newFd = xts.fieldDef(cgPos, classRef, newFlags, fd.type(), fd.name());
					members.add(0, fieldInfo.left.fieldDef(newFd));
				}

				// gen new initialize method
				md = makeInitMethod(cgPos, fName, fieldInfo, fdExcept.fieldDef(), fdCond.fieldDef(), fdId.fieldDef(),
						classDef);
			} else {
				md = makeFakeInitMethod(cgPos, fName, fieldInfo, classDef);
			}
			classDef.addMethod(md.methodDef());
			// add in the bottom
			members.add(md);
		}

		return members;
	}

	private X10ClassDecl createNestedShadowClass(final X10ClassDecl_c interfaceClass) {
		// create ClassDef first
		final X10ClassDef cDef = createShadowClassDef(interfaceClass.classDef());

		// create ClassDecl
		final Position cgPos = Position.compilerGenerated(null);
		final FlagsNode fNode = xnf.FlagsNode(cgPos, cDef.flags());
		final Id id = xnf.Id(cgPos, cDef.name());
		final TypeNode superTN = cDef.superType() != null ? xnf.CanonicalTypeNode(cgPos, cDef.superType()) : null;
		final List<ClassMember> cmembers = new ArrayList<ClassMember>();
		final ClassBody body = xnf.ClassBody(cgPos, cmembers);
		final List<TypeNode> interfaceTN = Collections.<TypeNode>emptyList();
		final X10ClassDecl cDecl = xnf.ClassDecl(cgPos, fNode, id, superTN, interfaceTN, body).classDef(cDef);
		return cDecl;
	}

	private X10ClassDef createShadowClassDef(final X10ClassDef interfaceClassDef) {
		final X10ClassDef cDef = xts.createClassDef(interfaceClassDef.sourceFile());
		final List<Ref<? extends Type>> interfacesRef = new ArrayList<Ref<? extends Type>>();
		interfacesRef.add(Types.ref(xts.Any()));
		cDef.setInterfaces(interfacesRef);
		cDef.name(Name.make(NESTEDSHADOWCLASS4INTERFACE));
		cDef.setFlags(Flags.PUBLIC.Abstract());
		cDef.kind(ClassDef.MEMBER);
		cDef.outer(Types.ref(interfaceClassDef));
		return cDef;
	}

	private ClassBody checkStaticFields(final ClassBody body, final Context myContext) {
		final X10ClassDef cd = myContext.currentClassDef();
		// one pass scan of class body and collect vars for static initialization
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
					if (isPerProcess(fd.fieldDef()))
						return n;
					if (flags.isFinal() && flags.isStatic()) {
						// static final field
						final StaticFieldInfo fieldInfo = checkFieldDeclRHS(fd.init(), fd, cd);
						if (fieldInfo.right != null) {
							// drop final and set private (XTENLANG-3076)
							// System.out.println("RHS of FieldDecl replaced: "+ct.classDef()+"."+fd.fieldDef().name());
							final FlagsNode fn = xnf.FlagsNode(fd.position(), flags.clearFinal().clearPublic()
									.clearProtected().Private());
							// remove rhs: suppress java-level static initialization
							final Expr init = getDefaultValue(fd.position(), fd.init().type());
							final FieldDecl newDecl = xnf.FieldDecl(fd.position(), fn, fd.type(), fd.name(),
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
					final X10Field_c f = (X10Field_c) n;
					if (isPerProcess(f.fieldInstance().x10Def()))
						return n;
					if (f.flags().isFinal() && f.flags().isStatic()) {
						// found reference to static field
						if (checkFieldRefReplacementRequired(f)) {
							// replace with a static method call
							Type targetType = f.target().type();
							if (targetType instanceof ParsedClassType) {
								final X10ClassDef targetClassDef = ((ParsedClassType) targetType).def();
								if (targetClassDef.flags().isInterface())
									// target nested shadow class within interface
									targetType = createShadowClassDef(targetClassDef).asType();
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

	private StaticFieldInfo checkFieldDeclRHS(final Expr rhs, final X10FieldDecl fd, final X10ClassDef cd) {
		// traverse nodes in RHS
		final Id leftName = fd.name();

		// true means "found something not suitable for per-place initialization"
		final AtomicBoolean found = new AtomicBoolean(false);
		final boolean deepAnalysis = opts.x10_config.STATICS_PER_PLACE_ANALYSIS;
		final Expr newRhs = (Expr) rhs.visit(new NodeVisitor() {
			@Override
			public Node override(final Node parent, final Node n) {
				if (found.get())
					// already found
					return n;
				if (n instanceof Expr) {
					if (isGlobalInit((Expr) n) || isConstraintToLiteral(((Expr) n).type())) {
						// initialization can be done in all places -- do not visit subtree further
						// System.out.println("isGlobalInit true in checkFieldDeclRHS: "+(Expr)n);
						return n;
					}
					if (n instanceof X10Call_c) {
						final X10Call call = (X10Call) n;
						final MethodInstance mi = call.methodInstance();
						// if (!mi.container().isSubtype(xts.Object(), context)) {
						// // allow method calls on non-objects (including numerics, char and boolean)
						if (call.target().type().isNumeric() || call.target().type().isChar()
								|| call.target().type().isBoolean()) {
							// allow method calls on numerics, char or boolean
							// XTENLANG-3081(part2)
							// exclude "1.operator/(0)"
							if (CHECKEXCEPTIONINCONSTANTEXPRESSION) {
								found.set(true);
								return n;
							}
						} else if (deepAnalysis && mi.flags().isStatic()) {
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
					} else {
						// XTENLANG-3081(part2)
						// exclude "1 as Any as Object"
						if (CHECKEXCEPTIONINCONSTANTEXPRESSION) {
							found.set(true);
							return n;
						}
					}
				}
				// continue traversal
				return null;
			}
		});

		// register original rhs
		final X10ClassType receiver = cd.asType();
		final StaticFieldInfo fieldInfo = getFieldEntry(receiver, leftName.id());
		fieldInfo.right = (fieldInfo.methodDef != null || found.get()) ? newRhs : null;
		fieldInfo.fieldDef = fd.fieldDef();

		return fieldInfo;
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

	private ProcedureDecl getProcedureDeclaration(final X10ProcedureDef candidate, final X10ClassDef container) {
		final ProcedureDecl r = procDeclCache.get(candidate);
		if (r != null)
			return r;

		// obtain X10SourceFile ast of the target class that already runs preliminary compilation phases
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

	private Node getAST(final X10ClassDef container) {
		// obtain the job for containing the constructor declaration
		final Job containerJob = container.job();
		if (containerJob == null || containerJob.ast() == null)
			return null;

		if (containerJob == this.job())
			// current class
			return containerJob.ast();

		// run the preliminary compilation phases on the job's AST
		Node ast = containerJob.ast();
		assert (ast instanceof X10SourceFile_c);
		if (!((X10SourceFile_c) ast).hasBeenTypeChecked())
			ast = ast.visit(new X10TypeChecker(containerJob, ts, nf, containerJob.nodeMemo()).begin());
		if (ast == null)
			return null;
		if (!((X10Ext) ast.ext()).subtreeValid())
			return null;

		ast = ast.visit(new Desugarer(containerJob, ts, nf).begin());
		return ast;
	}

	private static final int CHECKLIMIT = 7;

	private boolean checkProcedureBody(final Block body, final int count) {
		final Boolean r = procBodyCache.get(body);
		if (r != null)
			return (r == Boolean.TRUE);

		// Cut the search tree to avoid overly long compilation time.
		// True means centralized place-0 initialization is necessary,
		// which is a safe conservative assumption.
		if (count > CHECKLIMIT)
			return true;

		// check static field references in the body of constructor or method
		final AtomicBoolean found = new AtomicBoolean(false);
		body.visit(new NodeVisitor() {
			@Override
			public Node override(final Node n) {
				if (found.get())
					// already found
					return n;
				if (n instanceof Expr) {
					if (n instanceof X10Call) {
						final X10Call call = (X10Call) n;
						final MethodInstance mi = call.methodInstance();
						// if (!mi.container().isSubtype(xts.Object(), context)) {
						// // allow method calls on non-objects (including numerics, char and boolean)
						if (call.target().type().isNumeric() || call.target().type().isChar()
								|| call.target().type().isBoolean()) {
							// allow method calls on numerics, char or boolean
							// XTENLANG-3081(part2)
							// exclude "1.operator/(0)"
							if (CHECKEXCEPTIONINCONSTANTEXPRESSION) {
								found.set(true);
								return n;
							}
						} else if (mi.flags().isStatic()) {
							// found reference to special initializer method
							final X10MethodDecl mdecl = getMethodDeclaration(mi);
							if (mdecl == null || checkProcedureBody(mdecl.body(), count + 1)) {
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
						if (cdecl != null && !cdecl.body().equals(body)
						    && checkProcedureBody(cdecl.body(), count + 1)) {
							// constructor include static field references to be replaced
							found.set(true);
							return n;
						}
					} else {
						// XTENLANG-3081(part2)
						// exclude "1 as Any as Object"
						if (CHECKEXCEPTIONINCONSTANTEXPRESSION) {
							found.set(true);
							return n;
						}
					}
				}
				// continue traversal
				return null;
			}
		});
		procBodyCache.put(body, found.get() ? Boolean.TRUE : Boolean.FALSE);
		return found.get();
	}

	private Call makeStaticCall(final Position pos, final X10ClassType receiver, final Id id, final Type returnType) {
		// create MethodDef
		final Name name = Name.make(INITIALIZERPREFIX + id);
		final StaticFieldInfo fieldInfo = getFieldEntry(receiver, id.id());
		MethodDef md = fieldInfo.methodDef;
		if (md == null) {
			md = makeMethodDef(receiver, name, returnType);
			fieldInfo.methodDef = md;
		}

		// create static call for initialization
		final List<TypeNode> typeArgsN = Collections.<TypeNode>emptyList();
		final List<Expr> args = Collections.<Expr>emptyList();
		final MethodInstance mi = xts.createMethodInstance(pos, pos, Types.ref(md));
		final Call result = (Call) xnf.X10Call(pos, xnf.CanonicalTypeNode(pos, receiver),
				xnf.Id(pos, name), typeArgsN, args)
				.methodInstance(mi).type(returnType);
		return result;
	}

	private MethodDef makeMethodDef(final X10ClassType receiver, final Name name, final Type returnType) {
		final Position cgPos = Position.compilerGenerated(null);
		final List<Ref<? extends Type>> argTypes = Collections.<Ref<? extends Type>>emptyList();
		final MethodDef md = xts.methodDef(cgPos, cgPos, Types.ref(receiver),
				Flags.STATIC, Types.ref(returnType), name, argTypes, Collections.<Ref<? extends Type>>emptyList());
		return md;
	}

	private FieldDecl makeFieldVar4Guard(final Position pos, final Name fName, final X10ClassDef classDef) {
		// make FieldDef of AtomicInteger
		final ClassType type = xts.AtomicInteger();
		final Flags flags = Flags.PRIVATE.Static().Final();

		final Name name = Name.make("initStatus$" + fName);
		final FieldDef fd = xts.fieldDef(pos, Types.ref(classDef.asType()), flags, Types.ref(type), name);
		xts.createFieldInstance(pos, Types.ref(fd));

		// create right hand side: new AtomicInteger(UNINITIALIZED)
		final TypeNode tn = xnf.X10CanonicalTypeNode(pos, type);
		final List<Expr> args = new ArrayList<Expr>();
		args.add(getInitDispatcherConstant(pos, "UNINITIALIZED").type(xts.Int()));

		final List<ConstructorInstance> constructors = type.constructors();
		final ArrayList<Type> formals = new ArrayList<Type>();
		formals.add(xts.Int());
		ConstructorInstance consInstance = null;
		for (final ConstructorInstance instance : constructors) {
			if (instance.hasFormals(formals, xts.emptyContext())) {
				consInstance = instance;
				break;
			}
		}
		if (consInstance == null)
			throw new RuntimeException("Couldn't find AtomicInteger.this(int)");

		Expr init = xnf.New(pos, tn, args).constructorInstance(consInstance).type(type);
		final ClassType staticAllocAnn = xts.load("x10.compiler.StaticAllocate");
		final TypeNode annoTypeNode = xnf.CanonicalTypeNode(pos, staticAllocAnn).typeRef(Types.ref(staticAllocAnn));
		final AnnotationNode annoNode = xnf.AnnotationNode(pos, annoTypeNode);
		final List<AnnotationNode> annos = new ArrayList<AnnotationNode>();
		annos.add(annoNode);
		init = (Expr) ((X10Del) init.del()).annotations(annos);

		// fieldDecl and its association with fieldDef
		FieldDecl result = xnf.FieldDecl(pos, xnf.FlagsNode(pos, flags), tn, xnf.Id(pos, name), init);
		result = result.fieldDef(fd);
		return result;
	}

	private FieldDecl makeFieldVar4Except(final Position pos, final Name fName, final X10ClassDef classDef) {
		// make FieldDef of x10.lang.ExceptionInInitializer
		final ClassType type = exceptionInInitializer;
		final Flags flags = Flags.PRIVATE.Static();

		final Name name = Name.make("exception$" + fName);
		final FieldDef fd = xts.fieldDef(pos, Types.ref(classDef.asType()), flags, Types.ref(type), name);
		xts.createFieldInstance(pos, Types.ref(fd));

		// create field declaration node
		final TypeNode tn = xnf.X10CanonicalTypeNode(pos, type);
		FieldDecl result = xnf.FieldDecl(pos, xnf.FlagsNode(pos, flags), tn, xnf.Id(pos, name));
		result = result.fieldDef(fd);
		return result;
	}

	private FieldDecl makeFieldVar4Id(final Position pos, final Name fName, final X10ClassDef classDef) {
		// make FieldDef
		final Type type = xts.Short();
		final Name name = Name.make("fieldId$" + fName);
		final Flags flags = Flags.PRIVATE.Static();

		final FieldDef fd = xts.fieldDef(pos, Types.ref(classDef.asType()), flags, Types.ref(type), name);
		xts.createFieldInstance(pos, Types.ref(fd));

		// create the field declaration node
		final TypeNode tn = xnf.X10CanonicalTypeNode(pos, type);
		FieldDecl result = xnf.FieldDecl(pos, xnf.FlagsNode(pos, flags), tn, xnf.Id(pos, name));
		// associate fieldDef with fieldDecl
		result = result.fieldDef(fd);
		return result;
	}

	private Expr getDefaultValue(final Position pos, final Type type) {
		if (type.isBoolean()) {
			return xnf.BooleanLit(pos, false).type(type);
		} else if (type.isChar()) {
			return xnf.CharLit(pos, '\0').type(type);
		} else if (type.isByte() || type.isShort() || type.isInt()) {
			return xnf.IntLit(pos, IntLit.INT, 0).type(type);
		} else if (type.isLong()) {
			return xnf.IntLit(pos, IntLit.LONG, 0).type(type);
		} else if (type.isUByte() || type.isUShort() || type.isUInt()) {
			return xnf.IntLit(pos, IntLit.UINT, 0).type(type);
		} else if (type.isULong()) {
			return xnf.IntLit(pos, IntLit.ULONG, 0).type(type);
		} else if (type.isFloat()) {
			return xnf.FloatLit(pos, FloatLit.FLOAT, 0.0).type(type);
		} else if (type.isDouble()) {
			return xnf.FloatLit(pos, FloatLit.DOUBLE, 0.0).type(type);
		} else if (type.isString()) {
			return xnf.NullLit(pos).type(type);
		} else {
			return null;
		}
	}

	private MethodDecl makeInitMethod(final Position pos, final Name fName, final StaticFieldInfo fieldInfo,
			final FieldDef fdExcept, final FieldDef fdCond, final FieldDef fdId, final X10ClassDef classDef) {
		// get MethodDef
		final Name name = Name.make(INITIALIZERPREFIX + fName);
		final Type type = fieldInfo.fieldDef.type().get();
		MethodDef md = fieldInfo.methodDef;
		if (md == null) {
			md = makeMethodDef(classDef.asType(), name, type);
		}

		// create a method declaration node
		final List<TypeParamNode> typeParamNodes = Collections.<TypeParamNode>emptyList();
		final List<Formal> formals = Collections.<Formal>emptyList();

		final TypeNode returnType = xnf.X10CanonicalTypeNode(pos, type);
		final Block body = makeInitMethodBody(pos, fieldInfo, fdExcept, fdCond, fdId, classDef);
		MethodDecl result = xnf.X10MethodDecl(pos, xnf.FlagsNode(pos, Flags.STATIC), returnType, xnf.Id(pos, name),
				typeParamNodes, formals, null, null, Collections.<TypeNode>emptyList(), body);
		// associate methodDef with methodDecl
		result = result.methodDef(md);
		return result;
	}

	private Catch genCatch(final Position pos, final FieldDef fdExcept, final FieldDef fdCond, final Name excName,
			final X10ClassType excType, final TypeNode receiver, final Stmt throwExceptStmt) {
		final LocalDef excDef = xts.localDef(pos, Flags.NONE, Types.ref(excType), excName);
		final Formal excFormal = xnf.Formal(pos, xnf.FlagsNode(pos, excDef.flags()),
				xnf.CanonicalTypeNode(pos, excDef.type()), xnf.Id(pos, excDef.name())).localDef(excDef);

		final List<Ref<? extends Type>> newExceptArgTypes = new ArrayList<Ref<? extends Type>>();
		newExceptArgTypes.add(Types.ref(xts.Exception()));
		final Ref<X10ClassType> container = Types.ref(fdExcept.asInstance().type().toClass());
		final ConstructorDef cd = xts.constructorDef(pos, pos, container, Flags.NONE,
				newExceptArgTypes, Collections.<Ref<? extends Type>>emptyList());
		final ConstructorInstance ci = xts.createConstructorInstance(pos, pos, Types.ref(cd));
		final List<Expr> newExceptArgs = new ArrayList<Expr>();
		final Expr excExpr = xnf.Local(pos, xnf.Id(pos, excDef.name())).localInstance(excDef.asInstance()).type(
				excDef.asInstance().type());
		newExceptArgs.add(excExpr);
		final Expr newExceptExpr = xnf.New(pos, xnf.CanonicalTypeNode(pos, fdExcept.asInstance().type()), newExceptArgs)
				.constructorInstance(ci).type(fdExcept.asInstance().type());
		final Stmt storeExceptStmt = xnf.Eval(pos, xnf.FieldAssign(pos, receiver, xnf.Id(pos, fdExcept.name()),
				Assign.ASSIGN, newExceptExpr).fieldInstance(fdExcept.asInstance()).type(fdExcept.asInstance().type()));

		final List<Stmt> catchStmts = new ArrayList<Stmt>();
		// gen exception = new x10.lang.ExceptionInInitializer(e);
		catchStmts.add(storeExceptStmt);
		// gen AtomicInteger.set(EXCEPTION_RAISED)
		catchStmts.add(xnf.Eval(pos, genStatusSetExcept(pos, receiver, fdCond)));
		// gen lockInitialized()
		catchStmts.add(xnf.Eval(pos, callInitDispatcherMethodVoidNoarg(pos, lockInitialized)));
		// gen notifyInitialized()
		catchStmts.add(xnf.Eval(pos, callInitDispatcherMethodVoidNoarg(pos, notifyInitialized)));
		// gen throw exception;
		catchStmts.add(throwExceptStmt);

		return xnf.Catch(pos, excFormal, xnf.Block(pos, catchStmts));
	}

	/*
	 * private Catch genCatchWithMessage(Position pos, FieldDef fdExcept, FieldDef fdCond, Name excName, X10ClassType
	 * excType, TypeNode receiver, Stmt throwExceptStmt) {
	 * LocalDef excDef = xts.localDef(pos, Flags.NONE, Types.ref(excType), excName);
	 * Formal excFormal = xnf.Formal(pos, xnf.FlagsNode(pos, excDef.flags()), xnf.CanonicalTypeNode(pos, excDef.type()),
	 * xnf.Id(pos, excDef.name())).localDef(excDef);
	 *
	 * List<Ref<? extends Type>> newExceptArgTypes = new ArrayList<Ref<? extends Type>>();
	 * newExceptArgTypes.add(Types.ref(xts.String()));
	 * ConstructorDef cd = xts.constructorDef(pos, pos, Types.ref(fdExcept.asInstance().type().toClass()), Flags.NONE,
	 * newExceptArgTypes, Collections.<Ref<? extends Type>>emptyList());
	 * ConstructorInstance ci = xts.createConstructorInstance(pos, pos, Types.ref(cd));
	 * List<Expr> newExceptArgs = new ArrayList<Expr>();
	 * MethodDef md = xts.methodDef(pos, pos, (Ref<? extends ContainerType>) excDef.type(), Flags.NONE,
	 * Types.ref(xts.String()), Name.make("getMessage"), Collections.<Ref<? extends Type>>emptyList(),
	 * Collections.<Ref<? extends Type>>emptyList());
	 * MethodInstance mi = xts.createMethodInstance(pos, pos, Types.ref(md));
	 * Expr excExpr = xnf.Local(pos, xnf.Id(pos,
	 * excDef.name())).localInstance(excDef.asInstance()).type(excDef.asInstance().type());
	 * Expr call = xnf.X10Call(pos, excExpr, xnf.Id(pos, mi.name()), Collections.<TypeNode>emptyList(),
	 * Collections.<Expr>emptyList()).methodInstance(mi).type(mi.returnType());
	 * newExceptArgs.add(call);
	 * Expr newExceptExpr = xnf.New(pos, xnf.CanonicalTypeNode(pos, fdExcept.asInstance().type()),
	 * newExceptArgs).constructorInstance(ci).type(fdExcept.asInstance().type());
	 * Stmt storeExceptStmt = xnf.Eval(pos, xnf.FieldAssign(pos, receiver, xnf.Id(pos, fdExcept.name()), Assign.ASSIGN,
	 * newExceptExpr).fieldInstance(fdExcept.asInstance()).type(fdExcept.asInstance().type()));
	 *
	 * List<Stmt> catchStmts = new ArrayList<Stmt>();
	 * // gen exception = new x10.lang.ExceptionInInitializer(e.getMessage());
	 * catchStmts.add(storeExceptStmt);
	 * // gen AtomicInteger.set(EXCEPTION_RAISED)
	 * catchStmts.add(xnf.Eval(pos, genStatusSetExcept(pos, receiver, fdCond)));
	 * // gen lockInitialized()
	 * catchStmts.add(xnf.Eval(pos, genLock(pos)));
	 * // gen notifyInitialized()
	 * catchStmts.add(xnf.Eval(pos, genNotify(pos)));
	 * // gen throw exception;
	 * catchStmts.add(throwExceptStmt);
	 *
	 * return xnf.Catch(pos, excFormal, xnf.Block(pos, catchStmts));
	 * }
	 */

	private Block makeInitMethodBody(final Position pos, final StaticFieldInfo initInfo, final FieldDef fdExcept,
			final FieldDef fdCond, final FieldDef fdId, final X10ClassDef classDef) {
		List<Stmt> stmts;
		final TypeNode receiver = xnf.X10CanonicalTypeNode(pos, classDef.asType());
		final FieldInstance fi = initInfo.fieldDef.asInstance();
		final Expr right = initInfo.right;
		final Name name = initInfo.fieldDef.name();
		final Expr left = xnf.Field(pos, receiver, xnf.Id(pos, name)).fieldInstance(fi).type(right.type());

		// gen if (AtomicInteger.get() == INITIALIZED) { return field; }
		stmts = new ArrayList<Stmt>();
		stmts.add(xnf.X10Return(pos, left, false));
		final Stmt shortCutBlock = xnf.If(pos, genCheckInitialized(pos, receiver, fdCond, true), xnf.Block(pos, stmts));

		Stmt shortCutBlockExcept = null;
		Stmt throwExceptStmt = null;

		// gen if (AtomicInteger.get() == EXCEPTION_RAISED) { throw exception; }
		stmts = new ArrayList<Stmt>();
		/*
		 * stmts.add(xnf.If(pos, genPrintStmtCheckGuard(pos), makePrintStmtExcept(pos, name, classDef)));
		 */
		throwExceptStmt = xnf.Throw(pos, xnf.Field(pos, receiver, xnf.Id(pos, fdExcept.name())).fieldInstance(
				fdExcept.asInstance()).type(fdExcept.asInstance().type()));
		stmts.add(throwExceptStmt);
		shortCutBlockExcept = xnf.If(pos, genCheckExceptionRaised(pos, receiver, fdCond, true), xnf.Block(pos, stmts));

		// gen AtomicInteger.compareAndSet(UNINITIALIZED, INITIALIZING)
		final Expr ifCond = genAtomicGuard(pos, receiver, fdCond);
		final FieldInstance fdidi = fdId.asInstance();
		xnf.Field(pos, receiver, xnf.Id(pos, fdId.name())).fieldInstance(fdidi).type(fdidi.type());

		// make statement block of initialization
		stmts = new ArrayList<Stmt>();

		// if (stickyExceptionSemantics) surround with try
		final Expr fieldAssign = xnf.FieldAssign(pos, receiver, xnf.Id(pos, name), Assign.ASSIGN, right)
				.fieldInstance(fi).type(right.type());
		final Stmt fieldAssignStmt = xnf.Eval(pos, fieldAssign);
		final Name excName = Name.makeFresh("exc$");
		final List<Catch> catchBlocks = new ArrayList<Catch>();
		// gen catch (java.lang.Throwable exc) { exception = new x10.lang.ExceptionInInitializer(exc);
		// AtomicInteger.set(EXCEPTION_RAISED); lockInitialized(); notifyInitialized(); throw exception; }
		catchBlocks.add(genCatch(pos, fdExcept, fdCond, excName, (X10ClassType) xts.CheckedThrowable(), receiver,
				throwExceptStmt));
		stmts.add(xnf.Try(pos, xnf.Block(pos, fieldAssignStmt), catchBlocks));

		// stmts.add(xnf.If(pos, genPrintStmtCheckGuard(pos), makePrintStmt(pos, name, classDef)));

		stmts.add(xnf.Eval(pos, genStatusSet(pos, receiver, fdCond)));
		stmts.add(xnf.Eval(pos, callInitDispatcherMethodVoidNoarg(pos, lockInitialized)));
		stmts.add(xnf.Eval(pos, callInitDispatcherMethodVoidNoarg(pos, notifyInitialized)));
		final Block initBody = xnf.Block(pos, stmts);

		// gen while(AtomicInteger.get() != INITIALIZED) { await(); }
		final Expr initCheckCond = genCheckInitialized(pos, receiver, fdCond, Binary.LT);
		final Expr awaitCall = callInitDispatcherMethodVoidNoarg(pos, awaitInitialized);
		final Block whileBody = xnf.Block(pos, xnf.Eval(pos, awaitCall));

		// make statement block for waiting
		stmts = new ArrayList<Stmt>();
		stmts.add(xnf.Eval(pos, callInitDispatcherMethodVoidNoarg(pos, lockInitialized)));
		stmts.add(xnf.While(pos, initCheckCond, whileBody));
		stmts.add(xnf.Eval(pos, callInitDispatcherMethodVoidNoarg(pos, unlockInitialized)));
		stmts.add(shortCutBlockExcept);
		final Block waitBody = xnf.Block(pos, stmts);

		// make statement block of the entire method body
		stmts = new ArrayList<Stmt>();
		stmts.add(shortCutBlock);
		stmts.add(shortCutBlockExcept);

		// original
		// stmts.add(xnf.If(pos, initCheckCond, waitBody));
		// optimized
		stmts.add(xnf.If(pos, ifCond, initBody, xnf.If(pos, initCheckCond, waitBody)));
		stmts.add(xnf.X10Return(pos, left, false));
		final Block body = xnf.Block(pos, stmts);
		return body;
	}

	private Expr genAtomicGuard(final Position pos, final TypeNode receiver, final FieldDef fdCond) {
		final FieldInstance fi = fdCond.asInstance();
		final Expr ai = xnf.Field(pos, receiver, xnf.Id(pos, fdCond.name())).fieldInstance(fi).type(fi.type());

		final List<Expr> args = new ArrayList<Expr>();
		args.add(getInitDispatcherConstant(pos, "UNINITIALIZED").type(xts.Int()));
		args.add(getInitDispatcherConstant(pos, "INITIALIZING").type(xts.Int()));
		final List<TypeNode> typeParamNodes = new ArrayList<TypeNode>();
		typeParamNodes.add(xnf.CanonicalTypeNode(pos, xts.Int()));
		typeParamNodes.add(xnf.CanonicalTypeNode(pos, xts.Int()));
		final Id csId = xnf.Id(pos, compareAndSet.name());
		final Expr call = xnf.X10Call(pos, ai, csId, typeParamNodes, args)
				.methodInstance(compareAndSet).type(xts.Boolean());
		return call;
	}

	private Expr genStatusSet(final Position pos, final TypeNode receiver, final FieldDef fdCond) {
		return genStatusSet(pos, "INITIALIZED", receiver, fdCond);
	}

	private Expr genStatusSetExcept(final Position pos, final TypeNode receiver, final FieldDef fdCond) {
		return genStatusSet(pos, "EXCEPTION_RAISED", receiver, fdCond);
	}

	private Expr genStatusSet(final Position pos, final String status, final TypeNode receiver,
		final FieldDef fdCond) {
		final FieldInstance fi = fdCond.asInstance();
		final Expr ai = xnf.Field(pos, receiver, xnf.Id(pos, fdCond.name())).fieldInstance(fi).type(fi.type());
		 // Intentionally not SettableAssign.SET because AtomicInteger is a NativeRep class
		final Id name = xnf.Id(pos, Name.make("set"));

		final List<Ref<? extends Type>> argTypes = new ArrayList<Ref<? extends Type>>();
		argTypes.add(Types.ref(xts.Int()));
		final MethodDef md = xts.methodDef(pos, pos, Types.ref((ClassType) xts.AtomicInteger()),
				Flags.NONE, Types.ref(xts.Void()), name.id(), argTypes, Collections.<Ref<? extends Type>>emptyList());
		final MethodInstance mi = xts.createMethodInstance(pos, pos, Types.ref(md));

		final List<Expr> args = new ArrayList<Expr>();
		args.add(getInitDispatcherConstant(pos, status).type(xts.Int()));
		final List<TypeNode> typeParamNodes = new ArrayList<TypeNode>();
		typeParamNodes.add(xnf.CanonicalTypeNode(pos, xts.Int()));
		final Expr call = xnf.X10Call(pos, ai, name, typeParamNodes, args).methodInstance(mi).type(xts.Void());
		return call;
	}

	private Expr genCheckInitialized(final Position pos, final TypeNode receiver, final FieldDef fdCond,
		final boolean positive) {
		return genCheckInitialized(pos, receiver, fdCond, positive ? Binary.EQ : Binary.NE);
	}

	private Expr genCheckExceptionRaised(final Position pos, final TypeNode receiver, final FieldDef fdCond,
		final boolean positive) {
		return genCheckExceptionRaised(pos, receiver, fdCond, positive ? Binary.EQ : Binary.NE);
	}

	private Expr genCheckInitialized(final Position pos, final TypeNode receiver, final FieldDef fdCond,
		final Operator op) {
		return genCheck(pos, receiver, "INITIALIZED", fdCond, op);
	}

	private Expr genCheckExceptionRaised(final Position pos, final TypeNode receiver, final FieldDef fdCond,
		final Operator op) {
		return genCheck(pos, receiver, "EXCEPTION_RAISED", fdCond, op);
	}

	private Expr genCheck(final Position pos, final TypeNode receiver, final String fieldName, final FieldDef fdCond,
		final Operator op) {
		final FieldInstance fi = fdCond.asInstance();
		final Expr ai = xnf.Field(pos, receiver, xnf.Id(pos, fdCond.name())).fieldInstance(fi).type(fi.type());
		final Id name = xnf.Id(pos, Name.make("get"));

		final List<Ref<? extends Type>> argTypes = Collections.<Ref<? extends Type>>emptyList();
		final MethodDef md = xts.methodDef(pos, pos, Types.ref((ClassType) xts.AtomicInteger()),
				Flags.NONE, Types.ref(xts.Int()), name.id(), argTypes, Collections.<Ref<? extends Type>>emptyList());
		final MethodInstance mi = xts.createMethodInstance(pos, pos, Types.ref(md));

		final List<Expr> args = Collections.<Expr>emptyList();
		final List<TypeNode> typeParamNodes = Collections.<TypeNode>emptyList();
		final Expr call = xnf.X10Call(pos, ai, name, typeParamNodes, args).methodInstance(mi).type(xts.Int());

		return xnf.Binary(pos, call, op, getInitDispatcherConstant(pos, fieldName).type(xts.Int())).type(xts.Boolean());
	}

	private Expr callInitDispatcherMethodVoidNoarg(final Position pos, final MethodInstance mi) {
		// create MethodDef
		final Id id = xnf.Id(pos, mi.name());

		// actual arguments
		final List<Expr> args = Collections.<Expr>emptyList();
		final List<TypeNode> typeParamNodes = Collections.<TypeNode>emptyList();
		final Receiver receiver = xnf.CanonicalTypeNode(pos, initDispatcher);
		final Expr call = xnf.X10Call(pos, receiver, id, typeParamNodes, args).methodInstance(mi).type(xts.Void());
		return call;
	}

	private Expr getInitDispatcherConstant(final Position pos, final String name) {
		final Id id = xnf.Id(pos, Name.make(name));
		final FieldDef fd = xts.fieldDef(pos, Types.ref(initDispatcher),
				Flags.STATIC, Types.ref(xts.Int()), id.id());
		final FieldInstance fi = xts.createFieldInstance(pos, Types.ref(fd));
		final Receiver receiver = xnf.CanonicalTypeNode(pos, initDispatcher);
		return xnf.Field(pos, receiver, id).fieldInstance(fi);
	}

	private MethodDecl makeFakeInitMethod(final Position pos, final Name fName, final StaticFieldInfo fieldInfo,
		final X10ClassDef classDef) {
		// get MethodDef
		final Name name = Name.make(INITIALIZERPREFIX + fName);
		final FieldInstance fi = fieldInfo.fieldDef.asInstance();
		final MethodDef md = makeMethodDef(classDef.asType(), name, fi.type());

		// create a method declaration node
		final List<TypeParamNode> typeParamNodes = Collections.<TypeParamNode>emptyList();
		final List<Formal> formals = Collections.<Formal>emptyList();

		// get field reference
		X10ClassDef myDef = classDef;
		if (classDef.isMember() && classDef.outer().get().flags().isInterface())
			// should refer to fields in the outer interface
			myDef = classDef.outer().get();
		final TypeNode receiver = xnf.X10CanonicalTypeNode(pos, myDef.asType());
		final Id fieldId = xnf.Id(pos, fieldInfo.fieldDef.name());
		final Expr left = xnf.Field(pos, receiver, fieldId).fieldInstance(fi).type(fi.type());

		// make statement block
		final List<Stmt> stmts = new ArrayList<Stmt>();
		stmts.add(xnf.X10Return(pos, left, false));
		final Block body = xnf.Block(pos, stmts);

		// create method declaration
		final TypeNode returnType = xnf.X10CanonicalTypeNode(pos, fi.type());
		MethodDecl result = xnf.X10MethodDecl(pos, xnf.FlagsNode(pos, Flags.STATIC), returnType, xnf.Id(pos, name),
				typeParamNodes, formals, null, null, Collections.<TypeNode>emptyList(), body);
		// associate methodDef with methodDecl
		result = result.methodDef(md);
		return result;
	}

	/*
	 * private ClassType X10JavaSerializable_;
	 * private ClassType X10JavaSerializable() {
	 * if (X10JavaSerializable_ == null)
	 * X10JavaSerializable_ = xts.load("x10.compiler.X10JavaSerializable");
	 * return X10JavaSerializable_;
	 * }
	 *
	 * private ClassType X10JavaDeserializer_;
	 * private ClassType X10JavaDeserializer() {
	 * if (X10JavaDeserializer_ == null)
	 * X10JavaDeserializer_ = xts.load("x10.compiler.X10JavaDeserializer");
	 * return X10JavaDeserializer_;
	 * }
	 */

	/*
	 * private ClassType PlaceLocalHandle_;
	 * private ClassType PlaceLocalHandle() {
	 * if (PlaceLocalHandle_ == null)
	 * PlaceLocalHandle_ = xts.load("x10.compiler.PlaceLocalHandle");
	 * return PlaceLocalHandle_;
	 * }
	 */

	/*
	 * private Stmt makePrintStmt(Position pos, Name fieldName, X10ClassDef classDef) {
	 * // get fully qualified field name
	 * String fullName = getPackageName(classDef) + getClassName(classDef) + "." + Emitter.mangleToJava(fieldName);
	 * return makePrintStmt(pos, "Doing static initialization for field: " + fullName);
	 * }
	 *
	 * private Stmt makePrintStmtExcept(Position pos, Name fieldName, X10ClassDef classDef) {
	 * // get fully qualified field name
	 * String fullName = getPackageName(classDef) + getClassName(classDef) + "." + Emitter.mangleToJava(fieldName);
	 * return makePrintStmt(pos, "Rethrowing ExceptionInInitializer for field: " + fullName);
	 * }
	 *
	 * private Stmt makePrintStmt(Position pos, String message) {
	 * Id id = xnf.Id(pos, Name.make("printStaticInitMessage"));
	 *
	 * // argument type
	 * List<Ref<? extends Type>> argTypes = new ArrayList<Ref<? extends Type>>();
	 * argTypes.add(Types.ref(xts.String()));
	 *
	 * // create MethodDef
	 * MethodDef md = xts.methodDef(pos, pos, Types.ref(InitDispatcher()),
	 * Flags.STATIC, Types.ref(xts.Void()), id.id(), argTypes, Collections.<Ref<? extends Type>>emptyList());
	 * MethodInstance mi = xts.createMethodInstance(pos, pos,Types.ref(md));
	 *
	 * // actual arguments
	 * List<Expr> args = new ArrayList<Expr>();
	 * args.add(xnf.StringLit(pos, message).type(xts.String()));
	 *
	 * List<TypeNode> typeParamNodes = new ArrayList<TypeNode>();
	 * typeParamNodes.add(xnf.CanonicalTypeNode(pos, xts.String()));
	 * TypeNode receiver = xnf.CanonicalTypeNode(pos, InitDispatcher());
	 *
	 * return xnf.Eval(pos, xnf.X10Call(pos, receiver, id, typeParamNodes, args).methodInstance(mi).type(xts.Void()));
	 * }
	 *
	 * private Expr genPrintStmtCheckGuard(Position pos) {
	 * Id name = xnf.Id(pos, Name.make("TRACE_STATIC_INIT"));
	 *
	 * FieldDef fieldDef = xts.fieldDef(pos, Types.ref(InitDispatcher()), Flags.STATIC, Types.ref(xts.Boolean()),
	 * name.id());
	 * X10FieldInstance fi = xts.createFieldInstance(pos, Types.ref(fieldDef));
	 * Receiver receiver = xnf.CanonicalTypeNode(pos, InitDispatcher());
	 * Expr left = xnf.Field(pos, receiver, name).fieldInstance(fi);
	 * return xnf.Binary(pos, left.type(xts.Boolean()), Binary.EQ, xnf.BooleanLit(pos, true).type(xts.Boolean()));
	 * }
	 *
	 * private String getClassName(ClassDef classDef) {
	 * String name = classDef.name().toString();
	 * if (classDef.isNested()) {
	 * ClassDef outerDef = Types.get(classDef.outer());
	 * if (outerDef != null)
	 * // get outer's name recursively
	 * name = getClassName(outerDef) +'$' + name;
	 * }
	 * return name;
	 * }
	 *
	 * private String getPackageName(ClassDef classDef) {
	 * if (classDef.isNested())
	 * return getPackageName(Types.get(classDef.outer()));
	 * Package p = Types.get(classDef.package_());
	 * return (p != null ? p.toString() + "." : "");
	 * }
	 */

	private StaticFieldInfo getFieldEntry(final Type target, final Name name) {
		final Pair<Type, Name> key = new Pair<Type, Name>(target, name);
		StaticFieldInfo fieldInfo = staticFinalFields.get(key);
		if (fieldInfo == null) {
			fieldInfo = new StaticFieldInfo();
			staticFinalFields.put(key, fieldInfo);
		}
		return fieldInfo;
	}

	private boolean isGlobalInit(final Expr e) {
		// N.B. Process safe cast as constant
		if (e instanceof Cast)
			return isConstantExpression(e);
		if (e.type().isNumeric() || e.type().isBoolean() || e.type().isChar() || e.type().isNull())
			return isConstantExpression(e);
		if (e.type().isString())
			return isStringConstant(e);
		return false;
	}

	private static boolean isSafeCast(final Cast c, final Context context) {
		return c.expr().type().isSubtype(c.castType().type(), context);
	}

	/* from x10cpp.visit.ASTQuery */
	private boolean isConstantExpression(final Expr e) {
		// N.B. Need to check first because NullLit_c.isConstant() returns false to workaround constant propagator's
		// bug!
		if (e instanceof NullLit)
			return true;
		// N.B. Process safe cast as constant
		if (e instanceof Cast) {
			final Cast c = (Cast) e;
			return isConstantExpression(c.expr()) && isSafeCast(c, context);
		}
		if (!e.isConstant())
			return false;
		if (e instanceof BooleanLit)
			return true;
		if (e instanceof IntLit)
			return true;
		if (e instanceof FloatLit)
			return true;
		if (e instanceof CharLit)
			return true;
		// N.B. Process safe cast as constant
		// if (e instanceof Cast)
		// return isConstantExpression(((Cast) e).expr());
		if (e instanceof ParExpr)
			return isConstantExpression(((ParExpr) e).expr());
		if (e instanceof Unary)
			return isConstantExpression(((Unary) e).expr());
		if (e instanceof Binary)
			return isConstantExpression(((Binary) e).left())
			    && isConstantExpression(((Binary) e).right());
		if (e instanceof Conditional)
			return isConstantExpression(((Conditional) e).cond())
			    && isConstantExpression(((Conditional) e).consequent())
			    && isConstantExpression(((Conditional) e).alternative());
		if (e instanceof Closure) {
			final Closure c = (Closure) e;
			final List<Stmt> ss = c.body().statements();
			if (ss.size() != 1)
				return false;
			if (!(ss.get(0) instanceof Return))
				return false;
			return isConstantExpression(((Return) ss.get(0)).expr());
		}
		if (e instanceof ClosureCall) {
			final ClosureCall cc = (ClosureCall) e;
			final List<Expr> as = ((ClosureCall) e).arguments();
			for (final Expr a : as) {
				if (!isConstantExpression(a))
					return false;
			}
			return isConstantExpression(cc.target());
		}
		if (e instanceof Call) {
			final Call c = (Call) e;
			return c.isConstant();
		}
		return false;
	}

	private boolean isStringConstant(final Expr e) {
		if (!e.isConstant())
			return false;
		if (e instanceof StringLit)
			return true;
		if (e instanceof X10Call) {
			// check if this is string manipulation (e.g. concatenation)
			final X10Call call = (X10Call) e;
			final List<Expr> args = call.arguments();
			for (final Expr arg : args) {
				if (!isStringConstant(arg))
					return false;
			}
			Type targetType = call.target().type();
			if (targetType instanceof ConstrainedType)
				targetType = ((ConstrainedType) targetType).baseType().get();
			return targetType.isString();
		}
		return false;
	}

	private boolean checkFieldRefReplacementRequired(final X10Field_c f) {
		if (f.target().type().toClass().isJavaType())
			return false;

		if (f.isConstant())
			return false;

		if (isConstraintToLiteral(f.type()))
			return false;

		final Pair<Type, Name> key = new Pair<Type, Name>(f.target().type(), f.name().id());
		final StaticFieldInfo fieldInfo = staticFinalFields.get(key);
		// not yet registered, or registered as replacement required
		return fieldInfo == null || fieldInfo.right != null || fieldInfo.methodDef != null;
	}

	private static boolean isConstraintToLiteral(final Type type) {
		if (type instanceof ConstrainedType) {
			// check if self is bound to a constant
			final ConstrainedType ct = (ConstrainedType) (type);
			if (ct.constraint().known()) {
				final CConstraint cc = ct.constraint().get();
				final XTerm selfVar = cc.selfVarBinding();
				if (selfVar != null && selfVar.isLit())
					return true;
			}
		}
		return false;
	}

	/** info about a Static field. */
	private static class StaticFieldInfo {
		private Expr right; // RHS expression, if replaced with initialization method
		private MethodDef methodDef; // getInitialized methodDef to be replaced
		private FieldDef fieldDef;
		private FieldDecl left; // field declaration to be moved from interface to a shadow class
	}

	private boolean isPerProcess(final X10Def def) {
		try {
			final Type t = xts.systemResolver().findOne(QName.make("x10.compiler.PerProcess"));
			return !def.annotationsMatching(t).isEmpty();
		} catch (final SemanticException e) {
			return false;
		}
	}
}
