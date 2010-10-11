#include <x10/lang/Place.h>


#include "x10/lang/Place.inc"


//#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.PropertyDecl_c
namespace x10 { namespace lang { 
class Place_ithunk0 : public x10::lang::Place {
public:
    static x10::lang::Any::itable<Place_ithunk0 > itable;
    x10_boolean at(x10aux::ref<x10::lang::Object> arg0) {
        return (x10aux::get_location(*this) == (arg0)->location);
    }
    x10_boolean at(x10::lang::Place arg0) {
        return (x10aux::get_location(*this) == (arg0)->FMGL(id));
    }
    x10_boolean equals(x10aux::ref<x10::lang::Any> arg0) {
        return x10::lang::Place_methods::equals(*this, arg0);
    }
    x10_int hashCode() {
        return x10::lang::Place_methods::hashCode(*this);
    }
    x10::lang::Place home() {
        return x10::lang::Place_methods::place(x10aux::get_location(*this));
    }
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::Place_methods::toString(*this);
    }
    x10aux::ref<x10::lang::String> typeName() {
        return x10aux::type_name(*this);
    }
    
};
x10::lang::Any::itable<Place_ithunk0 >  Place_ithunk0::itable(&Place_ithunk0::at, &Place_ithunk0::at, &Place_ithunk0::equals, &Place_ithunk0::hashCode, &Place_ithunk0::home, &Place_ithunk0::toString, &Place_ithunk0::typeName);
class Place_iboxithunk0 : public x10::lang::IBox<x10::lang::Place> {
public:
    static x10::lang::Any::itable<Place_iboxithunk0 > itable;
    x10_boolean at(x10aux::ref<x10::lang::Object> arg0) {
        return (x10aux::get_location(this->value) == (arg0)->location);
    }
    x10_boolean at(x10::lang::Place arg0) {
        return (x10aux::get_location(this->value) == (arg0)->FMGL(id));
    }
    x10_boolean equals(x10aux::ref<x10::lang::Any> arg0) {
        return x10::lang::Place_methods::equals(this->value, arg0);
    }
    x10_int hashCode() {
        return x10::lang::Place_methods::hashCode(this->value);
    }
    x10::lang::Place home() {
        return x10::lang::Place_methods::place(x10aux::get_location(this->value));
    }
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::Place_methods::toString(this->value);
    }
    x10aux::ref<x10::lang::String> typeName() {
        return x10aux::type_name(this->value);
    }
    
};
x10::lang::Any::itable<Place_iboxithunk0 >  Place_iboxithunk0::itable(&Place_iboxithunk0::at, &Place_iboxithunk0::at, &Place_iboxithunk0::equals, &Place_iboxithunk0::hashCode, &Place_iboxithunk0::home, &Place_iboxithunk0::toString, &Place_iboxithunk0::typeName);
} } 
x10aux::itable_entry x10::lang::Place::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &Place_ithunk0::itable), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::lang::Place>())};
x10aux::itable_entry x10::lang::Place::_iboxitables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &Place_iboxithunk0::itable), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::lang::Place>())};
void x10::lang::Place_methods::_instance_init(x10::lang::Place& this_) {
    _I_("Doing initialisation for class: x10::lang::Place");
    
}


//#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10FieldDecl_c
x10_int x10::lang::Place_methods::FMGL(ALL_PLACES) = ((x10_int)4);


//#line 31 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10FieldDecl_c
x10_int x10::lang::Place_methods::FMGL(MAX_PLACES) = ((x10_int)4);


//#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c
x10_int x10::lang::Place_methods::numChildren(x10_int id) {
    
    //#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
    return ((x10_int)0);
    
}

//#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::lang::Place_methods::isHost(x10_int id) {
    
    //#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::lang::Place_methods::isSPE(x10_int id) {
    
    //#line 51 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
    return false;
    
}

//#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::lang::Place_methods::isCUDA(x10_int id) {
    
    //#line 57 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
    return false;
    
}

//#line 64 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c
x10_int x10::lang::Place_methods::parent(x10_int id) {
    
    //#line 65 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
    return id;
    
}

//#line 72 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c
x10_int x10::lang::Place_methods::child(x10_int p, x10_int i) {
    
    //#line 73 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::BadPlaceException::_make()));
}

//#line 79 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c
x10_int x10::lang::Place_methods::childIndex(x10_int id) {
    
    //#line 80 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::BadPlaceException::_make()));
}

//#line 82 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10FieldDecl_c
x10aux::ref<x10::lang::ValRail<x10::lang::Place > > x10::lang::Place_methods::FMGL(places);
void x10::lang::Place_methods::FMGL(places__do_init)() {
    FMGL(places__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::lang::Place_methods.places");
    x10aux::ref<x10::lang::ValRail<x10::lang::Place > > __var821__ = x10::lang::ValRail<x10::lang::Place >::make(x10aux::num_hosts, x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10::lang::Place> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10::lang::Place> >(x10aux::ref<x10_lang_Place__closure__0>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10::lang::Place> >(sizeof(x10_lang_Place__closure__0)))x10_lang_Place__closure__0()))));
    FMGL(places) = __var821__;
    FMGL(places__status) = x10aux::INITIALIZED;
}
void x10::lang::Place_methods::FMGL(places__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var822__ = (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(places__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var822__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(places__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(places),
                                                                    FMGL(places__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(places__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__823 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::lang::Place_methods::FMGL(places__init));

volatile x10aux::status x10::lang::Place_methods::FMGL(places__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object> x10::lang::Place_methods::FMGL(places__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(places) = buf.read<x10aux::ref<x10::lang::ValRail<x10::lang::Place > > >();
    x10::lang::Place_methods::FMGL(places__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::lang::Place_methods::FMGL(places__id) =
  x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::lang::Place_methods::FMGL(places__deserialize));


//#line 83 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10FieldDecl_c
x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::ValRail<x10::lang::Place > > > >
  x10::lang::Place_methods::FMGL(children);
void x10::lang::Place_methods::FMGL(children__do_init)() {
    FMGL(children__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::lang::Place_methods.children");
    x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::ValRail<x10::lang::Place > > > >
      __var824__ =
      x10::lang::ValRail<x10aux::ref<x10::lang::ValRail<x10::lang::Place > > >::make(x10aux::num_places, x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::lang::ValRail<x10::lang::Place > > > > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::lang::ValRail<x10::lang::Place > > > >(x10aux::ref<x10_lang_Place__closure__1>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::lang::ValRail<x10::lang::Place > > > >(sizeof(x10_lang_Place__closure__1)))x10_lang_Place__closure__1()))));
    FMGL(children) = __var824__;
    FMGL(children__status) = x10aux::INITIALIZED;
}
void x10::lang::Place_methods::FMGL(children__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var825__ = (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(children__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var825__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(children__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(children),
                                                                    FMGL(children__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(children__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__826 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::lang::Place_methods::FMGL(children__init));

volatile x10aux::status x10::lang::Place_methods::FMGL(children__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object> x10::lang::Place_methods::FMGL(children__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(children) = buf.read<x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::ValRail<x10::lang::Place > > > > >();
    x10::lang::Place_methods::FMGL(children__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::lang::Place_methods::FMGL(children__id) =
  x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::lang::Place_methods::FMGL(children__deserialize));


//#line 87 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10FieldDecl_c
x10_int x10::lang::Place_methods::FMGL(NUM_ACCELS);
void x10::lang::Place_methods::FMGL(NUM_ACCELS__do_init)() {
    FMGL(NUM_ACCELS__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::lang::Place_methods.NUM_ACCELS");
    x10_int __var827__ = ((x10_int) ((x10aux::num_places) - (x10aux::num_hosts)));
    FMGL(NUM_ACCELS) = __var827__;
    FMGL(NUM_ACCELS__status) = x10aux::INITIALIZED;
}
void x10::lang::Place_methods::FMGL(NUM_ACCELS__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var828__ = (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(NUM_ACCELS__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var828__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(NUM_ACCELS__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(NUM_ACCELS),
                                                                    FMGL(NUM_ACCELS__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(NUM_ACCELS__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__829 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::lang::Place_methods::FMGL(NUM_ACCELS__init));

volatile x10aux::status x10::lang::Place_methods::FMGL(NUM_ACCELS__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object> x10::lang::Place_methods::FMGL(NUM_ACCELS__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(NUM_ACCELS) = buf.read<x10_int>();
    x10::lang::Place_methods::FMGL(NUM_ACCELS__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::lang::Place_methods::FMGL(NUM_ACCELS__id) =
  x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::lang::Place_methods::FMGL(NUM_ACCELS__deserialize));


//#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10FieldDecl_c
x10::lang::Place x10::lang::Place_methods::FMGL(FIRST_PLACE);
void x10::lang::Place_methods::FMGL(FIRST_PLACE__do_init)() {
    FMGL(FIRST_PLACE__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::lang::Place_methods.FIRST_PLACE");
    x10::lang::Place __var830__ = (__extension__ ({
        x10::lang::Place __desugarer__var__43__ =
          (x10::lang::Place_methods::
             FMGL(places__get)())->apply(((x10_int)0));
        
        //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10LocalDecl_c
        x10::lang::Place __var831__;
        
        //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": polyglot.ast.Labeled_c
        goto __ret1977; __ret1977: 
        //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Do_c
        do
        {
        {
            
            //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10If_c
            if (!((x10aux::struct_equals(__desugarer__var__43__->
                                           FMGL(id),
                                         ((x10_int)0)))))
            {
                
                //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Place{self.id==0}"))));
            }
            
            //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": polyglot.ast.Eval_c
            __var831__ =
              __desugarer__var__43__;
            
            //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": polyglot.ast.Branch_c
            goto __ret1977_end_;
        }
        goto __ret1977_next_; __ret1977_next_: ;
        }
        while (false);
        goto __ret1977_end_; __ret1977_end_: ;
        __var831__;
    }))
    ;
    FMGL(FIRST_PLACE) = __var830__;
    FMGL(FIRST_PLACE__status) = x10aux::INITIALIZED;
}
void x10::lang::Place_methods::FMGL(FIRST_PLACE__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var832__ = (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(FIRST_PLACE__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var832__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(FIRST_PLACE__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(FIRST_PLACE),
                                                                    FMGL(FIRST_PLACE__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(FIRST_PLACE__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__833 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::lang::Place_methods::FMGL(FIRST_PLACE__init));

volatile x10aux::status x10::lang::Place_methods::FMGL(FIRST_PLACE__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object> x10::lang::Place_methods::FMGL(FIRST_PLACE__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(FIRST_PLACE) = buf.read<x10::lang::Place>();
    x10::lang::Place_methods::FMGL(FIRST_PLACE__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::lang::Place_methods::FMGL(FIRST_PLACE__id) =
  x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::lang::Place_methods::FMGL(FIRST_PLACE__deserialize));


//#line 90 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10ConstructorDecl_c


//#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c

//#line 93 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c

//#line 94 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c

//#line 95 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c

//#line 96 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c

//#line 106 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c

//#line 107 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c

//#line 109 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c

//#line 110 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c

//#line 111 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c

//#line 113 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c

//#line 114 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c

//#line 116 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::ValRail<x10::lang::Place > >
  x10::lang::Place_methods::children(
  x10::lang::Place this_) {
    
    //#line 116 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
    return (x10::lang::Place_methods::FMGL(children__get)())->apply(this_->
                                                                      FMGL(id));
    
}

//#line 118 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c
x10::lang::Place x10::lang::Place_methods::parent(
  x10::lang::Place this_) {
    
    //#line 118 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
    return (x10::lang::Place_methods::FMGL(places__get)())->apply(x10aux::parent(this_->
                                                                                   FMGL(id)));
    
}

//#line 120 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c
x10_int x10::lang::Place_methods::childIndex(
  x10::lang::Place this_) {
    
    //#line 121 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10If_c
    if (x10::lang::Place_methods::isHost(this_))
    {
        
        //#line 122 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::lang::BadPlaceException::_make()));
    }
    
    //#line 124 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
    return x10aux::child_index(this_->FMGL(id));
    
}

//#line 127 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::String> x10::lang::Place_methods::toString(
  x10::lang::Place this_) {
    
    //#line 127 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
    return ((((x10::lang::String::Lit("(Place ")) + (this_->
                                                       FMGL(id)))) + (x10::lang::String::Lit(")")));
    
}

//#line 128 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c

//#line 129 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::lang::Place_methods::equals(
  x10::lang::Place this_, x10aux::ref<x10::lang::Any> p) {
    
    //#line 129 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
    return x10aux::instanceof<x10::lang::Place>(p) &&
    (x10aux::struct_equals((x10aux::class_cast<x10::lang::Place>(p))->
                             FMGL(id),
                           this_->
                             FMGL(id)));
    
}

//#line 130 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c

//#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c

//#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c

//#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c

//#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c

//#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c

//#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::lang::Place_methods::_struct_equals(
  x10::lang::Place this_, x10aux::ref<x10::lang::Any> other) {
    
    //#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10If_c
    if ((!(x10aux::instanceof<x10::lang::Place>(other))))
    {
        
        //#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
        return false;
        
    }
    
    //#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
    return x10::lang::Place_methods::_struct_equals(this_, 
             x10aux::class_cast<x10::lang::Place>(other));
    
}

//#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10MethodDecl_c
void x10::lang::Place::_serialize(x10::lang::Place this_, x10aux::serialization_buffer& buf) {
    buf.write(this_->FMGL(id));
    
}

void x10::lang::Place::_deserialize_body(x10aux::deserialization_buffer& buf) {
    FMGL(id) = buf.read<x10_int>();
}


x10_boolean x10::lang::Place::equals(x10aux::ref<x10::lang::Any> that) {
    return x10::lang::Place_methods::equals(*this, that);
}
x10_boolean x10::lang::Place::equals(x10::lang::Place that) {
    return x10::lang::Place_methods::equals(*this, that);
}
x10_boolean x10::lang::Place::_struct_equals(x10aux::ref<x10::lang::Any> that) {
    return x10::lang::Place_methods::_struct_equals(*this, that);
}
x10_boolean x10::lang::Place::_struct_equals(x10::lang::Place that) {
    return x10::lang::Place_methods::_struct_equals(*this, that);
}
x10aux::ref<x10::lang::String> x10::lang::Place::toString() {
    return x10::lang::Place_methods::toString(*this);
}
x10_int x10::lang::Place::hashCode() {
    return x10::lang::Place_methods::hashCode(*this);
}
x10aux::RuntimeType x10::lang::Place::rtt;
void x10::lang::Place::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::lang::Any>()};
    rtt.initStageTwo("x10.lang.Place", 2, parents, 0, NULL, NULL);
    rtt.containsPtrs = false;
}
x10::lang::Fun_0_1<x10_int, x10::lang::Place>::itable<x10_lang_Place__closure__0>x10_lang_Place__closure__0::_itable(&x10_lang_Place__closure__0::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Place__closure__0::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Place__closure__0::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10::lang::Place> >, &x10_lang_Place__closure__0::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Place__closure__0::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Place__closure__0::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::lang::ValRail<x10::lang::Place > > >::itable<x10_lang_Place__closure__1>x10_lang_Place__closure__1::_itable(&x10_lang_Place__closure__1::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Place__closure__1::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Place__closure__1::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::lang::ValRail<x10::lang::Place > > > >, &x10_lang_Place__closure__1::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Place__closure__1::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Place__closure__1::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10::lang::Place>::itable<x10_lang_Place__closure__2>x10_lang_Place__closure__2::_itable(&x10_lang_Place__closure__2::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Place__closure__2::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Place__closure__2::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10::lang::Place> >, &x10_lang_Place__closure__2::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Place__closure__2::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Place__closure__2::_deserialize<x10::lang::Object>);

