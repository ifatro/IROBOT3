#include "CameraClass.h"



CameraClass::CameraClass()
{
	

	 xpixelMov=0;
	 ypixelMov=0;


	fovWidth = fovWidth1;  //[deg]
	fovLength = fovLength1;  //[deg]

	IfovWidth = fovWidth1 / double(Image.numPixelWidth);   //[deg]  angular size of one pixel (width)
	IfovLength = fovLength1 / double(Image.numPixelLength); //[deg]  angular size of one pixel (length)




	Image.extractImage();







}

void CameraClass::PhaseCorrImage()
{

	PhaseCorr1(Image.fixedImage, Image.movingImage, &xpixelMov, &ypixelMov);




}
