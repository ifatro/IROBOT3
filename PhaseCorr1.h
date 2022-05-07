//
// File: PhaseCorr1.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 06-May-2022 13:59:16
//
#ifndef PHASECORR1_H
#define PHASECORR1_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "PhaseCorr1_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void PhaseCorr1(const double A[250000], const double B[250000], double
  *xpeak, double *ypeak);

#endif

//
// File trailer for PhaseCorr1.h
//
// [EOF]
//
