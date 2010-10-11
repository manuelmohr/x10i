package x10.util;


final public class OptionsParser
extends x10.core.Ref
{public static final x10.rtt.RuntimeType<OptionsParser> _RTT = new x10.rtt.RuntimeType<OptionsParser>(
/* base class */OptionsParser.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 22
final public static class Err
                extends java.lang.Exception
                {public static final x10.rtt.RuntimeType<Err> _RTT = new x10.rtt.RuntimeType<Err>(
    /* base class */Err.class
    , /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Exception.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    
        
//#line 23
final public java.lang.String
          msg;
        
        
//#line 24
public Err(final java.lang.String m) {
            super();
            
//#line 24
this.msg = m;
        }
        
        
//#line 25
public java.lang.String
                      toString(
                      ){
            
//#line 25
return (("Commandline error: ") + (msg));
        }
    
    }
    
    
//#line 28
final public x10.
      util.
      HashMap<java.lang.String, java.lang.String>
      map;
    
//#line 29
final public x10.
      util.
      HashMap<java.lang.String, java.lang.Boolean>
      set;
    
//#line 30
final public x10.core.GrowableRail<java.lang.String>
      filteredArgs;
    
    
//#line 32
public OptionsParser(final x10.core.Rail<java.lang.String> args,
                                     final x10.core.ValRail<x10.
                                       util.
                                       Option> flags,
                                     final x10.core.ValRail<x10.
                                       util.
                                       Option> specs)
                      throws x10.
                  util.
                  OptionsParser.
                  Err {
        super();
        
//#line 33
final x10.
          util.
          HashMap<java.lang.String, java.lang.String> map =
          ((x10.
          util.
          HashMap)(new x10.
          util.
          HashMap<java.lang.String, java.lang.String>(x10.rtt.Types.STR,
                                                      x10.rtt.Types.STR)));
        
//#line 34
final x10.
          util.
          HashMap<java.lang.String, java.lang.Boolean> set =
          ((x10.
          util.
          HashMap)(new x10.
          util.
          HashMap<java.lang.String, java.lang.Boolean>(x10.rtt.Types.STR,
                                                       x10.rtt.Types.BOOLEAN)));
        
//#line 35
final x10.core.GrowableRail<java.lang.String> filteredArgs =
          ((x10.core.GrowableRail)(new x10.core.GrowableRail<java.lang.String>(x10.rtt.Types.STR)));
        
//#line 36
int offset =
          0;
        
//#line 37
boolean ended =
          false;
        {
            
//#line 38
final java.lang.String[] args$value2087 =
              ((java.lang.String[])args.value);
            
//#line 38
for (
//#line 38
int i =
                               0;
                             ((((int)(i))) < (((int)(args.
                                                       length))));
                             
//#line 38
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 39
final java.lang.String s =
                  ((java.lang.String)args$value2087[i]);
                
//#line 40
boolean recognised =
                  false;
                
//#line 41
if ((s).equals("--")) {
                    
//#line 42
ended = true;
                    
//#line 43
continue;
                }
                
//#line 45
if ((!(((boolean)(ended))))) {
                    
//#line 46
if ((!x10.rtt.Equality.equalsequals(flags,null))) {
                        
//#line 46
for (
//#line 46
final x10.core.Iterator<x10.
                                           util.
                                           Option> flag1849 =
                                           (flags).iterator();
                                         flag1849.hasNext();
                                         ) {
                            
//#line 46
final x10.
                              util.
                              Option flag =
                              flag1849.next$G();
                            
//#line 47
if (recognised) {
                                
//#line 47
break;
                            }
                            
//#line 48
if ((s).equals(flag.
                                                         short_) ||
                                            (s).equals(flag.
                                                         long_)) {
                                
//#line 49
if ((!x10.rtt.Equality.equalsequals(flag.
                                                                                  short_,null))) {
                                    
//#line 49
set.put(((java.lang.String)(flag.
                                                                              short_)),
                                                        (java.lang.Boolean)(true));
                                }
                                
//#line 50
if ((!x10.rtt.Equality.equalsequals(flag.
                                                                                  long_,null))) {
                                    
//#line 50
set.put(((java.lang.String)(flag.
                                                                              long_)),
                                                        (java.lang.Boolean)(true));
                                }
                                
//#line 51
recognised = true;
                            }
                        }
                    }
                    
//#line 54
if ((!x10.rtt.Equality.equalsequals(specs,null))) {
                        {
                            
//#line 54
for (
//#line 54
final x10.core.Iterator<x10.
                                               util.
                                               Option> spec1850 =
                                               (specs).iterator();
                                             spec1850.hasNext();
                                             ) {
                                
//#line 54
final x10.
                                  util.
                                  Option spec =
                                  spec1850.next$G();
                                
//#line 55
if (recognised) {
                                    
//#line 55
break;
                                }
                                
//#line 56
if ((s).equals(spec.
                                                             short_) ||
                                                (s).equals(spec.
                                                             long_)) {
                                    
//#line 57
recognised = true;
                                    
//#line 58
i = ((((int)(i))) + (((int)(1))));
                                    
//#line 59
if (((((int)(i))) >= (((int)(args.
                                                                               length))))) {
                                        
//#line 59
throw new x10.
                                          util.
                                          OptionsParser.
                                          Err((((("Expected another arg after: \"") + (s))) + ("\"")));
                                    }
                                    
//#line 60
final java.lang.String s2 =
                                      ((java.lang.String)args$value2087[i]);
                                    
//#line 61
if ((!x10.rtt.Equality.equalsequals(spec.
                                                                                      short_,null))) {
                                        
//#line 61
map.put(((java.lang.String)(spec.
                                                                                  short_)),
                                                            ((java.lang.String)(s2)));
                                    }
                                    
//#line 62
if ((!x10.rtt.Equality.equalsequals(spec.
                                                                                      long_,null))) {
                                        
//#line 62
map.put(((java.lang.String)(spec.
                                                                                  long_)),
                                                            ((java.lang.String)(s2)));
                                    }
                                }
                            }
                        }
                    }
                }
                
//#line 66
if ((!(((boolean)(recognised))))) {
                    
//#line 66
(filteredArgs).add(s);
                }
            }
        }
        
//#line 68
this.map = ((x10.
          util.
          HashMap)(map));
        
//#line 69
this.set = ((x10.
          util.
          HashMap)(set));
        
//#line 70
this.filteredArgs = ((x10.core.GrowableRail)(filteredArgs));
    }
    
    
//#line 73
public x10.core.Rail<java.lang.String>
                  filteredArgs(
                  ){
        
//#line 73
return (filteredArgs).toRail();
    }
    
    
//#line 75
public boolean
                  apply(
                  final java.lang.String key){
        
//#line 75
return set.containsKey(((java.lang.String)(key))) ||
        map.containsKey(((java.lang.String)(key)));
    }
    
    
//#line 77
public java.lang.String
                  apply(
                  final java.lang.String key,
                  final java.lang.String d){
        
//#line 77
return map.getOrElse$G(((java.lang.String)(key)),
                                           ((java.lang.String)(d)));
    }
    
    
//#line 89
public byte
                  apply(
                  final java.lang.String key,
                  final byte d)
                      throws x10.
                  util.
                  OptionsParser.
                  Err{
        
//#line 90
if ((!(((boolean)(map.containsKey(((java.lang.String)(key)))))))) {
            
//#line 90
return d;
        }
        
//#line 91
final java.lang.String v =
          map.getOrElse$G(((java.lang.String)(key)),
                          ((java.lang.String)("???")));
        
//#line 92
try {{
            
//#line 93
return java.lang.Byte.parseByte(v);
        }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
        if (__$generated_wrappedex$__.getCause() instanceof java.lang.NumberFormatException) {
        final java.lang.NumberFormatException e = (java.lang.NumberFormatException) __$generated_wrappedex$__.getCause();
        {
            
//#line 95
throw new x10.
              util.
              OptionsParser.
              Err((((("Expected Byte, got: \"") + (v))) + ("\"")));
        }
        }
        else {
        throw __$generated_wrappedex$__;
        }
        }catch (final java.lang.NumberFormatException e) {
            
//#line 95
throw new x10.
              util.
              OptionsParser.
              Err((((("Expected Byte, got: \"") + (v))) + ("\"")));
        }
    }
    
    
//#line 109
public short
                   apply(
                   final java.lang.String key,
                   final short d)
                       throws x10.
                   util.
                   OptionsParser.
                   Err{
        
//#line 110
if ((!(((boolean)(map.containsKey(((java.lang.String)(key)))))))) {
            
//#line 110
return d;
        }
        
//#line 111
final java.lang.String v =
          map.getOrElse$G(((java.lang.String)(key)),
                          ((java.lang.String)("???")));
        
//#line 112
try {{
            
//#line 113
return java.lang.Short.parseShort(v);
        }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
        if (__$generated_wrappedex$__.getCause() instanceof java.lang.NumberFormatException) {
        final java.lang.NumberFormatException e = (java.lang.NumberFormatException) __$generated_wrappedex$__.getCause();
        {
            
//#line 115
throw new x10.
              util.
              OptionsParser.
              Err((((("Expected Short, got: \"") + (v))) + ("\"")));
        }
        }
        else {
        throw __$generated_wrappedex$__;
        }
        }catch (final java.lang.NumberFormatException e) {
            
//#line 115
throw new x10.
              util.
              OptionsParser.
              Err((((("Expected Short, got: \"") + (v))) + ("\"")));
        }
    }
    
    
//#line 129
public int
                   apply(
                   final java.lang.String key,
                   final int d)
                       throws x10.
                   util.
                   OptionsParser.
                   Err{
        
//#line 130
if ((!(((boolean)(map.containsKey(((java.lang.String)(key)))))))) {
            
//#line 130
return d;
        }
        
//#line 131
final java.lang.String v =
          map.getOrElse$G(((java.lang.String)(key)),
                          ((java.lang.String)("???")));
        
//#line 132
try {{
            
//#line 133
return java.lang.Integer.parseInt(v);
        }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
        if (__$generated_wrappedex$__.getCause() instanceof java.lang.NumberFormatException) {
        final java.lang.NumberFormatException e = (java.lang.NumberFormatException) __$generated_wrappedex$__.getCause();
        {
            
//#line 135
throw new x10.
              util.
              OptionsParser.
              Err((((("Expected Long, got: \"") + (v))) + ("\"")));
        }
        }
        else {
        throw __$generated_wrappedex$__;
        }
        }catch (final java.lang.NumberFormatException e) {
            
//#line 135
throw new x10.
              util.
              OptionsParser.
              Err((((("Expected Long, got: \"") + (v))) + ("\"")));
        }
    }
    
    
//#line 149
public long
                   apply(
                   final java.lang.String key,
                   final long d)
                       throws x10.
                   util.
                   OptionsParser.
                   Err{
        
//#line 150
if ((!(((boolean)(map.containsKey(((java.lang.String)(key)))))))) {
            
//#line 150
return d;
        }
        
//#line 151
final java.lang.String v =
          map.getOrElse$G(((java.lang.String)(key)),
                          ((java.lang.String)("???")));
        
//#line 152
try {{
            
//#line 153
return java.lang.Long.parseLong(v);
        }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
        if (__$generated_wrappedex$__.getCause() instanceof java.lang.NumberFormatException) {
        final java.lang.NumberFormatException e = (java.lang.NumberFormatException) __$generated_wrappedex$__.getCause();
        {
            
//#line 155
throw new x10.
              util.
              OptionsParser.
              Err((((("Expected Int, got: \"") + (v))) + ("\"")));
        }
        }
        else {
        throw __$generated_wrappedex$__;
        }
        }catch (final java.lang.NumberFormatException e) {
            
//#line 155
throw new x10.
              util.
              OptionsParser.
              Err((((("Expected Int, got: \"") + (v))) + ("\"")));
        }
    }
    
    
//#line 160
public double
                   apply(
                   final java.lang.String key,
                   final double d)
                       throws x10.
                   util.
                   OptionsParser.
                   Err{
        
//#line 161
if ((!(((boolean)(map.containsKey(((java.lang.String)(key)))))))) {
            
//#line 161
return d;
        }
        
//#line 162
final java.lang.String v =
          map.getOrElse$G(((java.lang.String)(key)),
                          ((java.lang.String)("???")));
        
//#line 163
try {{
            
//#line 164
return java.lang.Double.parseDouble(v);
        }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
        if (__$generated_wrappedex$__.getCause() instanceof java.lang.NumberFormatException) {
        final java.lang.NumberFormatException e = (java.lang.NumberFormatException) __$generated_wrappedex$__.getCause();
        {
            
//#line 166
throw new x10.
              util.
              OptionsParser.
              Err((((("Expected Double, got: \"") + (v))) + ("\"")));
        }
        }
        else {
        throw __$generated_wrappedex$__;
        }
        }catch (final java.lang.NumberFormatException e) {
            
//#line 166
throw new x10.
              util.
              OptionsParser.
              Err((((("Expected Double, got: \"") + (v))) + ("\"")));
        }
    }
    
    
//#line 169
public float
                   apply(
                   final java.lang.String key,
                   final float d)
                       throws x10.
                   util.
                   OptionsParser.
                   Err{
        
//#line 170
if ((!(((boolean)(map.containsKey(((java.lang.String)(key)))))))) {
            
//#line 170
return d;
        }
        
//#line 171
final java.lang.String v =
          map.getOrElse$G(((java.lang.String)(key)),
                          ((java.lang.String)("???")));
        
//#line 172
try {{
            
//#line 173
return java.lang.Float.parseFloat(v);
        }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
        if (__$generated_wrappedex$__.getCause() instanceof java.lang.NumberFormatException) {
        final java.lang.NumberFormatException e = (java.lang.NumberFormatException) __$generated_wrappedex$__.getCause();
        {
            
//#line 175
throw new x10.
              util.
              OptionsParser.
              Err((((("Expected Float, got: \"") + (v))) + ("\"")));
        }
        }
        else {
        throw __$generated_wrappedex$__;
        }
        }catch (final java.lang.NumberFormatException e) {
            
//#line 175
throw new x10.
              util.
              OptionsParser.
              Err((((("Expected Float, got: \"") + (v))) + ("\"")));
        }
    }

}
