package invasic;

import x10.lang.Pointer;
import x10.compiler.LinkSymbol;

/** A processing element executes i-lets and represents a hardware core */
public class ProcessingElement {
    private val clm:Pointer;
    private val plc:Place;
    private val peid:Int;

    public static val DEFECT = 0 as Int;
    public static val LEON   = 1 as Int;
    public static val ICORE  = 2 as Int;
    public static val TCPA   = 3 as Int;

    public def this(clm:Pointer, plc:Place, peid:Int) {
        this.clm = clm;
        this.plc = plc;
        this.peid = peid;
    }

    public def toString(): String {
        return "<PE: " + plc + " pe=" + peid + ">";
    }

    /** Returns place of the PE */
    public def getPlace():Place {
        return plc;
    }

    public def equals(pe:Any) {
        val pe1 = pe as ProcessingElement;
        if (pe1 == null) return false;
        return this.plc == pe1.plc && this.peid == pe1.peid;
    }

    @LinkSymbol("get_cpu_id")
    static native public def currentCPU():int;
}
