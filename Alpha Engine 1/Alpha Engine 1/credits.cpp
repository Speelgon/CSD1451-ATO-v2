//==========================================================
// file		: credits.cpp
// 
// author   : Ng Wen Wen
// 
// email	: wenwen.ng@digipen.edu
//			  
// brief	: credits.cpp is where the credits functions are defined
//
// Copyright © 2023 DigiPen, All rights reserved.
//==========================================================

#include "allheaders.hpp"
#include "IncrementVariable.hpp"
#include "utils.h"

extern square buttons;
extern square background;
extern AEGfxVertexList* playMesh;
extern AEGfxVertexList* backgroundMesh;

extern int mousex;
extern int mousey;
extern int truemousex;
extern int truemousey;
extern square player;
extern AEGfxTexture* pTexMenuBackground;
extern AEGfxTexture* pTexCredits_1 = 0;
extern AEGfxTexture* pTexCredits_2 = 0;
extern AEGfxTexture* pTexCredits_3 = 0;
extern AEGfxTexture* pTexCredits_4 = 0;
extern AEGfxTexture* pTexCredits_5 = 0;
extern AEGfxTexture* pTexCredits_6 = 0;

extern f64 normalElapsedTime;
extern int timer;
extern f64 interval;
extern f64 elapsedtime;




void Credits_Load()
{
	std::cout << "GSM:Load\n";

	pTexCredits_1 = AEGfxTextureLoad("Assets/credits_1.png");
	AE_ASSERT_MESG(pTexCredits_1, "Failed to create credits page 1 texture!!");

	pTexCredits_2 = AEGfxTextureLoad("Assets/credits_2.png");
	AE_ASSERT_MESG(pTexCredits_1, "Failed to create credits page 2 texture!!");

	pTexCredits_3 = AEGfxTextureLoad("Assets/credits_3.png");
	AE_ASSERT_MESG(pTexCredits_1, "Failed to create credits page 3 texture!!");

	pTexCredits_4 = AEGfxTextureLoad("Assets/credits_4.png");
	AE_ASSERT_MESG(pTexCredits_1, "Failed to create credits page 4 texture!!");

	pTexCredits_5 = AEGfxTextureLoad("Assets/credits_5.png");
	AE_ASSERT_MESG(pTexCredits_1, "Failed to create credits page 5 texture!!");

	pTexCredits_6 = AEGfxTextureLoad("Assets/credits_6.png");
	AE_ASSERT_MESG(pTexCredits_1, "Failed to create credits page 6 texture!!");


}

void Credits_Initialize()
{

	timer = 6;
	elapsedtime = 0.0f;
	interval = 1.0f;


	background.x = 0;
	background.y = 0;
	background.width = screenwidth;
	background.height = screenheight;
	background.halfW = background.width / 2;
	background.halfH = background.height / 2;

	//AEGfxMeshStart();
	//AEGfxTriAdd(
	//	-buttons.halfW, -buttons.halfH, 0xFFFFFF00, 0.0f, 1.0f,
	//	buttons.halfW, -buttons.halfH, 0xFFFFFF00, 1.0f, 1.0f,
	//	-buttons.halfW, buttons.halfH, 0xFFFFFF00, 0.0f, 0.0f);

	//AEGfxTriAdd(
	//	buttons.halfW, -buttons.halfH, 0xFFFFFFFF, 1.0f, 1.0f,
	//	buttons.halfW, buttons.halfH, 0xFFFFFFFF, 1.0f, 0.0f,
	//	-buttons.halfW, buttons.halfH, 0xFFFFFFFF, 0.0f, 0.0f);

	//// Saving the mesh (list of triangles) in pMesh1

	//playMesh = AEGfxMeshEnd();
	//AE_ASSERT_MESG(playMesh, "Failed to create playMesh!!");


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

void Credits_Update()
{

	AEGfxSetCamPosition(0, 0);

	AEInputGetCursorPosition(&mousex, &mousey);
	truemousex = (int)(mousex - screenwidth / 2);
	truemousey = (int)(-mousey + screenheight / 2);




	updateSound();

}

void Credits_Draw()
{
	
	if (timer == 6)
	{
		//========================================//
		//			 Credits Page 1 Drawing		  //
		//========================================//

		// Drawing background
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		AEGfxSetBlendMode(AE_GFX_BM_BLEND);

		// Set position for background
		AEGfxSetPosition(background.x, background.y);

		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Texture for platform
		AEGfxTextureSet(pTexCredits_1, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(backgroundMesh, AE_GFX_MDM_TRIANGLES);

		AEGfxSetTransparency(1.0f);
	}

	
	if (timer == 5)
	{
		//========================================//
		//			 Credits Page 2 Drawing		  //
		//========================================//

		// Drawing background
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		AEGfxSetBlendMode(AE_GFX_BM_BLEND);

		// Set position for background
		AEGfxSetPosition(background.x, background.y);

		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Texture for platform
		AEGfxTextureSet(pTexCredits_2, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(backgroundMesh, AE_GFX_MDM_TRIANGLES);

		AEGfxSetTransparency(1.0f);

	}

	if (timer == 4)
	{
		//========================================//
		//			 Credits Page 3 Drawing		  //
		//========================================//

		// Drawing background
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		AEGfxSetBlendMode(AE_GFX_BM_BLEND);

		// Set position for background
		AEGfxSetPosition(background.x, background.y);

		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Texture for platform
		AEGfxTextureSet(pTexCredits_3, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(backgroundMesh, AE_GFX_MDM_TRIANGLES);

		AEGfxSetTransparency(1.0f);
	}

	if (timer == 3)
	{
		//========================================//
		//			 Credits Page 4 Drawing		  //
		//========================================//

		// Drawing background
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		AEGfxSetBlendMode(AE_GFX_BM_BLEND);

		// Set position for background
		AEGfxSetPosition(background.x, background.y);

		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Texture for platform
		AEGfxTextureSet(pTexCredits_4, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(backgroundMesh, AE_GFX_MDM_TRIANGLES);

		AEGfxSetTransparency(1.0f);
	}

	if (timer == 2)
	{
		//========================================//
		//			 Credits Page 5 Drawing		  //
		//========================================//

		// Drawing background
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		AEGfxSetBlendMode(AE_GFX_BM_BLEND);

		// Set position for background
		AEGfxSetPosition(background.x, background.y);

		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Texture for platform
		AEGfxTextureSet(pTexCredits_5, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(backgroundMesh, AE_GFX_MDM_TRIANGLES);

		AEGfxSetTransparency(1.0f);
	}

	if (timer == 1)
	{
		//========================================//
		//			 Credits Page 1 Drawing		  //
		//========================================//

		// Drawing background
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		AEGfxSetBlendMode(AE_GFX_BM_BLEND);

		// Set position for background
		AEGfxSetPosition(background.x, background.y);

		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Texture for platform
		AEGfxTextureSet(pTexCredits_6, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(backgroundMesh, AE_GFX_MDM_TRIANGLES);

		AEGfxSetTransparency(1.0f);
	}

	if (timer == 0)
	{
		next = GS_MAINMENU;
	}
	timer = normalUpdateTimer(&elapsedtime, timer, interval);


}

void Credits_Free()
{
	/*AEGfxMeshFree(playMesh);*/
	AEGfxMeshFree(backgroundMesh);

}

void Credits_Unload()
{
	AEGfxTextureUnload(pTexCredits_1);
	AEGfxTextureUnload(pTexCredits_2);
	AEGfxTextureUnload(pTexCredits_3);
	AEGfxTextureUnload(pTexCredits_4);
	AEGfxTextureUnload(pTexCredits_5);
	AEGfxTextureUnload(pTexCredits_6);
	freeSound();
}