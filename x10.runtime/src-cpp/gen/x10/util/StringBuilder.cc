#include <x10/util/StringBuilder.h>


#include "x10/util/StringBuilder.inc"

x10::util::Builder<x10aux::ref<x10::lang::Object>, x10aux::ref<x10::lang::String> >::itable<x10::util::StringBuilder >  x10::util::StringBuilder::_itable_0(&x10::util::StringBuilder::add, &x10::util::StringBuilder::at, &x10::util::StringBuilder::at, &x10::util::StringBuilder::equals, &x10::util::StringBuilder::hashCode, &x10::util::StringBuilder::home, &x10::util::StringBuilder::result, &x10::util::StringBuilder::toString, &x10::util::StringBuilder::typeName);
x10::lang::Any::itable<x10::util::StringBuilder >  x10::util::StringBuilder::_itable_1(&x10::util::StringBuilder::at, &x10::util::StringBuilder::at, &x10::util::StringBuilder::equals, &x10::util::StringBuilder::hashCode, &x10::util::StringBuilder::home, &x10::util::StringBuilder::toString, &x10::util::StringBuilder::typeName);
x10aux::itable_entry x10::util::StringBuilder::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::util::Builder<x10aux::ref<x10::lang::Object>, x10aux::ref<x10::lang::String> > >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::util::StringBuilder>())};
void x10::util::StringBuilder::_instance_init() {
    _I_("Doing initialisation for class: x10::util::StringBuilder");
    
}


//#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10FieldDecl_c

//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10ConstructorDecl_c
void x10::util::StringBuilder::_constructor() {
    this->x10::lang::Object::_constructor();
    
    //#line 20 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::StringBuilder>)this))->FMGL(buf) =
      x10::util::ValRailBuilder<x10_char>::_make();
    
}
x10aux::ref<x10::util::StringBuilder> x10::util::StringBuilder::_make(
  ) {
    x10aux::ref<x10::util::StringBuilder> this_ = new (memset(x10aux::alloc<x10::util::StringBuilder>(), 0, sizeof(x10::util::StringBuilder))) x10::util::StringBuilder();
    this_->_constructor();
    return this_;
}



//#line 31 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::String> x10::util::StringBuilder::toString(
  ) {
    
    //#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10If_c
    if ((!((x10aux::get_location(((x10aux::ref<x10::util::StringBuilder>)this)) == (x10::lang::Place_methods::_make(x10aux::here))->FMGL(id)))))
    {
        
        //#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::lang::UnsupportedOperationException::_make()));
    }
    
    //#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((__extension__ ({
                                  x10aux::ref<x10::util::StringBuilder> __desugarer__var__79__ =
                                    ((x10aux::ref<x10::util::StringBuilder>)this);
                                  
                                  //#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10LocalDecl_c
                                  x10aux::ref<x10::util::StringBuilder> __var1241__;
                                  
                                  //#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": polyglot.ast.Labeled_c
                                  goto __ret2008; __ret2008: 
                                  //#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Do_c
                                  do
                                  {
                                  {
                                      
                                      //#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10If_c
                                      if ((!x10aux::struct_equals(__desugarer__var__79__,
                                                                  x10aux::null)) &&
                                          !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__79__)->location),
                                                                   x10::lang::Place_methods::_make(x10aux::here)))))
                                      {
                                          
                                          //#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": polyglot.ast.Throw_c
                                          x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.util.StringBuilder{self.home==here}"))));
                                      }
                                      
                                      //#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": polyglot.ast.Eval_c
                                      __var1241__ =
                                        __desugarer__var__79__;
                                      
                                      //#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": polyglot.ast.Branch_c
                                      goto __ret2008_end_;
                                  }
                                  goto __ret2008_next_; __ret2008_next_: ;
                                  }
                                  while (false);
                                  goto __ret2008_end_; __ret2008_end_: ;
                                  __var1241__;
                              }))
                              ))->result();
    
}

//#line 36 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::util::Builder<x10aux::ref<x10::lang::Object>, x10aux::ref<x10::lang::String> > >
  x10::util::StringBuilder::add(
  x10aux::ref<x10::lang::Object> o) {
    
    //#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(o, x10aux::null)))
    {
        
        //#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
        return ((x10aux::ref<x10::util::StringBuilder>)this)->addString(
                 x10::lang::String::Lit("null"));
        
    }
    else
    {
        
        //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
        return ((x10aux::ref<x10::util::StringBuilder>)this)->addString(
                 x10aux::to_string((__extension__ ({
                     x10aux::ref<x10::lang::Object> __desugarer__var__80__ =
                       o;
                     
                     //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10LocalDecl_c
                     x10aux::ref<x10::lang::Object> __var1243__;
                     
                     //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": polyglot.ast.Labeled_c
                     goto __ret2009; __ret2009: 
                     //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Do_c
                     do
                     {
                     {
                         
                         //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10If_c
                         if ((!x10aux::struct_equals(__desugarer__var__80__,
                                                     x10aux::null)) &&
                             !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__80__)->location),
                                                      x10::lang::Place_methods::_make(x10aux::here)))))
                         {
                             
                             //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": polyglot.ast.Throw_c
                             x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Object{self.home==here}"))));
                         }
                         
                         //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": polyglot.ast.Eval_c
                         __var1243__ =
                           __desugarer__var__80__;
                         
                         //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": polyglot.ast.Branch_c
                         goto __ret2009_end_;
                     }
                     goto __ret2009_next_; __ret2009_next_: ;
                     }
                     while (false);
                     goto __ret2009_end_; __ret2009_end_: ;
                     __var1243__;
                 }))
                 ));
        
    }
    
}

//#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::util::StringBuilder> x10::util::StringBuilder::insert(
  x10_int p,
  x10aux::ref<x10::lang::Object> o) {
    
    //#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(o, x10aux::null)))
    {
        
        //#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
        return ((x10aux::ref<x10::util::StringBuilder>)this)->insertString(
                 p,
                 x10::lang::String::Lit("null"));
        
    }
    else
    {
        
        //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
        return ((x10aux::ref<x10::util::StringBuilder>)this)->insertString(
                 p,
                 x10aux::to_string((__extension__ ({
                     x10aux::ref<x10::lang::Object> __desugarer__var__81__ =
                       o;
                     
                     //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10LocalDecl_c
                     x10aux::ref<x10::lang::Object> __var1245__;
                     
                     //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": polyglot.ast.Labeled_c
                     goto __ret2010; __ret2010: 
                     //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Do_c
                     do
                     {
                     {
                         
                         //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10If_c
                         if ((!x10aux::struct_equals(__desugarer__var__81__,
                                                     x10aux::null)) &&
                             !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__81__)->location),
                                                      x10::lang::Place_methods::_make(x10aux::here)))))
                         {
                             
                             //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": polyglot.ast.Throw_c
                             x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Object{self.home==here}"))));
                         }
                         
                         //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": polyglot.ast.Eval_c
                         __var1245__ =
                           __desugarer__var__81__;
                         
                         //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": polyglot.ast.Branch_c
                         goto __ret2010_end_;
                     }
                     goto __ret2010_next_; __ret2010_next_: ;
                     }
                     while (false);
                     goto __ret2010_end_; __ret2010_end_: ;
                     __var1245__;
                 }))
                 ));
        
    }
    
}

//#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::util::StringBuilder> x10::util::StringBuilder::add(
  x10_char x) {
    
    //#line 51 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": polyglot.ast.Eval_c
    static_cast<x10aux::ref<x10::util::ValRailBuilder<x10_char> > >(x10aux::nullCheck(((x10aux::ref<x10::util::StringBuilder>)this)->
                                                                                        FMGL(buf))->add(
                                                                      x));
    
    //#line 52 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::StringBuilder>)this);
    
}

//#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::util::StringBuilder> x10::util::StringBuilder::add(
  x10_boolean x) {
    
    //#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::StringBuilder>)this)->addString(
             x10aux::to_string(x));
    
}

//#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::util::StringBuilder> x10::util::StringBuilder::add(
  x10_byte x) {
    
    //#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::StringBuilder>)this)->addString(
             x10aux::to_string(x));
    
}

//#line 57 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::util::StringBuilder> x10::util::StringBuilder::add(
  x10_short x) {
    
    //#line 57 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::StringBuilder>)this)->addString(
             x10aux::to_string(x));
    
}

//#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::util::StringBuilder> x10::util::StringBuilder::add(
  x10_int x) {
    
    //#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::StringBuilder>)this)->addString(
             x10aux::to_string(x));
    
}

//#line 59 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::util::StringBuilder> x10::util::StringBuilder::add(
  x10_long x) {
    
    //#line 59 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::StringBuilder>)this)->addString(
             x10aux::to_string(x));
    
}

//#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::util::StringBuilder> x10::util::StringBuilder::add(
  x10_float x) {
    
    //#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::StringBuilder>)this)->addString(
             x10aux::to_string(x));
    
}

//#line 61 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::util::StringBuilder> x10::util::StringBuilder::add(
  x10_double x) {
    
    //#line 61 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::StringBuilder>)this)->addString(
             x10aux::to_string(x));
    
}

//#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::util::Builder<x10aux::ref<x10::lang::Object>, x10aux::ref<x10::lang::String> > >
  x10::util::StringBuilder::add(
  x10aux::ref<x10::lang::String> x) {
    
    //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::StringBuilder>)this)->addString(
             x);
    
}

//#line 64 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::util::StringBuilder> x10::util::StringBuilder::insert(
  x10_int p,
  x10_boolean x) {
    
    //#line 64 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::StringBuilder>)this)->insertString(
             p,
             x10aux::to_string(x));
    
}

//#line 65 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::util::StringBuilder> x10::util::StringBuilder::insert(
  x10_int p,
  x10_byte x) {
    
    //#line 65 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::StringBuilder>)this)->insertString(
             p,
             x10aux::to_string(x));
    
}

//#line 66 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::util::StringBuilder> x10::util::StringBuilder::insert(
  x10_int p,
  x10_char x) {
    
    //#line 66 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::StringBuilder>)this)->insertString(
             p,
             x10aux::to_string(x));
    
}

//#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::util::StringBuilder> x10::util::StringBuilder::insert(
  x10_int p,
  x10_short x) {
    
    //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::StringBuilder>)this)->insertString(
             p,
             x10aux::to_string(x));
    
}

//#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::util::StringBuilder> x10::util::StringBuilder::insert(
  x10_int p,
  x10_int x) {
    
    //#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::StringBuilder>)this)->insertString(
             p,
             x10aux::to_string(x));
    
}

//#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::util::StringBuilder> x10::util::StringBuilder::insert(
  x10_int p,
  x10_long x) {
    
    //#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::StringBuilder>)this)->insertString(
             p,
             x10aux::to_string(x));
    
}

//#line 70 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::util::StringBuilder> x10::util::StringBuilder::insert(
  x10_int p,
  x10_float x) {
    
    //#line 70 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::StringBuilder>)this)->insertString(
             p,
             x10aux::to_string(x));
    
}

//#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::util::StringBuilder> x10::util::StringBuilder::insert(
  x10_int p,
  x10_double x) {
    
    //#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::StringBuilder>)this)->insertString(
             p,
             x10aux::to_string(x));
    
}

//#line 72 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::util::StringBuilder> x10::util::StringBuilder::insert(
  x10_int p,
  x10aux::ref<x10::lang::String> x) {
    
    //#line 72 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::StringBuilder>)this)->insertString(
             p,
             x);
    
}

//#line 74 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::util::StringBuilder> x10::util::StringBuilder::addString(
  x10aux::ref<x10::lang::String> s) {
    
    //#line 75 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 75 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < ((s)->length()));
             
             //#line 75 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 76 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10LocalDecl_c
            x10_char ch =
              (s)->charAt(i);
            
            //#line 77 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": polyglot.ast.Eval_c
            static_cast<x10aux::ref<x10::util::ValRailBuilder<x10_char> > >(x10aux::nullCheck(((x10aux::ref<x10::util::StringBuilder>)this)->
                                                                                                FMGL(buf))->add(
                                                                              ch));
        }
    }
    
    //#line 85 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::StringBuilder>)this);
    
}

//#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::util::StringBuilder> x10::util::StringBuilder::insertString(
  x10_int pos,
  x10aux::ref<x10::lang::String> s) {
    
    //#line 89 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10LocalDecl_c
    x10_int loc = pos;
    
    //#line 90 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals((s)->length(),
                               ((x10_int)0))))
    {
        
        //#line 91 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
        return ((x10aux::ref<x10::util::StringBuilder>)this);
        
    }
    
    //#line 93 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10If_c
    if (((loc) > (x10aux::nullCheck(((x10aux::ref<x10::util::StringBuilder>)this)->
                                      FMGL(buf))->length())))
    {
        
        //#line 94 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
        return ((x10aux::ref<x10::util::StringBuilder>)this)->addString(
                 s);
        
    }
    
    //#line 97 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10If_c
    if (((loc) < (((x10_int)0)))) {
        
        //#line 98 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": polyglot.ast.Eval_c
        loc = ((x10_int)0);
    }
    
    //#line 99 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::util::StringBuilder>)this)->
                        FMGL(buf))->insert(
      loc,
      (s)->chars());
    
    //#line 100 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::StringBuilder>)this);
    
}

//#line 103 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10_int x10::util::StringBuilder::length(
  ) {
    
    //#line 104 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::util::StringBuilder>)this)->
                               FMGL(buf))->length();
    
}

//#line 107 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c

//#line 111 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::String> x10::util::StringBuilder::result(
  ) {
    
    //#line 111 "/home/tux/workspace/x10.runtime/src-x10/x10/util/StringBuilder.x10": x10.ast.X10Return_c
    return x10aux::vrc_to_string(x10aux::nullCheck(((x10aux::ref<x10::util::StringBuilder>)this)->
                                                     FMGL(buf))->result());
    
}
const x10aux::serialization_id_t x10::util::StringBuilder::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::util::StringBuilder::_deserializer<x10::lang::Object>);

void x10::util::StringBuilder::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::util::StringBuilder::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::util::StringBuilder::rtt;
void x10::util::StringBuilder::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::util::Builder<x10aux::ref<x10::lang::Object>, x10aux::ref<x10::lang::String> > >()};
    rtt.initStageTwo("x10.util.StringBuilder", 2, parents, 0, NULL, NULL);
}
