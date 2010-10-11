package x10.io;

abstract public class Reader
extends x10.core.Ref
{public static final x10.rtt.RuntimeType<Reader> _RTT = new x10.rtt.RuntimeType<Reader>(
/* base class */Reader.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
    
//#line 30
abstract public void
                  close(
                  )
                      throws java.io.IOException;
    
    
//#line 32
abstract public byte
                  read(
                  )
                      throws java.io.IOException;
    
    
//#line 33
abstract public int
                  available(
                  )
                      throws java.io.IOException;
    
    
//#line 35
abstract public void
                  skip(
                  final int id$89)
                      throws java.io.IOException;
    
    
//#line 37
abstract public void
                  mark(
                  final int id$90)
                      throws java.io.IOException;
    
    
//#line 38
abstract public void
                  reset(
                  )
                      throws java.io.IOException;
    
    
//#line 39
abstract public boolean
                  markSupported(
                  );
    
    
//#line 41
public boolean
                  readBoolean(
                  )
                      throws java.io.IOException{
        
//#line 41
return x10.
          io.
          Marshal.BOOLEAN.read(((x10.
                                 io.
                                 Reader)(this)));
    }
    
    
//#line 42
public byte
                  readByte(
                  )
                      throws java.io.IOException{
        
//#line 42
return x10.
          io.
          Marshal.BYTE.read(((x10.
                              io.
                              Reader)(this)));
    }
    
    
//#line 43
public char
                  readChar(
                  )
                      throws java.io.IOException{
        
//#line 43
return x10.
          io.
          Marshal.CHAR.read(((x10.
                              io.
                              Reader)(this)));
    }
    
    
//#line 44
public short
                  readShort(
                  )
                      throws java.io.IOException{
        
//#line 44
return x10.
          io.
          Marshal.SHORT.read(((x10.
                               io.
                               Reader)(this)));
    }
    
    
//#line 45
public int
                  readInt(
                  )
                      throws java.io.IOException{
        
//#line 45
return x10.
          io.
          Marshal.INT.read(((x10.
                             io.
                             Reader)(this)));
    }
    
    
//#line 46
public long
                  readLong(
                  )
                      throws java.io.IOException{
        
//#line 46
return x10.
          io.
          Marshal.LONG.read(((x10.
                              io.
                              Reader)(this)));
    }
    
    
//#line 47
public float
                  readFloat(
                  )
                      throws java.io.IOException{
        
//#line 47
return x10.
          io.
          Marshal.FLOAT.read(((x10.
                               io.
                               Reader)(this)));
    }
    
    
//#line 48
public double
                  readDouble(
                  )
                      throws java.io.IOException{
        
//#line 48
return x10.
          io.
          Marshal.DOUBLE.read(((x10.
                                io.
                                Reader)(this)));
    }
    
    
//#line 49
public java.lang.String
                  readLine(
                  )
                      throws java.io.IOException{
        
//#line 49
return x10.
          io.
          Marshal.LINE.read(((x10.
                              io.
                              Reader)(this)));
    }
    
    
//#line 51
final public <T> T
                  read$G(
                  final x10.rtt.Type T,
                  final x10.
                    io.
                    Marshal<T> m)
                      throws java.io.IOException{
        
//#line 51
return m.read$G(((x10.
                                      io.
                                      Reader)(this)));
    }
    
    
//#line 53
final public <T> void
                  read(
                  final x10.rtt.Type T,
                  final x10.
                    io.
                    Marshal<T> m,
                  final x10.core.Rail<T> a)
                      throws java.io.IOException{
        {
            
//#line 54
this.<T>read(T,
                                     ((x10.
                                       io.
                                       Marshal)(m)),
                                     ((x10.core.Rail)(a)),
                                     (int)(0),
                                     (int)(a.
                                             length));
            
//#line 54
return;
        }
    }
    
    
//#line 55
final public <T> void
                  read(
                  final x10.rtt.Type T,
                  final x10.
                    io.
                    Marshal<T> m,
                  final x10.core.Rail<T> a,
                  final int off,
                  final int len)
                      throws java.io.IOException{
        
//#line 56
for (
//#line 56
int i =
                           off;
                         ((((int)(i))) < (((int)(((((int)(off))) + (((int)(len))))))));
                         
//#line 56
i = ((((int)(i))) + (((int)(1))))) {
            
//#line 57
(a).set$G(this.<T>read$G(T,
                                                 ((x10.
                                                   io.
                                                   Marshal)(m))), ((int)(i)));
        }
    }
    
    
//#line 91
public x10.
                  io.
                  ReaderIterator<java.lang.String>
                  lines(
                  ){
        
//#line 91
return new x10.
          io.
          ReaderIterator<java.lang.String>(x10.rtt.Types.STR,
                                           x10.
                                             io.
                                             Marshal.LINE,
                                           this);
    }
    
    
//#line 92
public x10.
                  io.
                  ReaderIterator<java.lang.Character>
                  chars(
                  ){
        
//#line 92
return new x10.
          io.
          ReaderIterator<java.lang.Character>(x10.rtt.Types.CHAR,
                                              x10.
                                                io.
                                                Marshal.CHAR,
                                              this);
    }
    
    
//#line 93
public x10.
                  io.
                  ReaderIterator<java.lang.Byte>
                  bytes(
                  ){
        
//#line 93
return new x10.
          io.
          ReaderIterator<java.lang.Byte>(x10.rtt.Types.BYTE,
                                         x10.
                                           io.
                                           Marshal.BYTE,
                                         this);
    }
    
    
//#line 29
public Reader() {
        
//#line 29
super();
    }

}
