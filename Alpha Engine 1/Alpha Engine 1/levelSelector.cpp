#include "allheaders.hpp"
#include "IncrementVariable.hpp"

square levels[10];

extern square buttons;
extern square background;
extern AEGfxVertexList* playMesh;
extern AEGfxVertexList* backgroundMesh;
extern square levelSelector;

extern int mousex;
extern int mousey;
extern int truemousex;
extern int truemousey;
extern square player;
extern AEGfxTexture* pTexMenuBackground ;
extern AEGfxTexture* pTexPlay;
extern AEGfxTexture* pTexTutorial;
extern AEGfxTexture* pTexCredits;
extern AEGfxTexture* pTexQuit;
extern f32 settingsbuttony;
extern f32 creditsbuttony;
extern f32 quitbuttony;


void levelSelector_Load()
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

void levelSelector_Initialize()
{

	for (int i = 0; i < 10; i++) {
		levels[i].x = 5000;
		levels[i].y = 5000;
		levels[i].width = 60;
		levels[i].height = 60;
		levels[i].halfW = 30;
		levels[i].halfH = 30;
	}

	float row1Height = 100;

	levels[0].x = -400;
	levels[0].y = row1Height;

	levels[1].x = -200;
	levels[1].y = row1Height;

	levels[2].x = 0;
	levels[2].y = row1Height;

	levels[3].x = 200;
	levels[3].y = row1Height;

	levels[4].x = 400;
	levels[4].y = row1Height;

	levels[5].x = -100;
	levels[5].y = row1Height - 150;

	levels[6].x = 100;
	levels[6].y = row1Height - 150;

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
	buttons.height = 120;
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
		-buttons.halfW, buttons.halfH, 0xFFFFFFFF, 0.0f, 0.0f);

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

void levelSelector_Update()
{

	AEGfxSetCamPosition(0, 0);

	AEInputGetCursorPosition(&mousex, &mousey);
	truemousex = (int)(mousex - screenwidth / 2);
	truemousey = (int)(-mousey + screenheight / 2);

	if (IsAreaClicked(levels[0].x, levels[0].y, buttons.halfW, buttons.halfH, truemousex, truemousey))
	{
		next = GS_LEVEL1;
	}

	if (IsAreaClicked(levels[1].x, levels[1].y, buttons.halfW, buttons.halfH, truemousex, truemousey))
	{
		next = GS_LEVEL2;
	}

	if (IsAreaClicked(levels[2].x, levels[2].y, buttons.halfW, buttons.halfH, truemousex, truemousey))
	{
		next = GS_LEVEL3;
	}

	if (IsAreaClicked(levels[3].x, levels[3].y, buttons.halfW, buttons.halfH, truemousex, truemousey))
	{
		next = GS_LEVEL4;
	}

	if (IsAreaClicked(levels[4].x, levels[4].y, buttons.halfW, buttons.halfH, truemousex, truemousey))
	{
		next = GS_LEVEL5;
	}

	if (IsAreaClicked(levels[5].x, levels[5].y, buttons.halfW, buttons.halfH, truemousex, truemousey))
	{
		next = GS_LEVEL6;
	}

	if (IsAreaClicked(levels[6].x, levels[6].y, buttons.halfW, buttons.halfH, truemousex, truemousey))
	{
		next = GS_LEVEL7;
	}


	updateSound();

}

void levelSelector_Draw()
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
	AEGfxSetPosition(levels[0].x, levels[0].y);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	// No texture 
	AEGfxTextureSet(pTexPlay, 0, 0);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(playMesh, AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);

	//Drawing 2nd "settings" button
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxSetPosition(levels[1].x, levels[1].y);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(pTexTutorial, 0, 0);
	AEGfxMeshDraw(playMesh, AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);

	//Drawing 3rd "credits" button 
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxSetPosition(levels[2].x, levels[2].y);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(pTexCredits, 0, 0);
	AEGfxMeshDraw(playMesh, AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);

	//Drawing 4th "quit" button
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxSetPosition(levels[3].x, levels[3].y);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(pTexQuit, 0, 0);
	AEGfxMeshDraw(playMesh, AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);


	//Drawing 5th "levelselect" button
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxSetPosition(levels[4].x, levels[4].y);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(pTexQuit, 0, 0);
	AEGfxMeshDraw(playMesh, AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);


	//Drawing 5th "levelselect" button
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxSetPosition(levels[5].x, levels[5].y);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(pTexQuit, 0, 0);
	AEGfxMeshDraw(playMesh, AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);



	//Drawing 5th "levelselect" button
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxSetPosition(levels[6].x, levels[6].y);
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

void levelSelector_Free()
{
	AEGfxMeshFree(playMesh);
	AEGfxMeshFree(backgroundMesh);

}

void levelSelector_Unload()
{
	AEGfxTextureUnload(pTexMenuBackground);
	AEGfxTextureUnload(pTexPlay);
	AEGfxTextureUnload(pTexTutorial);
	AEGfxTextureUnload(pTexCredits);
	AEGfxTextureUnload(pTexQuit);
	freeSound();
}