#include <iostream>
#include "ImageClass.h"
#include "ImagesNamesHeader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
//

double ImageClass::fixedImage[] = { 0 };
double ImageClass::movingImage[] = { 0 };


ImageClass::ImageClass()
{

	numPixelLength = numPixelLength1;
	numPixelWidth = numPixelWidth1;

	
}

void ImageClass::extractImage()
{



	int width, height, bpp;




	uint8_t* grayscale_image = stbi_load(ImageName1, &width, &height, &bpp, 3);
	if (!grayscale_image)
	{
		std::cout << "Image file not opened, cant continue: " << ImageName1 << std::endl;
		exit(-1);
	}


	uint8_t* grayscale_image2 = stbi_load(ImageName2, &width, &height, &bpp, 3);
	if (!grayscale_image2)
	{
		std::cout << "Image file not opened, cant continue: " << ImageName2 << std::endl;
		exit(-1);
	}



	//uint8_t* grayscale_image = stbi_load("C:\\Users\\Eran\\Desktop\\IROBOT3\\IROBOT3\\I1.bmp", &width, &height, &bpp, 3);
	//uint8_t* grayscale_image2 = stbi_load("C:\\Users\\Eran\\Desktop\\IROBOT3\\IROBOT3\\I2.bmp", &width, &height, &bpp, 3);







	 for (int i = 0; i < numPixelLength * numPixelWidth; i ++)
 {



		 fixedImage[i] = (double)grayscale_image[i*3];
		 movingImage[i] = (double)grayscale_image2[i*3];
  }




}
