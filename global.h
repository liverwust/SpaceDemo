//
// This is the newer copy of my Space demo, but this time the program
// is written in C++ with abstract classes, fewer dependencies on
// interrupt-driven functions, and fewer global variables.  In other
// words, it's much more efficient.
// 
// This file, global.h, contains the declarations for various global
// variables and contants used throughout the program, such as timer
// intervals and ship speeds.
// 
// Authors:
// Billy Wust <Billy.Wust@gmail.com>
//

#ifndef GLOBAL_H
#define GLOBAL_H

namespace SpaceDemo
{
// Screen width by height, very useful for drawing.
	extern unsigned int gScreenHeight;
	extern unsigned int gScreenWidth;
// Refresh interval, as well as the request itself.
	extern unsigned int gTimerInterval;
	extern bool gRequestRefresh;
// Starfield saturation, or how dense the background is.
	extern unsigned int gStarSaturation;
// Spaceship BMP filename.
	extern const char *gShipFilename;
// Spaceship physics settings (speed / rotation).
	extern const double gShipSpeed;
	extern const double gShipRotation;
}

#endif //GLOBAL_H
