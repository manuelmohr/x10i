package x10.io;


public interface Marshal<T>
{public static final x10.rtt.RuntimeType<Marshal> _RTT = new x10.rtt.RuntimeType<Marshal>(
/* base class */Marshal.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);

    
    
    
//#line 31
T
                  read$G(
                  final x10.
                    io.
                    Reader r)
                      throws java.io.IOException;
    
    
//#line 32
void
                  write(
                  final x10.
                    io.
                    Writer w,
                  final T id$77)
                      throws java.io.IOException;
    
    
//#line 34
x10.
      io.
      Marshal.
      BooleanMarshal
      BOOLEAN =
      ((x10.
      io.
      Marshal.
      BooleanMarshal)(new x10.
      io.
      Marshal.
      BooleanMarshal()));
    
//#line 35
x10.
      io.
      Marshal.
      ByteMarshal
      BYTE =
      ((x10.
      io.
      Marshal.
      ByteMarshal)(new x10.
      io.
      Marshal.
      ByteMarshal()));
    
//#line 36
x10.
      io.
      Marshal.
      CharMarshal
      CHAR =
      ((x10.
      io.
      Marshal.
      CharMarshal)(new x10.
      io.
      Marshal.
      CharMarshal()));
    
//#line 37
x10.
      io.
      Marshal.
      ShortMarshal
      SHORT =
      ((x10.
      io.
      Marshal.
      ShortMarshal)(new x10.
      io.
      Marshal.
      ShortMarshal()));
    
//#line 38
x10.
      io.
      Marshal.
      IntMarshal
      INT =
      ((x10.
      io.
      Marshal.
      IntMarshal)(new x10.
      io.
      Marshal.
      IntMarshal()));
    
//#line 39
x10.
      io.
      Marshal.
      LongMarshal
      LONG =
      ((x10.
      io.
      Marshal.
      LongMarshal)(new x10.
      io.
      Marshal.
      LongMarshal()));
    
//#line 40
x10.
      io.
      Marshal.
      FloatMarshal
      FLOAT =
      ((x10.
      io.
      Marshal.
      FloatMarshal)(new x10.
      io.
      Marshal.
      FloatMarshal()));
    
//#line 41
x10.
      io.
      Marshal.
      DoubleMarshal
      DOUBLE =
      ((x10.
      io.
      Marshal.
      DoubleMarshal)(new x10.
      io.
      Marshal.
      DoubleMarshal()));
    
//#line 42
x10.
      io.
      Marshal.
      LineMarshal
      LINE =
      ((x10.
      io.
      Marshal.
      LineMarshal)(new x10.
      io.
      Marshal.
      LineMarshal()));
    
//#line 44
public static class LineMarshal
                extends x10.core.Ref
                  implements x10.
                               io.
                               Marshal<java.lang.String>
                {public static final x10.rtt.RuntimeType<LineMarshal> _RTT = new x10.rtt.RuntimeType<LineMarshal>(
    /* base class */LineMarshal.class
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.io.Marshal._RTT, x10.rtt.Types.STR), x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    // bridge for method abstract global public x10.io.Marshal.read(r:x10.io.Reader): T throws x10.io.IOException
    public java.lang.String
      read$G(x10.
      io.
      Reader a1)
          throws java.io.IOException{return read( a1);}
    
        
        
//#line 45
public java.lang.String
                      read(
                      final x10.
                        io.
                        Reader r)
                          throws java.io.IOException{
            
//#line 46
final x10.
              util.
              StringBuilder sb =
              ((x10.
              util.
              StringBuilder)(new x10.
              util.
              StringBuilder()));
            
//#line 47
char ch;
            
//#line 48
do  {
                
//#line 49
ch = x10.
                  io.
                  Marshal.CHAR.read(((x10.
                                      io.
                                      Reader)(r)));
                
//#line 50
sb.add((char)(ch));
            }while(((char) ch) !=
                   ((char) '\n')); 
            
//#line 52
return sb.result();
        }
        
        
//#line 54
public void
                      write(
                      final x10.
                        io.
                        Writer w,
                      final java.lang.String s)
                          throws java.io.IOException{
            
//#line 55
for (
//#line 55
int i =
                               0;
                             ((((int)(i))) < (((int)((s).length()))));
                             
//#line 55
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 56
final char ch =
                  (s).charAt(((int)(i)));
                
//#line 57
x10.
                  io.
                  Marshal.CHAR.write(((x10.
                                       io.
                                       Writer)(w)),
                                     (char)(ch));
            }
        }
        
        
//#line 44
public LineMarshal() {
            
//#line 44
super();
        }
    
    }
    
    
//#line 68
public static class BooleanMarshal
                extends x10.core.Ref
                  implements x10.
                               io.
                               Marshal<java.lang.Boolean>
                {public static final x10.rtt.RuntimeType<BooleanMarshal> _RTT = new x10.rtt.RuntimeType<BooleanMarshal>(
    /* base class */BooleanMarshal.class
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.io.Marshal._RTT, x10.rtt.Types.BOOLEAN), x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    // bridge for method abstract global public x10.io.Marshal.read(r:x10.io.Reader): T throws x10.io.IOException
    public java.lang.Boolean
      read$G(x10.
      io.
      Reader a1)
          throws java.io.IOException{return read( a1);}
    // bridge for method abstract global public x10.io.Marshal.write(w:x10.io.Writer,id$77:T): x10.lang.Void throws x10.io.IOException
    public void
      write(x10.
      io.
      Writer a1,
    java.lang.Boolean a2)
          throws java.io.IOException{write( a1,
    (boolean) a2);}
    
        
        
//#line 69
public boolean
                      read(
                      final x10.
                        io.
                        Reader r)
                          throws java.io.IOException{
            
//#line 69
return ((int) ((int)(byte)(((byte)(r.read()))))) !=
            ((int) 0);
        }
        
        
//#line 70
public void
                      write(
                      final x10.
                        io.
                        Writer w,
                      final boolean b)
                          throws java.io.IOException{
            {
                
//#line 70
w.write((byte)(((byte)(int)(((int)((b
                                                                  ? 0
                                                                  : 1)))))));
                
//#line 70
return;
            }
        }
        
        
//#line 68
public BooleanMarshal() {
            
//#line 68
super();
        }
    
    }
    
    
//#line 73
public static class ByteMarshal
                extends x10.core.Ref
                  implements x10.
                               io.
                               Marshal<java.lang.Byte>
                {public static final x10.rtt.RuntimeType<ByteMarshal> _RTT = new x10.rtt.RuntimeType<ByteMarshal>(
    /* base class */ByteMarshal.class
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.io.Marshal._RTT, x10.rtt.Types.BYTE), x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    // bridge for method abstract global public x10.io.Marshal.read(r:x10.io.Reader): T throws x10.io.IOException
    public java.lang.Byte
      read$G(x10.
      io.
      Reader a1)
          throws java.io.IOException{return read( a1);}
    // bridge for method abstract global public x10.io.Marshal.write(w:x10.io.Writer,id$77:T): x10.lang.Void throws x10.io.IOException
    public void
      write(x10.
      io.
      Writer a1,
    java.lang.Byte a2)
          throws java.io.IOException{write( a1,
    (byte) a2);}
    
        
        
//#line 74
public byte
                      read(
                      final x10.
                        io.
                        Reader r)
                          throws java.io.IOException{
            
//#line 74
return r.read();
        }
        
        
//#line 75
public void
                      write(
                      final x10.
                        io.
                        Writer w,
                      final byte b)
                          throws java.io.IOException{
            {
                
//#line 75
w.write((byte)(b));
                
//#line 75
return;
            }
        }
        
        
//#line 73
public ByteMarshal() {
            
//#line 73
super();
        }
    
    }
    
    
//#line 78
public static class CharMarshal
                extends x10.core.Ref
                  implements x10.
                               io.
                               Marshal<java.lang.Character>
                {public static final x10.rtt.RuntimeType<CharMarshal> _RTT = new x10.rtt.RuntimeType<CharMarshal>(
    /* base class */CharMarshal.class
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.io.Marshal._RTT, x10.rtt.Types.CHAR), x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    // bridge for method abstract global public x10.io.Marshal.read(r:x10.io.Reader): T throws x10.io.IOException
    public java.lang.Character
      read$G(x10.
      io.
      Reader a1)
          throws java.io.IOException{return read( a1);}
    // bridge for method abstract global public x10.io.Marshal.write(w:x10.io.Writer,id$77:T): x10.lang.Void throws x10.io.IOException
    public void
      write(x10.
      io.
      Writer a1,
    java.lang.Character a2)
          throws java.io.IOException{write( a1,
    (char) a2);}
    
        
        
//#line 79
public char
                      read(
                      final x10.
                        io.
                        Reader r)
                          throws java.io.IOException{
            
//#line 80
final byte b1 =
              r.read();
            
//#line 81
if (((int) ((int)(byte)(((byte)(b1))))) ==
                            ((int) -1)) {
                
//#line 81
throw new java.io.EOFException();
            }
            
//#line 82
if (((int) ((((((int)(((int)(byte)(((byte)(b1))))))) & (((int)(248))))))) ==
                            ((int) 240)) {
                
//#line 83
final byte b2 =
                  r.read();
                
//#line 84
final byte b3 =
                  r.read();
                
//#line 85
final byte b4 =
                  r.read();
                
//#line 86
return ((char) (((int)(((((int)(((((int)(((((int)((((((int)((((((int)(((int)(byte)(((byte)(b1))))))) & (((int)(3)))))))) << (((int)(18)))))))) | (((int)((((((int)((((((int)(((int)(byte)(((byte)(b2))))))) & (((int)(63)))))))) << (((int)(12)))))))))))) | (((int)((((((int)((((((int)(((int)(byte)(((byte)(b3))))))) & (((int)(63)))))))) << (((int)(6)))))))))))) | (((int)((((((int)(((int)(byte)(((byte)(b4))))))) & (((int)(63)))))))))))));
            }
            
//#line 88
if (((int) ((((((int)(((int)(byte)(((byte)(b1))))))) & (((int)(240))))))) ==
                            ((int) 224)) {
                
//#line 89
final byte b2 =
                  r.read();
                
//#line 90
final byte b3 =
                  r.read();
                
//#line 91
return ((char) (((int)(((((int)(((((int)((((((int)((((((int)(((int)(byte)(((byte)(b1))))))) & (((int)(31)))))))) << (((int)(12)))))))) | (((int)((((((int)((((((int)(((int)(byte)(((byte)(b2))))))) & (((int)(63)))))))) << (((int)(6)))))))))))) | (((int)((((((int)(((int)(byte)(((byte)(b3))))))) & (((int)(63)))))))))))));
            }
            
//#line 93
if (((int) ((((((int)(((int)(byte)(((byte)(b1))))))) & (((int)(224))))))) ==
                            ((int) 192)) {
                
//#line 94
final byte b2 =
                  r.read();
                
//#line 95
return ((char) (((int)(((((int)((((((int)((((((int)(((int)(byte)(((byte)(b1))))))) & (((int)(31)))))))) << (((int)(6)))))))) | (((int)((((((int)(((int)(byte)(((byte)(b2))))))) & (((int)(63)))))))))))));
            }
            
//#line 98
return ((char) (((int)(((int)(byte)(((byte)(b1))))))));
        }
        
        
//#line 101
public void
                       write(
                       final x10.
                         io.
                         Writer w,
                       final char c)
                           throws java.io.IOException{
            
//#line 102
final int i =
              ((int) (c));
            
//#line 103
if (((int) ((((((int)(i))) & (((int)(0xffffff80))))))) ==
                             ((int) 0)) {
                
//#line 104
w.write((byte)(((byte)(int)(((int)(i))))));
                
//#line 105
return;
            }
            
//#line 107
if (((int) ((((((int)(i))) & (((int)(0xfffff800))))))) ==
                             ((int) 0)) {
                
//#line 108
w.write((byte)(((byte)(int)(((int)((((((int)((((((int)((((((int)(i))) >> (((int)(6)))))))) & (((int)(31)))))))) | (((int)(192)))))))))));
                
//#line 109
w.write((byte)(((byte)(int)(((int)((((((int)((((((int)(i))) & (((int)(63)))))))) | (((int)(128)))))))))));
                
//#line 110
return;
            }
            
//#line 112
if (((int) ((((((int)(i))) & (((int)(0xffff0000))))))) ==
                             ((int) 0)) {
                
//#line 113
w.write((byte)(((byte)(int)(((int)((((((int)((((((int)((((((int)(i))) >> (((int)(12)))))))) & (((int)(15)))))))) | (((int)(224)))))))))));
                
//#line 114
w.write((byte)(((byte)(int)(((int)((((((int)((((((int)((((((int)(i))) >> (((int)(6)))))))) & (((int)(63)))))))) | (((int)(128)))))))))));
                
//#line 115
w.write((byte)(((byte)(int)(((int)((((((int)((((((int)(i))) & (((int)(63)))))))) | (((int)(128)))))))))));
                
//#line 116
return;
            }
            
//#line 118
if (((int) ((((((int)(i))) & (((int)(0xffe00000))))))) ==
                             ((int) 0)) {
                
//#line 119
w.write((byte)(((byte)(int)(((int)((((((int)((((((int)((((((int)(i))) >> (((int)(18)))))))) & (((int)(7)))))))) | (((int)(240)))))))))));
                
//#line 120
w.write((byte)(((byte)(int)(((int)((((((int)((((((int)((((((int)(i))) >> (((int)(12)))))))) & (((int)(63)))))))) | (((int)(128)))))))))));
                
//#line 121
w.write((byte)(((byte)(int)(((int)((((((int)((((((int)((((((int)(i))) >> (((int)(6)))))))) & (((int)(63)))))))) | (((int)(128)))))))))));
                
//#line 122
w.write((byte)(((byte)(int)(((int)((((((int)((((((int)(i))) & (((int)(63)))))))) | (((int)(128)))))))))));
                
//#line 123
return;
            }
        }
        
        
//#line 78
public CharMarshal() {
            
//#line 78
super();
        }
    
    }
    
    
//#line 128
public static class ShortMarshal
                 extends x10.core.Ref
                   implements x10.
                                io.
                                Marshal<java.lang.Short>
                 {public static final x10.rtt.RuntimeType<ShortMarshal> _RTT = new x10.rtt.RuntimeType<ShortMarshal>(
    /* base class */ShortMarshal.class
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.io.Marshal._RTT, x10.rtt.Types.SHORT), x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    // bridge for method abstract global public x10.io.Marshal.read(r:x10.io.Reader): T throws x10.io.IOException
    public java.lang.Short
      read$G(x10.
      io.
      Reader a1)
          throws java.io.IOException{return read( a1);}
    // bridge for method abstract global public x10.io.Marshal.write(w:x10.io.Writer,id$77:T): x10.lang.Void throws x10.io.IOException
    public void
      write(x10.
      io.
      Writer a1,
    java.lang.Short a2)
          throws java.io.IOException{write( a1,
    (short) a2);}
    
        
        
//#line 129
public short
                       read(
                       final x10.
                         io.
                         Reader r)
                           throws java.io.IOException{
            
//#line 130
final byte b1 =
              r.read();
            
//#line 131
final byte b2 =
              r.read();
            
//#line 132
return ((short)(int)(((int)((((((int)((((((int)((((((int)(((int)(byte)(((byte)(b1))))))) & (((int)(255)))))))) << (((int)(8)))))))) | (((int)((((((int)(((int)(byte)(((byte)(b2))))))) & (((int)(255))))))))))))));
        }
        
        
//#line 135
public void
                       write(
                       final x10.
                         io.
                         Writer w,
                       final short s)
                           throws java.io.IOException{
            
//#line 136
final int i =
              ((int)(short)(((short)(s))));
            
//#line 137
final byte b1 =
              ((byte)(int)(((int)((((((int)(i))) >> (((int)(8)))))))));
            
//#line 138
final byte b2 =
              ((byte)(int)(((int)(i))));
            
//#line 139
w.write((byte)(b1));
            
//#line 140
w.write((byte)(b2));
        }
        
        
//#line 128
public ShortMarshal() {
            
//#line 128
super();
        }
    
    }
    
    
//#line 144
public static class IntMarshal
                 extends x10.core.Ref
                   implements x10.
                                io.
                                Marshal<java.lang.Integer>
                 {public static final x10.rtt.RuntimeType<IntMarshal> _RTT = new x10.rtt.RuntimeType<IntMarshal>(
    /* base class */IntMarshal.class
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.io.Marshal._RTT, x10.rtt.Types.INT), x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    // bridge for method abstract global public x10.io.Marshal.read(r:x10.io.Reader): T throws x10.io.IOException
    public java.lang.Integer
      read$G(x10.
      io.
      Reader a1)
          throws java.io.IOException{return read( a1);}
    // bridge for method abstract global public x10.io.Marshal.write(w:x10.io.Writer,id$77:T): x10.lang.Void throws x10.io.IOException
    public void
      write(x10.
      io.
      Writer a1,
    java.lang.Integer a2)
          throws java.io.IOException{write( a1,
    (int) a2);}
    
        
        
//#line 145
public int
                       read(
                       final x10.
                         io.
                         Reader r)
                           throws java.io.IOException{
            
//#line 146
final byte b1 =
              r.read();
            
//#line 147
final byte b2 =
              r.read();
            
//#line 148
final byte b3 =
              r.read();
            
//#line 149
final byte b4 =
              r.read();
            
//#line 150
return ((int) (int) 
                                  ((((((int)(((((int)(((((int)((((((int)((((((int)(((int)(byte)(((byte)(b1))))))) & (((int)(255)))))))) << (((int)(24)))))))) | (((int)((((((int)((((((int)(((int)(byte)(((byte)(b2))))))) & (((int)(255)))))))) << (((int)(16)))))))))))) | (((int)((((((int)((((((int)(((int)(byte)(((byte)(b3))))))) & (((int)(255)))))))) << (((int)(8)))))))))))) | (((int)((((((int)(((int)(byte)(((byte)(b4))))))) & (((int)(255))))))))))));
        }
        
        
//#line 153
public void
                       write(
                       final x10.
                         io.
                         Writer w,
                       final int i)
                           throws java.io.IOException{
            
//#line 154
final byte b1 =
              ((byte)(int)(((int)((((((int)(i))) >> (((int)(24)))))))));
            
//#line 155
final byte b2 =
              ((byte)(int)(((int)((((((int)(i))) >> (((int)(16)))))))));
            
//#line 156
final byte b3 =
              ((byte)(int)(((int)((((((int)(i))) >> (((int)(8)))))))));
            
//#line 157
final byte b4 =
              ((byte)(int)(((int)(i))));
            
//#line 158
w.write((byte)(b1));
            
//#line 159
w.write((byte)(b2));
            
//#line 160
w.write((byte)(b3));
            
//#line 161
w.write((byte)(b4));
        }
        
        
//#line 144
public IntMarshal() {
            
//#line 144
super();
        }
    
    }
    
    
//#line 165
public static class LongMarshal
                 extends x10.core.Ref
                   implements x10.
                                io.
                                Marshal<java.lang.Long>
                 {public static final x10.rtt.RuntimeType<LongMarshal> _RTT = new x10.rtt.RuntimeType<LongMarshal>(
    /* base class */LongMarshal.class
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.io.Marshal._RTT, x10.rtt.Types.LONG), x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    // bridge for method abstract global public x10.io.Marshal.read(r:x10.io.Reader): T throws x10.io.IOException
    public java.lang.Long
      read$G(x10.
      io.
      Reader a1)
          throws java.io.IOException{return read( a1);}
    // bridge for method abstract global public x10.io.Marshal.write(w:x10.io.Writer,id$77:T): x10.lang.Void throws x10.io.IOException
    public void
      write(x10.
      io.
      Writer a1,
    java.lang.Long a2)
          throws java.io.IOException{write( a1,
    (long) a2);}
    
        
        
//#line 166
public long
                       read(
                       final x10.
                         io.
                         Reader r)
                           throws java.io.IOException{
            
//#line 167
long l =
              0L;
            
//#line 168
for (
//#line 168
int i =
                                0;
                              ((((int)(i))) < (((int)(8))));
                              
//#line 168
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 169
final byte b =
                  r.read();
                
//#line 170
l = ((((long)((((((long)(l))) << (((int)(8)))))))) | (((long)(((long)(((int)((((((int)(((int)(byte)(((byte)(b))))))) & (((int)(255)))))))))))));
            }
            
//#line 172
return l;
        }
        
        
//#line 175
public void
                       write(
                       final x10.
                         io.
                         Writer w,
                       final long l)
                           throws java.io.IOException{
            
//#line 176
int shift =
              64;
            
//#line 177
while (((((int)(shift))) > (((int)(0))))) {
                
//#line 178
shift = ((((int)(shift))) - (((int)(8))));
                
//#line 179
final byte b =
                  ((byte)(long)(((long)((((((long)(l))) >> (((int)(shift)))))))));
                
//#line 180
w.write((byte)(b));
            }
        }
        
        
//#line 165
public LongMarshal() {
            
//#line 165
super();
        }
    
    }
    
    
//#line 185
public static class FloatMarshal
                 extends x10.core.Ref
                   implements x10.
                                io.
                                Marshal<java.lang.Float>
                 {public static final x10.rtt.RuntimeType<FloatMarshal> _RTT = new x10.rtt.RuntimeType<FloatMarshal>(
    /* base class */FloatMarshal.class
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.io.Marshal._RTT, x10.rtt.Types.FLOAT), x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    // bridge for method abstract global public x10.io.Marshal.read(r:x10.io.Reader): T throws x10.io.IOException
    public java.lang.Float
      read$G(x10.
      io.
      Reader a1)
          throws java.io.IOException{return read( a1);}
    // bridge for method abstract global public x10.io.Marshal.write(w:x10.io.Writer,id$77:T): x10.lang.Void throws x10.io.IOException
    public void
      write(x10.
      io.
      Writer a1,
    java.lang.Float a2)
          throws java.io.IOException{write( a1,
    (float) a2);}
    
        
        
//#line 186
public float
                       read(
                       final x10.
                         io.
                         Reader r)
                           throws java.io.IOException{
            
//#line 187
final int i =
              x10.
              io.
              Marshal.INT.read(((x10.
                                 io.
                                 Reader)(r)));
            
//#line 188
return java.lang.Float.intBitsToFloat(((int)(i)));
        }
        
        
//#line 190
public void
                       write(
                       final x10.
                         io.
                         Writer w,
                       final float f)
                           throws java.io.IOException{
            
//#line 191
final int i =
              java.lang.Float.floatToIntBits(f);
            
//#line 192
x10.
              io.
              Marshal.INT.write(((x10.
                                  io.
                                  Writer)(w)),
                                (int)(i));
        }
        
        
//#line 185
public FloatMarshal() {
            
//#line 185
super();
        }
    
    }
    
    
//#line 196
public static class DoubleMarshal
                 extends x10.core.Ref
                   implements x10.
                                io.
                                Marshal<java.lang.Double>
                 {public static final x10.rtt.RuntimeType<DoubleMarshal> _RTT = new x10.rtt.RuntimeType<DoubleMarshal>(
    /* base class */DoubleMarshal.class
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.io.Marshal._RTT, x10.rtt.Types.DOUBLE), x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    // bridge for method abstract global public x10.io.Marshal.read(r:x10.io.Reader): T throws x10.io.IOException
    public java.lang.Double
      read$G(x10.
      io.
      Reader a1)
          throws java.io.IOException{return read( a1);}
    // bridge for method abstract global public x10.io.Marshal.write(w:x10.io.Writer,id$77:T): x10.lang.Void throws x10.io.IOException
    public void
      write(x10.
      io.
      Writer a1,
    java.lang.Double a2)
          throws java.io.IOException{write( a1,
    (double) a2);}
    
        
        
//#line 197
public double
                       read(
                       final x10.
                         io.
                         Reader r)
                           throws java.io.IOException{
            
//#line 198
final long l =
              x10.
              io.
              Marshal.LONG.read(((x10.
                                  io.
                                  Reader)(r)));
            
//#line 199
return java.lang.Double.longBitsToDouble(((long)(l)));
        }
        
        
//#line 201
public void
                       write(
                       final x10.
                         io.
                         Writer w,
                       final double d)
                           throws java.io.IOException{
            
//#line 202
final long l =
              java.lang.Double.doubleToLongBits(d);
            
//#line 203
x10.
              io.
              Marshal.LONG.write(((x10.
                                   io.
                                   Writer)(w)),
                                 (long)(l));
        }
        
        
//#line 196
public DoubleMarshal() {
            
//#line 196
super();
        }
    
    }
    

}
