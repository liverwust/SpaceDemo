//
// This is the newer copy of my Space demo, but this time the program
// is written in C++ with abstract classes, fewer dependencies on
// interrupt-driven functions, and fewer global variables.  In other
// words, it's much more efficient.
// 
// This file, Vector.cxx, is the definition of the Vector class
// defined in geometry.h which is used to represent motion.
//
// Authors:
// Billy Wust <Billy.Wust@gmail.com>
//

#include <math.h>
#include "geometry.h"

SpaceDemo::Vector::Vector(double aAngle, double aMagnitude)
{
	mAngle = aAngle;
	mMagnitude = aMagnitude;
}

SpaceDemo::Vector::Vector()
{
	mAngle = 0;
	mMagnitude = 0;
}

SpaceDemo::Vector::~Vector()
{

}

SpaceDemo::Vector SpaceDemo::Vector::operator+(SpaceDemo::Vector aVector)
{
	SpaceDemo::Vector lResult;
	double x, y;
	x = mMagnitude * cos(mAngle) + aVector.mMagnitude * cos(aVector.mAngle);
	y = mMagnitude * sin(mAngle) + aVector.mMagnitude * sin(aVector.mAngle);
	lResult.mMagnitude = sqrt(pow(x, 2) + pow(y, 2));
	lResult.mAngle = acos(x / lResult.mMagnitude);
	if(y < 0) lResult.mAngle = 2 * M_PI - lResult.mAngle;
	return lResult;
}

SpaceDemo::Point SpaceDemo::Vector::ApplyVector(SpaceDemo::Point aPoint)
{
	double lCos, lSin;
	lCos = mMagnitude * cos(mAngle);
	lSin = mMagnitude * sin(mAngle);
	return Point(aPoint.mX + lCos, aPoint.mY + lSin);
}
