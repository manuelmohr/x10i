package invasic.actor;

import x10.util.ArrayList;

public abstract class AbstractChannel (capacity:int) {
    var pinned : boolean = false;
    public def this(capacity:int) {
        assert (capacity > 0) : "No channel with zero capacity!";
        property (capacity);
    }
    abstract def start() : void;
    abstract def stop() : void;
    abstract def waitForStop() : void;
    abstract def waitForStart() : void;
    abstract def running() : boolean;
    abstract def getActors() : ArrayList[GlobalRef[Actor]];
    abstract def migrated() : void;

    abstract def prettyPrint() : String;
}

