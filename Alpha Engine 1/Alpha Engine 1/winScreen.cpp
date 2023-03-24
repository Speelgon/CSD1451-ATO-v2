#include "winScreen.hpp"

#include "allheaders.hpp"
#include "Mainmenu.hpp"
#include "IncrementVariable.hpp"
#include "utils.h"
square collected1;
square collected2;
square collected3;

square next_level_button, restart_button, main_menu_button;
AEGfxVertexList* buttonMesh = 0;

extern int collectible_count;

extern GS_STATES previousState;
extern square background;
extern AEGfxVertexList* playMesh;
extern AEGfxVertexList* backgroundMesh;
extern s8 fontId;
//char strBufferPLAY[5], strBufferHTP[12], strBufferCredits[8], strBufferQuit[5], strBufferTitle[14];
//char strBufferSettings[50];
//f32 TextWidth, TextHeight;
extern int mousex;
extern int mousey;
extern int truemousex;
extern int truemousey;
extern square player;
extern AEGfxTexture* pTexMenuBackground;
extern AEGfxTexture* pTexNext = 0;
extern AEGfxTexture* pTexRestart = 0;
extern AEGfxTexture* pTexReturn = 0;
extern f32 settingsbuttony;
extern f32 creditsbuttony;
extern f32 quitbuttony;

//for quit confirmation prompt
int state_for_quit_confirm;



void winScreen_Load()
{
	std::cout << "GSM:Load\n";

	pTexMenuBackground = AEGfxTextureLoad("Assets/MenuBackground.png");
	AE_ASSERT_MESG(pTexMenuBackground, "Failed to create menu background texture!!");

	pTexCollectible = AEGfxTextureLoad("Assets/collectible.png");
	AE_ASSERT_MESG(pTexCollectible, "Failed to create play button texture!!");

	pTexNext = AEGfxTextureLoad("Assets/button_next.png");
	AE_ASSERT_MESG(pTexNext, "Failed to create play button next!!");

	pTexRestart = AEGfxTextureLoad("Assets/button_restart.png");
	AE_ASSERT_MESG(pTexNext, "Failed to create restart button next!!");

	pTexReturn = AEGfxTextureLoad("Assets/button_return.png");
	AE_ASSERT_MESG(pTexNext, "Failed to create return button next!!");

}

void winScreen_Initialize()
{
	state_for_quit_confirm = current;
	collected1.x = -200;
	collected1.y = 0;

	collected1.width = 100;
	collected1.height = 100;
	collected1.halfW = collected1.width / 2;
	collected1.halfH = collected1.height / 2;

	collected2.x = 0;
	collected2.y = 0;

	collected2.width = 100;
	collected2.height = 100;
	collected2.halfW = collected1.width / 2;
	collected2.halfH = collected1.height / 2;


	collected3.x = 200;
	collected3.y = 0;

	collected3.width = 100;
	collected3.height = 100;
	collected3.halfW = collected1.width / 2;
	collected3.halfH = collected1.height / 2;

	background.x = 0;
	background.y = 0;
	background.width = screenwidth;
	background.height = screenheight;
	background.halfW = background.width / 2;
	background.halfH = background.height / 2;


	//=========================================

	next_level_button.x = -350;
	next_level_button.y = -150;

	next_level_button.width = 150;
	next_level_button.height = 80;
	next_level_button.halfW = next_level_button.width / 2;
	next_level_button.halfH = next_level_button.height / 2;

	restart_button.x = 0;
	restart_button.y = -150;

	restart_button.width = 150;
	restart_button.height = 80;
	restart_button.halfW = restart_button.width / 2;
	restart_button.halfH = restart_button.height / 2;

	main_menu_button.x = 350;
	main_menu_button.y = -150;

	main_menu_button.width = 150;
	main_menu_button.height = 80;
	main_menu_button.halfW = main_menu_button.width / 2;
	main_menu_button.halfH = main_menu_button.height / 2;


	AEGfxMeshStart();
	AEGfxTriAdd(
		-collected1.halfW, -collected1.halfW, 0xFFFFFF00, 0.0f, 1.0f,
		collected1.halfW, -collected1.halfW, 0xFFFFFF00, 1.0f, 1.0f,
		-collected1.halfW, collected1.halfW, 0xFFFFFF00, 0.0f, 0.0f);

	AEGfxTriAdd(
		collected1.halfW, -collected1.halfW, 0xFFFFFFFF, 1.0f, 1.0f,
		collected1.halfW, collected1.halfW, 0xFFFFFFFF, 1.0f, 0.0f,
		-collected1.halfW, collected1.halfW, 0xFFFFFFFF, 0.0f, 0.0f);

	// Saving the mesh (list of triangles) in pMesh1

	//playMesh is the mesh for the collectibles
	playMesh = AEGfxMeshEnd();
	AE_ASSERT_MESG(playMesh, "Failed to create playMesh!!");


	AEGfxMeshStart();
	AEGfxTriAdd(
		-next_level_button.halfW, -next_level_button.halfH, 0xFFFFFF00, 0.0f, 1.0f,
		next_level_button.halfW, -next_level_button.halfH, 0xFFFFFF00, 1.0f, 1.0f,
		-next_level_button.halfW, next_level_button.halfH, 0xFFFFFF00, 0.0f, 0.0f);

	AEGfxTriAdd(
		next_level_button.halfW, -next_level_button.halfH, 0xFFFFFFFF, 1.0f, 1.0f,
		next_level_button.halfW, next_level_button.halfH, 0xFFFFFFFF, 1.0f, 0.0f,
		-next_level_button.halfW, next_level_button.halfH, 0xFFFFFFFF, 0.0f, 0.0f);

	// Saving the mesh (list of triangles) in pMesh1

	buttonMesh = AEGfxMeshEnd();
	AE_ASSERT_MESG(buttonMesh, "Failed to create playMesh!!");


	AEGfxMeshStart();
	AEGfxTriAdd(
		-background.halfW, -background.halfH, 0xFFFFFF00, 0.0f, 1.0f,
		background.halfW, -background.halfH, 0xFFFFFF00, 1.0f, 1.0f,
		-background.halfW, background.halfH, 0xFFFFFF00, 0.0f, 0.0f);

	AEGfxTriAdd(
		background.halfW, -background.halfH, 0xFFFFFFFF, 1.0f, 1.0f,
		background.halfW, background.halfH, 0xFFFFFFFF, 1.0f, 0.0f,
		-background.halfW, background.halfH, 0xFFFFFFFF, 0.0f, 0.0f);

	// Saving the mesh (list of triangles) in pMesh1
	backgroundMesh = AEGfxMeshEnd();
	AE_ASSERT_MESG(backgroundMesh, "Failed to create backgroundMesh!!");

	initAudioList();

}

void winScreen_Update()
{
	AEGfxSetCamPosition(0, 0);
	player.x = 0;
	player.y = 0;
	AEInputGetCursorPosition(&mousex, &mousey);
	truemousex = (int)(mousex - screenwidth / 2 + player.x);
	truemousey = (int)(-mousey + screenheight / 2 + player.y);

	if (IsAreaClicked(next_level_button.x, next_level_button.y, next_level_button.halfW, next_level_button.halfH, truemousex, truemousey))
	{
		next = previousState+1;
	}

	if (IsAreaClicked(restart_button.x, restart_button.y, restart_button.halfW, restart_button.halfH, truemousex, truemousey))
	{
		next = previousState;
	}

	//include quit confirmation prompt
	if (IsAreaClicked(main_menu_button.x, main_menu_button.y, main_menu_button.halfW, main_menu_button.halfH, truemousex, truemousey))
	{
		//std::cout << "quit button clicked" << '\n';
		//quit_confirm = 1;
		//state_for_quit_confirm = 
		next = GS_QUITCONFIRM;
	}

	/*if (quit_confirm == 1)
	{
		std::cout << "Entered quit confirm" << '\n';
		quit_confirmation_prompt(quit_confirm);
	}*/

	updateSound();

}

void winScreen_Draw()
{
	//====================================//
	//			 Background Drawing		  //
	//====================================//

	// Drawing background
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

	// Set position for background
	AEGfxSetPosition(background.x, background.y);

	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Texture for platform
	AEGfxTextureSet(pTexMenuBackground, 0.0f, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(backgroundMesh, AE_GFX_MDM_TRIANGLES);

	AEGfxSetTransparency(1.0f);

	//====================================//
	//			 Button Drawing			  //
	//====================================//

	if (collectible_count > 0) {

		// Drawing "collectible"" button
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		AEGfxSetBlendMode(AE_GFX_BM_BLEND);
		// Set position 
		AEGfxSetPosition(collected1.x, collected1.y);
		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// No texture 
		AEGfxTextureSet(pTexCollectible, 0, 0);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(playMesh, AE_GFX_MDM_TRIANGLES);
		AEGfxSetTransparency(1.0f);
	}

	if (collectible_count > 1) {
	
		//Drawing 2nd "collectible" button
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		AEGfxSetBlendMode(AE_GFX_BM_BLEND);
		AEGfxSetPosition(collected2.x, collected2.y);
		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		AEGfxTextureSet(pTexCollectible, 0, 0);
		AEGfxMeshDraw(playMesh, AE_GFX_MDM_TRIANGLES);
		AEGfxSetTransparency(1.0f);
	}

	if (collectible_count > 2) {
		//Drawing 3rd "collectible" button 
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		AEGfxSetBlendMode(AE_GFX_BM_BLEND);
		AEGfxSetPosition(collected3.x, collected3.y);
		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		AEGfxTextureSet(pTexCollectible, 0, 0);
		AEGfxMeshDraw(playMesh, AE_GFX_MDM_TRIANGLES);
		AEGfxSetTransparency(1.0f);
	}
	//Drawing next level button 
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxSetPosition(next_level_button.x, next_level_button.y);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(pTexNext, 0, 0);
	AEGfxMeshDraw(buttonMesh, AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);

	//Drawing restart button
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxSetPosition(restart_button.x, restart_button.y);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(pTexRestart, 0, 0);
	AEGfxMeshDraw(buttonMesh, AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);

	//Drawing mainmenu button
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxSetPosition(main_menu_button.x, main_menu_button.y);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(pTexReturn, 0, 0);
	AEGfxMeshDraw(buttonMesh, AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);


	//====================================//
	//			  TEXT PRINTING			  //
	//====================================//
	// 
	//PRINT "LEAP CLIMBERS" TEXT
	//AEGfxGetPrintSize(fontId, strBufferTitle, f32(1), TextWidth, TextHeight);
	//memset(strBufferTitle, 0, 5 * sizeof(char));
	//sprintf_s(strBufferTitle, "LEAP CLIMBERS");
	//AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	//AEGfxPrint(fontId, strBufferTitle, -0.22f, 0.5f, 1, 1.f, 1.f, 1.f);

	//PRINT "PLAY" TEXT
	//AEGfxGetPrintSize(fontId, strBufferPLAY, f32(1), TextWidth, TextHeight);
	//memset(strBufferPLAY, 0, 5 * sizeof(char));
	//sprintf_s(strBufferPLAY, "PLAY");
	//AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	/*AEGfxPrint(fontId, strBufferPLAY, -0.065f, 0.14f, 1, 0.f, 0.f, 0.f);*/

	////PRINT "TUTORIAL" TEXT
	//AEGfxGetPrintSize(fontId, strBufferHTP, f32(1), TextWidth, TextHeight);
	//memset(strBufferHTP, 0, 12 * sizeof(char));
	//sprintf_s(strBufferHTP, "TUTORIAL");
	//AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	//AEGfxPrint(fontId, strBufferHTP, -0.14f, -0.13f, 1, 0.f, 0.f, 0.f);

	////PRINT "CREDITS" TEXT
	//AEGfxGetPrintSize(fontId, strBufferCredits, f32(1), TextWidth, TextHeight);
	//memset(strBufferCredits, 0, 8 * sizeof(char));
	//sprintf_s(strBufferCredits, "CREDITS");
	//AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	//AEGfxPrint(fontId, strBufferCredits, -0.12f, -0.4f, 1, 0.f, 0.f, 0.f);
	//
	////PRINT "QUIT" TEXT
	//AEGfxGetPrintSize(fontId, strBufferQuit, f32(1), TextWidth, TextHeight);
	//memset(strBufferQuit, 0, 5 * sizeof(char));
	//sprintf_s(strBufferQuit, "QUIT");
	//AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	//AEGfxPrint(fontId, strBufferQuit, -0.065f, -0.66f, 1, 0.f, 0.f, 0.f);
}

void winScreen_Free()
{
	AEGfxMeshFree(playMesh);
	AEGfxMeshFree(backgroundMesh);
	AEGfxMeshFree(buttonMesh);

}

void winScreen_Unload()
{
	AEGfxTextureUnload(pTexMenuBackground);
	AEGfxTextureUnload(pTexCollectible);
	AEGfxTextureUnload(pTexNext);
	AEGfxTextureUnload(pTexRestart);
	AEGfxTextureUnload(pTexReturn);
}
