#pragma once
#include "CameraClass.h"
#include "config.h"
#include <math.h>
class RobotClass
{


public:


	RobotClass();
	void calcVirtArmToImageCenter();
	CameraClass Camera;
	void extrectMovFromPixel();
	double xMovMeter;
	double yMovMeter;

private:

	double installationCamHeight;
	double installationCamTilt;
	double VirtArmToImageCenter;
};

