package invasic.actor;

import invasic.actor.tiletypes.TileType;
import x10.lang.Pointer;
import x10.compiler.LinkSymbol;
import x10.util.List;

public class Cluster {
    val id: int;
    val tileType: TileType;
    val actors: List[IActor];

    public def this(id: int, actors: List[IActor], tileType: TileType) {
        this.id = id;
        this.tileType = tileType;
        this.actors = actors;
    }

    public def getId() {
        return id;
    }

    public def getActors() = actors;
}
