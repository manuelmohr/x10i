/**
 *******************************************************************************
 * \file WrappedDistPERestricted.x10
 *
 * \brief Implementation of class WrappedDistPERestricted
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

import x10.util.List;
import x10.util.ArrayList;
import invasic.ProcessingElement;

final class WrappedDistPERestricted extends PEDist {
	val base:Dist{self.rank==this.rank};
	val filterPE:ProcessingElement;

	// **************************************************************************
	// *** Constructor ***
	// **************************************************************************
	def this(d:PEDist, pe:ProcessingElement): WrappedDistPERestricted {
		super(d.get(pe));
		base = d as Dist{self.rank==this.rank}; // cast should not be needed
		filterPE = pe;
	}

	// **************************************************************************
	// *** New methods ***
	// **************************************************************************
	public def restriction(pe: ProcessingElement): Dist(rank) {
		if (pe == filterPE) {
			return this;
		} else {
			return Dist.make(Region.makeEmpty(rank));
		}
	}

	public def get(pe: ProcessingElement): Region(rank) {
		if (pe == filterPE) {
			return region;
		} else {
			return Region.makeEmpty(rank);
		}
	}

	public def pes(): List[ProcessingElement] {
		val arr = new ArrayList[ProcessingElement]();
		arr.add(filterPE);
		return arr;
	}

	// **************************************************************************
	// *** Methods from Dist ***
	// **************************************************************************
	public def places():PlaceGroup = new SparsePlaceGroup(filterPE.getPlace());

	public def numPlaces() = 1;

	public def regions():Sequence[Region(rank)] {
		return new Array[Region(rank)](1, (int)=>region).sequence();
	}

	public def get(p:Place):Region(rank) {
		if (p == filterPE.getPlace()) {
			return region;
		} else {
			return Region.makeEmpty(rank);
		}
	}

	public operator this(pt:Point(rank)):Place {
		val bp = base(pt);
		if (bp == filterPE.getPlace()) {
			return bp;
		} else {
			throw new ArrayIndexOutOfBoundsException("point " + pt + " not contained in distribution");
		}
	}

	public def offset(pt:Point(rank)):int {
		if (here == filterPE.getPlace()) {
			return base.offset(pt);
		} else {
			throw new ArrayIndexOutOfBoundsException("point " + pt + " not contained in distribution");
		}
	}

	public def maxOffset():int = base.maxOffset();

	public def restriction(r:Region(rank)): Dist(rank) {
		return new WrappedDistRegionRestricted(this, r) as Dist(rank); // TODO cast should not be needed
	}

	public def restriction(p:Place): Dist(rank) {
		if (p == filterPE.getPlace()) {
			return this;
		} else {
			return Dist.make(Region.makeEmpty(rank));
		}
	}

	public def equals(thatObj:Any): boolean {
		if (!(thatObj instanceof WrappedDistPERestricted)) return false;
		val that = thatObj as WrappedDistPERestricted;
		return this.base.equals(that.base) && this.filterPE.equals(that.filterPE);
	}
}

/* vim: set noexpandtab */
