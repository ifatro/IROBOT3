//
// File: relop.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 06-May-2022 13:59:16
//

// Include Files
#include "relop.h"
#include "PhaseCorr1.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <math.h>

// Function Definitions

//
// Arguments    : double x
//                double y
// Return Type  : boolean_T
//
boolean_T iseq(double x, double y)
{
  boolean_T p;
  double absx;
  int exponent;
  absx = std::abs(y / 2.0);
  if ((!std::isinf(absx)) && (!std::isnan(absx))) {
    if (absx <= 2.2250738585072014E-308) {
      absx = 4.94065645841247E-324;
    } else {
      frexp(absx, &exponent);
      absx = std::ldexp(1.0, exponent - 53);
    }
  } else {
    absx = rtNaN;
  }

  if ((std::abs(y - x) < absx) || (std::isinf(x) && std::isinf(y) && ((x > 0.0) ==
        (y > 0.0)))) {
    p = true;
  } else {
    p = false;
  }

  return p;
}

//
// File trailer for relop.cpp
//
// [EOF]
//
