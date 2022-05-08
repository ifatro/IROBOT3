#include "ImageClass.h"


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




	uint8_t* grayscale_image = stbi_load("C:\\....\\I1.bmp", &width, &height, &bpp, 3);
	uint8_t* grayscale_image2 = stbi_load("C:\\....\\I2.bmp", &width, &height, &bpp, 3);



	 for (int i = 0; i < numPixelLength * numPixelWidth; i ++)
 {



		 fixedImage[i] = (double)grayscale_image[i*3];
		 movingImage[i] = (double)grayscale_image2[i*3];
  }




}
