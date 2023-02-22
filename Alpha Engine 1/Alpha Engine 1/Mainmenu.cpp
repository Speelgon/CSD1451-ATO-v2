#include "allheaders.hpp"
#include "objects.hpp"
#include "IncrementVariable.hpp"

square buttons;
AEGfxVertexList* playMesh;
//s8 fontId = 0;
char strBufferPLAY[100];
//char strBufferSettings[50];
//f32 TextWidth, TextHeight;
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
	//fontId = AEGfxCreateFont("C:/Users/Yuki/OneDrive/Documents/GitHub/CSD1451-ATO-v2/Alpha Engine 1/Assets/Roboto-Regular.ttf", 12);

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
		std::cout << "SWITCH TO LEVEL 1 STATE HOW" << '\n';
		next = GS_LEVEL1;
	}

	if (IsAreaClicked(buttons.x, settingsbuttony, buttons.halfW, buttons.halfH, truemousex, truemousey))
	{
		std::cout << "FUOCK" << '\n';
	}

	if (IsAreaClicked(buttons.x, creditsbuttony, buttons.halfW, buttons.halfH, truemousex, truemousey))
	{
		std::cout << "ADA BABY" << '\n';
	}
	
	
	

}

void Mainmenu_Draw()
{
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

	////PRINT "PLAY" TEXT
	//AEGfxGetPrintSize(fontId, strBufferPLAY, 0.5f, TextWidth, TextHeight);
	//memset(strBufferPLAY, 0, 100 * sizeof(char));
	//sprintf_s(strBufferPLAY, "Play");
	//AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	//AEGfxPrint(fontId, strBufferPLAY, 0, 0.2, 1.0f, 1.f, 1.f, 1.f);

//	//PRINT "SETTINGS" TEXT
//	AEGfxGetPrintSize(fontId, strBufferPLAY, 200.0f, TextWidth, TextHeight);
//	memset(strBufferPLAY, 0, 100 * sizeof(char));
//	sprintf_s(strBufferPLAY, "Play");
//	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
//	AEGfxPrint(fontId, strBufferPLAY, 0, 0.2, 1.0f, 1.f, 1.f, 1.f);
}

void Mainmenu_Free()
{
	AEGfxMeshFree(playMesh);
	//AEGfxDestroyFont(fontId);
}

void Mainmenu_Unload()
{

}