package x10firm.visit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import polyglot.ast.Assign;
import polyglot.ast.Block;
import polyglot.ast.CanonicalTypeNode;
import polyglot.ast.ClassBody;
import polyglot.ast.ClassDecl;
import polyglot.ast.ClassMember;
import polyglot.ast.Expr;
import polyglot.ast.Field;
import polyglot.ast.FieldDecl;
import polyglot.ast.Formal;
import polyglot.ast.Id;
import polyglot.ast.Local;
import polyglot.ast.MethodDecl;
import polyglot.ast.NamedVariable;
import polyglot.ast.Node;
import polyglot.ast.NodeFactory;
import polyglot.ast.Receiver;
import polyglot.ast.Special;
import polyglot.ast.Special.Kind;
import polyglot.ast.TypeNode;
import polyglot.frontend.Job;
import polyglot.types.ClassDef;
import polyglot.types.Context;
import polyglot.types.FieldInstance;
import polyglot.types.Flags;
import polyglot.types.LocalDef;
import polyglot.types.LocalInstance;
import polyglot.types.Name;
import polyglot.types.Ref;
import polyglot.types.SemanticException;
import polyglot.types.Type;
import polyglot.types.TypeSystem;
import polyglot.types.Types;
import polyglot.types.VarDef;
import polyglot.types.VarInstance;
import polyglot.util.InternalCompilerError;
import polyglot.util.Position;
import polyglot.util.UniqueID;
import polyglot.visit.ContextVisitor;
import polyglot.visit.NodeVisitor;
import x10.ast.Closure;
import x10.ast.ClosureCall;
import x10.ast.TypeParamNode;
import x10.ast.X10ClassDecl;
import x10.ast.X10ConstructorDecl;
import x10.ast.X10Formal;
import x10.types.ClosureDef;
import x10.types.ParameterType;
import x10.types.ThisInstance;
import x10.types.X10ClassDef;
import x10.types.X10ClassType;
import x10.types.X10CodeDef;
import x10.types.X10ConstructorDef;
import x10.types.X10FieldDef;
import x10.types.X10FieldInstance;
import x10.types.X10LocalDef;
import x10.types.X10LocalInstance;
import x10.types.X10MethodDef;
import x10.types.constraints.TypeConstraint;
import x10.util.CollectionFactory;

/**
 * Closure context visitor which transforms closures to simpler x10 constructs. (static inner classes)
 */
public class X10ClosureRemover extends ContextVisitor {

    private static final String STATIC_INNER_CLASS_BASE_NAME = "$Closure";

    /**
     * Name of the outer field (reference to the enclosing class)
     */
    static final Name OUTER_NAME = Name.make("out$$");

    /**
     * Reference to the type system
     */
    final TypeSystem xts;

    /**
     * Reference to the node factory
     */
    final NodeFactory xnf;

    /**
     * Constructor
     * @param job The job
     * @param ts The type system
     * @param nf The node factory
     */
    public X10ClosureRemover(Job job, TypeSystem ts, NodeFactory nf) {
        super(job, ts, nf);
        xts = ts;
        xnf = nf;
    }

    @Override
    protected Node leaveCall(Node parent, Node old, Node n, NodeVisitor v) throws SemanticException {

        if (n instanceof ClassDecl) {
            ClassDecl cd = (ClassDecl) n;
            final X10ClassDef def = cd.classDef();
            final List<ClassMember> nmembers = new ArrayList<ClassMember>();

            // closure -> static inner class
            cd = (ClassDecl) cd.visitChildren(createClosureToStaticInnerClassVisitor(def, nmembers));

            ClassBody body = cd.body();
            nmembers.addAll(0, body.members());
            return ((ClassDecl) n).body(body.members(nmembers));
        } 

        return n;
    }
    
    private static Map<Type, Type> closureClassMapping = new HashMap<Type, Type>();
    
    /**
     * Returns the closure mapping type (static inner class) for a given closure type
     * @param type The closure type
     * @return The mapped closure type (static inner class) 
     */
    public static Type getClosureMappingType(final Type type) {
    	return closureClassMapping.get(type);
    }
    
    /**
     * Creates a new closure mapping (closureType -> (static inner class))
     * @param closure_type The closure type 
     * @param mapped_type The mapped type
     */
    public static void putClosureMappingType(final Type closure_type, final Type mapped_type) {
    	assert(!closureClassMapping.containsKey(closure_type));
    	closureClassMapping.put(closure_type, mapped_type); 
    }

    private ContextVisitor createClosureToStaticInnerClassVisitor(final X10ClassDef def,final List<ClassMember> nmembers) {
        return new ContextVisitor(job, ts, nf) {
            @Override
            public Node leaveCall(Node parent, Node old, Node n, NodeVisitor v) throws SemanticException {

                // TODO handle "this" in type constraints
                if (n instanceof Closure) {
                    final Closure cl = (Closure) n;
                    final ClosureDef cld = cl.closureDef();
                    final Position pos = Position.COMPILER_GENERATED;
                    final Flags privateStatic = Flags.PRIVATE.Static();
                    

                    final List<VarInstance<? extends VarDef>> capturedEnv = cld.capturedEnvironment();

                    Block closureBody = cl.body();

                    final Id staticInnerClassName = xnf.Id(pos, UniqueID.newID(STATIC_INNER_CLASS_BASE_NAME));

                    // create class def for static inner
                    final X10ClassDef staticInnerClassDef = xts.createClassDef();

                    staticInnerClassDef.superType(Types.ref(xts.Object()));
                    staticInnerClassDef.kind(ClassDef.MEMBER);
                    staticInnerClassDef.name(staticInnerClassName.id());
                    staticInnerClassDef.outer(Types.<X10ClassDef>ref(def));
                    staticInnerClassDef.setPackage(Types.ref(context.package_()));
                    staticInnerClassDef.flags(privateStatic);
                    staticInnerClassDef.setInterfaces(cld.classDef().interfaces());
                    staticInnerClassDef.setThisDef(ts.thisDef(pos, Types.ref(staticInnerClassDef.asType())));

                    // TODO set method bounds?
                    if (context.currentCode().staticContext()) {
                        staticInnerClassDef.setTypeBounds(Types.ref(new TypeConstraint()));
                    } else {
                        for (ParameterType pt :def.typeParameters()) {
                            staticInnerClassDef.addTypeParameter(pt, pt.getVariance());
                        }
                        staticInnerClassDef.setTypeBounds(def.typeBounds());
                    }

                    List<ParameterType> codeParam = null;
                    if (!(context.currentCode() instanceof X10ConstructorDef)) {
                        codeParam = getCurrentCodeParameterType(context);
                        for (ParameterType pt :codeParam) {
                            boolean contains = false;
                            for (ParameterType pt2: staticInnerClassDef.typeParameters()) {
                                if (pt.def().equals(pt2.def())) {
                                    contains = true;
                                    break;
                                }
                            }
                            if (!contains) {
                                staticInnerClassDef.addTypeParameter(pt, pt.getVariance());
                            }
                        }
                    }

                    // TODO handle "this" in type constraints
                    final X10MethodDef closureMethodDef = (X10MethodDef) xts.methodDef(pos, Types.ref(staticInnerClassDef.asType()), Flags.PUBLIC, cld.returnType(), ClosureCall.APPLY, cld.formalTypes());
                    List<LocalDef> forms = new LinkedList<LocalDef>();
                    for(Formal f: cl.formals())
                    	forms.add(f.localDef());

                    closureMethodDef.setFormalNames(forms);
                    closureMethodDef.setThisDef(staticInnerClassDef.thisDef());

                    staticInnerClassDef.setMethods(Collections.singletonList(closureMethodDef));
                    // create class decl
                    final List<TypeNode> interfaces = Collections.<TypeNode>singletonList(xnf.X10CanonicalTypeNode(pos, cld.asType()));
                    X10ClassDecl staticInnerClassDecl = (X10ClassDecl) xnf.ClassDecl(pos, xnf.FlagsNode(pos, privateStatic), staticInnerClassName, xnf.X10CanonicalTypeNode(pos, xts.Object()), interfaces, xnf.ClassBody(pos, Collections.<ClassMember>emptyList()));

                    List<TypeParamNode> tpns = new ArrayList<TypeParamNode>();
                    for (ParameterType pt : staticInnerClassDef.typeParameters()) {
                        tpns.add(xnf.TypeParamNode(pos, xnf.Id(pos, pt.name()), pt.getVariance()).type(pt));
                    }

                    staticInnerClassDecl = staticInnerClassDecl.typeParameters(tpns);

                    final List<NamedVariable> capturedVarsExThis = new ArrayList<NamedVariable>();
                    Map<String, X10FieldDef> nameToFieldDef = CollectionFactory.newHashMap();

                    // rewrite closure method body
                    closureBody = rewriteClosureBody(closureBody, staticInnerClassDef, capturedEnv, capturedVarsExThis, nameToFieldDef);

                    MethodDecl mdcl = xnf.MethodDecl(pos, xnf.FlagsNode(pos, Flags.PUBLIC), xnf.CanonicalTypeNode(pos, Types.baseType(cl.returnType().type())), xnf.Id(pos, ClosureCall.APPLY), cl.formals(), closureBody).methodDef(closureMethodDef);
                    mdcl = (MethodDecl) mdcl.body(closureBody);
                    mdcl = (MethodDecl) mdcl.typeCheck(this);

                    final ClassBody body = xnf.ClassBody(pos, Collections.<ClassMember>singletonList(mdcl));

                    staticInnerClassDecl = staticInnerClassDecl.body(body);

                    // add constructor
                    List<ClassMember> cm = new ArrayList<ClassMember>(staticInnerClassDecl.body().members());

                    List<Formal> formals = new ArrayList<Formal>(capturedEnv.size());
                    List<Ref<? extends Type>> argTypes = new ArrayList<Ref<? extends Type>>(capturedEnv.size());
                    List<Expr> args = new ArrayList<Expr>(capturedEnv.size());
                    Block body2 = xnf.Block(pos);

                    for (VarInstance<? extends VarDef> vi : capturedEnv) {
                        if (vi instanceof ThisInstance || (vi instanceof FieldInstance && !vi.flags().isFinal())) { // the latter means the receiver fo vi should be this
                        	final Name name = OUTER_NAME;

                            final X10LocalDef li = xts.localDef(pos, Flags.FINAL, Types.ref(vi.type()), name);
                            final X10Formal formal = xnf.Formal(pos, xnf.FlagsNode(pos, Flags.FINAL), xnf.X10CanonicalTypeNode(pos, Types.baseType(vi.type())), xnf.Id(pos, name)).localDef(li);

                            formals.add(formal);
                            argTypes.add(vi.def().type());
                            args.add(createExpr(pos, vi));

                            final X10FieldDef fi = nameToFieldDef.get(OUTER_NAME.toString());
                            staticInnerClassDef.addField(fi);

                            final FieldDecl fdcl = xnf.FieldDecl(pos, xnf.FlagsNode(pos, Flags.FINAL.Private()), xnf.X10CanonicalTypeNode(pos, vi.type()), xnf.Id(pos, name));
                            cm.add(fdcl.fieldDef(fi));

                            final Expr fa = xnf.FieldAssign(pos, xnf.Special(pos, Kind.THIS).type(staticInnerClassDef.asType()),
                            		xnf.Id(pos, name), Assign.ASSIGN, xnf.Local(pos, xnf.Id(pos, name)).localInstance(li.asInstance()).
                            		type(vi.type())).fieldInstance(fi.asInstance()).type(fi.asInstance().type());
                            body2 = body2.append(xnf.Eval(pos, fa));
                            break;
                        }
                    }

                    for (NamedVariable vn : capturedVarsExThis) {
                        final Name name = vn.name().id();

                        final X10LocalDef li = (vn instanceof Local) ?
                        					   (X10LocalDef) vn.varInstance().def() :
                        					    xts.localDef(pos, Flags.FINAL, Types.ref(vn.type()), vn.name().id());

                        final X10Formal formal = xnf.Formal(pos, xnf.FlagsNode(pos, Flags.FINAL), xnf.X10CanonicalTypeNode(pos, Types.baseType(vn.type())), xnf.Id(pos, name)).localDef(li);

                        formals.add(formal);
                        argTypes.add(vn.varInstance().def().type());
                        args.add(vn);

                        final X10FieldDef fd = nameToFieldDef.get(vn.name().toString());
                        assert(fd != null);

                        staticInnerClassDef.addField(fd);

                        final FieldDecl fdcl = xnf.FieldDecl(pos, xnf.FlagsNode(pos, fd.flags()), xnf.X10CanonicalTypeNode(pos, vn.type()), xnf.Id(pos, name));

                        cm.add(fdcl.fieldDef(fd));


                        final Expr fa = xnf.FieldAssign(pos, xnf.Special(pos, Kind.THIS).type(staticInnerClassDef.asType()), xnf.Id(pos, name),
                        		Assign.ASSIGN, xnf.Local(pos, xnf.Id(pos, name)).localInstance(li.asInstance()).type(vn.type())).fieldInstance(fd.asInstance()).type(fd.asInstance().type());

                        body2 = body2.append(xnf.Eval(pos, fa));
                    }

                    final X10ConstructorDecl consdcl = (X10ConstructorDecl) xnf.ConstructorDecl(pos, xnf.FlagsNode(pos, Flags.PRIVATE), staticInnerClassDecl.name(), formals, body2);
                    consdcl.typeParameters(staticInnerClassDecl.typeParameters());

                    final CanonicalTypeNode typeNode = xnf.CanonicalTypeNode(pos, staticInnerClassDef.asType());
                    consdcl.returnType(typeNode);

                    final List<Type> typeArgs = new ArrayList<Type>(staticInnerClassDef.typeParameters());

                    final X10ClassType staticInnerClassType = staticInnerClassDef.asType().typeArguments(typeArgs);

                    final X10ConstructorDef consd = (X10ConstructorDef) xts.constructorDef(pos,
                                                              Types.ref(staticInnerClassType),
                                                              Flags.PRIVATE,
                                                              argTypes);

                    List<LocalDef> formalNames = new LinkedList<LocalDef>();
                    for(Formal form: formals)
                    	formalNames.add(form.localDef());
                    consd.setFormalNames(formalNames);

                    cm.add((ClassMember) consdcl.constructorDef(consd).typeCheck(this));

                    staticInnerClassDef.addConstructor(consd);

                    staticInnerClassDecl = staticInnerClassDecl.classDef(staticInnerClassDef);

                    final ClassBody cb = staticInnerClassDecl.body();
                    nmembers.add((ClassMember) staticInnerClassDecl.body(cb.members(cm)).typeCheck(this));

                    putClosureMappingType(cld.asType(), staticInnerClassType);
                    
                    return xnf.New(pos, xnf.CanonicalTypeNode(pos, Types.ref(staticInnerClassType)), args).constructorInstance(consd.asInstance()).type(cl.type());
                }

                return n;
            }

            private Block rewriteClosureBody(Block closureBody,
                                             final X10ClassDef staticInnerClassDef,
                                             final List<VarInstance<? extends VarDef>> capturedEnv,
                                             final List<NamedVariable> capturedVarsExThis,
                                             final Map<String, X10FieldDef> nameToFieldDef
            ) {
                final Position pos = Position.COMPILER_GENERATED;
                return (Block) closureBody.visit(new ContextVisitor(job, ts, nf){
                    @Override
					protected Node leaveCall(Node parent, Node old, Node n, NodeVisitor v) throws SemanticException {
                        // field => out.field
                    	if (n instanceof Field) {
                            final Field field = (Field) n;
                            for (VarInstance<? extends VarDef> var : capturedEnv) {
                                if (!var.flags().isFinal()) {
                                    continue;
                                }

                                // because of coming not from the same VarInstance
                                if (var.def().equals(field.fieldInstance().def())) {
                                    final Receiver target = field.target();
                                    if (target instanceof Local) {
                                    	return n;
                                    }

                                    if (!contains(capturedVarsExThis, var.def()))
                                        capturedVarsExThis.add((NamedVariable) old);

                                    Flags ff = Flags.FINAL.Private();
                                    if (field.flags().isTransient())
                                    	ff = ff.Transient();

                                    X10FieldDef fd = nameToFieldDef.get(var.name().toString());
                                    if (fd == null) {
                                        fd = xts.fieldDef(pos, Types.ref(staticInnerClassDef.asType()), ff, Types.ref(field.type()), field.name().id());
                                        nameToFieldDef.put(var.name().toString(), fd);
                                    }

                                    fd = nameToFieldDef.get(var.name().toString());
                                    return xnf.Field(pos, xnf.This(pos).type(staticInnerClassDef.asType()), xnf.Id(pos, fd.name())).fieldInstance(fd.asInstance()).type(var.type());
                                }
                            }
                            return field.targetImplicit(false);
                        }

                        // local => field
                        if (n instanceof Local) {
                            Local local = (Local) n;
                            for (VarInstance<? extends VarDef> var : capturedEnv) {
                                if (var.def().equals(local.localInstance().def())) {
                                    if (!contains(capturedVarsExThis, var.def()))
                                        capturedVarsExThis.add((NamedVariable) old);

                                    final Flags ff = Flags.FINAL.Private();

                                    X10FieldDef fd = nameToFieldDef.get(var.name().toString());
                                    if(fd == null) {
                                        fd = xts.fieldDef(pos, Types.ref(staticInnerClassDef.asType()), ff, Types.ref(var.type()), local.name().id());
                                        nameToFieldDef.put(var.name().toString(), fd);
                                    }
                                    assert(fd != null);

                                    return xnf.Field(pos, xnf.This(pos).type(staticInnerClassDef.asType()), xnf.Id(pos, fd.name())).fieldInstance(fd.asInstance()).type(var.type());
                                }
                            }
                            return n;
                        }

                        // this => out$
                        if (n instanceof Special) {
                            Special special = (Special) n;
                            if (special.kind() == Special.THIS) {
                                final Type type = Types.baseType(special.type());

                                X10FieldDef fi = nameToFieldDef.get(OUTER_NAME.toString());
                                if(fi == null) {
                                    fi = xts.fieldDef(pos, Types.ref(staticInnerClassDef.asType()), Flags.PRIVATE.Final(), Types.ref(type), OUTER_NAME);
                                    nameToFieldDef.put(OUTER_NAME.toString(), fi);
                                }

                                final Special thiz = (Special) xnf.Special(pos, Kind.THIS).type(staticInnerClassDef.asType());
                                return xnf.Field(pos, thiz, xnf.Id(pos, OUTER_NAME)).fieldInstance(fi.asInstance()).type(type);
                            }
                        }
                        return n;
                    }
                }.context(context));
            }
        }.context(context);
    }

    /**
     * Checks a given variable definition is in a list.
     * @param capturedVars The list which should be checked
     * @param def The variable definition
     * @return True if the given variable definition is in the given list.
     */
    static boolean contains(List<NamedVariable> capturedVars, VarDef def) {
        for (NamedVariable nv : capturedVars) {
            if (nv.varInstance().def().equals(def)) {
                return true;
            }
        }
        return false;
    }

    /**
     * Traverses the given context backwards and returns the first type parameter list from the first non closure definition.
     * @param ctx The context which should be traversed
     * @return The type parameter list
     */
    List<ParameterType> getCurrentCodeParameterType(Context ctx) {
        X10CodeDef codeDef = ctx.currentCode();
        if (!(codeDef instanceof ClosureDef)) {
            return codeDef.typeParameters();
        }
        return getCurrentCodeParameterType(ctx.pop());
    }

    /**
     * Creates an expression AST node for a given variable definition
     * @param pos The position of the new AST node
     * @param vi The variable definition
     * @return The expression AST node
     */
    Expr createExpr(Position pos, VarInstance<? extends VarDef> vi) {
        if (vi instanceof X10LocalInstance) {
            return xnf.Local(pos, xnf.Id(pos, vi.name())).localInstance((LocalInstance) vi.def().asInstance()).type(vi.type());
        } else if (vi instanceof X10FieldInstance) {
            return xnf.Field(pos, xnf.Special(pos, Kind.THIS).type(((X10FieldInstance) vi).container()), xnf.Id(pos, vi.name())).fieldInstance((FieldInstance) vi.def().asInstance()).type(vi.type());
        } else if (vi instanceof ThisInstance) {
            return xnf.Special(pos, Kind.THIS).type(vi.type());
        }
        throw new InternalCompilerError("");//TODO
    }
}
