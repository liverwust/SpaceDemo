//
// This is the newer copy of my Space demo, but this time the program
// is written in C++ with abstract classes, fewer dependencies on
// interrupt-driven functions, and fewer global variables.  In other
// words, it's much more efficient.
// 
// This file, Starfield.cxx, is the definition of the nice background
// class declared in starfield.h.
//
// Authors:
// Billy Wust <Billy.Wust@gmail.com>
//

#include <allegro.h>
#include <stdlib.h>
#include <time.h>
#include "global.h"
#include "Starfield.h"

SpaceDemo::Starfield::Starfield(BITMAP *aBitmap, int aSaturation)
{
	SetBitmap(aBitmap);
	GenerateStarfield(aSaturation);
}

SpaceDemo::Starfield::Starfield(BITMAP *aBitmap)
{
	SetBitmap(aBitmap);
}

SpaceDemo::Starfield::Starfield()
{
	mBitmap = NULL;
}

SpaceDemo::Starfield::~Starfield()
{

}

void SpaceDemo::Starfield::SetBitmap(BITMAP *aBitmap)
{
	mBitmap = aBitmap;
}
void SpaceDemo::Starfield::GenerateStarfield(int aSaturation)
{
	unsigned int lXStep, lYStep, lXSize, lYSize;
	srand((unsigned int)time(NULL));
	lXSize = SpaceDemo::gScreenWidth / aSaturation;
	lYSize = SpaceDemo::gScreenHeight / aSaturation;
	for(lXStep = 0; lXStep < aSaturation; lXStep++)
	{
		for(lYStep = 0; lYStep < aSaturation; lYStep++)
		{
			mXStars.push_back((rand() % lXSize) + (lXStep * lXSize));
			mYStars.push_back((rand() % lYSize) + (lYStep * lYSize));
		}
	}
}

void SpaceDemo::Starfield::Draw()
{
	unsigned int lStarNum;
	unsigned int lColor = makecol(255, 255, 255);
	for(lStarNum = 0; lStarNum < mXStars.size(); lStarNum++)
	{
		putpixel(mBitmap, mXStars.at(lStarNum), mYStars.at(lStarNum), lColor);
	}
}
