package x10firm.visit;

import static x10cpp.visit.ASTQuery.assertNumberOfInitializers;
import static x10cpp.visit.ASTQuery.getStringPropertyInit;
import static x10cpp.visit.SharedVarsMethods.CPP_NATIVE_STRING;
import static x10cpp.visit.SharedVarsMethods.CUDA_NATIVE_STRING;
import static x10cpp.visit.SharedVarsMethods.THIS;
import static x10cpp.visit.SharedVarsMethods.chevrons;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import polyglot.ast.ArrayAccess_c;
import polyglot.ast.ArrayInit_c;
import polyglot.ast.Assert_c;
import polyglot.ast.Assign;
import polyglot.ast.Assign_c;
import polyglot.ast.Binary;
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
import polyglot.ast.ConstructorCall;
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
import polyglot.ast.Node;
import polyglot.ast.NodeFactory;
import polyglot.ast.NullLit_c;
import polyglot.ast.PackageNode_c;
import polyglot.ast.Receiver;
import polyglot.ast.Return_c;
import polyglot.ast.Stmt;
import polyglot.ast.StringLit_c;
import polyglot.ast.SwitchBlock_c;
import polyglot.ast.SwitchElement;
import polyglot.ast.Switch_c;
import polyglot.ast.Throw_c;
import polyglot.ast.TopLevelDecl;
import polyglot.ast.Try_c;
import polyglot.ast.TypeNode;
import polyglot.ast.Unary;
import polyglot.ast.Unary_c;
import polyglot.ast.While_c;
import polyglot.types.Context;
import polyglot.types.Flags;
import polyglot.types.FunctionDef;
import polyglot.types.LocalInstance;
import polyglot.types.Name;
import polyglot.types.QName;
import polyglot.types.SemanticException;
import polyglot.types.Type;
import polyglot.types.TypeSystem;
import polyglot.types.Types;
import polyglot.types.VarInstance;
import polyglot.util.CodeWriter;
import polyglot.util.ErrorInfo;
import polyglot.util.InternalCompilerError;
import polyglot.util.Position;
import polyglot.visit.Translator;
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
import x10.ast.X10NodeFactory;
import x10.ast.X10SourceFile_c;
import x10.ast.X10Special_c;
import x10.ast.X10Unary_c;
import x10.extension.X10Ext;
import x10.types.ParameterType;
import x10.types.X10ClassDef;
import x10.types.X10ClassType;
import x10.types.X10ConstructorInstance;
import x10.types.X10Def;
import x10.types.X10FieldDef;
import x10.types.X10FieldInstance;
import x10.types.X10Flags;
import x10.types.X10MethodDef;
import x10.types.X10MethodInstance;
import x10.types.X10TypeSystem;
import x10.types.checker.Converter;
import x10.visit.X10DelegatingVisitor;
import x10cpp.visit.ASTQuery;
import x10cpp.visit.Emitter;
import x10firm.NullCodeWriter;
import x10firm.types.X10FirmContext_c;
import x10firm.types.X10FirmTypeSystem_c;
import firm.TargetValue;

public class X10FirmCodeGenerator extends X10DelegatingVisitor {
	protected final CodeWriter sw;
	protected final Translator tr;
	
	private firm.Construction con = null;

	protected Emitter emitter;
	protected ASTQuery query;
	
	/** The method the current Firm graph is constructed for */
	private X10MethodDef current_method;
	
	public X10FirmCodeGenerator(Translator translator) {
		this.sw 	 = new NullCodeWriter();
		this.tr 	 = translator;
		this.emitter = new Emitter(translator);
		this.query   = new ASTQuery(translator);
	}
	
	@Override
	public void visit(Node n) {
		/* X10DelegatingVisitor does not handle all node types,
		 * thus we need to dispatch the rest here. */
		if (n instanceof X10ClassDecl_c) {
			visit((X10ClassDecl_c) n);
			return;
		} else if (n instanceof X10SourceFile_c) {
			X10SourceFile_c sf = (X10SourceFile_c) n;
			for(TopLevelDecl top_level_declaration : sf.decls()) {
				visit(top_level_declaration);
			}
			return;
		}
		
		tr.job().compiler().errorQueue().enqueue(ErrorInfo.SEMANTIC_ERROR,
				"Unhandled node type: "+n.getClass(), n.position());
	}

    @Override
	public void visit(TypeDecl_c n) {
    }

    @Override
	public void visit(LocalTypeDef_c n) {
    }

	@Override
	public void visit(X10ClassDecl_c n) {
		X10ClassDef def 			= (X10ClassDef) n.classDef();
		X10FirmTypeSystem_c xts 	= (X10FirmTypeSystem_c) tr.typeSystem();
		boolean isStruct 			= xts.isStructType(def.asType());
		//X10Ext ext 					= (X10Ext) n.ext();
		ClassBody_c body            = (ClassBody_c) n.body();
		
		// TODO: how do we treat native rep classes ?
		assert (!def.isNested()) : ("Nested class alert!");
		
		// decl a new FirmClassType
		if(!isStruct)
			xts.declFirmClass(def);
		else
			xts.declFirmStruct(def); 
		
		// visit the node children (class body)
		List<ClassMember> members 	= body.members();
		
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
	
	// returns the i argument in a native annotation 
	public static String getNativeRepParam(X10ClassDef def, int i) {
		try {
			X10TypeSystem xts = (X10TypeSystem) def.typeSystem();
			Type rep = (Type) xts.systemResolver().find(QName.make("x10.compiler.NativeRep"));
			List<Type> as = def.annotationsMatching(rep);
			for (Type at : as) {
				assertNumberOfInitializers(at, 4);
				String lang = getStringPropertyInit(at, 0);
				if (lang != null && lang.equals(CPP_NATIVE_STRING)) {
					return getStringPropertyInit(at, i);
				}
			}
		}
		catch (SemanticException e) {
			// TODO what now?
		}
		return null;
	}

	void processClass(X10ClassDecl_c n) {
		X10ClassDef def 			= (X10ClassDef) n.classDef();
		X10FirmTypeSystem_c xts 	= (X10FirmTypeSystem_c) tr.typeSystem();
        boolean isStruct 			= xts.isStructType(def.asType());
        //X10Ext ext 					= (X10Ext) n.ext();
        ClassBody_c body            = (ClassBody_c) n.body();
        
        // TODO: how do we treat native rep classes ?
        assert (!def.isNested()) : ("Nested class alert!");
        
        // decl a new FirmClassType
        if(!isStruct)
        	xts.declFirmClass(def);
        else
        	xts.declFirmStruct(def); 
        
        // visit the node children (class body)
		List<ClassMember> members 	= body.members();
		
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
        X10FirmContext_c ctx	 	= (X10FirmContext_c) tr.context();
        X10ClassType currentClass 	= (X10ClassType) ctx.currentClass();
        //X10ClassType superClass 	= (X10ClassType) X10TypeMixin.baseType(currentClass.superClass());
        //X10TypeSystem xts 			= (X10TypeSystem) tr.typeSystem();
        
        if (currentClass.flags().isInterface()) {
        	// TODO
        } else if (currentClass.isX10Struct()) {
        	// TODO
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
    
	@Override
	public void visit(MethodDecl_c dec) {
		X10FirmContext_c context 	= (X10FirmContext_c) tr.context();
		X10FirmTypeSystem_c xts = (X10FirmTypeSystem_c) tr.typeSystem();
		X10Flags flags 			= X10Flags.toX10Flags(dec.flags().flags());
		
		if (flags.isNative()) {
			// TODO Firm must handle this!
			return;
		}
		
		X10MethodDef def 		= (X10MethodDef) dec.methodDef();
		X10MethodInstance mi 	= (X10MethodInstance) def.asInstance();
		X10ClassType container 	= (X10ClassType) mi.container();
		
		current_method = def; // remember globally

		xts.declFirmMethod(def);
		
		String methodName = mi.name().toString();
		
		assert (con == null);
		final int nResults = def.returnType() == null ? 0 : 1;
		final int nParameters = def.typeParameters().size();
		firm.MethodType type = new firm.MethodType(nParameters, nResults);
		firm.Type global = firm.Program.getGlobalType();
		firm.Entity mainEnt = new firm.Entity(global, methodName, type);
		int n_vars = 1;
		firm.Graph graph = new firm.Graph(mainEnt, n_vars);
		con = new firm.Construction(graph);
		
		if ((container.x10Def().typeParameters().size() != 0) && flags.isStatic()) {
			// handle static method decl. 
			assert false; 
			return;
		}

		if (dec.body() != null) {
			if (!flags.isStatic()) {
				// add local vars for closure realisation.
				VarInstance<?> ti = xts.localDef(Position.COMPILER_GENERATED, Flags.FINAL,
						Types.ref(container), Name.make(THIS)).asInstance();
				context.addVariable(ti);
			}
			visitAppropriate(dec.body());
		} else {
			// Define property getter methods.
			if (flags.isProperty() && flags.isAbstract() && mi.formalTypes().size() == 0 && mi.typeParameters().size() == 0) {
				X10FieldInstance fi = (X10FieldInstance) container.fieldNamed(mi.name());
				if (fi != null) {
					String fieldName = fi.name().toString();
				}
			}
		}
		
		firm.Dump.dumpGraph(graph, methodName);
		current_method = null; // un-remember globally
	}

	@Override
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
	    VarInstance<?> ti = ts.localDef(Position.COMPILER_GENERATED, Flags.FINAL,
	                                 Types.ref(container), Name.make(THIS)).asInstance();
	    ctx.addVariable(ti);

	    Block_c body = (Block_c) dec.body();

	    // Synthetic fields must be initialized before everything else
	    for (Stmt s : body.statements()) {
	        if (query.isSyntheticOuterAccessor(s)) {
	        	visitAppropriate(s); 
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
	                for(Expr e : call.arguments() )
	                	visitAppropriate(e);
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

	@Override
	public void visit(FieldDecl_c dec) {
	    X10ClassType declaringClass 	= (X10ClassType)dec.fieldDef().asInstance().container();
	    
	    boolean isStatic = dec.flags().flags().isStatic();
	    
	    if ((((X10ClassDef)declaringClass.def()).typeParameters().size() != 0) && isStatic) {
	    	// static field 
	        return;
	    }

	    // Ignore the initializer -- this will have been done in extractInits/extractStaticInits
	    // FIXME: the above breaks switch constants!
	    if (isStatic) {
	    	visitAppropriate(dec.init());
	    }
	    String container = declaringClass.isX10Struct() ? Emitter.structMethodClass(declaringClass, true, true) : 
	    	Emitter.translateType(dec.fieldDef().asInstance().container());
	}
	
	@Override
	public void visit(PropertyDecl_c n) {
	}

	@Override
	public void visit(Initializer_c n) {
	}
	
    @Override
	public void visit(AssignPropertyBody_c n) {
    }

	@Override
	public void visit(Assert_c n) {
	}

	@Override
	public void visit(Switch_c n) {
		visitAppropriate(n.expr());
	    for(SwitchElement s : n.elements()) {
	    	visitAppropriate(s);
	    }
	}

	@Override
	public void visit(SwitchBlock_c n) {		
		for(Stmt s : n.statements()) {
			visitAppropriate(s);
		}
	}

	@Override
	public void visit(Case_c n) {
		if (n.expr() == null) {
			// default case: 
			
		} else {
			if (n.expr() instanceof Field_c && n.expr().isConstant()) {
				// handle constant case expr. 
			} else {
				visitAppropriate(n.expr());
			}
		}
	}

	@Override
	public void visit(Branch_c br) {
	}
	
	@Override
	public void visit(Labeled_c label) {
	}

	@Override
	public void visit(Assign_c asgn) {
	    boolean unsigned_op 	= false;
	    String opString 		= asgn.operator().toString();
	    NodeFactory nf 			= tr.nodeFactory();
	    X10FirmTypeSystem_c xts = (X10FirmTypeSystem_c) tr.typeSystem();
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
	    if (asgn.operator() != Assign.ASSIGN) {
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

	@Override
	public void visit(Return_c ret) {
		X10FirmContext_c ctx = (X10FirmContext_c) tr.context();
		
		Expr e = ret.expr();
		if (e == null) {
			return;
		} else {			
			X10FirmTypeSystem_c xts = (X10FirmTypeSystem_c) tr.typeSystem();
			FunctionDef container = current_method;
			Type rType = container.returnType().get();
			boolean rhsNeedsCast = !xts.typeDeepBaseEquals(rType, e.type(), ctx);
			
			if (rhsNeedsCast) {
				String toCast = chevrons(Emitter.translateType(rType, true));
			    // Cast is needed to ensure conversion/autoboxing.
			}

			visitAppropriate(e);
		}
	}

	@Override
	public void visit(Formal_c n) {
	}

	@Override
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
	        visitAppropriate(initexpr);
	    }
	}

	@Override
	public void visit(Block_c b) {
		List<Stmt> stmts = b.statements();
		
		for(Stmt s : stmts) {
			visitAppropriate(s);
		}
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
	    Stmt body = n.body();
	    if (!(body instanceof Block_c))
	        body = tr.nodeFactory().Block(body.position(), body);

	    visitAppropriate(body);
	    visitAppropriate(n.cond());
	}

	@Override
	public void visit(While_c n) {
		visitAppropriate(n.cond());
	    Stmt body = n.body();
	    if (!(body instanceof Block_c))
	        body = tr.nodeFactory().Block(body.position(), body);

	    visitAppropriate(body);
	}

	@Override
	public void visit(If_c n) {
		visitAppropriate(n.cond());
		visitAppropriate(n.consequent());
		
		if (n.alternative() != null) {
			// else block 
			Stmt alternative = n.alternative();
			if (alternative instanceof Block_c) {
				Block_c block = (Block_c) alternative;
				if (block.statements().size() == 1 && block.statements().get(0) instanceof If_c)
					alternative = block.statements().get(0);
			}
			visitAppropriate(alternative);
		}
	}

	@Override
	public void visit(Empty_c n) {
	}

	@Override
	public void visit(Eval_c n) {
		visitAppropriate(n.expr());
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
	
	// possible native language annotations -> c++, java, cuda
	private static String JAVA_NATIVE_STRING = "java"; 
    protected String[] getCurrentNativeStrings() { return new String[] {CPP_NATIVE_STRING, JAVA_NATIVE_STRING, CUDA_NATIVE_STRING}; }

    // returns true if the given X10Def has a native annotation 
	private boolean hasNativeImplForDef(X10Def o) {
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
    	                assert(null != getStringPropertyInit(at, 1));
    	                return true;
    	            }
    	        }
            }
	    }
	    catch (SemanticException e) {
	    	// TODO what now?
	    }
	    return false; 
	}
	
	@Override
	public void visit(X10Call_c n) {
		X10FirmContext_c ctx 		= (X10FirmContext_c) tr.context();
		X10FirmTypeSystem_c xts 	= (X10FirmTypeSystem_c) tr.typeSystem();
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
		
		X10Flags flags = X10Flags.toX10Flags(mi.flags());
		// Check for properties accessed using method syntax.  They may have @Native annotations too.
		if (flags.isProperty() && mi.formalTypes().size() == 0 && mi.typeParameters().size() == 0) {
		    X10FieldInstance fi = (X10FieldInstance) md.container().get().fieldNamed(mi.name());
		    if (fi != null) {
		        //assert (X10Flags.toX10Flags(fi.flags()).isProperty()); // FIXME: property fields don't seem to have the property flag set
		        // This is a property getter method.  Translate as a field access.
		    	assert false; 
		    	/*
		        String pat = getCppImplForDef(fi.x10Def());
		        if (pat != null) {
		            Object[] components = new Object[] { target };
		            emitter.dumpRegex("Native", components, tr, pat, sw);
		            return;
		        }
		        */
		    }
		}
		
		X10NodeFactory nf = (X10NodeFactory) tr.nodeFactory();
		List<Expr> args = new ArrayList<Expr>();
		int counter = 0;
		for (Expr a : n.arguments()) {
		    Type fType = mi.formalTypes().get(counter);
		    // HACK: Don't inject cases if the method is defined on x10.lang.Object.
		    //       Compensates for front-end resolving methods invoked on unconstrained type parameters to Object.
		    if (!xts.typeEquals(mi.container(), xts.Object(), ctx) &&
		            !xts.typeEquals(fType, a.type(), ctx) && !(xts.isParameterType(fType) && a.type().isNull())) {
		        a = cast(a, fType);
		    }
		    args.add(a);
		    counter++;
		}

		boolean hasNativeImpl = hasNativeImplForDef(md);	
	}

	@Override
	public void visit(RegionMaker_c n) {
	}

	@Override
	public void visit(ConstantDistMaker_c n) {
	}

	@Override
	public void visit(Field_c n) {
		Receiver target 		= n.target();
		Type t 					= target.type();
		X10TypeSystem xts 		= (X10TypeSystem) t.typeSystem();
		X10FieldInstance fi 	= (X10FieldInstance) n.fieldInstance();
		X10FieldDef fd 			= fi.x10Def();
		
		assert false; 
	}

	@Override
	public void visit(Local_c n) {
		LocalInstance var 		= n.localInstance();
		
		String name = var.name().toString();
	}

	@Override
	public void visit(New_c n) {
	}

	@Override
	public void visit(FloatLit_c n) {
		firm.Mode mode = null;
		
		if (n.kind() == FloatLit.FLOAT)
			mode = X10FirmTypeSystem_c.getFirmMode(X10FirmTypeSystem_c.X10_FLOAT);
		else if (n.kind() == FloatLit.DOUBLE)
			mode = X10FirmTypeSystem_c.getFirmMode(X10FirmTypeSystem_c.X10_DOUBLE);
		else
			throw new InternalCompilerError("Unrecognized FloatLit kind " + n.kind());
		
		con.newConst(TargetValue.newFromDouble(n.value(), mode)); 
	}

	@Override
	public void visit(IntLit_c n) {
	    firm.Mode mode = null; 
	    if (n.kind() == X10IntLit_c.ULONG) {
	    	mode = X10FirmTypeSystem_c.getFirmMode(X10FirmTypeSystem_c.X10_ULONG);
	    } else if (n.kind() == X10IntLit_c.UINT) {
	    	mode = X10FirmTypeSystem_c.getFirmMode(X10FirmTypeSystem_c.X10_UINT);
	    } else if (n.kind() == IntLit.LONG) {
	    	mode = X10FirmTypeSystem_c.getFirmMode(X10FirmTypeSystem_c.X10_LONG);
	    } else if (n.kind() == IntLit.INT) {
	    	mode = X10FirmTypeSystem_c.getFirmMode(X10FirmTypeSystem_c.X10_INT);
	    } else {
	        throw new InternalCompilerError("Unrecognized IntLit kind " + n.kind());
	    }
	    
	    con.newConst(new TargetValue(n.value(), mode));
	}

	@Override
	public void visit(NullLit_c n) {
	}

	@Override
	public void visit(StringLit_c n) {
		X10FirmTypeSystem_c xts = (X10FirmTypeSystem_c) tr.typeSystem();
        String str              = n.stringValue();
	}

	@Override
	public void visit(CharLit_c lit) {
		char val 			 = lit.charValue(); 
	}

	@Override
	public void visit(BooleanLit_c lit) {
		int val = (lit.value() ? 1 : 0);
		
		con.newConst(val, X10FirmTypeSystem_c.getFirmMode(X10FirmTypeSystem_c.X10_BOOLEAN));
	}

	@Override
	public void visit(Id_c n) {
		String name          = n.id().toString();
	}

	@Override
	public void visit(X10Cast_c c) {
	}

	@Override
	public void visit(SubtypeTest_c n) {
	}

	@Override
	public void visit(X10Instanceof_c n) {
	}

	@Override
	public void visit(Throw_c n) {
	}

	@Override
	public void visit(Try_c n) {
	}

	@Override
	public void visit(Catch_c n) {
	}

	@Override
	public void visit(Atomic_c a) {
	}

	@Override
	public void visit(Await_c n) {
	}

	@Override
	public void visit(Next_c n) {
	}

	@Override
	public void visit(ForLoop_c n) {
	}
	
    @Override
	public void visit(ForEach_c n) {
    }

    @Override
	public void visit(AtEach_c n) {
    }

    @Override
	public void visit(Finish_c n) {
    }

    @Override
	public void visit(ArrayAccess_c n) {
    }

    @Override
	public void visit(ParExpr_c n) {
    }

    @Override
	public void visit(Conditional_c n) {    
        n.printSubExpr(n.cond(), false, sw, tr);
        String type = Emitter.translateType(n.type(), true);
        
        n.printSubExpr(n.consequent(),  true, sw, tr);
        n.printSubExpr(n.alternative(), true, sw, tr);
    }

    @Override
	public void visit(Here_c n) {
		
    }

    @Override
	public void visit(Async_c n) {
		
    }

    @Override
	public void visit(X10Special_c n) {
		
    }

    @Override
	public void visit(Closure_c n) {
		
    }
    
	@Override
	public void visit(ClosureCall_c c) {
		
	}

	@Override
	public void visit(X10CanonicalTypeNode_c n) {
		
	}

	@Override
	public void visit(X10Unary_c n) {
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

	@Override
	public void visit(Unary_c n) {
		Unary_c.Operator operator 	= n.operator();
		Expr expr 					= n.expr();
		
		if (operator == Unary.NEG && expr instanceof IntLit) {
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

	@Override
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

	@Override
	public void visit(Binary_c n) {
		X10FirmTypeSystem_c xts = (X10FirmTypeSystem_c) tr.typeSystem();
		String opString 		= n.operator().toString();
		
		// Boolean short-circuiting operators are ok
		assert (opString.equals("&&") || opString.equals("||"))
		    : "visiting "+n.getClass()+" at "+n.position()+": "+n;

		n.printSubExpr(n.left(),  true, sw, tr);
		n.printSubExpr(n.right(), false, sw, tr);
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
