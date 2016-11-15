package invasic.actor;

import invasic.actor.qualities.QualityNumber;
import x10.lang.Pointer;
import x10.compiler.LinkSymbol;
import x10.util.Set;

public class OperatingPoint {
    val constraintGraph: ConstraintGraph;
    val qualityNumbers: Set[QualityNumber];
    val actorgraph: Any;

    public def this(constraintGraph: ConstraintGraph, qualityNumbers: Set[QualityNumber], actorgraph:Any) {
        this.constraintGraph = constraintGraph;
        this.qualityNumbers = qualityNumbers;
        this.actorgraph = actorgraph;
    }

    public def getActorGraph():Any {
        return this.actorgraph;
    }

    public def getCluster(p:Place):Cluster {
        return constraintGraph.getCluster(p.id);
    }
}
