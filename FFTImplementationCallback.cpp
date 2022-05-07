//
// File: FFTImplementationCallback.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 06-May-2022 13:59:16
//

// Include Files
#include "FFTImplementationCallback.h"
#include "PhaseCorr1.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <cstring>

// Function Definitions

//
// Arguments    : const creal_T x[2048]
//                const double costab[1025]
//                const double sintab[1025]
//                creal_T y[2048]
// Return Type  : void
//
void FFTImplementationCallback::b_r2br_r2dit_trig(const creal_T x[2048], const
  double costab[1025], const double sintab[1025], creal_T y[2048])
{
  int ix;
  int iy;
  int ju;
  int i;
  double twid_re;
  double temp_re;
  double twid_im;
  int iheight;
  double temp_im;
  int j;
  ix = 0;
  iy = 0;
  ju = 0;
  for (i = 0; i < 2047; i++) {
    boolean_T tst;
    y[iy] = x[ix];
    iy = 2048;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
    ix++;
  }

  y[iy] = x[ix];
  for (i = 0; i <= 2046; i += 2) {
    double re;
    double im;
    twid_re = y[i + 1].re;
    temp_re = twid_re;
    twid_im = y[i + 1].im;
    temp_im = twid_im;
    re = y[i].re;
    im = y[i].im;
    twid_re = y[i].re - twid_re;
    y[i + 1].re = twid_re;
    twid_im = y[i].im - twid_im;
    y[i + 1].im = twid_im;
    y[i].re = re + temp_re;
    y[i].im = im + temp_im;
  }

  iy = 2;
  ix = 4;
  ju = 512;
  iheight = 2045;
  while (ju > 0) {
    int istart;
    int temp_re_tmp;
    for (i = 0; i < iheight; i += ix) {
      temp_re_tmp = i + iy;
      temp_re = y[temp_re_tmp].re;
      temp_im = y[temp_re_tmp].im;
      y[temp_re_tmp].re = y[i].re - y[temp_re_tmp].re;
      y[temp_re_tmp].im = y[i].im - y[temp_re_tmp].im;
      y[i].re += temp_re;
      y[i].im += temp_im;
    }

    istart = 1;
    for (j = ju; j < 1024; j += ju) {
      int ihi;
      twid_re = costab[j];
      twid_im = sintab[j];
      i = istart;
      ihi = istart + iheight;
      while (i < ihi) {
        temp_re_tmp = i + iy;
        temp_re = twid_re * y[temp_re_tmp].re - twid_im * y[temp_re_tmp].im;
        temp_im = twid_re * y[temp_re_tmp].im + twid_im * y[temp_re_tmp].re;
        y[temp_re_tmp].re = y[i].re - temp_re;
        y[temp_re_tmp].im = y[i].im - temp_im;
        y[i].re += temp_re;
        y[i].im += temp_im;
        i += ix;
      }

      istart++;
    }

    ju /= 2;
    iy = ix;
    ix += ix;
    iheight -= iy;
  }

  for (iy = 0; iy < 2048; iy++) {
    y[iy].re *= 0.00048828125;
    y[iy].im *= 0.00048828125;
  }
}

//
// Arguments    : const creal_T x[1997]
//                const double costab[1025]
//                const double sintab[1025]
//                creal_T y[2048]
// Return Type  : void
//
void FFTImplementationCallback::r2br_r2dit_trig(const creal_T x[1997], const
  double costab[1025], const double sintab[1025], creal_T y[2048])
{
  int ix;
  int iy;
  int ju;
  int i;
  double twid_re;
  double temp_re;
  double twid_im;
  int iheight;
  double temp_im;
  int j;
  std::memset(&y[0], 0, 2048U * sizeof(creal_T));
  ix = 0;
  iy = 0;
  ju = 0;
  for (i = 0; i < 1996; i++) {
    boolean_T tst;
    y[iy] = x[ix];
    iy = 2048;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
    ix++;
  }

  y[iy] = x[ix];
  for (i = 0; i <= 2046; i += 2) {
    double re;
    double im;
    twid_re = y[i + 1].re;
    temp_re = twid_re;
    twid_im = y[i + 1].im;
    temp_im = twid_im;
    re = y[i].re;
    im = y[i].im;
    twid_re = y[i].re - twid_re;
    y[i + 1].re = twid_re;
    twid_im = y[i].im - twid_im;
    y[i + 1].im = twid_im;
    y[i].re = re + temp_re;
    y[i].im = im + temp_im;
  }

  iy = 2;
  ix = 4;
  ju = 512;
  iheight = 2045;
  while (ju > 0) {
    int istart;
    int temp_re_tmp;
    for (i = 0; i < iheight; i += ix) {
      temp_re_tmp = i + iy;
      temp_re = y[temp_re_tmp].re;
      temp_im = y[temp_re_tmp].im;
      y[temp_re_tmp].re = y[i].re - y[temp_re_tmp].re;
      y[temp_re_tmp].im = y[i].im - y[temp_re_tmp].im;
      y[i].re += temp_re;
      y[i].im += temp_im;
    }

    istart = 1;
    for (j = ju; j < 1024; j += ju) {
      int ihi;
      twid_re = costab[j];
      twid_im = sintab[j];
      i = istart;
      ihi = istart + iheight;
      while (i < ihi) {
        temp_re_tmp = i + iy;
        temp_re = twid_re * y[temp_re_tmp].re - twid_im * y[temp_re_tmp].im;
        temp_im = twid_re * y[temp_re_tmp].im + twid_im * y[temp_re_tmp].re;
        y[temp_re_tmp].re = y[i].re - temp_re;
        y[temp_re_tmp].im = y[i].im - temp_im;
        y[i].re += temp_re;
        y[i].im += temp_im;
        i += ix;
      }

      istart++;
    }

    ju /= 2;
    iy = ix;
    ix += ix;
    iheight -= iy;
  }
}

//
// Arguments    : const creal_T x[999]
//                const double costab[1025]
//                const double sintab[1025]
//                creal_T y[2048]
// Return Type  : void
//
void FFTImplementationCallback::r2br_r2dit_trig_impl(const creal_T x[999], const
  double costab[1025], const double sintab[1025], creal_T y[2048])
{
  int ix;
  int iy;
  int ju;
  int i;
  double twid_re;
  double temp_re;
  double twid_im;
  int iheight;
  double temp_im;
  int j;
  std::memset(&y[0], 0, 2048U * sizeof(creal_T));
  ix = 0;
  iy = 0;
  ju = 0;
  for (i = 0; i < 998; i++) {
    boolean_T tst;
    y[iy] = x[ix];
    iy = 2048;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
    ix++;
  }

  y[iy] = x[ix];
  for (i = 0; i <= 2046; i += 2) {
    double re;
    double im;
    twid_re = y[i + 1].re;
    temp_re = twid_re;
    twid_im = y[i + 1].im;
    temp_im = twid_im;
    re = y[i].re;
    im = y[i].im;
    twid_re = y[i].re - twid_re;
    y[i + 1].re = twid_re;
    twid_im = y[i].im - twid_im;
    y[i + 1].im = twid_im;
    y[i].re = re + temp_re;
    y[i].im = im + temp_im;
  }

  iy = 2;
  ix = 4;
  ju = 512;
  iheight = 2045;
  while (ju > 0) {
    int istart;
    int temp_re_tmp;
    for (i = 0; i < iheight; i += ix) {
      temp_re_tmp = i + iy;
      temp_re = y[temp_re_tmp].re;
      temp_im = y[temp_re_tmp].im;
      y[temp_re_tmp].re = y[i].re - y[temp_re_tmp].re;
      y[temp_re_tmp].im = y[i].im - y[temp_re_tmp].im;
      y[i].re += temp_re;
      y[i].im += temp_im;
    }

    istart = 1;
    for (j = ju; j < 1024; j += ju) {
      int ihi;
      twid_re = costab[j];
      twid_im = sintab[j];
      i = istart;
      ihi = istart + iheight;
      while (i < ihi) {
        temp_re_tmp = i + iy;
        temp_re = twid_re * y[temp_re_tmp].re - twid_im * y[temp_re_tmp].im;
        temp_im = twid_re * y[temp_re_tmp].im + twid_im * y[temp_re_tmp].re;
        y[temp_re_tmp].re = y[i].re - temp_re;
        y[temp_re_tmp].im = y[i].im - temp_im;
        y[i].re += temp_re;
        y[i].im += temp_im;
        i += ix;
      }

      istart++;
    }

    ju /= 2;
    iy = ix;
    ix += ix;
    iheight -= iy;
  }
}

//
// Arguments    : const creal_T x[998001]
//                const double costab[1025]
//                const double sintab[1025]
//                const double sintabinv[1025]
//                creal_T y[998001]
// Return Type  : void
//
void FFTImplementationCallback::b_dobluesteinfft(const creal_T x[998001], const
  double costab[1025], const double sintab[1025], const double sintabinv[1025],
  creal_T y[998001])
{
  int idx;
  int rt;
  creal_T wwc[1997];
  int k;
  int xoff;
  int b_k;
  creal_T fv[2048];
  int i;
  creal_T b_fv[2048];
  double im;
  double re;
  double d;
  double d1;
  idx = 997;
  rt = 0;
  wwc[998].re = 1.0;
  wwc[998].im = 0.0;
  for (k = 0; k < 998; k++) {
    int b_y;
    double nt_im;
    double nt_re;
    b_y = ((k + 1) << 1) - 1;
    if (1998 - rt <= b_y) {
      rt = (b_y + rt) - 1998;
    } else {
      rt += b_y;
    }

    nt_im = 3.1415926535897931 * static_cast<double>(rt) / 999.0;
    if (nt_im == 0.0) {
      nt_re = 1.0;
      nt_im = 0.0;
    } else {
      nt_re = std::cos(nt_im);
      nt_im = std::sin(nt_im);
    }

    wwc[idx].re = nt_re;
    wwc[idx].im = -nt_im;
    idx--;
  }

  idx = 0;
  for (k = 997; k >= 0; k--) {
    wwc[k + 999] = wwc[idx];
    idx++;
  }

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(xoff,b_k,fv,i,im,re,b_fv,d,d1)

  for (int chan = 0; chan < 999; chan++) {
    xoff = chan * 999;
    for (b_k = 0; b_k < 999; b_k++) {
      i = b_k + 999 * chan;
      im = wwc[b_k + 998].re;
      re = wwc[b_k + 998].im;
      y[i].re = im * x[xoff].re + re * x[xoff].im;
      y[i].im = im * x[xoff].im - re * x[xoff].re;
      xoff++;
    }

    FFTImplementationCallback::r2br_r2dit_trig_impl((*(creal_T (*)[999])&y[999 *
      chan]), (costab), (sintab), (fv));
    FFTImplementationCallback::r2br_r2dit_trig((wwc), (costab), (sintab), (b_fv));
    for (i = 0; i < 2048; i++) {
      im = fv[i].re * b_fv[i].im + fv[i].im * b_fv[i].re;
      b_fv[i].re = fv[i].re * b_fv[i].re - fv[i].im * b_fv[i].im;
      b_fv[i].im = im;
    }

    FFTImplementationCallback::b_r2br_r2dit_trig((b_fv), (costab), (sintabinv),
      (fv));
    xoff = 0;
    for (b_k = 0; b_k < 999; b_k++) {
      i = xoff + 999 * chan;
      im = wwc[b_k + 998].re;
      re = wwc[b_k + 998].im;
      d = fv[b_k + 998].re;
      d1 = fv[b_k + 998].im;
      y[i].re = im * d + re * d1;
      y[i].im = im * d1 - re * d;
      if (y[i].im == 0.0) {
        re = y[i].re / 999.0;
        im = 0.0;
      } else if (y[i].re == 0.0) {
        re = 0.0;
        im = y[i].im / 999.0;
      } else {
        re = y[i].re / 999.0;
        im = y[i].im / 999.0;
      }

      y[i].re = re;
      y[i].im = im;
      xoff++;
    }
  }
}

//
// Arguments    : const creal_T x[499500]
//                const double costab[1025]
//                const double sintab[1025]
//                const double sintabinv[1025]
//                creal_T y[998001]
// Return Type  : void
//
void FFTImplementationCallback::dobluesteinfft(const creal_T x[499500], const
  double costab[1025], const double sintab[1025], const double sintabinv[1025],
  creal_T y[998001])
{
  int idx;
  int rt;
  creal_T wwc[1997];
  int k;
  int xoff;
  int b_k;
  int i;
  creal_T fv[2048];
  double im;
  creal_T b_fv[2048];
  double d;
  double d1;
  double d2;
  idx = 997;
  rt = 0;
  wwc[998].re = 1.0;
  wwc[998].im = 0.0;
  for (k = 0; k < 998; k++) {
    int b_y;
    double nt_im;
    double nt_re;
    b_y = ((k + 1) << 1) - 1;
    if (1998 - rt <= b_y) {
      rt = (b_y + rt) - 1998;
    } else {
      rt += b_y;
    }

    nt_im = -3.1415926535897931 * static_cast<double>(rt) / 999.0;
    if (nt_im == 0.0) {
      nt_re = 1.0;
      nt_im = 0.0;
    } else {
      nt_re = std::cos(nt_im);
      nt_im = std::sin(nt_im);
    }

    wwc[idx].re = nt_re;
    wwc[idx].im = -nt_im;
    idx--;
  }

  idx = 0;
  for (k = 997; k >= 0; k--) {
    wwc[k + 999] = wwc[idx];
    idx++;
  }

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(xoff,b_k,i,im,d,fv,b_fv,d1,d2)

  for (int chan = 0; chan < 999; chan++) {
    xoff = chan * 500;
    std::memset(&y[chan * 999], 0, 999U * sizeof(creal_T));
    for (b_k = 0; b_k < 500; b_k++) {
      i = b_k + 999 * chan;
      im = wwc[b_k + 998].re;
      d = wwc[b_k + 998].im;
      y[i].re = im * x[xoff].re + d * x[xoff].im;
      y[i].im = im * x[xoff].im - d * x[xoff].re;
      xoff++;
    }

    std::memset(&y[chan * 999 + 500], 0, 499U * sizeof(creal_T));
    FFTImplementationCallback::r2br_r2dit_trig_impl((*(creal_T (*)[999])&y[999 *
      chan]), (costab), (sintab), (fv));
    FFTImplementationCallback::r2br_r2dit_trig((wwc), (costab), (sintab), (b_fv));
    for (i = 0; i < 2048; i++) {
      im = fv[i].re * b_fv[i].im + fv[i].im * b_fv[i].re;
      b_fv[i].re = fv[i].re * b_fv[i].re - fv[i].im * b_fv[i].im;
      b_fv[i].im = im;
    }

    FFTImplementationCallback::b_r2br_r2dit_trig((b_fv), (costab), (sintabinv),
      (fv));
    xoff = 0;
    for (b_k = 0; b_k < 999; b_k++) {
      i = xoff + 999 * chan;
      im = wwc[b_k + 998].re;
      d = wwc[b_k + 998].im;
      d1 = fv[b_k + 998].re;
      d2 = fv[b_k + 998].im;
      y[i].re = im * d1 + d * d2;
      y[i].im = im * d2 - d * d1;
      xoff++;
    }
  }
}

//
// Arguments    : const double x[250000]
//                const double costab[1025]
//                const double sintab[1025]
//                const double sintabinv[1025]
//                creal_T y[499500]
// Return Type  : void
//
void FFTImplementationCallback::dobluesteinfft(const double x[250000], const
  double costab[1025], const double sintab[1025], const double sintabinv[1025],
  creal_T y[499500])
{
  int idx;
  int rt;
  creal_T wwc[1997];
  int k;
  int xoff;
  int b_k;
  int i;
  creal_T fv[2048];
  creal_T b_fv[2048];
  double im;
  double d;
  double d1;
  double d2;
  idx = 997;
  rt = 0;
  wwc[998].re = 1.0;
  wwc[998].im = 0.0;
  for (k = 0; k < 998; k++) {
    int b_y;
    double nt_im;
    double nt_re;
    b_y = ((k + 1) << 1) - 1;
    if (1998 - rt <= b_y) {
      rt = (b_y + rt) - 1998;
    } else {
      rt += b_y;
    }

    nt_im = -3.1415926535897931 * static_cast<double>(rt) / 999.0;
    if (nt_im == 0.0) {
      nt_re = 1.0;
      nt_im = 0.0;
    } else {
      nt_re = std::cos(nt_im);
      nt_im = std::sin(nt_im);
    }

    wwc[idx].re = nt_re;
    wwc[idx].im = -nt_im;
    idx--;
  }

  idx = 0;
  for (k = 997; k >= 0; k--) {
    wwc[k + 999] = wwc[idx];
    idx++;
  }

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(xoff,b_k,i,fv,b_fv,im,d,d1,d2)

  for (int chan = 0; chan < 500; chan++) {
    xoff = chan * 500;
    std::memset(&y[chan * 999], 0, 999U * sizeof(creal_T));
    for (b_k = 0; b_k < 500; b_k++) {
      i = b_k + 999 * chan;
      y[i].re = wwc[b_k + 998].re * x[xoff];
      y[i].im = wwc[b_k + 998].im * -x[xoff];
      xoff++;
    }

    std::memset(&y[chan * 999 + 500], 0, 499U * sizeof(creal_T));
    FFTImplementationCallback::r2br_r2dit_trig_impl((*(creal_T (*)[999])&y[999 *
      chan]), (costab), (sintab), (fv));
    FFTImplementationCallback::r2br_r2dit_trig((wwc), (costab), (sintab), (b_fv));
    for (i = 0; i < 2048; i++) {
      im = fv[i].re * b_fv[i].im + fv[i].im * b_fv[i].re;
      b_fv[i].re = fv[i].re * b_fv[i].re - fv[i].im * b_fv[i].im;
      b_fv[i].im = im;
    }

    FFTImplementationCallback::b_r2br_r2dit_trig((b_fv), (costab), (sintabinv),
      (fv));
    xoff = 0;
    for (b_k = 0; b_k < 999; b_k++) {
      i = xoff + 999 * chan;
      im = wwc[b_k + 998].re;
      d = wwc[b_k + 998].im;
      d1 = fv[b_k + 998].re;
      d2 = fv[b_k + 998].im;
      y[i].re = im * d1 + d * d2;
      y[i].im = im * d2 - d * d1;
      xoff++;
    }
  }
}

//
// File trailer for FFTImplementationCallback.cpp
//
// [EOF]
//
