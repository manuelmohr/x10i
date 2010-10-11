package x10.lang;


final public class Place
extends x10.core.Struct
{public static final x10.rtt.RuntimeType<Place> _RTT = new x10.rtt.RuntimeType<Place>(
/* base class */Place.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 23
final public int
      id;
    
    
//#line 27
final public static int
      ALL_PLACES =
      4;
    
//#line 31
final public static int
      MAX_PLACES =
      4;
    
    
//#line 38
final public static int
                  numChildren(
                  final int id){
        
//#line 39
return 0;
    }
    
    
//#line 44
final public static boolean
                  isHost(
                  final int id){
        
//#line 45
return true;
    }
    
    
//#line 50
final public static boolean
                  isSPE(
                  final int id){
        
//#line 51
return false;
    }
    
    
//#line 56
final public static boolean
                  isCUDA(
                  final int id){
        
//#line 57
return false;
    }
    
    
//#line 64
final public static int
                  parent(
                  final int id){
        
//#line 65
return id;
    }
    
    
//#line 72
final public static int
                  child(
                  final int p,
                  final int i){
        
//#line 73
throw new x10.
          lang.
          BadPlaceException();
    }
    
    
//#line 79
final public static int
                  childIndex(
                  final int id){
        
//#line 80
throw new x10.
          lang.
          BadPlaceException();
    }
    
    
//#line 82
final public static x10.core.ValRail<x10.
      lang.
      Place>
      places =
      ((x10.core.ValRail)(x10.core.RailFactory.<x10.
      lang.
      Place>makeValRail(x10.lang.Place._RTT, ((int)(x10.runtime.impl.java.Runtime.MAX_PLACES)), (new x10.core.fun.Fun_0_1<java.lang.Integer, x10.
                                                                                                   lang.
                                                                                                   Place>() {public final x10.
                                                                                                   lang.
                                                                                                   Place apply$G(final java.lang.Integer id) { return apply((int)id);}
                                                                                                 public final x10.
                                                                                                   lang.
                                                                                                   Place apply(final int id) { {
                                                                                                     
//#line 82
return new x10.
                                                                                                       lang.
                                                                                                       Place(id);
                                                                                                 }}
                                                                                                 public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.lang.Place._RTT;return null;
                                                                                                 }
                                                                                                 }))));
    
//#line 83
final public static x10.core.ValRail<x10.core.ValRail<x10.
      lang.
      Place>>
      children =
      ((x10.core.ValRail)((new java.lang.Object() {final x10.core.ValRail<x10.core.ValRail<x10.
      lang.
      Place>> apply(int length) {x10.core.ValRail[] array = new x10.core.ValRail[length];for (int p$ = 0; p$ < length; p$++) {final int p = p$;array[p] = (new java.lang.Object() {final x10.core.ValRail<x10.
      lang.
      Place> apply(int length) {x10.
      lang.
      Place[] array = new x10.
      lang.
      Place[length];for (int i$ = 0; i$ < length; i$++) {final int i = i$;array[i] = new x10.
      lang.
      Place(x10.
              lang.
              Place.child((int)(p),
                          (int)(i)));}return new x10.core.ValRail<x10.
      lang.
      Place>(x10.lang.Place._RTT, x10.
      lang.
      Place.numChildren((int)(p)), array);}}.apply(x10.
      lang.
      Place.numChildren((int)(p))));}return new x10.core.ValRail<x10.core.ValRail<x10.
      lang.
      Place>>(new x10.rtt.ParameterizedType(x10.core.ValRail._RTT, x10.lang.Place._RTT), x10.runtime.impl.java.Runtime.MAX_PLACES, array);}}.apply(x10.runtime.impl.java.Runtime.MAX_PLACES))));
    
//#line 87
final public static int
      NUM_ACCELS =
      ((((int)(x10.runtime.impl.java.Runtime.MAX_PLACES))) - (((int)(x10.runtime.impl.java.Runtime.MAX_PLACES))));
    
//#line 88
final public static x10.
      lang.
      Place
      FIRST_PLACE =
      ((x10.
      lang.
      Place)(new x10.core.fun.Fun_0_1<x10.
      lang.
      Place, x10.
      lang.
      Place>() {public final x10.
      lang.
      Place apply$G(final x10.
      lang.
      Place __desugarer__var__42__) { return apply(__desugarer__var__42__);}
    public final x10.
      lang.
      Place apply(final x10.
      lang.
      Place __desugarer__var__42__) { {
        
//#line 88
if (!(((int) __desugarer__var__42__.
                                   id) ==
                          ((int) 0))) {
            
//#line 88
throw new java.lang.ClassCastException("x10.lang.Place{self.id==0}");
        }
        
//#line 88
return __desugarer__var__42__;
    }}
    public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.lang.Place._RTT;if (i ==1) return x10.lang.Place._RTT;return null;
    }
    }.apply(((x10.
              lang.
              Place)
              ((x10.
              lang.
              Place)((x10.
              lang.
              Place[])x10.
              lang.
              Place.places.value)[0])))));
    
    
//#line 90
public Place(final int id) {
        
//#line 90
this.id = id;
    }
    
    
//#line 92
final public static x10.
                  lang.
                  Place
                  place(
                  final int id){
        
//#line 92
return new x10.
          lang.
          Place(id);
    }
    
    
//#line 93
final public x10.
                  lang.
                  Place
                  next(
                  ){
        
//#line 93
return this.next((int)(1));
    }
    
    
//#line 94
final public x10.
                  lang.
                  Place
                  prev(
                  ){
        
//#line 94
return this.next((int)(-1));
    }
    
    
//#line 95
final public x10.
                  lang.
                  Place
                  prev(
                  final int i){
        
//#line 95
return this.next((int)((-(((int)(i))))));
    }
    
    
//#line 96
final public x10.
                  lang.
                  Place
                  next(
                  final int i){
        
//#line 98
if (x10.
                          lang.
                          Place.isHost((int)(id))) {
            
//#line 99
final int k =
              ((((int)((((((int)(((((int)(id))) + (((int)(((((int)(i))) % (((int)(x10.runtime.impl.java.Runtime.MAX_PLACES))))))))))) + (((int)(x10.runtime.impl.java.Runtime.MAX_PLACES)))))))) % (((int)(x10.runtime.impl.java.Runtime.MAX_PLACES))));
            
//#line 100
return x10.
              lang.
              Place.place((int)(k));
        }
        
//#line 103
return this;
    }
    
    
//#line 106
final public boolean
                   isFirst(
                   ){
        
//#line 106
return ((int) id) ==
        ((int) 0);
    }
    
    
//#line 107
final public boolean
                   isLast(
                   ){
        
//#line 107
return ((int) id) ==
        ((int) ((((int)(x10.runtime.impl.java.Runtime.MAX_PLACES))) - (((int)(1)))));
    }
    
    
//#line 109
final public boolean
                   isHost(
                   ){
        
//#line 109
return x10.
          lang.
          Place.isHost((int)(id));
    }
    
    
//#line 110
final public boolean
                   isSPE(
                   ){
        
//#line 110
return x10.
          lang.
          Place.isSPE((int)(id));
    }
    
    
//#line 111
final public boolean
                   isCUDA(
                   ){
        
//#line 111
return x10.
          lang.
          Place.isCUDA((int)(id));
    }
    
    
//#line 113
final public int
                   numChildren(
                   ){
        
//#line 113
return x10.
          lang.
          Place.numChildren((int)(id));
    }
    
    
//#line 114
final public x10.
                   lang.
                   Place
                   child(
                   final int i){
        
//#line 114
return new x10.
          lang.
          Place(x10.
                  lang.
                  Place.child((int)(id),
                              (int)(i)));
    }
    
    
//#line 116
final public x10.core.ValRail<x10.
                   lang.
                   Place>
                   children(
                   ){
        
//#line 116
return ((x10.core.ValRail<x10.
          lang.
          Place>)((x10.core.ValRail[])x10.
          lang.
          Place.children.value)[id]);
    }
    
    
//#line 118
final public x10.
                   lang.
                   Place
                   parent(
                   ){
        
//#line 118
return ((x10.
          lang.
          Place)((x10.
          lang.
          Place[])x10.
          lang.
          Place.places.value)[x10.
          lang.
          Place.parent((int)(id))]);
    }
    
    
//#line 120
final public int
                   childIndex(
                   ){
        
//#line 121
if (this.isHost()) {
            
//#line 122
throw new x10.
              lang.
              BadPlaceException();
        }
        
//#line 124
return x10.
          lang.
          Place.childIndex((int)(id));
    }
    
    
//#line 127
final public java.lang.String
                   toString(
                   ){
        
//#line 127
return (((("(Place ") + (((java.lang.Integer)(this.
                                                                     id))))) + (")"));
    }
    
    
//#line 128
final public boolean
                   equals(
                   final x10.
                     lang.
                     Place p){
        
//#line 128
return ((int) p.
                                     id) ==
        ((int) this.
                 id);
    }
    
    
//#line 129
final public boolean
                   equals(
                   final java.lang.Object p){
        
//#line 129
return x10.lang.Place._RTT.instanceof$(p) &&
        ((int) (((new java.lang.Object() {final x10.
                   lang.
                   Place cast(final x10.
                   lang.
                   Place self) {if (self==null) return null;x10.rtt.Type rtt = x10.lang.Place._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                   lang.
                   Place) p)))).
                 id) ==
        ((int) this.
                 id);
    }
    
    
//#line 130
final public int
                   hashCode(
                   ){
        
//#line 130
return id;
    }
    
    
//#line 23
final public int
                  id(
                  ){
        
//#line 23
return this.
                             id;
    }
    
    
//#line 23
final native public x10.
                  lang.
                  Place
                  home(
                  );
    
    
//#line 23
final native public java.lang.String
                  typeName(
                  );
    
    
//#line 23
final native public boolean
                  at(
                  x10.
                    lang.
                    Place p);
    
    
//#line 23
final native public boolean
                  at(
                  java.lang.Object r);
    
    
//#line 23
final public boolean
                  _struct_equals(
                  java.lang.Object other){
        
//#line 23
if ((!(((boolean)(x10.lang.Place._RTT.instanceof$(other)))))) {
            
//#line 23
return false;
        }
        
//#line 23
return this._struct_equals(((x10.
                                                 lang.
                                                 Place)((new java.lang.Object() {final x10.
                                                 lang.
                                                 Place cast(final x10.
                                                 lang.
                                                 Place self) {if (self==null) return null;x10.rtt.Type rtt = x10.lang.Place._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                                 lang.
                                                 Place) other)))));
    }
    
    
//#line 23
final public boolean
                  _struct_equals(
                  x10.
                    lang.
                    Place other){
        
//#line 23
return ((int) this.
                                    id) ==
        ((int) other.
                 id);
    }

}
