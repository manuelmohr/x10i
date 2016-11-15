package op;

import op.qualities.QualityNumber;
import x10.lang.Pointer;
import x10.compiler.LinkSymbol;
import x10.util.ArrayList;
import x10.util.List;

public class OperatingPoint {
    val constraintGraph: ConstraintGraph;
    val qualityNumbers: ArrayList[QualityNumber];

    @LinkSymbol("operating_point_create")
    public static native def create_native(): Pointer;
    @LinkSymbol("operating_point_delete")
    public static native def delete_native(graph: Pointer): void;
    @LinkSymbol("operating_point_debug_print")
    public static native def debug_print(graph: Pointer): void;

    @LinkSymbol("operating_point_set_constraint_graph")
    static native def set_constraint_graph(operatingPoint: Pointer, constraintGraph: Pointer): void;
    @LinkSymbol("operating_point_set_quality_number_count")
    static native def set_quality_number_count(operatingPoint: Pointer, count: int): void;
    @LinkSymbol("operating_point_get_quality_number")
    static native def get_quality_number(operatingPoint: Pointer, index: int): Pointer;

    public def this(constraintGraph: ConstraintGraph, qualityNumbers: List[QualityNumber]) {
        this.constraintGraph = constraintGraph;
        this.qualityNumbers = ArrayList.make[QualityNumber](qualityNumbers);
    }

    public def toAgentFormat(op: Pointer) {
        val constraintGraphPointer = ConstraintGraph.create_native();
        constraintGraph.toAgentFormat(constraintGraphPointer);
        set_constraint_graph(op, constraintGraphPointer);

        set_quality_number_count(op, qualityNumbers.size());
        var i: int = 0;
        for (qualityNumber in qualityNumbers) {
            val qualityNumberPointer = get_quality_number(op, i++);
            qualityNumber.toAgentFormat(qualityNumberPointer);
        }
    }
}
