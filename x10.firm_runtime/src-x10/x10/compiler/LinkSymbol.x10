package x10.compiler;

import x10.lang.annotations.MethodAnnotation;

/**
 * This annotation is used to explicit declare symbol names instead of relying
 * on the name mangleing of the compiler. Must be used on native methods,
 * to link them with some C procedures.
 */
public interface LinkSymbol(name:String) extends MethodAnnotation {
}
