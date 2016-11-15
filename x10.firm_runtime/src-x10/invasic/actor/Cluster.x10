package invasic.actor;

import invasic.actor.tiletypes.TileType;
import x10.lang.Pointer;
import x10.compiler.LinkSymbol;
import x10.util.ArrayList;

public class Cluster {
    val id: int;
    val tileType: TileType;
    val actors: Any;

    public def this(id: int, actors: Any, tileType: TileType) {
        this.id = id;
        this.tileType = tileType;
        this.actors = actors;
    }

    public def getId() {
        return id;
    }

    public def getActors() = actors;
}
