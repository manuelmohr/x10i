package invasic.constraints;

import x10.compiler.LinkSymbol;

import x10.util.List;

/** Specifies the scalability of the algorithm, which should be processed by the claims resources. */
public class ScalabilityHint extends Hint {
    private val curve:Array[int];

    // TODO some implementation ... currently we ignore it, since it is just a hint
    public def this(scalability:Array[int]) {
        this.curve = scalability;
    }

    public def this(a:int, b:int, c:int) {
        // FIXME compute the Array for now
        throw new UnsupportedOperationException("Not implemented yet");
    }

    public def apply(constr:Pointer) {
        val size = this.curve.size;
        val data = this.curve.raw().pointer();
        //set_curve(constr, data, size); TODO not implemented in iRTSS yet
    }

    /*
    @LinkSymbol("agent_constr_set_curve")
    static native def set_curve(constr:Pointer, vector:Pointer, size:Int):void;
    */
}
