package invasic.constraints;

/** This Exception is thrown, if an invade cannot fulfill
  * the constraints due to lack of resources */
public class NotEnoughResources extends Exception {
    public def this() { super(); }
    public def this(s:String) { super(s); }
}
