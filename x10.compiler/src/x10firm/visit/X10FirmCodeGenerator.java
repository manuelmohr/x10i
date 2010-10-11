package x10firm.visit;

import static x10cpp.visit.ASTQuery.*;
import static x10cpp.visit.Emitter.*;
import static x10cpp.visit.SharedVarsMethods.*;

import java.util.*;

import firm.Firm;

import polyglot.ast.*;
import polyglot.types.*;
import polyglot.util.*;
import polyglot.visit.Translator;
import x10.Configuration;
import x10.ast.*;
import x10.extension.*;
import x10.types.*;
import x10.types.checker.Converter;
import x10.types.checker.PlaceChecker;
import x10.util.*;
import x10.visit.*;
import x10cpp.types.X10CPPContext_c;
import x10cpp.visit.ASTQuery;
import x10cpp.visit.Emitter;
import x10cpp.visit.SharedVarsMethods;
import x10cpp.visit.StructMethodAnalyzer;
import x10firm.NullCodeWriter;
import x10firm.types.X10FirmContext_c;

public class X10FirmCodeGenerator extends X10DelegatingVisitor {
	
	protected final CodeWriter sw;
	protected final Translator tr;

	protected Emitter emitter;
	protected ASTQuery query;
	public X10FirmCodeGenerator(Translator tr) {
		this.sw 	 = new NullCodeWriter();
		this.tr 	 = tr;
		this.emitter = new Emitter(tr);
		this.query   = new ASTQuery(tr);
	}
	
	private void output(String s) {
		System.out.println(s);
	}
	
	public void visit(Node n) {
		X10CPPContext_c context = (X10CPPContext_c) tr.context();

		tr.job().compiler().errorQueue().enqueue(ErrorInfo.SEMANTIC_ERROR,
				"Unhandled node type: "+n.getClass(), n.position());
	}

    public void visit(TypeDecl_c n) {
        // do nothing
        output(" /* " + n + " *" + "/ ");
    }

    public void visit(LocalTypeDef_c n) {
        // do nothing
        output(" /* " + n + " *" + "/ ");
    }

	public void visit(X10ClassDecl_c n) {
		processClass(n);
	}

	void processClass(X10ClassDecl_c n) {
		X10FirmContext_c context 	= (X10FirmContext_c) tr.context();
		X10ClassDef def 			= (X10ClassDef) n.classDef();
        X10TypeSystem_c xts 		= (X10TypeSystem_c) tr.typeSystem();
        boolean isStruct 			= xts.isStructType(def.asType());
        X10Ext ext 					= (X10Ext) n.ext();
        
        // TODO: how do we treat native rep classes ?
        
        assert (!def.isNested()) : ("Nested class alert!");
        
        // visit the node children (class body) 
        n.print(n.body(), sw, tr);
	}
	
	public void visit(LocalClassDecl_c n) {
		assert (false) : ("Local classes should have been removed by a separate pass");
	}
	
    private void visitInterfaceBody(ClassBody_c n, X10FirmContext_c context,
            X10ClassType currentClass, X10ClassType superClass,
            X10TypeSystem xts) {
    
    }
    
    private void visitStructBody(ClassBody_c n, X10FirmContext_c context,
            X10ClassType currentClass, X10ClassType superClass,
            X10TypeSystem xts) {
    	
    }
    
    private void visitClassBody(ClassBody_c n, X10FirmContext_c context,
            X10ClassType currentClass, X10ClassType superClass,
            X10TypeSystem xts) {

    	X10FirmContext_c ctx 		= (X10FirmContext_c)tr.context();
        List<ClassMember> members 	= n.members();

        if (!members.isEmpty()) {
            String className = Emitter.translateType(currentClass);

            for (ClassMember member : members) {
                n.printBlock(member, sw, tr);
            }
                
        }
    }
	
    public void visit(ClassBody_c n) {
        X10FirmContext_c ctx	 	= (X10FirmContext_c) tr.context();
        X10ClassType currentClass 	= (X10ClassType) ctx.currentClass();
        X10ClassType superClass 	= (X10ClassType) X10TypeMixin.baseType(currentClass.superClass());
        X10TypeSystem xts 			= (X10TypeSystem) tr.typeSystem();
        
        if (currentClass.flags().isInterface()) {
            visitInterfaceBody(n, ctx, currentClass, superClass, xts);
        } else if (currentClass.isX10Struct()) {
            visitStructBody(n, ctx, currentClass, superClass, xts);
        } else {
            visitClassBody(n, ctx, currentClass, superClass, xts);
        }
    }

    public void visit(PackageNode_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
		String pkgName = translateFQN(n.package_().get().fullName().toString());
    }

    public void visit(Import_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
    }
    
    protected void processMain(X10ClassType container) {
        X10TypeSystem_c xts = (X10TypeSystem_c) container.typeSystem();
    }
    
	public void visit(MethodDecl_c dec) {
		X10FirmContext_c ctx 	= (X10FirmContext_c) tr.context();
		X10TypeSystem_c xts 	= (X10TypeSystem_c) tr.typeSystem();
		X10Flags flags 			= X10Flags.toX10Flags(dec.flags().flags());
		
		if (flags.isNative())
			return;

		X10MethodDef def 		= (X10MethodDef) dec.methodDef();
		X10MethodInstance mi 	= (X10MethodInstance) def.asInstance();
		X10ClassType container 	= (X10ClassType) mi.container();
		
		if ((container.x10Def().typeParameters().size() != 0) && flags.isStatic()) {
			// handle static method  
			return;
		}
		
		//if (query.isMainMethod(dec))
		//    processMain(container);
		String methodName = mi.name().toString();

		if (dec.body() != null) {
			if (!flags.isStatic()) {
				// add local vars for closure realisation.
				VarInstance ti = xts.localDef(Position.COMPILER_GENERATED, Flags.FINAL,
						Types.ref(container), Name.make(THIS)).asInstance();
				ctx.addVariable(ti);
			}
			dec.printSubStmt(dec.body(), sw, tr);
		} else {
			// Define property getter methods.
			if (flags.isProperty() && flags.isAbstract() && mi.formalTypes().size() == 0 && mi.typeParameters().size() == 0) {
				X10FieldInstance fi = (X10FieldInstance) container.fieldNamed(mi.name());
				if (fi != null) {
					String fieldName = fi.name().toString();
				}
			}
		}
	}

	public void visit(ConstructorDecl_c dec) {
		X10FirmContext_c ctx 		= (X10FirmContext_c) tr.context();
	    if (dec.flags().flags().isNative())
	        return;

	    X10ClassType container 		= (X10ClassType) dec.constructorDef().container().get();
	    String typeName 			= Emitter.translateType(container.def().asType());
	    X10TypeSystem xts 			= (X10TypeSystem)ctx.typeSystem();

	    X10ConstructorInstance ci 	= (X10ConstructorInstance) dec.constructorDef().asInstance();
	    
	    // constructor must have a body
	    if (dec.body() == null) {
	        assert false : dec.position().toString();
	    }

	    // no static constructors allowed
	    assert (!dec.flags().flags().isStatic());

	    TypeSystem ts = tr.typeSystem();

	    // add local vars for closure realisation.
	    VarInstance ti = ts.localDef(Position.COMPILER_GENERATED, Flags.FINAL,
	                                 Types.ref(container), Name.make(THIS)).asInstance();
	    ctx.addVariable(ti);

	    Block_c body = (Block_c) dec.body();

	    // Synthetic fields must be initialized before everything else
	    for (Stmt s : body.statements()) {
	        if (query.isSyntheticOuterAccessor(s)) {
	            dec.print(s, sw, tr); 
	        }
	    }

	    for (Stmt s : body.statements()) {
	    	// handle constructor calls -> super etc. 
	        if (s instanceof ConstructorCall) {
	            ConstructorCall call = (ConstructorCall)s;
	            if (call.kind() == ConstructorCall.SUPER) {
	            	// super call
	                if (container.isX10Struct()) {
	                    String superClass = Emitter.structMethodClass(container.superClass().toClass(), true, true);
	                    // TODO: 
	                } else {
	                    String superClass = Emitter.translateType(container.superClass());
	                    // TODO: 
	                }
	            } else if (call.kind() == ConstructorCall.THIS) {
	                if (container.isX10Struct()) {
	                    // TODO: 
	                    if (call.arguments().size() > 0) sw.write(", ");
	                } else {
	                    // TODO: 
	                }
	            }
	            if (call.arguments().size() > 0) {
	                for(Expr e : (List<Expr>) call.arguments() )
	                    dec.print(e, sw, tr);
	            }
	        } else if (query.isSyntheticOuterAccessor(s)) {
	            // we did synthetic field initialisation earlier
	        } else {
	            dec.printBlock(s, sw, tr);
	        }
	    }

	    if (!container.flags().isAbstract()) {
	        // _make
	        if (!container.isX10Struct()) {
	        	// alloc container. 
	        }
	        for (Iterator<Formal> i = dec.formals().iterator(); i.hasNext(); ) {
	            Formal f = i.next();
	            String formal_name = f.name().id().toString();
	        }
	    }
	}

	public void visit(FieldDecl_c dec) {
		X10FirmContext_c ctx 			= (X10FirmContext_c) tr.context();
	    X10ClassType declaringClass 	= (X10ClassType)dec.fieldDef().asInstance().container();
	    
	    boolean isStatic = dec.flags().flags().isStatic();
	    
	    if ((((X10ClassDef)declaringClass.def()).typeParameters().size() != 0) && isStatic) {
	    	// static field 
	        return;
	    }

	    // Ignore the initializer -- this will have been done in extractInits/extractStaticInits
	    // FIXME: the above breaks switch constants!
	    if (isStatic) {
	    	dec.print(dec.init(), sw, tr);
	    }
	    String container = declaringClass.isX10Struct() ? Emitter.structMethodClass(declaringClass, true, true) : 
	    	Emitter.translateType(dec.fieldDef().asInstance().container());
	}
	
	public void visit(PropertyDecl_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
	}

	public void visit(Initializer_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
	}
	
    public void visit(AssignPropertyBody_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
    }

	public void visit(Assert_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
	}

	public void visit(Switch_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
		
	    n.print(n.expr(), sw, tr);
	    for(SwitchElement s : n.elements())
	    	n.print(s, sw, tr);
	}

	public void visit(SwitchBlock_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
		
		for(Stmt s : n.statements())
			n.print(s, sw, tr);
	}

	public void visit(Case_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
		
		if (n.expr() == null) {
			// default case: 
			
		} else {
			if (n.expr() instanceof Field_c && n.expr().isConstant()) {
				// handle constant case expr. 
			} else {
				n.print(n.expr(), sw, tr);
			}
		}
	}

	public void visit(Branch_c br) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
	}
	
	public void visit(Labeled_c label) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
	}

	public void visit(Assign_c asgn) {
		X10FirmContext_c ctx 	= (X10FirmContext_c) tr.context();
		
	    boolean unsigned_op 	= false;
	    String opString 		= asgn.operator().toString();
	    NodeFactory nf 			= tr.nodeFactory();
	    X10TypeSystem_c xts 	= (X10TypeSystem_c) tr.typeSystem();
	    Context context 		= tr.context();

	    if (opString.equals(">>>=")) {
	        unsigned_op = true;
	        opString = opString.substring(1);
	    }

	    Expr lhs = asgn.left();
	    Expr rhs = asgn.right();
	    if (unsigned_op) {
	    	String type  = Emitter.translateType(asgn.type());
	    	String utype = emitter.makeUnsignedType(lhs.type());
	    }
	    
	    asgn.printSubExpr(lhs, false, sw, tr);
	    if (asgn.operator() != Assign_c.ASSIGN) {
	        assert (false);
	    }

	    Type aType = lhs.type();
	    boolean rhsNeedsCast = !xts.typeDeepBaseEquals(aType, rhs.type(), context);
	    if (rhsNeedsCast) {
	        // Cast is needed to ensure conversion/autoboxing.
	    	String castType = chevrons(Emitter.translateType(aType, true));
	    }
	    
	    asgn.printSubExpr(rhs, true, sw, tr);
	}

	public void visit(Return_c ret) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
		
		Expr e = ret.expr();
		if (e == null) {
			return;
		} else {
			assert (ctx.currentCode() instanceof FunctionDef);
			
			X10TypeSystem_c xts = (X10TypeSystem_c) tr.typeSystem();
			FunctionDef container = (FunctionDef)ctx.currentCode();
			Type rType = container.returnType().get();
			boolean rhsNeedsCast = !xts.typeDeepBaseEquals(rType, e.type(), ctx);
			
			if (rhsNeedsCast) {
				String toCast = chevrons(Emitter.translateType(rType, true));
			    // Cast is needed to ensure conversion/autoboxing.
			}

			ret.print(e, sw, tr);
		}
	}

	public void visit(Formal_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
	}

	public void visit(LocalDecl_c dec) {
		X10FirmContext_c ctx 	= (X10FirmContext_c) tr.context();
	    X10TypeSystem xts 		= (X10TypeSystem)ctx.typeSystem();
	    
        boolean stackAllocate = false;
        try {
            Type annotation = (Type) xts.systemResolver().find(QName.make("x10.compiler.StackAllocate"));
            if (!((X10Ext) dec.ext()).annotationMatching(annotation).isEmpty()) {
                stackAllocate = true;
                System.err.println("@StackAllocate " + dec);
            }
        } catch (SemanticException e) { 
            /* Ignore exception when looking for annotation */  
        }
        
        String tmpName = null;
        if (stackAllocate) {
            tmpName = "_StackAllocate_"+dec.name().id().toString();
            String type = Emitter.translateType(dec.type().type(), false);
        }

	    Expr initexpr = dec.init();
	    if (initexpr != null) {
	        Type aType = dec.type().type();
	        boolean rhsNeedsCast = !xts.typeDeepBaseEquals(aType, initexpr.type(), ctx);
	        if (rhsNeedsCast) {
	        	String toCast = chevrons(Emitter.translateType(aType, true));
	            // Cast is needed to ensure conversion/autoboxing.
	        }
	        dec.print(initexpr, sw, tr);
	    }
	}

	public void visit(Block_c b) {
		List<Stmt> stmts = b.statements();
		
		for(Stmt s : stmts) {
			b.printBlock(s, sw, tr);
		}
	}

	public void visit(StmtSeq_c n) {
	    List<Stmt> stmts = n.statements();

	    output("In StmtSeq_c"); 
	    for (Stmt s : stmts)
	        n.printBlock(s, sw, tr);
	}

	public void visit(StmtExpr_c n) {
		// visit the children 
	    List<Stmt> stmts = n.statements();
	    
	    for (Stmt stmt : stmts)
	        n.printBlock(stmt, sw, tr);
	    
	    // evaulate the stmt expr
	    Expr e = n.result();
	    if (e != null)
	        n.print(e, sw, tr);
	}

	public void visit(For_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
		assert false;
	}

	public void visit(Do_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
		
	    Stmt body = n.body();
	    if (!(body instanceof Block_c))
	        body = tr.nodeFactory().Block(body.position(), body);

	    n.print(body, sw, tr);
	    n.printBlock(n.cond(), sw, tr);
	}

	public void visit(While_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
		
	    n.printBlock(n.cond(), sw, tr);
	    Stmt body = n.body();
	    if (!(body instanceof Block_c))
	        body = tr.nodeFactory().Block(body.position(), body);

	    n.print(body, sw, tr);
	}

	public void visit(If_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();

		n.printBlock(n.cond(), sw, tr);
		n.print(n.consequent(), sw, tr);
		
		if (n.alternative() != null) {
			// else block 
			Stmt alternative = n.alternative();
			if (alternative instanceof Block_c) {
				Block_c block = (Block_c) alternative;
				if (block.statements().size() == 1 && block.statements().get(0) instanceof If_c)
					alternative = (Stmt) block.statements().get(0);
			}
			n.print(alternative, sw, tr);
		}
	}

	public void visit(Empty_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
	}

	public void visit(Eval_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
		
		n.print(n.expr(), sw, tr);
	}
	
	private Expr cast(Expr a, Type fType) {
		X10TypeSystem xts = (X10TypeSystem) tr.typeSystem();
		X10NodeFactory nf = (X10NodeFactory) tr.nodeFactory();
		Context ctx = tr.context();
		
		if (!xts.typeDeepBaseEquals(fType, a.type(), ctx)) {
			Position pos = a.position();
			a = nf.X10Cast(pos, nf.CanonicalTypeNode(pos, fType), a,
			               Converter.ConversionType.UNCHECKED).type(fType);
        }
		return a;
	}
	
	private static boolean needsNullCheck(Receiver e) {
	    if (e instanceof X10CanonicalTypeNode_c)
	        return false;
	    if (e instanceof X10Special_c)
	        return ((X10Special_c) e).qualifier() != null;
	    if (e instanceof X10Cast_c)
	        return needsNullCheck(((X10Cast_c) e).expr());
	    return !X10TypeMixin.isNonNull(e.type());
	}
	
	public void visit(X10Call_c n) {
		X10FirmContext_c ctx 		= (X10FirmContext_c) tr.context();
		X10TypeSystem_c xts 		= (X10TypeSystem_c) tr.typeSystem();
		X10MethodInstance mi 		= (X10MethodInstance) n.methodInstance();
		Receiver target 			= n.target();
		Type t 						= target.type();
		X10MethodDef md 			= mi.x10Def();
		
		if (mi.flags().isStatic()) {
		    TypeNode tn =
		        target instanceof TypeNode ?
		                (TypeNode) target :
		                tr.nodeFactory().CanonicalTypeNode(target.position(), t);
		    if (t instanceof ParameterType) {
		        // Rewrite to the class declaring the field.
		        target = tn.typeRef(md.container());
		        n = (X10Call_c) n.target(target);
		    }
		    if (t.isClass()) {
		        X10ClassType ct = (X10ClassType)t.toClass();
		        X10ClassDef cd = (X10ClassDef)ct.def();
		   //     target = tn.typeRef(Types.ref(getStaticMemberContainer((X10ClassType)cd.asType())));
		    }
		}
		
		
	}

	public void visit(RegionMaker_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
	}

	public void visit(ConstantDistMaker_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
	}

	public void visit(Field_c n) {
		X10FirmContext_c ctx 	= (X10FirmContext_c) tr.context();
		Receiver target 		= n.target();
		Type t 					= target.type();
		X10TypeSystem xts 		= (X10TypeSystem) t.typeSystem();
		X10FieldInstance fi 	= (X10FieldInstance) n.fieldInstance();
		X10FieldDef fd 			= fi.x10Def();
		
		assert false; 
	}

	public void visit(Local_c n) {
		X10FirmContext_c ctx 	= (X10FirmContext_c) tr.context();
		LocalInstance var 		= n.localInstance();
		
		String name = var.name().toString();
	}

	public void visit(New_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
	}

	public void visit(FloatLit_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
		
		String val;
		if (n.kind() == FloatLit_c.FLOAT)
			val = Float.toString((float) n.value()) + "f";
		else if (n.kind() == FloatLit_c.DOUBLE)
			val = Double.toString(n.value());
		else
			throw new InternalCompilerError("Unrecognized FloatLit kind " + n.kind());
	}

	public void visit(IntLit_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
		
	    String val;
	    if (n.kind() == X10IntLit_c.ULONG) {
	        if (n.boundary())
	            val = "0x" + Long.toHexString(n.value()).toUpperCase() + "llu";
	        else if (n.value() < 0)
	            val = "0x" + Long.toHexString(n.value()).toUpperCase() + "llu";
	        else
	            val = Long.toString(n.value()) + "ull";
	    } else if (n.kind() == X10IntLit_c.UINT) {
	        if (n.value() >= 0x80000000L)
	            val = "0x" + Long.toHexString(n.value()).toUpperCase() + "u";
	        else if (n.boundary())
	            val = "0x" + Long.toHexString(-n.value()).toUpperCase() + "u";
	        else
	            val = Long.toString((int) n.value()) + "u";
	    } else if (n.kind() == IntLit_c.LONG) {
	        if (n.boundary())
	            val = "0x" + Long.toHexString(n.value()).toUpperCase() + "llu";
	        else
	            val = Long.toString(n.value()) + "ll";
	    } else if (n.kind() == IntLit_c.INT) {
	        if (n.value() >= 0x80000000L)
	            val = "0x" + Long.toHexString(n.value()).toUpperCase() + "u";
	        else if (n.boundary())
	            val = "0x" + Long.toHexString(-n.value()).toUpperCase() + "u";
	        else
	            val = Long.toString((int) n.value());
	    } else
	        throw new InternalCompilerError("Unrecognized IntLit kind " + n.kind());
	    
	    
	}

	public void visit(NullLit_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
	}

	public void visit(StringLit_c n) {
		X10FirmContext_c ctx 	= (X10FirmContext_c) tr.context();
        X10TypeSystem_c xts 	= (X10TypeSystem_c) tr.typeSystem();
        String str              = n.stringValue();
	}

	public void visit(CharLit_c lit) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
		char val 			 = lit.charValue(); 
	}

	public void visit(BooleanLit_c lit) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
		boolean val			 = lit.value(); 
		
	}

	public void visit(Id_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
		String name          = n.id().toString();
		
		
	}

	public void visit(X10Cast_c c) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
	}

	public void visit(SubtypeTest_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
	}

	public void visit(X10Instanceof_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
	}

	public void visit(Throw_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
	}

	public void visit(Try_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
	}

	public void visit(Catch_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
	}

	public void visit(Atomic_c a) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
	}

	public void visit(Await_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
	}

	public void visit(Next_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
	}

	public void visit(ForLoop_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
	}
	
    public void visit(ForEach_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
    }

    public void visit(AtEach_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
    }

    public void visit(Finish_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
    }

    public void visit(ArrayAccess_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
    }

    public void visit(ParExpr_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
    }

    public void visit(Conditional_c n) {
        X10FirmContext_c context = (X10FirmContext_c) tr.context();
    
        n.printSubExpr(n.cond(), false, sw, tr);
        String type = Emitter.translateType(n.type(), true);
        
        n.printSubExpr(n.consequent(), true, sw, tr);
        n.printSubExpr(n.alternative(), true, sw, tr);
    }

    public void visit(Here_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
    }

    public void visit(Async_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
    }

    public void visit(X10Special_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
    }

    public void visit(Closure_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
    }
    
	public void visit(ClosureCall_c c) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
	}

	public void visit(X10CanonicalTypeNode_c n) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
	}

	public void visit(X10Unary_c n) {
		X10FirmContext_c ctx 	= (X10FirmContext_c) tr.context();
	    Expr left 				= n.expr();
	    Type l 					= left.type();
	    X10TypeSystem xts 		= (X10TypeSystem) tr.typeSystem();
	    NodeFactory nf 			= tr.nodeFactory();
	    Unary.Operator op 		= n.operator();

	    if (op == Unary.POST_DEC || op == Unary.POST_INC || op == Unary.PRE_DEC || op == Unary.PRE_INC) { // TODO
	        visit((Unary_c)n);
	        return;
	    }
	    if (l.isNumeric()) { 
	        visit((Unary_c)n);
	        return;
	    }
	    if (l.isBoolean()) { 
	        visit((Unary_c)n);
	        return;
	    }
	    assert (false) : ("User-defined unary operators should have been desugared earier");
	}

	public void visit(Unary_c n) {
		X10FirmContext_c ctx 		= (X10FirmContext_c) tr.context();
		Unary_c.Operator operator 	= n.operator();
		Expr expr 					= n.expr();
		
		if (operator == Unary_c.NEG && expr instanceof IntLit) {
		    IntLit_c lit = (IntLit_c) expr;
		    IntLit.Kind kind = (lit.kind() == X10IntLit_c.UINT) ? IntLit.INT : ((lit.kind() == X10IntLit_c.ULONG) ? IntLit.LONG : lit.kind());
		    n.printSubExpr(lit.value(-lit.longValue()).kind(kind), true, sw, tr);
		}
		else if (operator.isPrefix()) {
			n.printSubExpr(expr, false, sw, tr);
		}
		else {
			n.printSubExpr(expr, false, sw, tr);
		}
	}

	public void visit(X10Binary_c n) {
		X10FirmContext_c ctx 	= (X10FirmContext_c) tr.context();
	    Expr left 				= n.left();
	    Type l 					= left.type();
	    Expr right 				= n.right();
	    Type r 					= right.type();
	    X10TypeSystem xts 		= (X10TypeSystem) tr.typeSystem();
	    NodeFactory nf 			= tr.nodeFactory();
	    Binary.Operator op 		= n.operator();

	    if (op == Binary.EQ || op == Binary.NE) { 
	        Type c = null;
	        if (l.isNumeric() && r.isNumeric()) {
	            try {
	                c = xts.promote(l, r);
	            } catch (SemanticException e) { assert (false); }
	        }
	        if (c != null && !xts.isParameterType(c) && !xts.typeBaseEquals(c, l, ctx)) {
	        	String type = Emitter.translateType(c, true); 
	        }
	        n.printSubExpr(left, sw, tr);
	        if (c != null && !xts.isParameterType(c) && !xts.typeBaseEquals(c, r, ctx)) {
	        	String type = Emitter.translateType(c, true); 
	        }
	        n.printSubExpr(right, sw, tr);
	        return;
	    }
	    
	    if (l.isNumeric() && r.isNumeric()) { 
	        visit((Binary_c)n);
	        return;
	    }
	    if (l.isBoolean() && r.isBoolean()) { 
	        visit((Binary_c)n);
	        return;
	    }
	    if (op == Binary.ADD && (l.isSubtype(xts.String(), ctx) || r.isSubtype(xts.String(), ctx))) { 
	        visit((Binary_c)n);
	        return;
	    }
	    assert (false) : ("User-defined binary operators should have been desugared earier");
	}

	public void visit(Binary_c n) {
		X10FirmContext_c ctx 	= (X10FirmContext_c) tr.context();
		X10TypeSystem_c xts 	= (X10TypeSystem_c) tr.typeSystem();
		String opString 		= n.operator().toString();
		
		// Boolean short-circuiting operators are ok
		assert (opString.equals("&&") || opString.equals("||"))
		    : "visiting "+n.getClass()+" at "+n.position()+": "+n;

		n.printSubExpr(n.left(),  true, sw, tr);
		n.printSubExpr(n.right(), false, sw, tr);
	}

	public void visit(ArrayInit_c n) {
		throw new InternalCompilerError("Should not be invoked");
	}

	public void visit(SettableAssign_c n) {
		assert (false) : ("Function assign should have been desugared earlier");
	}
	
	public void visit(Tuple_c c) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
	}

	public void visit(When_c n) {
        assert (false) : ("When should have been desugared earlier");
	}

    public void visit(Future_c n) {
        assert (false) : ("Future should have been desugared earlier");
    }

    public void visit(AtStmt_c n) {
        assert (false) : ("At statements are deprecated");
    }

    public void visit(AtExpr_c n) {
        assert (false) : ("At expression should have been desugared earlier");
    }
}
