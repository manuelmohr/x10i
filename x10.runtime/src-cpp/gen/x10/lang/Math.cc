#include <x10/lang/Math.h>


#include "x10/lang/Math.inc"

void x10::lang::Math::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Math");
    
}


//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10FieldDecl_c
x10_double x10::lang::Math::FMGL(E) = 2.718281828459045;


//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10FieldDecl_c
x10_double x10::lang::Math::FMGL(PI) = 3.141592653589793;


//#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10_double x10::lang::Math::abs(x10_double a) {
    
    //#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
    return ((a) <= (0.0)) ? (x10_double)(((0.0) - (a))) : (x10_double)(a);
    
}

//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10_int x10::lang::Math::abs(x10_int a) {
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
    return ((a) < (((x10_int)0))) ? (x10_int)(((x10_int) -(a))) : (x10_int)(a);
    
}

//#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10_float x10::lang::Math::abs(x10_float a) {
    
    //#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
    return ((a) <= (0.0f)) ? (x10_float)(((0.0f) - (a))) : (x10_float)(a);
    
}

//#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10_long x10::lang::Math::abs(x10_long a) {
    
    //#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
    return ((a) < (((x10_long)0ll))) ? (x10_long)(((x10_long) -(a))) : (x10_long)(a);
    
}

//#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 52 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10::lang::Complex x10::lang::Math::pow(x10::lang::Complex a, x10::lang::Complex b) {
    
    //#line 52 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
    return x10::lang::Math::exp(x10::lang::Complex_methods::__times(x10::lang::Math::log(
                                                                      a), 
                                  b));
    
}

//#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 59 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10::lang::Complex x10::lang::Math::exp(x10::lang::Complex a) {
    
    //#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10If_c
    if (x10::lang::Complex_methods::isNaN(a)) {
        
        //#line 70 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::FMGL(NaN__get)();
        
    }
    
    //#line 72 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10LocalDecl_c
    x10_double expRe = x10aux::math_utils::exp(a->FMGL(re));
    
    //#line 73 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
    return x10::lang::Complex_methods::_make(((expRe) * (x10aux::math_utils::cos(a->
                                                                                   FMGL(im)))),
                                             ((expRe) * (x10aux::math_utils::sin(a->
                                                                                   FMGL(im)))));
    
}

//#line 76 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 80 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10::lang::Complex x10::lang::Math::cos(x10::lang::Complex z) {
    
    //#line 89 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(z->FMGL(im),
                               0.0))) {
        
        //#line 90 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::_make(x10aux::math_utils::cos(z->
                                                                           FMGL(re)),
                                                 0.0);
        
    } else {
        
        //#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::_make(((x10aux::math_utils::cos(z->
                                                                             FMGL(re))) * (x10aux::math_utils::cosh(z->
                                                                                                                      FMGL(im)))),
                                                 ((x10aux::math_utils::sin(z->
                                                                             FMGL(re))) * (x10aux::math_utils::sinh((-(z->
                                                                                                                         FMGL(im)))))));
        
    }
    
}

//#line 96 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 104 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10::lang::Complex x10::lang::Math::sin(x10::lang::Complex z) {
    
    //#line 105 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(z->FMGL(im),
                               0.0))) {
        
        //#line 106 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::_make(x10aux::math_utils::sin(z->
                                                                           FMGL(re)),
                                                 0.0);
        
    } else {
        
        //#line 108 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::_make(((x10aux::math_utils::sin(z->
                                                                             FMGL(re))) * (x10aux::math_utils::cosh(z->
                                                                                                                      FMGL(im)))),
                                                 ((x10aux::math_utils::cos(z->
                                                                             FMGL(re))) * (x10aux::math_utils::sinh(z->
                                                                                                                      FMGL(im)))));
        
    }
    
}

//#line 112 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 120 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10::lang::Complex x10::lang::Math::tan(x10::lang::Complex z) {
    
    //#line 121 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(z->FMGL(im),
                               0.0))) {
        
        //#line 122 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::_make(x10aux::math_utils::tan(z->
                                                                           FMGL(re)),
                                                 0.0);
        
    } else {
        
        //#line 125 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10LocalDecl_c
        x10::lang::Complex e2IZ = x10::lang::Math::exp(
                                    x10::lang::Complex_methods::__times(x10::lang::Complex_methods::__times(
                                                                          2.0,
                                                                          x10::lang::Complex_methods::
                                                                            FMGL(I__get)()), 
                                      z));
        
        //#line 126 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::__over(x10::lang::Complex_methods::__minus(e2IZ, 
                                                    1.0), 
                 x10::lang::Complex_methods::__times(x10::lang::Complex_methods::
                                                       FMGL(I__get)(), 
                   x10::lang::Complex_methods::__plus(e2IZ, 
                     1.0)));
        
    }
    
}

//#line 130 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 141 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10::lang::Complex x10::lang::Math::acos(
  x10::lang::Complex z) {
    
    //#line 142 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(z->FMGL(im),
                               0.0)) && ((x10::lang::Math::abs(
                                            z->
                                              FMGL(re))) <= (1.0)))
    {
        
        //#line 143 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::_make(x10aux::math_utils::acos(z->
                                                                            FMGL(re)),
                                                 0.0);
        
    }
    else
    {
        
        //#line 146 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::__plus(
                 ((x10::lang::Math::
                     FMGL(PI__get)()) / (2.0)),
                 x10::lang::Complex_methods::__times(x10::lang::Complex_methods::
                                                       FMGL(I__get)(), 
                   x10::lang::Math::log(
                     x10::lang::Complex_methods::__plus(x10::lang::Complex_methods::__times(x10::lang::Complex_methods::
                                                                                              FMGL(I__get)(), 
                                                          z), 
                       x10::lang::Math::sqrt(
                         x10::lang::Complex_methods::__minus(
                           1.0,
                           x10::lang::Complex_methods::__times(z, 
                             z)))))));
        
    }
    
}

//#line 150 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 161 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10::lang::Complex x10::lang::Math::asin(
  x10::lang::Complex z) {
    
    //#line 162 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(z->FMGL(im),
                               0.0)) && ((x10::lang::Math::abs(
                                            z->
                                              FMGL(re))) <= (1.0)))
    {
        
        //#line 163 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::_make(x10aux::math_utils::asin(z->
                                                                            FMGL(re)),
                                                 0.0);
        
    }
    else
    {
        
        //#line 166 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::__times(x10::lang::Complex_methods::__minus(x10::lang::Complex_methods::
                                                                                         FMGL(I__get)()), 
                 x10::lang::Math::log(
                   x10::lang::Complex_methods::__plus(x10::lang::Complex_methods::__times(x10::lang::Complex_methods::
                                                                                            FMGL(I__get)(), 
                                                        z), 
                     x10::lang::Math::sqrt(
                       x10::lang::Complex_methods::__minus(
                         1.0,
                         x10::lang::Complex_methods::__times(z, 
                           z))))));
        
    }
    
}

//#line 170 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 181 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10::lang::Complex x10::lang::Math::atan(
  x10::lang::Complex z) {
    
    //#line 182 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(z->FMGL(im),
                               0.0))) {
        
        //#line 183 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::_make(x10aux::math_utils::atan(z->
                                                                            FMGL(re)),
                                                 0.0);
        
    } else 
    //#line 184 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(z, x10::lang::Complex_methods::
                                    FMGL(I__get)())))
    {
        
        //#line 185 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::_make(0.0,
                                                 x10aux::double_utils::fromLongBits(0x7ff0000000000000LL));
        
    }
    else
    
    //#line 186 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(z,
                               x10::lang::Complex_methods::__minus(x10::lang::Complex_methods::
                                                                     FMGL(I__get)()))))
    {
        
        //#line 187 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::_make(0.0,
                                                 x10aux::double_utils::fromLongBits(0xfff0000000000000LL));
        
    }
    else
    {
        
        //#line 190 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::__times(x10::lang::Complex_methods::__over(x10::lang::Complex_methods::
                                                                                        FMGL(I__get)(), 
                                                     2.0), 
                 x10::lang::Complex_methods::__minus(x10::lang::Math::log(
                                                       x10::lang::Complex_methods::__minus(
                                                         1.0,
                                                         x10::lang::Complex_methods::__times(x10::lang::Complex_methods::
                                                                                               FMGL(I__get)(), 
                                                           z))), 
                   x10::lang::Math::log(
                     x10::lang::Complex_methods::__plus(
                       1.0,
                       x10::lang::Complex_methods::__times(x10::lang::Complex_methods::
                                                             FMGL(I__get)(), 
                         z)))));
        
    }
    
}

//#line 194 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 198 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 206 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10::lang::Complex x10::lang::Math::cosh(
  x10::lang::Complex z) {
    
    //#line 207 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10If_c
    if (x10::lang::Complex_methods::isNaN(z))
    {
        
        //#line 208 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::
                 FMGL(NaN__get)();
        
    }
    else
    
    //#line 209 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(z->
                                 FMGL(im),
                               0.0)))
    {
        
        //#line 210 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::_make(x10aux::math_utils::cosh(z->
                                                                            FMGL(re)),
                                                 0.0);
        
    }
    else
    {
        
        //#line 212 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::_make(((x10aux::math_utils::cosh(z->
                                                                              FMGL(re))) * (x10aux::math_utils::cos(z->
                                                                                                                      FMGL(im)))),
                                                 ((x10aux::math_utils::sinh(z->
                                                                              FMGL(re))) * (x10aux::math_utils::sin(z->
                                                                                                                      FMGL(im)))));
        
    }
    
}

//#line 216 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 224 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10::lang::Complex x10::lang::Math::sinh(
  x10::lang::Complex z) {
    
    //#line 225 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10If_c
    if (x10::lang::Complex_methods::isNaN(z))
    {
        
        //#line 226 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::
                 FMGL(NaN__get)();
        
    }
    else
    
    //#line 227 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(z->
                                 FMGL(im),
                               0.0)))
    {
        
        //#line 228 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::_make(x10aux::math_utils::sinh(z->
                                                                            FMGL(re)),
                                                 0.0);
        
    }
    else
    {
        
        //#line 230 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::_make(((x10aux::math_utils::sinh(z->
                                                                              FMGL(re))) * (x10aux::math_utils::cos(z->
                                                                                                                      FMGL(im)))),
                                                 ((x10aux::math_utils::cosh(z->
                                                                              FMGL(re))) * (x10aux::math_utils::sin(z->
                                                                                                                      FMGL(im)))));
        
    }
    
}

//#line 234 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 242 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10::lang::Complex x10::lang::Math::tanh(
  x10::lang::Complex z) {
    
    //#line 243 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10If_c
    if (x10::lang::Complex_methods::isNaN(z))
    {
        
        //#line 244 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::
                 FMGL(NaN__get)();
        
    }
    
    //#line 246 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10LocalDecl_c
    x10_double d = ((x10aux::math_utils::cosh(((2.0) * (z->
                                                          FMGL(re))))) + (x10aux::math_utils::cos(((2.0) * (z->
                                                                                                              FMGL(im))))));
    
    //#line 247 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
    return x10::lang::Complex_methods::_make(((x10aux::math_utils::sinh(((2.0) * (z->
                                                                                    FMGL(re))))) / (d)),
                                             ((x10aux::math_utils::sin(((2.0) * (z->
                                                                                   FMGL(im))))) / (d)));
    
}

//#line 250 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 260 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10::lang::Complex x10::lang::Math::sqrt(
  x10::lang::Complex z) {
    
    //#line 261 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10If_c
    if (x10::lang::Complex_methods::isNaN(z))
    {
        
        //#line 262 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::
                 FMGL(NaN__get)();
        
    }
    else
    
    //#line 263 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(z,
                               x10::lang::Complex_methods::
                                 FMGL(ZERO__get)())))
    {
        
        //#line 264 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::
                 FMGL(ZERO__get)();
        
    }
    else
    {
        
        //#line 266 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10LocalDecl_c
        x10_double t =
          x10aux::math_utils::sqrt(((((x10::lang::Math::abs(
                                         z->
                                           FMGL(re))) + (x10::lang::Complex_methods::abs(z)))) / (2.0)));
        
        //#line 267 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10If_c
        if (((z->
                FMGL(re)) >= (0.0)))
        {
            
            //#line 268 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
            return x10::lang::Complex_methods::_make(t,
                                                     ((z->
                                                         FMGL(im)) / (((2.0) * (t)))));
            
        }
        else
        {
            
            //#line 270 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
            return x10::lang::Complex_methods::_make(((x10::lang::Math::abs(
                                                         z->
                                                           FMGL(im))) / (((2.0) * (t)))),
                                                     x10aux::math_utils::copysign(t,z->
                                                                                      FMGL(im)));
            
        }
        
    }
    
}

//#line 276 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 281 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 286 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 291 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 295 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 299 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 304 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 315 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10::lang::Complex x10::lang::Math::log(x10::lang::Complex a) {
    
    //#line 316 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10If_c
    if (x10::lang::Complex_methods::isNaN(a))
    {
        
        //#line 317 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::
                 FMGL(NaN__get)();
        
    }
    
    //#line 319 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
    return x10::lang::Complex_methods::_make(x10aux::math_utils::log(x10::lang::Complex_methods::abs(a)),
                                             x10aux::math_utils::atan2(a->
                                                                         FMGL(im),a->
                                                                                    FMGL(re)));
    
}

//#line 322 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 326 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 331 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10_int x10::lang::Math::max(x10_int a, x10_int b) {
    
    //#line 331 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
    return ((a) < (b)) ? (x10_int)(b) : (x10_int)(a);
    
}

//#line 332 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10_int x10::lang::Math::min(x10_int a, x10_int b) {
    
    //#line 332 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
    return ((a) < (b)) ? (x10_int)(a) : (x10_int)(b);
    
}

//#line 335 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10_long x10::lang::Math::max(x10_long a,
                              x10_long b) {
    
    //#line 335 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
    return ((a) < (b)) ? (x10_long)(b) : (x10_long)(a);
    
}

//#line 336 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10_long x10::lang::Math::min(x10_long a,
                              x10_long b) {
    
    //#line 336 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
    return ((a) < (b)) ? (x10_long)(a) : (x10_long)(b);
    
}

//#line 339 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10_float x10::lang::Math::max(x10_float a,
                               x10_float b) {
    
    //#line 339 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
    return ((a) < (b)) ? (x10_float)(b) : (x10_float)(a);
    
}

//#line 340 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10_float x10::lang::Math::min(x10_float a,
                               x10_float b) {
    
    //#line 340 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
    return ((a) < (b)) ? (x10_float)(a) : (x10_float)(b);
    
}

//#line 341 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10_double x10::lang::Math::max(x10_double a,
                                x10_double b) {
    
    //#line 341 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
    return ((a) < (b)) ? (x10_double)(b) : (x10_double)(a);
    
}

//#line 342 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10_double x10::lang::Math::min(x10_double a,
                                x10_double b) {
    
    //#line 342 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
    return ((a) < (b)) ? (x10_double)(a) : (x10_double)(b);
    
}

//#line 347 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c

//#line 351 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10_int x10::lang::Math::nextPowerOf2(x10_int p) {
    
    //#line 352 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(p, ((x10_int)0))))
    {
        
        //#line 352 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
        return ((x10_int)0);
        
    }
    
    //#line 353 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10LocalDecl_c
    x10_int pow2 = ((x10_int)1);
    
    //#line 354 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10While_c
    while (((pow2) < (p))) {
        
        //#line 355 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": polyglot.ast.Eval_c
        pow2 = ((x10_int) ((pow2) << (((x10_int)1))));
    }
    
    //#line 356 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
    return pow2;
    
}

//#line 359 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::lang::Math::powerOf2(x10_int p) {
    
    //#line 360 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
    return (x10aux::struct_equals((((x10_int) ((p) & (((x10_int) -(p)))))),
                                  p));
    
}

//#line 362 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10_int x10::lang::Math::log2(x10_int p) {
    
    //#line 363 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": polyglot.ast.Assert_c
    #ifndef NO_ASSERTIONS
    if (x10aux::x10__assertions_enabled)
        x10aux::x10__assert(x10::lang::Math::powerOf2(
                              p));
    #endif//NO_ASSERTIONS
    
    //#line 364 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10LocalDecl_c
    x10_int i = ((x10_int)0);
    
    //#line 365 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10While_c
    while (((p) > (((x10_int)1)))) {
        
        //#line 365 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": polyglot.ast.Eval_c
        p = ((x10_int) ((p) / (((x10_int)2))));
        
        //#line 365 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": polyglot.ast.Eval_c
        i = ((x10_int) ((i) + (((x10_int)1))));
    }
    
    //#line 366 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
    return i;
    
}

//#line 369 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10MethodDecl_c
x10_int x10::lang::Math::pow2(x10_int i) {
    
    //#line 370 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10Return_c
    return ((x10_int) ((((x10_int)1)) << (i)));
    
}

//#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Math.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::Math::_constructor() {
    this->x10::lang::Object::_constructor();
    
}
x10aux::ref<x10::lang::Math> x10::lang::Math::_make(
  ) {
    x10aux::ref<x10::lang::Math> this_ = new (memset(x10aux::alloc<x10::lang::Math>(), 0, sizeof(x10::lang::Math))) x10::lang::Math();
    this_->_constructor();
    return this_;
}


const x10aux::serialization_id_t x10::lang::Math::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::Math::_deserializer<x10::lang::Object>);

void x10::lang::Math::_serialize(x10aux::ref<x10::lang::Math> this_,
                                 x10aux::serialization_buffer& buf) {
    _serialize_reference(this_, buf);
    if (this_ != x10aux::null) {
        this_->_serialize_body(buf);
    }
}

void x10::lang::Math::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::lang::Math::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::Math::rtt;
void x10::lang::Math::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.lang.Math", 1, parents, 0, NULL, NULL);
}
