package x10.util;

public class Random
extends x10.core.Ref
{public static final x10.rtt.RuntimeType<Random> _RTT = new x10.rtt.RuntimeType<Random>(
/* base class */Random.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
    
//#line 16
public Random() {
        
//#line 17
this(java.lang.System.currentTimeMillis());
    }
    
    
//#line 20
public Random(final long seed) {
        super();
        
//#line 131
this.index = 0;
        
//#line 132
this.MT = null;
        
//#line 21
this.setSeed((long)(seed));
    }
    
    
//#line 24
public void
                  setSeed(
                  final long seed){
        
//#line 25
this.init((long)(seed));
    }
    
    
//#line 29
public int
                  nextInt(
                  ){
        
//#line 29
return this.random();
    }
    
    
//#line 33
public int
                  nextInt(
                  final int maxPlus1){
        
//#line 34
if (((((int)(maxPlus1))) <= (((int)(0))))) {
            
//#line 35
return 0;
        }
        
//#line 37
int n =
          maxPlus1;
        
//#line 39
if (((int) ((((((int)(n))) & (((int)((-(((int)(n))))))))))) ==
                        ((int) n)) {
            
//#line 41
return ((((int)(this.nextInt()))) & (((int)((((((int)(n))) - (((int)(1)))))))));
        }
        
//#line 44
int mask =
          1;
        
//#line 45
while (((int) ((((((int)(n))) & (((int)((~(((int)(mask))))))))))) !=
                           ((int) 0)) {
            
//#line 46
mask = ((((int)(mask))) << (((int)(1))));
            
//#line 47
mask = ((((int)(mask))) | (((int)(1))));
        }
        
//#line 52
int x;
        
//#line 54
do  {
            
//#line 55
x = ((((int)(this.nextInt()))) & (((int)(mask))));
        }while(((((int)(x))) >= (((int)(n))))); 
        
//#line 58
return x;
    }
    
    
//#line 61
public void
                  nextBytes(
                  final x10.core.Rail<java.lang.Byte> buf){
        
//#line 62
int i =
          0;
        {
            
//#line 63
final byte[] buf$value2089 =
              ((byte[])buf.value);
            
//#line 63
while (true) {
                
//#line 64
int x =
                  this.nextInt();
                {
                    
//#line 65
for (
//#line 65
int j =
                                       0;
                                     ((((int)(j))) < (((int)(4))));
                                     
//#line 65
j = ((((int)(j))) + (((int)(1))))) {
                        
//#line 66
if (((((int)(i))) >= (((int)(buf.
                                                                   length))))) {
                            
//#line 67
return;
                        }
                        
//#line 68
buf$value2089[i]=((byte)(int)(((int)((((((int)(x))) & (((int)(255)))))))));
                        
//#line 69
i = ((((int)(i))) + (((int)(1))));
                        
//#line 70
x = ((((int)(x))) >> (((int)(8))));
                    }
                }
            }
        }
    }
    
    
//#line 76
public long
                  nextLong(
                  ){
        
//#line 76
return ((((long)((((((long)((((long)(((int)(this.nextInt())))))))) << (((int)(32)))))))) | (((long)((((((long)(((long)(((int)(this.nextInt()))))))) & (((long)(4294967295L)))))))));
    }
    
    
//#line 78
public long
                  nextLong(
                  final long maxPlus1){
        
//#line 79
if (((((long)(maxPlus1))) <= (((long)(((long)(((int)(0))))))))) {
            
//#line 80
return 0L;
        }
        
//#line 82
long n =
          maxPlus1;
        
//#line 84
if (((long) ((((((long)(n))) & (((long)((-(((long)(n))))))))))) ==
                        ((long) n)) {
            
//#line 86
return ((((long)(this.nextLong()))) & (((long)((((((long)(n))) - (((long)(((long)(((int)(1)))))))))))));
        }
        
//#line 90
long pow2 =
          ((long)(((int)(1))));
        
//#line 91
while (((((long)(pow2))) < (((long)(n)))))
            
//#line 92
pow2 = ((((long)(pow2))) << (((int)(1))));
        
//#line 96
long x;
        
//#line 98
do  {
            
//#line 99
x = ((((long)(this.nextLong()))) & (((long)((((((long)(pow2))) - (((long)(((long)(((int)(1)))))))))))));
        }while(((((long)(x))) >= (((long)(n))))); 
        
//#line 102
return x;
    }
    
    
//#line 106
public boolean
                   nextBoolean(
                   ){
        
//#line 106
return ((((int)(this.nextInt()))) < (((int)(0))));
    }
    
    
//#line 109
public float
                   nextFloat(
                   ){
        
//#line 109
return ((((float)(((float)(int)(((int)((((int) (((x10.
                                                               lang.
                                                               UInt)((x10.
                                                                        lang.
                                                                        UInt.$right((x10.
                                                                                      lang.
                                                                                      UInt)((x10.
                                                                                               lang.
                                                                                               UInt.$implicit_convert((int)(this.nextInt())))),
                                                                                    (int)((((((int)(32))) - (((int)(24)))))))))).intVal)))))))))) / (((float)((((float)(int)(((int)((((((int)(1))) << (((int)(24))))))))))))));
    }
    
    
//#line 112
public double
                   nextDouble(
                   ){
        
//#line 112
return ((((double)(((double)(long)(((long)((((long)(((x10.
                                                                   lang.
                                                                   ULong)((x10.
                                                                             lang.
                                                                             ULong.$right((x10.
                                                                                            lang.
                                                                                            ULong)((x10.
                                                                                                      lang.
                                                                                                      ULong.$implicit_convert((long)(this.nextLong())))),
                                                                                          (int)((((((int)(64))) - (((int)(53)))))))))).longVal)))))))))) / (((double)((((double)(long)(((long)((((((long)(1L))) << (((int)(53))))))))))))));
    }
    
    
//#line 128
final public static int
      N =
      624;
    
//#line 129
final public static int
      M =
      397;
    
//#line 131
public int
      index;
    
//#line 132
public x10.core.Rail<java.lang.Integer>
      MT;
    
    
//#line 134
public void
                   init(
                   final long seed){
        
//#line 135
final x10.core.Rail<java.lang.Integer> mt =
          ((x10.core.Rail)(x10.core.RailFactory.<java.lang.Integer>makeVarRail(x10.rtt.Types.INT, ((int)(x10.
          util.
          Random.N)))));
        
//#line 136
this.MT = ((x10.core.Rail)(mt));
        
//#line 138
if (((long) seed) ==
                         ((long) 0L)) {
            
//#line 139
this.init((long)(4357L));
            
//#line 140
return;
        }
        
//#line 145
((int[])mt.value)[0] = ((int)(long)(((long)((((long) (long) 
                                                                    seed))))));
        {
            
//#line 146
final int[] mt$value2090 =
              ((int[])mt.value);
            
//#line 146
for (
//#line 146
int i =
                                1;
                              ((((int)(i))) < (((int)(x10.
                                util.
                                Random.N))));
                              
//#line 146
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 147
mt$value2090[i]=((int)(long)(((long)((((((long)(((((long)(69069L))) * (((long)(((long)(((int)(((int)mt$value2090[((((int)(i))) - (((int)(1))))])))))))))))) + (((long)(((long)(((int)(1)))))))))))));
            }
        }
        
//#line 151
this.index = 0;
        
//#line 152
x10.
          util.
          Random.twist(((x10.core.Rail)(mt)));
    }
    
    
//#line 155
public int
                   random(
                   ){
        
//#line 156
if (((int) index) ==
                         ((int) x10.
                           util.
                           Random.N)) {
            
//#line 157
this.index = 0;
            
//#line 158
x10.
              util.
              Random.twist(((x10.core.Rail)(MT)));
        }
        
//#line 160
return ((int[])MT.value)[((x10.
          util.
          Random.__$closure$apply$__2088(((x10.
                                           util.
                                           Random)(this)),
                                         (int)(1))) - (((int)(1))))];
    }
    
    
//#line 163
private static void
                   twist(
                   final x10.core.Rail<java.lang.Integer> MT){
        
//#line 164
int i =
          0;
        
//#line 165
int s;
        {
            
//#line 166
final int[] MT$value2091 =
              ((int[])MT.value);
            
//#line 166
for (;
                              ((((int)(i))) < (((int)(((((int)(x10.
                                util.
                                Random.N))) - (((int)(x10.
                                util.
                                Random.M))))))));
                              
//#line 166
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 167
s = ((((int)((((((int)(((int)MT$value2091[i])))) & (((int)(0x80000000)))))))) | (((int)((((((int)(((int)MT$value2091[((((int)(i))) + (((int)(1))))])))) & (((int)(2147483647)))))))));
                
//#line 168
MT$value2091[i]=((((int)(((((int)(((int)MT$value2091[((((int)(i))) + (((int)(x10.
                  util.
                  Random.M))))])))) ^ (((int)((((((int)(s))) >> (((int)(1)))))))))))) ^ (((int)((((((int)((((((int)(s))) & (((int)(1)))))))) * (((int)(0x9908b0df)))))))));
            }
        }
        {
            
//#line 170
final int[] MT$value2092 =
              ((int[])MT.value);
            
//#line 170
for (;
                              ((((int)(i))) < (((int)(((((int)(x10.
                                util.
                                Random.N))) - (((int)(1))))))));
                              
//#line 170
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 171
s = ((((int)((((((int)(((int)MT$value2092[i])))) & (((int)(0x80000000)))))))) | (((int)((((((int)(((int)MT$value2092[((((int)(i))) + (((int)(1))))])))) & (((int)(2147483647)))))))));
                
//#line 172
MT$value2092[i]=((((int)(((((int)(((int)MT$value2092[((((int)(i))) - (((int)((((((int)(x10.
                                                                                                             util.
                                                                                                             Random.N))) - (((int)(x10.
                                                                                                             util.
                                                                                                             Random.M)))))))))])))) ^ (((int)((((((int)(s))) >> (((int)(1)))))))))))) ^ (((int)((((((int)((((((int)(s))) & (((int)(1)))))))) * (((int)(0x9908b0df)))))))));
            }
        }
        
//#line 175
s = ((((int)((((((int)(((int[])MT.value)[((((int)(x10.
                                     util.
                                     Random.N))) - (((int)(1))))]))) & (((int)(0x80000000)))))))) | (((int)((((((int)(((int[])MT.value)[0]))) & (((int)(2147483647)))))))));
        
//#line 176
((int[])MT.value)[((((int)(x10.
          util.
          Random.N))) - (((int)(1))))] = ((((int)(((((int)(((int[])MT.value)[((((int)(x10.
          util.
          Random.M))) - (((int)(1))))]))) ^ (((int)((((((int)(s))) >> (((int)(1)))))))))))) ^ (((int)((((((int)((((((int)(s))) & (((int)(1)))))))) * (((int)(0x9908b0df)))))))));
    }
    
    public static void
      twist$P(
      final x10.core.Rail<java.lang.Integer> MT){
        Random.twist(((x10.core.Rail)(MT)));
    }
    
    final private static int
      __$closure$apply$__2088(
      final x10.
        util.
        Random x,
      final int y){
        
//#line 160
return x.index = ((((int)(x.
                                                 index))) + (((int)(y))));
    }
    
    final public static int
      __$closure$apply$__2088$P(
      final x10.
        util.
        Random x,
      final int y){
        return Random.__$closure$apply$__2088(((x10.
                                                util.
                                                Random)(x)),
                                              (int)(y));
    }

}
