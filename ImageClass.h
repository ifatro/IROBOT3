#pragma once
#include <iostream>
#include "config.h"


/*The image class is a member of the camera class, The main function
of the image class is extractImage which loads two images at any format (tiff, bmp, png, jpg, etc.) and transforming them
into  grayscale images represented in a matrix of a size of [pixelLength1=500,pixelWidth1-500]
The image size is defined in the configuration file (config.h) and is constant in this solution
The function that performs this operation is called stb_image.h - v2.27 - public domain image loader*/




class ImageClass
{


public:

	ImageClass();
	void extractImage();
	static double fixedImage[numPixelLength1* numPixelWidth1];
	static double movingImage[numPixelLength1* numPixelWidth1];
	int  numPixelWidth;
	int  numPixelLength;

private:


protected:




};

