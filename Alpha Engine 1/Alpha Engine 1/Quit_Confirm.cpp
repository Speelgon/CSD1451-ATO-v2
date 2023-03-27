#include "allheaders.hpp"
#include "IncrementVariable.hpp"
#include "winScreen.hpp"

extern int mousex;
extern int mousey;
extern int truemousex;
extern int truemousey;
extern square player;
extern int state_for_quit_confirm;
#define screenwidth 1600
#define screenheight 900
AEGfxVertexList* button_mesh;
square yes_button;
f32 no_buttonx;
f32 no_buttony;

void quit_confirm_Load()
{
	std::cout << "GSM:Load\n";
}

void quit_confirm_Initialize()
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
}

void quit_confirm_Update()
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
		next = state_for_quit_confirm;
	}
}

void quit_confirm_Draw()
{
	

	//draw yes mesh
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	//AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxSetPosition(yes_button.x, yes_button.y);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(NULL, 0, 0);
	AEGfxMeshDraw(button_mesh, AE_GFX_MDM_TRIANGLES);
	//AEGfxSetTransparency(1.0f);

	//draw no mesh
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	//AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxSetPosition(no_buttonx, no_buttony);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(NULL, 0, 0);
	AEGfxMeshDraw(button_mesh, AE_GFX_MDM_TRIANGLES);
	//AEGfxSetTransparency(1.0f);
}

void quit_confirm_Free()
{
	AEGfxMeshFree(button_mesh);
}

void quit_confirm_Unload()
{

}