package x10.lang;


final public class UInt
extends x10.core.Struct
{public static final x10.rtt.UIntType<UInt> _RTT = new x10.rtt.UIntType<UInt>(
/* base class */UInt.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
static {x10.rtt.Types.UINT = _RTT;}
public x10.rtt.UIntType<UInt> getRTT() {return _RTT;}



    
//#line 33
/** The actual number with Int representation */final public int
      intVal;
    
    
//#line 34
public UInt(final int value) {
        
//#line 35
this.intVal = value;
    }
    
    
//#line 47
final public static boolean
                  $lt(
                  final x10.
                    lang.
                    UInt x,
                  final x10.
                    lang.
                    UInt y){
        
//#line 49
return ((((int)((((((int)(x.
                                                intVal))) + (((int)(java.lang.Integer.MIN_VALUE)))))))) < (((int)((((((int)(y.
                                                                                                                              intVal))) + (((int)(java.lang.Integer.MIN_VALUE)))))))));
    }
    
    
//#line 61
final public static boolean
                  $gt(
                  final x10.
                    lang.
                    UInt x,
                  final x10.
                    lang.
                    UInt y){
        
//#line 63
return ((((int)((((((int)(x.
                                                intVal))) + (((int)(java.lang.Integer.MIN_VALUE)))))))) > (((int)((((((int)(y.
                                                                                                                              intVal))) + (((int)(java.lang.Integer.MIN_VALUE)))))))));
    }
    
    
//#line 75
final public static boolean
                  $le(
                  final x10.
                    lang.
                    UInt x,
                  final x10.
                    lang.
                    UInt y){
        
//#line 77
return ((((int)((((((int)(x.
                                                intVal))) + (((int)(java.lang.Integer.MIN_VALUE)))))))) <= (((int)((((((int)(y.
                                                                                                                               intVal))) + (((int)(java.lang.Integer.MIN_VALUE)))))))));
    }
    
    
//#line 89
final public static boolean
                  $ge(
                  final x10.
                    lang.
                    UInt x,
                  final x10.
                    lang.
                    UInt y){
        
//#line 91
return ((((int)((((((int)(x.
                                                intVal))) + (((int)(java.lang.Integer.MIN_VALUE)))))))) >= (((int)((((((int)(y.
                                                                                                                               intVal))) + (((int)(java.lang.Integer.MIN_VALUE)))))))));
    }
    
    
//#line 104
final public static x10.
                   lang.
                   UInt
                   $plus(
                   final x10.
                     lang.
                     UInt x,
                   final x10.
                     lang.
                     UInt y){
        
//#line 105
return new x10.
          lang.
          UInt(((((int)(x.
                          intVal))) + (((int)(y.
                                                intVal)))));
    }
    
    
//#line 111
final public static x10.
                   lang.
                   UInt
                   $plus(
                   final int x,
                   final x10.
                     lang.
                     UInt y){
        
//#line 112
return new x10.
          lang.
          UInt(((((int)(x))) + (((int)(y.
                                         intVal)))));
    }
    
    
//#line 118
final public static x10.
                   lang.
                   UInt
                   $plus(
                   final x10.
                     lang.
                     UInt x,
                   final int y){
        
//#line 119
return new x10.
          lang.
          UInt(((((int)(x.
                          intVal))) + (((int)(y)))));
    }
    
    
//#line 130
final public static x10.
                   lang.
                   UInt
                   $minus(
                   final x10.
                     lang.
                     UInt x,
                   final x10.
                     lang.
                     UInt y){
        
//#line 131
return new x10.
          lang.
          UInt(((((int)(x.
                          intVal))) - (((int)(y.
                                                intVal)))));
    }
    
    
//#line 137
final public static x10.
                   lang.
                   UInt
                   $minus(
                   final int x,
                   final x10.
                     lang.
                     UInt y){
        
//#line 138
return new x10.
          lang.
          UInt(((((int)(x))) - (((int)(y.
                                         intVal)))));
    }
    
    
//#line 144
final public static x10.
                   lang.
                   UInt
                   $minus(
                   final x10.
                     lang.
                     UInt x,
                   final int y){
        
//#line 145
return new x10.
          lang.
          UInt(((((int)(x.
                          intVal))) - (((int)(y)))));
    }
    
    
//#line 156
final public static x10.
                   lang.
                   UInt
                   $times(
                   final x10.
                     lang.
                     UInt x,
                   final x10.
                     lang.
                     UInt y){
        
//#line 157
return new x10.
          lang.
          UInt(((((int)(x.
                          intVal))) * (((int)(y.
                                                intVal)))));
    }
    
    
//#line 163
final public static x10.
                   lang.
                   UInt
                   $times(
                   final int x,
                   final x10.
                     lang.
                     UInt y){
        
//#line 164
return new x10.
          lang.
          UInt(((((int)(x))) * (((int)(y.
                                         intVal)))));
    }
    
    
//#line 170
final public static x10.
                   lang.
                   UInt
                   $times(
                   final x10.
                     lang.
                     UInt x,
                   final int y){
        
//#line 171
return new x10.
          lang.
          UInt(((((int)(x.
                          intVal))) * (((int)(y)))));
    }
    
    
//#line 181
final public static x10.
                   lang.
                   UInt
                   $over(
                   final x10.
                     lang.
                     UInt x,
                   final x10.
                     lang.
                     UInt y){
        
//#line 183
return new x10.
          lang.
          UInt(((int)(long)(((long)((((((long)((((long)(((int)(x.
                                                                 intVal)))))))) / (((long)((((long)(((int)(y.
                                                                                                             intVal)))))))))))))));
    }
    
    
//#line 190
final public static x10.
                   lang.
                   UInt
                   $over(
                   final int x,
                   final x10.
                     lang.
                     UInt y){
        
//#line 192
return new x10.
          lang.
          UInt(((int)(long)(((long)((((((long)((((long)(((int)(x)))))))) / (((long)((((long)(((int)(y.
                                                                                                      intVal)))))))))))))));
    }
    
    
//#line 199
final public static x10.
                   lang.
                   UInt
                   $over(
                   final x10.
                     lang.
                     UInt x,
                   final int y){
        
//#line 201
return new x10.
          lang.
          UInt(((int)(long)(((long)((((((long)((((long)(((int)(x.
                                                                 intVal)))))))) / (((long)((((long)(((int)(y)))))))))))))));
    }
    
    
//#line 212
final public static x10.
                   lang.
                   UInt
                   $percent(
                   final x10.
                     lang.
                     UInt x,
                   final x10.
                     lang.
                     UInt y){
        
//#line 214
return new x10.
          lang.
          UInt(((int)(long)(((long)((((((long)((((long)(((int)(x.
                                                                 intVal)))))))) % (((long)((((long)(((int)(y.
                                                                                                             intVal)))))))))))))));
    }
    
    
//#line 221
final public static x10.
                   lang.
                   UInt
                   $percent(
                   final int x,
                   final x10.
                     lang.
                     UInt y){
        
//#line 223
return new x10.
          lang.
          UInt(((int)(long)(((long)((((((long)((((long)(((int)(x)))))))) % (((long)((((long)(((int)(y.
                                                                                                      intVal)))))))))))))));
    }
    
    
//#line 230
final public static x10.
                   lang.
                   UInt
                   $percent(
                   final x10.
                     lang.
                     UInt x,
                   final int y){
        
//#line 232
return new x10.
          lang.
          UInt(((int)(long)(((long)((((((long)((((long)(((int)(x.
                                                                 intVal)))))))) % (((long)((((long)(((int)(y)))))))))))))));
    }
    
    
//#line 242
final public static x10.
                   lang.
                   UInt
                   $plus(
                   final x10.
                     lang.
                     UInt x){
        
//#line 243
return x;
    }
    
    
//#line 253
final public static x10.
                   lang.
                   UInt
                   $minus(
                   final x10.
                     lang.
                     UInt x){
        
//#line 254
return new x10.
          lang.
          UInt((-(((int)((x.
                            intVal))))));
    }
    
    
//#line 265
final public static x10.
                   lang.
                   UInt
                   $ampersand(
                   final x10.
                     lang.
                     UInt x,
                   final x10.
                     lang.
                     UInt y){
        
//#line 266
return new x10.
          lang.
          UInt(((((int)(x.
                          intVal))) & (((int)(y.
                                                intVal)))));
    }
    
    
//#line 272
final public static x10.
                   lang.
                   UInt
                   $ampersand(
                   final int x,
                   final x10.
                     lang.
                     UInt y){
        
//#line 273
return new x10.
          lang.
          UInt(((((int)(x))) & (((int)(y.
                                         intVal)))));
    }
    
    
//#line 279
final public static x10.
                   lang.
                   UInt
                   $ampersand(
                   final x10.
                     lang.
                     UInt x,
                   final int y){
        
//#line 280
return new x10.
          lang.
          UInt(((((int)(x.
                          intVal))) & (((int)(y)))));
    }
    
    
//#line 290
final public static x10.
                   lang.
                   UInt
                   $bar(
                   final x10.
                     lang.
                     UInt x,
                   final x10.
                     lang.
                     UInt y){
        
//#line 291
return new x10.
          lang.
          UInt(((((int)(x.
                          intVal))) | (((int)(y.
                                                intVal)))));
    }
    
    
//#line 297
final public static x10.
                   lang.
                   UInt
                   $bar(
                   final int x,
                   final x10.
                     lang.
                     UInt y){
        
//#line 298
return new x10.
          lang.
          UInt(((((int)(x))) | (((int)(y.
                                         intVal)))));
    }
    
    
//#line 304
final public static x10.
                   lang.
                   UInt
                   $bar(
                   final x10.
                     lang.
                     UInt x,
                   final int y){
        
//#line 305
return new x10.
          lang.
          UInt(((((int)(x.
                          intVal))) | (((int)(y)))));
    }
    
    
//#line 315
final public static x10.
                   lang.
                   UInt
                   $caret(
                   final x10.
                     lang.
                     UInt x,
                   final x10.
                     lang.
                     UInt y){
        
//#line 316
return new x10.
          lang.
          UInt(((((int)(x.
                          intVal))) ^ (((int)(y.
                                                intVal)))));
    }
    
    
//#line 322
final public static x10.
                   lang.
                   UInt
                   $caret(
                   final int x,
                   final x10.
                     lang.
                     UInt y){
        
//#line 323
return new x10.
          lang.
          UInt(((((int)(x))) ^ (((int)(y.
                                         intVal)))));
    }
    
    
//#line 329
final public static x10.
                   lang.
                   UInt
                   $caret(
                   final x10.
                     lang.
                     UInt x,
                   final int y){
        
//#line 330
return new x10.
          lang.
          UInt(((((int)(x.
                          intVal))) ^ (((int)(y)))));
    }
    
    
//#line 341
final public static x10.
                   lang.
                   UInt
                   $left(
                   final x10.
                     lang.
                     UInt x,
                   final int count){
        
//#line 342
return new x10.
          lang.
          UInt(((((int)(x.
                          intVal))) << (((int)(count)))));
    }
    
    
//#line 354
final public static x10.
                   lang.
                   UInt
                   $right(
                   final x10.
                     lang.
                     UInt x,
                   final int count){
        
//#line 355
return new x10.
          lang.
          UInt(((((int)(x.
                          intVal))) >>> (((int)(count)))));
    }
    
    
//#line 368
final public static x10.
                   lang.
                   UInt
                   $unsigned_right(
                   final x10.
                     lang.
                     UInt x,
                   final int count){
        
//#line 369
return new x10.
          lang.
          UInt(((((int)(x.
                          intVal))) >>> (((int)(count)))));
    }
    
    
//#line 378
final public static x10.
                   lang.
                   UInt
                   $tilde(
                   final x10.
                     lang.
                     UInt x){
        
//#line 379
return new x10.
          lang.
          UInt((~(((int)((x.
                            intVal))))));
    }
    
    
//#line 388
final public static x10.
                   lang.
                   UInt
                   $implicit_convert(
                   final x10.
                     lang.
                     UByte x){
        
//#line 389
return new x10.
          lang.
          UInt(((((int)(((int)(byte)(((byte)(x.
                                               byteVal))))))) & (((int)(255)))));
    }
    
    
//#line 397
final public static x10.
                   lang.
                   UInt
                   $implicit_convert(
                   final x10.
                     lang.
                     UShort x){
        
//#line 398
return new x10.
          lang.
          UInt(((((int)(((int)(short)(((short)(x.
                                                 shortVal))))))) & (((int)(65535)))));
    }
    
    
//#line 406
final public static x10.
                   lang.
                   UInt
                   $convert(
                   final x10.
                     lang.
                     ULong x){
        
//#line 407
return new x10.
          lang.
          UInt(((int)(long)(((long)(x.
                                      longVal)))));
    }
    
    
//#line 416
final public static x10.
                   lang.
                   UInt
                   $implicit_convert(
                   final byte x){
        
//#line 417
return new x10.
          lang.
          UInt(((int)(byte)(((byte)(x)))));
    }
    
    
//#line 425
final public static x10.
                   lang.
                   UInt
                   $implicit_convert(
                   final short x){
        
//#line 426
return new x10.
          lang.
          UInt(((int)(short)(((short)(x)))));
    }
    
    
//#line 434
final public static x10.
                   lang.
                   UInt
                   $convert(
                   final long x){
        
//#line 435
return new x10.
          lang.
          UInt(((int)(long)(((long)(x)))));
    }
    
    
//#line 443
final public static x10.
                   lang.
                   UInt
                   $convert(
                   final float x){
        
//#line 444
return new x10.
          lang.
          UInt(((int)(float)(((float)(x)))));
    }
    
    
//#line 452
final public static x10.
                   lang.
                   UInt
                   $convert(
                   final double x){
        
//#line 454
final long temp =
          ((long)(double)(((double)(x))));
        
//#line 455
if (((((long)(temp))) > (((long)(((long)(((int)(0xffffffff))))))))) {
            
//#line 455
return new x10.
              lang.
              UInt(((int) (int) 
                     (0xffffffff)));
        } else {
            
//#line 456
if (((((long)(temp))) < (((long)(((long)(((int)(0))))))))) {
                
//#line 456
return new x10.
                  lang.
                  UInt(0);
            } else {
                
//#line 457
return new x10.
                  lang.
                  UInt(((int)(long)(((long)(temp)))));
            }
        }
    }
    
    
//#line 466
final public static x10.
                   lang.
                   UInt
                   $implicit_convert(
                   final int x){
        
//#line 467
return new x10.
          lang.
          UInt(x);
    }
    
    
//#line 475
/**
     * A constant holding the minimum value a UInt can have, 0.
     */final public static x10.
      lang.
      UInt
      MIN_VALUE =
      x10.
      lang.
      UInt.$implicit_convert((int)(0));
    
//#line 482
/**
     * A constant holding the maximum value a UInt can have, 2<sup>32</sup>-1.
     */final public static x10.
      lang.
      UInt
      MAX_VALUE =
      x10.
      lang.
      UInt.$implicit_convert((int)(0xffffffff));
    
    
//#line 491
final public java.lang.String
                   toString(
                   final int radix){
        
//#line 492
return java.lang.Long.toString((((long) (long) 
                                                       ((((((long)(((long)(((int)(this.
                                                                                    intVal))))))) & (((long)(4294967295L)))))))), ((int)(radix)));
    }
    
    
//#line 499
final public java.lang.String
                   toHexString(
                   ){
        
//#line 500
return java.lang.Integer.toHexString(this.
                                                            intVal);
    }
    
    
//#line 507
final public java.lang.String
                   toOctalString(
                   ){
        
//#line 508
return java.lang.Integer.toOctalString(this.
                                                              intVal);
    }
    
    
//#line 515
final public java.lang.String
                   toBinaryString(
                   ){
        
//#line 516
return java.lang.Integer.toBinaryString(this.
                                                               intVal);
    }
    
    
//#line 523
final public java.lang.String
                   toString(
                   ){
        
//#line 524
return java.lang.Long.toString((((long) (long) 
                                                       ((((((long)(((long)(((int)(this.
                                                                                    intVal))))))) & (((long)(4294967295L)))))))));
    }
    
    
//#line 530
final public static x10.
                   lang.
                   UInt
                   parseUInt(
                   final java.lang.String s,
                   final int radix)
                       throws java.lang.NumberFormatException{
        
//#line 532
return new x10.
          lang.
          UInt(java.lang.Integer.parseInt(s, ((int)(radix))));
    }
    
    
//#line 539
final public static x10.
                   lang.
                   UInt
                   parseUInt(
                   final java.lang.String s)
                       throws java.lang.NumberFormatException{
        
//#line 541
return new x10.
          lang.
          UInt(java.lang.Integer.parseInt(s));
    }
    
    
//#line 552
final public static x10.
                   lang.
                   UInt
                   parse(
                   final java.lang.String s,
                   final int radix)
                       throws java.lang.NumberFormatException{
        
//#line 554
return new x10.
          lang.
          UInt(java.lang.Integer.parseInt(s, ((int)(radix))));
    }
    
    
//#line 564
final public static x10.
                   lang.
                   UInt
                   parse(
                   final java.lang.String s)
                       throws java.lang.NumberFormatException{
        
//#line 566
return new x10.
          lang.
          UInt(java.lang.Integer.parseInt(s));
    }
    
    
//#line 578
final public x10.
                   lang.
                   UInt
                   highestOneBit(
                   ){
        
//#line 579
return new x10.
          lang.
          UInt(java.lang.Integer.highestOneBit(this.
                                                 intVal));
    }
    
    
//#line 589
final public x10.
                   lang.
                   UInt
                   lowestOneBit(
                   ){
        
//#line 590
return new x10.
          lang.
          UInt(java.lang.Integer.lowestOneBit(this.
                                                intVal));
    }
    
    
//#line 600
final public int
                   numberOfLeadingZeros(
                   ){
        
//#line 601
return java.lang.Integer.numberOfLeadingZeros(this.
                                                                     intVal);
    }
    
    
//#line 611
final public int
                   numberOfTrailingZeros(
                   ){
        
//#line 612
return java.lang.Integer.numberOfTrailingZeros(this.
                                                                      intVal);
    }
    
    
//#line 621
final public int
                   bitCount(
                   ){
        
//#line 622
return java.lang.Integer.bitCount(this.
                                                         intVal);
    }
    
    
//#line 641
final public x10.
                   lang.
                   UInt
                   rotateLeft(
                   final int distance){
        
//#line 642
return new x10.
          lang.
          UInt(java.lang.Integer.rotateLeft(this.
                                              intVal, ((int)(distance))));
    }
    
    
//#line 661
final public x10.
                   lang.
                   UInt
                   rotateRight(
                   final int distance){
        
//#line 662
return new x10.
          lang.
          UInt(java.lang.Integer.rotateRight(this.
                                               intVal, ((int)(distance))));
    }
    
    
//#line 670
final public x10.
                   lang.
                   UInt
                   reverse(
                   ){
        
//#line 671
return new x10.
          lang.
          UInt(java.lang.Integer.reverse(this.
                                           intVal));
    }
    
    
//#line 679
final public int
                   signum(
                   ){
        
//#line 680
return ((((int) this.
                                       intVal) ==
                              ((int) 0)))
          ? 0
          : 1;
    }
    
    
//#line 688
final public x10.
                   lang.
                   UInt
                   reverseBytes(
                   ){
        
//#line 689
return new x10.
          lang.
          UInt(java.lang.Integer.reverseBytes(this.
                                                intVal));
    }
    
    
//#line 699
final public boolean
                   equals(
                   final java.lang.Object x){
        
//#line 700
return x10.rtt.Equality.equalsequals(this.
                                                            intVal, x);
    }
    
    
//#line 708
final public boolean
                   equals(
                   final x10.
                     lang.
                     UInt x){
        
//#line 709
return ((int) this.
                                     intVal) ==
        ((int) x.
                 intVal);
    }
    
    
//#line 30
final native public x10.
                  lang.
                  Place
                  home(
                  );
    
    
//#line 30
final native public java.lang.String
                  typeName(
                  );
    
    
//#line 30
final native public boolean
                  at(
                  x10.
                    lang.
                    Place p);
    
    
//#line 30
final native public boolean
                  at(
                  java.lang.Object r);
    
    
//#line 30
final public boolean
                  _struct_equals(
                  java.lang.Object other){
        
//#line 30
if ((!(((boolean)(x10.rtt.Types.UINT.instanceof$(other)))))) {
            
//#line 30
return false;
        }
        
//#line 30
return this._struct_equals((x10.
                                                 lang.
                                                 UInt)(((x10.
                                                         lang.
                                                         UInt)
                                                         other)));
    }
    
    
//#line 30
final public boolean
                  _struct_equals(
                  x10.
                    lang.
                    UInt other){
        
//#line 30
return ((int) this.
                                    intVal) ==
        ((int) other.
                 intVal);
    }

}
