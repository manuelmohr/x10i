#include <x10/array/DistArray.h>

x10aux::RuntimeType x10::array::DistArray<void>::rtt;
x10::array::RectLayout x10::array::DistArray<void>::layout(x10aux::ref<x10::array::Region> r)
{
    
    //#line 405 "/home/tux/workspace/x10.runtime/src-x10/x10/array/DistArray.x10": x10.ast.X10If_c
    if (x10aux::nullCheck(r)->isEmpty())
    {
        
        //#line 407 "/home/tux/workspace/x10.runtime/src-x10/x10/array/DistArray.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10_int > > min =
          x10::lang::ValRail<x10_int >::make(x10aux::nullCheck(r)->
                                               FMGL(rank), x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_DistArray__closure__10>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_DistArray__closure__10)))x10_array_DistArray__closure__10()))));
        
        //#line 408 "/home/tux/workspace/x10.runtime/src-x10/x10/array/DistArray.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10_int > > max =
          x10::lang::ValRail<x10_int >::make(x10aux::nullCheck(r)->
                                               FMGL(rank), x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_DistArray__closure__11>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_DistArray__closure__11)))x10_array_DistArray__closure__11()))));
        
        //#line 409 "/home/tux/workspace/x10.runtime/src-x10/x10/array/DistArray.x10": x10.ast.X10Return_c
        return x10::array::RectLayout_methods::_make(min,
                                                     max);
        
    }
    else
    {
        
        //#line 411 "/home/tux/workspace/x10.runtime/src-x10/x10/array/DistArray.x10": x10.ast.X10Return_c
        return x10::array::RectLayout_methods::_make(x10aux::nullCheck(r)->min(),
                                                     x10aux::nullCheck(r)->max());
        
    }
    
}

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_DistArray__closure__10>x10_array_DistArray__closure__10::_itable(&x10_array_DistArray__closure__10::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_DistArray__closure__10::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_DistArray__closure__10::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_DistArray__closure__10::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_DistArray__closure__10::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_DistArray__closure__10::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_DistArray__closure__11>x10_array_DistArray__closure__11::_itable(&x10_array_DistArray__closure__11::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_DistArray__closure__11::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_DistArray__closure__11::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_DistArray__closure__11::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_DistArray__closure__11::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_DistArray__closure__11::_deserialize<x10::lang::Object>);

