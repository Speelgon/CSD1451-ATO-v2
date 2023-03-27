#include "allheaders.hpp"
#include "PauseScreen.hpp"
#include "IncrementVariable.hpp"



square resume_button, restartpause_button, howtoplay_button, mainmenu_button, quit_button;
extern square background;

//AEGfxVertexList* buttonMesh = 0;


extern GS_STATES previousState;
extern int mousex;
extern int mousey;
extern int truemousex;
extern int truemousey;
extern s8 fontId;
extern AEGfxTexture* pTexPauseBackground = 0;
extern AEGfxTexture* pTexResume = 0;
extern AEGfxTexture* pTexRestart;
extern AEGfxTexture* pTexTutorial;
extern AEGfxTexture* pTexMainMenu = 0;
extern AEGfxTexture* pTexQuit;

extern AEGfxVertexList* backgroundMesh;
extern AEGfxVertexList* buttonMesh;



void Pausemenu_Load()
{
	std::cout << "GSM:Load\n";

	//Change the AEGfxTextureLoad to right file path for all 
	
	pTexPauseBackground = AEGfxTextureLoad("Assets/pause_background.png");
	AE_ASSERT_MESG(pTexPauseBackground, "Failed to create pause background texture!!");

	pTexResume = AEGfxTextureLoad("Assets/button_resume.png");
	AE_ASSERT_MESG(pTexResume, "Failed to create resume button texture!!");

	pTexRestart = AEGfxTextureLoad("Assets/button_restart.png");
	AE_ASSERT_MESG(pTexRestart, "Failed to create restart button next!!");

	pTexTutorial = AEGfxTextureLoad("Assets/button_tutorial.png");
	AE_ASSERT_MESG(pTexTutorial, "Failed to create tutorial button next!!");

	pTexMainMenu = AEGfxTextureLoad("Assets/button_menu.png");
	AE_ASSERT_MESG(pTexMainMenu, "Failed to create main menu button next!!");

	pTexQuit = AEGfxTextureLoad("Assets/button_quit.png");
	AE_ASSERT_MESG(pTexQuit, "Failed to create quit button next!!");
	
}

void Pausemenu_Initialize()
{
	AEGfxSetBackgroundColor(0.8f, 0.6f, 0.2f);

	resume_button.x = 0;
	resume_button.y = 200;
	resume_button.width = 140;
	resume_button.height = 60;
	resume_button.halfW = resume_button.width / 2;
	resume_button.halfH = resume_button.height / 2;

	restartpause_button.x = 0;
	restartpause_button.y = resume_button.y - 110;
	restartpause_button.width = 140;
	restartpause_button.height = 160;
	restartpause_button.halfW = restartpause_button.width / 2;
	restartpause_button.halfH = restartpause_button.height / 2;

	howtoplay_button.x = 0;
	howtoplay_button.y = restartpause_button.y - 110;
	howtoplay_button.width = 140;
	howtoplay_button.height = 60;
	howtoplay_button.halfW = howtoplay_button.width / 2;
	howtoplay_button.halfH = howtoplay_button.height / 2;

	mainmenu_button.x = 0;
	mainmenu_button.y = howtoplay_button.y - 110;
	mainmenu_button.width = 140;
	mainmenu_button.height = 60;
	mainmenu_button.halfW = mainmenu_button.width / 2;
	mainmenu_button.halfH = mainmenu_button.height / 2;

	quit_button.x = 0;
	quit_button.y = mainmenu_button.y - 110;
	quit_button.width = 140;
	quit_button.height = 60;
	quit_button.halfW = quit_button.width / 2;
	quit_button.halfH = quit_button.height / 2;

	background.x = 0;
	background.y = 0;
	background.width = screenwidth;
	background.height = screenheight;
	background.halfW = background.width / 2;
	background.halfH = background.height / 2;

	AEGfxMeshStart();
	AEGfxTriAdd(
		-resume_button.halfW, -resume_button.halfH, 0xFFFFFF00, 0.0f, 1.0f,
		resume_button.halfW, -resume_button.halfH, 0xFFFFFF00, 1.0f, 1.0f,
		-resume_button.halfW, resume_button.halfH, 0xFFFFFF00, 0.0f, 0.0f);

	AEGfxTriAdd(
		resume_button.halfW, -resume_button.halfH, 0xFFFFFFFF, 1.0f, 1.0f,
		resume_button.halfW, resume_button.halfH, 0xFFFFFFFF, 1.0f, 0.0f,
		-resume_button.halfW, resume_button.halfH, 0xFFFFFFFF, 0.0f, 0.0f);

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

}

void Pausemenu_Update()
{
	AEGfxSetCamPosition(0, 0);
	AEInputGetCursorPosition(&mousex, &mousey);
	truemousex = (int)(mousex - screenwidth / 2);
	truemousey = (int)(-mousey + screenheight / 2);


	if (IsAreaClicked(resume_button.x, resume_button.y, resume_button.halfW, resume_button.halfH, truemousex, truemousey))
	{
		next = previousState;
	}
	
	if (IsAreaClicked(restartpause_button.x, restartpause_button.y, restartpause_button.halfW, restartpause_button.halfH, truemousex, truemousey))
	{
		next = previousState;

	}

	if (IsAreaClicked(howtoplay_button.x, howtoplay_button.y, howtoplay_button.halfW, howtoplay_button.halfH, truemousex, truemousey))
	{
		next = GS_HOWTOPLAY;
	}

	if (IsAreaClicked(mainmenu_button.x, mainmenu_button.y, mainmenu_button.halfW, mainmenu_button.halfH, truemousex, truemousey))
	{
		next = GS_MAINMENU;
	}

	if (IsAreaClicked(quit_button.x, quit_button.y, quit_button.halfW, quit_button.halfH, truemousex, truemousey))
	{
		next = GS_QUITCONFIRM;
	}
	

}

void Pausemenu_Draw()
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
	AEGfxTextureSet(pTexPauseBackground, 0.0f, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(backgroundMesh, AE_GFX_MDM_TRIANGLES);

	AEGfxSetTransparency(1.0f);


	//====================================//
	//			 Button Drawing			  //
	//====================================//



	// Drawing "resume" button
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	// Set position 
	AEGfxSetPosition(resume_button.x, resume_button.y);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(pTexResume, 0, 0);
	//Drawing the mesh (list of triangles)
	AEGfxMeshDraw(buttonMesh, AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);



	//Drawing "restart" button
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxSetPosition(restartpause_button.x, restartpause_button.y);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(pTexRestart, 0, 0);
	AEGfxMeshDraw(buttonMesh, AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);


	//Drawing "howtoplay" button 
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxSetPosition(howtoplay_button.x, howtoplay_button.y);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(pTexTutorial, 0, 0);
	AEGfxMeshDraw(buttonMesh, AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);

	//Drawing "mainmenu" button 
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxSetPosition(mainmenu_button.x, mainmenu_button.y);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(pTexMainMenu, 0, 0);
	AEGfxMeshDraw(buttonMesh, AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);

	//Drawing "quit" button
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxSetPosition(quit_button.x, quit_button.y);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(pTexQuit, 0, 0);
	AEGfxMeshDraw(buttonMesh, AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);

	
	
}

void Pausemenu_Free()
{
	AEGfxMeshFree(backgroundMesh);
	AEGfxMeshFree(buttonMesh);
	
}

void Pausemenu_Unload()
{
	AEGfxTextureUnload(pTexPauseBackground);
	AEGfxTextureUnload(pTexRestart);
	AEGfxTextureUnload(pTexTutorial);
	AEGfxTextureUnload(pTexQuit);
	AEGfxTextureUnload(pTexResume);
	AEGfxTextureUnload(pTexMainMenu);
}