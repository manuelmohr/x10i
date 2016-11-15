package invasic.actor.qualities;

import x10.lang.String;

public class Power extends QualityNumber {
    val value: int;
    val unit: String;

    public def this(value: int, unit: String) {
        this.value = value;
        this.unit = unit;
    }
}
