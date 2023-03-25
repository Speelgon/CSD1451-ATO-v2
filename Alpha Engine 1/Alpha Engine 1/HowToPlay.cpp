#include "allheaders.hpp"
#include "Mainmenu.hpp"
#include "IncrementVariable.hpp"
#include "howToPlay.hpp"

extern square buttons;
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
extern AEGfxTexture* pTexPlay;

void howToPlay_Load()
{
	std::cout << "GSM:Load\n";

	pTexMenuBackground = AEGfxTextureLoad("Assets/how_to_play.png");
	AE_ASSERT_MESG(pTexMenuBackground, "Failed to create menu background texture!!");

	pTexPlay = AEGfxTextureLoad("Assets/button_play.png");
	AE_ASSERT_MESG(pTexPlay, "Failed to create play button texture!!");


}

void howToPlay_Initialize()
{

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

void howToPlay_Update()
{

	AEGfxSetCamPosition(0, 0);

	AEInputGetCursorPosition(&mousex, &mousey);
	truemousex = (int)(mousex - screenwidth / 2);
	truemousey = (int)(-mousey + screenheight / 2);

	if (IsAreaClicked(buttons.x, buttons.y, buttons.halfW, buttons.halfH, truemousex, truemousey))
	{
		next = GS_LEVEL1;
	}

	updateSound();

}

void howToPlay_Draw()
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

void howToPlay_Free()
{
	AEGfxMeshFree(playMesh);
	AEGfxMeshFree(backgroundMesh);

}

void howToPlay_Unload()
{
	AEGfxTextureUnload(pTexMenuBackground);
	AEGfxTextureUnload(pTexPlay);


	freeSound();
}