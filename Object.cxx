//
// This is the newer copy of my Space demo, but this time the program
// is written in C++ with abstract classes, fewer dependencies on
// interrupt-driven functions, and fewer global variables.  In other
// words, it's much more efficient.
// 
// This file, Object.cxx, is the definition of the Object class
// initially declared in Object.h.
// 
// Authors:
// Billy Wust <Billy.Wust@gmail.com>
//

#include <allegro.h>
#include "global.h"
#include "geometry.h"
#include "Object.h"

SpaceDemo::Object::Object(BITMAP *aBitmap)
{
	SetBitmap(aBitmap);
}

SpaceDemo::Object::Object()
{
	mBitmap = NULL;
}

SpaceDemo::Object::~Object()
{

}

void SpaceDemo::Object::SetPoint(Point aPoint)
{
	mPoint = aPoint;
}

void SpaceDemo::Object::SetVector(Vector aVector)
{
	mVector = aVector;
}

void SpaceDemo::Object::AddVector(Vector aVector)
{
	mVector = mVector + aVector;
}

void SpaceDemo::Object::SetBitmap(BITMAP *aBitmap)
{
	mBitmap = aBitmap;
}

void SpaceDemo::Object::Update()
{
	if(!mBitmap) return;
	Cleanup();
	mPoint = mVector.ApplyVector(mPoint);
	if(Check()) Draw();
}

void SpaceDemo::Object::Cleanup()
{

}

bool SpaceDemo::Object::Check()
{
	return false;
}

void SpaceDemo::Object::Draw()
{

}
