package invasic.util.queue;

import invasic.Claim;
import invasic.constraints.Constraint;
import x10.util.List;

/**
 * Builder class for the distributed job queue framework.
 */
public class JobQueueFrameworkBuilder[T, X] {T isref, T haszero, X haszero} {
	private var doAutomaticReinvades:Boolean = false;
	private var reinvadeTime:Int = 250; // value in ms
	private var claim:Claim = null;
	private val constraint:Constraint;
	private var initialWork:List[T] = null;
	private var localStealPolicy:Int = 5;
	private var remoteStealPolicy:Int = 0;
	private var targetIletRestartTime:Int = -1; // value in ms
	
	/**
	 * Constructor.
	 */
	public def this(constraint:Constraint) {
		this.constraint = constraint;
	}
	
	/**
	 * Set the given initial work for the job queue framework.
	 */
	public def setWorkList(initialWork:List[T]):JobQueueFrameworkBuilder[T, X] {T isref, T haszero, X haszero} {
		this.initialWork = initialWork;
		return this;
	}
	
	/**
	 * Set the given claim for the job queue framework.
	 */
	public def setClaim(claim:Claim):JobQueueFrameworkBuilder[T, X] {T isref, T haszero, X haszero} {
		this.claim = claim;
		return this;
	}
	
	/**
	 * Set the given local stealing policy for the job queue framework.
	 */
	public def setLocalStealPolicy(localStealPolicy:Int):JobQueueFrameworkBuilder[T, X] {T isref, T haszero, X haszero} {
		this.localStealPolicy = localStealPolicy;
		return this;
	}
	
	/**
	 * Set the given remote stealing policy for the job queue framework.
	 */
	public def setRemoteStealPolicy(remoteStealPolicy:Int):JobQueueFrameworkBuilder[T, X] {T isref, T haszero, X haszero} {
		this.remoteStealPolicy = remoteStealPolicy;
		return this;
	}
	
	/**
	 * Set if the job queue framework should perform automatic reinvades at the given reinvadeTime intervals in ms.
	 */
	public def setAutomaticReinvades(doAutomaticReinvades:Boolean, reinvadeTime:Int):JobQueueFrameworkBuilder[T, X] {T isref, T haszero, X haszero} {
		this.doAutomaticReinvades = doAutomaticReinvades;
		this.reinvadeTime = reinvadeTime;
		return this;
	}
	
	/**
	 * Set if the job queue framework should perform automatic reinvades..
	 */
	public def setAutomaticReinvades(doAutomaticReinvades:Boolean):JobQueueFrameworkBuilder[T, X] {T isref, T haszero, X haszero} {
		this.doAutomaticReinvades = doAutomaticReinvades;
		return this;
	}
	
	/**
	 * Set the target restart time for each ilet in ms.
	 */
	public def setIletRestartTime(targetIletRestartTime:Int) {
		this.targetIletRestartTime = targetIletRestartTime;
		return this;
	}
	
	/**
	 * Build a distributed job queue framework with all the set parameters.
	 */
	public def build() : DistributedQueueFramework[T, X]{T isref, T haszero, X haszero} {
		val claim = this.claim == null ? Claim.getCurrent() : this.claim;
		if(initialWork == null) {
			return new DistributedQueueFramework[T, X](claim, constraint, doAutomaticReinvades, localStealPolicy, 
					remoteStealPolicy, targetIletRestartTime, reinvadeTime);
		} else {
			return new DistributedQueueFramework[T, X](claim, constraint, initialWork, doAutomaticReinvades, localStealPolicy, 
					remoteStealPolicy, targetIletRestartTime, reinvadeTime);
		}
	}
}