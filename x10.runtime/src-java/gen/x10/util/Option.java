package x10.util;

public class Option
extends x10.core.Struct
{public static final x10.rtt.RuntimeType<Option> _RTT = new x10.rtt.RuntimeType<Option>(
/* base class */Option.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 19
final public java.lang.String
      short_;
    
//#line 20
final public java.lang.String
      long_;
    
//#line 21
final public java.lang.String
      description;
    
    
//#line 22
public Option(final java.lang.String s,
                              final java.lang.String l,
                              final java.lang.String d) {
        
//#line 23
this.short_ = (("-") + (s));
        
//#line 23
this.long_ = (("--") + (l));
        
//#line 23
this.description = d;
    }
    
    
//#line 25
final public java.lang.String
                  toString(
                  ){
        
//#line 25
return description;
    }
    
    
//#line 18
final native public x10.
                  lang.
                  Place
                  home(
                  );
    
    
//#line 18
final native public java.lang.String
                  typeName(
                  );
    
    
//#line 18
final native public boolean
                  at(
                  x10.
                    lang.
                    Place p);
    
    
//#line 18
final native public boolean
                  at(
                  java.lang.Object r);
    
    
//#line 18
final public int
                  hashCode(
                  ){
        
//#line 18
int result =
          0;
        
//#line 18
result = ((((int)(((((int)(31))) * (((int)(result))))))) + (((int)((this.
                                                                                          short_).hashCode()))));
        
//#line 18
result = ((((int)(((((int)(31))) * (((int)(result))))))) + (((int)((this.
                                                                                          long_).hashCode()))));
        
//#line 18
result = ((((int)(((((int)(31))) * (((int)(result))))))) + (((int)((this.
                                                                                          description).hashCode()))));
        
//#line 18
return result;
    }
    
    
//#line 18
final public boolean
                  equals(
                  java.lang.Object other){
        
//#line 18
if ((!(((boolean)(x10.util.Option._RTT.instanceof$(other)))))) {
            
//#line 18
return false;
        }
        
//#line 18
return this.equals(((x10.
                                         util.
                                         Option)((new java.lang.Object() {final x10.
                                         util.
                                         Option cast(final x10.
                                         util.
                                         Option self) {if (self==null) return null;x10.rtt.Type rtt = x10.util.Option._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                         util.
                                         Option) other)))));
    }
    
    
//#line 18
final public boolean
                  equals(
                  x10.
                    util.
                    Option other){
        
//#line 18
return x10.rtt.Equality.equalsequals(this.
                                                           short_,other.
                                                                    short_) &&
        x10.rtt.Equality.equalsequals(this.
                                        long_,other.
                                                long_) &&
        x10.rtt.Equality.equalsequals(this.
                                        description,other.
                                                      description);
    }
    
    
//#line 18
final public boolean
                  _struct_equals(
                  java.lang.Object other){
        
//#line 18
if ((!(((boolean)(x10.util.Option._RTT.instanceof$(other)))))) {
            
//#line 18
return false;
        }
        
//#line 18
return this._struct_equals(((x10.
                                                 util.
                                                 Option)((new java.lang.Object() {final x10.
                                                 util.
                                                 Option cast(final x10.
                                                 util.
                                                 Option self) {if (self==null) return null;x10.rtt.Type rtt = x10.util.Option._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                                 util.
                                                 Option) other)))));
    }
    
    
//#line 18
final public boolean
                  _struct_equals(
                  x10.
                    util.
                    Option other){
        
//#line 18
return x10.rtt.Equality.equalsequals(this.
                                                           short_,other.
                                                                    short_) &&
        x10.rtt.Equality.equalsequals(this.
                                        long_,other.
                                                long_) &&
        x10.rtt.Equality.equalsequals(this.
                                        description,other.
                                                      description);
    }

}
