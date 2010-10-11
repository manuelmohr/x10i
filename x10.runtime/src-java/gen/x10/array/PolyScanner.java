package x10.array;


final public class PolyScanner
extends x10.core.Ref
  implements x10.
               array.
               Region.
               Scanner
{public static final x10.rtt.RuntimeType<PolyScanner> _RTT = new x10.rtt.RuntimeType<PolyScanner>(
/* base class */PolyScanner.class
, /* parents */ new x10.rtt.Type[] {x10.array.Region.Scanner._RTT, x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 68
final public int
      rank;
    
    
//#line 70
final public x10.
      array.
      PolyMat
      C;
    
//#line 74
final public x10.core.Rail<x10.
      array.
      VarMat>
      myMin;
    
//#line 75
final public x10.core.Rail<x10.
      array.
      VarMat>
      myMax;
    
//#line 76
final public x10.core.Rail<x10.
      array.
      VarMat>
      minSum;
    
//#line 77
final public x10.core.Rail<x10.
      array.
      VarMat>
      maxSum;
    
//#line 79
final public x10.core.Rail<java.lang.Boolean>
      parFlags;
    
//#line 80
final public x10.core.Rail<x10.core.Rail<x10.
      array.
      PolyRow>>
      min2;
    
//#line 81
final public x10.core.Rail<x10.core.Rail<x10.
      array.
      PolyRow>>
      max2;
    
    
//#line 83
public static x10.
                  array.
                  PolyScanner
                  make(
                  final x10.
                    array.
                    PolyMat pm){
        
//#line 84
final x10.
          array.
          PolyScanner x =
          ((x10.
          array.
          PolyScanner)(new x10.
          array.
          PolyScanner(pm)));
        
//#line 85
x.init();
        
//#line 86
return x;
    }
    
    
//#line 89
private PolyScanner(final x10.
                                      array.
                                      PolyMat pm) {
        super();
        
//#line 90
this.rank = pm.
                                  rank;
        
//#line 91
x10.
          array.
          PolyMat pm0 =
          pm.simplifyAll();
        
//#line 93
this.C = pm;
        
//#line 94
final int r =
          pm0.
            rank;
        
//#line 95
final x10.core.Rail<x10.
          array.
          VarMat> n =
          ((x10.core.Rail)(x10.core.RailFactory.<x10.
          array.
          VarMat>makeVarRail(x10.array.VarMat._RTT, ((int)(r)))));
        
//#line 96
this.myMin = ((x10.core.Rail)(n));
        
//#line 97
final x10.core.Rail<x10.
          array.
          VarMat> x =
          ((x10.core.Rail)(x10.core.RailFactory.<x10.
          array.
          VarMat>makeVarRail(x10.array.VarMat._RTT, ((int)(r)))));
        
//#line 98
this.myMax = ((x10.core.Rail)(x));
        
//#line 99
final x10.core.Rail<x10.
          array.
          VarMat> nSum =
          ((x10.core.Rail)(x10.core.RailFactory.<x10.
          array.
          VarMat>makeVarRail(x10.array.VarMat._RTT, ((int)(r)))));
        
//#line 100
this.minSum = ((x10.core.Rail)(nSum));
        
//#line 101
final x10.core.Rail<x10.
          array.
          VarMat> xSum =
          ((x10.core.Rail)(x10.core.RailFactory.<x10.
          array.
          VarMat>makeVarRail(x10.array.VarMat._RTT, ((int)(r)))));
        
//#line 102
this.maxSum = ((x10.core.Rail)(xSum));
        
//#line 103
final x10.core.Rail<x10.core.Rail<x10.
          array.
          PolyRow>> n2 =
          ((x10.core.Rail)(x10.core.RailFactory.<x10.core.Rail<x10.
          array.
          PolyRow>>makeVarRail(new x10.rtt.ParameterizedType(x10.core.Rail._RTT, x10.array.PolyRow._RTT), ((int)(r)))));
        
//#line 104
this.min2 = ((x10.core.Rail)(n2));
        
//#line 105
final x10.core.Rail<x10.core.Rail<x10.
          array.
          PolyRow>> x2 =
          ((x10.core.Rail)(x10.core.RailFactory.<x10.core.Rail<x10.
          array.
          PolyRow>>makeVarRail(new x10.rtt.ParameterizedType(x10.core.Rail._RTT, x10.array.PolyRow._RTT), ((int)(r)))));
        
//#line 106
this.max2 = ((x10.core.Rail)(x2));
        
//#line 109
this.parFlags = ((x10.core.Rail)(x10.core.RailFactory.<java.lang.Boolean>makeVarRail(x10.rtt.Types.BOOLEAN, ((int)(r)))));
    }
    
    
//#line 112
private void
                   init(
                   ){
        
//#line 113
x10.
          array.
          PolyMat pm =
          C;
        
//#line 114
this.init(((x10.
                                 array.
                                 PolyMat)(pm)),
                               (int)(((((int)(rank))) - (((int)(1))))));
        
//#line 115
for (
//#line 115
int k =
                            ((((int)(rank))) - (((int)(2))));
                          ((((int)(k))) >= (((int)(0))));
                          
//#line 115
k = ((((int)(k))) - (((int)(1))))) {
            
//#line 116
pm = pm.eliminate((int)(((((int)(k))) + (((int)(1))))),
                                           (boolean)(true));
            
//#line 117
this.init(((x10.
                                     array.
                                     PolyMat)(pm)),
                                   (int)(k));
        }
    }
    
    public static void
      init$P(
      final x10.
        array.
        PolyScanner PolyScanner){
        PolyScanner.init();
    }
    
    
//#line 122
final private void
                   init(
                   final x10.
                     array.
                     PolyMat pm,
                   final int axis){
        
//#line 127
int imin =
          0;
        
//#line 128
int imax =
          0;
        
//#line 129
for (
//#line 129
final x10.core.Iterator<x10.
                            array.
                            PolyRow> r1656 =
                            pm.iterator();
                          r1656.hasNext();
                          ) {
            
//#line 129
final x10.
              array.
              PolyRow r =
              r1656.next$G();
            
//#line 130
if (((((int)(r.apply((int)(axis))))) < (((int)(0))))) {
                
//#line 130
imin = ((((int)(imin))) + (((int)(1))));
            }
            
//#line 131
if (((((int)(r.apply((int)(axis))))) > (((int)(0))))) {
                
//#line 131
imax = ((((int)(imax))) + (((int)(1))));
            }
        }
        
//#line 135
if (((int) imin) ==
                         ((int) 0) ||
                         ((int) imax) ==
                         ((int) 0)) {
            
//#line 136
final java.lang.String m =
              ((int) imin) ==
            ((int) 0)
              ? "minimum"
              : "maximum";
            
//#line 137
final java.lang.String msg =
              (((((("axis ") + (((java.lang.Integer)(axis))))) + (" has no "))) + (m));
            
//#line 138
throw new x10.
              array.
              UnboundedRegionException(msg);
        }
        
//#line 142
((x10.
          array.
          VarMat[])myMin.value)[axis] = new x10.
          array.
          VarMat(imin,
                 ((((int)(axis))) + (((int)(1)))));
        
//#line 143
((x10.
          array.
          VarMat[])myMax.value)[axis] = new x10.
          array.
          VarMat(imax,
                 ((((int)(axis))) + (((int)(1)))));
        
//#line 144
((x10.
          array.
          VarMat[])minSum.value)[axis] = new x10.
          array.
          VarMat(imin,
                 ((((int)(axis))) + (((int)(1)))));
        
//#line 145
((x10.
          array.
          VarMat[])maxSum.value)[axis] = new x10.
          array.
          VarMat(imax,
                 ((((int)(axis))) + (((int)(1)))));
        
//#line 146
((x10.core.Rail[])min2.value)[axis] = x10.core.RailFactory.<x10.
          array.
          PolyRow>makeVarRail(x10.array.PolyRow._RTT, ((int)(imin)));
        
//#line 147
((x10.core.Rail[])max2.value)[axis] = x10.core.RailFactory.<x10.
          array.
          PolyRow>makeVarRail(x10.array.PolyRow._RTT, ((int)(imax)));
        
//#line 150
imin = 0;
        
//#line 150
imax = 0;
        {
            
//#line 151
final x10.
              array.
              VarMat[] x10$array$PolyScanner$this$myMin$value1955 =
              ((x10.
              array.
              VarMat[])myMin.value);
            
//#line 151
final x10.
              array.
              VarMat[] x10$array$PolyScanner$this$myMax$value1956 =
              ((x10.
              array.
              VarMat[])myMax.value);
            
//#line 151
final x10.
              array.
              VarMat[] x10$array$PolyScanner$this$minSum$value1957 =
              ((x10.
              array.
              VarMat[])minSum.value);
            
//#line 151
final x10.core.Rail[] x10$array$PolyScanner$this$min2$value1958 =
              ((x10.core.Rail[])min2.value);
            
//#line 151
final x10.
              array.
              VarMat[] x10$array$PolyScanner$this$maxSum$value1959 =
              ((x10.
              array.
              VarMat[])maxSum.value);
            
//#line 151
final x10.core.Rail[] x10$array$PolyScanner$this$max2$value1960 =
              ((x10.core.Rail[])max2.value);
            
//#line 151
for (
//#line 151
final x10.core.Iterator<x10.
                                array.
                                PolyRow> r1657 =
                                pm.iterator();
                              r1657.hasNext();
                              ) {
                
//#line 151
final x10.
                  array.
                  PolyRow r =
                  r1657.next$G();
                
//#line 152
if (((((int)(r.apply((int)(axis))))) < (((int)(0))))) {
                    {
                        
//#line 153
for (
//#line 153
int i =
                                            0;
                                          ((((int)(i))) <= (((int)(axis))));
                                          
//#line 153
i = ((((int)(i))) + (((int)(1))))) {
                            
//#line 154
((x10.
                              array.
                              VarMat)x10$array$PolyScanner$this$myMin$value1955[axis]).apply$G((int)(imin)).set((int)(r.apply((int)(i))),
                                                                                                                (int)(i));
                        }
                    }
                    
//#line 155
((x10.
                      array.
                      VarMat)x10$array$PolyScanner$this$minSum$value1957[axis]).apply$G((int)(imin)).set((int)(r.apply((int)(rank))),
                                                                                                         (int)(0));
                    
//#line 156
((x10.
                      array.
                      PolyRow[])((x10.core.Rail<x10.
                      array.
                      PolyRow>)x10$array$PolyScanner$this$min2$value1958[axis]).value)[imin] = r;
                    
//#line 157
imin = ((((int)(imin))) + (((int)(1))));
                }
                
//#line 159
if (((((int)(r.apply((int)(axis))))) > (((int)(0))))) {
                    {
                        
//#line 160
for (
//#line 160
int i =
                                            0;
                                          ((((int)(i))) <= (((int)(axis))));
                                          
//#line 160
i = ((((int)(i))) + (((int)(1))))) {
                            
//#line 161
((x10.
                              array.
                              VarMat)x10$array$PolyScanner$this$myMax$value1956[axis]).apply$G((int)(imax)).set((int)(r.apply((int)(i))),
                                                                                                                (int)(i));
                        }
                    }
                    
//#line 162
((x10.
                      array.
                      VarMat)x10$array$PolyScanner$this$maxSum$value1959[axis]).apply$G((int)(imax)).set((int)(r.apply((int)(rank))),
                                                                                                         (int)(0));
                    
//#line 163
((x10.
                      array.
                      PolyRow[])((x10.core.Rail<x10.
                      array.
                      PolyRow>)x10$array$PolyScanner$this$max2$value1960[axis]).value)[imax] = r;
                    
//#line 164
imax = ((((int)(imax))) + (((int)(1))));
                }
            }
        }
    }
    
    final public static void
      init$P(
      final x10.
        array.
        PolyMat pm,
      final int axis,
      final x10.
        array.
        PolyScanner PolyScanner){
        PolyScanner.init(((x10.
                           array.
                           PolyMat)(pm)),
                         (int)(axis));
    }
    
    
//#line 176
final public void
                   set(
                   final int axis,
                   final int v){
        {
            
//#line 177
final x10.
              array.
              VarMat[] x10$array$PolyScanner$this$minSum$value1961 =
              ((x10.
              array.
              VarMat[])minSum.value);
            
//#line 177
final x10.
              array.
              VarMat[] x10$array$PolyScanner$this$myMin$value1962 =
              ((x10.
              array.
              VarMat[])myMin.value);
            
//#line 177
for (
//#line 177
int k =
                                ((((int)(axis))) + (((int)(1))));
                              ((((int)(k))) < (((int)(rank))));
                              
//#line 177
k = ((((int)(k))) + (((int)(1))))) {
                {
                    
//#line 178
for (
//#line 178
int l =
                                        0;
                                      ((((int)(l))) < (((int)(((x10.
                                                                array.
                                                                VarMat)((x10.
                                                                array.
                                                                VarMat[])minSum.value)[k]).
                                                                rows))));
                                      
//#line 178
l = ((((int)(l))) + (((int)(1))))) {
                        
//#line 179
((x10.
                          array.
                          VarMat)x10$array$PolyScanner$this$minSum$value1961[k]).apply$G((int)(l)).set((int)(((((int)(((((int)(((x10.
                                                                                                         array.
                                                                                                         VarMat)x10$array$PolyScanner$this$myMin$value1962[k]).apply$G((int)(l)).apply((int)(axis))))) * (((int)(v))))))) + (((int)(((x10.
                                                                                                         array.
                                                                                                         VarMat)x10$array$PolyScanner$this$minSum$value1961[k]).apply$G((int)(l)).apply((int)(axis))))))),
                                                                                                       (int)(((((int)(axis))) + (((int)(1))))));
                    }
                }
            }
        }
        {
            
//#line 180
final x10.
              array.
              VarMat[] x10$array$PolyScanner$this$maxSum$value1963 =
              ((x10.
              array.
              VarMat[])maxSum.value);
            
//#line 180
final x10.
              array.
              VarMat[] x10$array$PolyScanner$this$myMax$value1964 =
              ((x10.
              array.
              VarMat[])myMax.value);
            
//#line 180
for (
//#line 180
int k =
                                ((((int)(axis))) + (((int)(1))));
                              ((((int)(k))) < (((int)(rank))));
                              
//#line 180
k = ((((int)(k))) + (((int)(1))))) {
                {
                    
//#line 181
for (
//#line 181
int l =
                                        0;
                                      ((((int)(l))) < (((int)(((x10.
                                                                array.
                                                                VarMat)((x10.
                                                                array.
                                                                VarMat[])maxSum.value)[k]).
                                                                rows))));
                                      
//#line 181
l = ((((int)(l))) + (((int)(1))))) {
                        
//#line 182
((x10.
                          array.
                          VarMat)x10$array$PolyScanner$this$maxSum$value1963[k]).apply$G((int)(l)).set((int)(((((int)(((((int)(((x10.
                                                                                                         array.
                                                                                                         VarMat)x10$array$PolyScanner$this$myMax$value1964[k]).apply$G((int)(l)).apply((int)(axis))))) * (((int)(v))))))) + (((int)(((x10.
                                                                                                         array.
                                                                                                         VarMat)x10$array$PolyScanner$this$maxSum$value1963[k]).apply$G((int)(l)).apply((int)(axis))))))),
                                                                                                       (int)(((((int)(axis))) + (((int)(1))))));
                    }
                }
            }
        }
    }
    
    
//#line 185
final public int
                   min(
                   final int axis){
        
//#line 186
int result =
          java.lang.Integer.MIN_VALUE;
        {
            
//#line 187
final x10.
              array.
              VarMat[] x10$array$PolyScanner$this$myMin$value1965 =
              ((x10.
              array.
              VarMat[])myMin.value);
            
//#line 187
final x10.
              array.
              VarMat[] x10$array$PolyScanner$this$minSum$value1966 =
              ((x10.
              array.
              VarMat[])minSum.value);
            
//#line 187
for (
//#line 187
int k =
                                0;
                              ((((int)(k))) < (((int)(((x10.
                                                        array.
                                                        VarMat)((x10.
                                                        array.
                                                        VarMat[])myMin.value)[axis]).
                                                        rows))));
                              
//#line 187
k = ((((int)(k))) + (((int)(1))))) {
                
//#line 188
final int a =
                  ((x10.
                  array.
                  VarMat)x10$array$PolyScanner$this$myMin$value1965[axis]).apply$G((int)(k)).apply((int)(axis));
                
//#line 189
int b =
                  ((x10.
                  array.
                  VarMat)x10$array$PolyScanner$this$minSum$value1966[axis]).apply$G((int)(k)).apply((int)(axis));
                
//#line 191
final int m =
                  ((((int)(b))) > (((int)(0))))
                  ? ((((int)((((((int)(((((int)((-(((int)(b))))))) + (((int)(a))))))) + (((int)(1)))))))) / (((int)(a))))
                  : ((((int)((-(((int)(b))))))) / (((int)(a))));
                
//#line 192
if (((((int)(m))) > (((int)(result))))) {
                    
//#line 192
result = m;
                }
            }
        }
        
//#line 194
return result;
    }
    
    
//#line 197
final public int
                   max(
                   final int axis){
        
//#line 198
int result =
          java.lang.Integer.MAX_VALUE;
        {
            
//#line 199
final x10.
              array.
              VarMat[] x10$array$PolyScanner$this$myMax$value1967 =
              ((x10.
              array.
              VarMat[])myMax.value);
            
//#line 199
final x10.
              array.
              VarMat[] x10$array$PolyScanner$this$maxSum$value1968 =
              ((x10.
              array.
              VarMat[])maxSum.value);
            
//#line 199
for (
//#line 199
int k =
                                0;
                              ((((int)(k))) < (((int)(((x10.
                                                        array.
                                                        VarMat)((x10.
                                                        array.
                                                        VarMat[])myMax.value)[axis]).
                                                        rows))));
                              
//#line 199
k = ((((int)(k))) + (((int)(1))))) {
                
//#line 200
final int a =
                  ((x10.
                  array.
                  VarMat)x10$array$PolyScanner$this$myMax$value1967[axis]).apply$G((int)(k)).apply((int)(axis));
                
//#line 201
final int b =
                  ((x10.
                  array.
                  VarMat)x10$array$PolyScanner$this$maxSum$value1968[axis]).apply$G((int)(k)).apply((int)(axis));
                
//#line 203
final int m =
                  ((((int)(b))) > (((int)(0))))
                  ? ((((int)((((((int)(((((int)((-(((int)(b))))))) - (((int)(a))))))) + (((int)(1)))))))) / (((int)(a))))
                  : ((((int)((-(((int)(b))))))) / (((int)(a))));
                
//#line 204
if (((((int)(m))) < (((int)(result))))) {
                    
//#line 204
result = m;
                }
            }
        }
        
//#line 206
return result;
    }
    
    
//#line 228
final public static class RailIt
                 extends x10.core.Ref
                   implements x10.core.Iterator<x10.core.Rail<java.lang.Integer>>
                 {public static final x10.rtt.RuntimeType<RailIt> _RTT = new x10.rtt.RuntimeType<RailIt>(
    /* base class */RailIt.class
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(new x10.rtt.RuntimeType(x10.core.Iterator.class), new x10.rtt.ParameterizedType(new x10.rtt.RuntimeType(x10.core.Rail.class), x10.rtt.Types.INT)), x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    // bridge for method abstract public x10.lang.Iterator.next(): T
    final public x10.core.Rail<java.lang.Integer>
      next$G(){return next();}
    
        
//#line 68
final public x10.
          array.
          PolyScanner
          out$;
        
        
//#line 229
public x10.
                       array.
                       PolyScanner
                       outerThis(
                       ){
            
//#line 229
return x10.
              array.
              PolyScanner.
              RailIt.__$closure$apply$__1951(((x10.
                                               array.
                                               PolyScanner)(((x10.
                                                              array.
                                                              PolyScanner)
                                                              this.
                                                                out$))));
        }
        
        
//#line 230
final public int
          rank;
        
//#line 231
final public x10.
          array.
          PolyScanner
          s;
        
//#line 233
final public x10.core.Rail<java.lang.Integer>
          x;
        
//#line 234
final public x10.core.Rail<java.lang.Integer>
          myMin;
        
//#line 235
final public x10.core.Rail<java.lang.Integer>
          myMax;
        
//#line 237
public int
          k;
        
        
//#line 238
public RailIt(final x10.
                                     array.
                                     PolyScanner out$) {
            super();
            
//#line 68
this.out$ = out$;
            
//#line 230
this.rank = this.outerThis().
                                       rank;
            
//#line 231
this.s = ((x10.
              array.
              PolyScanner)(this.outerThis()));
            
//#line 233
this.x = ((x10.core.Rail)(x10.core.RailFactory.<java.lang.Integer>makeVarRail(x10.rtt.Types.INT, ((int)(rank)))));
            
//#line 234
this.myMin = ((x10.core.Rail)(x10.core.RailFactory.<java.lang.Integer>makeVarRail(x10.rtt.Types.INT, ((int)(rank)))));
            
//#line 235
this.myMax = ((x10.core.Rail)(x10.core.RailFactory.<java.lang.Integer>makeVarRail(x10.rtt.Types.INT, ((int)(rank)))));
            
//#line 237
this.k = 0;
        }
        
        
//#line 239
public void
                       init(
                       ){
            
//#line 240
((int[])myMin.value)[0] = s.min((int)(0));
            
//#line 241
((int[])myMax.value)[0] = s.max((int)(0));
            
//#line 242
((int[])x.value)[0] = s.min((int)(0));
            {
                
//#line 243
final int[] x10$array$PolyScanner$RailIt$this$x$value1969 =
                  ((int[])x.value);
                
//#line 243
final int[] x10$array$PolyScanner$RailIt$this$myMin$value1970 =
                  ((int[])myMin.value);
                
//#line 243
final int[] x10$array$PolyScanner$RailIt$this$myMax$value1971 =
                  ((int[])myMax.value);
                
//#line 243
for (
//#line 243
this.k = 1;
                                  ((((int)(k))) < (((int)(rank))));
                                  
//#line 243
x10.
                                    array.
                                    PolyScanner.
                                    RailIt.__$closure$apply$__1952(((x10.
                                                                     array.
                                                                     PolyScanner.
                                                                     RailIt)(this)),
                                                                   (int)(1))) {
                    
//#line 244
s.set((int)(((((int)(k))) - (((int)(1))))),
                                       (int)(((int)x10$array$PolyScanner$RailIt$this$x$value1969[((((int)(k))) - (((int)(1))))])));
                    
//#line 245
final int m =
                      s.min((int)(k));
                    
//#line 246
x10$array$PolyScanner$RailIt$this$x$value1969[k]=m;
                    
//#line 247
x10$array$PolyScanner$RailIt$this$myMin$value1970[k]=m;
                    
//#line 248
x10$array$PolyScanner$RailIt$this$myMax$value1971[k]=s.max((int)(k));
                }
            }
            
//#line 250
((int[])x.value)[((((int)(rank))) - (((int)(1))))] -= 1;
        }
        
        
//#line 253
final public boolean
                       hasNext(
                       ){
            
//#line 254
this.k = ((((int)(rank))) - (((int)(1))));
            
//#line 255
while (((((int)(((int[])x.value)[k]))) >= (((int)(((int[])myMax.value)[k])))))
                
//#line 256
if (((x10.
                                   array.
                                   PolyScanner.
                                   RailIt.__$closure$apply$__1953(((x10.
                                                                    array.
                                                                    PolyScanner.
                                                                    RailIt)(this)),
                                                                  (int)(1))) < (((int)(0))))) {
                    
//#line 257
return false;
                }
            
//#line 258
return true;
        }
        
        
//#line 261
final public x10.core.Rail<java.lang.Integer>
                       next(
                       ){
            
//#line 262
((int[])x.value)[k] += 1;
            {
                
//#line 263
final int[] x10$array$PolyScanner$RailIt$this$x$value1972 =
                  ((int[])x.value);
                
//#line 263
final int[] x10$array$PolyScanner$RailIt$this$myMin$value1973 =
                  ((int[])myMin.value);
                
//#line 263
final int[] x10$array$PolyScanner$RailIt$this$myMax$value1974 =
                  ((int[])myMax.value);
                
//#line 263
for (
//#line 263
this.k = ((((int)(k))) + (((int)(1))));
                                  ((((int)(k))) < (((int)(rank))));
                                  
//#line 263
x10.
                                    array.
                                    PolyScanner.
                                    RailIt.__$closure$apply$__1954(((x10.
                                                                     array.
                                                                     PolyScanner.
                                                                     RailIt)(this)),
                                                                   (int)(1))) {
                    
//#line 264
s.set((int)(((((int)(k))) - (((int)(1))))),
                                       (int)(((int)x10$array$PolyScanner$RailIt$this$x$value1972[((((int)(k))) - (((int)(1))))])));
                    
//#line 265
final int m =
                      s.min((int)(k));
                    
//#line 266
x10$array$PolyScanner$RailIt$this$x$value1972[k]=m;
                    
//#line 267
x10$array$PolyScanner$RailIt$this$myMin$value1973[k]=m;
                    
//#line 268
x10$array$PolyScanner$RailIt$this$myMax$value1974[k]=s.max((int)(k));
                }
            }
            
//#line 270
return x;
        }
        
        
//#line 273
public void
                       remove(
                       ){
            
        }
        
        final private static x10.
          array.
          PolyScanner
          __$closure$apply$__1951(
          final x10.
            array.
            PolyScanner __desugarer__var__27__){
            
//#line 229
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__27__,null)) &&
                               !(x10.rtt.Equality.equalsequals(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__27__)),x10.
                                   lang.
                                   Runtime.here()))) {
                
//#line 229
throw new java.lang.ClassCastException("x10.array.PolyScanner{self.home==here}");
            }
            
//#line 229
return __desugarer__var__27__;
        }
        
        final public static x10.
          array.
          PolyScanner
          __$closure$apply$__1951$P(
          final x10.
            array.
            PolyScanner __desugarer__var__27__){
            return RailIt.__$closure$apply$__1951(((x10.
                                                    array.
                                                    PolyScanner)(__desugarer__var__27__)));
        }
        
        final private static int
          __$closure$apply$__1952(
          final x10.
            array.
            PolyScanner.
            RailIt x,
          final int y){
            
//#line 243
return x.k = ((((int)(x.
                                                 k))) + (((int)(y))));
        }
        
        final public static int
          __$closure$apply$__1952$P(
          final x10.
            array.
            PolyScanner.
            RailIt x,
          final int y){
            return RailIt.__$closure$apply$__1952(((x10.
                                                    array.
                                                    PolyScanner.
                                                    RailIt)(x)),
                                                  (int)(y));
        }
        
        final private static int
          __$closure$apply$__1953(
          final x10.
            array.
            PolyScanner.
            RailIt x,
          final int y){
            
//#line 256
return x.k = ((((int)(x.
                                                 k))) - (((int)(y))));
        }
        
        final public static int
          __$closure$apply$__1953$P(
          final x10.
            array.
            PolyScanner.
            RailIt x,
          final int y){
            return RailIt.__$closure$apply$__1953(((x10.
                                                    array.
                                                    PolyScanner.
                                                    RailIt)(x)),
                                                  (int)(y));
        }
        
        final private static int
          __$closure$apply$__1954(
          final x10.
            array.
            PolyScanner.
            RailIt x,
          final int y){
            
//#line 263
return x.k = ((((int)(x.
                                                 k))) + (((int)(y))));
        }
        
        final public static int
          __$closure$apply$__1954$P(
          final x10.
            array.
            PolyScanner.
            RailIt x,
          final int y){
            return RailIt.__$closure$apply$__1954(((x10.
                                                    array.
                                                    PolyScanner.
                                                    RailIt)(x)),
                                                  (int)(y));
        }
    
    }
    
    
//#line 283
final public static class PointIt
                 extends x10.core.Ref
                   implements x10.core.Iterator<x10.
                                array.
                                Point>
                 {public static final x10.rtt.RuntimeType<PointIt> _RTT = new x10.rtt.RuntimeType<PointIt>(
    /* base class */PointIt.class
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(new x10.rtt.RuntimeType(x10.core.Iterator.class), x10.array.Point._RTT), x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    // bridge for method abstract public x10.lang.Iterator.next(): T
    final public x10.
      array.
      Point
      next$G(){return next();}
    
        
//#line 68
final public x10.
          array.
          PolyScanner
          out$;
        
//#line 286
final public x10.
          array.
          PolyScanner.
          RailIt
          it;
        
        
//#line 288
public PointIt(final x10.
                                      array.
                                      PolyScanner out$) {
            super();
            
//#line 68
this.out$ = out$;
            
//#line 289
this.it = ((x10.
              array.
              PolyScanner.
              RailIt)(new x10.
              array.
              PolyScanner.
              RailIt(this.
                       out$)));
        }
        
        
//#line 292
final public boolean
                       hasNext(
                       ){
            
//#line 292
return it.hasNext();
        }
        
        
//#line 293
final public x10.
                       array.
                       Point
                       next(
                       ){
            
//#line 293
return new x10.core.fun.Fun_0_1<x10.
              array.
              Point, x10.
              array.
              Point>() {public final x10.
              array.
              Point apply$G(final x10.
              array.
              Point __desugarer__var__28__) { return apply(__desugarer__var__28__);}
            public final x10.
              array.
              Point apply(final x10.
              array.
              Point __desugarer__var__28__) { {
                
//#line 293
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__28__,null)) &&
                                   !(((int) __desugarer__var__28__.
                                              rank) ==
                                     ((int) x10.
                                              array.
                                              PolyScanner.
                                              PointIt.this.
                                              out$.
                                              rank))) {
                    
//#line 293
throw new java.lang.ClassCastException("x10.array.Point{self.rank==x10.array.PolyScanner#this.rank}");
                }
                
//#line 293
return __desugarer__var__28__;
            }}
            public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Point._RTT;if (i ==1) return x10.array.Point._RTT;return null;
            }
            }.apply(((x10.
                      array.
                      Point)
                      x10.
                      array.
                      Point.$implicit_convert(((x10.core.Rail)(it.next())))));
        }
        
        
//#line 294
final public void
                       remove(
                       ){
            {
                
//#line 294
it.remove();
                
//#line 294
return;
            }
        }
    
    }
    
    
    
//#line 297
public x10.core.Iterator<x10.
                   array.
                   Point>
                   iterator(
                   ){
        
//#line 298
final x10.
          array.
          PolyScanner.
          PointIt it =
          ((x10.
          array.
          PolyScanner.
          PointIt)(new x10.
          array.
          PolyScanner.
          PointIt(this)));
        
//#line 299
it.
                       it.init();
        
//#line 300
return it;
    }
    
    
//#line 309
public void
                   printInfo(
                   final x10.
                     io.
                     Printer ps){
        
//#line 310
ps.println(((java.lang.Object)("PolyScanner")));
        
//#line 311
C.printInfo(((x10.
                                   io.
                                   Printer)(ps)),
                                 ((java.lang.String)("  C")));
    }
    
    
//#line 314
public void
                   printInfo2(
                   final x10.
                     io.
                     Printer ps){
        {
            
//#line 315
final x10.
              array.
              VarMat[] x10$array$PolyScanner$this$myMin$value1975 =
              ((x10.
              array.
              VarMat[])myMin.value);
            
//#line 315
final x10.
              array.
              VarMat[] x10$array$PolyScanner$this$minSum$value1976 =
              ((x10.
              array.
              VarMat[])minSum.value);
            
//#line 315
final x10.
              array.
              VarMat[] x10$array$PolyScanner$this$myMax$value1977 =
              ((x10.
              array.
              VarMat[])myMax.value);
            
//#line 315
final x10.
              array.
              VarMat[] x10$array$PolyScanner$this$maxSum$value1978 =
              ((x10.
              array.
              VarMat[])maxSum.value);
            
//#line 315
for (
//#line 315
int k =
                                0;
                              ((((int)(k))) < (((int)(myMin.
                                                        length))));
                              
//#line 315
k = ((((int)(k))) + (((int)(1))))) {
                
//#line 316
ps.println(((java.lang.Object)((("axis ") + (((java.lang.Integer)(k)))))));
                
//#line 317
ps.println(((java.lang.Object)("  min")));
                {
                    
//#line 318
for (
//#line 318
int l =
                                        0;
                                      ((((int)(l))) < (((int)(((x10.
                                                                array.
                                                                VarMat)((x10.
                                                                array.
                                                                VarMat[])myMin.value)[k]).
                                                                rows))));
                                      
//#line 318
l = ((((int)(l))) + (((int)(1))))) {
                        
//#line 319
ps.print(((java.lang.String)("  ")));
                        {
                            
//#line 320
for (
//#line 320
int m =
                                                0;
                                              ((((int)(m))) < (((int)(((x10.
                                                                        array.
                                                                        VarMat)((x10.
                                                                        array.
                                                                        VarMat[])myMin.value)[k]).apply$G((int)(l)).
                                                                        cols))));
                                              
//#line 320
m = ((((int)(m))) + (((int)(1))))) {
                                
//#line 321
ps.print(((java.lang.String)(((" ") + (((java.lang.Integer)(((x10.
                                                        array.
                                                        VarMat)x10$array$PolyScanner$this$myMin$value1975[k]).apply$G((int)(l)).apply((int)(m)))))))));
                            }
                        }
                        
//#line 322
ps.print(((java.lang.String)("  sum")));
                        {
                            
//#line 323
for (
//#line 323
int m =
                                                0;
                                              ((((int)(m))) < (((int)(((x10.
                                                                        array.
                                                                        VarMat)((x10.
                                                                        array.
                                                                        VarMat[])minSum.value)[k]).apply$G((int)(l)).
                                                                        cols))));
                                              
//#line 323
m = ((((int)(m))) + (((int)(1))))) {
                                
//#line 324
ps.print(((java.lang.String)(((" ") + (((java.lang.Integer)(((x10.
                                                        array.
                                                        VarMat)x10$array$PolyScanner$this$minSum$value1976[k]).apply$G((int)(l)).apply((int)(m)))))))));
                            }
                        }
                        
//#line 325
ps.print(((java.lang.String)("\n")));
                    }
                }
                
//#line 327
ps.printf(((java.lang.String)("  max\n")));
                {
                    
//#line 328
for (
//#line 328
int l =
                                        0;
                                      ((((int)(l))) < (((int)(((x10.
                                                                array.
                                                                VarMat)((x10.
                                                                array.
                                                                VarMat[])myMax.value)[k]).
                                                                rows))));
                                      
//#line 328
l = ((((int)(l))) + (((int)(1))))) {
                        
//#line 329
ps.print(((java.lang.String)("  ")));
                        {
                            
//#line 330
for (
//#line 330
int m =
                                                0;
                                              ((((int)(m))) < (((int)(((x10.
                                                                        array.
                                                                        VarMat)((x10.
                                                                        array.
                                                                        VarMat[])myMax.value)[k]).apply$G((int)(l)).
                                                                        cols))));
                                              
//#line 330
m = ((((int)(m))) + (((int)(1))))) {
                                
//#line 331
ps.print(((java.lang.String)(((" ") + (((java.lang.Integer)(((x10.
                                                        array.
                                                        VarMat)x10$array$PolyScanner$this$myMax$value1977[k]).apply$G((int)(l)).apply((int)(m)))))))));
                            }
                        }
                        
//#line 332
ps.print(((java.lang.String)("  sum")));
                        {
                            
//#line 333
for (
//#line 333
int m =
                                                0;
                                              ((((int)(m))) < (((int)(((x10.
                                                                        array.
                                                                        VarMat)((x10.
                                                                        array.
                                                                        VarMat[])maxSum.value)[k]).apply$G((int)(l)).
                                                                        cols))));
                                              
//#line 333
m = ((((int)(m))) + (((int)(1))))) {
                                
//#line 334
ps.print(((java.lang.String)(((" ") + (((java.lang.Integer)(((x10.
                                                        array.
                                                        VarMat)x10$array$PolyScanner$this$maxSum$value1978[k]).apply$G((int)(l)).apply((int)(m)))))))));
                            }
                        }
                        
//#line 335
ps.println();
                    }
                }
            }
        }
    }
    
    
//#line 68
final public int
                  rank(
                  ){
        
//#line 68
return this.
                             rank;
    }

}
