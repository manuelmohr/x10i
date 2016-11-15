package invasic.actor;

import invasic.actor.tiletypes.TileType;
import x10.lang.Pointer;
import x10.compiler.LinkSymbol;
import x10.util.ArrayList;

public class ConstraintGraph {
    val clusters = new ArrayList[Cluster]();
    val channels = new ArrayList[Channel]();
    val actorgraph:Any;

    public def this(actorgraph:Any) {
      this.actorgraph = actorgraph;
    }

    public def addCluster(id: int, actors: Any, tileType: TileType):Cluster {
      val c = new Cluster(id, actors, tileType);
      clusters.add(c);
      return c;
    }

    public def getCluster(id: int) {
      return clusters(id);
    }

    public def addInterconnects(source: Cluster, dest: Cluster, channels:Any, hopDistance: int, serviceLevel: int) {
      // FIXME
    }
}
