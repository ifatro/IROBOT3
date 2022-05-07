#include "RobotClass.h"

RobotClass::RobotClass()
{

	installationCamHeight = installationCamHeight1; //meter
    installationCamTilt = installationCamTilt1; //deg
	calcVirtArmToImageCenter();

}

void RobotClass::calcVirtArmToImageCenter()
{

	VirtArmToImageCenter = installationCamHeight / cos(installationCamTilt * DEG2RAD);
}

void RobotClass::extrectMovFromPixel()
{

	double xMovDeg;
	double yMovDeg;




	xMovDeg = Camera.xpixelMov*Camera.IfovLength;
	yMovDeg = Camera.ypixelMov*Camera.fovWidth;


	xMovMeter=cos(xMovDeg * DEG2RAD)* VirtArmToImageCenter;
	yMovMeter=cos(yMovDeg * DEG2RAD)* VirtArmToImageCenter;
}
