#ifndef __X10_LANG_PLACE_H
#define __X10_LANG_PLACE_H

#include <x10rt.h>


#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace compiler { 
class Native;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
class BadPlaceException;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
class ClassCastException;
} } 
namespace x10 { namespace lang { 
class String;
} } 
namespace x10 { namespace lang { 
class Object;
} } 
#include <x10/lang/Place.struct_h>

namespace x10 { namespace lang { 

class Place_methods  {
    public:
    static void _instance_init(x10::lang::Place& this_);
    
    static x10_int FMGL(ALL_PLACES);
    
    static inline x10_int FMGL(ALL_PLACES__get)() {
        return x10::lang::Place_methods::FMGL(ALL_PLACES);
    }
    static x10_int FMGL(MAX_PLACES);
    
    static inline x10_int FMGL(MAX_PLACES__get)() {
        return x10::lang::Place_methods::FMGL(MAX_PLACES);
    }
    static x10_int numChildren(x10_int id);
    static x10_boolean isHost(x10_int id);
    static x10_boolean isSPE(x10_int id);
    static x10_boolean isCUDA(x10_int id);
    static x10_int parent(x10_int id);
    static x10_int child(x10_int p, x10_int i);
    static x10_int childIndex(x10_int id);
    static x10aux::ref<x10::lang::ValRail<x10::lang::Place > > FMGL(places);
    
    static void FMGL(places__do_init)();
    static void FMGL(places__init)();
    static volatile x10aux::status FMGL(places__status);
    static inline x10aux::ref<x10::lang::ValRail<x10::lang::Place > > FMGL(places__get)() {
        if (FMGL(places__status) != x10aux::INITIALIZED) {
            FMGL(places__init)();
        }
        return x10::lang::Place_methods::FMGL(places);
    }
    static x10aux::ref<x10::lang::Object> FMGL(places__deserialize)(x10aux::deserialization_buffer &buf);
    static const x10aux::serialization_id_t FMGL(places__id);
    
    static x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::ValRail<x10::lang::Place > > > >
      FMGL(children);
    
    static void FMGL(children__do_init)();
    static void FMGL(children__init)();
    static volatile x10aux::status FMGL(children__status);
    static inline x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::ValRail<x10::lang::Place > > > >
      FMGL(children__get)() {
        if (FMGL(children__status) != x10aux::INITIALIZED) {
            FMGL(children__init)();
        }
        return x10::lang::Place_methods::FMGL(children);
    }
    static x10aux::ref<x10::lang::Object>
      FMGL(children__deserialize)(x10aux::deserialization_buffer &buf);
    static const x10aux::serialization_id_t FMGL(children__id);
    
    static x10_int
      FMGL(NUM_ACCELS);
    
    static void FMGL(NUM_ACCELS__do_init)();
    static void FMGL(NUM_ACCELS__init)();
    static volatile x10aux::status FMGL(NUM_ACCELS__status);
    static inline x10_int
      FMGL(NUM_ACCELS__get)() {
        if (FMGL(NUM_ACCELS__status) != x10aux::INITIALIZED) {
            FMGL(NUM_ACCELS__init)();
        }
        return x10::lang::Place_methods::FMGL(NUM_ACCELS);
    }
    static x10aux::ref<x10::lang::Object>
      FMGL(NUM_ACCELS__deserialize)(x10aux::deserialization_buffer &buf);
    static const x10aux::serialization_id_t FMGL(NUM_ACCELS__id);
    
    static x10::lang::Place
      FMGL(FIRST_PLACE);
    
    static void FMGL(FIRST_PLACE__do_init)();
    static void FMGL(FIRST_PLACE__init)();
    static volatile x10aux::status FMGL(FIRST_PLACE__status);
    static inline x10::lang::Place
      FMGL(FIRST_PLACE__get)() {
        if (FMGL(FIRST_PLACE__status) != x10aux::INITIALIZED) {
            FMGL(FIRST_PLACE__init)();
        }
        return x10::lang::Place_methods::FMGL(FIRST_PLACE);
    }
    static x10aux::ref<x10::lang::Object>
      FMGL(FIRST_PLACE__deserialize)(x10aux::deserialization_buffer &buf);
    static const x10aux::serialization_id_t FMGL(FIRST_PLACE__id);
    
    static void _constructor(
      x10::lang::Place& this_, x10_int id)
    {
        
        //#line 90 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": polyglot.ast.Eval_c
        this_->
          FMGL(id) =
          id;
        
    }
    inline static x10::lang::Place _make(
             x10_int id)
    {
        x10::lang::Place this_; 
        _constructor(this_, id);
        return this_;
    }
    
    static x10::lang::Place
      place(
      x10_int id) {
        
        //#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
        return x10::lang::Place_methods::_make(id);
        
    }
    static x10::lang::Place
      next(
      x10::lang::Place this_) {
        
        //#line 93 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
        return x10::lang::Place_methods::next(this_, 
                 ((x10_int)1));
        
    }
    static x10::lang::Place
      prev(
      x10::lang::Place this_) {
        
        //#line 94 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
        return x10::lang::Place_methods::next(this_, 
                 ((x10_int)-1));
        
    }
    static x10::lang::Place
      prev(
      x10::lang::Place this_, x10_int i) {
        
        //#line 95 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
        return x10::lang::Place_methods::next(this_, 
                 ((x10_int) -(i)));
        
    }
    static x10::lang::Place
      next(
      x10::lang::Place this_, x10_int i) {
        
        //#line 98 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10If_c
        if (x10aux::is_host(this_->
                              FMGL(id)))
        {
            
            //#line 99 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10LocalDecl_c
            x10_int k =
              ((x10_int) ((((x10_int) ((((x10_int) ((this_->
                                                       FMGL(id)) + (((x10_int) ((i) % (x10aux::num_hosts))))))) + (x10aux::num_hosts)))) % (x10aux::num_hosts)));
            
            //#line 100 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
            return x10::lang::Place_methods::place(
                     k);
            
        }
        
        //#line 103 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
        return this_;
        
    }
    static x10_boolean
      isFirst(
      x10::lang::Place this_) {
        
        //#line 106 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
        return (x10aux::struct_equals(this_->
                                        FMGL(id),
                                      ((x10_int)0)));
        
    }
    static x10_boolean
      isLast(
      x10::lang::Place this_) {
        
        //#line 107 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
        return (x10aux::struct_equals(this_->
                                        FMGL(id),
                                      ((x10_int) ((x10aux::num_hosts) - (((x10_int)1))))));
        
    }
    static x10_boolean
      isHost(
      x10::lang::Place this_) {
        
        //#line 109 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
        return x10aux::is_host(this_->
                                 FMGL(id));
        
    }
    static x10_boolean
      isSPE(
      x10::lang::Place this_) {
        
        //#line 110 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
        return x10aux::is_spe(this_->
                                FMGL(id));
        
    }
    static x10_boolean
      isCUDA(
      x10::lang::Place this_) {
        
        //#line 111 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
        return x10aux::is_cuda(this_->
                                 FMGL(id));
        
    }
    static x10_int
      numChildren(
      x10::lang::Place this_) {
        
        //#line 113 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
        return x10aux::num_children(this_->
                                      FMGL(id));
        
    }
    static x10::lang::Place
      child(
      x10::lang::Place this_, x10_int i) {
        
        //#line 114 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
        return x10::lang::Place_methods::_make(x10aux::child(this_->
                                                               FMGL(id),i));
        
    }
    static x10aux::ref<x10::lang::ValRail<x10::lang::Place > >
      children(
      x10::lang::Place this_);
    static x10::lang::Place
      parent(
      x10::lang::Place this_);
    static x10_int
      childIndex(
      x10::lang::Place this_);
    static x10aux::ref<x10::lang::String>
      toString(
      x10::lang::Place this_);
    static x10_boolean
      equals(
      x10::lang::Place this_, x10::lang::Place p) {
        
        //#line 128 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
        return (x10aux::struct_equals(p->
                                        FMGL(id),
                                      this_->
                                        FMGL(id)));
        
    }
    static x10_boolean
      equals(
      x10::lang::Place this_, x10aux::ref<x10::lang::Any> p);
    static x10_int
      hashCode(
      x10::lang::Place this_) {
        
        //#line 130 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
        return this_->
                 FMGL(id);
        
    }
    static x10_int
      id(
      x10::lang::Place this_) {
        
        //#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
        return this_->
                 FMGL(id);
        
    }
    static x10_boolean
      _struct_equals(
      x10::lang::Place this_, x10aux::ref<x10::lang::Any> other);
    static x10_boolean
      _struct_equals(
      x10::lang::Place this_, x10::lang::Place other) {
        
        //#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
        return (x10aux::struct_equals(this_->
                                        FMGL(id),
                                      other->
                                        FMGL(id)));
        
    }
    
};

} } 
#endif // X10_LANG_PLACE_H

namespace x10 { namespace lang { 
class Place;
} } 

#ifndef X10_LANG_PLACE_H_NODEPS
#define X10_LANG_PLACE_H_NODEPS
#include <x10/lang/Any.h>
#include <x10/lang/Any.h>
#include <x10/lang/Int.h>
#include <x10/compiler/Native.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/BadPlaceException.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/ClassCastException.h>
#include <x10/lang/String.h>
#include <x10/lang/Object.h>
#ifndef X10_LANG_PLACE_H_GENERICS
#define X10_LANG_PLACE_H_GENERICS
#endif // X10_LANG_PLACE_H_GENERICS
#endif // __X10_LANG_PLACE_H_NODEPS
