#pragma once
#include "allheaders.hpp"
#include "Mainmenu.hpp"
#include "SplashScreen.hpp"
int current = 0, previous = 0, next = 0;

FP fpLoad = nullptr, fpInitialize = nullptr, fpUpdate = nullptr, fpDraw = nullptr, fpFree = nullptr, fpUnload = nullptr;

// ----------------------------------------------------------------------------
// This function prints GSM initialize to the output stream
// It sets all states to a staring state.
// ----------------------------------------------------------------------------

void GSM_Initialize(int startingState)
{
	std::cout << "GSM:Initialize\n";
	current = previous = next = startingState;
}

// ----------------------------------------------------------------------------
// This function prints GSM:Update to the output stream and
// loads the function pointers to functions declared in level1.c based
// on the current state of the game, which is initialized in GSM_Initialize
// ----------------------------------------------------------------------------

void GSM_Update()
{
	//some unfinishd code here
	std::cout << "GSM:Update\n";
	switch (current)
	{
	case GS_SPLASHSCREEN:			//Loads the function pointers for MAINMENU

		fpLoad = SplashScreen_Load;
		fpInitialize = SplashScreen_Initialize;
		fpUpdate = SplashScreen_Update;
		fpDraw = SplashScreen_Draw;
		fpFree = SplashScreen_Free;
		fpUnload = SplashScreen_Unload;
		break;

	case GS_MAINMENU:			//Loads the function pointers for MAINMENU
		
		fpLoad = Mainmenu_Load;
		fpInitialize = Mainmenu_Initialize;
		fpUpdate = Mainmenu_Update;
		fpDraw = Mainmenu_Draw;
		fpFree = Mainmenu_Free;
		fpUnload = Mainmenu_Unload;
		break;

	case GS_LEVEL1:
		fpLoad = Level1NEW_Load;
		fpInitialize = Level1NEW_Initialize;
		fpUpdate = Level1NEW_Update;
		fpDraw = Level1NEW_Draw;
		fpFree = Level1NEW_Free;
		fpUnload = Level1NEW_Unload;
		
		break;

	case GS_LEVEL2:	
		fpLoad = Level2_Load;
		fpInitialize = Level2_Initialize;
		fpUpdate = Level2_Update;
		fpDraw = Level2_Draw;
		fpFree = Level2_Free;
		fpUnload = Level2_Unload;
		break;
	
	case GS_LEVEL3:
		fpLoad = Level3_Load;
		fpInitialize = Level3_Initialize;
		fpUpdate = Level3_Update;
		fpDraw = Level3_Draw;
		fpFree = Level3_Free;
		fpUnload = Level3_Unload;
		break;

	case GS_LEVEL4:
		fpLoad = Level4_Load;
		fpInitialize = Level4_Initialize;
		fpUpdate = Level4_Update;
		fpDraw = Level4_Draw;
		fpFree = Level4_Free;
		fpUnload = Level4_Unload;
		break;

	case GS_LEVEL5:
		fpLoad = Level5_Load;
		fpInitialize = Level5_Initialize;
		fpUpdate = Level5_Update;
		fpDraw = Level5_Draw;
		fpFree = Level5_Free;
		fpUnload = Level5_Unload;
		break;

			
	case GS_RESTART:		//Breaks the current case if the gamestate is required to restart
		break;
	case GS_QUIT:			//Breaks the current case if the gamestate is required to quit
		break;
	default:
		break;
	}

}
