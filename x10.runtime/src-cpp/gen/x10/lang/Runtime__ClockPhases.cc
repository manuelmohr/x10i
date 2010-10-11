#include <x10/lang/Runtime__ClockPhases.h>


#include "x10/lang/Runtime__ClockPhases.inc"

x10::util::Map<x10aux::ref<x10::lang::Clock>, x10_int>::itable<x10::lang::Runtime__ClockPhases >  x10::lang::Runtime__ClockPhases::_itable_0(&x10::lang::Runtime__ClockPhases::at, &x10::lang::Runtime__ClockPhases::at, &x10::lang::Runtime__ClockPhases::clear, &x10::lang::Runtime__ClockPhases::containsKey, &x10::lang::Runtime__ClockPhases::entries, &x10::lang::Runtime__ClockPhases::equals, &x10::lang::Runtime__ClockPhases::get, &x10::lang::Runtime__ClockPhases::getOrElse, &x10::lang::Runtime__ClockPhases::getOrThrow, &x10::lang::Runtime__ClockPhases::hashCode, &x10::lang::Runtime__ClockPhases::home, &x10::lang::Runtime__ClockPhases::keySet, &x10::lang::Runtime__ClockPhases::put, &x10::lang::Runtime__ClockPhases::remove, &x10::lang::Runtime__ClockPhases::toString, &x10::lang::Runtime__ClockPhases::typeName);
x10::lang::Any::itable<x10::lang::Runtime__ClockPhases >  x10::lang::Runtime__ClockPhases::_itable_1(&x10::lang::Runtime__ClockPhases::at, &x10::lang::Runtime__ClockPhases::at, &x10::lang::Runtime__ClockPhases::equals, &x10::lang::Runtime__ClockPhases::hashCode, &x10::lang::Runtime__ClockPhases::home, &x10::lang::Runtime__ClockPhases::toString, &x10::lang::Runtime__ClockPhases::typeName);
x10aux::itable_entry x10::lang::Runtime__ClockPhases::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::util::Map<x10aux::ref<x10::lang::Clock>, x10_int> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::lang::Runtime__ClockPhases>())};
void x10::lang::Runtime__ClockPhases::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Runtime__ClockPhases");
    
}


//#line 280 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Runtime__ClockPhases> x10::lang::Runtime__ClockPhases::make(
  x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Clock> > > clocks,
  x10aux::ref<x10::lang::ValRail<x10_int > > phases) {
    
    //#line 281 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Runtime__ClockPhases> clockPhases = x10::lang::Runtime__ClockPhases::_make();
    
    //#line 282 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 282 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (x10aux::nullCheck(clocks)->
                                         FMGL(length))); 
                                                         //#line 282 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                                                         i = ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 282 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            clockPhases->put(
              (clocks)->apply(i),
              (phases)->apply(i));
        }
    }
    
    //#line 283 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return clockPhases;
    
}

//#line 286 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::ValRail<x10_int > > x10::lang::Runtime__ClockPhases::_kwd__register(
  x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Clock> > > clocks) {
    
    //#line 287 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10::lang::ValRail<x10_int >::make(x10aux::nullCheck(clocks)->
                                                FMGL(length), x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_lang_Runtime__ClockPhases__closure__0>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_lang_Runtime__ClockPhases__closure__0)))x10_lang_Runtime__ClockPhases__closure__0(clocks)))));
    
}

//#line 290 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__ClockPhases::next() {
    
    //#line 291 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::lang::Clock> > > clock1797;
        for (
             //#line 291 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
             clock1797 = (__extension__ ({ x10aux::ref<x10::lang::Reference> _ = x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__ClockPhases>)this)->keySet());
                         (((x10::lang::Reference*)(_.operator->()))->*(x10aux::findITable<x10::util::Set<x10aux::ref<x10::lang::Clock> > >(_->_getITables())->iterator))(); }));
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(clock1797))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::lang::Clock> > >(((x10aux::ref<x10::lang::Reference>)clock1797)->_getITables())->hasNext))();
             ) {
            
            //#line 291 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::lang::Clock> clock =
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(clock1797))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::lang::Clock> > >(((x10aux::ref<x10::lang::Reference>)clock1797)->_getITables())->next))();
            
            //#line 291 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(clock)->resumeUnsafe();
        }
    }
    
    //#line 292 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::lang::Clock> > > clock1798;
        for (
             //#line 292 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
             clock1798 = (__extension__ ({ x10aux::ref<x10::lang::Reference> _ = x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__ClockPhases>)this)->keySet());
                         (((x10::lang::Reference*)(_.operator->()))->*(x10aux::findITable<x10::util::Set<x10aux::ref<x10::lang::Clock> > >(_->_getITables())->iterator))(); }));
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(clock1798))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::lang::Clock> > >(((x10aux::ref<x10::lang::Reference>)clock1798)->_getITables())->hasNext))();
             ) {
            
            //#line 292 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::lang::Clock> clock =
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(clock1798))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::lang::Clock> > >(((x10aux::ref<x10::lang::Reference>)clock1798)->_getITables())->next))();
            
            //#line 292 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(clock)->nextUnsafe();
        }
    }
    
}

//#line 295 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__ClockPhases::drop(
  ) {
    
    //#line 296 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::lang::Clock> > > clock1799;
        for (
             //#line 296 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
             clock1799 = (__extension__ ({ x10aux::ref<x10::lang::Reference> _ = x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__ClockPhases>)this)->keySet());
                         (((x10::lang::Reference*)(_.operator->()))->*(x10aux::findITable<x10::util::Set<x10aux::ref<x10::lang::Clock> > >(_->_getITables())->iterator))(); }));
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(clock1799))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::lang::Clock> > >(((x10aux::ref<x10::lang::Reference>)clock1799)->_getITables())->hasNext))();
             ) {
            
            //#line 296 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::lang::Clock> clock =
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(clock1799))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::lang::Clock> > >(((x10aux::ref<x10::lang::Reference>)clock1799)->_getITables())->next))();
            
            //#line 296 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(clock)->dropInternal();
        }
    }
    
    //#line 297 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__ClockPhases>)this)->clear();
}

//#line 279 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::Runtime__ClockPhases::_constructor(
  ) {
    this->x10::util::HashMap<x10aux::ref<x10::lang::Clock>, x10_int>::_constructor();
    
}
x10aux::ref<x10::lang::Runtime__ClockPhases> x10::lang::Runtime__ClockPhases::_make(
  ) {
    x10aux::ref<x10::lang::Runtime__ClockPhases> this_ = new (memset(x10aux::alloc<x10::lang::Runtime__ClockPhases>(), 0, sizeof(x10::lang::Runtime__ClockPhases))) x10::lang::Runtime__ClockPhases();
    this_->_constructor();
    return this_;
}


const x10aux::serialization_id_t x10::lang::Runtime__ClockPhases::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::Runtime__ClockPhases::_deserializer<x10::lang::Object>);

void x10::lang::Runtime__ClockPhases::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::util::HashMap<x10aux::ref<x10::lang::Clock>, x10_int>::_serialize_body(buf);
    
}

void x10::lang::Runtime__ClockPhases::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::util::HashMap<x10aux::ref<x10::lang::Clock>, x10_int>::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::Runtime__ClockPhases::rtt;
void x10::lang::Runtime__ClockPhases::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::util::HashMap<x10aux::ref<x10::lang::Clock>, x10_int> >()};
    rtt.initStageTwo("x10.lang.Runtime$ClockPhases", 1, parents, 0, NULL, NULL);
}
x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_lang_Runtime__ClockPhases__closure__0>x10_lang_Runtime__ClockPhases__closure__0::_itable(&x10_lang_Runtime__ClockPhases__closure__0::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__ClockPhases__closure__0::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__ClockPhases__closure__0::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_lang_Runtime__ClockPhases__closure__0::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__ClockPhases__closure__0::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__ClockPhases__closure__0::_deserialize<x10::lang::Object>);

