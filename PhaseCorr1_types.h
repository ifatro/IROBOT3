//
// File: PhaseCorr1_types.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 06-May-2022 13:59:16
//
#ifndef PHASECORR1_TYPES_H
#define PHASECORR1_TYPES_H

// Include Files
#include "rtwtypes.h"

// Type Definitions
class FFTImplementationCallback
{
 public:
  static void dobluesteinfft(const double x[250000], const double costab[1025],
    const double sintab[1025], const double sintabinv[1025], creal_T y[499500]);
  static void dobluesteinfft(const creal_T x[499500], const double costab[1025],
    const double sintab[1025], const double sintabinv[1025], creal_T y[998001]);
  static void b_dobluesteinfft(const creal_T x[998001], const double costab[1025],
    const double sintab[1025], const double sintabinv[1025], creal_T y[998001]);
 protected:
  static void r2br_r2dit_trig_impl(const creal_T x[999], const double costab
    [1025], const double sintab[1025], creal_T y[2048]);
  static void r2br_r2dit_trig(const creal_T x[1997], const double costab[1025],
    const double sintab[1025], creal_T y[2048]);
  static void b_r2br_r2dit_trig(const creal_T x[2048], const double costab[1025],
    const double sintab[1025], creal_T y[2048]);
};

#define MAX_THREADS                    omp_get_max_threads()
#endif

//
// File trailer for PhaseCorr1_types.h
//
// [EOF]
//
