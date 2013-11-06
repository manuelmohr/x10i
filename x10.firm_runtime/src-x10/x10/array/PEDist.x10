/**
*******************************************************************************
* \file PEDist.x10
*
* \brief Implementation of class PEDist
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
import invasic.ProcessingElement;

public abstract class PEDist extends Dist {
	protected def this(region:Region) {
		super(region);
	}

	public static def makePEBlock(r:Region, axis:int, pes:List[ProcessingElement]):PEDist(r) {
		return new PEBlockDist(r, axis, pes) as PEDist(r);
	}

	abstract public def restriction(pe: ProcessingElement): Dist(rank);
	abstract public def get(pe: ProcessingElement): Region(rank);
	abstract public def pes():List[ProcessingElement];

	public operator this | (pe: ProcessingElement): Dist(rank) = restriction(pe);
	public operator this(pe: ProcessingElement): Region(rank) = get(pe);

	public def toString():String {
		var s:String = "PEDist(";
		var first:boolean = true;
		for (pe:ProcessingElement in pes()) {
			if (!first) s += ",";
			s +=  "" + get(pe) + "->" + pe;
			first = false;
		}
		s += ")";
		return s;
	}
}
public type PEDist(r:Int) = PEDist{self.rank==r};
public type PEDist(r:Region) = PEDist{self.region==r};
public type PEDist(d:Dist) = PEDist{self==d};

/* vim: set noexpandtab */
