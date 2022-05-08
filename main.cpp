#include <stdlib.h>
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include "RobotClass.h"



int  main()
{



  RobotClass IROBOT;
  IROBOT.Camera.PhaseCorrImage();



  std::cout << "x and y pixel change from IMAGE 1 to IMAGE 2: " << std::endl;

  std::cout << IROBOT.Camera.xpixelMov << std::endl;
  std::cout << IROBOT.Camera.ypixelMov  << std::endl;

  IROBOT.extractMovFromPixel();


  std::cout << "x and y IROBOT3 movement from IMAGE 1 to IMAGE 2: " << std::endl;

  std::cout << IROBOT.xMovMeter << std::endl;
  std::cout << IROBOT.yMovMeter << std::endl;



  return 0;

}


