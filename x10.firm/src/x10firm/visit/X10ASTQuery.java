package x10firm.visit;

import java.util.LinkedList;
import java.util.List;

import polyglot.ast.Binary;
import polyglot.ast.BooleanLit;
import polyglot.ast.Cast;
import polyglot.ast.ClassMember;
import polyglot.ast.Conditional;
import polyglot.ast.Expr;
import polyglot.ast.FieldDecl_c;
import polyglot.ast.FloatLit;
import polyglot.ast.Initializer_c;
import polyglot.ast.IntLit;
import polyglot.ast.MethodDecl;
import polyglot.ast.Return;
import polyglot.ast.Stmt;
import polyglot.ast.Unary;
import polyglot.types.Context;
import polyglot.util.ErrorInfo;
import x10.ast.Closure;
import x10.ast.ClosureCall;
import x10.ast.ParExpr;
import x10.types.X10ClassDef;
import x10.types.X10ClassType;
import x10cpp.Configuration;
import x10firm.types.TypeSystem;

/**
 * Our main class for AST queries. 
 */
public class X10ASTQuery {

	/** Reference to the type system */
	private final TypeSystem typeSystem;
	
	/** Reference to the main polyglot compiler */
	private final polyglot.frontend.Compiler compiler;
	
	/**
	 * X10ASTQuery Constructor
	 * @param typeSystem_ Reference to the type system
	 * @param compiler_ Reference to the main polyglot compiler 
	 */
	public X10ASTQuery(TypeSystem typeSystem_, polyglot.frontend.Compiler compiler_) {
		this.typeSystem = typeSystem_;
		this.compiler   = compiler_;
	}
	
	/**
	 * Returns true if a given expression is constant
	 * @param e The expression which should be checked
	 * @return True if the given expression is constant
	 */
	public boolean isConstantExpression(Expr e) {
	    if (!e.isConstant())
	        return false;
	    if (e instanceof BooleanLit)
	        return true;
	    if (e instanceof IntLit)
	        return true;
	    if (e instanceof FloatLit)
	        return true;
	    if (e instanceof Cast)
	        return isConstantExpression(((Cast) e).expr());
	    if (e instanceof ParExpr)
	        return isConstantExpression(((ParExpr) e).expr());
	    if (e instanceof Unary)
	        return isConstantExpression(((Unary) e).expr());
	    if (e instanceof Binary)
	        return isConstantExpression(((Binary) e).left()) &&
	               isConstantExpression(((Binary) e).right());
	    if (e instanceof Conditional)
	        return isConstantExpression(((Conditional) e).cond()) &&
	               isConstantExpression(((Conditional) e).consequent()) &&
	               isConstantExpression(((Conditional) e).alternative());
	    if (e instanceof Closure) {
	        Closure c = (Closure) e;
	        List<Stmt> ss = c.body().statements();
            if (ss.size() != 1)
	            return false;
	        if (!(ss.get(0) instanceof Return))
	            return false;
	        return isConstantExpression(((Return) ss.get(0)).expr());
	    }
	    if (e instanceof ClosureCall) {
	        ClosureCall cc = (ClosureCall) e;
	        List<Expr> as = ((ClosureCall) e).arguments();
	        for (Expr a : as) {
	            if (!isConstantExpression(a))
	                return false;
            }
	        return isConstantExpression(cc.target());
	    }
	    return false;
	}
	
	/**
	 * Checks if a given field name is a synthetic field
	 * @param name The field name which should be checked
	 * @return True if the given field name is actually a synthetic field
	 */
    private boolean isSyntheticField(String name) {
		if (name.startsWith("jlc$")) return true;
		return false;
	}
    
    /**
     * Checks if a given field decl is global init (static and the init expression must be constant)
     * @param fd The field decl which should be checked
     * @return True if the given field decl is a global init field decl. 
     */
	private boolean isGlobalInit(FieldDecl_c fd) {
	    return (fd.init() != null &&
	            fd.flags().flags().isStatic() && fd.flags().flags().isFinal() &&
	            isConstantExpression(fd.init()) &&
	            (fd.init().type().isNumeric() || fd.init().type().isBoolean() ||
	             fd.init().type().isChar() || fd.init().type().isNull()));
	}
	
	/**
	 * Extracts all class members from a given class members list which must be manually initialized (val instanced fields) 
	 * @param members A list with class members
 	 * @return The class members from the given list which must be manually initialized
	 */
	public List<ClassMember> extractInits(List<ClassMember> members)
	{
		final List<ClassMember> ret = new LinkedList<ClassMember>();

	    for(ClassMember member : members) {
	        if(member.memberDef().flags().isStatic())
	            continue;
	        if(!(member instanceof Initializer_c) && !(member instanceof FieldDecl_c))
	            continue;
	        if(member instanceof FieldDecl_c && (((FieldDecl_c)member).init() == null ||
	            isSyntheticField(((FieldDecl_c)member).name().id().toString())))
	            continue;
	        if (member instanceof FieldDecl_c) {
	            FieldDecl_c dec = (FieldDecl_c) member;
	            if(dec.flags().flags().isStatic()) {
	                X10ClassType container = (X10ClassType)dec.fieldDef().asInstance().container();
	                if(((X10ClassDef)container.def()).typeParameters().size() != 0)
	                    continue;
	                if(isGlobalInit(dec))
	                    continue;
	            }
	        }
	        
	        // This class members must be initialised
	        ret.add(member);
	    }
	    
	    return ret;
	}
	
    private boolean seenMain = false;
    private boolean warnedAboutMain = false;
    /** test if a method is the main method (the one we start first when the
     * program runs)
     * Note: This code is copied from the ASTQuery class. (It doesn't have the
     * public modifier there so we can't use it directly. Also ASTQuery
     * unnecessarily depends on a Translator which we don't have)
     */
	public boolean isMainMethod(MethodDecl dec) {
		X10ClassType container = (X10ClassType) dec.methodDef().asInstance()
				.container();
		Context context = null;
		assert (container.isClass());
		boolean result = (Configuration.MAIN_CLASS == null || container
				.fullName().toString().equals(Configuration.MAIN_CLASS))
				&& dec.name().toString().equals("main")
				&& dec.flags().flags().isPublic()
				&& dec.flags().flags().isStatic()
				&& dec.returnType().type().isVoid()
				&& (dec.formals().size() == 1)
				&& typeSystem.isSubtype(dec.formals().get(0).type()
						.type(), typeSystem.Array(typeSystem.String()), context);
		if (result) {
			boolean dash_c = compiler.sourceExtension().getOptions().post_compiler == null;
			if (seenMain && !warnedAboutMain && !dash_c
					&& Configuration.MAIN_CLASS == null) {
				compiler.errorQueue().enqueue(
						ErrorInfo.SEMANTIC_ERROR,
						"Multiple main() methods encountered.  "
								+ "Please specify MAIN_CLASS.");
				warnedAboutMain = true;
			}
			seenMain = true;
		}
		return result;
	}
}
