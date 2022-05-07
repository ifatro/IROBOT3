//
// File: minOrMax.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 06-May-2022 13:59:16
//

// Include Files
#include "minOrMax.h"
#include "PhaseCorr1.h"
#include "PhaseCorr1_rtwutil.h"
#include "relop.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions

//
// Arguments    : const creal_T x[998001]
//                creal_T ex[999]
//                int idx[999]
// Return Type  : void
//
void maximum(const creal_T x[998001], creal_T ex[999], int idx[999])
{
  int j;
  for (j = 0; j < 999; j++) {
    idx[j] = 1;
  }

  for (j = 0; j < 999; j++) {
    ex[j] = x[999 * j];
    for (int i = 0; i < 998; i++) {
      int re_tmp;
      boolean_T SCALEA;
      re_tmp = (i + 999 * j) + 1;
      if (std::isnan(x[re_tmp].re) || std::isnan(x[re_tmp].im)) {
        SCALEA = false;
      } else if (std::isnan(ex[j].re) || std::isnan(ex[j].im)) {
        SCALEA = true;
      } else {
        double ma;
        double mb;
        boolean_T SCALEB;
        double absai;
        double absbi;
        ma = std::abs(ex[j].re);
        if ((ma > 8.9884656743115785E+307) || (std::abs(ex[j].im) >
             8.9884656743115785E+307)) {
          SCALEA = true;
        } else {
          SCALEA = false;
        }

        mb = std::abs(x[re_tmp].re);
        if ((mb > 8.9884656743115785E+307) || (std::abs(x[re_tmp].im) >
             8.9884656743115785E+307)) {
          SCALEB = true;
        } else {
          SCALEB = false;
        }

        if (SCALEA || SCALEB) {
          absai = rt_hypotd_snf(ex[j].re / 2.0, ex[j].im / 2.0);
          absbi = rt_hypotd_snf(x[re_tmp].re / 2.0, x[re_tmp].im / 2.0);
        } else {
          absai = rt_hypotd_snf(ex[j].re, ex[j].im);
          absbi = rt_hypotd_snf(x[re_tmp].re, x[re_tmp].im);
        }

        if (iseq(absai, absbi)) {
          double Ma;
          double Mb;
          absai = std::abs(ex[j].im);
          absbi = std::abs(x[re_tmp].im);
          if (ma > absai) {
            Ma = ma;
            ma = absai;
          } else {
            Ma = absai;
          }

          if (mb > absbi) {
            Mb = mb;
            mb = absbi;
          } else {
            Mb = absbi;
          }

          if (Ma > Mb) {
            if (ma < mb) {
              absai = Ma - Mb;
              absbi = (ma / 2.0 + mb / 2.0) / (Ma / 2.0 + Mb / 2.0) * (mb - ma);
            } else {
              absai = Ma;
              absbi = Mb;
            }
          } else if (Ma < Mb) {
            if (ma > mb) {
              absbi = Mb - Ma;
              absai = (ma / 2.0 + mb / 2.0) / (Ma / 2.0 + Mb / 2.0) * (ma - mb);
            } else {
              absai = Ma;
              absbi = Mb;
            }
          } else {
            absai = ma;
            absbi = mb;
          }

          if (iseq(absai, absbi)) {
            absai = rt_atan2d_snf(ex[j].im, ex[j].re);
            absbi = rt_atan2d_snf(x[re_tmp].im, x[re_tmp].re);
            if (iseq(absai, absbi)) {
              if (absai > 0.78539816339744828) {
                if (absai > 2.3561944901923448) {
                  absai = -ex[j].im;
                  absbi = -x[re_tmp].im;
                } else {
                  absai = -ex[j].re;
                  absbi = -x[re_tmp].re;
                }
              } else if (absai > -0.78539816339744828) {
                absai = ex[j].im;
                absbi = x[re_tmp].im;
              } else if (absai > -2.3561944901923448) {
                absai = ex[j].re;
                absbi = x[re_tmp].re;
              } else {
                absai = -ex[j].im;
                absbi = -x[re_tmp].im;
              }

              if (iseq(absai, absbi)) {
                absai = 0.0;
                absbi = 0.0;
              }
            }
          }
        }

        SCALEA = (absai < absbi);
      }

      if (SCALEA) {
        ex[j].re = x[re_tmp].re;
        ex[j].im = x[re_tmp].im;
        idx[j] = i + 2;
      }
    }
  }
}

//
// File trailer for minOrMax.cpp
//
// [EOF]
//
