package invasic.actor;

import invasic.actor.tiletypes.TileType;
import x10.lang.Pointer;
import x10.compiler.LinkSymbol;
import x10.util.ArrayList;
import x10.util.List;

public class ConstraintGraph {
    val clusters = new ArrayList[Cluster]();
    val channels = new ArrayList[AbstractChannel]();
    val actorgraph:IActorGraph;

    public def this(actorgraph:IActorGraph) {
      this.actorgraph = actorgraph;
    }

    public def addCluster(id: int, actors: List[IActor], tileType: TileType):Cluster {
      val c = new Cluster(id, actors, tileType);
      clusters.add(c);
      return c;
    }

    public def getCluster(id: int) {
      return clusters(id);
    }

    public def addInterconnects(source: Cluster, dest: Cluster, channels:List[AbstractChannel], hopDistance: int, serviceLevel: int) {
      // FIXME
    }
}
