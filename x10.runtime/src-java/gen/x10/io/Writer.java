package x10.io;


abstract public class Writer
extends x10.core.Ref
{public static final x10.rtt.RuntimeType<Writer> _RTT = new x10.rtt.RuntimeType<Writer>(
/* base class */Writer.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
    
//#line 31
abstract public void
                  close(
                  )
                      throws java.io.IOException;
    
    
//#line 32
abstract public void
                  flush(
                  )
                      throws java.io.IOException;
    
    
//#line 33
abstract public void
                  write(
                  final byte x)
                      throws java.io.IOException;
    
    
//#line 35
public void
                  writeByte(
                  final byte x)
                      throws java.io.IOException{
        {
            
//#line 35
x10.
              io.
              Marshal.BYTE.write(((x10.
                                   io.
                                   Writer)(this)),
                                 (byte)(x));
            
//#line 35
return;
        }
    }
    
    
//#line 36
public void
                  writeChar(
                  final char x)
                      throws java.io.IOException{
        {
            
//#line 36
x10.
              io.
              Marshal.CHAR.write(((x10.
                                   io.
                                   Writer)(this)),
                                 (char)(x));
            
//#line 36
return;
        }
    }
    
    
//#line 37
public void
                  writeShort(
                  final short x)
                      throws java.io.IOException{
        {
            
//#line 37
x10.
              io.
              Marshal.SHORT.write(((x10.
                                    io.
                                    Writer)(this)),
                                  (short)(x));
            
//#line 37
return;
        }
    }
    
    
//#line 38
public void
                  writeInt(
                  final int x)
                      throws java.io.IOException{
        {
            
//#line 38
x10.
              io.
              Marshal.INT.write(((x10.
                                  io.
                                  Writer)(this)),
                                (int)(x));
            
//#line 38
return;
        }
    }
    
    
//#line 39
public void
                  writeLong(
                  final long x)
                      throws java.io.IOException{
        {
            
//#line 39
x10.
              io.
              Marshal.LONG.write(((x10.
                                   io.
                                   Writer)(this)),
                                 (long)(x));
            
//#line 39
return;
        }
    }
    
    
//#line 40
public void
                  writeFloat(
                  final float x)
                      throws java.io.IOException{
        {
            
//#line 40
x10.
              io.
              Marshal.FLOAT.write(((x10.
                                    io.
                                    Writer)(this)),
                                  (float)(x));
            
//#line 40
return;
        }
    }
    
    
//#line 41
public void
                  writeDouble(
                  final double x)
                      throws java.io.IOException{
        {
            
//#line 41
x10.
              io.
              Marshal.DOUBLE.write(((x10.
                                     io.
                                     Writer)(this)),
                                   (double)(x));
            
//#line 41
return;
        }
    }
    
    
//#line 42
public void
                  writeBoolean(
                  final boolean x)
                      throws java.io.IOException{
        {
            
//#line 42
x10.
              io.
              Marshal.BOOLEAN.write(((x10.
                                      io.
                                      Writer)(this)),
                                    (boolean)(x));
            
//#line 42
return;
        }
    }
    
    
//#line 45
final public <T> void
                  write(
                  final x10.rtt.Type T,
                  final x10.
                    io.
                    Marshal<T> m,
                  final T x)
                      throws java.io.IOException{
        {
            
//#line 45
m.write(((x10.
                                  io.
                                  Writer)(this)),
                                ((T)(x)));
            
//#line 45
return;
        }
    }
    
    
//#line 47
public void
                  write(
                  final x10.core.ValRail<java.lang.Byte> buf)
                      throws java.io.IOException{
        
//#line 48
this.write(((x10.core.ValRail)(buf)),
                               (int)(0),
                               (int)(buf.
                                       length));
    }
    
    
//#line 51
public void
                  write(
                  final x10.core.Rail<java.lang.Byte> buf)
                      throws java.io.IOException{
        
//#line 52
this.write(((x10.core.Rail)(buf)),
                               (int)(0),
                               (int)(buf.
                                       length));
    }
    
    
//#line 55
public void
                  write(
                  final x10.core.ValRail<java.lang.Byte> buf,
                  final int off,
                  final int len)
                      throws java.io.IOException{
        {
            
//#line 56
final byte[] buf$value2004 =
              ((byte[])buf.value);
            
//#line 56
for (
//#line 56
int i =
                               off;
                             ((((int)(i))) < (((int)(((((int)(off))) + (((int)(len))))))));
                             
//#line 56
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 57
this.write((byte)(((byte)buf$value2004[i])));
            }
        }
    }
    
    
//#line 61
public void
                  write(
                  final x10.core.Rail<java.lang.Byte> buf,
                  final int off,
                  final int len)
                      throws java.io.IOException{
        {
            
//#line 62
final byte[] buf$value2005 =
              ((byte[])buf.value);
            
//#line 62
for (
//#line 62
int i =
                               off;
                             ((((int)(i))) < (((int)(((((int)(off))) + (((int)(len))))))));
                             
//#line 62
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 63
this.write((byte)(((byte)buf$value2005[i])));
            }
        }
    }
    
    
//#line 67
private java.io.OutputStream
                  oos(
                  ){
        
//#line 69
return new java.lang.Object() { java.io.OutputStream eval(final x10.io.Writer w) { return new java.io.OutputStream() { public void write(int x) throws java.io.IOException { w.write((byte) x); } }; } }.eval(this);
    }
    
    public static java.io.OutputStream
      oos$P(
      final x10.
        io.
        Writer Writer){
        return new java.lang.Object() { java.io.OutputStream eval(final x10.io.Writer w) { return new java.io.OutputStream() { public void write(int x) throws java.io.IOException { w.write((byte) x); } }; } }.eval(Writer);
    }
    
    
//#line 73
public java.io.OutputStream
                  getNativeOutputStream(
                  ){
        
//#line 73
return new java.lang.Object() { java.io.OutputStream eval(final x10.io.Writer w) { return new java.io.OutputStream() { public void write(int x) throws java.io.IOException { w.write((byte) x); } }; } }.eval(this);
    }
    
    
//#line 30
public Writer() {
        
//#line 30
super();
    }

}
