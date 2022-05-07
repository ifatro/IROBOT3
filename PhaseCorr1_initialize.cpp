//
// File: PhaseCorr1_initialize.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 06-May-2022 13:59:16
//

// Include Files
#include "PhaseCorr1_initialize.h"
#include "PhaseCorr1.h"
#include "PhaseCorr1_data.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void PhaseCorr1_initialize()
{
  rt_InitInfAndNaN();
  omp_init_nest_lock(&emlrtNestLockGlobal);
  isInitialized_PhaseCorr1 = true;
}

//
// File trailer for PhaseCorr1_initialize.cpp
//
// [EOF]
//
