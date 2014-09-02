package x10.compiler;

import x10.lang.annotations.ExpressionAnnotation;
import x10.lang.annotations.ClassAnnotation;

/** An annotation that requests the compiler to allocate an object in the
 * tile-local memory.
 * Can be used on individual allocations:
 *   val v = @TLMAllocate new T(...);
 * Or on classes, so all objects will be TLM-allocated by default:
 *   @TLMAllocate class Foobar { ... }
 */
public interface TLMAllocate extends ExpressionAnnotation, ClassAnnotation { }
