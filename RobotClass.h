#pragma once
#include "CameraClass.h"
#include "config.h"
#include <math.h>



/*The robot class is the main class in this solution and is defined in the main(). the Robot class
holds the image class and has the functionality to translate pixel change in adjacent images to
horizontal and vertical movements using the function extractMovFromPixel()*/


class RobotClass
{


public:


	RobotClass();
	void calcVirtArmToImageCenter();
	CameraClass Camera;
	void extractMovFromPixel();
	double xMovMeter;
	double yMovMeter;

private:

	double installationCamHeight;
	double installationCamTilt;
	double VirtArmToImageCenter;
};

