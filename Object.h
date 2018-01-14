//
// This is the newer copy of my Space demo, but this time the program
// is written in C++ with abstract classes, fewer dependencies on
// interrupt-driven functions, and fewer global variables.  In other
// words, it's much more efficient.
// 
// The Object class is the ultimate parent class of all moving or
// nonmoving objects in the Universe.  It provides services for
// moving the origin of whatever object it represents across the
// screen.
//
// Authors:
// Billy Wust <Billy.Wust@gmail.com>
//

#ifndef OBJECT_H
#define OBJECT_H

#include <allegro.h>
#include "geometry.h"

namespace SpaceDemo
{
	class Object
	{
	public:
		Object(BITMAP *aBitmap);
		Object();
		virtual ~Object();
		void SetPoint(Point aPoint);
		void SetVector(Vector aVector);
		void AddVector(Vector aVector);
		void SetBitmap(BITMAP *aBitmap);
		void Update();
	protected:
// These three functions are indicators to child classes of when
// various events are happening.  Cleanup() is before mPoint is
// altered, so it can be used to remove what needs to be removed
// before drawing.  Check() happens right before the draw, and if
// it returns false, drawing won't happen.  Draw() is the draw
// itself, which happens last.
		virtual void Cleanup();
		virtual bool Check();
		virtual void Draw();
		BITMAP *mBitmap;
		Point mPoint;
	private:
		Vector mVector;
	};
}

#endif //OBJECT_H
