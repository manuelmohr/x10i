package x10.io;


public class Printer
extends x10.
  io.
  FilterWriter
{public static final x10.rtt.RuntimeType<Printer> _RTT = new x10.rtt.RuntimeType<Printer>(
/* base class */Printer.class
, /* parents */ new x10.rtt.Type[] {x10.io.FilterWriter._RTT}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
    
//#line 31
public Printer(final x10.
                                 io.
                                 Writer w) {
        
//#line 31
super(w);
    }
    
    
//#line 33
final public static char
      NEWLINE =
      '\n';
    
    
//#line 35
public void
                  println(
                  ){
        {
            
//#line 35
this.print((char)(x10.
                                     io.
                                     Printer.NEWLINE));
            
//#line 35
return;
        }
    }
    
    
//#line 37
final public void
                  println(
                  final java.lang.Object o){
        
//#line 38
this.print(((java.lang.String)(x10.rtt.Equality.equalsequals(o,null)
                                 ? "null\n"
                                 : ((((java.lang.Object)(o)).toString()) + ("\n")))));
    }
    
    
//#line 40
final public void
                  print(
                  final java.lang.Object o){
        
//#line 41
this.print(((java.lang.String)(x10.rtt.Equality.equalsequals(o,null)
                                 ? "null"
                                 : ((java.lang.Object)(o)).toString())));
    }
    
    
//#line 44
public void
                  print(
                  final java.lang.String s){
        
//#line 45
try {{
            
//#line 46
final x10.core.ValRail<java.lang.Byte> b =
              x10.core.RailFactory.<java.lang.Byte>makeValRailFromJavaArray(x10.rtt.Types.BYTE, (s).getBytes());
            
//#line 47
this.write(((x10.core.ValRail)(b)),
                                   (int)(0),
                                   (int)(b.
                                           length));
        }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
        if (__$generated_wrappedex$__.getCause() instanceof java.io.IOException) {
        final java.io.IOException e = (java.io.IOException) __$generated_wrappedex$__.getCause();
        {
            
//#line 50
throw new x10.
              io.
              IORuntimeException(e.getMessage());
        }
        }
        else {
        throw __$generated_wrappedex$__;
        }
        }catch (final java.io.IOException e) {
            
//#line 50
throw new x10.
              io.
              IORuntimeException(e.getMessage());
        }
    }
    
    
//#line 54
public void
                  printf(
                  final java.lang.String fmt){
        
//#line 54
this.printf(((java.lang.String)(fmt)),
                                ((x10.core.ValRail)(x10.core.RailFactory.<java.lang.Object>makeValRailFromJavaArray(x10.rtt.Types.runtimeType(java.lang.Object.class), new java.lang.Object[] {}))));
    }
    
    
//#line 55
public void
                  printf(
                  final java.lang.String fmt,
                  final java.lang.Object o1){
        
//#line 55
this.printf(((java.lang.String)(fmt)),
                                ((x10.core.ValRail)(x10.core.RailFactory.<java.lang.Object>makeValRailFromJavaArray(x10.rtt.Types.runtimeType(java.lang.Object.class), new java.lang.Object[] {o1}))));
    }
    
    
//#line 56
public void
                  printf(
                  final java.lang.String fmt,
                  final java.lang.Object o1,
                  final java.lang.Object o2){
        
//#line 56
this.printf(((java.lang.String)(fmt)),
                                ((x10.core.ValRail)(x10.core.RailFactory.<java.lang.Object>makeValRailFromJavaArray(x10.rtt.Types.runtimeType(java.lang.Object.class), new java.lang.Object[] {o1, o2}))));
    }
    
    
//#line 57
public void
                  printf(
                  final java.lang.String fmt,
                  final java.lang.Object o1,
                  final java.lang.Object o2,
                  final java.lang.Object o3){
        
//#line 57
this.printf(((java.lang.String)(fmt)),
                                ((x10.core.ValRail)(x10.core.RailFactory.<java.lang.Object>makeValRailFromJavaArray(x10.rtt.Types.runtimeType(java.lang.Object.class), new java.lang.Object[] {o1, o2, o3}))));
    }
    
    
//#line 58
public void
                  printf(
                  final java.lang.String fmt,
                  final java.lang.Object o1,
                  final java.lang.Object o2,
                  final java.lang.Object o3,
                  final java.lang.Object o4){
        
//#line 59
this.printf(((java.lang.String)(fmt)),
                                ((x10.core.ValRail)(x10.core.RailFactory.<java.lang.Object>makeValRailFromJavaArray(x10.rtt.Types.runtimeType(java.lang.Object.class), new java.lang.Object[] {o1, o2, o3, o4}))));
    }
    
    
//#line 61
public void
                  printf(
                  final java.lang.String fmt,
                  final java.lang.Object o1,
                  final java.lang.Object o2,
                  final java.lang.Object o3,
                  final java.lang.Object o4,
                  final java.lang.Object o5){
        
//#line 62
this.printf(((java.lang.String)(fmt)),
                                ((x10.core.ValRail)(x10.core.RailFactory.<java.lang.Object>makeValRailFromJavaArray(x10.rtt.Types.runtimeType(java.lang.Object.class), new java.lang.Object[] {o1, o2, o3, o4, o5}))));
    }
    
    
//#line 64
public void
                  printf(
                  final java.lang.String fmt,
                  final java.lang.Object o1,
                  final java.lang.Object o2,
                  final java.lang.Object o3,
                  final java.lang.Object o4,
                  final java.lang.Object o5,
                  final java.lang.Object o6){
        
//#line 65
this.printf(((java.lang.String)(fmt)),
                                ((x10.core.ValRail)(x10.core.RailFactory.<java.lang.Object>makeValRailFromJavaArray(x10.rtt.Types.runtimeType(java.lang.Object.class), new java.lang.Object[] {o1, o2, o3, o4, o5, o6}))));
    }
    
    
//#line 67
public void
                  printf(
                  final java.lang.String fmt,
                  final x10.core.Rail<java.lang.Object> args){
        
//#line 67
this.print(((java.lang.String)(java.lang.String.format(fmt,(x10.core.RailFactory.<java.lang.Object>makeValRailFromRail(x10.rtt.Types.runtimeType(java.lang.Object.class), args)).getBoxedArray()))));
    }
    
    
//#line 68
public void
                  printf(
                  final java.lang.String fmt,
                  final x10.core.ValRail<java.lang.Object> args){
        
//#line 68
this.print(((java.lang.String)(java.lang.String.format(fmt,(args).getBoxedArray()))));
    }
    
    
//#line 70
public void
                  flush(
                  ){
        
//#line 71
try {{
            
//#line 72
super.flush();
        }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
        if (__$generated_wrappedex$__.getCause() instanceof java.io.IOException) {
        final java.io.IOException id$87 = (java.io.IOException) __$generated_wrappedex$__.getCause();
        {
            
        }
        }
        else {
        throw __$generated_wrappedex$__;
        }
        }catch (final java.io.IOException id$87) {
            
        }
    }
    
    
//#line 77
public void
                  close(
                  ){
        
//#line 78
try {{
            
//#line 79
super.close();
        }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
        if (__$generated_wrappedex$__.getCause() instanceof java.io.IOException) {
        final java.io.IOException id$88 = (java.io.IOException) __$generated_wrappedex$__.getCause();
        {
            
        }
        }
        else {
        throw __$generated_wrappedex$__;
        }
        }catch (final java.io.IOException id$88) {
            
        }
    }
    
    final public void
      x10$io$Printer$flush$S(
      )
          throws java.io.IOException{
        super.flush();
    }
    
    final public void
      x10$io$Printer$close$S(
      )
          throws java.io.IOException{
        super.close();
    }

}
