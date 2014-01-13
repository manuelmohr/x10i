package x10.compiler;

import x10.lang.annotations.ExpressionAnnotation;
import x10.lang.annotations.StatementAnnotation;

/** An annotation that requests the compiler to place an object in the
 * data segment memory. Executing this statement twice overwrites the first
 * object. So, only use this for static fields or code which guaranteed
 * to only be executed once.
 *
 * Must be used *exactly* as the following for now:
 *   val v = @TLMAllocate new T(...);
 */
public interface StaticAllocate extends ExpressionAnnotation { }
