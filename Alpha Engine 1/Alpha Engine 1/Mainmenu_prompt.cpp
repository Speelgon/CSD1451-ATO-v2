//==========================================================
// file		: Mainmenu_prompt.cpp
// 
// author   : Kathleen Lim
// 
// email	: l.kathleenxiangxuan@digipen.edu
//
// brief	: Mainmenu_prompt.cpp contains logic to ask players for double confirmation
//
// Copyright © 2023 DigiPen, All rights reserved.
//==========================================================
#include "allheaders.hpp"
#include "IncrementVariable.hpp"
#include "winScreen.hpp"

extern square background;
extern int mousex;
extern int mousey;
extern int truemousex;
extern int truemousey;
extern square player;

#define screenwidth 1600
#define screenheight 900
extern AEGfxVertexList* backgroundMesh;
extern AEGfxVertexList* button_mesh;
extern square yes_button;
extern f32 no_buttonx;
extern f32 no_buttony;

extern AEGfxTexture* pTexYes;
extern AEGfxTexture* pTexNo;
extern AEGfxTexture* pTexConfirmationBackground;

void mainmenu_prompt_Load()
{
	std::cout << "GSM:Load\n";
	
	pTexConfirmationBackground = AEGfxTextureLoad("Assets/confirmation_text.png");
	AE_ASSERT_MESG(pTexConfirmationBackground, "Failed to create background texture!!");

	pTexYes = AEGfxTextureLoad("Assets/button_yes.png");
	AE_ASSERT_MESG(pTexYes, "Failed to create yes button texture!!");

	pTexNo = AEGfxTextureLoad("Assets/button_no.png");
	AE_ASSERT_MESG(pTexNo, "Failed to create no button texture!!");
}

void mainmenu_prompt_Initialize()
{
	AEGfxSetBackgroundColor(0.8f, 0.6f, 0.2f);

	no_buttonx = -150;
	no_buttony = 50;

	yes_button.x = 150;
	yes_button.y = 50;

	yes_button.width = 200;
	yes_button.height = 80;
	yes_button.halfW = yes_button.width / 2;
	yes_button.halfH = yes_button.height / 2;

	background.x = 0;
	background.y = 0;
	background.width = screenwidth;
	background.height = screenheight;
	background.halfW = background.width / 2;
	background.halfH = background.height / 2;

	AEGfxMeshStart();
	AEGfxTriAdd(
		-yes_button.halfW, -yes_button.halfH, 0xFFFFFF00, 0.0f, 1.0f,
		yes_button.halfW, -yes_button.halfH, 0xFFFFFF00, 1.0f, 1.0f,
		-yes_button.halfW, yes_button.halfH, 0xFFFFFF00, 0.0f, 0.0f);

	AEGfxTriAdd(
		yes_button.halfW, -yes_button.halfH, 0xFFFFFFFF, 1.0f, 1.0f,
		yes_button.halfW, yes_button.halfH, 0xFFFFFFFF, 1.0f, 0.0f,
		-yes_button.halfW, yes_button.halfH, 0xFFFFFFFF, 0.0f, 0.0f);

	// Saving the mesh (list of triangles) in pMesh1

	button_mesh = AEGfxMeshEnd();
	AE_ASSERT_MESG(button_mesh, "Failed to create button_mesh!!");

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


}

void mainmenu_prompt_Update()
{
	
	AEGfxSetCamPosition(0, 0);
	player.x = 0;
	player.y = 0;
	AEInputGetCursorPosition(&mousex, &mousey);
	truemousex = (int)(mousex - screenwidth / 2 + player.x);
	truemousey = (int)(-mousey + screenheight / 2 + player.y);

	if (IsAreaClicked(yes_button.x, yes_button.y, yes_button.halfW, yes_button.halfH, truemousex, truemousey))
	{
		std::cout << "Yes button clicked" << '\n';
		next = GS_MAINMENU;
	}

	if (IsAreaClicked(no_buttonx, no_buttony, yes_button.halfW, yes_button.halfH, truemousex, truemousey))
	{
		std::cout << "no button clicked" << '\n';
		next = GS_PAUSEMENU;
	}
}

void mainmenu_prompt_Draw()
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
	AEGfxTextureSet(pTexConfirmationBackground, 0.0f, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(backgroundMesh, AE_GFX_MDM_TRIANGLES);

	AEGfxSetTransparency(1.0f);

	//Drawing yes button 
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxSetPosition(yes_button.x, yes_button.y);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(pTexYes, 0, 0);
	AEGfxMeshDraw(button_mesh, AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);

	//Drawing no button 
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxSetPosition(no_buttonx, no_buttony);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(pTexNo, 0, 0);
	AEGfxMeshDraw(button_mesh, AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);


}

void mainmenu_prompt_Free()
{
	AEGfxMeshFree(button_mesh);
}

void mainmenu_prompt_Unload()
{
	AEGfxTextureUnload(pTexYes);
	AEGfxTextureUnload(pTexNo);
	AEGfxTextureUnload(pTexConfirmationBackground);
}