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

package x10.array;

import x10.compiler.CompilerFlags;
import x10.compiler.Header;
import x10.compiler.Inline;
import x10.compiler.Native;
import x10.compiler.NoInline;
import x10.compiler.NoReturn;
import x10.compiler.Incomplete;

import x10.io.CustomSerialization;
import x10.io.SerialData;

import x10.util.IndexedMemoryChunk;

/**
 * <p>A distributed array (DistArray) defines a mapping from {@link Point}s to data
 * values of some type T. The Points in the DistArray's domain are defined by
 * specifying a {@link Region} over which the Array is defined.  Attempting to access
 * a data value at a Point not included in the Array's Region will result in a
 * {@link ArrayIndexOutOfBoundsException} being raised. The array's distribution ({@link Dist})
 * defines a mapping for the Points in the DistArray's region to Places. This defines
 * the Place where the data element for each Point is actually stored. Attempting to access
 * a data element from any other place will result in a {@link BadPlaceException} being
 * raised.</p>
 *
 * <p>The closely related class {@link Array} is used to define
 * non-distributed arrays where the data values for the Points in the
 * array's domain are all stored in a single place.  Although it is possible to
 * use a DistArray to store data in only a single place by creating a "constant distribution",
 * an Array will significantly outperform a DistArray with a constant distribution.</p>
 *
 * @see Point
 * @see Region
 * @see Dist
 * @see Array
 */
public final class DistArray[T] (
    /**
     * The distribution of this array.
     */
    dist:Dist
) implements (Point(dist.region.rank))=>T,
             Iterable[Point(dist.region.rank)],
             CustomSerialization
{

    //
    // property methods that forward to dist and dist.region
    //

    /**
     * The region this array is defined over.
     */
    public property region(): Region(rank) = dist.region;

    /**
     * The rank of this array.
     */
    public property rank(): int = dist.rank;

    protected static class LocalState[T](dist:Dist, data:IndexedMemoryChunk[T]) {
      public def this(d:Dist, c:IndexedMemoryChunk[T]) {
          property(d, c);

          // Calling operator this here serves to force initialization of any
          // cached local state in the Dist object.  The main reason for doing
          // this is to avoid lazy creation of this state (and thus allocation)
          // when the debugger uses the LocalState to display the elements of a DistArray
          val unused = d(here);
      }
    }

    /** The place-local backing storage for the DistArray */
    protected val localHandle:PlaceLocalHandle[LocalState[T]];
    /** Can the backing storage be obtained from cachedRaw? */
    protected transient var cachedRawValid:boolean;
    /** Cached pointer to the backing storage */
    protected transient var cachedRaw:IndexedMemoryChunk[T];

    /**
     * Method to acquire a pointer to the backing storage for the
     * array's data in the current place.
     */
    public final def raw():IndexedMemoryChunk[T] {
        if (!cachedRawValid) {
            cachedRaw = localHandle().data;
            x10.util.concurrent.Fences.storeStoreBarrier();
	    cachedRawValid = true;
        }
        return cachedRaw;
    }

    /**
     * Free internal structures, it is invalid to further use the DistArrays
     * after this point.
     */
    public def free() : void {
        PlaceLocalHandle.destroy[LocalState[T]](PlaceGroup.getWorld(), localHandle);
    }

    /**
     * @return the portion of the DistArray that is stored
     *    locally at the current place, as an Array
     */
    public def getLocalPortion():Array[T](dist.rank) {
        val regionForHere = dist.get(here);
        if (!regionForHere.rect) throw new UnsupportedOperationException(this.typeName() +".getLocalPortion(): local portion is not rectangular!");
        return new Array[T](regionForHere, raw());
    }

    /**
     * Create a zero-initialized distributed array over the argument distribution.
     *
     * @param dist the given distribution
     * @return the newly created DistArray
     */
    public static def make[T](dist:Dist) {T haszero} = new DistArray[T](dist);

    def this(dist: Dist) {T haszero} : DistArray[T]{self.dist==dist} {
        property(dist);

        val plsInit:()=>LocalState[T] = () => {
            val size = dist.places().contains(here) ? dist.maxOffset()+1 : 0;
            val localRaw = IndexedMemoryChunk.allocateZeroed[T](size);
            return new LocalState(dist, localRaw);
        };

        localHandle = PlaceLocalHandle.makeFlat[LocalState[T]](PlaceGroup.getWorld(), plsInit);
    }

    def this(sd:SerialData) {
      val plh:PlaceLocalHandle[LocalState[T]] = sd.data as PlaceLocalHandle[LocalState[T]];
      val ls = plh();
      var d:Dist;
      if (ls != null) {
          d = ls.dist;
      } else {
          /* might happen due to reinvasion, assume Place(0) works */
          assert here.id != 0;
          val dist = at (new Place(0)) plh().dist;
          val size = dist.places().contains(here) ? dist.maxOffset()+1 : 0;
          val localRaw = IndexedMemoryChunk.allocateZeroed[T](size);
          plh.set(new LocalState(dist, localRaw));
          d = dist;
      }
      property(d);
      localHandle = plh;
    }

    public def serialize():SerialData {
        return new SerialData(localHandle, null);
    }


    /**
     * Create a distributed array over the argument distribution whose elements
     * are initialized by executing the given initializer function for each
     * element of the array in the place where the argument Point is mapped.
     * The function will be evaluated exactly once for each point
     * in dist in an arbitrary order to compute the initial value for each array element.</p>
     *
     * Within each place, it is unspecified whether the function evaluations will
     * be done sequentially by a single activity for each point or concurrently for disjoint sets
     * of points by one or more child activities.
     *
     * @param dist the given distribution
     * @param init the initializer function
     * @return the newly created DistArray
     * @see #make[T](Dist)
     */
    public static def make[T](dist:Dist, init:(Point(dist.rank))=>T)= new DistArray[T](dist, init);

    // TODO: consider making this constructor public
    def this(dist:Dist, init:(Point(dist.rank))=>T):DistArray[T]{self.dist==dist} {
        property(dist);

        val plsInit:()=>LocalState[T] = () => {
            val localRaw:IndexedMemoryChunk[T];
            if (dist.places().contains(here)) {
                localRaw = IndexedMemoryChunk.allocateUninitialized[T](dist.maxOffset()+1);
                val reg = dist.get(here);
                for (pt in reg) {
                    localRaw(dist.offset(pt)) = init(pt);
                }
            } else {
                localRaw = IndexedMemoryChunk.allocateUninitialized[T](0);
            }
            return new LocalState(dist, localRaw);
        };

        localHandle = PlaceLocalHandle.make[LocalState[T]](PlaceGroup.getWorld(), plsInit);
    }


    /**
     * Create a distributed array over the argument distribution whose elements
     * are initialized to the given initial value.
     *
     * @param dist the given distribution
     * @param init the initial value
     * @return the newly created DistArray
     * @see #make[T](Dist)
     */
    public static def make[T](dist:Dist, init:T)= new DistArray[T](dist, init);

    // TODO: consider making this constructor public
    def this(dist:Dist, init:T):DistArray[T]{self.dist==dist} {
        property(dist);

        val plsInit:()=>LocalState[T] = () => {
            val localRaw:IndexedMemoryChunk[T];
            if (dist.places().contains(here)) {
                localRaw = IndexedMemoryChunk.allocateUninitialized[T](dist.maxOffset()+1);
                val reg = dist.get(here);
                for (pt in reg) {
                    localRaw(dist.offset(pt)) = init;
                }
            } else {
                localRaw = IndexedMemoryChunk.allocateUninitialized[T](0);
            }
            return new LocalState(dist, localRaw);
        };

        localHandle = PlaceLocalHandle.makeFlat[LocalState[T]](PlaceGroup.getWorld(), plsInit);
    }

    /**
     * Create a DistArray that views the same backing data
     * as the argument DistArray using a different distribution.</p>
     *
     * An unchecked invariant for this to be correct is that for every
     * point p in d, <code>d.offset(p) == a.dist.offset(p)</code>.
     * This invariant is too expensive to be checked dynamically, so it simply must
     * be respected by the DistArray code that calls this constructor.
     */
    protected def this(a:DistArray[T], d:Dist):DistArray[T]{self.dist==d} {
        property(d);

        val plsInit:()=>LocalState[T] = ()=> new LocalState(d, a.localHandle().data);
        localHandle = PlaceLocalHandle.makeFlat[LocalState[T]](PlaceGroup.getWorld(), plsInit);
    }

    /**
     * Create a DistArray from a distribution and a PlaceLocalHandle[LocalState[T]]
     * This constructor is intended for internal use only by operations such as
     * map to enable them to complete with only 1 collective operation instead of 2.
     */
    protected def this(d:Dist, pls:PlaceLocalHandle[LocalState[T]]) {
        property(d);
        localHandle = pls;
    }


    /**
     * Return the element of this array corresponding to the given point.
     * The rank of the given point has to be the same as the rank of this array.
     * If the distribution does not map the given Point to the current place,
     * then a BadPlaceException will be raised.
     *
     * @param pt the given point
     * @return the element of this array corresponding to the given point.
     * @see #operator(Int)
     * @see #set(T, Point)
     */
    public final operator this(pt:Point(rank)): T {
        val offset = dist.offset(pt);
        return raw()(offset);
    }

    /**
     * Return the element of this array corresponding to the given index.
     * Only applies to one-dimensional arrays.
     * Functionally equivalent to indexing the array via a one-dimensional point.
     * If the distribution does not map the specified index to the current place,
     * then a BadPlaceException will be raised.
     *
     * @param i0 the given index in the first dimension
     * @return the element of this array corresponding to the given index.
     * @see #operator(Point)
     * @see #set(T, Int)
     */
    public final operator this(i0:int){rank==1}: T {
        val offset = dist.offset(i0);
        return raw()(offset);
    }

    /**
     * Return the element of this array corresponding to the given pair of indices.
     * Only applies to two-dimensional arrays.
     * Functionally equivalent to indexing the array via a two-dimensional point.
     * If the distribution does not map the specified index to the current place,
     * then a BadPlaceException will be raised.
     *
     * @param i0 the given index in the first dimension
     * @param i1 the given index in the second dimension
     * @return the element of this array corresponding to the given pair of indices.
     * @see #operator(Point)
     * @see #set(T, Int, Int)
     */
    public final operator this(i0:int, i1:int){rank==2}: T {
        val offset = dist.offset(i0, i1);
        return raw()(offset);
    }

    /**
     * Return the element of this array corresponding to the given triple of indices.
     * Only applies to three-dimensional arrays.
     * Functionally equivalent to indexing the array via a three-dimensional point.
     * If the distribution does not map the specified index to the current place,
     * then a BadPlaceException will be raised.
     *
     * @param i0 the given index in the first dimension
     * @param i1 the given index in the second dimension
     * @param i2 the given index in the third dimension
     * @return the element of this array corresponding to the given triple of indices.
     * @see #operator(Point)
     * @see #set(T, Int, Int, Int)
     */
    public final operator this(i0:int, i1:int, i2:int){rank==3}: T {
        val offset = dist.offset(i0, i1, i2);
        return raw()(offset);
    }

    /**
     * Return the element of this array corresponding to the given quartet of indices.
     * Only applies to four-dimensional arrays.
     * Functionally equivalent to indexing the array via a four-dimensional point.
     * If the distribution does not map the specified index to the current place,
     * then a BadPlaceException will be raised.
     *
     * @param i0 the given index in the first dimension
     * @param i1 the given index in the second dimension
     * @param i2 the given index in the third dimension
     * @param i3 the given index in the fourth dimension
     * @return the element of this array corresponding to the given quartet of indices.
     * @see #operator(Point)
     * @see #set(T, Int, Int, Int, Int)
     */
    public final operator this(i0:int, i1:int, i2:int, i3:int){rank==4}: T {
        val offset = dist.offset(i0, i1, i2, i3);
        return raw()(offset);
    }


    /**
     * Set the element of this array corresponding to the given point to the given value.
     * Return the new value of the element.
     * The rank of the given point has to be the same as the rank of this array.
     * If the distribution does not map the specified index to the current place,
     * then a BadPlaceException will be raised.
     *
     * @param v the given value
     * @param pt the given point
     * @return the new value of the element of this array corresponding to the given point.
     * @see #operator(Point)
     * @see #set(T, Int)
     */
    public final operator this(pt: Point(rank))=(v: T): T {
        val offset = dist.offset(pt);
        raw()(offset) = v;
        return v;
    }

    /**
     * Set the element of this array corresponding to the given index to the given value.
     * Return the new value of the element.
     * Only applies to one-dimensional arrays.
     * Functionally equivalent to setting the array via a one-dimensional point.
     * If the distribution does not map the specified index to the current place,
     * then a BadPlaceException will be raised.
     *
     * @param v the given value
     * @param i0 the given index in the first dimension
     * @return the new value of the element of this array corresponding to the given index.
     * @see #operator(Int)
     * @see #set(T, Point)
     */
    public final operator this(i0: int)=(v: T){rank==1}: T {
        val offset = dist.offset(i0);
        raw()(offset) = v;
        return v;
    }

    /**
     * Set the element of this array corresponding to the given pair of indices to the given value.
     * Return the new value of the element.
     * Only applies to two-dimensional arrays.
     * Functionally equivalent to setting the array via a two-dimensional point.
     * If the distribution does not map the specified index to the current place,
     * then a BadPlaceException will be raised.
     *
     * @param v the given value
     * @param i0 the given index in the first dimension
     * @param i1 the given index in the second dimension
     * @return the new value of the element of this array corresponding to the given pair of indices.
     * @see #operator(Int, Int)
     * @see #set(T, Point)
     */
    public final operator this(i0: int, i1: int)=(v: T){rank==2}: T {
        val offset = dist.offset(i0, i1);
        raw()(offset) = v;
        return v;
    }

    /**
     * Set the element of this array corresponding to the given triple of indices to the given value.
     * Return the new value of the element.
     * Only applies to three-dimensional arrays.
     * Functionally equivalent to setting the array via a three-dimensional point.
     * If the distribution does not map the specified index to the current place,
     * then a BadPlaceException will be raised.
     *
     * @param v the given value
     * @param i0 the given index in the first dimension
     * @param i1 the given index in the second dimension
     * @param i2 the given index in the third dimension
     * @return the new value of the element of this array corresponding to the given triple of indices.
     * @see #operator(Int, Int, Int)
     * @see #set(T, Point)
     */
    public final operator this(i0: int, i1: int, i2: int)=(v: T){rank==3}: T {
        val offset = dist.offset(i0,i1,i2);
        raw()(offset) = v;
        return v;
    }

    /**
     * Set the element of this array corresponding to the given quartet of indices to the given value.
     * Return the new value of the element.
     * Only applies to four-dimensional arrays.
     * Functionally equivalent to setting the array via a four-dimensional point.     * If the distribution does not map the specified index to the current place,
     * then a BadPlaceException will be raised.
     *
     *
     * @param v the given value
     * @param i0 the given index in the first dimension
     * @param i1 the given index in the second dimension
     * @param i2 the given index in the third dimension
     * @param i3 the given index in the fourth dimension
     * @return the new value of the element of this array corresponding to the given quartet of indices.
     * @see #operator(Int, Int, Int, Int)
     * @see #set(T, Point)
     */
    public final operator this(i0: int, i1: int, i2: int, i3: int)=(v: T){rank==4}: T {
        val offset = dist.offset(i0,i1,i2,i3);
        raw()(offset) = v;
        return v;
    }

    /*
     * restriction view
     */

    /**
     * Return a DistArray that access the same backing storage
     * as this array, but only over the Points in the argument
     * distribtion.</p>
     *
     * For this operation to be semantically sound, it should
     * be the case that for every point p in d,
     * <code>this.dist.offset(p) == d.offset</code>.
     * This invariant is not statically or dynamically checked;
     * but must be ensured by the caller's of this API.
     *
     * @param d the Dist to use as the restriction
     */
    public def restriction(d:Dist(rank)) {
        return new DistArray[T](this, d) as DistArray[T](rank);
    }

    /**
     * Return a DistArray that is defined over the same distribution
     * and backing storage as this DistArray instance, but is
     * restricted to only allowing access to those points that are
     * contained in the argument region r.
     *
     * @param r the Region to which to restrict the array
     */
    public def restriction(r: Region(rank)): DistArray[T](rank) {
        return restriction(dist.restriction(r) as Dist(rank));
    }

    /**
     * Return a DistArray that is defined over the same distribution
     * and backing storage as this DistArray instance, but is
     * restricted to only allowing access to those points that are
     * mapped by the defining distripution to the argument Place.
     *
     * @param p the Place to which to restrict the array
     */
    public def restriction(p: Place): DistArray[T](rank) {
        return restriction(dist.restriction(p) as Dist(rank));
    }

    /**
     * Return a DistArray that is defined over the same distribution
     * and backing storage as this DistArray instance, but is
     * restricted to only allowing access to those points that are
     * contained in the argument region r.
     *
     * @param r the Region to which to restrict the array
     */
    public operator this | (r: Region(rank)) = restriction(r);

    /**
     * Return a DistArray that is defined over the same distribution
     * and backing storage as this DistArray instance, but is
     * restricted to only allowing access to those points that are
     * mapped by the defining distripution to the argument Place.
     *
     * @param p the Place to which to restrict the array
     */
    public operator this | (p: Place) = restriction(p);


    //
    // Bulk operations
    //

    /**
     * Fill all elements of the array to contain the argument value.
     *
     * @param v the value with which to fill the array
     */
    public def fill(v:T) {
        finish for (where in dist.places()) {
            at (where) async {
                val imc = raw();
                val reg = dist.get(here);
                for (pt in reg) {
                    imc(dist.offset(pt)) = v;
                }
            }
        }
    }

    /**
     * Map the function onto the elements of this array
     * constructing a new result array such that for all points <code>p</code>
     * in <code>this.dist</code>,
     * <code>result(p) == op(this(p))</code>.<p>
     *
     * @param op the function to apply to each element of the array
     * @return a new array with the same distribution as this array where <code>result(p) == op(this(p))</code>
     */
    public final def map[U](op:(T)=>U):DistArray[U](this.dist) {
        val plh = PlaceLocalHandle.make[LocalState[U]](PlaceGroup.getWorld(), ()=> {
            val newImc:IndexedMemoryChunk[U];
            if (dist.places().contains(here)) {
                val srcImc = raw();
                newImc = IndexedMemoryChunk.allocateUninitialized[U](dist.maxOffset()+1);
                val reg = dist.get(here);
                for (pt in reg) {
                    val offset = dist.offset(pt);
                    newImc(offset) = op(srcImc(offset));
                }
            } else {
                newImc = IndexedMemoryChunk.allocateUninitialized[U](0);
            }
            return new LocalState[U](dist, newImc);
        });
        return new DistArray[U](dist, plh);
    }

    /**
     * Map the given function onto the elements of this array
     * storing the results in the dst array such that for all points <code>p</code>
     * in <code>this.dist</code>,
     * <code>dst(p) == op(this(p))</code>.<p>
     *
     * @param dst the destination array for the results of the map operation
     * @param op the function to apply to each element of the array
     * @return dst after applying the map operation.
     */
    public final def map[U](dst:DistArray[U](this.dist), op:(T)=>U):DistArray[U](dist){self==dst} {
        finish {
            for (where in dist.places()) {
                at(where) async {
                    val reg = dist.get(here);
                    val srcImc = raw();
                    val dstImc = dst.raw();
                    for (pt in reg) {
                        val offset = dist.offset(pt);
                        dstImc(offset) = op(srcImc(offset));
                    }
                }
            }
        }
        return dst;
    }

    /**
     * Map the given function onto the elements of this array
     * storing the results in the dst array for the subset of points included
     * in the filter region such that for all points <code>p</code>
     * in <code>filter</code>,
     * <code>dst(p) == op(this(p))</code>.<p>
     *
     * @param dst the destination array for the results of the map operation
     * @param op the function to apply to each element of the array
     * @param filter the region to use as a filter on the map operation
     * @return dst after applying the map operation.
     */
    public final def map[U](dst:DistArray[U](this.dist), filter:Region(rank), op:(T)=>U):DistArray[U](dist){self==dst} {
        finish {
            for (where in dist.places()) {
                at(where) async {
                    val reg = dist.get(here);
                    val freg = reg && filter;
                    val srcImc = raw();
                    val dstImc = dst.raw();
                    for (pt in freg) {
                        val offset = dist.offset(pt);
                        dstImc(offset) = op(srcImc(offset));
                    }
                }
            }
        }
        return dst;
    }

    /**
     * Map the given function onto the elements of this array
     * and the other src array, storing the results in a new result array
     * such that for all points <code>p</code> in <code>this.dist</code>,
     * <code>result(p) == op(this(p), src(p))</code>.<p>
     *
     * @param src the other src array
     * @param op the function to apply to each element of the array
     * @return a new array with the same distribution as this array containing the result of the map
     */
    public final def map[S,U](src:DistArray[U](this.dist), op:(T,U)=>S):DistArray[S](dist) {
        val plh = PlaceLocalHandle.make[LocalState[S]](PlaceGroup.getWorld(), ()=> {
            val newImc:IndexedMemoryChunk[S];
            if (dist.places().contains(here)) {
                val src1Imc = raw();
                val src2Imc = src.raw();
                newImc = IndexedMemoryChunk.allocateUninitialized[S](dist.maxOffset()+1);
                val reg = dist.get(here);
                for (pt in reg) {
                    val offset = dist.offset(pt);
                    newImc(offset) = op(src1Imc(offset), src2Imc(offset));
                }
            } else {
                newImc = IndexedMemoryChunk.allocateUninitialized[S](0);
            }
            return new LocalState[S](dist, newImc);
        });
        return new DistArray[S](dist, plh);
    }

    /**
     * Map the given function onto the elements of this array
     * and the other src array, storing the results in the given dst array
     * such that for all points <code>p</code> in <code>this.dist</code>,
     * <code>dst(p) == op(this(p), src(p))</code>.<p>
     *
     * @param dst the destination array for the map operation
     * @param src the second source array for the map operation
     * @param op the function to apply to each element of the array
     * @return destination after applying the map operation.
     */
    public final def map[S,U](dst:DistArray[S](this.dist), src:DistArray[U](this.dist), op:(T,U)=>S):DistArray[S](dist) {
        finish {
            for (where in dist.places()) {
                at(where) async {
                    val reg = dist.get(here);
                    val src1Imc = raw();
                    val src2Imc = src.raw();
                    val dstImc = dst.raw();
                    for (pt in reg) {
                        val offset = dist.offset(pt);
                        dstImc(offset) = op(src1Imc(offset), src2Imc(offset));
                    }
                }
            }
        }
        return dst;
    }

    /**
     * Map the given function onto the elements of this array
     * and the other src array, storing the results in the given dst array
     * such that for all points in the filter region <code>p</code> in <code>filter</code>,
     * <code>dst(p) == op(this(p), src(p))</code>.<p>
     *
     * @param dst the destination array for the map operation
     * @param src the second source array for the map operation
     * @param op the function to apply to each element of the array
     * @param filter the region to use to select the subset of points to include in the map
     * @return destination after applying the map operation.
     */
    public final def map[S,U](dst:DistArray[S](this.dist), src:DistArray[U](this.dist), filter:Region(rank), op:(T,U)=>S):DistArray[S](dist) {
        finish {
            for (where in dist.places()) {
                at(where) async {
                    val reg = dist.get(here);
                    val freg = reg && filter;
                    val src1Imc = raw();
                    val src2Imc = src.raw();
                    val dstImc = dst.raw();
                    for (pt in freg) {
                        val offset = dist.offset(pt);
                        dstImc(offset) = op(src1Imc(offset), src2Imc(offset));
                    }
                }
            }
        }
        return dst;
    }

    /**
     * Reduce this array using the given function and the given initial value.
     * Each element of the array will be given as an argument to the reduction
     * function exactly once, but in an arbitrary order.  The reduction function
     * may be applied concurrently to implement a parallel reduction.
     *
     * @param op the reduction function
     * @param unit the given initial value
     * @return the final result of the reduction.
     * @see #map((T)=>S)
     * @see #reduce(U,T)=>U,(U,U)=>U,U)
     */
    public final def reduce(op:(T,T)=>T, unit:T):T  = reduce[T](op, op, unit);

    /**
     * Reduce this array using the given function and the given initial value.
     * Each element of the array will be given as an argument to the reduction
     * function exactly once, but in an arbitrary order.  The reduction function
     * may be applied concurrently to implement a parallel reduction.
     *
     * @param lop the local reduction function
     * @param gop the global reduction function
     * @param unit the given initial value
     * @return the final result of the reduction.
     * @see #map((T)=>S)
     */
    public final def reduce[U](lop:(U,T)=>U, gop:(U,U)=>U, unit:U):U {
        val result = new GlobalRef[Cell[U]](Cell.make[U](unit));
        val home   = here;

        finish for (where in dist.places()) at (where) async {
            val reg = dist.get(here);
            var localTmp:U = unit;
            val imc = raw();
            for (pt in reg) {
               localTmp = lop(localTmp, imc(dist.offset(pt)));
            }
            val localRes = localTmp;
            at (home) atomic {
                result().set(gop(result()(), localRes));
            }
        }

        return result()();
    }

    public def toString(): String {
        return "DistArray(" + dist + ")";
    }

    /**
     * Return an iterator over the points in the region of this array.
     *
     * @return an iterator over the points in the region of this array.
     * @see x10.lang.Iterable[T]#iterator()
     */
    public def iterator(): Iterator[Point(rank)] = region.iterator() as Iterator[Point(rank)];
}
public type DistArray[T](r:Int) = DistArray[T]{self.rank==r};
public type DistArray[T](r:Region) = DistArray[T]{self.region==r};
public type DistArray[T](d:Dist) = DistArray[T]{self.dist==d};
public type DistArray[T](a:DistArray[T]) = DistArray[T]{self==a};

// vim:tabstop=4:shiftwidth=4:expandtab
