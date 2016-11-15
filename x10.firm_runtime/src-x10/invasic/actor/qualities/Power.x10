package op.qualities;

import x10.lang.Pointer;
import x10.lang.String;

public class Power extends QualityNumber {
    val value: int;
    val unit: String;

    public def toAgentFormat(qualityNumber: Pointer) {
        QualityNumber.set_type(qualityNumber, 123);
        QualityNumber.set_value(qualityNumber, value);
    }

    public def this(value: int, unit: String) {
        this.value = value;
        this.unit = unit;
    }
}
