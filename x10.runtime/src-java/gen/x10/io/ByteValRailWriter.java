package x10.io;


public class ByteValRailWriter
extends x10.
  io.
  ByteWriter<x10.core.ValRail<java.lang.Byte>>
{public static final x10.rtt.RuntimeType<ByteValRailWriter> _RTT = new x10.rtt.RuntimeType<ByteValRailWriter>(
/* base class */ByteValRailWriter.class
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.io.ByteWriter._RTT, new x10.rtt.ParameterizedType(new x10.rtt.RuntimeType(x10.core.ValRail.class), x10.rtt.Types.BYTE))}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}


// bridge for method global public x10.io.ByteWriter.result(): T
public x10.core.ValRail<java.lang.Byte>
  result(){return super.result$G();}

    
    
//#line 17
public ByteValRailWriter() {
        
//#line 17
super(new x10.rtt.ParameterizedType(x10.core.ValRail._RTT, x10.rtt.Types.BYTE),
                          ((x10.
                            util.
                            Builder)
                            new x10.
                            util.
                            ValRailBuilder<java.lang.Byte>(x10.rtt.Types.BYTE)));
    }
    
    
//#line 18
public x10.core.ValRail<java.lang.Byte>
                  toValRail(
                  ){
        
//#line 18
return this.result$G();
    }

}
