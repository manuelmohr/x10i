package x10firm.visit;

import polyglot.ast.Node;
import polyglot.ast.TypeNode;
import polyglot.frontend.Job;
import polyglot.types.ContainerType;
import polyglot.types.MemberDef;
import polyglot.types.Ref;
import polyglot.types.Type;
import polyglot.types.Types;
import polyglot.util.Position;
import polyglot.visit.NodeVisitor;
import x10.ast.X10Call;
import x10.ast.X10ClassDecl;
import x10.ast.X10MethodDecl;
import x10.ast.X10SourceFile_c;
import x10.types.X10ClassDef;
import x10.types.X10ClassType;
import x10.types.X10MethodDef;

/**
 * Finds the declaration, i.e. the ClassDecl node, for a given class.
 * Stolen from Inliner.java and further adapted. Let's hope the X10 guys
 * refactor this and put it into a separate class soon.
 *
 * TODO: cache the results
 */
public class DeclFetcher {

	/**
	 * Get the definition of the X10 Class that implements a given constructor.
	 *
	 * @param candidate the constructor definition whose container is desired
	 * @return the definition of the X10 Class containing the constructor
	 */
	private static X10ClassDef getContainer(final MemberDef candidate) {
		final Ref<? extends ContainerType> containerRef = candidate.container();
		final ContainerType containerType = Types.get(containerRef);
		final Type containerBase = Types.baseType(containerType);
		assert containerBase instanceof X10ClassType;
		final X10ClassDef container = ((X10ClassType) containerBase).x10Def();
		return container;
	}

	private static Job getJob(final X10ClassDef container) {
		final Job job = container.job();
		if (job == null)
			return null;
		if (!job.extensionInfo().scheduler().shouldCompile(job))
			return null;

		Node ast = job.ast();
		if (ast == null) {
			System.err.println("Unable to reconstruct AST for " + job);
			return null;
		}

		assert ast instanceof X10SourceFile_c;
		assert ((X10SourceFile_c) ast).hasBeenTypeChecked();
		return job;
	}

	/**
	 * Walk an AST looking for the declaration of a given constructor.
	 *
	 * @param candidate
	 *            the cons whose declaration is desired
	 * @param ast
	 *            the abstract syntax tree containing the declaration
	 * @return the declaration for the indicated method, or null if no
	 *         declaration can be found or it has an empty body.
	 */
	private static X10ClassDecl getClassDeclaration(final X10ClassDef candidate, final Node ast) {
		final Position pos = candidate.position();
		final X10ClassDecl[] decl = new X10ClassDecl[1];

		ast.visit(new NodeVisitor() {
			private boolean contains(final Position outer, final Position inner) {
				if (!outer.file().equals(inner.file()))
					return false;
				if (!outer.path().equals(inner.path()))
					return false;
				return (outer.offset() <= inner.offset() && inner.endOffset() <= inner.endOffset());
			}

			@Override
			public polyglot.ast.Node override(final polyglot.ast.Node n) {
				if (null != decl[0])
					return n; // we've already found the decl, short-circuit search
				if (n instanceof TypeNode)
					return n; // TypeNodes don't contain decls, short-circuit search
				if (!pos.isCompilerGenerated() && !contains(n.position(), pos))
					return n; // definition of md isn't inside n, short-circuit search
				if (n instanceof X10ClassDecl
						&& candidate == ((X10ClassDecl) n).classDef()) {
					decl[0] = (X10ClassDecl) n;
					return n; // we found the decl for the candidate, short-circuit search
				}
				return null; // look for the decl inside n
			}
		});

		if (null == decl[0]) {
			System.err.println("declaration not found for " + candidate);
			return null;
		}

		if (null == decl[0].body()) {
			System.err.println("no declaration body for " + decl[0] + " (" + candidate + ")");
			return null;
		}

		return decl[0];
	}

	/**
	 * Walk an AST looking for the declaration of a given method.
	 *
	 * @param candidate
	 *            the method whose declaration is desired
	 * @param ast
	 *            the abstract syntax tree containing the declaration
	 * @return the declaration for the indicated method, or null if no
	 *         declaration can be found or it has an empty body.
	 */
	private static X10MethodDecl getMethodDeclaration(final X10MethodDef candidate, final Node ast) {
		final Position pos = candidate.position();
		final X10MethodDecl[] decl = new X10MethodDecl[1];

		ast.visit(new NodeVisitor() {
			private boolean contains(final Position outer, final Position inner) {
				if (!outer.file().equals(inner.file()))
					return false;
				if (!outer.path().equals(inner.path()))
					return false;
				return (outer.offset() <= inner.offset() && inner.endOffset() <= inner.endOffset());
			}

			@Override
			public polyglot.ast.Node override(final polyglot.ast.Node n) {
				if (null != decl[0])
					return n; // we've already found the decl, short-circuit search
				if (n instanceof TypeNode)
					return n; // TypeNodes don't contain decls, short-circuit search
				if (!pos.isCompilerGenerated() && !contains(n.position(), pos))
					return n; // definition of md isn't inside n, short-circuit search
				if (n instanceof X10MethodDecl
						&& candidate == ((X10MethodDecl) n).methodDef()) {
					decl[0] = (X10MethodDecl) n;
					return n; // we found the decl for the candidate, short-circuit search
				}
				return null; // look for the decl inside n
			}
		});

		if (null == decl[0]) {
			System.err.println("declaration not found for " + candidate);
			return null;
		}

		if (!decl[0].flags().flags().isNative() && null == decl[0].body()) {
			System.err.println("no declaration body for " + decl[0] + " (" + candidate + ")");
			return null;
		}

		return decl[0];
	}

	private static Node getAST(final X10ClassDef container) {
		if (null == container) {
			System.err.println("unable to find container for candidate: " + container);
			return null;
		}

		final Job candidateJob = getJob(container);
		if (null == candidateJob) {
			System.err.println("unable to find job for candidate: " + container);
			return null;
		}

		Node ast = candidateJob.ast();
		if (null == ast) {
			System.err.println("unable to find ast for candidated: " + container);
			return null;
		}
		return ast;
	}


	/**
	 * Get the declaration corresponding to a call.
	 *
	 * @return The declaration of the method invoked by call, or null if the
	 *         declaration cannot be found.
	 */
	public static X10ClassDecl getDecl(final X10ClassType n) {
		final X10ClassDef candidate = n.def();
		final Node ast = getAST(candidate);
		if (ast == null)
			return null;

		final X10ClassDecl decl = getClassDeclaration(candidate, ast);
		if (null == decl) {
			System.err.println("unable to find declaration for candidate: " + n);
			return null;
		}

		return decl;
	}

	/**
	 * Get the declaration corresponding to a call.
	 *
	 * @param call
	 *            The call to the method we need the declaration for.
	 * @return The declaration of the method invoked by call, or null if the
	 *         declaration cannot be found.
	 */
	public static X10MethodDecl getDecl(final X10Call call) {
		// get candidate
		final X10MethodDef candidate = call.methodInstance().x10Def();
		final X10ClassDef container = getContainer(candidate);
		final Node ast = getAST(container);
		if (ast == null)
			return null;

		final X10MethodDecl decl = getMethodDeclaration(candidate, ast);
		if (null == decl) {
			System.err.println("unable to find declaration for candidate: "
					+ candidate);
			return null;
		}

		return decl;
	}
}
