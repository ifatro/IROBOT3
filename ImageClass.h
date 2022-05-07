#pragma once
#include <iostream>
#include "config.h"






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

