#pragma once
#include "allheaders.hpp"
#include "Mainmenu.hpp"

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
	case GS_MAINMENU:			//Loads the function pointers for MAINMENU
		
		fpLoad = Mainmenu_Load;
		fpInitialize = Mainmenu_Initialize;
		fpUpdate = Mainmenu_Update;
		fpDraw = Mainmenu_Draw;
		fpFree = Mainmenu_Free;
		fpUnload = Mainmenu_Unload;
		break;

	case GS_LEVEL1:
		fpLoad = Level1_Load;
		fpInitialize = Level1_Initialize;
		fpUpdate = Level1_Update;
		fpDraw = Level1_Draw;
		fpFree = Level1_Free;
		fpUnload = Level1_Unload;
		break;

	case GS_LEVEL2:			//Loads the function pointers for level 2
		break;
	case GS_RESTART:		//Breaks the current case if the gamestate is required to restart
		break;
	case GS_QUIT:			//Breaks the current case if the gamestate is required to quit
		break;
	default:
		break;
	}

}