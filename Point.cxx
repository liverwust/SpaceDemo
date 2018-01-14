//
// This is the newer copy of my Space demo, but this time the program
// is written in C++ with abstract classes, fewer dependencies on
// interrupt-driven functions, and fewer global variables.  In other
// words, it's much more efficient.
// 
// Definition of the Point class, used to represent coordinate points,
// as declared in geometry.h.
//
// Authors:
// Billy Wust <Billy.Wust@gmail.com>
//

#include <math.h>
#include "global.h"
#include "geometry.h"

SpaceDemo::Point::Point(double aX, double aY)
{
	mX = aX;
	mY = aY;
}

SpaceDemo::Point::Point()
{
	mX = 0;
	mY = 0;
}

SpaceDemo::Point::~Point()
{

}

SpaceDemo::Point::operator Pixel()
{
	return Pixel((int)round(mX + (SpaceDemo::gScreenWidth / 2)), (int)round((SpaceDemo::gScreenHeight / 2) - mY));
}
