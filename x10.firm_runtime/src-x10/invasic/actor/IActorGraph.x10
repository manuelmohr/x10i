package invasic.actor;

import x10.util.*;

public abstract class IActorGraph[T] {T <: IActor, T isref} {
    
    /**
     * Get a list containing all actors.
     */
    public abstract def getActors() : List[GlobalRef[T]];

    /**
     * Move an actor to a place.
     n*/
    public abstract def moveActor(actor:GlobalRef[T], place:Place) : Any;

    /**
     * Move the referenced actor to a place.
     */
    public abstract def moveActor(actor:T, place:Place) : Any;

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
