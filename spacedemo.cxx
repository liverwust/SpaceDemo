//
// This is the newer copy of my Space demo, but this time the program
// is written in C++ with abstract classes, fewer dependencies on
// interrupt-driven functions, and fewer global variables.  In other
// words, it's much more efficient.
// 
// This file, spacedemo.cxx, houses the main() routine, which in turn
// contains all of the initialization code, as well as the main loop.
//
// Authors:
// Billy Wust <Billy.Wust@gmail.com>
//

#include <allegro.h>
#include <math.h>
#include "global.h"
#include "geometry.h"
#include "callback.h"
#include "Starfield.h"
#include "Sprite.h"

// RunGame() -> Main routine of the program.  The init/loop code has
// been taken out of the main() function in order to allow class
// destructors to call things like destroy_bitmap().
void RunGame()
{
	BITMAP *lDoubleBuffer;
	SpaceDemo::Starfield lStarfield;
	SpaceDemo::Sprite lShip;
	bool lBreakCondition = false;
	int lKeyCode;
	lDoubleBuffer = create_bitmap(SpaceDemo::gScreenWidth, SpaceDemo::gScreenHeight);
	clear_bitmap(lDoubleBuffer);
	lStarfield.SetBitmap(lDoubleBuffer);
	lStarfield.GenerateStarfield(SpaceDemo::gStarSaturation);
	lShip.SetBitmap(lDoubleBuffer);
	lShip.LoadSprite(SpaceDemo::gShipFilename);
	lShip.SetPoint(SpaceDemo::Point(0, 0));
	SpaceDemo::gRequestRefresh = true;
	LOCK_FUNCTION(SpaceDemo::RefreshTimer);
	install_int(SpaceDemo::RefreshTimer, SpaceDemo::gTimerInterval);
	while(!lBreakCondition)
	{
		while((!keypressed()) && (!SpaceDemo::gRequestRefresh))
		{
		}
		if(SpaceDemo::gRequestRefresh)
		{
			clear_bitmap(lDoubleBuffer);
			lStarfield.Draw();
			lShip.Update();
			blit(lDoubleBuffer, screen, 0, 0, 0, 0, SpaceDemo::gScreenWidth, SpaceDemo::gScreenHeight);
		}
		if(keypressed())
		{
			lKeyCode = readkey();
			switch(lKeyCode >> 8)
			{
			case KEY_ESC:
				lBreakCondition = true;
				break;
			case KEY_UP:
				lShip.Translate(SpaceDemo::Vector(0, SpaceDemo::gShipSpeed));
				break;
			case KEY_DOWN:
				lShip.Translate(SpaceDemo::Vector(M_PI, SpaceDemo::gShipSpeed));
				break;
			case KEY_LEFT:
				lShip.Rotate(SpaceDemo::gShipRotation);
				break;
			case KEY_RIGHT:
				lShip.Rotate(-1 * SpaceDemo::gShipRotation);
				break;
			case KEY_SPACE:
				lShip.Freeze(false);
				break;
			}
		}
	}
	destroy_bitmap(lDoubleBuffer);
}

// main() -> The first and last procedure of the program.  Contains
// init code plus the loop routine.
int main(int argc, char **argv)
{
	allegro_init();
	install_timer();
	install_keyboard();
	set_color_depth(32);
	if(set_gfx_mode(GFX_AUTODETECT_WINDOWED, SpaceDemo::gScreenWidth, SpaceDemo::gScreenHeight, 0, 0) < 0)
	{
		allegro_message("Can't set video mode.");
		return -1;
	}
	RunGame();
	allegro_exit();
	return 0;
}
END_OF_MAIN()
