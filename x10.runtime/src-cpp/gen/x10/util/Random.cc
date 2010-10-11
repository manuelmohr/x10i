#include <x10/util/Random.h>


#include "x10/util/Random.inc"

void x10::util::Random::_instance_init() {
    _I_("Doing initialisation for class: x10::util::Random");
    
}


//#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10ConstructorDecl_c
void x10::util::Random::_constructor() {
    this->_constructor(x10aux::system_utils::currentTimeMillis());
    
}
x10aux::ref<x10::util::Random> x10::util::Random::_make() {
    x10aux::ref<x10::util::Random> this_ = new (memset(x10aux::alloc<x10::util::Random>(), 0, sizeof(x10::util::Random))) x10::util::Random();
    this_->_constructor();
    return this_;
}



//#line 20 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10ConstructorDecl_c
void x10::util::Random::_constructor(x10_long seed) {
    this->x10::lang::Object::_constructor();
    
    //#line 131 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::Random>)this))->FMGL(index) =
      ((x10_int)0);
    
    //#line 132 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::Random>)this))->FMGL(MT) =
      x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Rail<x10_int > > >(x10aux::null);
    
    //#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::Random>)this))->setSeed(seed);
    
}
x10aux::ref<x10::util::Random> x10::util::Random::_make(x10_long seed) {
    x10aux::ref<x10::util::Random> this_ = new (memset(x10aux::alloc<x10::util::Random>(), 0, sizeof(x10::util::Random))) x10::util::Random();
    this_->_constructor(seed);
    return this_;
}



//#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10MethodDecl_c
void x10::util::Random::setSeed(x10_long seed) {
    
    //#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::util::Random>)this)->init(seed);
}

//#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10MethodDecl_c
x10_int x10::util::Random::nextInt() {
    
    //#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::Random>)this)->random();
    
}

//#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10MethodDecl_c
x10_int x10::util::Random::nextInt(x10_int maxPlus1) {
    
    //#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10If_c
    if (((maxPlus1) <= (((x10_int)0)))) {
        
        //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10Return_c
        return ((x10_int)0);
        
    }
    
    //#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10LocalDecl_c
    x10_int n = maxPlus1;
    
    //#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals((((x10_int) ((n) & (((x10_int) -(n)))))), n)))
    {
        
        //#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10Return_c
        return ((x10_int) ((((x10aux::ref<x10::util::Random>)this)->nextInt()) & (((x10_int) ((n) - (((x10_int)1)))))));
        
    }
    
    //#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10LocalDecl_c
    x10_int mask = ((x10_int)1);
    
    //#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10While_c
    while ((!x10aux::struct_equals((((x10_int) ((n) & (((x10_int) ~(mask)))))),
                                   ((x10_int)0)))) {
        
        //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
        mask = ((x10_int) ((mask) << (((x10_int)1))));
        
        //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
        mask = ((x10_int) ((mask) | (((x10_int)1))));
    }
    
    //#line 52 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10LocalDecl_c
    x10_int x;
    
    //#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10Do_c
    do {
        
        //#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
        x = ((x10_int) ((((x10aux::ref<x10::util::Random>)this)->nextInt()) & (mask)));
    } while (((x) >= (n)));
    
    //#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10Return_c
    return x;
    
}

//#line 61 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10MethodDecl_c
void x10::util::Random::nextBytes(x10aux::ref<x10::lang::Rail<x10_byte > > buf) {
    
    //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10LocalDecl_c
    x10_int i = ((x10_int)0);
    
    //#line 63 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10While_c
    while (true) {
        
        //#line 64 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10LocalDecl_c
        x10_int x = ((x10aux::ref<x10::util::Random>)this)->nextInt();
        
        //#line 65 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.For_c
        {
            x10_int j;
            for (
                 //#line 65 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10LocalDecl_c
                 j = ((x10_int)0); ((j) < (((x10_int)4))); 
                                                           //#line 65 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
                                                           j = ((x10_int) ((j) + (((x10_int)1)))))
            {
                
                //#line 66 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10If_c
                if (((i) >= (x10aux::nullCheck(buf)->
                               FMGL(length))))
                {
                    
                    //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10Return_c
                    return;
                }
                
                //#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
                (buf)->set(((x10_byte) (((x10_int) ((x) & (((x10_int)255)))))), i);
                
                //#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
                i =
                  ((x10_int) ((i) + (((x10_int)1))));
                
                //#line 70 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
                x =
                  ((x10_int) ((x) >> (((x10_int)8))));
            }
        }
        
    }
    
}

//#line 76 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10MethodDecl_c
x10_long x10::util::Random::nextLong() {
    
    //#line 76 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10Return_c
    return ((x10_long) ((((x10_long) ((((x10_long) (((x10aux::ref<x10::util::Random>)this)->nextInt()))) << (((x10_int)32))))) | (((x10_long) ((((x10_long) (((x10aux::ref<x10::util::Random>)this)->nextInt()))) & (((x10_long)4294967295ll)))))));
    
}

//#line 78 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10MethodDecl_c
x10_long x10::util::Random::nextLong(x10_long maxPlus1) {
    
    //#line 79 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10If_c
    if (((maxPlus1) <= (((x10_long) (((x10_int)0)))))) {
        
        //#line 80 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10Return_c
        return ((x10_long)0ll);
        
    }
    
    //#line 82 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10LocalDecl_c
    x10_long n = maxPlus1;
    
    //#line 84 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals((((x10_long) ((n) & (((x10_long) -(n)))))),
                               n))) {
        
        //#line 86 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10Return_c
        return ((x10_long) ((((x10aux::ref<x10::util::Random>)this)->nextLong()) & (((x10_long) ((n) - (((x10_long) (((x10_int)1)))))))));
        
    }
    
    //#line 90 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10LocalDecl_c
    x10_long pow2 = ((x10_long) (((x10_int)1)));
    
    //#line 91 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10While_c
    while (((pow2) < (n))) {
        
        //#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
        pow2 = ((x10_long) ((pow2) << (((x10_int)1))));
    }
    
    //#line 96 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10LocalDecl_c
    x10_long x;
    
    //#line 98 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10Do_c
    do {
        
        //#line 99 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
        x = ((x10_long) ((((x10aux::ref<x10::util::Random>)this)->nextLong()) & (((x10_long) ((pow2) - (((x10_long) (((x10_int)1)))))))));
    } while (((x) >= (n)));
    
    //#line 102 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10Return_c
    return x;
    
}

//#line 106 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::util::Random::nextBoolean() {
    
    //#line 106 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10Return_c
    return ((((x10aux::ref<x10::util::Random>)this)->nextInt()) < (((x10_int)0)));
    
}

//#line 109 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10MethodDecl_c
x10_float x10::util::Random::nextFloat() {
    
    //#line 109 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10Return_c
    return ((((x10_float) (((x10_int) (((x10_uint) ((((x10_uint) (((x10aux::ref<x10::util::Random>)this)->nextInt()))) >> (((x10_int) ((((x10_int)32)) - (((x10_int)24)))))))))))) / (((x10_float) (((x10_int) ((((x10_int)1)) << (((x10_int)24))))))));
    
}

//#line 112 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10MethodDecl_c
x10_double x10::util::Random::nextDouble() {
    
    //#line 112 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10Return_c
    return ((((x10_double) (((x10_long) (((x10_ulong) ((((x10_ulong) (((x10aux::ref<x10::util::Random>)this)->nextLong()))) >> (((x10_int) ((((x10_int)64)) - (((x10_int)53)))))))))))) / (((x10_double) (((x10_long) ((((x10_long)1ll)) << (((x10_int)53))))))));
    
}

//#line 128 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10FieldDecl_c
x10_int x10::util::Random::FMGL(N) = ((x10_int)624);


//#line 129 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10FieldDecl_c
x10_int x10::util::Random::FMGL(M) = ((x10_int)397);


//#line 131 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10FieldDecl_c

//#line 132 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10FieldDecl_c

//#line 134 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10MethodDecl_c
void x10::util::Random::init(x10_long seed) {
    
    //#line 135 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Rail<x10_int > > mt = x10::lang::Rail<void>::make<x10_int >(x10::util::Random::
                                                                                         FMGL(N__get)());
    
    //#line 136 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::util::Random>)this)->FMGL(MT) = mt;
    
    //#line 138 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(seed, ((x10_long)0ll)))) {
        
        //#line 139 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::util::Random>)this)->init(((x10_long)4357ll));
        
        //#line 140 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10Return_c
        return;
    }
    
    //#line 145 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
    (mt)->set(((x10_int) (seed)), ((x10_int)0));
    
    //#line 146 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 146 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)1); ((i) < (x10::util::Random::
                                         FMGL(N__get)()));
             
             //#line 146 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1))))) {
            
            //#line 147 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
            (mt)->set(((x10_int) (((x10_long) ((((x10_long) ((((x10_long)69069ll)) * (((x10_long) ((mt)->apply(((x10_int) ((i) - (((x10_int)1))))))))))) + (((x10_long) (((x10_int)1)))))))), i);
        }
    }
    
    //#line 151 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::util::Random>)this)->FMGL(index) =
      ((x10_int)0);
    
    //#line 152 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
    x10::util::Random::twist(mt);
}

//#line 155 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10MethodDecl_c
x10_int x10::util::Random::random() {
    
    //#line 156 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(((x10aux::ref<x10::util::Random>)this)->
                                 FMGL(index), x10::util::Random::
                                                FMGL(N__get)())))
    {
        
        //#line 157 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::util::Random>)this)->
          FMGL(index) =
          ((x10_int)0);
        
        //#line 158 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
        x10::util::Random::twist(
          ((x10aux::ref<x10::util::Random>)this)->
            FMGL(MT));
    }
    
    //#line 160 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::util::Random>)this)->FMGL(MT))->apply(((x10_int) (((__extension__ ({
        x10aux::ref<x10::util::Random> x = ((x10aux::ref<x10::util::Random>)this);
        x10_int y = ((x10_int)1);
        x10aux::nullCheck(x)->FMGL(index) = ((x10_int) ((x10aux::nullCheck(x)->
                                                           FMGL(index)) + (y)));
    }))
    ) - (((x10_int)1)))));
    
}

//#line 163 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10MethodDecl_c
void x10::util::Random::twist(x10aux::ref<x10::lang::Rail<x10_int > > MT) {
    
    //#line 164 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10LocalDecl_c
    x10_int i = ((x10_int)0);
    
    //#line 165 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": x10.ast.X10LocalDecl_c
    x10_int s;
    
    //#line 166 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.For_c
    {
        for (; ((i) < (((x10_int) ((x10::util::Random::FMGL(N__get)()) - (x10::util::Random::
                                                                            FMGL(M__get)())))));
             
             //#line 166 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 167 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
            s =
              ((x10_int) ((((x10_int) (((MT)->apply(i)) & (((x10_int)0x80000000u))))) | (((x10_int) (((MT)->apply(((x10_int) ((i) + (((x10_int)1)))))) & (((x10_int)2147483647)))))));
            
            //#line 168 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
            (MT)->set(((x10_int) ((((x10_int) (((MT)->apply(((x10_int) ((i) + (x10::util::Random::
                                                                                 FMGL(M__get)()))))) ^ (((x10_int) ((s) >> (((x10_int)1)))))))) ^ (((x10_int) ((((x10_int) ((s) & (((x10_int)1))))) * (((x10_int)0x9908B0DFu))))))), i);
        }
    }
    
    //#line 170 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.For_c
    {
        for (; ((i) < (((x10_int) ((x10::util::Random::
                                      FMGL(N__get)()) - (((x10_int)1))))));
             
             //#line 170 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 171 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
            s =
              ((x10_int) ((((x10_int) (((MT)->apply(i)) & (((x10_int)0x80000000u))))) | (((x10_int) (((MT)->apply(((x10_int) ((i) + (((x10_int)1)))))) & (((x10_int)2147483647)))))));
            
            //#line 172 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
            (MT)->set(((x10_int) ((((x10_int) (((MT)->apply(((x10_int) ((i) - (((x10_int) ((x10::util::Random::
                                                                                              FMGL(N__get)()) - (x10::util::Random::
                                                                                                                   FMGL(M__get)())))))))) ^ (((x10_int) ((s) >> (((x10_int)1)))))))) ^ (((x10_int) ((((x10_int) ((s) & (((x10_int)1))))) * (((x10_int)0x9908B0DFu))))))), i);
        }
    }
    
    //#line 175 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
    s = ((x10_int) ((((x10_int) (((MT)->apply(((x10_int) ((x10::util::Random::
                                                             FMGL(N__get)()) - (((x10_int)1)))))) & (((x10_int)0x80000000u))))) | (((x10_int) (((MT)->apply(((x10_int)0))) & (((x10_int)2147483647)))))));
    
    //#line 176 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Random.x10": polyglot.ast.Eval_c
    (MT)->set(((x10_int) ((((x10_int) (((MT)->apply(((x10_int) ((x10::util::Random::
                                                                   FMGL(M__get)()) - (((x10_int)1)))))) ^ (((x10_int) ((s) >> (((x10_int)1)))))))) ^ (((x10_int) ((((x10_int) ((s) & (((x10_int)1))))) * (((x10_int)0x9908B0DFu))))))), ((x10_int) ((x10::util::Random::
                                                                                                                                                                                                                                                       FMGL(N__get)()) - (((x10_int)1)))));
}
const x10aux::serialization_id_t x10::util::Random::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::util::Random::_deserializer<x10::lang::Object>);

void x10::util::Random::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::util::Random::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::util::Random::rtt;
void x10::util::Random::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.util.Random", 1, parents, 0, NULL, NULL);
}
