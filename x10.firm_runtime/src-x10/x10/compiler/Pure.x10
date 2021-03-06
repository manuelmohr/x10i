/*
 *  This file is part of the X10 project (http://x10-lang.org).
 *
 *  This file is licensed to You under the Eclipse Public License (EPL);
 *  You may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *      http://www.opensource.org/licenses/eclipse-1.0.php
 *
 *  (C) Copyright IBM Corporation 2006-2010.
 */

package x10.compiler;

import x10.lang.annotations.ExpressionAnnotation;
import x10.lang.annotations.MethodAnnotation;

/**
 * This annotation is used to allow the programmer
 * to permit the compiler to delete this expression
 * or call to this method if its result is not used.</p>
 *
 * This annotation is processed by the X10 compiler's
 * common optimizer.
 */
public interface Pure extends MethodAnnotation, ExpressionAnnotation { }
