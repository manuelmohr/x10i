package op;

import x10.lang.Pointer;
import x10.compiler.LinkSymbol;
import x10.util.ArrayList;

public class Channel {
    val source: Cluster;
    val destination: Cluster;
    val hopDistance: int;
    val serviceLevel: int;

    @LinkSymbol("channel_create")
    static public native def create_native(): Pointer;
    @LinkSymbol("channel_delete")
    static public native def delete_native(channel: Pointer): void;
    @LinkSymbol("channel_debug_print")
    static public native def debug_print(channel: Pointer): void;

    @LinkSymbol("channel_set_source")
    static native def set_source(channel: Pointer, source: int): void;
    @LinkSymbol("channel_set_destination")
    static native def set_destination(channel: Pointer, destination: int): void;
    @LinkSymbol("channel_set_hop_distance")
    static native def set_hop_distance(channel: Pointer, hopDistance: int): void;
    @LinkSymbol("channel_set_service_level")
    static native def set_service_level(channel: Pointer, serviceLevel: int): void;

    public def this(source: Cluster, destination: Cluster, hopDistance: int, serviceLevel: int) {
        this.source = source;
        this.destination = destination;
        this.hopDistance = hopDistance;
        this.serviceLevel = serviceLevel;
    }

    public def toAgentChannel(channel: Pointer) {
        set_source(channel, source.getId());
        set_destination(channel, destination.getId());
        set_hop_distance(channel, hopDistance);
        set_service_level(channel, serviceLevel);
    }
}
