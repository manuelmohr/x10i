package invasic.actor;

import x10.util.List;

import invasic.actor.qualities.QualityNumber;
import invasic.actor.OperatingPoint;
import invasic.Claim;

public class Binding {
	val claim:Claim;
	val operatingPoint:OperatingPoint;

	public def this(claim:Claim, operatingPoints:List[OperatingPoint]) {
		this.claim = claim;
		assert (claim.getOperatingPointIndex() >= 0);
		assert (claim.getOperatingPointIndex() < operatingPoints.size);
		this.operatingPoint = operatingPoints(claim.getOperatingPointIndex());
	}

	public def infect() {
		val actorGraph = this.operatingPoint.getActorGraph();
		for(p in this.claim.places()) {
			val cluster = actorgraph.getCluster(p.id);
			for(actor in cluster.actors()) {
				actorGraph.moveActor(actor, p);
			}
		}
		finish actorGraph.start();
	}
}
