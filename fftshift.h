//
// File: fftshift.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 06-May-2022 13:59:16
//
#ifndef FFTSHIFT_H
#define FFTSHIFT_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "PhaseCorr1_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void fftshift(creal_T x[998001]);

#endif

//
// File trailer for fftshift.h
//
// [EOF]
//
