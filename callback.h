//
// This is the newer copy of my Space demo, but this time the program
// is written in C++ with abstract classes, fewer dependencies on
// interrupt-driven functions, and fewer global variables.  In other
// words, it's much more efficient.
// 
// This file, callback.h, is the declaration of some of the callbacks
// that are used in the program, like those for keyboard handling and
// the refresh timer.
//
// Authors:
// Billy Wust <Billy.Wust@gmail.com>
//

// Remember, these callbacks must be in locked memory and must
// execute REALLY fast, so make sure that they do little more than
// set a variable or something.

#ifndef CALLBACK_H
#define CALLBACK_H

namespace SpaceDemo
{
// Executes once per every preset time period and sets global
// variable SpaceDemo::gRequestRefresh.
	void RefreshTimer();
}

#endif //CALLBACK_H
