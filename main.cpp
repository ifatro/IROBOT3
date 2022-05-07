#include <stdlib.h>
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include "RobotClass.h"



int  main()
{

  RobotClass IROBOT;
  IROBOT.Camera.PhaseCorrImage();


  std::cout << IROBOT.Camera.xpixelMov  << std::endl;
  std::cout << IROBOT.Camera.ypixelMov  << std::endl;

  IROBOT.extrectMovFromPixel();

  std::cout << IROBOT.xMovMeter << std::endl;
  std::cout << IROBOT.yMovMeter << std::endl;



  return 0;

}


