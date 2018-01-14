//
// This is the newer copy of my Space demo, but this time the program
// is written in C++ with abstract classes, fewer dependencies on
// interrupt-driven functions, and fewer global variables.  In other
// words, it's much more efficient.
// 
// The Sprite class is the parent class of all objects on the screen
// that use images loaded from files and rotate.  It is a subclass of
// Object.
//
// Authors:
// Billy Wust <Billy.Wust@gmail.com>
//

#ifndef STATICSHIP_H
#define STATICSHIP_H

#include <allegro.h>
#include "geometry.h"
#include "Object.h"

namespace SpaceDemo
{
	class Sprite : public Object
	{
	public:
		Sprite();
		~Sprite();
		bool LoadSprite(const char *aFilename);
		void Translate(Vector aVector);
		void Rotate(double aAngle);
		void Freeze(bool aResetRotation);
	protected:
		bool Check();
		void Draw();
	private:
		double mAngle;
		BITMAP *mSprite;
		BITMAP *mScratch;
	};
}

#endif //STATICSHIP_H
