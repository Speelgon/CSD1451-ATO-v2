#pragma once
#include "AEEngine.h"
#include <cstdlib>
#include <iostream>
#include "Level1.hpp"
#include "Mainmenu.hpp"

#define screenwidth 800
#define screenheight 600

typedef void(*FP)(void);

extern int current, previous, next;

extern FP fpLoad, fpInitialize, fpUpdate, fpDraw, fpFree, fpUnload;

enum GS_STATES
{
	GS_MAINMENU = 0,
	GS_LEVEL1,
	GS_LEVEL2,

	GS_QUIT,
	GS_RESTART
};
