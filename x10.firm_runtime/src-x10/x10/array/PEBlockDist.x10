/**
 *******************************************************************************
 * \file PEBlockDist.x10
 *
 * \brief Implementation of class PEBlockDist
 *
 * \attention  Copyright (C) 2010-2011 by University of Erlangen-Nuremberg,
 *             Chair for Hardware-Software-Co-Design, Germany.
 *             All rights reserved.
 *
 * \author Sascha Roloff
 *
 *******************************************************************************
 */
package x10.array;

import x10.compiler.CompilerFlags;
import x10.util.List;
import x10.util.ArrayList;
import invasic.ProcessingElement;

final class PEBlockDist extends PEDist {
	// The place group for this distribution
	private val pg:PlaceGroup;
	// The Processing Elements for this distribution
	private val pes:List[ProcessingElement];
	// The axis along which the region is being distributed
	private val axis:int;
	// Cached restricted region for the current place.
	private transient var regionForHere:Region(this.rank);

	// **************************************************************************
	// *** Constructor ***
	// **************************************************************************
	def this(r:Region, axis:int, pes:List[ProcessingElement]) {
		super(r);
		this.axis = axis;
		val cmp = (pe1:ProcessingElement, pe2:ProcessingElement):Int => {
			return pe1.getPlace().id.compareTo(pe2.getPlace().id);
		};
		pes.sort(cmp);
		this.pes = pes;

		// create array list containing places
		val list = new ArrayList[Place]();
		for(pe in pes) {
			val home = pe.getPlace();
			if(!list.contains(home))
				list.add(home);
		}
/*		val cmp = (p1:Place, p2:Place):Int => {
			return p1.id.compareTo(p2.id);
		};
		list.sort(cmp);*/
		// create array
		val arr = list.toArray();
		// create sequence
		val seq = arr.sequence();
		// create place group
		pg = new SparsePlaceGroup(seq);
	}

	// **************************************************************************
	// *** Implementation of the distribution ***
	// **************************************************************************
	private def blockRegionForPE(pe:ProcessingElement):Region{self.rank==this.rank} {
		// information about the region to partition
		val b = this.region.boundingBox();
		val min = b.min(this.axis);
		val max = b.max(this.axis);
		if (min >= max) return Region.makeEmpty(this.rank);
		val numElems = max - min + 1;
		// calculate the partition size for all pes
		val P = pes.size();
		if (P == 0) return Region.makeEmpty(this.rank);
		val blockSize = numElems / P;
		val leftOver  = numElems % P;
		// calculate the boundaries for the specific pe
		val i = pes.indexOf(pe);
		if (i == -1) return Region.makeEmpty(this.rank);
		val low = min + blockSize * i + (i < leftOver ? i : leftOver);
		val hi  = low + blockSize     + (i < leftOver ? 0 : -1);
		assert hi <= max;

		// create a new region
		if (this.region instanceof RectRegion) {
			// Optimize common case.
			val newMin = new Array[Int](rank, (i:Int) => this.region.min(i));
			val newMax = new Array[Int](rank, (i:Int) => this.region.max(i));
			newMin(this.axis) = low;
			newMax(this.axis) = hi;
			return new RectRegion(newMin, newMax);
		} else {
			// General case handled via region algebra
			val r1 = Region.makeFull(this.axis);
			val r2 = low..hi;
			val r3 = Region.makeFull(region.rank-axis-1);
			return (r1.product(r2).product(r3) as Region(region.rank)).intersection(region);
		}
	}

	/**
	 * The key algorithm for this class.
	 * Compute the region for the given place by doing region algebra.
	 *
	 * Assumption: Caller has done error checking to ensure that place is
	 *   actually a member of pg.
	 */
	private def blockRegionForPlace(place:Place):Region{self.rank==this.rank} {
		// information about the region to partition
		val b = region.boundingBox();
		val min = b.min(axis);
		val max = b.max(axis);
		val numElems = max - min + 1;
		// calculate the partition size for all pes
		val P = pes.size();
		val blockSize = numElems/P;
		val leftOver = numElems - P*blockSize;
		// calculate the boundaries for the specific amount of pes
		val part = getPEs(place);
		val i = pes.indexOf(part(0));
		val low = min + blockSize*i + (i< leftOver ? i : leftOver);
		val j = i + part.size() - 1;
		val low2 = min + blockSize*j + (j < leftOver ? j : leftOver);
		val hi = low2 + blockSize + (j < leftOver ? 0 : -1);

		// create a new region
		if (region instanceof RectRegion) {
			// Optimize common case.
			val newMin = new Array[Int](rank, (i:Int) => region.min(i));
			val newMax = new Array[Int](rank, (i:Int) => region.max(i));
			newMin(axis) = low;
			newMax(axis) = hi;
			return new RectRegion(newMin, newMax);
		} else {
			// General case handled via region algebra
			val r1 = Region.makeFull(axis);
			val r2 = low..hi;
			val r3 = Region.makeFull(region.rank-axis-1);
			return (r1.product(r2).product(r3) as Region(region.rank)).intersection(region);
		}
	}

	/**
	 * Given an index into the "axis dimension" determine which place it
	 * is mapped to.
	 *
	 * Assumption: Caller has done error checking to ensure that index is
	 *   actually within the bounds of the axis dimension.
	 */
	private def mapIndexToPlace(index:int):Place {
		val bb = region.boundingBox();
		val min = bb.min(axis);
		val max = bb.max(axis);
		val numElems = max - min + 1;
		val P = pes.size();
		val blockSize = numElems/P;
		val leftOver = numElems - P*blockSize;
		val normalizedIndex = index-min;
		val nominalPE = normalizedIndex/(blockSize+1);

		if (nominalPE < leftOver) {
			return pes(nominalPE).getPlace();
		} else {
			val indexFromTop = max-index;
			return pes(pes.size() - 1 - (indexFromTop/(blockSize))).getPlace();
		}
	}

	// **************************************************************************
	// *** New methods ***
	// **************************************************************************
	public def restriction(pe: ProcessingElement): Dist(rank) {
		return new WrappedDistPERestricted(this, pe) as Dist(rank); // TODO: cast should not be needed
	}

	public def get(pe: ProcessingElement): Region(rank) {
		return blockRegionForPE(pe);
	}

	public def pes(): List[ProcessingElement] = pes.clone() as List[ProcessingElement];

	private def getPEs(p: Place): List[ProcessingElement] {
		val arr = new ArrayList[ProcessingElement]();
		for(pe in pes) {
			if(pe.getPlace() == p) {
				arr.add(pe);
			}
		}
		return arr;
	}

	// **************************************************************************
	// *** Methods from Dist ***
	// **************************************************************************
	public def places():PlaceGroup = pg;

	public def numPlaces():int = pg.numPlaces();

	public def regions():Sequence[Region(rank)] {
		return new Array[Region(rank)](pg.numPlaces(), (i:int)=>blockRegionForPlace(pg(i))).sequence();
	}

	public def get(p:Place):Region(rank) {
		if (p == here) {
			if (regionForHere == null) {
				regionForHere = blockRegionForPlace(here);
			}
			return regionForHere;
		} else {
			return blockRegionForPlace(p);
		}
	}

	public operator this(pt:Point(rank)):Place {
		if (CompilerFlags.checkBounds() && !region.contains(pt)) raiseBoundsError(pt);
		return mapIndexToPlace(pt(axis));
	}

	public operator this(i0:int){rank==1}:Place {
		if (CompilerFlags.checkBounds() && !region.contains(i0)) raiseBoundsError(i0);
		return mapIndexToPlace(i0);
	}

	public operator this(i0:int, i1:int){rank==2}:Place {
		if (CompilerFlags.checkBounds() && !region.contains(i0, i1)) raiseBoundsError(i0,i1);
		switch(axis) {
			case 0: return mapIndexToPlace(i0);
			case 1: return mapIndexToPlace(i1);
			default: return here; // UNREACHABLE
		}
	}

	public operator this(i0:int, i1:int, i2:int){rank==3}:Place {
		if (CompilerFlags.checkBounds() && !region.contains(i0, i1, i2)) raiseBoundsError(i0,i1,i2);
		switch(axis) {
			case 0: return mapIndexToPlace(i0);
			case 1: return mapIndexToPlace(i1);
			case 2: return mapIndexToPlace(i2);
			default: return here; // UNREACHABLE
		}
	}

	public operator this(i0:int, i1:int, i2:int, i3:int){rank==4}:Place {
		if (CompilerFlags.checkBounds() && !region.contains(i0, i1, i2, i3)) raiseBoundsError(i0,i1,i2,i3);
		switch(axis) {
			case 0: return mapIndexToPlace(i0);
			case 1: return mapIndexToPlace(i1);
			case 2: return mapIndexToPlace(i2);
			case 3: return mapIndexToPlace(i3);
			default: return here; // UNREACHABLE
		}
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
		return new WrappedDistRegionRestricted(this, r) as Dist(rank); // TODO: cast should not be needed
	}

	public def restriction(p:Place):Dist(rank) {
		return new WrappedDistPlaceRestricted(this, p) as Dist(rank); // TODO: cast should not be needed
	}

	public def equals(thatObj:Any):boolean {
		if (this == thatObj) return true;
		if (!(thatObj instanceof PEBlockDist)) return super.equals(thatObj);
		val that = thatObj as PEBlockDist;
		return this.axis.equals(that.axis) && this.region.equals(that.region);
	}

}


/* vim: set noexpandtab */
