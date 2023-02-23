#pragma once
#include "Level1.hpp"
#include "allheaders.hpp"

/*
enum that controls properties of a platform in a level.
*/
enum disappearstatus { CANTDISAPPEAR = 0, CANDISAPPEAR, DISAPPEARED, TIMERSTARTED };

/*
struct that contains all variables for the disappearing platform object.
disappearstatus state: enum value that defines characteristic of platform on each frame
int timer: Starting value of timer. Only applies to disappearing platforms
f64 elapsedtime: Total elapsed time form moment player comes into contact with platform
f64 interval: length of time between 2 values that are tracked in elapsedtime
*/
struct PlatformState
{
	disappearstatus state;
	int timer;
	f64 elapsedtime;
	f64 interval;
};