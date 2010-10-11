#include <x10/lang/MultipleExceptions.h>


#include "x10/lang/MultipleExceptions.inc"


//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": x10.ast.PropertyDecl_c
void x10::lang::MultipleExceptions::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::MultipleExceptions");
    
}


//#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::MultipleExceptions::_constructor(x10aux::ref<x10::util::Stack<x10aux::ref<x10::lang::Throwable> > > stack)
{
    this->x10::lang::RuntimeException::_constructor();
    
    //#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::Stack<x10aux::ref<x10::lang::Throwable> > > s =
      x10::util::Stack<x10aux::ref<x10::lang::Throwable> >::_make();
    
    //#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::lang::Throwable> > > t1787;
        for (
             //#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": x10.ast.X10LocalDecl_c
             t1787 =
               (x10aux::placeCheck(x10aux::nullCheck(stack))->toValRail())->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(t1787))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::lang::Throwable> > >(((x10aux::ref<x10::lang::Reference>)t1787)->_getITables())->hasNext))();
             )
        {
            
            //#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::lang::Throwable> t =
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(t1787))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::lang::Throwable> > >(((x10aux::ref<x10::lang::Reference>)t1787)->_getITables())->next))();
            
            //#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": x10.ast.X10If_c
            if (x10aux::instanceof<x10aux::ref<x10::lang::MultipleExceptions> >(t))
            {
                
                //#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": polyglot.ast.For_c
                {
                    x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::lang::Throwable> > > u1786;
                    for (
                         //#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": x10.ast.X10LocalDecl_c
                         u1786 =
                           (x10aux::nullCheck((x10aux::class_cast<x10aux::ref<x10::lang::MultipleExceptions> >(t)))->
                              FMGL(exceptions))->iterator();
                         (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(u1786))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::lang::Throwable> > >(((x10aux::ref<x10::lang::Reference>)u1786)->_getITables())->hasNext))();
                         )
                    {
                        
                        //#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": x10.ast.X10LocalDecl_c
                        x10aux::ref<x10::lang::Throwable> u =
                          (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(u1786))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::lang::Throwable> > >(((x10aux::ref<x10::lang::Reference>)u1786)->_getITables())->next))();
                        
                        //#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": polyglot.ast.Eval_c
                        x10aux::placeCheck(s)->push(
                          u);
                    }
                }
                
            }
            else
            {
                
                //#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": polyglot.ast.Eval_c
                x10aux::placeCheck(s)->push(
                  t);
            }
            
        }
    }
    
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::MultipleExceptions>)this)->
      FMGL(exceptions) =
      x10aux::placeCheck(s)->toValRail();
    
}
x10aux::ref<x10::lang::MultipleExceptions> x10::lang::MultipleExceptions::_make(
  x10aux::ref<x10::util::Stack<x10aux::ref<x10::lang::Throwable> > > stack)
{
    x10aux::ref<x10::lang::MultipleExceptions> this_ = new (memset(x10aux::alloc<x10::lang::MultipleExceptions>(), 0, sizeof(x10::lang::MultipleExceptions))) x10::lang::MultipleExceptions();
    this_->_constructor(stack);
    return this_;
}



//#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::MultipleExceptions::_constructor(
  x10aux::ref<x10::lang::Throwable> t) {
    this->x10::lang::RuntimeException::_constructor();
    
    //#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::Stack<x10aux::ref<x10::lang::Throwable> > > s =
      x10::util::Stack<x10aux::ref<x10::lang::Throwable> >::_make();
    
    //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": x10.ast.X10If_c
    if (x10aux::instanceof<x10aux::ref<x10::lang::MultipleExceptions> >(t))
    {
        
        //#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": polyglot.ast.For_c
        {
            x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::lang::Throwable> > > u1788;
            for (
                 //#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": x10.ast.X10LocalDecl_c
                 u1788 =
                   (x10aux::nullCheck((x10aux::class_cast<x10aux::ref<x10::lang::MultipleExceptions> >(t)))->
                      FMGL(exceptions))->iterator();
                 (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(u1788))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::lang::Throwable> > >(((x10aux::ref<x10::lang::Reference>)u1788)->_getITables())->hasNext))();
                 )
            {
                
                //#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": x10.ast.X10LocalDecl_c
                x10aux::ref<x10::lang::Throwable> u =
                  (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(u1788))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::lang::Throwable> > >(((x10aux::ref<x10::lang::Reference>)u1788)->_getITables())->next))();
                
                //#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": polyglot.ast.Eval_c
                x10aux::placeCheck(s)->push(
                  u);
            }
        }
        
    }
    else
    {
        
        //#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": polyglot.ast.Eval_c
        x10aux::placeCheck(s)->push(
          t);
    }
    
    //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::MultipleExceptions>)this)->
      FMGL(exceptions) = x10aux::placeCheck(s)->toValRail();
    
}
x10aux::ref<x10::lang::MultipleExceptions> x10::lang::MultipleExceptions::_make(
  x10aux::ref<x10::lang::Throwable> t) {
    x10aux::ref<x10::lang::MultipleExceptions> this_ = new (memset(x10aux::alloc<x10::lang::MultipleExceptions>(), 0, sizeof(x10::lang::MultipleExceptions))) x10::lang::MultipleExceptions();
    this_->_constructor(t);
    return this_;
}



//#line 51 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": x10.ast.X10MethodDecl_c
void x10::lang::MultipleExceptions::printStackTrace(
  ) {
    
    //#line 53 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::lang::Throwable> > > t1789;
        for (
             //#line 53 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": x10.ast.X10LocalDecl_c
             t1789 = (((x10aux::ref<x10::lang::MultipleExceptions>)this)->
                        FMGL(exceptions))->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(t1789))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::lang::Throwable> > >(((x10aux::ref<x10::lang::Reference>)t1789)->_getITables())->hasNext))();
             ) {
            
            //#line 53 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::lang::Throwable> t =
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(t1789))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::lang::Throwable> > >(((x10aux::ref<x10::lang::Reference>)t1789)->_getITables())->next))();
            
            //#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": polyglot.ast.Eval_c
            (t)->printStackTrace();
        }
    }
    
}

//#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": x10.ast.X10MethodDecl_c
void x10::lang::MultipleExceptions::printStackTrace(
  x10aux::ref<x10::io::Printer> p) {
 
}

//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Throwable> > >
  x10::lang::MultipleExceptions::exceptions(
  ) {
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/MultipleExceptions.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::lang::MultipleExceptions>)this)->
             FMGL(exceptions);
    
}
const x10aux::serialization_id_t x10::lang::MultipleExceptions::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::MultipleExceptions::_deserializer<x10::lang::Object>);

void x10::lang::MultipleExceptions::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::RuntimeException::_serialize_body(buf);
    buf.write(this->FMGL(exceptions));
    
}

void x10::lang::MultipleExceptions::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::RuntimeException::_deserialize_body(buf);
    FMGL(exceptions) = buf.read<x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Throwable> > > >();
}

x10aux::RuntimeType x10::lang::MultipleExceptions::rtt;
void x10::lang::MultipleExceptions::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::RuntimeException>()};
    rtt.initStageTwo("x10.lang.MultipleExceptions", 1, parents, 0, NULL, NULL);
}
