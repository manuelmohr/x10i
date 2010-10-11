package x10.io;


public class ByteRailWriter
extends x10.
  io.
  ByteWriter<x10.core.Rail<java.lang.Byte>>
{public static final x10.rtt.RuntimeType<ByteRailWriter> _RTT = new x10.rtt.RuntimeType<ByteRailWriter>(
/* base class */ByteRailWriter.class
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.io.ByteWriter._RTT, new x10.rtt.ParameterizedType(new x10.rtt.RuntimeType(x10.core.Rail.class), x10.rtt.Types.BYTE))}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}


// bridge for method global public x10.io.ByteWriter.result(): T
public x10.core.Rail<java.lang.Byte>
  result(){return super.result$G();}

    
    
//#line 17
public ByteRailWriter() {
        
//#line 17
super(new x10.rtt.ParameterizedType(x10.core.Rail._RTT, x10.rtt.Types.BYTE),
                          ((x10.
                            util.
                            Builder)
                            new x10.
                            util.
                            RailBuilder<java.lang.Byte>(x10.rtt.Types.BYTE)));
    }
    
    
//#line 18
public x10.core.Rail<java.lang.Byte>
                  toRail(
                  ){
        
//#line 18
return this.result$G();
    }

}
