//==========================================================
// file		: Main.cpp
// 
// author   : Owen Quek
// 
// email	: o.quek@digipen.edu
//
// brief	: Main.cpp is where the game runs
//
// Copyright � 2023 DigiPen, All rights reserved.
//==========================================================

// ---------------------------------------------------------------------------
// includes
#pragma once
#include "allheaders.hpp"
#include "objects.hpp"
#include "movement.hpp"
#include "vpCollision.hpp"
#include "collision.hpp"
#include "IncrementVariable.hpp"
#include <math.h>
#include "Level1.hpp"
#include "GSM.hpp"
#include "objectDecs.hpp"
#include "Mainmenu.hpp"



// ---------------------------------------------------------------------------
// main
s8 fontId;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	/////////////////
// Initialization

// Using custom window procedure
	AESysInit(hInstance, nCmdShow, screenwidth, screenheight, 0, 60, true, NULL);

	// Changing the window title
	AESysSetWindowTitle("Leap Climbers");

	SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);

	// reset the system modules
	AESysReset();

	//set background color
	AEGfxSetBackgroundColor(0.81f, 0.6f, 0.46f);

	fontId = AEGfxCreateFont("Assets/Roboto-Regular.ttf", 24);
	// Initialization end
	/////////////////////

	///////////////////////
	// Variable declaration

	int gGameRunning = 1;
	
	/*float minWorldX = 10;
	float minWorldY = 10;*/

	// Variable declaration end
	///////////////////////////

	////////////////////////////////
	// Creating the objects (Shapes)

	// Creating the objects (Shapes) end
	////////////////////////////////////

	////////////////////////////
	// Loading textures (images)

	// Loading textures (images) end
	//////////////////////////////////

	//////////////////////////////////
	// Creating Fonts	

	// Creating Fonts end
	//////////////////////////////////

	// Game Loop

	//current = previous = next = GS_LEVEL1;
	while (gGameRunning)
	{
		// current = 1;
		GSM_Initialize(current);

		if (current != GS_RESTART)
		{
			GSM_Update();
			fpLoad();
		}
		else
		{
			next = previous;
			current = previous;
		}

		std::cout << "CURRENT IS:" << current << '\n';

		fpInitialize();

		while (current == next)
		{

			// Informing the system about the loop's start
			AESysFrameStart();

			//=============================================================================================
			// Input Loop
			//=============================================================================================

			AEInputUpdate();

			AEAudioUpdate();

			//=============================================================================================
			// Input Loop end
			//=============================================================================================

			//=============================================================================================
			// Game loop update	
			//=============================================================================================

			fpUpdate();

			//=============================================================================================
			// Game loop update end
			//=============================================================================================

			//------------------------------------------------------------------------------------------------------------------------------------------------------------
			//------------------------------------------------------------------------------------------------------------------------------------------------------------
			//------------------------------------------------------------------------------------------------------------------------------------------------------------

			//=============================================================================================
			// Game loop draw
			//=============================================================================================

			fpDraw();

			//=============================================================================================
			// Game loop draw end
			//=============================================================================================

			// Informing the system about the loop's end
			AESysFrameEnd();

			// check if forcing the application to quit
			if (0 == AESysDoesWindowExist())
			{
				current = GS_QUIT;
				gGameRunning = 0;
			}
		}

		fpFree();

		if (next != GS_RESTART)
		{
			fpUnload();
		}
		previous = current;
		current = next;

		if (current == GS_QUIT)
		{
			gGameRunning = 0;
		}

		

	}
	// Freeing the objects and textures
	AEGfxDestroyFont(fontId);
	// free the system
	AESysExit();
}
