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

package x10.lang;

import x10.compiler.Pragma;
import x10.compiler.NativeClass;
import x10.compiler.TLMAllocate;
import x10.util.concurrent.AtomicInteger;
import x10.util.GrowableIndexedMemoryChunk;

/**
 * The primary operation on a PlaceLocalHandle is to use it to access an object
 * on the current place.  If the current place is not part of the distribution
 * over which the PlaceLocalHandle is defined, a BadPlaceException will be thrown.</p>
 *
 * A key concept for correct usage of PlaceLocalHandles is that in different places,
 * the Handle may be mapped to distinct objects.  For example (assuming >1 Place):
 * <pre>
 *   val plh:PlaceLocalHandle[T] = ....;
 *   val obj:T = plh();
 *   at (here.next()) Console.out.println(plh() == obj);
 * </pre>
 * may print either true or false depending on how the application is
 * using the particular PlaceLocalHandle (mapping the same object at
 * multiple places or mapping distinct object at each place).</p>
 */
@NativeClass("c++", "x10.lang", "PlaceLocalHandle_Impl")
@NativeClass("java", "x10.runtime.impl.java", "PlaceLocalHandle")
public final struct PlaceLocalHandle[T]{T isref, T <: Any} {

    /* @only at first place... */
    private static val nextPlaceLocalId = @TLMAllocate new AtomicInteger(0);

    private static val datas = new GrowableIndexedMemoryChunk[Pointer]();

    val id: Int;

    private def this(): PlaceLocalHandle[T] {
        id = at (Place.FIRST_PLACE) nextPlaceLocalId.getAndIncrement();
    }

    /**
     * @return the object mapped to the handle at the current place
     */
    public operator this():T {
        atomic {
            return datas(id).castTo[T]();
        }
    }

    // Only to be used by make method and Runtime class
    def set(newVal:T):void {
        atomic {
            val length = datas.length();
            if (id >= datas.length()) {
                datas.grow(id);
                do {
                    datas.add(Pointer.NULL);
                } while (id >= datas.length());
            }
            datas(id) = newVal as Pointer;
        }
    }

    public def hashCode():Int = id.hashCode();

    public def toString():String = "PlaceLocalHandle(" + id + ")";

    /**
     * Create a distributed object with local state of type T
     * at each place in the argument distribution.  The local object will be initialized
     * by evaluating init at each place.  When this method returns, the local objects
     * will be initialized and available via the returned PlaceLocalHandle instance
     * at every place in the distribution.
     *
     * @param dist a distribution specifiying the places where local objects should be created.
     * @param init the initialization closure used to create the local object.
     * @return a PlaceLocalHandle that can be used to access the local objects.
     */
    public static def make[T](dist:Dist, init:()=>T){T isref}:PlaceLocalHandle[T] {
        return make(dist.places(), init);
    }

    /**
     * Create a distributed object with local state of type T
     * at each place in the argument distribution.  For each place in the
     * argument distribution, the local_init closure will be evaluated to
     * yield a value of type U.  This value will then be serialized to the
     * target place and passed as an argument to the init closure.
     * When this method returns, the local objects will be initialized and available
     * via the returned PlaceLocalHandle instance at every place in the distribution.
     *
     * @param dist a distribution specifiying the places where local objects should be created.
     * @param init_here a closure to compute the local portion of the initialization (evaluated in the current place)
     * @param init_there a closure to be evaluated in each place to create the local objects.
     * @return a PlaceLocalHandle that can be used to access the local objects.
     */
    public static def make[T,U](dist:Dist, init_here:(Place)=>U, init_there:(U)=>T){T isref}:PlaceLocalHandle[T] {
        return make(dist.places(), init_here, init_there);
    }

    /**
     * Create a distributed object with local state of type T
     * at each place in the argument PlaceGroup.  The local object will be initialized
     * by evaluating init at each place.  When this method returns, the local objects
     * will be initialized and available via the returned PlaceLocalHandle instance
     * at every place in the PlaceGroup.
     *
     * @param pg a PlaceGroup specifiying the places where local objects should be created.
     * @param init the initialization closure used to create the local object.
     * @return a PlaceLocalHandle that can be used to access the local objects.
     */
    public static def make[T](pg:PlaceGroup, init:()=>T){T isref}:PlaceLocalHandle[T] {
        val handle = new PlaceLocalHandle[T]();
        finish for (p in pg) {
            at (p) async handle.set(init());
        }
        return handle;
    }

    /**
     * Create a distributed object with local state of type T
     * at each place in the argument PlaceGroup.  For each place in the
     * argument PlaceGroup, the local_init closure will be evaluated in the
     * current place to yield a value of type U.  This value will then be serialized
     * to the target place and passed as an argument to the init closure.
     * When this method returns, the local objects will be initialized and available
     * via the returned PlaceLocalHandle instance at every place in the distribution.
     *
     * @param dist a distribution specifiying the places where local objects should be created.
     * @param init_here a closure to compute the local portion of the initialization (evaluated in the current place)
     * @param init_there a closure to be evaluated in each place to create the local objects.
     * @return a PlaceLocalHandle that can be used to access the local objects.
     */
    public static def make[T,U](pg:PlaceGroup, init_here:(Place)=>U, init_there:(U)=>T){T isref}:PlaceLocalHandle[T] {
        val handle = at(Place.FIRST_PLACE) PlaceLocalHandle[T]();
        finish for (p in pg) {
            val v:U = init_here(p);
            at (p) async handle.set(init_there(v));
        }
        return handle;
    }

    /*
     * Same API, but replicated for flat asyncs (optimized finish implementation
     */

    /**
     * Create a distributed object with local state of type T
     * at each place in the argument distribution.  The local object will be initialized
     * by evaluating init at each place.  When this method returns, the local objects
     * will be initialized and available via the returned PlaceLocalHandle instance
     * at every place in the distribution.
     *
     * Requires an initialization closure that does not change place asynchronously.
     *
     * @param dist a distribution specifiying the places where local objects should be created.
     * @param init the initialization closure used to create the local object.
     * @return a PlaceLocalHandle that can be used to access the local objects.
     */
    public static def makeFlat[T](dist:Dist, init:()=>T){T isref}:PlaceLocalHandle[T] {
        return makeFlat(dist.places(), init);
    }

    /**
     * Create a distributed object with local state of type T
     * at each place in the argument distribution.  For each place in the
     * argument distribution, the local_init closure will be evaluated to
     * yield a value of type U.  This value will then be serialized to the
     * target place and passed as an argument to the init closure.
     * When this method returns, the local objects will be initialized and available
     * via the returned PlaceLocalHandle instance at every place in the distribution.
     *
     * Requires an initialization closure that does not change place asynchronously.
     *
     * @param dist a distribution specifiying the places where local objects should be created.
     * @param init_here a closure to compute the local portion of the initialization (evaluated in the current place)
     * @param init_there a closure to be evaluated in each place to create the local objects.
     * @return a PlaceLocalHandle that can be used to access the local objects.
     */
    public static def makeFlat[T,U](dist:Dist, init_here:(Place)=>U, init_there:(U)=>T){T isref}:PlaceLocalHandle[T] {
        return makeFlat(dist.places(), init_here, init_there);
    }

    /**
     * Create a distributed object with local state of type T
     * at each place in the argument PlaceGroup.  The local object will be initialized
     * by evaluating init at each place.  When this method returns, the local objects
     * will be initialized and available via the returned PlaceLocalHandle instance
     * at every place in the PlaceGroup.
     *
     * Requires an initialization closure that does not change place asynchronously.
     *
     * @param pg a PlaceGroup specifiying the places where local objects should be created.
     * @param init the initialization closure used to create the local object.
     * @return a PlaceLocalHandle that can be used to access the local objects.
     */
     /*
    public static def makeFlat[T](pg:PlaceGroup, init:()=>T){T isref}:PlaceLocalHandle[T] {
        val handle = at(Place.FIRST_PLACE) PlaceLocalHandle[T]();
        @Pragma(Pragma.FINISH_SPMD) finish for (p in pg) {
            at (p) async handle.set(init());
        }
        return handle;
    }
    */
    public static def makeFlat[T](pg:PlaceGroup, init:()=>T){T isref}:PlaceLocalHandle[T] {
        return make[T](pg, init);
    }

    /**
     * Create a distributed object with local state of type T
     * at each place in the argument PlaceGroup.  For each place in the
     * argument PlaceGroup, the local_init closure will be evaluated in the
     * current place to yield a value of type U.  This value will then be serialized
     * to the target place and passed as an argument to the init closure.
     * When this method returns, the local objects will be initialized and available
     * via the returned PlaceLocalHandle instance at every place in the distribution.
     *
     * Requires an initialization closure that does not change place asynchronously.
     *
     * @param dist a distribution specifiying the places where local objects should be created.
     * @param init_here a closure to compute the local portion of the initialization (evaluated in the current place)
     * @param init_there a closure to be evaluated in each place to create the local objects.
     * @return a PlaceLocalHandle that can be used to access the local objects.
     */
    /*
    public static def makeFlat[T,U](pg:PlaceGroup, init_here:(Place)=>U, init_there:(U)=>T){T isref}:PlaceLocalHandle[T] {
        val handle = at(Place.FIRST_PLACE) PlaceLocalHandle[T]();
        @Pragma(Pragma.FINISH_SPMD) finish for (p in pg) {
            val v:U = init_here(p);
            at (p) async handle.set(init_there(v));
        }
        return handle;
    }*/
    public static def makeFlat[T,U](pg:PlaceGroup, init_here:(Place)=>U, init_there:(U)=>T){T isref}:PlaceLocalHandle[T] {
        return make[T,U](pg, init_here, init_there);
    }

    public static def destroy[T](pg: PlaceGroup, plh:PlaceLocalHandle[T]){T isref, T haszero}: void {
        finish for (p in pg) {
            at (p) async plh.set(Zero.get[T]());
        }
    }
}
