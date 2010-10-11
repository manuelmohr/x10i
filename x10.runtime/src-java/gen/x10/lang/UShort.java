package x10.lang;


final public class UShort
extends x10.core.Struct
{public static final x10.rtt.UShortType<UShort> _RTT = new x10.rtt.UShortType<UShort>(
/* base class */UShort.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
static {x10.rtt.Types.USHORT = _RTT;}
public x10.rtt.UShortType<UShort> getRTT() {return _RTT;}



    
//#line 31
/** The actual number with Short representation */final public short
      shortVal;
    
    
//#line 32
public UShort(final short value) {
        
//#line 33
this.shortVal = value;
    }
    
    
//#line 45
final public static boolean
                  $lt(
                  final x10.
                    lang.
                    UShort x,
                  final x10.
                    lang.
                    UShort y){
        
//#line 47
return ((((short)((((short) ((((short)(x.
                                                             shortVal))) + (((short)(java.lang.Short.MIN_VALUE))))))))) < (((short)((((short) ((((short)(y.
                                                                                                                                                           shortVal))) + (((short)(java.lang.Short.MIN_VALUE))))))))));
    }
    
    
//#line 59
final public static boolean
                  $gt(
                  final x10.
                    lang.
                    UShort x,
                  final x10.
                    lang.
                    UShort y){
        
//#line 61
return ((((short)((((short) ((((short)(x.
                                                             shortVal))) + (((short)(java.lang.Short.MIN_VALUE))))))))) > (((short)((((short) ((((short)(y.
                                                                                                                                                           shortVal))) + (((short)(java.lang.Short.MIN_VALUE))))))))));
    }
    
    
//#line 73
final public static boolean
                  $le(
                  final x10.
                    lang.
                    UShort x,
                  final x10.
                    lang.
                    UShort y){
        
//#line 75
return ((((short)((((short) ((((short)(x.
                                                             shortVal))) + (((short)(java.lang.Short.MIN_VALUE))))))))) <= (((short)((((short) ((((short)(y.
                                                                                                                                                            shortVal))) + (((short)(java.lang.Short.MIN_VALUE))))))))));
    }
    
    
//#line 87
final public static boolean
                  $ge(
                  final x10.
                    lang.
                    UShort x,
                  final x10.
                    lang.
                    UShort y){
        
//#line 89
return ((((short)((((short) ((((short)(x.
                                                             shortVal))) + (((short)(java.lang.Short.MIN_VALUE))))))))) >= (((short)((((short) ((((short)(y.
                                                                                                                                                            shortVal))) + (((short)(java.lang.Short.MIN_VALUE))))))))));
    }
    
    
//#line 102
final public static x10.
                   lang.
                   UShort
                   $plus(
                   final x10.
                     lang.
                     UShort x,
                   final x10.
                     lang.
                     UShort y){
        
//#line 103
return new x10.
          lang.
          UShort(((short) ((((short)(x.
                                       shortVal))) + (((short)(y.
                                                                 shortVal))))));
    }
    
    
//#line 109
final public static x10.
                   lang.
                   UShort
                   $plus(
                   final x10.
                     lang.
                     UShort x,
                   final short y){
        
//#line 110
return new x10.
          lang.
          UShort(((short) ((((short)(x.
                                       shortVal))) + (((short)(y))))));
    }
    
    
//#line 116
final public static x10.
                   lang.
                   UShort
                   $plus(
                   final short x,
                   final x10.
                     lang.
                     UShort y){
        
//#line 117
return new x10.
          lang.
          UShort(((short) ((((short)(x))) + (((short)(y.
                                                        shortVal))))));
    }
    
    
//#line 128
final public static x10.
                   lang.
                   UShort
                   $minus(
                   final x10.
                     lang.
                     UShort x,
                   final x10.
                     lang.
                     UShort y){
        
//#line 129
return new x10.
          lang.
          UShort(((short) ((((short)(x.
                                       shortVal))) - (((short)(y.
                                                                 shortVal))))));
    }
    
    
//#line 135
final public static x10.
                   lang.
                   UShort
                   $minus(
                   final short x,
                   final x10.
                     lang.
                     UShort y){
        
//#line 136
return new x10.
          lang.
          UShort(((short) ((((short)(x))) - (((short)(y.
                                                        shortVal))))));
    }
    
    
//#line 142
final public static x10.
                   lang.
                   UShort
                   $minus(
                   final x10.
                     lang.
                     UShort x,
                   final short y){
        
//#line 143
return new x10.
          lang.
          UShort(((short) ((((short)(x.
                                       shortVal))) - (((short)(y))))));
    }
    
    
//#line 154
final public static x10.
                   lang.
                   UShort
                   $times(
                   final x10.
                     lang.
                     UShort x,
                   final x10.
                     lang.
                     UShort y){
        
//#line 155
return new x10.
          lang.
          UShort(((short) ((((short)(x.
                                       shortVal))) * (((short)(y.
                                                                 shortVal))))));
    }
    
    
//#line 161
final public static x10.
                   lang.
                   UShort
                   $times(
                   final short x,
                   final x10.
                     lang.
                     UShort y){
        
//#line 162
return new x10.
          lang.
          UShort(((short) ((((short)(x))) * (((short)(y.
                                                        shortVal))))));
    }
    
    
//#line 168
final public static x10.
                   lang.
                   UShort
                   $times(
                   final x10.
                     lang.
                     UShort x,
                   final short y){
        
//#line 169
return new x10.
          lang.
          UShort(((short) ((((short)(x.
                                       shortVal))) * (((short)(y))))));
    }
    
    
//#line 179
final public static x10.
                   lang.
                   UShort
                   $over(
                   final x10.
                     lang.
                     UShort x,
                   final x10.
                     lang.
                     UShort y){
        
//#line 181
return new x10.
          lang.
          UShort(((short)(long)(((long)((((((long)((((long)(((short)(x.
                                                                       shortVal)))))))) / (((long)((((long)(((short)(y.
                                                                                                                       shortVal)))))))))))))));
    }
    
    
//#line 188
final public static x10.
                   lang.
                   UShort
                   $over(
                   final short x,
                   final x10.
                     lang.
                     UShort y){
        
//#line 190
return new x10.
          lang.
          UShort(((short)(long)(((long)((((((long)((((long)(((short)(x)))))))) / (((long)((((long)(((short)(y.
                                                                                                              shortVal)))))))))))))));
    }
    
    
//#line 197
final public static x10.
                   lang.
                   UShort
                   $over(
                   final x10.
                     lang.
                     UShort x,
                   final short y){
        
//#line 199
return new x10.
          lang.
          UShort(((short)(long)(((long)((((((long)((((long)(((short)(x.
                                                                       shortVal)))))))) / (((long)((((long)(((short)(y)))))))))))))));
    }
    
    
//#line 210
final public static x10.
                   lang.
                   UShort
                   $percent(
                   final x10.
                     lang.
                     UShort x,
                   final x10.
                     lang.
                     UShort y){
        
//#line 212
return new x10.
          lang.
          UShort(((short)(long)(((long)((((((long)((((long)(((short)(x.
                                                                       shortVal)))))))) % (((long)((((long)(((short)(y.
                                                                                                                       shortVal)))))))))))))));
    }
    
    
//#line 219
final public static x10.
                   lang.
                   UShort
                   $percent(
                   final short x,
                   final x10.
                     lang.
                     UShort y){
        
//#line 221
return new x10.
          lang.
          UShort(((short)(long)(((long)((((((long)((((long)(((short)(x)))))))) % (((long)((((long)(((short)(y.
                                                                                                              shortVal)))))))))))))));
    }
    
    
//#line 228
final public static x10.
                   lang.
                   UShort
                   $percent(
                   final x10.
                     lang.
                     UShort x,
                   final short y){
        
//#line 230
return new x10.
          lang.
          UShort(((short)(long)(((long)((((((long)((((long)(((short)(x.
                                                                       shortVal)))))))) % (((long)((((long)(((short)(y)))))))))))))));
    }
    
    
//#line 240
final public static x10.
                   lang.
                   UShort
                   $plus(
                   final x10.
                     lang.
                     UShort x){
        
//#line 241
return x;
    }
    
    
//#line 251
final public static x10.
                   lang.
                   UShort
                   $minus(
                   final x10.
                     lang.
                     UShort x){
        
//#line 252
return new x10.
          lang.
          UShort(((short) -(((short)((x.
                                        shortVal))))));
    }
    
    
//#line 263
final public static x10.
                   lang.
                   UShort
                   $ampersand(
                   final x10.
                     lang.
                     UShort x,
                   final x10.
                     lang.
                     UShort y){
        
//#line 264
return new x10.
          lang.
          UShort(((short) ((((short)(x.
                                       shortVal))) & (((short)(y.
                                                                 shortVal))))));
    }
    
    
//#line 270
final public static x10.
                   lang.
                   UShort
                   $ampersand(
                   final short x,
                   final x10.
                     lang.
                     UShort y){
        
//#line 271
return new x10.
          lang.
          UShort(((short) ((((short)(x))) & (((short)(y.
                                                        shortVal))))));
    }
    
    
//#line 277
final public static x10.
                   lang.
                   UShort
                   $ampersand(
                   final x10.
                     lang.
                     UShort x,
                   final short y){
        
//#line 278
return new x10.
          lang.
          UShort(((short) ((((short)(x.
                                       shortVal))) & (((short)(y))))));
    }
    
    
//#line 288
final public static x10.
                   lang.
                   UShort
                   $bar(
                   final x10.
                     lang.
                     UShort x,
                   final x10.
                     lang.
                     UShort y){
        
//#line 289
return new x10.
          lang.
          UShort(((short) ((((short)(x.
                                       shortVal))) | (((short)(y.
                                                                 shortVal))))));
    }
    
    
//#line 295
final public static x10.
                   lang.
                   UShort
                   $bar(
                   final short x,
                   final x10.
                     lang.
                     UShort y){
        
//#line 296
return new x10.
          lang.
          UShort(((short) ((((short)(x))) | (((short)(y.
                                                        shortVal))))));
    }
    
    
//#line 302
final public static x10.
                   lang.
                   UShort
                   $bar(
                   final x10.
                     lang.
                     UShort x,
                   final short y){
        
//#line 303
return new x10.
          lang.
          UShort(((short) ((((short)(x.
                                       shortVal))) | (((short)(y))))));
    }
    
    
//#line 313
final public static x10.
                   lang.
                   UShort
                   $caret(
                   final x10.
                     lang.
                     UShort x,
                   final x10.
                     lang.
                     UShort y){
        
//#line 314
return new x10.
          lang.
          UShort(((short) ((((short)(x.
                                       shortVal))) ^ (((short)(y.
                                                                 shortVal))))));
    }
    
    
//#line 320
final public static x10.
                   lang.
                   UShort
                   $caret(
                   final short x,
                   final x10.
                     lang.
                     UShort y){
        
//#line 321
return new x10.
          lang.
          UShort(((short) ((((short)(x))) ^ (((short)(y.
                                                        shortVal))))));
    }
    
    
//#line 327
final public static x10.
                   lang.
                   UShort
                   $caret(
                   final x10.
                     lang.
                     UShort x,
                   final short y){
        
//#line 328
return new x10.
          lang.
          UShort(((short) ((((short)(x.
                                       shortVal))) ^ (((short)(y))))));
    }
    
    
//#line 339
final public static x10.
                   lang.
                   UShort
                   $left(
                   final x10.
                     lang.
                     UShort x,
                   final int count){
        
//#line 340
return new x10.
          lang.
          UShort(((short) ((((short)(x.
                                       shortVal))) << (((int)(count))))));
    }
    
    
//#line 352
final public static x10.
                   lang.
                   UShort
                   $right(
                   final x10.
                     lang.
                     UShort x,
                   final int count){
        
//#line 353
return new x10.
          lang.
          UShort(((short) ((((short)(x.
                                       shortVal))) >>> (((int)(count))))));
    }
    
    
//#line 366
final public static x10.
                   lang.
                   UShort
                   $unsigned_right(
                   final x10.
                     lang.
                     UShort x,
                   final int count){
        
//#line 367
return new x10.
          lang.
          UShort(((short) ((((short)(x.
                                       shortVal))) >>> (((int)(count))))));
    }
    
    
//#line 376
final public static x10.
                   lang.
                   UShort
                   $tilde(
                   final x10.
                     lang.
                     UShort x){
        
//#line 377
return new x10.
          lang.
          UShort(((short) ~(((short)((x.
                                        shortVal))))));
    }
    
    
//#line 386
final public static x10.
                   lang.
                   UShort
                   $implicit_convert(
                   final x10.
                     lang.
                     UByte x){
        
//#line 387
return new x10.
          lang.
          UShort(((short) ((((short)(((short) (((byte)(x.
                                                         byteVal))))))) & (((short)(((short)(int)(((int)(255))))))))));
    }
    
    
//#line 395
final public static x10.
                   lang.
                   UShort
                   $convert(
                   final x10.
                     lang.
                     UInt x){
        
//#line 396
return new x10.
          lang.
          UShort(((short)(int)(((int)(x.
                                        intVal)))));
    }
    
    
//#line 404
final public static x10.
                   lang.
                   UShort
                   $convert(
                   final x10.
                     lang.
                     ULong x){
        
//#line 405
return new x10.
          lang.
          UShort(((short)(long)(((long)(x.
                                          longVal)))));
    }
    
    
//#line 414
final public static x10.
                   lang.
                   UShort
                   $implicit_convert(
                   final byte x){
        
//#line 415
return new x10.
          lang.
          UShort(((short) (((byte)(x)))));
    }
    
    
//#line 423
final public static x10.
                   lang.
                   UShort
                   $convert(
                   final int x){
        
//#line 424
return new x10.
          lang.
          UShort(((short)(int)(((int)(x)))));
    }
    
    
//#line 432
final public static x10.
                   lang.
                   UShort
                   $convert(
                   final long x){
        
//#line 433
return new x10.
          lang.
          UShort(((short)(long)(((long)(x)))));
    }
    
    
//#line 441
final public static x10.
                   lang.
                   UShort
                   $convert(
                   final float x){
        
//#line 443
final int temp =
          ((int)(float)(((float)(x))));
        
//#line 444
if (((((int)(temp))) > (((int)(65535))))) {
            
//#line 444
return new x10.
              lang.
              UShort(((short) (((byte)(((byte)(int)(((int)(65535)))))))));
        } else {
            
//#line 445
if (((((int)(temp))) < (((int)(0))))) {
                
//#line 445
return new x10.
                  lang.
                  UShort(((short)(int)(((int)(0)))));
            } else {
                
//#line 446
return new x10.
                  lang.
                  UShort(((short)(int)(((int)(temp)))));
            }
        }
    }
    
    
//#line 455
final public static x10.
                   lang.
                   UShort
                   $convert(
                   final double x){
        
//#line 457
final int temp =
          ((int)(double)(((double)(x))));
        
//#line 458
if (((((int)(temp))) > (((int)(65535))))) {
            
//#line 458
return new x10.
              lang.
              UShort(((short) (((byte)(((byte)(int)(((int)(65535)))))))));
        } else {
            
//#line 459
if (((((int)(temp))) < (((int)(0))))) {
                
//#line 459
return new x10.
                  lang.
                  UShort(((short)(int)(((int)(0)))));
            } else {
                
//#line 460
return new x10.
                  lang.
                  UShort(((short)(int)(((int)(temp)))));
            }
        }
    }
    
    
//#line 469
final public static x10.
                   lang.
                   UShort
                   $implicit_convert(
                   final short x){
        
//#line 470
return new x10.
          lang.
          UShort(x);
    }
    
    
//#line 478
/**
     * A constant holding the minimum value a UShort can have, 0.
     */final public static x10.
      lang.
      UShort
      MIN_VALUE =
      x10.
      lang.
      UShort.$convert((int)(0));
    
//#line 485
/**
     * A constant holding the maximum value a UShort can have, 2<sup>16</sup>-1.
     */final public static x10.
      lang.
      UShort
      MAX_VALUE =
      x10.
      lang.
      UShort.$convert((int)(65535));
    
    
//#line 494
final public java.lang.String
                   toString(
                   final int radix){
        
//#line 495
return java.lang.Integer.toString((((int) (int) 
                                                          ((((((int)(((int)(short)(((short)(this.
                                                                                              shortVal))))))) & (((int)(65535)))))))), ((int)(radix)));
    }
    
    
//#line 502
final public java.lang.String
                   toHexString(
                   ){
        
//#line 503
return java.lang.Integer.toHexString(this.
                                                            shortVal);
    }
    
    
//#line 510
final public java.lang.String
                   toOctalString(
                   ){
        
//#line 511
return java.lang.Integer.toOctalString(this.
                                                              shortVal);
    }
    
    
//#line 518
final public java.lang.String
                   toBinaryString(
                   ){
        
//#line 519
return java.lang.Integer.toBinaryString(this.
                                                               shortVal);
    }
    
    
//#line 526
final public java.lang.String
                   toString(
                   ){
        
//#line 527
return java.lang.Integer.toString((((int) (int) 
                                                          ((((((int)(((int)(short)(((short)(this.
                                                                                              shortVal))))))) & (((int)(65535)))))))));
    }
    
    
//#line 533
final public static x10.
                   lang.
                   UShort
                   parseUShort(
                   final java.lang.String s,
                   final int radix)
                       throws java.lang.NumberFormatException{
        
//#line 535
return new x10.
          lang.
          UShort(java.lang.Short.parseShort(s, ((int)(radix))));
    }
    
    
//#line 542
final public static x10.
                   lang.
                   UShort
                   parseUShort(
                   final java.lang.String s)
                       throws java.lang.NumberFormatException{
        
//#line 544
return new x10.
          lang.
          UShort(java.lang.Short.parseShort(s));
    }
    
    
//#line 555
final public static x10.
                   lang.
                   UShort
                   parse(
                   final java.lang.String s,
                   final int radix)
                       throws java.lang.NumberFormatException{
        
//#line 557
return new x10.
          lang.
          UShort(java.lang.Short.parseShort(s, ((int)(radix))));
    }
    
    
//#line 567
final public static x10.
                   lang.
                   UShort
                   parse(
                   final java.lang.String s)
                       throws java.lang.NumberFormatException{
        
//#line 569
return new x10.
          lang.
          UShort(java.lang.Short.parseShort(s));
    }
    
    
//#line 579
final public x10.
                   lang.
                   UShort
                   reverse(
                   ){
        
//#line 580
return new x10.
          lang.
          UShort(((short)(java.lang.Integer.reverse(this.
                                                      shortVal)>>>16)));
    }
    
    
//#line 588
final public int
                   signum(
                   ){
        
//#line 589
return ((((int) ((int)(short)(((short)(this.
                                                              shortVal))))) ==
                              ((int) 0)))
          ? 0
          : 1;
    }
    
    
//#line 597
final public x10.
                   lang.
                   UShort
                   reverseBytes(
                   ){
        
//#line 598
return new x10.
          lang.
          UShort(java.lang.Short.reverseBytes(this.
                                                shortVal));
    }
    
    
//#line 608
final public boolean
                   equals(
                   final java.lang.Object x){
        
//#line 609
return x10.rtt.Equality.equalsequals(this.
                                                            shortVal, x);
    }
    
    
//#line 617
final public boolean
                   equals(
                   final x10.
                     lang.
                     UShort x){
        
//#line 618
return ((short) this.
                                       shortVal) ==
        ((short) x.
                   shortVal);
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
if ((!(((boolean)(x10.rtt.Types.USHORT.instanceof$(other)))))) {
            
//#line 28
return false;
        }
        
//#line 28
return this._struct_equals((x10.
                                                 lang.
                                                 UShort)(((x10.
                                                           lang.
                                                           UShort)
                                                           other)));
    }
    
    
//#line 28
final public boolean
                  _struct_equals(
                  x10.
                    lang.
                    UShort other){
        
//#line 28
return ((short) this.
                                      shortVal) ==
        ((short) other.
                   shortVal);
    }

}
