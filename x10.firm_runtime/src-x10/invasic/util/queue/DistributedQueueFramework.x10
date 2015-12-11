package invasic.util.queue;

import invasic.Claim;
import invasic.IncarnationID;
import invasic.ProcessingElement;
import invasic.Tile;
import invasic.constraints.Constraint;
import invasic.constraints.PEQuantity;
import invasic.constraints.TileSharing;
import invasic.util.InfectType;
import invasic.util.PlaceSequence;
import octopos.Memory;
import x10.compiler.NonEscaping;
import x10.compiler.TLMAllocate;
import x10.compiler.Volatile;
import x10.io.CustomSerialization;
import x10.io.SerialData;
import x10.util.ArrayList;
import x10.util.Collection;
import x10.util.HashMap;
import x10.util.HashSet;
import x10.util.List;
import x10.util.Set;
import x10.util.Random;
import x10.util.concurrent.AtomicInteger;
import x10.util.concurrent.Monitor;
import x10.util.IndexedMemoryChunk;

/**
 * Framework to execute independent jobs on any number of PEs and on any number of places.
 * Can be configured to change the number of PEs and places at runtime.
 */
public class DistributedQueueFramework[T, X]{T isref, T haszero, X haszero} implements CustomSerialization {
	
	private static val random = new Random();
	
	/* only used on the 'home' tile because the agent is only valid on the tile where the claim was created */
 	private var claim:Claim;
	private var constraint:Constraint;
	private val averageTimePerJob = IndexedMemoryChunk.allocateZeroed[Float](Tile.getTileCoreCount() as Int);
	
	/* storage for late creation of new doWork() i-lets */
	private var infectType:Int = -1;
	private var work:(job:T) => void;
	private var workReduce:(job:T) => X;
	private var reduce:(X,X)=>X;
	private var nextId:Int = -1;
	
	/* cache for the plh */
	private var localQueueFramework:PlaceLocalQueueFramework[T, X];
	
	/* serialized values */
	private val plh:PlaceLocalHandle[PlaceLocalQueueFramework[T, X]]{PlaceLocalQueueFramework[T, X] haszero, PlaceLocalQueueFramework[T, X] isref};
	private val doAutomaticReinvades:Boolean;
	private var targetILetRestartTime:Int;
	private val reinvadeTime:Int;
	private var measuredAtTime:Int;

	/**
	 * Creates a new distributed queue framework with the given constraints.
	 * The queue framework will reinvade the given claim and run inside of it.
	 */
	def this(claim:Claim, constraint:Constraint, doAutomaticReinvades:Boolean, localStealPolicy:Int, 
			remoteStealPolicy:Int, targetILetRestartTime:Int, reinvadeTime:Int) {
		initialize(claim, constraint, targetILetRestartTime);
		this.reinvadeTime = reinvadeTime;
		this.doAutomaticReinvades = doAutomaticReinvades;
		val pes = claim.processingElements();
		val places = PlaceGroup.getWorld();
		val pesPerPlace = getPesPerPlace(pes, places);
		plh = PlaceLocalHandle.makeFlat[PlaceLocalQueueFramework[T, X], InitializationData[T]](places, (p:Place) 
				=> InitializationData[T](pesPerPlace(places.indexOf(p)), new ArrayList[T](), localStealPolicy, remoteStealPolicy), 
				(u:InitializationData[T]) => new PlaceLocalQueueFramework[T, X](u.pes, u.initialWork, u.localStealPolicy, u.remoteStealPolicy));
		localQueueFramework = plh();
	}
	
	/**
	 * Creates a new distributed queue framework with the given constraints and the given amount of
	 * available work.
	 * The queue framework will reinvade the given claim and run inside of it.
	 * The given work will be distributed among all available places and pes with each pe getting roughly the
	 * same amount of work.
	 */
	def this(claim:Claim, constraint:Constraint, initialWork:List[T], doAutomaticReinvades:Boolean, localStealPolicy:Int, 
			remoteStealPolicy:Int, targetILetRestartTime:Int, reinvadeTime:Int) {
		initialize(claim, constraint, targetILetRestartTime);
		this.reinvadeTime = reinvadeTime;
		this.doAutomaticReinvades = doAutomaticReinvades;
		val pes = claim.processingElements();
		val places = PlaceGroup.getWorld();
		val pesPerPlace = getPesPerPlace(pes, places);
		val workPerPlace = getWorkPerPlace(pes, places, pesPerPlace, initialWork);
		plh = PlaceLocalHandle.makeFlat[PlaceLocalQueueFramework[T, X], InitializationData[T]](places, (p:Place) 
				=> InitializationData[T](pesPerPlace(places.indexOf(p)),workPerPlace.get(p)(), localStealPolicy, remoteStealPolicy), 
				(u:InitializationData[T]) => new PlaceLocalQueueFramework[T, X](u.pes, u.initialWork, u.localStealPolicy, u.remoteStealPolicy));
		localQueueFramework = plh();
	}
	
	/**
	 * Deserialization.
	 */
	public def this(serialData:SerialData) {
		plh = serialData.data as PlaceLocalHandle[PlaceLocalQueueFramework[T, X]];
		doAutomaticReinvades = serialData.superclassData.data as Boolean;
		targetILetRestartTime = serialData.superclassData.superclassData.data as Int;
		reinvadeTime = serialData.superclassData.superclassData.superclassData.data as Int;
		measuredAtTime = serialData.superclassData.superclassData.superclassData.superclassData.data as Int;
		localQueueFramework = plh();
	}
	
	@NonEscaping
	private final def initialize(claim:Claim, constraint:Constraint, targetILetRestartTime:Int) {
		val c = constraint && new TileSharing();
		this.claim = claim;
		this.claim.reinvade(c);
		this.constraint = c;
		val places = PlaceGroup.getWorld();
		if(places.size() > 1) {
			val index = places.indexOf(here) < places.size() - 1 ? places.indexOf(here) + 1 : 0;
			this.measuredAtTime = measureAtTime(places(index));
		}
		this.targetILetRestartTime = targetILetRestartTime;
	}
	
	/**
	 * Returns an array which i's coordinate will hold the number of PEs for that specific place in the place group.
	 */
	private static def getPesPerPlace(pes:Collection[ProcessingElement], places:PlaceGroup) : Array[Int](1) {
		val pesPerPlace = new Array[Int](Tile.getComputeTileCount() as Int);
		for(pe in pes) {
			val index = places.indexOf(pe.getPlace());
			pesPerPlace(index) += 1;
		}
		return pesPerPlace;
	}
	
	/**
	 * Returns a map from place to the list of jobs that should be distributed to that place.
	 */
	private static def getWorkPerPlace[T](pes:Collection[ProcessingElement], places:PlaceGroup, pesPerPlace:Array[Int](1), initialWork:List[T]) : HashMap[Place, List[T]] {
		val workPerPlace = new HashMap[Place, List[T]]();
		val workSize = initialWork.size();
		for(val p in places) {
			val index = places.indexOf(p);
			val workThisPlace = (pesPerPlace(index) as Float / pes.size() as Float) * workSize as Float;
			val work = new ArrayList[T](workThisPlace as Int + 1);
			for(var i:Int = 0; i < Math.floor(workThisPlace); i++) {
				work.add(initialWork.removeFirst());
			}
			workPerPlace.put(p, work);
		}
		var i:Int = 0;
		for(val job in initialWork) {
			val place = places(i++);
			workPerPlace.get(place)().add(job);
		}
		assert(initialWork.size() == i) : "Not all jobs were distributed.\n " + (initialWork.size() - i) + " jobs left.";
		initialWork.clear();
		return workPerPlace;
	}
	
	private final def initializeIlets(infectType:Int, peCount:Int, work:(job:T)=>void, claim:Claim, constraint:Constraint) {
		initializeIlets(infectType, peCount, claim, constraint);
		this.work = work;
	}
	
	private final def initializeIlets(infectType:Int, peCount:Int, work:(job:T)=>X, reduce:(X,X)=>X, claim:Claim, constraint:Constraint) {
		initializeIlets(infectType, peCount, claim, constraint);
		this.workReduce = work;
		this.reduce = reduce;
	}
	
	private final def initializeIlets(infectType:Int, peCount:Int, claim:Claim, constraint:Constraint) {
		this.infectType = infectType;
		nextId = peCount;
		this.claim = claim;
		this.constraint = constraint;
	}
	
	private static def measureAtTime(place:Place):Int {
		// measure the time the system needs for an 'at' with serialization
		var time:Long;
		do {
			val dummyList = new ArrayList[Int]();
			for(n in 1..10)
				dummyList.add(n);
			val start = System.nanoTime();
			val result = at(place) {
				val returnList = new ArrayList[Int]();
				for(i in dummyList) {
					returnList.add(i);
				}
				return returnList;
			};
			time = System.nanoTime() - start;
		} while(time < 0);
		return time as Int;
	}
	
	private def getBatchSize(avgTime:Float):Int {
		return (getRestartTime() / avgTime) as Int;
	}
	
	private def getNumberOfContinousRuns(avgTime:Float) {
		if(!doAutomaticReinvades) return Int.MAX_VALUE;
		var numberOfRuns:Double = reinvadeTime / 4 / (avgTime / 1000000); // run for 25% of the reinvade time without interruptions
		return numberOfRuns < 1 ? 1 : numberOfRuns as Int;
	}
	
	private def getRestartTime():Int {
		if(targetILetRestartTime > 0)
			return targetILetRestartTime * 1000000;
		return measuredAtTime * 4 as Int;
	}
	
	/* starting & restarting of activites */
	
	/**
	 * Starts the queue framework with the given function for executing a job.
	 */
	public def start(work:(job:T) => void) {
		if(claim == null)
			throw new BadPlaceException();
		if(plh().globalFinished)
			resetQueueFramework();
		claim.infect(createLoop(work));
	}
	
	/**
	 * Starts the queue framework with the given function for executing a job.
	 * The reduce function will be used for the reduction of each jobs return value.
	 */
	public def start(work:(job:T) => X, reduce:(X, X) => X) : X {
		if(claim == null)
			throw new BadPlaceException();
		if(plh().globalFinished)
			resetQueueFramework();
		claim.infect(createLoop(work, reduce));
		var result:X = Zero.get[X]();
		for(p in PlaceGroup.getWorld()) {
			val current = result;
			result = at(p) {
				val handle = plh();
				if(handle == null)
					return Zero.get[X]();
				var placeLocalResult:X = current;
				for(var i:Int = 0; i < handle.results.length(); i++) {
					placeLocalResult = reduce(placeLocalResult, handle.results(i));
				}
				return placeLocalResult;
			};
		}
		return result;
	}
	
	private def createLoop(work:(job:T) => void) : (id:IncarnationID) => void {
		val peCount = claim.size();
		val claim = this.claim;
		val constraint = this.constraint;
		val nIlet:(id:IncarnationID) => void;
		nIlet = (id:IncarnationID) => {
			if(id.ordinal == 0)
				initializeIlets(InfectType.STANDARD_INFECT, peCount, work, claim, constraint);
			doInitialJobs(work, id);
		};
		return nIlet;
	}
	
	private def createLoop(work:(job:T) => X, reduce:(X,X) => X) : (id:IncarnationID) => void {
		val peCount = claim.size();
		val claim = this.claim;
		val constraint = this.constraint;
		val nIlet:(id:IncarnationID) => void;
		nIlet = (id:IncarnationID) => {
			if(id.ordinal == 0)
				initializeIlets(InfectType.REDUCE_INFECT, peCount, work, reduce, claim, constraint);
			doInitialJobs(work, reduce, id);
		};
		return nIlet;
	}
	
	private def doInitialJobs(work:(job:T) => void, id:IncarnationID) {
		val time = System.currentTimeMillis();
		var total:Long = 0;
		var initialRuns:Int = 20;
		
		for(var i:Int = 0; i < initialRuns; i++) {
			val job = this.get();
			if (job == Zero.get[T]())
				return;
			val now = System.nanoTime();
			work(job);
			val then = System.nanoTime();
			total += (then - now) < 0 ? total/(i+1) : then - now;
			if(doAutomaticReinvades && (total/1000000 > reinvadeTime / 2 || total/(i+1) > getRestartTime())) {
				initialRuns = i + 1;
				break;
			}
		}
		val avgTime = total as Float / initialRuns;
		val localActivities = localQueueFramework.localActivities;
		averageTimePerJob(ProcessingElement.currentCPU()) += avgTime;
		if(PlaceGroup.getWorld().size() > 1) {
			val batchSize = getBatchSize(avgTime);
			async doJobs(work, localActivities * (batchSize < 1 ? 1 : batchSize), id, time);
		} else {
			val runs = getNumberOfContinousRuns(avgTime);
			async doContinousJobs(work, runs, id, time);
		}
	}
	
	private def doInitialJobs(work:(job:T) => X, reduce:(X,X) => X, id:IncarnationID) {
		val time = System.currentTimeMillis();
		var total:Long = 0;
		var initialRuns:Int = 20;
		
		for(var i:Int = 0; i < initialRuns; i++) {
			val job = this.get();
			if (job == Zero.get[T]())
				return;
			val now = System.nanoTime();
			val result = work(job);
			localQueueFramework.addResult(result, reduce);
			val then = System.nanoTime();
			total += (then - now) < 0 ? total/(i+1) : then - now;
			if(doAutomaticReinvades && (total/1000000 > reinvadeTime / 2 || total/(i+1) > getRestartTime())) {
				initialRuns = i + 1;
				break;
			}
		}
		val avgTime = total as Float / initialRuns;
		val localActivities = localQueueFramework.localActivities;
		averageTimePerJob(ProcessingElement.currentCPU()) += avgTime;
		if(PlaceGroup.getWorld().size() > 1) {
			val batchSize = getBatchSize(avgTime);
			async doJobs(work, localActivities * (batchSize < 1 ? 1 : batchSize), reduce, id, time);
		} else {
			val runs = getNumberOfContinousRuns(avgTime);
			async doContinousJobs(work, reduce, runs, id, time);
		}
	}
	
	private def doContinousJobs(work:(job:T) => void, numberOfRuns:Int, id:IncarnationID, time:Long) {
		var currentTime:Long = time;
		while(true) {
			if(PlaceGroup.getWorld().size() > 1) {
				break;
			} else if(!localQueueFramework.globalFinished) {
				if(checkReinvade(time)) {
					if(perhapsRemoveActiviy()) return; // stop this activity due to reinvade
					waitForReinvade();
					if(perhapsRemoveActiviy()) return; // stop this activity due to reinvade
					currentTime = System.currentTimeMillis();
					continue;
				}
			}
			for(var i:Int = 0; i < numberOfRuns; i++) {
				val job = this.get();
				if (job == Zero.get[T]())
					return;
				work(job);
			}
		}
		async doInitialJobs(work, id);
	}
	
	private def doContinousJobs(work:(job:T) => X, reduce:(X,X) => X, numberOfRuns:Int, id:IncarnationID, time:Long) {
		var currentTime:Long = time;
		while(true) {
			if(PlaceGroup.getWorld().size() > 1) {
				break;
			} else if(!localQueueFramework.globalFinished) {
				if(checkReinvade(time)) {
					if(perhapsRemoveActiviy()) return; // stop this activity due to reinvade
					waitForReinvade();
					if(perhapsRemoveActiviy()) return; // stop this activity due to reinvade
					currentTime = System.currentTimeMillis();
					continue;
				}
			}
			for(var i:Int = 0; i < numberOfRuns; i++) {
				val job = this.get();
				if (job == Zero.get[T]())
					return;
				val result = work(job);
				localQueueFramework.addResult(result, reduce);
			}
		}
		async doInitialJobs(work, reduce, id);
	}
	
	private def doJobs(work:(job:T) => void, numberOfRuns:Int, id:IncarnationID, time:Long) {
		val thisTime:Long;
		if(checkReinvade(time)) {
			if(perhapsRemoveActiviy()) return; // stop this activity due to reinvade
			waitForReinvade();
			if(perhapsRemoveActiviy()) return; // stop this activity due to reinvade
			thisTime = System.currentTimeMillis();
		} else {
			thisTime = time;
		}
		
		for(var i:Int = 0; i < numberOfRuns; i++) {
			val job = this.get();
			if (job == Zero.get[T]())
				return;
			work(job);
		}
		async doJobs(work, numberOfRuns, id, thisTime);
	}

	private def doJobs(work:(job:T) => X, numberOfRuns:Int, reduce:(X,X) => X, id:IncarnationID, time:Long) {
		val thisTime:Long;
		if(checkReinvade(time)) {
			if(perhapsRemoveActiviy()) return; // stop this activity due to reinvade
			waitForReinvade();
			if(perhapsRemoveActiviy()) return; // stop this activity due to reinvade
			thisTime = System.currentTimeMillis();
		} else {
			thisTime = time;
		}	
	
		for(var i:Int = 0; i < numberOfRuns; i++) {
			val job = this.get();
			if (job == Zero.get[T]())
				return;
			val result = work(job);
			localQueueFramework.addResult(result, reduce);
		}
		async doJobs(work, numberOfRuns, reduce, id, thisTime);
	}
	
	/* reinvade */
	
	private def perhapsRemoveActiviy():Boolean {
		val handle = plh();
		handle.reinvadeMonitor.lock();
		if(handle.activitiesToRemove > 0) {
			handle.activitiesToRemove--;
			handle.reinvadeMonitor.unlock();
			localQueueFramework.monitor.lock();
			localQueueFramework.localFinishedCount = 0;
			localQueueFramework.monitor.release();
			return true;
		} else {
			handle.reinvadeMonitor.unlock();
			return false;
		}
	}

	private def waitForReinvade() {
		val handle = plh();
		handle.reinvadeMonitor.lock();
		if(claim != null && !handle.resizeInProgress) {
			if(handle.waitingActivities == 0) {
				handle.waitingActivities++;
				handle.reinvadeMonitor.unlock();
				val constraint = generateNewConstraint();
				reinvade(constraint);
			} else {
				// do not stop this activity yet
				handle.reinvadeMonitor.unlock();
			}
		} else {
			handle.waitingActivities++;
			handle.reinvadeMonitor.await();
			handle.reinvadeMonitor.unlock();
		}
	}
	
	private def checkReinvade(time:Long):Boolean {
		if(!doAutomaticReinvades) return false;
		val now = System.currentTimeMillis();
		val handle = plh();
		if((time + reinvadeTime < now && claim != null) || handle.resizeInProgress || handle.activitiesToRemove > 0)
			return true;
		return false;
	}
	
	private def prepareReinvade() {
		prepareReinvade(PlaceGroup.getWorld());
	}
	
	private def prepareReinvade(placeGroup:PlaceGroup) {
		val homePlace = here;
		finish for(place in placeGroup) {
			at(place) async {
				waitForAllActivities(homePlace);
			}
		}
	}
	
	private def waitForAllActivities(homePlace:Place) {
		val handle = plh();
		if(handle != null) {
			handle.monitor.lock();
			val waiting = handle.localFinishedCount == handle.localActivities ? handle.localFinishedCount - 1: handle.localFinishedCount;
			handle.monitor.unlock();
			handle.reinvadeMonitor.lock();
			if(handle.waitingActivities + waiting < handle.localActivities) {
				handle.reinvadeMonitor.unlock();
				async waitForAllActivities(homePlace);
			} else {
				handle.reinvadeMonitor.unlock();
			}
		} else {
			async waitForAllActivities(homePlace);
		}
	}
	
	private def continueAfterReinvade(placeGroup:PlaceGroup) {
		val serializedPlh = plh;
		finish for(place in placeGroup) {
			at(place) async {
				val handle = serializedPlh();
				releaseAllActivities[T, X](handle);
			}
		}
	}
	
	private def continueAfterReinvade() {
		continueAfterReinvade(PlaceGroup.getWorld());
	}
	
	private static def releaseAllActivities[T, X](handle:PlaceLocalQueueFramework[T, X]) {T isref, T haszero, X haszero} {
		if(handle != null) {
			handle.reinvadeMonitor.lock();
			handle.resizeInProgress = false;
			handle.waitingActivities = 0;
			handle.reinvadeMonitor.release();
		} else {
			async releaseAllActivities[T, X](handle);
		}
	}
	
	private def startResizingClaim() {
		val serializedPlh = plh;
		finish for(place in PlaceGroup.getWorld()) {
			at(place) async {
				blockAllActivities[T, X](serializedPlh());
			}
		}
	}
	
	private static def blockAllActivities[T, X](handle:PlaceLocalQueueFramework[T, X]) {T isref, T haszero, X haszero} {
		if(handle != null) {
			handle.reinvadeMonitor.lock();
			handle.resizeInProgress = true;
			handle.reinvadeMonitor.unlock();
		} else {
			async blockAllActivities[T, X](handle);
		}
	}
	
	private def resetQueueFramework() {
		finish for(place in PlaceGroup.getWorld()) {
			val serializedPlh = plh;
			at(place) async {
				serializedPlh().reset();
			}
		}
	}
	
	/**
	 * Returns the claim's size.
	 */
	public def size() : Int {
		if(claim == null)
			throw new BadPlaceException();
		return claim.size();
	}
	
	private def get() : T {
		while(!localQueueFramework.globalFinished) {
			val value = localQueueFramework.dequeue();
			if(value != Zero.get[T]())
				return value;
			val finished = stealing();
			if(finished)
				break;
		}
		return Zero.get[T]();
	}
	
	/**
	 * Push the given job into the queue framework.
	 */
	public def push(value:T) {
		localQueueFramework.enqueue(value);
	}
	
	private def stealing():Boolean {
		var maxStealAttempts:Int = PlaceGroup.getWorld().size() - 1;
		var stealAttempts:Int = 0;
		while(localQueueFramework.localFinished && !localQueueFramework.globalFinished) {
			val size = PlaceGroup.getWorld().size();
			if(size == 1) {
				localQueueFramework.terminate();
				return true;
			} else if(stealAttempts > maxStealAttempts) {
				val terminate = detectDistributedTermination[T, X](plh, new Token());
				if(terminate)
					return true;
				maxStealAttempts += size;
			} else if(localQueueFramework.resizeInProgress) {
				// we need to halt the last running activity as well
				waitForReinvade();
				if(perhapsRemoveActiviy()) return true; // stop this activity due to reinvade
			} else {
				val values = tryRemoteSteal();
				localQueueFramework.stoleWork(values);
				if(values != null)
					return false;
				stealAttempts++;
			}
		}
		return false;
	}
	
	private def tryRemoteSteal() : ArrayList[T] {
		val places = PlaceGroup.getWorld();
		val handle = plh();
		if(places.size() == 1 || handle.globalFinished || handle.resizeInProgress)
			return null;
		val placeNum = places.indexOf(here);
		var placeN:Int = random.nextInt(places.size());
		if(placeN == placeNum) {
			placeN = placeNum < places.size() - 1 ? placeNum + 1 : placeNum - 1;
		}
		val place = places(placeN);
		
		val serializedPlh = plh;
		val values = at(place) {
			val remoteHandle = serializedPlh();
			if(remoteHandle == null)
				return null;
			val values = remoteHandle.steal();
			return values;
		};
		return values;
	}
	
	private static def detectDistributedTermination[T, X](plh:PlaceLocalHandle[PlaceLocalQueueFramework[T, X]], token:Token) {T isref, T haszero, X haszero} : Boolean {
		val places = PlaceGroup.getWorld();
		val handle = plh();
		if(places.size() == 1 || handle.globalFinished)
			return true;
		if(handle.resizeInProgress)
			return false;
		val termination:Boolean;
		if(handle.localFinished) {
			val thisPlace = places.indexOf(here);
			val nextPlace = thisPlace + 1 >= places.size() ? 0 : thisPlace + 1;
			token.sentChunks += handle.getSentChunks();
			token.stolenChunks += handle.getStolenChunks();
			val next = places(nextPlace);
			
			val serializedPlh = plh;
			if(next == token.starter) {
				termination = at(next) {
					val remoteHandle = serializedPlh();
					if(remoteHandle == null)
						return false;
					return terminateQueueFramework[T, X](serializedPlh, token);
				};
			} else {
				termination = at(next) {
					val remoteHandle = serializedPlh();
					if(remoteHandle == null)
						return false;
					return detectDistributedTermination[T, X](serializedPlh, token);
				};
			}
		} else {
			return false;
		}
		return termination;
	}
	
	private static def terminateQueueFramework[T, X](plh:PlaceLocalHandle[PlaceLocalQueueFramework[T, X]], token:Token) {T isref, T haszero, X haszero} : Boolean {
		val handle = plh();
		if(handle.localFinished && token.sentChunks == token.stolenChunks && !handle.resizeInProgress) {		
			// we need to make sure that each place will receive the termination notice
			var finished:Boolean;
			val serializedPlh = plh;
			do {
				finished = true;
				for(p in PlaceGroup.getWorld()) {
					finished &= at(p) {
						val remoteHandle = serializedPlh();
						if(remoteHandle != null) {
							remoteHandle.terminate();
							return true;
						}
						return false;
					};
				}
			} while(!finished);
			return true;
		}
		return false;
	}
	
	/**
	 * Close this and free all TLM.
	 */
	public def close() {
		finish for(place in PlaceGroup.getWorld()) {
			val serializedPlh = plh;
			at(place) async {
				val handle = serializedPlh();
				Memory.freeTLM(handle.sent as Pointer);
				Memory.freeTLM(handle.stolen as Pointer);
				Memory.freeTLM(handle.monitor as Pointer);
				Memory.freeTLM(handle.reinvadeMonitor as Pointer);
				for(var i:Int = 0; i < handle.queues.length(); i++) {
					handle.queues(i).close();
				}
			}
		}
		
	}
	
	private def getAvailableJobsAndUpdateClocks(place:Place) {
		val homePlace = here;
		return at(place) {
			return updateEstimatedWaitingTimeAndSendClockInformation(homePlace);
		};
	}
	
	private def updateEstimatedWaitingTimeAndSendClockInformation(homePlace:Place):Int {
		val handle = plh();
		val jobs = handle.getAvailableJobs();
		updateEstimatedWaitingTime[T, X](handle, PlaceGroup.getWorld().indexOf(here));
		if(here.equals(homePlace)) return jobs; // don't send it to the same place
		val waits = handle.averageWaitingTimePerPlace;
		val serializedPlh = plh;
		at(homePlace) {
			val remoteHandle = serializedPlh();
			if(remoteHandle != null)
				updateAverageEstimatedWaitingTimePerPlace[T, X](remoteHandle, waits);
		}
		return jobs;
	}

	private def getAverageTimePerJob():Float {
		var averageTimePerJob:Int = 0;
		var pes:Int = 0;
		for(var i:Int = 0; i < this.averageTimePerJob.length(); i++) {
			averageTimePerJob += this.averageTimePerJob(i) as Int;
			if(this.averageTimePerJob(i) > 0)
				pes++;
		}
		return pes == 0 ? 0 : averageTimePerJob / pes;
	}
	
	private def getEstimatedWaitingTimeForAllPlaces():Float {
		val handle = plh();
		var estimatedWaitingTime:Int = 0;
		for(var i:Int = 0; i < handle.averageWaitingTimePerPlace.size; i++) {
			estimatedWaitingTime += handle.averageWaitingTimePerPlace(i).wait as Int;
		}
		return estimatedWaitingTime / PlaceGroup.getWorld().size();
	}
	
	private def getAvailableJobsForAllPlaces():Int {
		val availableJobs = @TLMAllocate new AtomicInteger(0);
		finish for(place in PlaceGroup.getWorld()) async {
			availableJobs.addAndGet(getAvailableJobsAndUpdateClocks(place));
		}
		Memory.freeTLM(availableJobs as Pointer);
		return availableJobs.get();
	}
	
	private static def updateAverageEstimatedWaitingTimePerPlace[T, X](handle:PlaceLocalQueueFramework[T, X], waits:Array[Wait](1)){T isref, T haszero, X haszero} {
		handle.monitor.lock();	
		handle.averageWaitingTimePerPlace = handle.averageWaitingTimePerPlace.map[Wait, Wait](waits, (i:Wait, j:Wait) => {
			i.wait = i.timeStamp >= j.timeStamp ? i.wait : j.wait;
			i.timeStamp = Math.max(i.timeStamp, j.timeStamp);
			return i;
		});
		handle.monitor.unlock();
	}
	
	private static def updateEstimatedWaitingTime[T, X](handle:PlaceLocalQueueFramework[T, X], index:Int){T isref, T haszero, X haszero} {
		handle.monitor.lock();
		val w = handle.averageWaitingTimePerPlace(index);
		var waitingTime:Float = 0f;
		for(var i:Int = 0; i <  handle.queues.length(); i++) {
			waitingTime += handle.queues(i).getEstimatedWaitingTime();
		}
		waitingTime /= handle.localActivities;
		w.wait = waitingTime < 0 ? Float.MAX_VALUE : waitingTime;
		w.timeStamp++;
		handle.monitor.unlock();
	}
	
	/**
	 * Check the current constraints of this claim and evaluate the performance of the queue framework.
	 * Keeps all given constraints and returns a new constraint for the next reinvade.
	 */
	private def generateNewConstraint():Constraint {
		var constraints:Constraint = this.constraint;
		val size = claim.size();
		val handle = plh();
		val averageTimePerJob = getAverageTimePerJob();
		val availableJobs = getAvailableJobsForAllPlaces();
		val estimatedWaitingTime = getEstimatedWaitingTimeForAllPlaces() as Int;
		if(averageTimePerJob > 0 && (estimatedWaitingTime > averageTimePerJob * 0.4)) {
			val shrink = Math.min(estimatedWaitingTime/averageTimePerJob/2, 0.5f);
			// shrink the amount of PEs by 20%-50%, but at least by one
			val min = size == 1 ? size : (size / (shrink + 1f)) as Int;
			constraints = constraints && new PEQuantity(1, min);
		} else if(availableJobs > (Math.min(estimatedWaitingTime/averageTimePerJob, 1f) * size) && estimatedWaitingTime < averageTimePerJob * 0.1) {			
			// grow the amount of PEs by 25%, but at least by one
			val max = size < 5 ? size + 1 : (size * 1.25f) as Int;
			constraints = constraints && new PEQuantity(1, max);
		}
		return constraints;
	}
	
	/**
	 * Reinvades the claim with the given constraint.
	 * Stops all necessary activities, then revinades the claim and starts all activities again. 
	 */
	private def reinvade(constraint:Constraint) {
		if(claim == null)
			throw new BadPlaceException("Claim was null.");
		if(constraint == null || constraint.equals(this.constraint)) {
			val handle = plh();
			handle.reinvadeMonitor.lock();
			handle.waitingActivities = 0;
			handle.reinvadeMonitor.unlock();
			return;
		}
		startResizingClaim();
		val pes = claim.processingElements().clone();
		val places = new SparsePlaceGroup(new PlaceSequence(claim.places().clone()));
		prepareReinvade();
		if(!claim.reinvade(constraint)) {
			continueAfterReinvade();
			return;
		}
		this.constraint = constraint;
		
		val nPes = claim.processingElements();
		val addedPEs = new ArrayList[ProcessingElement]();
		val removedPEs = new ArrayList[ProcessingElement]();
		for(pe in nPes) {
			if(!pes.contains(pe))
				addedPEs.add(pe);
		}
		for(pe in pes) {
			if(!nPes.contains(pe))
				removedPEs.add(pe);
		}
		runtimeReinvade(places, pes, addedPEs, removedPEs);
		continueAfterReinvade();
	}
	
	private static def calculateAddedPlaces(oldPlaces:PlaceGroup, addedPEs:List[ProcessingElement]):HashSet[Place] {
		val addedPlaces = new HashSet[Place]();
		for(pe in addedPEs) {
			val place = pe.getPlace();
			if(!oldPlaces.contains(place))
				addedPlaces.add(place);
		}
		return addedPlaces;
	}
	
	private static def calculateRemovedPlaces(oldPlaces:PlaceGroup, removedPEs:List[ProcessingElement], oldPesPerPlace:Array[Int](1)):HashSet[Place] {
		val removedPlaces = new HashSet[Place]();
		val oldPesPerPlaceCopy = new Array[Int](Tile.getComputeTileCount() as Int);
		Array.copy(oldPesPerPlace, oldPesPerPlaceCopy);
		for(pe in removedPEs) {
			val place = pe.getPlace();
			if(oldPlaces.contains(place)) {
				val index = oldPlaces.indexOf(place);
				oldPesPerPlaceCopy(index) -= 1;
				if(oldPesPerPlaceCopy(index) == 0)
					removedPlaces.add(place);
			} else {
				throw new IllegalArgumentException(pe + " cannot be removed since it wasn't used before.");
			}
		}
		return removedPlaces;
	}
	
	private def checkAndGrowPlh(addedPlaces:HashSet[Place], places:PlaceGroup, pesPerPlace:Array[Int](1)) {
		if(addedPlaces.size() > 0) {
			val aPlaces = new SparsePlaceGroup(new PlaceSequence(addedPlaces));
			measuredAtTime = measureAtTime(aPlaces(0));
			PlaceLocalHandle.grow[PlaceLocalQueueFramework[T, X], Int](aPlaces, plh, (p:Place) => pesPerPlace(places.indexOf(p)),
					(pe:Int) => new PlaceLocalQueueFramework[T, X](pe, plh().localStealPolicy, plh().remoteStealPolicy));
		}
	}
	
	private def checkAndDestroyPlh(removedPlaces:HashSet[Place]) {
		if(removedPlaces.size() > 0) {
			val rPlaces = new SparsePlaceGroup(new PlaceSequence(removedPlaces));
			PlaceLocalHandle.destroy[PlaceLocalQueueFramework[T, X]](rPlaces, plh);
		}
	}
	
	private def setNewLocalPECount(oldPlaces:PlaceGroup, places:PlaceGroup, pesPerPlace:Array[Int](1), oldPesPerPlace:Array[Int](1), addedPlaces:HashSet[Place], 
			removedPlaces:HashSet[Place]) {
		val iter = addedPlaces.iterator();
		for(p in oldPlaces) {
			val newLocalPEs = pesPerPlace(places.indexOf(p));
			val oldLocalPEs = oldPesPerPlace(oldPlaces.indexOf(p));
			if((newLocalPEs != oldLocalPEs) && !removedPlaces.contains(p)) {
				/* for each removed pe we should remove an activity as well */
				val serializedPlh = plh;
				at(p) {
					val handle = serializedPlh();
					handle.monitor.lock();
					handle.globalFinished = false;
					handle.localActivities = newLocalPEs;
					handle.activitiesToRemove = Math.max(oldLocalPEs - newLocalPEs, 0);
					handle.localFinished = false;
					val queues = handle.queues;
					for(var i:Int = 0; i < queues.length(); i++) {
						queues(i).reset(); // all local activities must be stopped for this to be safe
					}
					handle.monitor.unlock();
				}
			} else if (removedPlaces.contains(p)){
				/* this part is only necessary once a resize handler can be used */
				val target:Place;
				if(iter.hasNext()) {
					target = iter.next();
				} else {
					var placeN:Int;
					do {
						placeN = random.nextInt(places.size());
					} while(placeN == places.indexOf(p));
					target = places(placeN);
				}
				val serializedPlh = plh;
				at(p) {
					val handle = serializedPlh();
					// recover remaining jobs if there are any
					val remainingJobs = new ArrayList[T]();
					for(var i:Int = 0; i < handle.queues.length(); i++) {
						remainingJobs.addAll(handle.queues(i).stealAll()); // all local activities must be stopped for this to work
					}
					// recover the sent/stolen counter from places that will be removed
					val sent = handle.getSentChunks();
					val stolen = handle.getStolenChunks();
					at(target) {
						val remoteHandle = plh();
						remoteHandle.stoleWork(remainingJobs); // increments stolen counter by 1
						remoteHandle.incrementSentChunks(sent + 1);
						remoteHandle.incrementStolenChunks(stolen);
					}
				};
			}

		}
	}
	
	private def startAdditionalActivities(addedPEs:List[ProcessingElement], places:PlaceGroup) {
		if(nextId == -1 && addedPEs.size() > 0)
			throw new BadPlaceException("Reinvade on the wrong place.");
		for(p in places) {
			val ids = new ArrayList[IncarnationID]();
			for (pe in addedPEs) {
				val pi = pe.getPlace();
				if (!pi.equals(p)) continue;
				ids.add(new IncarnationID(nextId++,pe));
			}
			if(ids.size() < 1) continue;
			val homePlace = here;
			val claim = this.claim;
			val constraint = this.constraint;
			val peCount = claim.size() + addedPEs.size();
			
			switch(infectType) {
			case InfectType.STANDARD_INFECT:
				val work = this.work;
				at(p) {
					for(id in ids) async {
						if(homePlace.equals(here))
							initializeIlets(InfectType.STANDARD_INFECT, peCount, work, claim, constraint);
						doInitialJobs(work, id);
					}
				}
				break;
			case InfectType.REDUCE_INFECT:
				val workReduce = this.workReduce;
				val reduce = this.reduce;
				at(p) {
					for(id in ids) async {
						if(homePlace.equals(here))
							initializeIlets(InfectType.REDUCE_INFECT, peCount, workReduce, reduce, claim, constraint);
						doInitialJobs(workReduce, reduce, id);
					}
				}
				break;
			default:
				throw new IllegalArgumentException("Unrecognized type of infect.");
			}
		}
	}
	
	/**
	 * Handles all necessary adjustments for all places if the reinvade was called in a non-malleable application.
	 */
	private def runtimeReinvade(oldPlaces:PlaceGroup, oldPes:Collection[ProcessingElement], addedPEs:List[ProcessingElement], removedPEs:List[ProcessingElement]) {
		val oldPesPerPlace = getPesPerPlace(oldPes, oldPlaces);
		val addedPlaces = calculateAddedPlaces(oldPlaces, addedPEs);
		val removedPlaces = calculateRemovedPlaces(oldPlaces, removedPEs, oldPesPerPlace);
		val places = PlaceGroup.getWorld();
		val pesPerPlace = getPesPerPlace(claim.processingElements(), places);
		
		checkAndGrowPlh(addedPlaces, places, pesPerPlace);
		setNewLocalPECount(oldPlaces, places, pesPerPlace, oldPesPerPlace, addedPlaces, removedPlaces);
		checkAndDestroyPlh(removedPlaces);
		startAdditionalActivities(addedPEs, places);
	}
	
	/**
	 * Crate a resize handle for malleable applications.
	 */
	private def createResizeHandler(oldPlaces:PlaceGroup, oldPes:Collection[ProcessingElement]) : (addedPEs:List[ProcessingElement], removedPEs:List[ProcessingElement]) => void {
		val resizeHandler = (addedPEs:List[ProcessingElement], removedPEs:List[ProcessingElement]) => {
			/* block all operations while resizing */
			startResizingClaim();
			
			val oldPesPerPlace = getPesPerPlace(oldPes, oldPlaces);
			val editedPlacesList = new ArrayList[Place]();
			val addedPlaces = calculateAddedPlaces(oldPlaces, addedPEs);
			val removedPlaces = calculateRemovedPlaces(oldPlaces, removedPEs, oldPesPerPlace);
			for(p in addedPlaces) {
				editedPlacesList.add(p);
			}
			for(p in removedPlaces) {
				editedPlacesList.add(p);
			}
			
			/* block all operations on the resized tiles while resizing */
			prepareReinvade(new SparsePlaceGroup(new PlaceSequence(editedPlacesList)));

			/* assume claim holds the union of old and new pes/places */
			val allPes = claim.processingElements().clone();
			val places = PlaceGroup.getWorld();
			val pesPerPlace = getPesPerPlace(allPes, places);
			
			checkAndGrowPlh(addedPlaces, places, pesPerPlace);
			setNewLocalPECount(oldPlaces, places, pesPerPlace, oldPesPerPlace, addedPlaces, removedPlaces);
			checkAndDestroyPlh(removedPlaces);
			startAdditionalActivities(addedPEs, places);
			
			/* continue all operations after resizing */
			continueAfterReinvade();
		};
		return resizeHandler;
	}
	
	/**
	 * Serialization.
	 */
	public def serialize() : SerialData {
		return new SerialData(plh, new SerialData(doAutomaticReinvades, new SerialData(targetILetRestartTime, 
				new SerialData(reinvadeTime, new SerialData(measuredAtTime, null)))));
	}
	
	/**
	 * Wraps the number of local PEs and the initial work given to each place in an object to intialize
	 * at a certain place.
	 */
	private static struct InitializationData[Y](pes:Int, initialWork:List[Y], localStealPolicy:Int, remoteStealPolicy:Int) {Y haszero} {
		private def this(val pes:Int, val initialWork:List[Y], val localStealPolicy:Int, val remoteStealPolicy:Int) {
			property(pes, initialWork, localStealPolicy, remoteStealPolicy);
		}
	}
	
	/**
	 * Stores the amount of jobs and the time spent stealing. 
	 */
	private static class Wait {
		private var wait:Float = 0f;
		private var timeStamp:Int = 0;
	}
	
	/**
	 * The token that is used for global termination detection.
	 * Will be passed around through all places.
	 */
	private static class Token {
		private var sentChunks:Int;
		private var stolenChunks:Int;
		private val starter = here;
		
		private def this() {
			sentChunks = 0;
			stolenChunks = 0;
		}
	}
	
	/**
	 * Represents a place local represantation of the queue framework i.e. the queue itself and local counters.
	 */
	 private static class PlaceLocalQueueFramework[T, X]{T isref, T haszero, X haszero} implements CustomSerialization {
		 
		private val queues = IndexedMemoryChunk.allocateUninitialized[Deque[T]](Tile.getTileCoreCount() as Int);
		private val results = IndexedMemoryChunk.allocateZeroed[X](Tile.getTileCoreCount() as Int);
		
		/* steal policies of all queues */
		private var localStealPolicy:Int;
		private var remoteStealPolicy:Int;
		
		/* counter */
		private val stolen:AtomicInteger = @TLMAllocate new AtomicInteger(0);
		private val sent:AtomicInteger = @TLMAllocate new AtomicInteger(0);
		private @Volatile var localActivities:Int;
		private var localFinishedCount:Int = 0;
		private var waitingActivities:Int = 0;
		private var activitiesToRemove:Int = 0;
		
		/* flags */
		private @Volatile var globalFinished:Boolean = false;
		private @Volatile var localFinished:Boolean = false;
		private @Volatile var resizeInProgress:Boolean = false;
		
		/* vector clocks */
		private var averageWaitingTimePerPlace:Array[Wait](1);
		
		/* monitors */
		private val monitor = @TLMAllocate new Monitor();
		private val reinvadeMonitor = @TLMAllocate new Monitor();
		
		/**
		 * Creates deques on this place.
		 */
		private def this(pes:Int, localStealPolicy:Int, remoteStealPolicy:Int) {
			initialize(pes, localStealPolicy, remoteStealPolicy);
			for(var i:Int = 0; i < queues.length(); i++) {
				queues(i) = new SplitDeque[T](localStealPolicy, remoteStealPolicy);
			}
		}
		
		/**
		 * Creates deques on this place and distributes the given work among all pes.
		 * So that: work per place = (#PEs on this place / #PEs) * work
		 */
		private def this(pes:Int, initialWork:List[T], localStealPolicy:Int, remoteStealPolicy:Int) {
			initialize(pes, localStealPolicy, remoteStealPolicy);
			val size = initialWork.size();
			val workPerQueue = size % localActivities == 0 ? size / localActivities : size / localActivities + 1;
			val work = new ArrayList[T](workPerQueue);
			for(var i:Int = 0; i < queues.length(); i++) {
				for(var j:Int = 0; j < workPerQueue && initialWork.size() > 0; j++) {
					work.add(initialWork.removeFirst());
				}
				queues(i) = new SplitDeque[T](localStealPolicy, remoteStealPolicy, work);
				work.clear();
			}
		}
		
		@NonEscaping
		private def initialize(pes:Int, localStealPolicy:Int, remoteStealPolicy:Int) {
			this.localStealPolicy = localStealPolicy;
			this.remoteStealPolicy = remoteStealPolicy;
			localActivities = pes;
			averageWaitingTimePerPlace = new Array[Wait](Tile.getComputeTileCount() as Int, (i:Int) => new Wait());
		}
		
		/**
		 * Deserialization.
		 */
		public def this(val data:SerialData) {
			throw new UnsupportedOperationException("Cannot deserialize " + this.typeName());
		}
		
		private def enqueue(value:T) {
			val index = ProcessingElement.currentCPU();
			queues(index).pushBottom(value);
			if(localFinishedCount > 0) {
				monitor.lock();
				localFinishedCount = 0;
				localFinished = false;
				monitor.release();
			}
		}
		
		private def dequeue() : T {
			while(!globalFinished) {
				val queue = queues(ProcessingElement.currentCPU());
				val value = queue.popBottom();
				if(value == Zero.get[T]()) {
					val start = System.nanoTime();
					val job = tryLocalSteal(queue);
					if(job != Zero.get[T]()) {
						updateEstimatedWaitingTime(start, queue);
						return job;
					}
					monitor.lock();
					if(localActivities == ++localFinishedCount) {
						var finished:Boolean = true;
						for(var i:Int = 0; i < queues.length(); i++) {
							// check if a queue still has work left
							val q = queues(i);
							if(!q.isEmpty()) {
								q.reset();
								finished = false;
							}
						}
						if(finished) {
							localFinished = true;
							monitor.unlock();
							return Zero.get[T]();
						} else {
							localFinishedCount = 0;
							monitor.release();
						}
					} else {
						monitor.await();			
						monitor.unlock();		
					}
					updateEstimatedWaitingTime(start, queues(ProcessingElement.currentCPU()));
				} else {
					return value;
				}
			}
			return Zero.get[T]();
		}
		
		private def tryLocalSteal(queue:Deque[T]) : T {
			val maxLocalPEs = Tile.getTileCoreCount() as Int;
			for(var i:Int = 0; i < maxLocalPEs; i++) {
				val targetQueue = random.nextInt(maxLocalPEs);
				val stolen = queues(targetQueue).localSteal();
				if(stolen != null) {
					queue.stoleWork(stolen);
					return queue.popBottom();
				}
			}
			return Zero.get[T]();
		}
		
		private def steal() : ArrayList[T] {
			val maxLocalPEs = Tile.getTileCoreCount() as Int;
			incrementSentChunks();
			for(var i:Int = 0; i < maxLocalPEs; i++) {
				val targetQueue = random.nextInt(maxLocalPEs);
				val stolen = queues(targetQueue).remoteSteal();
				if(stolen != null)
					return stolen;
			}
			return null;
		}
		
		private def stoleWork(stolen:ArrayList[T]) {
			if(stolen != null && stolen.size() > 0) {
				val index = ProcessingElement.currentCPU();
				queues(index).stoleWork(stolen);
				monitor.lock();
				localFinished = false;
				localFinishedCount = 0;
				monitor.release();			
			}
			incrementStolenChunks();
		}
		
		private def updateEstimatedWaitingTime(start:Long, queue:Deque[T]) {
			val now = System.nanoTime();
			val diff = (now - start) < 0 ? (now - start) - Int.MIN_VALUE : now - start;
			queue.updateWaitingTime(diff as Float);
		}
		
		private def addResult(result:X, reduce:(X,X) => X) {
			val index = ProcessingElement.currentCPU();
			results(index) = reduce(results(index), result); 
		}
		
		private def getSentChunks():Int {
			return sent.get();
		}
		
		private def getStolenChunks():Int {
			return stolen.get();
		}
		
		private def incrementSentChunks():void {
			sent.incrementAndGet();
		}
		
		private def incrementStolenChunks():void {
			stolen.incrementAndGet();
		}
		
		private def incrementSentChunks(sentChunks:Int):void {
			sent.addAndGet(sentChunks);
		}
		
		private def incrementStolenChunks(stolenChunks:Int):void {
			stolen.addAndGet(stolenChunks);
		}
		
		private def getEstimatedWaitingTime():Float {
			val wait = averageWaitingTimePerPlace.reduce[Float]((i:Float, j:Wait) => i + j.wait, 0f);
			return wait < 0 ? Float.MAX_VALUE : wait / PlaceGroup.getWorld().size();
		}
		
		private def getAvailableJobs():Int {
			var availableJobs:Int = 0;
			for(var i:Int = 0; i <  queues.length(); i++) {
				availableJobs += queues(i).getAvailableJobs();
			}
			return availableJobs;
		}
		
		private def terminate():void {
			if(globalFinished) return;
			for(var i:Int = 0; i < queues.length(); i++) {
				queues(i).terminate();
			}
			monitor.lock();
			sent.set(0);
			stolen.set(0);
			globalFinished = true;
			localFinished = true;
			localFinishedCount = 0;
			monitor.release();
			reinvadeMonitor.lock();
			waitingActivities = 0;
			activitiesToRemove = 0;
			reinvadeMonitor.release();
		}
		
		private def reset():void {
			for(var i:Int = 0; i < queues.length(); i++) {
				queues(i).reset();
			}
			for(var i:Int = 0; i < results.length(); i++) {
				results(i) = Zero.get[X]();
			}
			monitor.lock();
			globalFinished = false;
			localFinished = false;
			monitor.unlock();
			reinvadeMonitor.lock();
			resizeInProgress = false;	
			reinvadeMonitor.unlock();
		}

		/**
		 * Serialization.
		 */
		public def serialize() : SerialData {
			throw new UnsupportedOperationException("Cannot serialize " + this.typeName());
		}
	}
}

