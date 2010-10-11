package x10.lang;


final public class UByte
extends x10.core.Struct
{public static final x10.rtt.UByteType<UByte> _RTT = new x10.rtt.UByteType<UByte>(
/* base class */UByte.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
static {x10.rtt.Types.UBYTE = _RTT;}
public x10.rtt.UByteType<UByte> getRTT() {return _RTT;}



    
//#line 31
/** The actual number with Byte representation */final public byte
      byteVal;
    
    
//#line 32
public UByte(final byte value) {
        
//#line 33
this.byteVal = value;
    }
    
    
//#line 45
final public static boolean
                  $lt(
                  final x10.
                    lang.
                    UByte x,
                  final x10.
                    lang.
                    UByte y){
        
//#line 47
return ((((byte)((((byte) ((((byte)(x.
                                                          byteVal))) + (((byte)(java.lang.Byte.MIN_VALUE))))))))) < (((byte)((((byte) ((((byte)(y.
                                                                                                                                                  byteVal))) + (((byte)(java.lang.Byte.MIN_VALUE))))))))));
    }
    
    
//#line 59
final public static boolean
                  $gt(
                  final x10.
                    lang.
                    UByte x,
                  final x10.
                    lang.
                    UByte y){
        
//#line 61
return ((((byte)((((byte) ((((byte)(x.
                                                          byteVal))) + (((byte)(java.lang.Byte.MIN_VALUE))))))))) > (((byte)((((byte) ((((byte)(y.
                                                                                                                                                  byteVal))) + (((byte)(java.lang.Byte.MIN_VALUE))))))))));
    }
    
    
//#line 73
final public static boolean
                  $le(
                  final x10.
                    lang.
                    UByte x,
                  final x10.
                    lang.
                    UByte y){
        
//#line 75
return ((((byte)((((byte) ((((byte)(x.
                                                          byteVal))) + (((byte)(java.lang.Byte.MIN_VALUE))))))))) <= (((byte)((((byte) ((((byte)(y.
                                                                                                                                                   byteVal))) + (((byte)(java.lang.Byte.MIN_VALUE))))))))));
    }
    
    
//#line 87
final public static boolean
                  $ge(
                  final x10.
                    lang.
                    UByte x,
                  final x10.
                    lang.
                    UByte y){
        
//#line 89
return ((((byte)((((byte) ((((byte)(x.
                                                          byteVal))) + (((byte)(java.lang.Byte.MIN_VALUE))))))))) >= (((byte)((((byte) ((((byte)(y.
                                                                                                                                                   byteVal))) + (((byte)(java.lang.Byte.MIN_VALUE))))))))));
    }
    
    
//#line 102
final public static x10.
                   lang.
                   UByte
                   $plus(
                   final x10.
                     lang.
                     UByte x,
                   final x10.
                     lang.
                     UByte y){
        
//#line 103
return new x10.
          lang.
          UByte(((byte) ((((byte)(x.
                                    byteVal))) + (((byte)(y.
                                                            byteVal))))));
    }
    
    
//#line 110
final public static x10.
                   lang.
                   UByte
                   $plus(
                   final byte x,
                   final x10.
                     lang.
                     UByte y){
        
//#line 111
return new x10.
          lang.
          UByte(((byte) ((((byte)(x))) + (((byte)(y.
                                                    byteVal))))));
    }
    
    
//#line 117
final public static x10.
                   lang.
                   UByte
                   $plus(
                   final x10.
                     lang.
                     UByte x,
                   final byte y){
        
//#line 118
return new x10.
          lang.
          UByte(((byte) ((((byte)(x.
                                    byteVal))) + (((byte)(y))))));
    }
    
    
//#line 129
final public static x10.
                   lang.
                   UByte
                   $minus(
                   final x10.
                     lang.
                     UByte x,
                   final x10.
                     lang.
                     UByte y){
        
//#line 130
return new x10.
          lang.
          UByte(((byte) ((((byte)(x.
                                    byteVal))) - (((byte)(y.
                                                            byteVal))))));
    }
    
    
//#line 137
final public static x10.
                   lang.
                   UByte
                   $minus(
                   final byte x,
                   final x10.
                     lang.
                     UByte y){
        
//#line 138
return new x10.
          lang.
          UByte(((byte) ((((byte)(x))) - (((byte)(y.
                                                    byteVal))))));
    }
    
    
//#line 144
final public static x10.
                   lang.
                   UByte
                   $minus(
                   final x10.
                     lang.
                     UByte x,
                   final byte y){
        
//#line 145
return new x10.
          lang.
          UByte(((byte) ((((byte)(x.
                                    byteVal))) - (((byte)(y))))));
    }
    
    
//#line 156
final public static x10.
                   lang.
                   UByte
                   $times(
                   final x10.
                     lang.
                     UByte x,
                   final x10.
                     lang.
                     UByte y){
        
//#line 157
return new x10.
          lang.
          UByte(((byte) ((((byte)(x.
                                    byteVal))) * (((byte)(y.
                                                            byteVal))))));
    }
    
    
//#line 164
final public static x10.
                   lang.
                   UByte
                   $times(
                   final byte x,
                   final x10.
                     lang.
                     UByte y){
        
//#line 165
return new x10.
          lang.
          UByte(((byte) ((((byte)(x))) * (((byte)(y.
                                                    byteVal))))));
    }
    
    
//#line 171
final public static x10.
                   lang.
                   UByte
                   $times(
                   final x10.
                     lang.
                     UByte x,
                   final byte y){
        
//#line 172
return new x10.
          lang.
          UByte(((byte) ((((byte)(x.
                                    byteVal))) * (((byte)(y))))));
    }
    
    
//#line 182
final public static x10.
                   lang.
                   UByte
                   $over(
                   final x10.
                     lang.
                     UByte x,
                   final x10.
                     lang.
                     UByte y){
        
//#line 184
return new x10.
          lang.
          UByte(((byte)(long)(((long)((((((long)((((long)(((byte)(x.
                                                                    byteVal)))))))) / (((long)((((long)(((byte)(y.
                                                                                                                  byteVal)))))))))))))));
    }
    
    
//#line 191
final public static x10.
                   lang.
                   UByte
                   $over(
                   final byte x,
                   final x10.
                     lang.
                     UByte y){
        
//#line 193
return new x10.
          lang.
          UByte(((byte)(long)(((long)((((((long)((((long)(((byte)(x)))))))) / (((long)((((long)(((byte)(y.
                                                                                                          byteVal)))))))))))))));
    }
    
    
//#line 200
final public static x10.
                   lang.
                   UByte
                   $over(
                   final x10.
                     lang.
                     UByte x,
                   final byte y){
        
//#line 202
return new x10.
          lang.
          UByte(((byte)(long)(((long)((((((long)((((long)(((byte)(x.
                                                                    byteVal)))))))) / (((long)((((long)(((byte)(y)))))))))))))));
    }
    
    
//#line 213
final public static x10.
                   lang.
                   UByte
                   $percent(
                   final x10.
                     lang.
                     UByte x,
                   final x10.
                     lang.
                     UByte y){
        
//#line 215
return new x10.
          lang.
          UByte(((byte)(long)(((long)((((((long)((((long)(((byte)(x.
                                                                    byteVal)))))))) % (((long)((((long)(((byte)(y.
                                                                                                                  byteVal)))))))))))))));
    }
    
    
//#line 222
final public static x10.
                   lang.
                   UByte
                   $percent(
                   final byte x,
                   final x10.
                     lang.
                     UByte y){
        
//#line 224
return new x10.
          lang.
          UByte(((byte)(long)(((long)((((((long)((((long)(((byte)(x)))))))) % (((long)((((long)(((byte)(y.
                                                                                                          byteVal)))))))))))))));
    }
    
    
//#line 231
final public static x10.
                   lang.
                   UByte
                   $percent(
                   final x10.
                     lang.
                     UByte x,
                   final byte y){
        
//#line 233
return new x10.
          lang.
          UByte(((byte)(long)(((long)((((((long)((((long)(((byte)(x.
                                                                    byteVal)))))))) % (((long)((((long)(((byte)(y)))))))))))))));
    }
    
    
//#line 243
final public static x10.
                   lang.
                   UByte
                   $plus(
                   final x10.
                     lang.
                     UByte x){
        
//#line 244
return x;
    }
    
    
//#line 254
final public static x10.
                   lang.
                   UByte
                   $minus(
                   final x10.
                     lang.
                     UByte x){
        
//#line 255
return new x10.
          lang.
          UByte(((byte) -(((byte)((x.
                                     byteVal))))));
    }
    
    
//#line 266
final public static x10.
                   lang.
                   UByte
                   $ampersand(
                   final x10.
                     lang.
                     UByte x,
                   final x10.
                     lang.
                     UByte y){
        
//#line 267
return new x10.
          lang.
          UByte(((byte) ((((byte)(x.
                                    byteVal))) & (((byte)(y.
                                                            byteVal))))));
    }
    
    
//#line 273
final public static x10.
                   lang.
                   UByte
                   $ampersand(
                   final byte x,
                   final x10.
                     lang.
                     UByte y){
        
//#line 274
return new x10.
          lang.
          UByte(((byte) ((((byte)(x))) & (((byte)(y.
                                                    byteVal))))));
    }
    
    
//#line 280
final public static x10.
                   lang.
                   UByte
                   $ampersand(
                   final x10.
                     lang.
                     UByte x,
                   final byte y){
        
//#line 281
return new x10.
          lang.
          UByte(((byte) ((((byte)(x.
                                    byteVal))) & (((byte)(y))))));
    }
    
    
//#line 291
final public static x10.
                   lang.
                   UByte
                   $bar(
                   final x10.
                     lang.
                     UByte x,
                   final x10.
                     lang.
                     UByte y){
        
//#line 292
return new x10.
          lang.
          UByte(((byte) ((((byte)(x.
                                    byteVal))) | (((byte)(y.
                                                            byteVal))))));
    }
    
    
//#line 298
final public static x10.
                   lang.
                   UByte
                   $bar(
                   final byte x,
                   final x10.
                     lang.
                     UByte y){
        
//#line 299
return new x10.
          lang.
          UByte(((byte) ((((byte)(x))) | (((byte)(y.
                                                    byteVal))))));
    }
    
    
//#line 305
final public static x10.
                   lang.
                   UByte
                   $bar(
                   final x10.
                     lang.
                     UByte x,
                   final byte y){
        
//#line 306
return new x10.
          lang.
          UByte(((byte) ((((byte)(x.
                                    byteVal))) | (((byte)(y))))));
    }
    
    
//#line 316
final public static x10.
                   lang.
                   UByte
                   $caret(
                   final x10.
                     lang.
                     UByte x,
                   final x10.
                     lang.
                     UByte y){
        
//#line 317
return new x10.
          lang.
          UByte(((byte) ((((byte)(x.
                                    byteVal))) ^ (((byte)(y.
                                                            byteVal))))));
    }
    
    
//#line 323
final public static x10.
                   lang.
                   UByte
                   $caret(
                   final byte x,
                   final x10.
                     lang.
                     UByte y){
        
//#line 324
return new x10.
          lang.
          UByte(((byte) ((((byte)(x))) ^ (((byte)(y.
                                                    byteVal))))));
    }
    
    
//#line 330
final public static x10.
                   lang.
                   UByte
                   $caret(
                   final x10.
                     lang.
                     UByte x,
                   final byte y){
        
//#line 331
return new x10.
          lang.
          UByte(((byte) ((((byte)(x.
                                    byteVal))) ^ (((byte)(y))))));
    }
    
    
//#line 342
final public static x10.
                   lang.
                   UByte
                   $left(
                   final x10.
                     lang.
                     UByte x,
                   final int count){
        
//#line 343
return new x10.
          lang.
          UByte(((byte) ((((byte)(x.
                                    byteVal))) << (((int)(count))))));
    }
    
    
//#line 355
final public static x10.
                   lang.
                   UByte
                   $right(
                   final x10.
                     lang.
                     UByte x,
                   final int count){
        
//#line 356
return new x10.
          lang.
          UByte(((byte) ((((byte)(x.
                                    byteVal))) >>> (((int)(count))))));
    }
    
    
//#line 369
final public static x10.
                   lang.
                   UByte
                   $unsigned_right(
                   final x10.
                     lang.
                     UByte x,
                   final int count){
        
//#line 370
return new x10.
          lang.
          UByte(((byte) ((((byte)(x.
                                    byteVal))) >>> (((int)(count))))));
    }
    
    
//#line 379
final public static x10.
                   lang.
                   UByte
                   $tilde(
                   final x10.
                     lang.
                     UByte x){
        
//#line 380
return new x10.
          lang.
          UByte(((byte) ~(((byte)((x.
                                     byteVal))))));
    }
    
    
//#line 389
final public static x10.
                   lang.
                   UByte
                   $convert(
                   final x10.
                     lang.
                     UShort x){
        
//#line 390
return new x10.
          lang.
          UByte(((byte)(short)(((short)(x.
                                          shortVal)))));
    }
    
    
//#line 398
final public static x10.
                   lang.
                   UByte
                   $convert(
                   final x10.
                     lang.
                     UInt x){
        
//#line 399
return new x10.
          lang.
          UByte(((byte)(int)(((int)(x.
                                      intVal)))));
    }
    
    
//#line 407
final public static x10.
                   lang.
                   UByte
                   $convert(
                   final x10.
                     lang.
                     ULong x){
        
//#line 408
return new x10.
          lang.
          UByte(((byte)(long)(((long)(x.
                                        longVal)))));
    }
    
    
//#line 417
final public static x10.
                   lang.
                   UByte
                   $convert(
                   final short x){
        
//#line 418
return new x10.
          lang.
          UByte(((byte)(short)(((short)(x)))));
    }
    
    
//#line 426
final public static x10.
                   lang.
                   UByte
                   $convert(
                   final int x){
        
//#line 427
return new x10.
          lang.
          UByte(((byte)(int)(((int)(x)))));
    }
    
    
//#line 435
final public static x10.
                   lang.
                   UByte
                   $convert(
                   final long x){
        
//#line 436
return new x10.
          lang.
          UByte(((byte)(long)(((long)(x)))));
    }
    
    
//#line 444
final public static x10.
                   lang.
                   UByte
                   $convert(
                   final float x){
        
//#line 446
final int temp =
          ((int)(float)(((float)(x))));
        
//#line 447
if (((((int)(temp))) > (((int)(255))))) {
            
//#line 447
return new x10.
              lang.
              UByte(((byte)(int)(((int)(255)))));
        } else {
            
//#line 448
if (((((int)(temp))) < (((int)(0))))) {
                
//#line 448
return new x10.
                  lang.
                  UByte(((byte)(int)(((int)(0)))));
            } else {
                
//#line 449
return new x10.
                  lang.
                  UByte(((byte)(int)(((int)(temp)))));
            }
        }
    }
    
    
//#line 458
final public static x10.
                   lang.
                   UByte
                   $convert(
                   final double x){
        
//#line 460
final int temp =
          ((int)(double)(((double)(x))));
        
//#line 461
if (((((int)(temp))) > (((int)(255))))) {
            
//#line 461
return new x10.
              lang.
              UByte(((byte)(int)(((int)(255)))));
        } else {
            
//#line 462
if (((((int)(temp))) < (((int)(0))))) {
                
//#line 462
return new x10.
                  lang.
                  UByte(((byte)(int)(((int)(0)))));
            } else {
                
//#line 463
return new x10.
                  lang.
                  UByte(((byte)(int)(((int)(temp)))));
            }
        }
    }
    
    
//#line 472
final public static x10.
                   lang.
                   UByte
                   $implicit_convert(
                   final byte x){
        
//#line 473
return new x10.
          lang.
          UByte(x);
    }
    
    
//#line 481
/**
     * A constant holding the minimum value a UByte can have, 0.
     */final public static x10.
      lang.
      UByte
      MIN_VALUE =
      x10.
      lang.
      UByte.$convert((int)(0));
    
//#line 488
/**
     * A constant holding the maximum value a UByte can have, 2<sup>8</sup>-1.
     */final public static x10.
      lang.
      UByte
      MAX_VALUE =
      x10.
      lang.
      UByte.$convert((int)(255));
    
    
//#line 497
final public java.lang.String
                   toString(
                   final int radix){
        
//#line 498
return java.lang.Integer.toString((((int) (int) 
                                                          ((((((int)(((int)(byte)(((byte)(this.
                                                                                            byteVal))))))) & (((int)(255)))))))), ((int)(radix)));
    }
    
    
//#line 505
final public java.lang.String
                   toHexString(
                   ){
        
//#line 506
return x10.core.Bytes.toString(this.
                                                      byteVal, 16);
    }
    
    
//#line 513
final public java.lang.String
                   toOctalString(
                   ){
        
//#line 514
return x10.core.Bytes.toString(this.
                                                      byteVal, 8);
    }
    
    
//#line 521
final public java.lang.String
                   toBinaryString(
                   ){
        
//#line 522
return x10.core.Bytes.toString(this.
                                                      byteVal, 2);
    }
    
    
//#line 529
final public java.lang.String
                   toString(
                   ){
        
//#line 530
return java.lang.Integer.toString((((int) (int) 
                                                          ((((((int)(((int)(byte)(((byte)(this.
                                                                                            byteVal))))))) & (((int)(255)))))))));
    }
    
    
//#line 536
final public static x10.
                   lang.
                   UByte
                   parseUByte(
                   final java.lang.String s,
                   final int radix)
                       throws java.lang.NumberFormatException{
        
//#line 538
return new x10.
          lang.
          UByte(java.lang.Byte.parseByte(s, ((int)(radix))));
    }
    
    
//#line 545
final public static x10.
                   lang.
                   UByte
                   parseUByte(
                   final java.lang.String s)
                       throws java.lang.NumberFormatException{
        
//#line 547
return new x10.
          lang.
          UByte(java.lang.Byte.parseByte(s));
    }
    
    
//#line 558
final public static x10.
                   lang.
                   UByte
                   parse(
                   final java.lang.String s,
                   final int radix)
                       throws java.lang.NumberFormatException{
        
//#line 560
return new x10.
          lang.
          UByte(java.lang.Byte.parseByte(s, ((int)(radix))));
    }
    
    
//#line 570
final public static x10.
                   lang.
                   UByte
                   parse(
                   final java.lang.String s)
                       throws java.lang.NumberFormatException{
        
//#line 572
return new x10.
          lang.
          UByte(java.lang.Byte.parseByte(s));
    }
    
    
//#line 582
final public x10.
                   lang.
                   UByte
                   reverse(
                   ){
        
//#line 583
return new x10.
          lang.
          UByte(((byte)(java.lang.Integer.reverse(this.
                                                    byteVal)>>>24)));
    }
    
    
//#line 591
final public int
                   signum(
                   ){
        
//#line 592
return ((((int) ((int)(byte)(((byte)(this.
                                                            byteVal))))) ==
                              ((int) 0)))
          ? 0
          : 1;
    }
    
    
//#line 602
final public boolean
                   equals(
                   final java.lang.Object x){
        
//#line 603
return x10.rtt.Equality.equalsequals(this.
                                                            byteVal, x);
    }
    
    
//#line 611
final public boolean
                   equals(
                   final x10.
                     lang.
                     UByte x){
        
//#line 612
return ((byte) this.
                                      byteVal) ==
        ((byte) x.
                  byteVal);
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
if ((!(((boolean)(x10.rtt.Types.UBYTE.instanceof$(other)))))) {
            
//#line 28
return false;
        }
        
//#line 28
return this._struct_equals((x10.
                                                 lang.
                                                 UByte)(((x10.
                                                          lang.
                                                          UByte)
                                                          other)));
    }
    
    
//#line 28
final public boolean
                  _struct_equals(
                  x10.
                    lang.
                    UByte other){
        
//#line 28
return ((byte) this.
                                     byteVal) ==
        ((byte) other.
                  byteVal);
    }

}
