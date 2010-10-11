package x10.util;


public class StringBuilder
extends x10.core.Ref
  implements x10.
               util.
               Builder<java.lang.Object, java.lang.String>
{public static final x10.rtt.RuntimeType<StringBuilder> _RTT = new x10.rtt.RuntimeType<StringBuilder>(
/* base class */StringBuilder.class
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.util.Builder._RTT, x10.rtt.Types.runtimeType(java.lang.Object.class), x10.rtt.Types.STR), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}


// bridge for method abstract public x10.util.Builder.result(): Collection
public java.lang.String
  result$G(){return result();}

    
//#line 17
final public x10.
      util.
      ValRailBuilder<java.lang.Character>
      buf;
    
    
//#line 19
public StringBuilder() {
        super();
        
//#line 20
this.buf = ((x10.
          util.
          ValRailBuilder)(new x10.
          util.
          ValRailBuilder<java.lang.Character>(x10.rtt.Types.CHAR)));
    }
    
    
//#line 31
public java.lang.String
                  toString(
                  ){
        
//#line 32
if ((!(((boolean)(x10.core.Ref.at((java.lang.Object)(this), x10.
                          lang.
                          Runtime.here().id)))))) {
            
//#line 32
throw new java.lang.UnsupportedOperationException();
        }
        
//#line 33
return (x10.
                              util.
                              StringBuilder.__$closure$apply$__2093(((x10.
                                                                      util.
                                                                      StringBuilder)(((x10.
                                                                                       util.
                                                                                       StringBuilder)
                                                                                       this))))).result();
    }
    
    
//#line 36
public x10.
                  util.
                  StringBuilder
                  add(
                  final java.lang.Object o){
        
//#line 37
if (x10.rtt.Equality.equalsequals(o,null)) {
            
//#line 38
return this.addString(((java.lang.String)("null")));
        } else {
            
//#line 40
return this.addString(((java.lang.String)(((java.lang.Object)((x10.
                                                                                         util.
                                                                                         StringBuilder.__$closure$apply$__2094(((java.lang.Object)(((java.lang.Object)
                                                                                                                                                     o))))))).toString())));
        }
    }
    
    
//#line 43
public x10.
                  util.
                  StringBuilder
                  insert(
                  final int p,
                  final java.lang.Object o){
        
//#line 44
if (x10.rtt.Equality.equalsequals(o,null)) {
            
//#line 45
return this.insertString((int)(p),
                                                 ((java.lang.String)("null")));
        } else {
            
//#line 47
return this.insertString((int)(p),
                                                 ((java.lang.String)(((java.lang.Object)((x10.
                                                                                            util.
                                                                                            StringBuilder.__$closure$apply$__2095(((java.lang.Object)(((java.lang.Object)
                                                                                                                                                        o))))))).toString())));
        }
    }
    
    
//#line 50
public x10.
                  util.
                  StringBuilder
                  add(
                  final char x){
        
//#line 51
buf.add((java.lang.Character)(x));
        
//#line 52
return this;
    }
    
    
//#line 55
public x10.
                  util.
                  StringBuilder
                  add(
                  final boolean x){
        
//#line 55
return this.addString(((java.lang.String)(java.lang.Boolean.toString(x))));
    }
    
    
//#line 56
public x10.
                  util.
                  StringBuilder
                  add(
                  final byte x){
        
//#line 56
return this.addString(((java.lang.String)(java.lang.Byte.toString(x))));
    }
    
    
//#line 57
public x10.
                  util.
                  StringBuilder
                  add(
                  final short x){
        
//#line 57
return this.addString(((java.lang.String)(java.lang.Short.toString(x))));
    }
    
    
//#line 58
public x10.
                  util.
                  StringBuilder
                  add(
                  final int x){
        
//#line 58
return this.addString(((java.lang.String)(java.lang.Integer.toString(x))));
    }
    
    
//#line 59
public x10.
                  util.
                  StringBuilder
                  add(
                  final long x){
        
//#line 59
return this.addString(((java.lang.String)(java.lang.Long.toString(x))));
    }
    
    
//#line 60
public x10.
                  util.
                  StringBuilder
                  add(
                  final float x){
        
//#line 60
return this.addString(((java.lang.String)(java.lang.Float.toString(x))));
    }
    
    
//#line 61
public x10.
                  util.
                  StringBuilder
                  add(
                  final double x){
        
//#line 61
return this.addString(((java.lang.String)(java.lang.Double.toString(x))));
    }
    
    
//#line 62
public x10.
                  util.
                  StringBuilder
                  add(
                  final java.lang.String x){
        
//#line 62
return this.addString(((java.lang.String)(x)));
    }
    
    
//#line 64
public x10.
                  util.
                  StringBuilder
                  insert(
                  final int p,
                  final boolean x){
        
//#line 64
return this.insertString((int)(p),
                                             ((java.lang.String)(java.lang.Boolean.toString(x))));
    }
    
    
//#line 65
public x10.
                  util.
                  StringBuilder
                  insert(
                  final int p,
                  final byte x){
        
//#line 65
return this.insertString((int)(p),
                                             ((java.lang.String)(java.lang.Byte.toString(x))));
    }
    
    
//#line 66
public x10.
                  util.
                  StringBuilder
                  insert(
                  final int p,
                  final char x){
        
//#line 66
return this.insertString((int)(p),
                                             ((java.lang.String)(java.lang.Character.toString(x))));
    }
    
    
//#line 67
public x10.
                  util.
                  StringBuilder
                  insert(
                  final int p,
                  final short x){
        
//#line 67
return this.insertString((int)(p),
                                             ((java.lang.String)(java.lang.Short.toString(x))));
    }
    
    
//#line 68
public x10.
                  util.
                  StringBuilder
                  insert(
                  final int p,
                  final int x){
        
//#line 68
return this.insertString((int)(p),
                                             ((java.lang.String)(java.lang.Integer.toString(x))));
    }
    
    
//#line 69
public x10.
                  util.
                  StringBuilder
                  insert(
                  final int p,
                  final long x){
        
//#line 69
return this.insertString((int)(p),
                                             ((java.lang.String)(java.lang.Long.toString(x))));
    }
    
    
//#line 70
public x10.
                  util.
                  StringBuilder
                  insert(
                  final int p,
                  final float x){
        
//#line 70
return this.insertString((int)(p),
                                             ((java.lang.String)(java.lang.Float.toString(x))));
    }
    
    
//#line 71
public x10.
                  util.
                  StringBuilder
                  insert(
                  final int p,
                  final double x){
        
//#line 71
return this.insertString((int)(p),
                                             ((java.lang.String)(java.lang.Double.toString(x))));
    }
    
    
//#line 72
public x10.
                  util.
                  StringBuilder
                  insert(
                  final int p,
                  final java.lang.String x){
        
//#line 72
return this.insertString((int)(p),
                                             ((java.lang.String)(x)));
    }
    
    
//#line 74
public x10.
                  util.
                  StringBuilder
                  addString(
                  final java.lang.String s){
        
//#line 75
for (
//#line 75
int i =
                           0;
                         ((((int)(i))) < (((int)((s).length()))));
                         
//#line 75
i = ((((int)(i))) + (((int)(1))))) {
            
//#line 76
final char ch =
              (s).charAt(((int)(i)));
            
//#line 77
buf.add((java.lang.Character)(ch));
        }
        
//#line 85
return this;
    }
    
    
//#line 88
public x10.
                  util.
                  StringBuilder
                  insertString(
                  final int pos,
                  final java.lang.String s){
        
//#line 89
int loc =
          pos;
        
//#line 90
if (((int) (s).length()) ==
                        ((int) 0)) {
            
//#line 91
return this;
        }
        
//#line 93
if (((((int)(loc))) > (((int)(buf.length()))))) {
            
//#line 94
return this.addString(((java.lang.String)(s)));
        }
        
//#line 97
if (((((int)(loc))) < (((int)(0))))) {
            
//#line 98
loc = 0;
        }
        
//#line 99
buf.insert((int)(loc),
                               ((x10.core.ValRail)(x10.core.RailFactory.<java.lang.Character>makeValRailFromJavaArray(x10.rtt.Types.CHAR, (s).toCharArray()))));
        
//#line 100
return this;
    }
    
    
//#line 103
public int
                   length(
                   ){
        
//#line 104
return buf.length();
    }
    
    
//#line 107
native private static java.lang.String
                   makeString(
                   final x10.core.ValRail<java.lang.Character> id$174);
    
    public static java.lang.String
      makeString$P(
      final x10.core.ValRail<java.lang.Character> id$174){
        return new String(id$174.getCharArray());
    }
    
    
//#line 111
public java.lang.String
                   result(
                   ){
        
//#line 111
return new String(buf.result().getCharArray());
    }
    
    final private static x10.
      util.
      StringBuilder
      __$closure$apply$__2093(
      final x10.
        util.
        StringBuilder __desugarer__var__79__){
        
//#line 33
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__79__,null)) &&
                          !(x10.rtt.Equality.equalsequals(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__79__)),x10.
                              lang.
                              Runtime.here()))) {
            
//#line 33
throw new java.lang.ClassCastException("x10.util.StringBuilder{self.home==here}");
        }
        
//#line 33
return __desugarer__var__79__;
    }
    
    final public static x10.
      util.
      StringBuilder
      __$closure$apply$__2093$P(
      final x10.
        util.
        StringBuilder __desugarer__var__79__){
        return StringBuilder.__$closure$apply$__2093(((x10.
                                                       util.
                                                       StringBuilder)(__desugarer__var__79__)));
    }
    
    final private static java.lang.Object
      __$closure$apply$__2094(
      final java.lang.Object __desugarer__var__80__){
        
//#line 40
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__80__,null)) &&
                          !(x10.rtt.Equality.equalsequals(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__80__)),x10.
                              lang.
                              Runtime.here()))) {
            
//#line 40
throw new java.lang.ClassCastException("x10.lang.Object{self.home==here}");
        }
        
//#line 40
return __desugarer__var__80__;
    }
    
    final public static java.lang.Object
      __$closure$apply$__2094$P(
      final java.lang.Object __desugarer__var__80__){
        return StringBuilder.__$closure$apply$__2094(((java.lang.Object)(__desugarer__var__80__)));
    }
    
    final private static java.lang.Object
      __$closure$apply$__2095(
      final java.lang.Object __desugarer__var__81__){
        
//#line 47
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__81__,null)) &&
                          !(x10.rtt.Equality.equalsequals(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__81__)),x10.
                              lang.
                              Runtime.here()))) {
            
//#line 47
throw new java.lang.ClassCastException("x10.lang.Object{self.home==here}");
        }
        
//#line 47
return __desugarer__var__81__;
    }
    
    final public static java.lang.Object
      __$closure$apply$__2095$P(
      final java.lang.Object __desugarer__var__81__){
        return StringBuilder.__$closure$apply$__2095(((java.lang.Object)(__desugarer__var__81__)));
    }

}
