package op;

import op.tiletypes.TileType;
import x10.lang.Pointer;
import x10.compiler.LinkSymbol;
import x10.util.ArrayList;

public class Cluster {
    val id: int;
    val tileType: TileType;
    var actors: ArrayList[int];

    @LinkSymbol("cluster_create")
    static public native def create_native(): Pointer;
    @LinkSymbol("cluster_delete")
    static public native def delete_native(cluster: Pointer): void;
    @LinkSymbol("cluster_debug_print")
    static public native def debug_print(cluster: Pointer): void;

    @LinkSymbol("cluster_set_id")
    static native def set_id(cluster: Pointer, id: int): void;
    @LinkSymbol("cluster_set_actor_count")
    static native def set_actor_count(cluster: Pointer, count: int): void;
    @LinkSymbol("cluster_set_actor")
    static native def set_actor(cluster: Pointer, index: int, id: int): void;
    @LinkSymbol("cluster_set_tile_type")
    static native def set_tile_type(cluster: Pointer, tileType: Pointer): void;

    public def this(id: int, actors: Array[int](1), tileType: TileType) {
        this.id = id;
        this.tileType = tileType;
        this.actors = new ArrayList[int]();
        for (actor in actors.values()) {
            this.actors.add(actor);
        }
    }

    public def toAgentCluster(cluster: Pointer) {
        set_id(cluster, id);
        set_actor_count(cluster, actors.size());
        var i: int = 0;
        for (actorId in actors) {
            set_actor(cluster, i, actorId);
            ++i;
        }

        val tileTypePointer = TileType.create_native();
        tileType.toAgentTileType(tileTypePointer);
        set_tile_type(cluster, tileTypePointer);
    }

    public def getId() {
        return id;
    }
}
