//
// This is the newer copy of my Space demo, but this time the program
// is written in C++ with abstract classes, fewer dependencies on
// interrupt-driven functions, and fewer global variables.  In other
// words, it's much more efficient.
// 
// Definition of the Pixel class, used to represent on-screen points,
// as declared in geometry.h.
//
// Authors:
// Billy Wust <Billy.Wust@gmail.com>
//

#include "global.h"
#include "geometry.h"

SpaceDemo::Pixel::Pixel(int aX, int aY)
{
	mX = aX;
	mY = aY;
}

SpaceDemo::Pixel::Pixel()
{
	mX = SpaceDemo::gScreenWidth / 2;
	mY = SpaceDemo::gScreenHeight / 2;
}

SpaceDemo::Pixel::~Pixel()
{

}

SpaceDemo::Pixel::operator Point()
{
	return Point(mX - (SpaceDemo::gScreenWidth / 2), (SpaceDemo::gScreenHeight / 2) - mY);
}
