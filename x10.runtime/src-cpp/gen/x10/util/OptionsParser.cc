#include <x10/util/OptionsParser.h>


#include "x10/util/OptionsParser.inc"

void x10::util::OptionsParser::_instance_init() {
    _I_("Doing initialisation for class: x10::util::OptionsParser");
    
}


//#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10FieldDecl_c

//#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10FieldDecl_c

//#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10FieldDecl_c

//#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10ConstructorDecl_c
void x10::util::OptionsParser::_constructor(x10aux::ref<x10::lang::Rail<x10aux::ref<x10::lang::String> > > args,
                                            x10aux::ref<x10::lang::ValRail<x10::util::Option > > flags,
                                            x10aux::ref<x10::lang::ValRail<x10::util::Option > > specs)
{
    this->x10::lang::Object::_constructor();
    
    //#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::HashMap<x10aux::ref<x10::lang::String>, x10aux::ref<x10::lang::String> > > map =
      x10::util::HashMap<x10aux::ref<x10::lang::String>, x10aux::ref<x10::lang::String> >::_make();
    
    //#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::HashMap<x10aux::ref<x10::lang::String>, x10_boolean> > set =
      x10::util::HashMap<x10aux::ref<x10::lang::String>, x10_boolean>::_make();
    
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::GrowableRail<x10aux::ref<x10::lang::String> > > filteredArgs =
      x10::util::GrowableRail<x10aux::ref<x10::lang::String> >::_make();
    
    //#line 36 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10LocalDecl_c
    x10_int offset =
      ((x10_int)0);
    
    //#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10LocalDecl_c
    x10_boolean ended =
      false;
    
    //#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10LocalDecl_c
             i =
               ((x10_int)0);
             ((i) < (x10aux::nullCheck(args)->
                       FMGL(length)));
             
             //#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::lang::String> s =
              (args)->apply(i);
            
            //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10LocalDecl_c
            x10_boolean recognised =
              false;
            
            //#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10If_c
            if (x10aux::equals(s,x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Any> >(x10::lang::String::Lit("--"))))
            {
                
                //#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Eval_c
                ended =
                  true;
                
                //#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Branch_c
                continue;
            }
            
            //#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10If_c
            if ((!(ended)))
            {
                
                //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10If_c
                if ((!x10aux::struct_equals(flags,
                                            x10aux::null)))
                {
                    
                    //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.For_c
                    {
                        x10aux::ref<x10::lang::Iterator<x10::util::Option> > flag1841;
                        for (
                             //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10LocalDecl_c
                             flag1841 =
                               (flags)->iterator();
                             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(flag1841))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10::util::Option> >(((x10aux::ref<x10::lang::Reference>)flag1841)->_getITables())->hasNext))();
                             )
                        {
                            
                            //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10LocalDecl_c
                            x10::util::Option flag =
                              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(flag1841))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10::util::Option> >(((x10aux::ref<x10::lang::Reference>)flag1841)->_getITables())->next))();
                            
                            //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10If_c
                            if (recognised)
                            {
                                
                                //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Branch_c
                                break;
                            }
                            
                            //#line 48 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10If_c
                            if (x10aux::equals(s,x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Any> >(flag->
                                                                                                              FMGL(short_))) ||
                                x10aux::equals(s,x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Any> >(flag->
                                                                                                              FMGL(long_))))
                            {
                                
                                //#line 49 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10If_c
                                if ((!x10aux::struct_equals(flag->
                                                              FMGL(short_),
                                                            x10aux::null)))
                                {
                                    
                                    //#line 49 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Eval_c
                                    x10aux::placeCheck(set)->put(
                                      flag->
                                        FMGL(short_),
                                      true);
                                }
                                
                                //#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10If_c
                                if ((!x10aux::struct_equals(flag->
                                                              FMGL(long_),
                                                            x10aux::null)))
                                {
                                    
                                    //#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Eval_c
                                    x10aux::placeCheck(set)->put(
                                      flag->
                                        FMGL(long_),
                                      true);
                                }
                                
                                //#line 51 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Eval_c
                                recognised =
                                  true;
                            }
                            
                        }
                    }
                    
                }
                
                //#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10If_c
                if ((!x10aux::struct_equals(specs,
                                            x10aux::null)))
                {
                    
                    //#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.For_c
                    {
                        x10aux::ref<x10::lang::Iterator<x10::util::Option> > spec1842;
                        for (
                             //#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10LocalDecl_c
                             spec1842 =
                               (specs)->iterator();
                             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(spec1842))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10::util::Option> >(((x10aux::ref<x10::lang::Reference>)spec1842)->_getITables())->hasNext))();
                             )
                        {
                            
                            //#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10LocalDecl_c
                            x10::util::Option spec =
                              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(spec1842))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10::util::Option> >(((x10aux::ref<x10::lang::Reference>)spec1842)->_getITables())->next))();
                            
                            //#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10If_c
                            if (recognised)
                            {
                                
                                //#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Branch_c
                                break;
                            }
                            
                            //#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10If_c
                            if (x10aux::equals(s,x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Any> >(spec->
                                                                                                              FMGL(short_))) ||
                                x10aux::equals(s,x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Any> >(spec->
                                                                                                              FMGL(long_))))
                            {
                                
                                //#line 57 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Eval_c
                                recognised =
                                  true;
                                
                                //#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Eval_c
                                i =
                                  ((x10_int) ((i) + (((x10_int)1))));
                                
                                //#line 59 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10If_c
                                if (((i) >= (x10aux::nullCheck(args)->
                                               FMGL(length))))
                                {
                                    
                                    //#line 59 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Throw_c
                                    x10aux::throwException(x10aux::nullCheck(x10::util::OptionsParser__Err::_make(((((x10::lang::String::Lit("Expected another arg after: \"")) + (s))) + (x10::lang::String::Lit("\""))))));
                                }
                                
                                //#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10LocalDecl_c
                                x10aux::ref<x10::lang::String> s2 =
                                  (args)->apply(i);
                                
                                //#line 61 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10If_c
                                if ((!x10aux::struct_equals(spec->
                                                              FMGL(short_),
                                                            x10aux::null)))
                                {
                                    
                                    //#line 61 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Eval_c
                                    x10aux::placeCheck(map)->put(
                                      spec->
                                        FMGL(short_),
                                      s2);
                                }
                                
                                //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10If_c
                                if ((!x10aux::struct_equals(spec->
                                                              FMGL(long_),
                                                            x10aux::null)))
                                {
                                    
                                    //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Eval_c
                                    x10aux::placeCheck(map)->put(
                                      spec->
                                        FMGL(long_),
                                      s2);
                                }
                                
                            }
                            
                        }
                    }
                    
                }
                
            }
            
            //#line 66 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10If_c
            if ((!(recognised)))
            {
                
                //#line 66 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Eval_c
                (filteredArgs)->add(s);
            }
            
        }
    }
    
    //#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::OptionsParser>)this))->
      FMGL(map) =
      map;
    
    //#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::OptionsParser>)this))->
      FMGL(set) =
      set;
    
    //#line 70 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::OptionsParser>)this))->
      FMGL(filteredArgs) =
      filteredArgs;
    
}
x10aux::ref<x10::util::OptionsParser> x10::util::OptionsParser::_make(
  x10aux::ref<x10::lang::Rail<x10aux::ref<x10::lang::String> > > args,
  x10aux::ref<x10::lang::ValRail<x10::util::Option > > flags,
  x10aux::ref<x10::lang::ValRail<x10::util::Option > > specs)
{
    x10aux::ref<x10::util::OptionsParser> this_ = new (memset(x10aux::alloc<x10::util::OptionsParser>(), 0, sizeof(x10::util::OptionsParser))) x10::util::OptionsParser();
    this_->_constructor(args,
    flags,
    specs);
    return this_;
}



//#line 73 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Rail<x10aux::ref<x10::lang::String> > >
  x10::util::OptionsParser::filteredArgs(
  ) {
    
    //#line 73 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::util::OptionsParser>)this)->
              FMGL(filteredArgs))->toRail();
    
}

//#line 75 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::util::OptionsParser::apply(
  x10aux::ref<x10::lang::String> key) {
    
    //#line 75 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::util::OptionsParser>)this)->
                               FMGL(set))->containsKey(
             key) || x10aux::nullCheck(((x10aux::ref<x10::util::OptionsParser>)this)->
                                         FMGL(map))->containsKey(
                       key);
    
}

//#line 77 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::String> x10::util::OptionsParser::apply(
  x10aux::ref<x10::lang::String> key,
  x10aux::ref<x10::lang::String> d) {
    
    //#line 77 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::util::OptionsParser>)this)->
                               FMGL(map))->getOrElse(
             key,
             d);
    
}

//#line 89 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10MethodDecl_c
x10_byte x10::util::OptionsParser::apply(
  x10aux::ref<x10::lang::String> key,
  x10_byte d) {
    
    //#line 90 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10If_c
    if ((!(x10aux::nullCheck(((x10aux::ref<x10::util::OptionsParser>)this)->
                               FMGL(map))->containsKey(
             key)))) {
        
        //#line 90 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10Return_c
        return d;
        
    }
    
    //#line 91 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::String> v = x10aux::nullCheck(((x10aux::ref<x10::util::OptionsParser>)this)->
                                                           FMGL(map))->getOrElse(
                                         key,
                                         x10::lang::String::Lit("???"));
    
    //#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Try_c
    try {
        
        //#line 93 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10Return_c
        return x10aux::byte_utils::parseByte(v);
        
    }
    catch (x10aux::__ref& __ref__1196) {
        x10aux::ref<x10::lang::Throwable>& __exc__ref__1196 = (x10aux::ref<x10::lang::Throwable>&)__ref__1196;
        if (x10aux::instanceof<x10aux::ref<x10::lang::NumberFormatException> >(__exc__ref__1196)) {
            x10aux::ref<x10::lang::NumberFormatException> e =
              static_cast<x10aux::ref<x10::lang::NumberFormatException> >(__exc__ref__1196);
            {
                
                //#line 95 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::util::OptionsParser__Err::_make(((((x10::lang::String::Lit("Expected Byte, got: \"")) + (v))) + (x10::lang::String::Lit("\""))))));
            }
        } else
        throw;
    }
}

//#line 109 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10MethodDecl_c
x10_short x10::util::OptionsParser::apply(
  x10aux::ref<x10::lang::String> key,
  x10_short d) {
    
    //#line 110 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10If_c
    if ((!(x10aux::nullCheck(((x10aux::ref<x10::util::OptionsParser>)this)->
                               FMGL(map))->containsKey(
             key)))) {
        
        //#line 110 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10Return_c
        return d;
        
    }
    
    //#line 111 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::String> v = x10aux::nullCheck(((x10aux::ref<x10::util::OptionsParser>)this)->
                                                           FMGL(map))->getOrElse(
                                         key,
                                         x10::lang::String::Lit("???"));
    
    //#line 112 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Try_c
    try {
        
        //#line 113 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10Return_c
        return x10aux::short_utils::parseShort(v);
        
    }
    catch (x10aux::__ref& __ref__1198) {
        x10aux::ref<x10::lang::Throwable>& __exc__ref__1198 = (x10aux::ref<x10::lang::Throwable>&)__ref__1198;
        if (x10aux::instanceof<x10aux::ref<x10::lang::NumberFormatException> >(__exc__ref__1198)) {
            x10aux::ref<x10::lang::NumberFormatException> e =
              static_cast<x10aux::ref<x10::lang::NumberFormatException> >(__exc__ref__1198);
            {
                
                //#line 115 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::util::OptionsParser__Err::_make(((((x10::lang::String::Lit("Expected Short, got: \"")) + (v))) + (x10::lang::String::Lit("\""))))));
            }
        } else
        throw;
    }
}

//#line 129 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10MethodDecl_c
x10_int x10::util::OptionsParser::apply(x10aux::ref<x10::lang::String> key,
                                        x10_int d) {
    
    //#line 130 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10If_c
    if ((!(x10aux::nullCheck(((x10aux::ref<x10::util::OptionsParser>)this)->
                               FMGL(map))->containsKey(
             key)))) {
        
        //#line 130 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10Return_c
        return d;
        
    }
    
    //#line 131 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::String> v = x10aux::nullCheck(((x10aux::ref<x10::util::OptionsParser>)this)->
                                                           FMGL(map))->getOrElse(
                                         key,
                                         x10::lang::String::Lit("???"));
    
    //#line 132 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Try_c
    try {
        
        //#line 133 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10Return_c
        return x10aux::int_utils::parseInt(v);
        
    }
    catch (x10aux::__ref& __ref__1200) {
        x10aux::ref<x10::lang::Throwable>& __exc__ref__1200 = (x10aux::ref<x10::lang::Throwable>&)__ref__1200;
        if (x10aux::instanceof<x10aux::ref<x10::lang::NumberFormatException> >(__exc__ref__1200)) {
            x10aux::ref<x10::lang::NumberFormatException> e =
              static_cast<x10aux::ref<x10::lang::NumberFormatException> >(__exc__ref__1200);
            {
                
                //#line 135 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::util::OptionsParser__Err::_make(((((x10::lang::String::Lit("Expected Long, got: \"")) + (v))) + (x10::lang::String::Lit("\""))))));
            }
        } else
        throw;
    }
}

//#line 149 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10MethodDecl_c
x10_long x10::util::OptionsParser::apply(
  x10aux::ref<x10::lang::String> key,
  x10_long d) {
    
    //#line 150 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10If_c
    if ((!(x10aux::nullCheck(((x10aux::ref<x10::util::OptionsParser>)this)->
                               FMGL(map))->containsKey(
             key)))) {
        
        //#line 150 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10Return_c
        return d;
        
    }
    
    //#line 151 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::String> v = x10aux::nullCheck(((x10aux::ref<x10::util::OptionsParser>)this)->
                                                           FMGL(map))->getOrElse(
                                         key,
                                         x10::lang::String::Lit("???"));
    
    //#line 152 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Try_c
    try {
        
        //#line 153 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10Return_c
        return x10aux::long_utils::parseLong(v);
        
    }
    catch (x10aux::__ref& __ref__1202) {
        x10aux::ref<x10::lang::Throwable>& __exc__ref__1202 = (x10aux::ref<x10::lang::Throwable>&)__ref__1202;
        if (x10aux::instanceof<x10aux::ref<x10::lang::NumberFormatException> >(__exc__ref__1202)) {
            x10aux::ref<x10::lang::NumberFormatException> e =
              static_cast<x10aux::ref<x10::lang::NumberFormatException> >(__exc__ref__1202);
            {
                
                //#line 155 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::util::OptionsParser__Err::_make(((((x10::lang::String::Lit("Expected Int, got: \"")) + (v))) + (x10::lang::String::Lit("\""))))));
            }
        } else
        throw;
    }
}

//#line 160 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10MethodDecl_c
x10_double x10::util::OptionsParser::apply(
  x10aux::ref<x10::lang::String> key,
  x10_double d) {
    
    //#line 161 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10If_c
    if ((!(x10aux::nullCheck(((x10aux::ref<x10::util::OptionsParser>)this)->
                               FMGL(map))->containsKey(
             key)))) {
        
        //#line 161 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10Return_c
        return d;
        
    }
    
    //#line 162 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::String> v = x10aux::nullCheck(((x10aux::ref<x10::util::OptionsParser>)this)->
                                                           FMGL(map))->getOrElse(
                                         key,
                                         x10::lang::String::Lit("???"));
    
    //#line 163 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Try_c
    try {
        
        //#line 164 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10Return_c
        return x10aux::double_utils::parseDouble(v);
        
    }
    catch (x10aux::__ref& __ref__1204) {
        x10aux::ref<x10::lang::Throwable>& __exc__ref__1204 = (x10aux::ref<x10::lang::Throwable>&)__ref__1204;
        if (x10aux::instanceof<x10aux::ref<x10::lang::NumberFormatException> >(__exc__ref__1204)) {
            x10aux::ref<x10::lang::NumberFormatException> e =
              static_cast<x10aux::ref<x10::lang::NumberFormatException> >(__exc__ref__1204);
            {
                
                //#line 166 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::util::OptionsParser__Err::_make(((((x10::lang::String::Lit("Expected Double, got: \"")) + (v))) + (x10::lang::String::Lit("\""))))));
            }
        } else
        throw;
    }
}

//#line 169 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10MethodDecl_c
x10_float x10::util::OptionsParser::apply(
  x10aux::ref<x10::lang::String> key,
  x10_float d) {
    
    //#line 170 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10If_c
    if ((!(x10aux::nullCheck(((x10aux::ref<x10::util::OptionsParser>)this)->
                               FMGL(map))->containsKey(
             key)))) {
        
        //#line 170 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10Return_c
        return d;
        
    }
    
    //#line 171 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::String> v = x10aux::nullCheck(((x10aux::ref<x10::util::OptionsParser>)this)->
                                                           FMGL(map))->getOrElse(
                                         key,
                                         x10::lang::String::Lit("???"));
    
    //#line 172 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Try_c
    try {
        
        //#line 173 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10Return_c
        return x10aux::float_utils::parseFloat(v);
        
    }
    catch (x10aux::__ref& __ref__1206) {
        x10aux::ref<x10::lang::Throwable>& __exc__ref__1206 = (x10aux::ref<x10::lang::Throwable>&)__ref__1206;
        if (x10aux::instanceof<x10aux::ref<x10::lang::NumberFormatException> >(__exc__ref__1206)) {
            x10aux::ref<x10::lang::NumberFormatException> e =
              static_cast<x10aux::ref<x10::lang::NumberFormatException> >(__exc__ref__1206);
            {
                
                //#line 175 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::util::OptionsParser__Err::_make(((((x10::lang::String::Lit("Expected Float, got: \"")) + (v))) + (x10::lang::String::Lit("\""))))));
            }
        } else
        throw;
    }
}
const x10aux::serialization_id_t x10::util::OptionsParser::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::util::OptionsParser::_deserializer<x10::lang::Object>);

void x10::util::OptionsParser::_serialize(x10aux::ref<x10::util::OptionsParser> this_,
                                          x10aux::serialization_buffer& buf) {
    _serialize_reference(this_, buf);
    if (this_ != x10aux::null) {
        this_->_serialize_body(buf);
    }
}

void x10::util::OptionsParser::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::util::OptionsParser::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::util::OptionsParser::rtt;
void x10::util::OptionsParser::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.util.OptionsParser", 1, parents, 0, NULL, NULL);
}
