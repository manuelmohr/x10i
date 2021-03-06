/*
 *  This file is part of the X10 project (http://x10-lang.org).
 *
 *  This file is licensed to You under the Eclipse Public License (EPL);
 *  You may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *      http://www.opensource.org/licenses/eclipse-1.0.php
 *
 *  (C) Copyright IBM Corporation 2006-2010.
 *  (C) Copyright Australian National University 2010.
 */

package x10.array;

import x10.compiler.Pragma;

/**
 * <p> A PlaceGroup represents an ordered set of Places.
 * PlaceGroups are represented by a specialized set of classes (instead of using
 * arbitrary collection types) because it is necessary for performance/scalability
 * to have optimized representations of specific special cases.  The API is also 
 * designed specifically to efficiently support the operations needed by Dist, 
 * DistArray, and Team.</p>
 *
 * @see Place
 * @see Dist
 * @see DistArray
 * @see x10.util.Team
 */
public abstract class PlaceGroup implements Sequence[Place] {

  /**
   * A PlaceGroup that represents exactly Place.places().
   * All places, in order of increasing Place.id.
   */
  public static val WORLD = new SimplePlaceGroup(Place.numPlaces());

  /**
   * The size of the PlaceGroup is equal to the value returned by numPlaces()
   */
  public final property def size():int = numPlaces();

  /**
   * @return the number of Places in the PlaceGroup
   */
  public abstract def numPlaces():Int;

  /**
   * @return true if the PlaceGroup contains place, false otherwise
   */
  public def contains(place:Place):Boolean = contains(place.id);

  /**
   * @return true if the PlaceGroup contains the place with
   *  the given id, false otherwise
   */
  public abstract def contains(id:int):Boolean;

  /**
   * <p>If the argument place is contained in the PlaceGroup
   * return an int between 0 and numPlaces()-1 that is the
   * ordinal number of the Place in the PlaceGroup. 
   * If the argument place is not contained in the PlaceGroup,
   * then return -1.</p>
   *
   * <p>If the PlaceGroup pg contains place, then the invariant
   * <code>pg(indexOf(place)).equals(place) == true</code> holds.</p>
   * 
   * @return the index of place
   */
  public def indexOf(place:Place):int = indexOf(place.id);

  /**
   * <p>If the Place with id equal to id is contained in the PlaceGroup
   * return an int between 0 and numPlaces()-1 that is the
   * ordinal number of said Place in the PlaceGroup. 
   * If the argument place is not contained in the PlaceGroup,
   * then return -1.</p>
   *
   * <p>If the PlaceGroup pg contains the argument Place, 
   * then the invariant
   * <code>pg(indexOf(id)).equals(Place.place(id)) == true</code> holds.</p>
   * 
   * @return the index of the Place encoded by id
   */
  public abstract def indexOf(id:int):int;

  /**
   * Return the Place with ordinal number <code>i</code> in the place group
   *
   * @param i the ordinal number of the desired place
   * @return the ith place in the place group
   */
  public abstract operator this(i:int):Place;


  /**
   * Two place groups are equal iff they contain the same places
   */
  public def equals(thatObj:Any):Boolean {
    if (this == thatObj) return true;
    if (!(thatObj instanceof PlaceGroup)) return false;
    val that = thatObj as PlaceGroup;
    if (numPlaces() != that.numPlaces()) return false;
    for (var i:int=0; i<numPlaces(); i++) {
      if (!this(i).equals(that(i))) return false;
    }
    return true;
  }

  public def broadcastFlat(cl:()=>void) {
    @Pragma(Pragma.FINISH_SPMD) finish for (p in this) {
      at (p) async cl();
    }
  }

  public static class SimplePlaceGroup extends PlaceGroup {
    private val numPlaces:Int;
    def this(numPlaces:Int) { this.numPlaces = numPlaces; }
    public operator this(i:int):Place = Place(i);
    public def numPlaces() = numPlaces;
    public def contains(id:int) = id >= 0 && id < numPlaces;
    public def indexOf(id:int) = contains(id) ? id : -1;
    public def iterator():Iterator[Place]{self!=null} = new Iterator[Place](){
      private var i:Int = 0;
      public def hasNext() = i < numPlaces;
      public def next() = Place(i++);
    };
    public def equals(thatObj:Any):Boolean {
        if (thatObj instanceof SimplePlaceGroup) {
            return numPlaces() == (thatObj as PlaceGroup).numPlaces();
        } else {
            return super.equals(thatObj);
        }
    }
    public def hashCode() = numPlaces.hashCode();
    public def broadcastFlat(cl:()=>void) {
        if (numPlaces() >= 1024) {
            @Pragma(Pragma.FINISH_SPMD) finish for(var i:Int=numPlaces()-1; i>=0; i-=32) {
                at (Place(i)) async {
                    val max = Runtime.hereInt();
                    val min = Math.max(max-31, 0);
                    @Pragma(Pragma.FINISH_SPMD) finish for (var j:Int=min; j<=max; ++j) {
                        at (Place(j)) async cl();
                    }
                }
            }
        } else {
            super.broadcastFlat(cl);
        }
    }
  }

  public static make(numPlaces:Int) = new SimplePlaceGroup(numPlaces);
}
