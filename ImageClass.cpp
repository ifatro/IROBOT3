#include "ImageClass.h"


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
//

double ImageClass::A_tmp[] = { 0 };
double ImageClass::B_tmp[] = { 0 };


ImageClass::ImageClass()
{

	pixelLength = pixelLength1;
	pixelWidth = pixelWidth1;

	
}

void ImageClass::extractImage()
{



	int width, height, bpp;




	uint8_t* grayscale_image = stbi_load("C:\\....\\I1.bmp", &width, &height, &bpp, 3);
	uint8_t* grayscale_image2 = stbi_load("C:\\....\\I2.bmp", &width, &height, &bpp, 3);



	 for (int i = 0; i < pixelLength * pixelWidth; i ++)
 {



		A_tmp[i] = (double)grayscale_image[i*3];
		B_tmp[i] = (double)grayscale_image2[i*3];
  }




}
