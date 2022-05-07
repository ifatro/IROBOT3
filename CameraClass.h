#pragma once
#include "CameraClass.h"
#include "ImageClass.h"
#include "rtwtypes.h"
#include "omp.h"
#include "PhaseCorr1_types.h"
#define MAX_THREADS                    omp_get_max_threads()
#include "PhaseCorr1.h"
#include "PhaseCorr1_terminate.h"
#include "rt_nonfinite.h"
#include "config.h"


class CameraClass
{



public:

	CameraClass();
	void PhaseCorrImage();
	double xpixelMov;
	double ypixelMov;
	double fovWidth;
	double fovLength;
	double IfovWidth;
	double IfovLength;

protected:


	ImageClass Image;


};

