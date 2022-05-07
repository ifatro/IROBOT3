#include "CameraClass.h"



CameraClass::CameraClass()
{
	

	 xpixelMov=0;
	 ypixelMov=0;


	fovWidth = fovWidth1;  //[deg]
	fovLength = fovLength1;  //[deg]
	IfovWidth = IfovWidth1;//[deg]
	IfovLength = IfovLength1;//[deg]

	Image.extractImage();







}

void CameraClass::PhaseCorrImage()
{

	PhaseCorr1(Image.A_tmp, Image.B_tmp, &xpixelMov, &ypixelMov);




}
