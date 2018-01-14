//
// This is the newer copy of my Space demo, but this time the program
// is written in C++ with abstract classes, fewer dependencies on
// interrupt-driven functions, and fewer global variables.  In other
// words, it's much more efficient.
// 
// This file, geometry.h, is the declaration of the various geometric
// constructs, such as points and vectors, used throughout the
// program.
//
// Authors:
// Billy Wust <Billy.Wust@gmail.com>
//

#ifndef GEOMETRY_H
#define GEOMETRY_H

namespace SpaceDemo
{
	class Point;
	class Pixel
	{
	public:
		Pixel(int aX, int aY);
		Pixel();
		~Pixel();
		operator Point();
		int mX;
		int mY;
	};
	class Point
	{
	public:
		Point(double aX, double aY);
		Point();
		~Point();
		operator Pixel();
		double mX;
		double mY;
	};
	class Vector
	{
	public:
		Vector(double aAngle, double aMagnitude);
		Vector();
		~Vector();
		Vector operator+(Vector aVector);
		Point ApplyVector(Point aPoint);
		double mAngle;
		double mMagnitude;
	};
}

#endif //GEOMETRY_H
