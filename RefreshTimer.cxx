//
// This is the newer copy of my Space demo, but this time the program
// is written in C++ with abstract classes, fewer dependencies on
// interrupt-driven functions, and fewer global variables.  In other
// words, it's much more efficient.
// 
// This file, RefreshTimer.cxx, implements the refresh timer
// interrupt routine.
//
// Authors:
// Billy Wust <Billy.Wust@gmail.com>
//

#include <queue>
#include "global.h"
#include "callback.h"

// As a side note, this routine no longer generates events on the
// message queue.  It was simply not the right way to go, as doing so
// could potentially overflow the queue if some time-consuming check
// for pending refreshes was not done first.  Also, the events would
// need to be added to the BACK of the queue, to avoid blocking more
// important events like keypresses.
void SpaceDemo::RefreshTimer()
{
	SpaceDemo::gRequestRefresh = true;
}
