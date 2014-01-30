package invasic;

import x10.lang.Pointer;
import x10.compiler.LinkSymbol;

/** A processing element executes i-lets and represents a hardware core */
public class ProcessingElement {
    private val clm:Pointer;
    private val tileid:Int;
    private val petype:Int;
    private val peid:Int;

    public static val DEFECT = 0 as Int;
    public static val LEON   = 1 as Int;
    public static val ICORE  = 2 as Int;
    public static val TCPA   = 3 as Int;

    public def this(clm:Pointer, tileid:Int, petype:Int, peid:Int) {
        this.clm = clm;
        this.tileid = tileid;
        this.petype = petype;
        this.peid = peid;
    }

    public def toString(): String {
        return "<PE: tile=" + tileid + " pe=" + peid + " type="+petype+">";
    }

    /** Returns place of the PE */
    public def getPlace():Place {
        return new Place(tileid);
    }

    public def equals(pe:Any) {
        val pe1 = pe as ProcessingElement;
        if (pe1 == null) return false;
        return this.tileid == pe1.tileid && this.peid == pe1.peid;
    }

    @LinkSymbol("get_cpu_id")
    static native public def currentCPU():int;
}
