package x10.lang;


final public class ULong
extends x10.core.Struct
{public static final x10.rtt.ULongType<ULong> _RTT = new x10.rtt.ULongType<ULong>(
/* base class */ULong.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
static {x10.rtt.Types.ULONG = _RTT;}
public x10.rtt.ULongType<ULong> getRTT() {return _RTT;}



    
//#line 31
/** The actual number with Long representation */final public long
      longVal;
    
    
//#line 32
public ULong(final long value) {
        
//#line 33
this.longVal = value;
    }
    
    
//#line 45
final public static boolean
                  $lt(
                  final x10.
                    lang.
                    ULong x,
                  final x10.
                    lang.
                    ULong y){
        
//#line 47
return ((((long)((((((long)(x.
                                                  longVal))) + (((long)(java.lang.Long.MIN_VALUE)))))))) < (((long)((((((long)(y.
                                                                                                                                 longVal))) + (((long)(java.lang.Long.MIN_VALUE)))))))));
    }
    
    
//#line 59
final public static boolean
                  $gt(
                  final x10.
                    lang.
                    ULong x,
                  final x10.
                    lang.
                    ULong y){
        
//#line 61
return ((((long)((((((long)(x.
                                                  longVal))) + (((long)(java.lang.Long.MIN_VALUE)))))))) > (((long)((((((long)(y.
                                                                                                                                 longVal))) + (((long)(java.lang.Long.MIN_VALUE)))))))));
    }
    
    
//#line 73
final public static boolean
                  $le(
                  final x10.
                    lang.
                    ULong x,
                  final x10.
                    lang.
                    ULong y){
        
//#line 75
return ((((long)((((((long)(x.
                                                  longVal))) + (((long)(java.lang.Long.MIN_VALUE)))))))) <= (((long)((((((long)(y.
                                                                                                                                  longVal))) + (((long)(java.lang.Long.MIN_VALUE)))))))));
    }
    
    
//#line 87
final public static boolean
                  $ge(
                  final x10.
                    lang.
                    ULong x,
                  final x10.
                    lang.
                    ULong y){
        
//#line 89
return ((((long)((((((long)(x.
                                                  longVal))) + (((long)(java.lang.Long.MIN_VALUE)))))))) >= (((long)((((((long)(y.
                                                                                                                                  longVal))) + (((long)(java.lang.Long.MIN_VALUE)))))))));
    }
    
    
//#line 102
final public static x10.
                   lang.
                   ULong
                   $plus(
                   final x10.
                     lang.
                     ULong x,
                   final x10.
                     lang.
                     ULong y){
        
//#line 103
return new x10.
          lang.
          ULong(((((long)(x.
                            longVal))) + (((long)(y.
                                                    longVal)))));
    }
    
    
//#line 109
final public static x10.
                   lang.
                   ULong
                   $plus(
                   final long x,
                   final x10.
                     lang.
                     ULong y){
        
//#line 110
return new x10.
          lang.
          ULong(((((long)(x))) + (((long)(y.
                                            longVal)))));
    }
    
    
//#line 116
final public static x10.
                   lang.
                   ULong
                   $plus(
                   final x10.
                     lang.
                     ULong x,
                   final long y){
        
//#line 117
return new x10.
          lang.
          ULong(((((long)(x.
                            longVal))) + (((long)(y)))));
    }
    
    
//#line 128
final public static x10.
                   lang.
                   ULong
                   $minus(
                   final x10.
                     lang.
                     ULong x,
                   final x10.
                     lang.
                     ULong y){
        
//#line 129
return new x10.
          lang.
          ULong(((((long)(x.
                            longVal))) - (((long)(y.
                                                    longVal)))));
    }
    
    
//#line 135
final public static x10.
                   lang.
                   ULong
                   $minus(
                   final long x,
                   final x10.
                     lang.
                     ULong y){
        
//#line 136
return new x10.
          lang.
          ULong(((((long)(x))) - (((long)(y.
                                            longVal)))));
    }
    
    
//#line 142
final public static x10.
                   lang.
                   ULong
                   $minus(
                   final x10.
                     lang.
                     ULong x,
                   final long y){
        
//#line 143
return new x10.
          lang.
          ULong(((((long)(x.
                            longVal))) - (((long)(y)))));
    }
    
    
//#line 154
final public static x10.
                   lang.
                   ULong
                   $times(
                   final x10.
                     lang.
                     ULong x,
                   final x10.
                     lang.
                     ULong y){
        
//#line 155
return new x10.
          lang.
          ULong(((((long)(x.
                            longVal))) * (((long)(y.
                                                    longVal)))));
    }
    
    
//#line 161
final public static x10.
                   lang.
                   ULong
                   $times(
                   final long x,
                   final x10.
                     lang.
                     ULong y){
        
//#line 162
return new x10.
          lang.
          ULong(((((long)(x))) * (((long)(y.
                                            longVal)))));
    }
    
    
//#line 168
final public static x10.
                   lang.
                   ULong
                   $times(
                   final x10.
                     lang.
                     ULong x,
                   final long y){
        
//#line 169
return new x10.
          lang.
          ULong(((((long)(x.
                            longVal))) * (((long)(y)))));
    }
    
    
//#line 179
final public static x10.
                   lang.
                   ULong
                   $over(
                   final x10.
                     lang.
                     ULong x,
                   final x10.
                     lang.
                     ULong y){
        
//#line 181
if (((((long)(x.
                                     longVal))) > (((long)(((long)(((int)(0)))))))) &&
                         ((((long)(y.
                                     longVal))) > (((long)(((long)(((int)(0))))))))) {
            
//#line 182
return new x10.
              lang.
              ULong(((((long)(x.
                                longVal))) / (((long)(y.
                                                        longVal)))));
        } else {
            
//#line 183
if (((((long)(x.
                                         longVal))) < (((long)(y.
                                                                 longVal))))) {
                
//#line 184
return x10.
                  lang.
                  ULong.$implicit_convert((long)(0L));
            } else {
                
//#line 186
return x10.
                  lang.
                  ULong.$implicit_convert((long)(1L));
            }
        }
    }
    
    
//#line 193
final public static x10.
                   lang.
                   ULong
                   $over(
                   final long x,
                   final x10.
                     lang.
                     ULong y){
        
//#line 195
if (((((long)(x))) > (((long)(((long)(((int)(0)))))))) &&
                         ((((long)(y.
                                     longVal))) > (((long)(((long)(((int)(0))))))))) {
            
//#line 196
return new x10.
              lang.
              ULong(((((long)(x))) / (((long)(y.
                                                longVal)))));
        } else {
            
//#line 197
if (((((long)(x))) < (((long)(y.
                                                         longVal))))) {
                
//#line 198
return x10.
                  lang.
                  ULong.$implicit_convert((long)(0L));
            } else {
                
//#line 200
return x10.
                  lang.
                  ULong.$implicit_convert((long)(1L));
            }
        }
    }
    
    
//#line 207
final public static x10.
                   lang.
                   ULong
                   $over(
                   final x10.
                     lang.
                     ULong x,
                   final long y){
        
//#line 209
if (((((long)(x.
                                     longVal))) > (((long)(((long)(((int)(0)))))))) &&
                         ((((long)(y))) > (((long)(((long)(((int)(0))))))))) {
            
//#line 210
return new x10.
              lang.
              ULong(((((long)(x.
                                longVal))) / (((long)(y)))));
        } else {
            
//#line 211
if (((((long)(x.
                                         longVal))) < (((long)(y))))) {
                
//#line 212
return x10.
                  lang.
                  ULong.$implicit_convert((long)(0L));
            } else {
                
//#line 214
return x10.
                  lang.
                  ULong.$implicit_convert((long)(1L));
            }
        }
    }
    
    
//#line 225
final public static x10.
                   lang.
                   ULong
                   $percent(
                   final x10.
                     lang.
                     ULong x,
                   final x10.
                     lang.
                     ULong y){
        
//#line 227
if (((((long)(x.
                                     longVal))) > (((long)(((long)(((int)(0)))))))) &&
                         ((((long)(y.
                                     longVal))) > (((long)(((long)(((int)(0))))))))) {
            
//#line 228
return new x10.
              lang.
              ULong(((((long)(x.
                                longVal))) % (((long)(y.
                                                        longVal)))));
        } else {
            
//#line 229
if (((((long)(x.
                                         longVal))) < (((long)(y.
                                                                 longVal))))) {
                
//#line 230
return x;
            } else {
                
//#line 232
return new x10.
                  lang.
                  ULong(((((long)(x.
                                    longVal))) - (((long)(y.
                                                            longVal)))));
            }
        }
    }
    
    
//#line 239
final public static x10.
                   lang.
                   ULong
                   $percent(
                   final long x,
                   final x10.
                     lang.
                     ULong y){
        
//#line 241
if (((((long)(x))) > (((long)(((long)(((int)(0)))))))) &&
                         ((((long)(y.
                                     longVal))) > (((long)(((long)(((int)(0))))))))) {
            
//#line 242
return new x10.
              lang.
              ULong(((((long)(x))) % (((long)(y.
                                                longVal)))));
        } else {
            
//#line 243
if (((((long)(x))) < (((long)(y.
                                                         longVal))))) {
                
//#line 244
return new x10.
                  lang.
                  ULong(x);
            } else {
                
//#line 246
return new x10.
                  lang.
                  ULong(((((long)(x))) - (((long)(y.
                                                    longVal)))));
            }
        }
    }
    
    
//#line 253
final public static x10.
                   lang.
                   ULong
                   $percent(
                   final x10.
                     lang.
                     ULong x,
                   final long y){
        
//#line 255
if (((((long)(x.
                                     longVal))) > (((long)(((long)(((int)(0)))))))) &&
                         ((((long)(y))) > (((long)(((long)(((int)(0))))))))) {
            
//#line 256
return new x10.
              lang.
              ULong(((((long)(x.
                                longVal))) % (((long)(y)))));
        } else {
            
//#line 257
if (((((long)(x.
                                         longVal))) < (((long)(y))))) {
                
//#line 258
return x;
            } else {
                
//#line 260
return new x10.
                  lang.
                  ULong(((((long)(x.
                                    longVal))) - (((long)(y)))));
            }
        }
    }
    
    
//#line 270
final public static x10.
                   lang.
                   ULong
                   $plus(
                   final x10.
                     lang.
                     ULong x){
        
//#line 271
return x;
    }
    
    
//#line 281
final public static x10.
                   lang.
                   ULong
                   $minus(
                   final x10.
                     lang.
                     ULong x){
        
//#line 282
return new x10.
          lang.
          ULong((-(((long)((x.
                              longVal))))));
    }
    
    
//#line 293
final public static x10.
                   lang.
                   ULong
                   $ampersand(
                   final x10.
                     lang.
                     ULong x,
                   final x10.
                     lang.
                     ULong y){
        
//#line 294
return new x10.
          lang.
          ULong(((((long)(x.
                            longVal))) & (((long)(y.
                                                    longVal)))));
    }
    
    
//#line 300
final public static x10.
                   lang.
                   ULong
                   $ampersand(
                   final long x,
                   final x10.
                     lang.
                     ULong y){
        
//#line 301
return new x10.
          lang.
          ULong(((((long)(x))) & (((long)(y.
                                            longVal)))));
    }
    
    
//#line 307
final public static x10.
                   lang.
                   ULong
                   $ampersand(
                   final x10.
                     lang.
                     ULong x,
                   final long y){
        
//#line 308
return new x10.
          lang.
          ULong(((((long)(x.
                            longVal))) & (((long)(y)))));
    }
    
    
//#line 318
final public static x10.
                   lang.
                   ULong
                   $bar(
                   final x10.
                     lang.
                     ULong x,
                   final x10.
                     lang.
                     ULong y){
        
//#line 319
return new x10.
          lang.
          ULong(((((long)(x.
                            longVal))) | (((long)(y.
                                                    longVal)))));
    }
    
    
//#line 325
final public static x10.
                   lang.
                   ULong
                   $bar(
                   final long x,
                   final x10.
                     lang.
                     ULong y){
        
//#line 326
return new x10.
          lang.
          ULong(((((long)(x))) | (((long)(y.
                                            longVal)))));
    }
    
    
//#line 332
final public static x10.
                   lang.
                   ULong
                   $bar(
                   final x10.
                     lang.
                     ULong x,
                   final long y){
        
//#line 333
return new x10.
          lang.
          ULong(((((long)(x.
                            longVal))) | (((long)(y)))));
    }
    
    
//#line 343
final public static x10.
                   lang.
                   ULong
                   $caret(
                   final x10.
                     lang.
                     ULong x,
                   final x10.
                     lang.
                     ULong y){
        
//#line 344
return new x10.
          lang.
          ULong(((((long)(x.
                            longVal))) ^ (((long)(y.
                                                    longVal)))));
    }
    
    
//#line 350
final public static x10.
                   lang.
                   ULong
                   $caret(
                   final long x,
                   final x10.
                     lang.
                     ULong y){
        
//#line 351
return new x10.
          lang.
          ULong(((((long)(x))) ^ (((long)(y.
                                            longVal)))));
    }
    
    
//#line 357
final public static x10.
                   lang.
                   ULong
                   $caret(
                   final x10.
                     lang.
                     ULong x,
                   final long y){
        
//#line 358
return new x10.
          lang.
          ULong(((((long)(x.
                            longVal))) ^ (((long)(y)))));
    }
    
    
//#line 369
final public static x10.
                   lang.
                   ULong
                   $left(
                   final x10.
                     lang.
                     ULong x,
                   final int count){
        
//#line 370
return new x10.
          lang.
          ULong(((((long)(x.
                            longVal))) << (((int)(count)))));
    }
    
    
//#line 382
final public static x10.
                   lang.
                   ULong
                   $right(
                   final x10.
                     lang.
                     ULong x,
                   final int count){
        
//#line 383
return new x10.
          lang.
          ULong(((((long)(x.
                            longVal))) >>> (((int)(count)))));
    }
    
    
//#line 396
final public static x10.
                   lang.
                   ULong
                   $unsigned_right(
                   final x10.
                     lang.
                     ULong x,
                   final int count){
        
//#line 397
return new x10.
          lang.
          ULong(((((long)(x.
                            longVal))) >>> (((int)(count)))));
    }
    
    
//#line 406
final public static x10.
                   lang.
                   ULong
                   $tilde(
                   final x10.
                     lang.
                     ULong x){
        
//#line 407
return new x10.
          lang.
          ULong(((long) ~(((long)((x.
                                     longVal))))));
    }
    
    
//#line 416
final public static x10.
                   lang.
                   ULong
                   $implicit_convert(
                   final x10.
                     lang.
                     UByte x){
        
//#line 417
return new x10.
          lang.
          ULong(((((long)(((long)(((byte)(x.
                                            byteVal))))))) & (((long)(255L)))));
    }
    
    
//#line 425
final public static x10.
                   lang.
                   ULong
                   $implicit_convert(
                   final x10.
                     lang.
                     UShort x){
        
//#line 426
return new x10.
          lang.
          ULong(((((long)(((long)(((short)(x.
                                             shortVal))))))) & (((long)(65535L)))));
    }
    
    
//#line 434
final public static x10.
                   lang.
                   ULong
                   $implicit_convert(
                   final x10.
                     lang.
                     UInt x){
        
//#line 435
return new x10.
          lang.
          ULong(((((long)(((long)(((int)(x.
                                           intVal))))))) & (((long)(4294967295L)))));
    }
    
    
//#line 444
final public static x10.
                   lang.
                   ULong
                   $implicit_convert(
                   final byte x){
        
//#line 445
return new x10.
          lang.
          ULong(((long)(((byte)(x)))));
    }
    
    
//#line 453
final public static x10.
                   lang.
                   ULong
                   $implicit_convert(
                   final short x){
        
//#line 454
return new x10.
          lang.
          ULong(((long)(((short)(x)))));
    }
    
    
//#line 462
final public static x10.
                   lang.
                   ULong
                   $implicit_convert(
                   final int x){
        
//#line 463
return new x10.
          lang.
          ULong(((long)(((int)(x)))));
    }
    
    
//#line 471
final public static x10.
                   lang.
                   ULong
                   $convert(
                   final float x){
        
//#line 472
return new x10.
          lang.
          ULong(((long)(float)(((float)(x)))));
    }
    
    
//#line 480
final public static x10.
                   lang.
                   ULong
                   $convert(
                   final double x){
        
//#line 481
return new x10.
          lang.
          ULong(((long)(double)(((double)(x)))));
    }
    
    
//#line 489
final public static x10.
                   lang.
                   ULong
                   $implicit_convert(
                   final long x){
        
//#line 490
return new x10.
          lang.
          ULong(x);
    }
    
    
//#line 498
/**
     * A constant holding the minimum value a ULong can have, 0.
     */final public static x10.
      lang.
      ULong
      MIN_VALUE =
      x10.
      lang.
      ULong.$implicit_convert((long)(0L));
    
//#line 505
/**
     * A constant holding the maximum value a ULong can have, 2<sup>64</sup>-1.
     */final public static x10.
      lang.
      ULong
      MAX_VALUE =
      x10.
      lang.
      ULong.$implicit_convert((long)(-1L));
    
    
//#line 514
final public java.lang.String
                   toString(
                   final int radix){
        
//#line 515
return java.lang.Long.toString((((((long)(this.
                                                                 longVal))) & (((long)(-1L))))), ((int)(radix)));
    }
    
    
//#line 522
final public java.lang.String
                   toHexString(
                   ){
        
//#line 523
return java.lang.Long.toHexString(this.
                                                         longVal);
    }
    
    
//#line 530
final public java.lang.String
                   toOctalString(
                   ){
        
//#line 531
return java.lang.Long.toOctalString(this.
                                                           longVal);
    }
    
    
//#line 538
final public java.lang.String
                   toBinaryString(
                   ){
        
//#line 539
return java.lang.Long.toBinaryString(this.
                                                            longVal);
    }
    
    
//#line 546
final public java.lang.String
                   toString(
                   ){
        
//#line 547
return java.lang.Long.toString((((((long)(this.
                                                                 longVal))) & (((long)(-1L))))));
    }
    
    
//#line 553
final public static x10.
                   lang.
                   ULong
                   parseULong(
                   final java.lang.String s,
                   final int radix)
                       throws java.lang.NumberFormatException{
        
//#line 555
return new x10.
          lang.
          ULong(java.lang.Long.parseLong(s, ((int)(radix))));
    }
    
    
//#line 562
final public static x10.
                   lang.
                   ULong
                   parseULong(
                   final java.lang.String s)
                       throws java.lang.NumberFormatException{
        
//#line 564
return new x10.
          lang.
          ULong(java.lang.Long.parseLong(s));
    }
    
    
//#line 575
final public static x10.
                   lang.
                   ULong
                   parse(
                   final java.lang.String s,
                   final int radix)
                       throws java.lang.NumberFormatException{
        
//#line 577
return new x10.
          lang.
          ULong(java.lang.Long.parseLong(s, ((int)(radix))));
    }
    
    
//#line 587
final public static x10.
                   lang.
                   ULong
                   parse(
                   final java.lang.String s)
                       throws java.lang.NumberFormatException{
        
//#line 589
return new x10.
          lang.
          ULong(java.lang.Long.parseLong(s));
    }
    
    
//#line 601
final public x10.
                   lang.
                   ULong
                   highestOneBit(
                   ){
        
//#line 602
return new x10.
          lang.
          ULong(java.lang.Long.highestOneBit(this.
                                               longVal));
    }
    
    
//#line 612
final public x10.
                   lang.
                   ULong
                   lowestOneBit(
                   ){
        
//#line 613
return new x10.
          lang.
          ULong(java.lang.Long.lowestOneBit(this.
                                              longVal));
    }
    
    
//#line 623
final public int
                   numberOfLeadingZeros(
                   ){
        
//#line 624
return java.lang.Long.numberOfLeadingZeros(this.
                                                                  longVal);
    }
    
    
//#line 634
final public int
                   numberOfTrailingZeros(
                   ){
        
//#line 635
return java.lang.Long.numberOfTrailingZeros(this.
                                                                   longVal);
    }
    
    
//#line 644
final public int
                   bitCount(
                   ){
        
//#line 645
return java.lang.Long.bitCount(this.
                                                      longVal);
    }
    
    
//#line 664
final public x10.
                   lang.
                   ULong
                   rotateLeft(
                   final int distance){
        
//#line 665
return new x10.
          lang.
          ULong(java.lang.Long.rotateLeft(this.
                                            longVal, ((int)(distance))));
    }
    
    
//#line 684
final public x10.
                   lang.
                   ULong
                   rotateRight(
                   final int distance){
        
//#line 685
return new x10.
          lang.
          ULong(java.lang.Long.rotateRight(this.
                                             longVal, ((int)(distance))));
    }
    
    
//#line 693
final public x10.
                   lang.
                   ULong
                   reverse(
                   ){
        
//#line 694
return new x10.
          lang.
          ULong(java.lang.Long.reverse(this.
                                         longVal));
    }
    
    
//#line 702
final public int
                   signum(
                   ){
        
//#line 703
return ((((long) this.
                                        longVal) ==
                              ((long) 0L)))
          ? 0
          : 1;
    }
    
    
//#line 711
final public x10.
                   lang.
                   ULong
                   reverseBytes(
                   ){
        
//#line 712
return new x10.
          lang.
          ULong(java.lang.Long.reverseBytes(this.
                                              longVal));
    }
    
    
//#line 722
final public boolean
                   equals(
                   final java.lang.Object x){
        
//#line 723
return x10.rtt.Equality.equalsequals(this.
                                                            longVal, x);
    }
    
    
//#line 731
final public boolean
                   equals(
                   final x10.
                     lang.
                     ULong x){
        
//#line 732
return ((long) this.
                                      longVal) ==
        ((long) x.
                  longVal);
    }
    
    
//#line 28
final native public x10.
                  lang.
                  Place
                  home(
                  );
    
    
//#line 28
final native public java.lang.String
                  typeName(
                  );
    
    
//#line 28
final native public boolean
                  at(
                  x10.
                    lang.
                    Place p);
    
    
//#line 28
final native public boolean
                  at(
                  java.lang.Object r);
    
    
//#line 28
final public boolean
                  _struct_equals(
                  java.lang.Object other){
        
//#line 28
if ((!(((boolean)(x10.rtt.Types.ULONG.instanceof$(other)))))) {
            
//#line 28
return false;
        }
        
//#line 28
return this._struct_equals((x10.
                                                 lang.
                                                 ULong)(((x10.
                                                          lang.
                                                          ULong)
                                                          other)));
    }
    
    
//#line 28
final public boolean
                  _struct_equals(
                  x10.
                    lang.
                    ULong other){
        
//#line 28
return ((long) this.
                                     longVal) ==
        ((long) other.
                  longVal);
    }

}
