//
// This is the newer copy of my Space demo, but this time the program
// is written in C++ with abstract classes, fewer dependencies on
// interrupt-driven functions, and fewer global variables.  In other
// words, it's much more efficient.
// 
// This file, Sprite.cxx, defines the Sprite class as described in
// file Sprite.h.
//
// Authors:
// Billy Wust <Billy.Wust@gmail.com>
//

#include <allegro.h>
#include <math.h>
#include <stdlib.h>
#include "geometry.h"
#include "Object.h"
#include "Sprite.h"

SpaceDemo::Sprite::Sprite() : SpaceDemo::Object()
{
	mSprite = NULL;
	mScratch = NULL;
	mAngle = M_PI / 2;
}

SpaceDemo::Sprite::~Sprite()
{
	destroy_bitmap(mSprite);
	destroy_bitmap(mScratch);
}

bool SpaceDemo::Sprite::LoadSprite(const char *aFilename)
{
	mSprite = load_bitmap(aFilename, NULL);
	if(!mSprite)
	{
		allegro_message("Couldn't open sprite.\n");
		exit(-1);
	}
	mScratch = create_bitmap(mSprite->w, mSprite->h);
}

void SpaceDemo::Sprite::Translate(SpaceDemo::Vector aVector)
{
	aVector.mAngle += mAngle;
	AddVector(aVector);
}

void SpaceDemo::Sprite::Rotate(double aAngle)
{
	mAngle += aAngle;
	double lDPi = 2 * M_PI;
	while(!((mAngle >= 0) && (mAngle < lDPi)))
	{
		if(mAngle < 0) mAngle += lDPi;
		else if(mAngle >= lDPi) mAngle -= lDPi;
	}
}

void SpaceDemo::Sprite::Freeze(bool aResetRotation)
{
	SetVector(Vector(0, 0));
	if(aResetRotation) mAngle = M_PI / 2;
}

bool SpaceDemo::Sprite::Check()
{
	return true;
}

void SpaceDemo::Sprite::Draw()
{
	SpaceDemo::Pixel lPixel = mPoint;
	clear_to_color(mScratch, makecol(255, 0, 255));
	rotate_sprite(mScratch, mSprite, 0, 0, ftofix(320 - ((mAngle * 256) / (2 * M_PI))));
	masked_blit(mScratch, mBitmap, 0, 0, lPixel.mX - (mBitmap->w / 2), lPixel.mY - (mBitmap->h / 2), mBitmap->w, mBitmap->h);
}
