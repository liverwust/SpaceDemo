//
// This is the newer copy of my Space demo, but this time the program
// is written in C++ with abstract classes, fewer dependencies on
// interrupt-driven functions, and fewer global variables.  In other
// words, it's much more efficient.
// 
// This file, Starfield.h, is the declaration of the class that
// represents and draws the starfield pattern in the background of
// the screen.
//
// Authors:
// Billy Wust <Billy.Wust@gmail.com>
//

#ifndef STARFIELD_H
#define STARFIELD_H

#include <allegro.h>
#include <vector>

namespace SpaceDemo
{
	class Starfield
	{
	public:
		Starfield(BITMAP *aBitmap, int aSaturation);
		Starfield(BITMAP *aBitmap);
		Starfield();
		~Starfield();
		void SetBitmap(BITMAP *aBitmap);
		void GenerateStarfield(int aSaturation);
		void Draw();
	private:
		BITMAP *mBitmap;
		std::vector<unsigned int> mXStars;
		std::vector<unsigned int> mYStars;
	};
}

#endif //STARFIELD_H
