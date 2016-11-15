package op.qualities;

import x10.lang.Pointer;
import x10.compiler.LinkSymbol;

abstract public class QualityNumber {
    abstract public def toAgentFormat(qualityNumber: Pointer): void;

    @LinkSymbol("quality_number_create")
    static public native def create_native(): Pointer;
    @LinkSymbol("quality_number_create")
    static public native def delete_native(tileType: Pointer): void;
    @LinkSymbol("quality_number_set_type")
    static public native def set_type(tileType: Pointer, typeId: int): void;
    @LinkSymbol("quality_number_set_value")
    static public native def set_value(tileType: Pointer, typeId: int): void;
}
