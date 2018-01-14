//
// This is the newer copy of my Space demo, but this time the program
// is written in C++ with abstract classes, fewer dependencies on
// interrupt-driven functions, and fewer global variables.  In other
// words, it's much more efficient.
// 
// This file, global.cxx, is simply the definition of all the global
// variables declared in global.h.
//
// Authors:
// Billy Wust <Billy.Wust@gmail.com>
//

#include <math.h>
#include "global.h"

unsigned int SpaceDemo::gScreenWidth = 512;
unsigned int SpaceDemo::gScreenHeight = 512;
unsigned int SpaceDemo::gTimerInterval = 10;
unsigned int SpaceDemo::gStarSaturation = 16;
bool SpaceDemo::gRequestRefresh = false;
const char *SpaceDemo::gShipFilename = "42demo.bmp";
const double SpaceDemo::gShipSpeed = 1;
const double SpaceDemo::gShipRotation = M_PI / 8;
