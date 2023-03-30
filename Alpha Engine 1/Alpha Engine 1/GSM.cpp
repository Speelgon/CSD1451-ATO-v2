//==========================================================
// file		: GSM.cpp
// 
// author   : Owen Quek
// co-author: Ng Wen Wen
// co-author: Kathleen Lim
// 
// email	: o.quek@digipen.edu
//			  wenwen.ng@digipen.edu
//            l.kathleenxiangxuan@digipen.edu
//
// brief	: collision.c is where our main collision checks and calculations are done
//
// Copyright © 2023 DigiPen, All rights reserved.
//==========================================================



#pragma once
#include "allheaders.hpp"
#include "Mainmenu.hpp"
#include "SplashScreen.hpp"
#include "Quit_Confirm.hpp"
#include "PauseScreen.hpp"
#include "Mainmenu_prompt.hpp"
int current = GS_SPLASHSCREEN, previous = 0, next = 0;

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

	case GS_LEVEL6:
		fpLoad = Level6_Load;
		fpInitialize = Level6_Initialize;
		fpUpdate = Level6_Update;
		fpDraw = Level6_Draw;
		fpFree = Level6_Free;
		fpUnload = Level6_Unload;
		break;


	case GS_LEVEL7:
		fpLoad = Level7_Load;
		fpInitialize = Level7_Initialize;
		fpUpdate = Level7_Update;
		fpDraw = Level7_Draw;
		fpFree = Level7_Free;
		fpUnload = Level7_Unload;
		break;
			
	case GS_LEVELSELECTOR:
		fpLoad = levelSelector_Load;
		fpInitialize = levelSelector_Initialize;
		fpUpdate = levelSelector_Update;
		fpDraw = levelSelector_Draw;
		fpFree = levelSelector_Free;
		fpUnload = levelSelector_Unload;
		break;


	case GS_WINSCREEN:
		fpLoad = winScreen_Load;
		fpInitialize = winScreen_Initialize;
		fpUpdate = winScreen_Update;
		fpDraw = winScreen_Draw;
		fpFree = winScreen_Free;
		fpUnload = winScreen_Unload;
		break;


	case GS_HOWTOPLAY:
		fpLoad = howToPlay_Load;
		fpInitialize = howToPlay_Initialize;
		fpUpdate = howToPlay_Update;
		fpDraw = howToPlay_Draw;
		fpFree = howToPlay_Free;
		fpUnload = howToPlay_Unload;
		break;

	case GS_CREDITS:
		fpLoad = Credits_Load;
		fpInitialize = Credits_Initialize;
		fpUpdate = Credits_Update;
		fpDraw = Credits_Draw;
		fpFree = Credits_Free;
		fpUnload = Credits_Unload;
		break;

	case GS_RESTART:		//Breaks the current case if the gamestate is required to restart
		break;
	case GS_QUIT:			//Breaks the current case if the gamestate is required to quit
		break;
	case GS_QUITCONFIRM:
		fpLoad = quit_confirm_Load;
		fpInitialize = quit_confirm_Initialize;
		fpUpdate = quit_confirm_Update;
		fpDraw = quit_confirm_Draw;
		fpFree = quit_confirm_Free;
		fpUnload = quit_confirm_Unload;
		break;

	case GS_MAINMENUCONFIRM:
		fpLoad = mainmenu_prompt_Load;
		fpInitialize = mainmenu_prompt_Initialize;
		fpUpdate = mainmenu_prompt_Update;
		fpDraw = mainmenu_prompt_Draw;
		fpFree = mainmenu_prompt_Free;
		fpUnload = mainmenu_prompt_Unload;
		break;

	case GS_PAUSEMENU:
		fpLoad = Pausemenu_Load;
		fpInitialize = Pausemenu_Initialize;
		fpUpdate = Pausemenu_Update;
		fpDraw = Pausemenu_Draw;
		fpFree = Pausemenu_Free;
		fpUnload = Pausemenu_Unload;
		break;
	default:
		break;
	}

}
