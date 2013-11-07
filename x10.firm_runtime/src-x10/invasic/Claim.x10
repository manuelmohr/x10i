package invasic;

import x10.lang.Pointer;
import x10.compiler.LinkSymbol;

import x10.util.List;
import x10.util.ArrayList;
import x10.util.Set;
import x10.util.HashSet;

import invasic.constraints.Constraint;
import invasic.constraints.AND;
import invasic.constraints.NotEnoughResources;

/**
  A claim represents a set of reserved resources.
 */
abstract public class Claim {
    /** Returns a claim fulfilling the constraint or throws a NotEnoughResources exception */
    public static def invade(c:Constraint):Claim {
        val and = c as AND;
        val clm = invade(null as Pointer, and.constr);
        return new AgentClaim(clm);
    }

    @LinkSymbol("agent_claim_invade")
    static native def invade(parent:Pointer, constraints:Pointer):Pointer;

    /** convenience invade function */
    public static def invadeAND(lst:Array[Constraint](1)):Claim {
        val cs = new AND();
        for (i in lst) {
            val c = lst(i);
            cs.add(c);
        }
        return invade(cs);
    }

    abstract public def infect(ilet:(IncarnationID)=>void):void;
    abstract public def reinvade():boolean;
    abstract public def reinvade(c:Constraint):boolean;
    abstract public def retreat():void;
    abstract public def retreat(pe:ProcessingElement):void;
    abstract public def partialRetreat(c:Constraint):void;
    abstract public def processingElements():List[ProcessingElement];
    abstract public def size():int;
    abstract public def print():void;
    abstract def my_clm():Pointer;

    /** Returns a string representing this claim */
    public def toString():String = "(Claim "+size()+" PE)";

    /** Returns a new claim, which contains all PEs from both operands. */
    public operator this + (b:Claim):Claim {
        assert (b != null) : "null claim";
        return new UnionClaim(this, b);
    }

    /** Get a set of all places of the PEs in the claim */
    public def places():Set[Place] {
        val ps = new HashSet[Place]();
        for (pe in processingElements()) {
            ps.add(pe.getPlace());
        }
        return ps;
    }

    /** Returns the list of all places according to your current claim */
    public static def placeSeq():Sequence[Place] {
      val tiles = AgentClaim.tiles(AgentClaim.get_current());
      val arr = new Array[Place](tiles.size());
      var i:int = 0;
      for (tid in tiles) {
        arr(i) = new Place(tid);
        i += 1;
      }
      return arr.sequence();
    }

    public def infect[T](ilet:(IncarnationID)=>T) {T haszero}:Array[T] {
        val pes = this.processingElements();
        val results = new Array[T](pes.size(), Zero.get[T]());
        assert (pes.size() == this.size());
        var iid:Int = 0;
        finish for (pe in pes) {
            val p = pe.getPlace();
            val current_iid = iid;
            if (p == here) { // FIXME compare tile instead?
                async {
                    val id = new IncarnationID(current_iid, pe);
                    results(current_iid) = ilet(id);
                }
            } else {
                val current = AgentClaim.get_current();
                AgentClaim.set_current(this.my_clm());
                async {
                    results(current_iid) = at (p)
                        ilet(new IncarnationID(current_iid, pe));
                }
                AgentClaim.set_current(current);
            }
            iid += 1;
        }
        return results;
    }

    public def infect[T](ilet:(IncarnationID)=>T, reduce:(T,T)=>T) {T haszero}:T {
        val results = infect[T](ilet);
        // TODO(roloff) simulator does account reduction to infect call
        return reduction[T](results,reduce);
    }

    private static def reduction[T](values:Array[T], reduce:(T,T)=>T) {T haszero}:T {
        var result:T = Zero.get[T]();
        for (p in values) {
            result = reduce(result,values(p));
        }
        return result;
    }
}

final class AgentClaim extends Claim {
    private val clm:Pointer;
    def my_clm():Pointer = this.clm;

    /** Constructor is protected, because the invade method is the only way to get a claim. */
    def this(clm:Pointer) {
        this.clm = clm;
    }

    /** Reinvades with the same constraints and returns whether claim contents changed */
    public def reinvade():Boolean = reinvade(this.clm) != 0;

    @LinkSymbol("agent_claim_reinvade")
    static native def reinvade(clm:Pointer):Int;

    /** Reinvades with new constraints and returns whether claim contents changed */
    public def reinvade(c:Constraint):Boolean {
        val and = c as AND;
        return reinvade(this.clm, and.constr) != 0;
    }

    @LinkSymbol("agent_claim_reinvade_constraints")
    static native def reinvade(clm:Pointer, constr:Pointer):Int;

    /** Retreat completely and free all resources. */
    public def retreat():void = { retreat(this.clm); }

    @LinkSymbol("agent_claim_retreat")
    static native def retreat(clm:Pointer):void;

    /** Only retreat from those resources fulfilling the constraint. */
    public def partialRetreat(c:Constraint):void {
        throw new UnsupportedOperationException("partialRetreat not supported");
    }

    /** Retreat from this specific PE. */
    public def retreat(pe:ProcessingElement):void {
    }

    /** Returns how many PEs are in this claim. */
    public def size():Int = size(this.clm);

    @LinkSymbol("agent_claim_get_pecount")
    static native def size(clm:Pointer):Int;

    @LinkSymbol("agent_claim_get_tilecount")
    static native def tilecount(clm:Pointer):Int;

    @LinkSymbol("agent_claim_get_pecount_tile")
    static native def pecount_tile(clm:Pointer, tileid:Int):Int;

    @LinkSymbol("agent_claim_get_pecount_tile_type")
    static native def pecount_tile_type(clm:Pointer, tileid:Int, petype:Int):Int;

    @LinkSymbol("agent_claim_get_tileid_iterative")
    static native def get_tileid(clm:Pointer, iter:Int):Int;

    @LinkSymbol("agentclaim_get_current")
    static native def get_current():Pointer;

    @LinkSymbol("agentclaim_set_current")
    static native def set_current(ptr:Pointer):void;

    static def tiles(clm:Pointer):List[Int] {
        val ts = tilecount(clm);
        val ret = new ArrayList[Int](ts);
        for (var i:Int=0; i<ts; i++) {
            val tid = get_tileid(clm, i);
            ret.add(tid);
        }
        return ret;
    }

    /** Get all PEs inside the claim */
    public def processingElements():List[ProcessingElement] {
        val res = new ArrayList[ProcessingElement]();
        val tiles = tiles(this.clm);
        for (tid in tiles) {
            val pecount = pecount_tile_type(this.clm, tid, 0/*RISC*/);
            for (peid in 0..(pecount-1)) {
                val pe_type = 0/*RISC*/;
                val pe = new ProcessingElement(this.clm, tid, pe_type, peid);
                res.add(pe);
            }
        }
        return res;
    }

    public def print():void {
        print_claim(this.clm);
    }

    @LinkSymbol("agent_claim_print")
    static native def print_claim(claim:Pointer):void;

    public def infect(ilet:(IncarnationID)=>void) {
        val pes = this.processingElements();
        assert (pes.size() == this.size());
        var iid:Int = 0;
        finish for (pe in pes) {
            val p = pe.getPlace();
            val current_iid = iid;
            if (p == here) { // FIXME compare tile instead?
                async {
                    val id = new IncarnationID(current_iid, pe);
                    ilet(id);
                }
            } else {
                val current = AgentClaim.get_current();
                AgentClaim.set_current(this.clm);
                at (p) async {
                    val id = new IncarnationID(current_iid, pe);
                    ilet(id);
                }
                AgentClaim.set_current(current);
            }
            iid += 1;
        }
    }
}

final class UnionClaim extends Claim {
    private val a:Claim;
    private val b:Claim;

    def this(a:Claim, b:Claim) {
        this.a = a;
        this.b = b;
    }

    public def retreat() {
        this.a.retreat();
        this.b.retreat();
    }

    public def processingElements():List[ProcessingElement] {
        val PEs = new ArrayList[ProcessingElement]();
        PEs.addAll(this.a.processingElements());
        PEs.addAll(this.b.processingElements());
        return PEs;
    }

    public def places():Set[Place] {
        val ps = new HashSet[Place]();
        ps.addAll(this.a.places());
        ps.addAll(this.b.places());
        return ps;
    }

    public def retreat(pe:ProcessingElement):void {
        this.a.retreat(pe);
        this.b.retreat(pe);
    }

    public def reinvade():boolean {
        val achange = this.a.reinvade();
        val bchange = this.b.reinvade();
        return achange || bchange;
    }

    public def partialRetreat(c:Constraint):void {
        throw new UnsupportedOperationException("Cannot partialRetreat from union claims");
    }

    public def reinvade(c:Constraint):boolean {
        throw new UnsupportedOperationException("Cannot reinvade union claims");
    }

    public def size():int = this.a.size() + this.b.size();

    public def print():void {
        this.a.print();
        this.b.print();
    }

    public def infect(ilet:(IncarnationID)=>void) {
      finish {
        async this.a.infect(ilet);
        async this.b.infect(ilet);
      }
    }

    def my_clm():Pointer = null as Pointer;
}
