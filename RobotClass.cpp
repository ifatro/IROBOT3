#include "RobotClass.h"

RobotClass::RobotClass()
{

	installationCamHeight = installationCamHeight1; //meter
    installationCamTilt = installationCamTilt1; //deg
	calcVirtArmToImageCenter();

}

void RobotClass::calcVirtArmToImageCenter()
{

	// This function calculates the range to the center of the image in [meters]

	VirtArmToImageCenter = installationCamHeight / cos(installationCamTilt * DEG2RAD);
}

void RobotClass::extractMovFromPixel()
{

	// This function translate the image pixel movement in horizontal and vertical to movement in radians
	// and from radians to meters using the length of virtual arm to the image center:


	double xMovDeg;
	double yMovDeg;

	double xMovRad;
	double yMovRad;
	// calculating the movement in degrees :

	xMovDeg = Camera.xpixelMov*Camera.IfovLength;
	yMovDeg = Camera.ypixelMov*Camera.IfovWidth;


	// calculating the movement in meters:


	xMovRad = xMovDeg * DEG2RAD;
	yMovRad = yMovDeg * DEG2RAD;

	xMovMeter=tan(xMovRad) * VirtArmToImageCenter;
	//yMovMeter=tan(yMovRad) * VirtArmToImageCenter;
    
	// using the "MISHPAT HASINUSIM" to extract the movement in the horizontal dimension:

	// The length in meter in the horizontal direction is bigger if the pixel change is farther than the image center

	if (yMovRad < 0)
	{
		yMovMeter = (VirtArmToImageCenter * sin(yMovRad)) / sin(PI / 2 - yMovRad - this->installationCamTilt * DEG2RAD);
	}

	else

	{
		yMovMeter = (VirtArmToImageCenter * sin(yMovRad)) / sin(PI / 2 - yMovRad + this->installationCamTilt * DEG2RAD);
	}
	


	



}
