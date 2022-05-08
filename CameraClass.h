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

/*The Camera class is a member of the robot class and holds the Image class
The main function of the camera class is performing a phase correlation operation from two images
one image is considered to be the fixed image and the second image is the moving image. the number of movement
pixels is calculated using the PhaseCorrImage() function.
 This function was generated from an AUTOMATIC code in matlab using the following functions:
 -PhaseCorr1
 -PhaseCorr1_data
 -PhaseCorr1_initialize
 -PhaseCorr1_rtwutil
 -PhaseCorr1_terminate
 -PhaseCorr1_types
 -relop
 -rt_defines
 -rt_nonfinite
 -rtGetInf
 -rtGetNan
 -rtwtypes
 -tmwtypes
 
 */



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

