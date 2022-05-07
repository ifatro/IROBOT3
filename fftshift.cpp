//
// File: fftshift.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 06-May-2022 13:59:16
//

// Include Files
#include "fftshift.h"
#include "PhaseCorr1.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : creal_T x[998001]
// Return Type  : void
//
void fftshift(creal_T x[998001])
{
  int vstride;
  int npages;
  int i2;
  int ia;
  for (int dim = 0; dim < 2; dim++) {
    int k;
    int vspread;
    int midoffset;
    vstride = 1;
    for (k = 0; k < dim; k++) {
      vstride *= 999;
    }

    npages = 1;
    vspread = dim + 2;
    for (k = vspread; k < 3; k++) {
      npages *= 999;
    }

    vspread = 998 * vstride;
    midoffset = 499 * vstride - 1;
    i2 = 0;
    for (int i = 0; i < npages; i++) {
      int i1;
      i1 = i2;
      i2 += vspread;
      for (int j = 0; j < vstride; j++) {
        int ib;
        double xtmp_re;
        double xtmp_im;
        i1++;
        i2++;
        ia = i1 - 1;
        ib = i1 + midoffset;
        xtmp_re = x[ib].re;
        xtmp_im = x[ib].im;
        for (k = 0; k < 499; k++) {
          int ic;
          ic = ib + vstride;
          x[ib] = x[ia];
          x[ia] = x[ic];
          ia += vstride;
          ib = ic;
        }

        x[ib].re = xtmp_re;
        x[ib].im = xtmp_im;
      }
    }
  }
}

//
// File trailer for fftshift.cpp
//
// [EOF]
//
