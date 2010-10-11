package x10.io;


public class PutbackReader
extends x10.
  io.
  FilterReader
{public static final x10.rtt.RuntimeType<PutbackReader> _RTT = new x10.rtt.RuntimeType<PutbackReader>(
/* base class */PutbackReader.class
, /* parents */ new x10.rtt.Type[] {x10.io.FilterReader._RTT}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 17
final public x10.core.GrowableRail<java.lang.Byte>
      putback;
    
    
//#line 19
public x10.core.GrowableRail<java.lang.Byte>
                  putback(
                  ){
        
//#line 19
return x10.
          io.
          PutbackReader.__$closure$apply$__2003(((x10.core.GrowableRail)(((x10.core.GrowableRail)
                                                                           putback))));
    }
    
    
//#line 20
public PutbackReader(final x10.
                                       io.
                                       Reader r) {
        
//#line 21
super(r);
        
//#line 22
this.putback = new x10.core.GrowableRail<java.lang.Byte>(x10.rtt.Types.BYTE);
    }
    
    
//#line 25
public byte
                  read(
                  )
                      throws java.io.IOException{
        
//#line 26
if (((((int)((this.putback()).length()))) > (((int)(0))))) {
            
//#line 27
final byte p =
              (this.putback()).apply$G(((int)(((((int)((this.putback()).length()))) - (((int)(1)))))));
            
//#line 28
(this.putback()).removeLast();
            
//#line 29
return p;
        }
        
//#line 31
return super.read();
    }
    
    
//#line 34
public void
                  putback(
                  final byte p){
        
//#line 35
(this.putback()).add(((java.lang.Byte)(p)));
    }
    
    final private static x10.core.GrowableRail<java.lang.Byte>
      __$closure$apply$__2003(
      final x10.core.GrowableRail<java.lang.Byte> __desugarer__var__38__){
        
//#line 19
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__38__,null)) &&
                          !(x10.rtt.Equality.equalsequals(((x10.
                              lang.
                              Place)(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__38__)))),x10.
                              lang.
                              Runtime.here()))) {
            
//#line 19
throw new java.lang.ClassCastException("x10.util.GrowableRail[x10.lang.Byte]{self.home==here}");
        }
        
//#line 19
return __desugarer__var__38__;
    }
    
    final public static x10.core.GrowableRail<java.lang.Byte>
      __$closure$apply$__2003$P(
      final x10.core.GrowableRail<java.lang.Byte> __desugarer__var__38__){
        return PutbackReader.__$closure$apply$__2003(((x10.core.GrowableRail)(__desugarer__var__38__)));
    }
    
    final public byte
      x10$io$PutbackReader$read$S(
      )
          throws java.io.IOException{
        return super.read();
    }

}
