#pragma once
#include "AEEngine.h"
#include <cstdlib>
#include <iostream>
#include "Level1.hpp"
#include "objects.hpp"
#include "Mainmenu.hpp"
#include "SplashScreen.hpp"

#define screenwidth 800
#define screenheight 600

typedef void(*FP)(void);

extern int current, previous, next;

extern FP fpLoad, fpInitialize, fpUpdate, fpDraw, fpFree, fpUnload;

enum GS_STATES
{
	GS_SPLASHSCREEN = 0,
	GS_MAINMENU,
	GS_LEVEL1,
	GS_LEVEL2,

	GS_QUIT,
	GS_RESTART
};
