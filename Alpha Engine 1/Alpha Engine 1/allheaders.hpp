#pragma once
#include "AEEngine.h"
#include <cstdlib>
#include <iostream>
#include "Level1.hpp"
#include "objects.hpp"
#include "level1_new.hpp"
#include "Level2.hpp"
#include "Level3.hpp"
#include "Level4.hpp"
#include "Level5.hpp"
#include "audio.hpp"





#define screenwidth 1600
#define screenheight 900

typedef void(*FP)(void);

extern int current, previous, next;

extern FP fpLoad, fpInitialize, fpUpdate, fpDraw, fpFree, fpUnload;

enum GS_STATES
{
	
	GS_SPLASHSCREEN,
	GS_MAINMENU,
	GS_LEVEL1,
	GS_LEVEL2,
	GS_LEVEL3,
	GS_LEVEL4,
	GS_LEVEL5,

	GS_QUIT,
	GS_RESTART
};
