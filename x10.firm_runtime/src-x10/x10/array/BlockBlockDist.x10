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

/**
 * <p>A BlockBlock distribution maps points in its region
 * in a 2D blocked fashion to the places in its PlaceGroup</p>
 *
 * It caches the region for the current place as a transient field.
 * This makes the initial access to this information somewhat slow,
 * but optimizes the wire-transfer size of the Dist object.
 * This appears to be the appropriate tradeoff, since Dist objects
 * are frequently serialized and usually the restriction operation is
 * applied to get the Region for here, not for other places.
 */
final class BlockBlockDist extends Dist {

    /**
     * The place group for this distribution
     */
    private val pg:PlaceGroup;

    /**
     * The first axis along which the region is distributed
     */
    private val axis0:int;

    /**
     * The second axis along which the region is distributed
     */
    private val axis1:int;

    /**
     * Cached restricted region for the current place.
     */
    private transient var regionForHere:Region(this.rank);


    public def this(r:Region, axis0:int, axis1:int, pg:PlaceGroup):BlockBlockDist{self.region==r} {
        super(r);
        this.axis0 = axis0;
        this.axis1 = axis1;
        this.pg = pg;
    }


    /**
     * The key algorithm for this class.
     * Compute the region for the given place by doing region algebra.
     *
     * Assumption: Caller has done error checking to ensure that place is
     *   actually a member of pg.
     */
    private def blockBlockRegionForPlace(place:Place):Region{self.rank==this.rank} {
        val b = region.boundingBox();
        val min0 = b.min(axis0);
        val max0 = b.max(axis0);
        val min1 = b.min(axis1);
        val max1 = b.max(axis1);
        val size0 = (max0 - min0 + 1);
        val size1 = (max1 - min1 + 1);
        val size0Even = size0 % 2 == 0 ? size0 : size0-1;
        val P = Math.min(pg.numPlaces(), size0Even * size1);
        val divisions0 = Math.min(size0Even, Math.pow2(Math.ceil((Math.log(P as Double) / Math.log(2.0)) / 2.0) as Int));
        val divisions1 = Math.min(size1, Math.ceil((P as Double) / divisions0) as Int);
        val leftOver = divisions0*divisions1 - P;

        val i = pg.indexOf(place);
        if (i >= P) return Region.makeEmpty(rank);

        val leftOverOddOffset = (divisions0 % 2 == 0) ? 0 : i*2/(divisions0+1);

        val blockIndex0 = i < leftOver ? (i*2-leftOverOddOffset) % divisions0 : (i+leftOver) % divisions0;
        val blockIndex1 = i < leftOver ? (i*2) / divisions0 : (i+leftOver) / divisions0;

        val low0 = min0 + Math.ceil(blockIndex0 * size0 / divisions0 as Double) as Int;
        val blockHi0 = blockIndex0 + (i < leftOver ? 2 : 1);
        val hi0 = min0 + Math.ceil(blockHi0 * size0 / divisions0 as Double) as Int - 1;

        val low1 = min1 + Math.ceil(blockIndex1 * size1 / divisions1 as Double) as Int;
        val hi1 = min1 + Math.ceil((blockIndex1+1) * size1 / divisions1 as Double) as Int - 1;

        if (region instanceof RectRegion) {
            // Optimize common case.
            val newMin = new Array[Int](rank, (i : Int) => region.min(i));
            val newMax = new Array[Int](rank, (i : Int) => region.max(i));
            newMin(axis0) = low0;
            newMin(axis1) = low1;
            newMax(axis0) = hi0;
            newMax(axis1) = hi1;
            return new RectRegion(newMin, newMax) as Region(rank);
        } else {
            // General case handled via region algebra
            val beforeAxes = (axis1 > axis0) ? Region.makeFull(axis0) : Region.makeFull(axis1);
            val betweenAxes = (axis1 > axis0) ? Region.makeFull(axis1-axis0-1) : Region.makeFull(axis0-axis1-1);
            val afterAxes = (axis1 > axis0) ? Region.makeFull(region.rank-axis1-1) : Region.makeFull(region.rank-axis0-1);
            var lowFirst:Int;
            val hiFirst:Int;
            val lowSecond:Int;
            val hiSecond:Int;
            if (axis1 > axis0) {
                lowFirst = low0;
                lowSecond = low1;
                hiFirst = hi0;
                hiSecond = hi1;
            } else {
                lowFirst = low1;
                lowSecond = low0;
                hiFirst = hi1;
                hiSecond = hi0;
            }
            val rFirst = lowFirst..hiFirst;
            val rSecond = lowSecond..hiSecond;

            return (beforeAxes.product(rFirst).product(betweenAxes).product(rSecond).product(afterAxes) as Region(region.rank)).intersection(region);
        }
    }

    /**
     * Given an index into the "axis dimensions" determine which place it
     * is mapped to.
     * Assumption: Caller has done error checking to ensure that index is
     *   actually within the bounds of the axis dimension.
     */
    private def mapIndexToPlace(index0:int, index1:int) {
        val b = region.boundingBox();
        val min0 = b.min(axis0);
        val max0 = b.max(axis0);
        val min1 = b.min(axis1);
        val max1 = b.max(axis1);
        val size0 = (max0 - min0 + 1);
        val size1 = (max1 - min1 + 1);
        val size0Even = size0 % 2 == 0 ? size0 : size0-1;
        val P = Math.min(pg.numPlaces(), size0Even * size1);
        val divisions0 = Math.min(size0Even, Math.pow2(Math.ceil((Math.log(P as Double) / Math.log(2.0)) / 2.0) as Int));
        val divisions1 = Math.min(size1, Math.ceil((P as Double) / divisions0) as Int);
        val numBlocks = divisions0 * divisions1;
        val leftOver = numBlocks - P;

        val blockIndex0 = divisions0 == 1 ? 0 : ((index0 - min0) * divisions0) / size0;
        val blockIndex1 = divisions1 == 1 ? 0 : ((index1 - min1) * divisions1) / size1;
        val blockIndex = (blockIndex1 * divisions0) + blockIndex0;

        if (blockIndex <= leftOver * 2) {
            return pg((blockIndex / 2) as Int);
        } else {
            return pg(blockIndex - leftOver);
        }
    }

    public def places():PlaceGroup = pg;

    public def numPlaces():int = pg.numPlaces();

    public def regions():Sequence[Region(rank)] {
        return new Array[Region(rank)](pg.numPlaces(), (i:int)=>blockBlockRegionForPlace(pg(i))).sequence();
    }

    public def get(p:Place):Region(rank) {
        if (p == here) {
            if (regionForHere == null) {
                regionForHere = blockBlockRegionForPlace(here);
            }
            return regionForHere;
        } else {
            return blockBlockRegionForPlace(p);
        }
    }

    public def containsLocally(p:Point):boolean = get(here).contains(p);

    // replicated from superclass to workaround xlC bug with using & itables
    public operator this(p:Place):Region(rank) = get(p);

    public operator this(pt:Point(rank)):Place {
        if (CompilerFlags.checkBounds() && !region.contains(pt)) raiseBoundsError(pt);
            return mapIndexToPlace(pt(axis0), pt(axis1));
    }

    public operator this(i0:int){rank==1}:Place {
        // block,block dist only supported for rank>=2
        throw new UnsupportedOperationException("operator(i0:int)");
    }

    public operator this(i0:int, i1:int){rank==2}:Place {
        if (CompilerFlags.checkBounds() && !region.contains(i0, i1)) raiseBoundsError(i0,i1);
        switch(axis0) {
            case 0: return mapIndexToPlace(i0,i1);
            case 1: return mapIndexToPlace(i1,i0);
            default: return here; // UNREACHABLE
        }
    }

    public operator this(i0:int, i1:int, i2:int){rank==3}:Place {
        if (CompilerFlags.checkBounds() && !region.contains(i0, i1, i2)) raiseBoundsError(i0,i1,i2);
        switch(axis0) {
            case 0: switch(axis1) {
                case 1:
                    return mapIndexToPlace(i0,i1);
                case 2:
                    return mapIndexToPlace(i0,i2);
                default: return here; // UNREACHABLE
            }
            case 1: switch(axis1) {
                case 0:
                    return mapIndexToPlace(i1,i0);
                case 2:
                    return mapIndexToPlace(i1,i2);
                default: return here; // UNREACHABLE
            }
            case 2: switch(axis1) {
                case 0:
                    return mapIndexToPlace(i2,i0);
                case 1:
                    return mapIndexToPlace(i2,i1);
                default: return here; // UNREACHABLE
            }
            default: return here; // UNREACHABLE
        }
    }

    public operator this(i0:int, i1:int, i2:int, i3:int){rank==4}:Place {
        val pt = Point.make(i0, i1, i2, i3);
        if (CompilerFlags.checkBounds() && !region.contains(pt)) raiseBoundsError(pt);
        return mapIndexToPlace(pt(axis0), pt(axis1));
    }

    public def offset(pt:Point(rank)):int {
        val r = get(here);
        val offset = r.indexOf(pt);
        if (offset == -1) {
            if (CompilerFlags.checkBounds() && !region.contains(pt)) raiseBoundsError(pt);
            if (CompilerFlags.checkPlace()) raisePlaceError(pt);
        }
        return offset;
    }

    public def offset(i0:int){rank==1}:int {
        val r = get(here);
        val offset = r.indexOf(i0);
        if (offset == -1) {
            if (CompilerFlags.checkBounds() && !region.contains(i0)) raiseBoundsError(i0);
            if (CompilerFlags.checkPlace()) raisePlaceError(i0);
        }
        return offset;
    }

    public def offset(i0:int, i1:int){rank==2}:int {
        val r = get(here);
	    val offset = r.indexOf(i0,i1);
	    if (offset == -1) {
	        if (CompilerFlags.checkBounds() && !region.contains(i0,i1)) raiseBoundsError(i0,i1);
            if (CompilerFlags.checkPlace()) raisePlaceError(i0,i1);
        }
        return offset;
    }

    public def offset(i0:int, i1:int, i2:int){rank==3}:int {
        val r = get(here);
	    val offset = r.indexOf(i0,i1,i2);
	    if (offset == -1) {
	        if (CompilerFlags.checkBounds() && !region.contains(i0,i1,i2)) raiseBoundsError(i0,i1,i2);
            if (CompilerFlags.checkPlace()) raisePlaceError(i0,i1,i2);
        }
        return offset;
    }

    public def offset(i0:int, i1:int, i2:int, i3:int){rank==4}:int {
        val r = get(here);
	    val offset = r.indexOf(i0,i1,i2,i3);
	    if (offset == -1) {
	        if (CompilerFlags.checkBounds() && !region.contains(i0,i1,i2,i3)) raiseBoundsError(i0,i1,i2,i3);
            if (CompilerFlags.checkPlace()) raisePlaceError(i0,i1,i2,i3);
        }
        return offset;
    }

    public def maxOffset() {
        val r = get(here);
        return r.size()-1;
    }

    public def restriction(r:Region(rank)):Dist(rank) {
        return new WrappedDistRegionRestricted(this, r);
    }

    public def restriction(p:Place):Dist(rank) {
        return new WrappedDistPlaceRestricted(this, p);
    }


    public def equals(thatObj:Any):boolean {
        if (!(thatObj instanceof BlockBlockDist)) return false;
        val that = thatObj as BlockBlockDist;
        return this.axis0.equals(that.axis0) && this.axis1.equals(that.axis1) && this.region.equals(that.region);
    }
}

