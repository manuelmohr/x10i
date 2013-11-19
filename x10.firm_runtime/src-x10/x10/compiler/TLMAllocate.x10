package x10.compiler;

import x10.lang.annotations.ExpressionAnnotation;
import x10.lang.annotations.StatementAnnotation;

/** An annotation that requests the compiler to allocate an object in the
 * tile-local memory.
 * Must be used *exactly* as the following for now:
 *   val v = @TLMAllocate new T(...);
 */
public interface TLMAllocate extends ExpressionAnnotation { }
