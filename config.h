// GENERAL PARAMETERS:
#define PI 3.14159265359
#define DEG2RAD 3.14159265359/180
#define RAD2DEG 180/3.14159265359


// ROBOT PARAMETERS:

#define installationCamHeight1 0.1 //meter - height of the camera from the floor.
#define installationCamTilt1  10   //deg   - Tilt of the camera in respect to the Nadir point (=to the floor)


// CAMERA PARAMETERS
#define pixelLength1  500 //[-] //number of pixels in the image length
#define pixelWidth1  500  //[-] //number of pixels in the image width

// IMAGE PARAMETERS


#define fovWidth1   10 //[deg]   //angular size of the image field of view (width)
#define fovLength1   10  //[deg] //angular size of the image field of view (length)
#define IfovWidth1   fovWidth1 / pixelWidth1     //[deg]  angular size of one pixel (width)
#define IfovLength1   fovLength1 / pixelLength1  //[deg]  angular size of one pixel (length)



