//
// File: PhaseCorr1_rtwutil.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 06-May-2022 13:59:16
//
#ifndef PHASECORR1_RTWUTIL_H
#define PHASECORR1_RTWUTIL_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "PhaseCorr1_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern double rt_atan2d_snf(double u0, double u1);
extern double rt_hypotd_snf(double u0, double u1);

#endif

//
// File trailer for PhaseCorr1_rtwutil.h
//
// [EOF]
//
