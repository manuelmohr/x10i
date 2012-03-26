package x10firm.visit;

import java.util.LinkedList;
import java.util.List;

import polyglot.ast.Binary;
import polyglot.ast.BooleanLit;
import polyglot.ast.Cast;
import polyglot.ast.ClassMember;
import polyglot.ast.Conditional;
import polyglot.ast.Expr;
import polyglot.ast.FieldDecl;
import polyglot.ast.FieldDecl_c;
import polyglot.ast.FloatLit;
import polyglot.ast.Initializer_c;
import polyglot.ast.IntLit;
import polyglot.ast.Return;
import polyglot.ast.Stmt;
import polyglot.ast.Unary;
import polyglot.types.QName;
import polyglot.types.SemanticException;
import polyglot.types.Type;
import polyglot.types.TypeSystem;
import x10.ast.Closure;
import x10.ast.ClosureCall;
import x10.ast.ParExpr;
import x10.types.X10ClassType;
import x10.types.X10Def;
import x10.types.X10FieldDef;
import x10.types.X10MethodDef;
import x10.util.HierarchyUtils;

/**
 * Our main class for AST queries.
 */
public class ASTQuery {

	private final TypeSystem x10TypeSystem;

	/**
	 * X10ASTQuery Constructor.
	 * @param x10TypeSystem The x10 type system
	 */
	public ASTQuery(final TypeSystem x10TypeSystem) {
		this.x10TypeSystem = x10TypeSystem;
	}

	/**
	 * Returns true if a given expression is constant.
	 * @param e The expression which should be checked
	 * @return True if the given expression is constant
	 */
	public boolean isConstantExpression(final Expr e) {
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
	    return false;
	}

	/**
	 * Checks if a given field name is a synthetic field.
	 *
	 * @param name The field name which should be checked
	 * @return True if the given field name is actually a synthetic field
	 */
	private static boolean isSyntheticField(final String name) {
		return name.startsWith("jlc$");
	}

	/**
	 * Checks if a given field decl is global init (static and the init
	 * expression must be constant).
	 *
	 * @param fd
	 *            The field decl which should be checked
	 * @return True if the given field decl is a global init field decl.
	 */
	public boolean isGlobalInit(final FieldDecl fd) {
		return (fd.init() != null && fd.flags().flags().isStatic()
				&& fd.flags().flags().isFinal()
				&& isConstantExpression(fd.init()) && (fd.init().type().isNumeric()
				|| fd.init().type().isBoolean() || fd.init().type().isChar() || fd.init().type().isNull()))
				|| isPerProcess((X10FieldDef) fd.fieldDef());
	}

	/**
	 * Extracts all class members from a given class members list which must be manually initialized
	 * (val instanced fields).
	 * @param members A list with class members
	 * @return The class members from the given list which must be manually initialized
	 */
	public List<ClassMember> extractInits(final List<ClassMember> members) {
		final List<ClassMember> ret = new LinkedList<ClassMember>();

	    for (final ClassMember member : members) {
	        if (member.memberDef().flags().isStatic())
	            continue;
	        if (!(member instanceof Initializer_c) && !(member instanceof FieldDecl_c))
	            continue;
	        if (member instanceof FieldDecl_c && (((FieldDecl_c)member).init() == null
	            || isSyntheticField(((FieldDecl_c)member).name().id().toString())))
	            continue;
	        if (member instanceof FieldDecl_c) {
	            final FieldDecl_c dec = (FieldDecl_c) member;
	            if (dec.flags().flags().isStatic()) {
	                final X10ClassType container = (X10ClassType)dec.fieldDef().asInstance().container();
	                if ((container.def()).typeParameters().size() != 0)
	                    continue;
	                if (isGlobalInit(dec))
	                    continue;
	            }
	        }

	        // This class members must be initialised
	        ret.add(member);
	    }

	    return ret;
	}

	/** returns true if definition has @PerProcess annotation. */
	public boolean isPerProcess(final X10Def def) {
		try {
			final Type type = x10TypeSystem.systemResolver().findOne(QName.make("x10.compiler.PerProcess"));
			return !def.annotationsMatching(type).isEmpty();
		} catch (SemanticException e) {
			return false;
		}
	}

	/**
	 * test if a method is the main method (the one we start first when the
	 * program runs). Note: This code is copied from the ASTQuery class. (It
	 * doesn't have the public modifier there so we can't use it directly. Also
	 * ASTQuery unnecessarily depends on a Translator which we don't have)
	 */
	public boolean isMainMethod(final X10MethodDef md) {
		return HierarchyUtils.isMainMethod(md, x10TypeSystem.emptyContext());
	}
}
