// ---------------------------------------------------------------------------
// includes
#pragma once
#include "allheaders.hpp"
#include "objects.hpp"
#include "movement.hpp"
#include "vpCollision.hpp"
#include "collision.hpp"
#include "collectibles.hpp"
#include "IncrementVariable.hpp"
#include <math.h>
#include "Level1.hpp"
#include "GSM.hpp"
#include "objectDecs.hpp"

// ---------------------------------------------------------------------------
// main

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
	AESysInit(hInstance, nCmdShow, 800, 600, 1, 60, true, NULL);

	// Changing the window title
	AESysSetWindowTitle("My New Demo!");

	// reset the system modules
	AESysReset();

	//set background color
	AEGfxSetBackgroundColor(0.81f, 0.6f, 0.46f);

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

	// Texture 1: From file
	pTexFront = AEGfxTextureLoad("Assets/FCat_Front.png");
	AE_ASSERT_MESG(pTexFront, "Failed to create texture1!!");

	pTexRight = AEGfxTextureLoad("Assets/FCat_Right.png");
	AE_ASSERT_MESG(pTexRight, "Failed to create texture2!!");

	pTexLeft = AEGfxTextureLoad("Assets/FCat_Left.png");
	AE_ASSERT_MESG(pTexLeft, "Failed to create texture2!!");

	// Loading textures (images) end
	//////////////////////////////////

	//////////////////////////////////
	// Creating Fonts	

	// Creating Fonts end
	//////////////////////////////////

	// Game Loop

	

	while (gGameRunning)
	{

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

		Level1_Initialize();

		while (next == current)
		{

			// Informing the system about the loop's start
			AESysFrameStart();

			//=============================================================================================
			// Input Loop
			//=============================================================================================

			AEInputUpdate();

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
			if (AEInputCheckTriggered(AEVK_ESCAPE) || 0 == AESysDoesWindowExist())
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

	}
	// Freeing the objects and textures

	// free the system
	AESysExit();
}
