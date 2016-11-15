package op.tiletypes;

import x10.lang.Pointer;

public class RISC extends TileType {
    public def toAgentTileType(tileType: Pointer) {
        TileType.set_type(tileType, 123);
    }

    public def this() { }
}
