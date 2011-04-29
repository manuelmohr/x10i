package x10firm.visit;

import polyglot.ast.TypeNode;
import polyglot.frontend.Job;
import polyglot.types.ContainerType;
import polyglot.types.Ref;
import polyglot.types.SemanticException;
import polyglot.types.Type;
import polyglot.types.Types;
import polyglot.util.Position;
import polyglot.visit.NodeVisitor;
import x10.ast.X10Call;
import x10.ast.X10MethodDecl;
import x10.ast.X10NodeFactory_c;
import x10.ast.X10SourceFile_c;
import x10.errors.Errors;
import x10.optimizations.ForLoopOptimizer;
import x10.types.X10ClassDef;
import x10.types.X10ClassType;
import x10.types.X10MethodDef;
import x10.visit.Desugarer;
import x10.visit.X10TypeChecker;
import x10firm.types.TypeSystem;

/**
 * Stolen from Inliner.java. Let's hope the X10 guys refactor this and put it
 * into a separate class soon.
 */
public class MethodDeclFetcher {
	private final TypeSystem typeSystem;
	private final X10NodeFactory_c xnf;

	/**
	 * @param typeSystem Our FIRM type system.
	 * @param xnf The node factory.
	 */
	public MethodDeclFetcher(TypeSystem typeSystem, X10NodeFactory_c xnf) {
		this.typeSystem = typeSystem;
		this.xnf = xnf;
	}

	/**
	 * Get the definition of the X10 Class that implements a given method.
	 * 
	 * @param candidate the method definition whose container is desired
	 * @return the definition of the X10 Class containing md
	 */
	private X10ClassDef getContainer(X10MethodDef candidate) {
		Ref<? extends ContainerType> containerRef = candidate.container();
		ContainerType containerType = Types.get(containerRef);
		Type containerBase = Types.baseType(containerType);
		assert (containerBase instanceof X10ClassType);
		X10ClassDef container = ((X10ClassType) containerBase).x10Def();
		return container;
	}

	/**
	 * Obtain the job for containing the declaration for a given method. Run the
	 * preliminary compilation phases on the job's AST.
	 * 
	 * Note Errors during speculative compilation should not be fatal. The
	 * mechanism implementing this behavior consists of a pair of hacks that
	 * should be fixed.
	 * 
	 * @param candidate
	 * @param container
	 * @return
	 */
	private Job getJob(X10MethodDef candidate, X10ClassDef container) {
		Job job = container.job();
		try {
			/*
			 * TODO: reconstruct job from position if (null == job) { String
			 * file = pos.file(); String path = pos.path(); Source source = new
			 * Source(file, path, null); job =
			 * xts.extensionInfo().scheduler().addJob(source); }
			 */
			if (null == job) {
				System.err.println("Unable to find or create job for method: "
						+ candidate);
				return null;
			}

			polyglot.ast.Node ast = null;

			// TODO reconstruct the AST for the job will all preliminary
			// compiler passes
			ast = job.ast();
			assert (ast instanceof X10SourceFile_c);
			if (!((X10SourceFile_c) ast).hasBeenTypeChecked())
				ast = ast.visit(new X10TypeChecker(job, typeSystem, xnf, job.nodeMemo()).begin());
			if (null == ast) {
				System.err.println("Unable to reconstruct AST for " + job);
				return null;
			}
			job.ast(ast); // ASK: why does this work?

		} catch (Exception x) {
			String msg = "AST for job, " + job + " (for candidate " + candidate
					+ ") does not typecheck (" + x + ")";
			System.err.println(msg);
			SemanticException e = new SemanticException(msg, candidate.position());
			Errors.issue(job, e);
			return null;
		}
		return job;
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
	public X10MethodDecl getDeclaration(final X10MethodDef candidate,
			final polyglot.ast.Node ast) {
		final Position pos = candidate.position();
		final X10MethodDecl[] decl = new X10MethodDecl[1];

		ast.visit(new NodeVisitor() {
			private boolean contains(Position outer, Position inner) {
				if (!outer.file().equals(inner.file()))
					return false;
				if (!outer.path().equals(inner.path()))
					return false;
				return (outer.offset() <= inner.offset() && inner.endOffset() <= inner.endOffset());
			}

			@Override
			public polyglot.ast.Node override(polyglot.ast.Node n) {
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

		if (null == decl[0].body()) {
			System.err.println("no declaration body for " + decl[0] + " (" + candidate + ")");
			return null;
		}

		return decl[0];
	}

	/**
	 * Get the declaration corresponding to a call.
	 * TODO
	 * TODO: Add caching.
	 * TODO
	 * 
	 * @param call
	 *            The call to the method we need the declaration for.
	 * @return The declaration of the method invoked by call, or null if the
	 *         declaration cannot be found.
	 */
	public X10MethodDecl getDecl(X10Call call) {
		// get candidate
		X10MethodDef candidate = call.methodInstance().x10Def();

		// get container and declaration for candidate
		X10ClassDef container = getContainer(candidate);
		if (null == container) {
			System.err.println("unable to find container for candidate: "
					+ candidate);
			return null;
		}

		Job candidateJob = getJob(candidate, container);
		if (null == candidateJob) {
			System.err.println("unable to find job for candidate: " + candidate);
			return null;
		}

		polyglot.ast.Node ast = candidateJob.ast();
		if (null == ast) {
			System.err.println("unable to find ast for candidated: "
					+ candidate);
			return null;
		}

		ast = ast.visit(new Desugarer(candidateJob, typeSystem, xnf).begin());
		ast = ast.visit(new ForLoopOptimizer(candidateJob, typeSystem, xnf).begin());
		X10MethodDecl decl = getDeclaration(candidate, ast);
		if (null == decl) {
			System.err.println("unable to find declaration for candidate: "
					+ candidate);
			return null;
		}

		return decl;
	}
}
