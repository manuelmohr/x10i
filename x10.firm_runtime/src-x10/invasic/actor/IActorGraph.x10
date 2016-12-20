package invasic.actor;

import x10.util.*;

public abstract class IActorGraph {
    /**
     * Get a list containing all actors.
     */
    public abstract def getActors() : List[GlobalRef[IActor]];

    /**
     * Move an actor to a place.
     n*/
    public abstract def moveActor(actor:GlobalRef[IActor], place:Place) : Any;

    /**
     * Move the referenced actor to a place.
     */
    public abstract def moveActor(actor:IActor, place:Place) : Any;

    /**
     * Start the actor graph's execution
     */
    public abstract def start() : void;

    /**
     * Signal the actor graph to pause its execution.
     */
    public abstract def stop() : void;

    /**
     * Print XML description of the actor graph.
     */
    public abstract def prettyPrint() : String;
}
