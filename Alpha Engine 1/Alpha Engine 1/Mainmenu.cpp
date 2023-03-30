//==========================================================
// file		: Mainmenu.cpp
// 
// author   : Ng Wen Wen
// co-author: Ng Yue Zhi
// 
// email	: wenwen.ng@digipen.edu
//			  n.yuezhi@digipen.edu           
// 
// brief	: Mainmenu.cpp is where our main collision checks and calculations are done
//
// Copyright © 2023 DigiPen, All rights reserved.
//==========================================================


#include "allheaders.hpp"
#include "Mainmenu.hpp"
#include "IncrementVariable.hpp"

square buttons;
square background;
AEGfxVertexList* playMesh;
AEGfxVertexList* backgroundMesh;
square levelSelector;
extern s8 fontId;
//char strBufferPLAY[5], strBufferHTP[12], strBufferCredits[8], strBufferQuit[5], strBufferTitle[14];
//char strBufferSettings[50];
//f32 TextWidth, TextHeight;
extern int mousex;
extern int mousey;
extern int truemousex;
extern int truemousey;
extern square player;
extern AEGfxTexture* pTexMenuBackground = 0;
extern AEGfxTexture* pTexPlay = 0;
extern AEGfxTexture* pTexTutorial = 0;
extern AEGfxTexture* pTexCredits = 0;
extern AEGfxTexture* pTexQuit = 0;
f32 settingsbuttony;
f32 creditsbuttony;
f32 quitbuttony;


void Mainmenu_Load()
{
	std::cout << "GSM:Load\n";

	pTexMenuBackground = AEGfxTextureLoad("Assets/MenuBackground.png");
	AE_ASSERT_MESG(pTexMenuBackground, "Failed to create menu background texture!!");

	pTexPlay = AEGfxTextureLoad("Assets/button_play.png");
	AE_ASSERT_MESG(pTexPlay, "Failed to create play button texture!!");

	pTexTutorial = AEGfxTextureLoad("Assets/button_tutorial.png");
	AE_ASSERT_MESG(pTexTutorial, "Failed to create tutorial button texture!!");

	pTexCredits = AEGfxTextureLoad("Assets/button_credits.png");
	AE_ASSERT_MESG(pTexCredits, "Failed to create credits button texture!!");

	pTexQuit = AEGfxTextureLoad("Assets/button_quit.png");
	AE_ASSERT_MESG(pTexQuit, "Failed to create quit button texture!!");
}

void Mainmenu_Initialize()
{

	levelSelector.x = 150;
	levelSelector.y = 0;
	levelSelector.width = 120;
	levelSelector.height = 60;
	levelSelector.halfW = buttons.width / 2;
	levelSelector.halfH = buttons.height / 2;



	buttons.x = 0;
	buttons.y = 70;
	settingsbuttony = buttons.y - 80;
	creditsbuttony = buttons.y - 160;
	quitbuttony = buttons.y - 240;
	buttons.width = 120;
	buttons.height = 60;
	buttons.halfW = buttons.width / 2;
	buttons.halfH = buttons.height / 2;



	background.x = 0;
	background.y = 0;
	background.width = screenwidth;
	background.height = screenheight;
	background.halfW = background.width / 2;
	background.halfH = background.height / 2;

	AEGfxMeshStart();
	AEGfxTriAdd(
		-buttons.halfW, -buttons.halfH, 0xFFFFFF00, 0.0f, 1.0f,
		buttons.halfW, -buttons.halfH, 0xFFFFFF00, 1.0f, 1.0f,
		-buttons.halfW, buttons.halfH, 0xFFFFFF00, 0.0f, 0.0f);

	AEGfxTriAdd(
		buttons.halfW, -buttons.halfH, 0xFFFFFFFF, 1.0f, 1.0f,
		buttons.halfW, buttons.halfH, 0xFFFFFFFF, 1.0f, 0.0f,
		-buttons.halfW,buttons.halfH, 0xFFFFFFFF, 0.0f, 0.0f);

	// Saving the mesh (list of triangles) in pMesh1

	playMesh = AEGfxMeshEnd();
	AE_ASSERT_MESG(playMesh, "Failed to create playMesh!!");


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

void Mainmenu_Update()
{

	AEGfxSetCamPosition(0, 0);

	AEInputGetCursorPosition(&mousex, &mousey);
	truemousex = (int)(mousex - screenwidth / 2);
	truemousey = (int) ( - mousey + screenheight / 2);

	if (IsAreaClicked(buttons.x, buttons.y, buttons.halfW, buttons.halfH, truemousex, truemousey))
	{
		next = GS_LEVEL1;
	}

	if (IsAreaClicked(buttons.x, settingsbuttony, buttons.halfW, buttons.halfH, truemousex, truemousey))
	{
		next = GS_HOWTOPLAY;
	}

	if (IsAreaClicked(buttons.x, creditsbuttony, buttons.halfW, buttons.halfH, truemousex, truemousey))
	{
		next = GS_CREDITS;
	}

	if (IsAreaClicked(buttons.x, quitbuttony, buttons.halfW, buttons.halfH, truemousex, truemousey))
	{
		next = GS_QUIT;
	}
	
	if (IsAreaClicked(levelSelector.x, levelSelector.y, buttons.halfW, buttons.halfH, truemousex, truemousey))
	{
		next = GS_LEVELSELECTOR;
	}

	updateSound();

}

void Mainmenu_Draw()
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
	
	// Drawing top "play" button
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	// Set position 
	AEGfxSetPosition(buttons.x, buttons.y);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	// No texture 
	AEGfxTextureSet(pTexPlay, 0, 0);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(playMesh, AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);

	//Drawing 2nd "settings" button
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxSetPosition(buttons.x, settingsbuttony);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(pTexTutorial, 0, 0);
	AEGfxMeshDraw(playMesh, AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);

	//Drawing 3rd "credits" button 
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxSetPosition(buttons.x, creditsbuttony);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(pTexCredits, 0, 0);
	AEGfxMeshDraw(playMesh, AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);

	//Drawing 4th "quit" button
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxSetPosition(buttons.x, quitbuttony);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(pTexQuit, 0, 0);
	AEGfxMeshDraw(playMesh, AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);


	//Drawing 5th "levelselect" button
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxSetPosition(levelSelector.x, levelSelector.y);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(pTexQuit, 0, 0);
	AEGfxMeshDraw(playMesh, AE_GFX_MDM_TRIANGLES);
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

void Mainmenu_Free()
{
	AEGfxMeshFree(playMesh);
	AEGfxMeshFree(backgroundMesh);

}

void Mainmenu_Unload()
{
	AEGfxTextureUnload(pTexMenuBackground);
	AEGfxTextureUnload(pTexPlay);
	AEGfxTextureUnload(pTexTutorial);
	AEGfxTextureUnload(pTexCredits);
	AEGfxTextureUnload(pTexQuit);
	freeSound();
}