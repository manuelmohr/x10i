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
    @LinkSymbol("agent_constr_create")
    static native def create_constr():Pointer;

    @LinkSymbol("agent_constr_delete")
    static native def delete_constr(c:Pointer):Pointer;

    /** Converts X10 constraints into iRTSS constraints
      * Remember to delete them afterwards! */
    private static def createAgentConst(c:Constraint):Pointer {
      val constr = create_constr();
      c.toAgentConstr(constr);
      return constr;
    }

    /** Returns a claim fulfilling the constraint or throws a NotEnoughResources exception */
    public static def invade(c:Constraint):Claim {
        val ac = create_constr();
        c.toAgentConstr(ac);
        val clm = invade(null as Pointer, ac);
        val ret = new AgentClaim(clm);
        delete_constr(ac);
        return ret;
    }

    @LinkSymbol("x10_agent_claim_invade")
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

    /* Get current claim. */
    public static def getCurrent():Claim {
        return new AgentClaim(AgentClaim.get_current());
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
        arr(i) = new Place(i);
        i += 1;
      }
      return arr.sequence();
    }

    public def infect[T](ilet:(IncarnationID)=>T) {T haszero}:Array[T] {
        val places = this.places();
        val all_pes = this.processingElements();
        val results = new Array[T](all_pes.size(), Zero.get[T]());
        assert (all_pes.size() == this.size());
        var iid:Int = 0;
        finish for (p in places) {
            /* compute incarnationids for current place */
            val ids = new ArrayList[IncarnationID]();
            val start_iid = iid;
            for (pe in all_pes) {
              val pi = pe.getPlace();
              if (!pi.equals(p)) continue;
              ids.add(new IncarnationID(iid,pe));
              iid += 1;
            }

            val ac = this as AgentClaim;
            ac.check_invariant();
            async {
                val iilet = ()=>{
                  val ret = new Array[T](ids.size(), Zero.get[T]());
                  finish for (id in ids) async {
                    ret(id.ordinal - start_iid) = ilet(id);
                  }
                  return ret as Any;
                };
                val part_res = ac.evalAtAgent(p,iilet) as Array[T];
                for (id in ids) {
                  results(id.ordinal) = part_res(id.ordinal - start_iid);
                }
            }
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
    private val tileid:uint;
    def my_clm():Pointer = this.clm;

    public def check_invariant():void {
        /* the underlying agent_claim_t is only valid on the tile,
        where it was invaded. However, we must copy AgentClaim through 'at'
        for infect. This might go to a different Place (Claim) on the same tile,
        so we check the tile id. */
        assert this.tileid == Tile.getCurrentTileId() : "AgentClaim only valid on its tile "+this.tileid+" not here on tile "+Tile.getCurrentTileId();
    }

    /** Constructor is protected, because the invade method is the only way to get a claim. */
    def this(clm:Pointer) {
        this.clm = clm;
        this.tileid = Tile.getCurrentTileId();
    }

    /** Reinvades with the same constraints and returns whether claim contents changed */
    public def reinvade():Boolean {
        this.check_invariant();
        val ret = reinvade(this.clm);
        if (ret < 0) throw new ReinvadeFail("claim is invalid now");
        return ret != 0;
    }

    @LinkSymbol("x10_agent_claim_reinvade")
    static native def reinvade(clm:Pointer):Int;

    /** Reinvades with new constraints and returns whether claim contents changed */
    public def reinvade(c:Constraint):Boolean {
        this.check_invariant();
        val ac = create_constr();
        c.toAgentConstr(ac);
        val ret = reinvade(this.clm, ac);
        delete_constr(ac);
        if (ret < 0) throw new ReinvadeFail("claim is invalid now");
        return ret != 0;
    }

    @LinkSymbol("x10_agent_claim_reinvade_constraints")
    static native def reinvade(clm:Pointer, constr:Pointer):Int;

    /** Retreat completely and free all resources. */
    public def retreat():void = {
        if (this.clm == Pointer.NULL) return; /* nothing to do */
        this.check_invariant();
        retreat(this.clm);
    }

    @LinkSymbol("agent_claim_retreat")
    static native def retreat(clm:Pointer):void;

    /** Only retreat from those resources fulfilling the constraint. */
    public def partialRetreat(c:Constraint):void {
        throw new UnsupportedOperationException("partialRetreat not supported");
    }

    /** Retreat from this specific PE. */
    public def retreat(pe:ProcessingElement):void {
        throw new UnsupportedOperationException("retreatPE not supported");
    }

    /** Returns how many PEs are in this claim. */
    public def size():Int {
      if (this.clm == Pointer.NULL) return 0;
      return size(this.clm);
    }

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
        this.check_invariant();
        val res = new ArrayList[ProcessingElement]();
        val tiles = tiles(this.clm);
        var pid:int = 0;
        for (tid in tiles) {
            val pecount = pecount_tile_type(this.clm, tid, 0/*RISC*/);
            for (peid in 0..(pecount-1)) {
                val pe_type = 0/*RISC*/;
                val pe = new ProcessingElement(this.clm, new Place(pid), pe_type, peid);
                res.add(pe);
            }
            pid += 1;
        }
        return res;
    }

    public def print():void {
        this.check_invariant();
        print_claim(this.clm);
    }

    @LinkSymbol("agent_claim_print")
    static native def print_claim(claim:Pointer):void;

    public def infect(ilet:(IncarnationID)=>void) {
        val places = this.places();
        var iid:Int = 0;
        val cur = Claim.getCurrent();
        val all_pes = this.processingElements();
        finish for (p in places) {
            /* compute incarnationids for current place */
            val ids = new ArrayList[IncarnationID]();
            for (pe in all_pes) {
              val pi = pe.getPlace();
              if (!pi.equals(p)) continue;
              ids.add(new IncarnationID(iid,pe));
              iid += 1;
            }

            if (this.equals(cur)) {
              /* this shortcut avoids one async and thus some scheduling chaos */
              at(p) async {
                for (id in ids) async {
                  ilet(id);
                }
              }
            } else {
              runAtAsyncAgent(p, ()=>{
                  for (id in ids) async {
                    ilet(id);
                  }
              });
            }
        }
    }

    @LinkSymbol("x10_eval_at_agent")
    private static native def evalAtOtherAgent(placeId:Int, agentclaim:Pointer, o:Any):Any;

    public def evalAtAgent(p:Place, f:()=>Any):Any {
        this.check_invariant();
        return evalAtOtherAgent(p.id, this.clm, f);
    }

    @LinkSymbol("x10_exec_at_agent")
    private static native def execAtOtherAgent(placeId:Int, agentclaim:Pointer, o:Any):void;

    public def runAtAgent(p:Place, f:()=>void) {
        this.check_invariant();
        execAtOtherAgent(p.id, this.clm, f);
    }

    @LinkSymbol("x10_exec_atasync_agent")
    private static native def execAtAsyncOtherAgent(placeId:Int, agentclaim:Pointer, o:Any):void;

    public def runAtAsyncAgent(p:Place, f:()=>void) {
        this.check_invariant();
        execAtAsyncOtherAgent(p.id, this.clm, f);
    }

    public def equals(a:Any):boolean {
      if (!(a instanceof AgentClaim)) return false;
      val c = a as AgentClaim;
      return this.clm == c.clm && this.tileid == c.tileid;
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

    public def equals(a:Any):boolean {
      if (!(a instanceof UnionClaim)) return false;
      val c = a as UnionClaim;
      return this.a == c.a && this.b == c.b;
    }
}
