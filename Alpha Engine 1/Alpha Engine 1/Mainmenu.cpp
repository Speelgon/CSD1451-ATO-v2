#include "allheaders.hpp"

#include "IncrementVariable.hpp"

square buttons;
AEGfxVertexList* playMesh;
extern s8 fontId;
char strBufferPLAY[5], strBufferHTP[12], strBufferCredits[8], strBufferQuit[5], strBufferTitle[14];
//char strBufferSettings[50];
f32 TextWidth, TextHeight;
extern int mousex;
extern int mousey;
extern int truemousex;
extern int truemousey;
extern square player;
f32 settingsbuttony;
f32 creditsbuttony;
f32 quitbuttony;




void Mainmenu_Load()
{
	std::cout << "GSM:Load\n";
}

void Mainmenu_Initialize()
{
	TextWidth = 1;
	TextHeight = 1;
	//AEGfxSetBackgroundColor(0.0f, 70.0f, 50.0f);
	buttons.x = 0;
	buttons.y = 50;
	/*buttons.xvel = 0;
	buttons.yvel = 0;*/
	settingsbuttony = buttons.y - 80;
	creditsbuttony = buttons.y - 160;
	quitbuttony = buttons.y - 240;
	buttons.width = 120;
	buttons.height = 40;
	buttons.halfW = buttons.width / 2;
	buttons.halfH = buttons.height / 2;

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

	
}

void Mainmenu_Update()
{
	AEInputGetCursorPosition(&mousex, &mousey);
	truemousex = mousex - screenwidth / 2 + player.x;
	truemousey = -mousey + screenheight / 2 + player.y;

	if (IsAreaClicked(buttons.x, buttons.y, buttons.halfW, buttons.halfH, truemousex, truemousey))
	{
		next = GS_LEVEL1;
	}

	if (IsAreaClicked(buttons.x, settingsbuttony, buttons.halfW, buttons.halfH, truemousex, truemousey))
	{
		
	}

	if (IsAreaClicked(buttons.x, creditsbuttony, buttons.halfW, buttons.halfH, truemousex, truemousey))
	{
		
	}
	
	
	

}

void Mainmenu_Draw()
{
	//====================================//
	//			 Button Drawing			  //
	//====================================//
	
	// Drawing top "play" button
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	// Set position 
	AEGfxSetPosition(buttons.x, buttons.y);
	AEGfxSetTintColor(0.0f, 0.5f, 1.0f, 1.0f);
	// No texture 
	AEGfxTextureSet(NULL, 0, 0);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(playMesh, AE_GFX_MDM_TRIANGLES);

	//Drawing 2nd "settings" button
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	AEGfxSetPosition(buttons.x, settingsbuttony);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(NULL, 0, 0);
	AEGfxMeshDraw(playMesh, AE_GFX_MDM_TRIANGLES);

	//Drawing 3rd "credits" button 
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	AEGfxSetPosition(buttons.x, creditsbuttony);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(NULL, 0, 0);
	AEGfxMeshDraw(playMesh, AE_GFX_MDM_TRIANGLES);

	//Drawing 4th "quit" button
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	AEGfxSetPosition(buttons.x, quitbuttony);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(NULL, 0, 0);
	AEGfxMeshDraw(playMesh, AE_GFX_MDM_TRIANGLES);

	//====================================//
	//			  TEXT PRINTING			  //
	//====================================//
	// 
	//PRINT "LEAP CLIMBERS" TEXT
	AEGfxGetPrintSize(fontId, strBufferTitle, f32(1), TextWidth, TextHeight);
	memset(strBufferTitle, 0, 5 * sizeof(char));
	sprintf_s(strBufferTitle, "LEAP CLIMBERS");
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxPrint(fontId, strBufferTitle, -0.22f, 0.5f, 1, 1.f, 1.f, 1.f);

	//PRINT "PLAY" TEXT
	AEGfxGetPrintSize(fontId, strBufferPLAY, f32(1), TextWidth, TextHeight);
	memset(strBufferPLAY, 0, 5 * sizeof(char));
	sprintf_s(strBufferPLAY, "PLAY");
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxPrint(fontId, strBufferPLAY, -0.065f, 0.14f, 1, 0.f, 0.f, 0.f);

	//PRINT "TUTORIAL" TEXT
	AEGfxGetPrintSize(fontId, strBufferHTP, f32(1), TextWidth, TextHeight);
	memset(strBufferHTP, 0, 12 * sizeof(char));
	sprintf_s(strBufferHTP, "TUTORIAL");
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxPrint(fontId, strBufferHTP, -0.14f, -0.13f, 1, 0.f, 0.f, 0.f);

	//PRINT "CREDITS" TEXT
	AEGfxGetPrintSize(fontId, strBufferCredits, f32(1), TextWidth, TextHeight);
	memset(strBufferCredits, 0, 8 * sizeof(char));
	sprintf_s(strBufferCredits, "CREDITS");
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxPrint(fontId, strBufferCredits, -0.12f, -0.4f, 1, 0.f, 0.f, 0.f);
	
	//PRINT "QUIT" TEXT
	AEGfxGetPrintSize(fontId, strBufferQuit, f32(1), TextWidth, TextHeight);
	memset(strBufferQuit, 0, 5 * sizeof(char));
	sprintf_s(strBufferQuit, "QUIT");
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxPrint(fontId, strBufferQuit, -0.065f, -0.66f, 1, 0.f, 0.f, 0.f);
}

void Mainmenu_Free()
{
	AEGfxMeshFree(playMesh);
}

void Mainmenu_Unload()
{

}