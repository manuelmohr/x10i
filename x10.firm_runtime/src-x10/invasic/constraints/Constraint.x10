package invasic.constraints;

import x10.lang.Pointer;

/** The abstract root of all constraints. */
public abstract class Constraint {
    abstract public def toAgentConstr(constr:Pointer):void;

    public static operator (a:Constraint) && (b:Constraint) {
        val and = new AND();
        and.add(a);
        and.add(b);
        return and as Constraint;
    }
    public static operator (a:AND) && (b:Constraint) {
        a.add(b);
        return a as Constraint;
    }
    public static operator (a:Constraint) && (b:AND) {
        b.add(a);
        return b as Constraint;
    }

}
