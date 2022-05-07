#pragma once
#include <iostream>
#include "config.h"


/*The image class is a member of the camera class, The main function
of the image class is two load two images at any format (tiff, bmp, png, jpg, etc.) and transforming it
to a grayscale image represented in a matrix of a size of [pixelLength1=500,pixelWidth1-500]
The image size is defined in the configuration file (config.h) and is constant in this solution*/




class ImageClass
{


public:

	ImageClass();
	void extractImage();
	static double A_tmp[pixelLength1*pixelWidth1];
	static double B_tmp[pixelLength1*pixelWidth1];

private:


protected:

	int  pixelWidth;
	int  pixelLength;


};

