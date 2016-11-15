package op;

import op.tiletypes.TileType;
import x10.lang.Pointer;
import x10.compiler.LinkSymbol;
import x10.util.ArrayList;

public class ConstraintGraph {
    var clusters: ArrayList[Cluster];
    var channels: ArrayList[Channel];

    public def this() {
        clusters = new ArrayList[Cluster]();
        channels = new ArrayList[Channel]();
    }

    @LinkSymbol("constraint_graph_create")
    public static native def create_native(): Pointer;
    @LinkSymbol("constraint_graph_delete")
    public static native def delete_native(graph: Pointer): void;
    @LinkSymbol("constraint_graph_debug_print")
    public static native def debug_print(graph: Pointer): void;

    @LinkSymbol("constraint_graph_set_cluster_count")
    static native def set_cluster_count(graph: Pointer, count: int): void;
    @LinkSymbol("constraint_graph_set_channel_count")
    static native def set_channel_count(graph: Pointer, count: int): void;
    @LinkSymbol("constraint_graph_get_cluster")
    static native def get_cluster(graph: Pointer, index: int): Pointer;
    @LinkSymbol("constraint_graph_get_channel")
    static native def get_channel(graph: Pointer, index: int): Pointer;

    public def toAgentFormat(graph: Pointer) {
        set_cluster_count(graph, clusters.size());
        set_channel_count(graph, channels.size());

        for(var i:int = 0; i < clusters.size(); ++i) {
            val cluster = get_cluster(graph, i); 
            clusters(i).toAgentCluster(cluster);
        }

        for(var i:int = 0; i < channels.size(); ++i) {
            val channel = get_channel(graph, i); 
            channels(i).toAgentChannel(channel);
        }
    }

    public def addCluster(id: int, actors: Array[int](1), tileType: TileType) {
        val cluster = new Cluster(id, actors, tileType);
        clusters.add(cluster);
        return cluster;
    }

    public def addChannel(source: Cluster, destination: Cluster, hopDistance: int, serviceLevel: int) {
        val channel = new Channel(source, destination, hopDistance, serviceLevel);
        channels.add(channel);
        return channel;
    }
}
