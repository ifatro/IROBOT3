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

/*The Camera class is a member of the rbot class and holds the Image class
The main function of the camera class is performing a phase correlation operation from two images
one image is considered to be the fixed image and the second image is the moving image. the number of movement
pixels is calculated using the PhaseCorrImage() function*/



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

