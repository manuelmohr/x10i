package x10.compiler;

import x10.lang.annotations.ClassAnnotation;

/**
 * If an object is annotated with OpaqueHandle then it is assumed to represent
 * an opaque pointer to some native structure. This is intended to be used to
 * efficiently provide access to C APIs.
 * If such types have constructors fields or non-final methods, then the
 * behavior is undefined.
 */
public interface OpaqueHandle extends ClassAnnotation {
}
