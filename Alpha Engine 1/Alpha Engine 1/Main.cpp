// ---------------------------------------------------------------------------
// includes
#pragma once
#include "allheaders.hpp"
#include "objects.hpp"
#include "movement.hpp"
#include "vpCollision.hpp"
#include "collision.hpp"
#include "Incrementvariable.h"
#include <iostream>

// ---------------------------------------------------------------------------
// main
#define screenwidth 800
#define screenheight 600
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	///////////////////////
	// Variable declaration
	
	int gGameRunning = 1;
	AEGfxVertexList* pMesh1 = 0;
	AEGfxVertexList* pMesh2 = 0;
	AEGfxVertexList* pMeshY1 = 0;
	AEGfxVertexList* pMeshY2 = 0;
	AEGfxVertexList* pMesh[30];
	square object[30];
	
	for (int i = 0; i < meshMax; i++)
	{
		pMesh[i] = 0;
	}

	AEGfxTexture* pTex1 = 0;

	objectinit(object);

	objectlevel1init(object);

	square player;
	player.x = 0;
	player.y = 0;
	player.xvel = 0;
	player.yvel = 0;
	player.width = 10;
	player.height = 60;
	player.halfW = player.width / 2;
	player.halfH = player.height / 2;
	float stabliser = 0.25;
	float gravity = 9.81;
	int jumptoken = 1;

	//object.x = 100;
	//object.y = -100;
	//object.width = 1000;
	//object.height = 60;
	//object.halfW = object.width / 2;
	//object.halfH = object.height / 2;

	float objectsize = 60;
	float objhalf = objectsize / 2;
	float playerSpeed = 3;

	//viewport 
	float viewportwidth = player.width + 100;
	float viewportheight = player.width + 100; 
	float viewporthalfw = viewportwidth / 2;
	float viewporthalfh = viewportheight / 2;

	//float camX, camY; // Used to temporary store camera position
	float worldX = 0;
	float worldY = 0;
	float worldwidth = (float)AEGetWindowWidth();;
	float worldheight =(float)AEGetWindowHeight();;
	float worldhalfW = worldwidth / 2;
	float worldhalfH = worldheight / 2;

	//MAPSIZE
	float mapx = 800;
	float mapy = 400;
	float halfmapx= mapx / 2;
	float halfmapy = mapy / 2;

	//variables for passing over obj
	int a;
	int b;

	int mousex = 0;
	int mousey = 0;
	int truemousex = 0;
	int truemousey = 0;

	float middlex = 30;
	float middley = 220;
	float optionside = 50;
	float optionhalfside = optionside / 2;

	int incrementobjintializer = 0;
	/*float minWorldX = 10;
	float minWorldY = 10;*/
	
	// Variable declaration end
	///////////////////////////


	/////////////////
	// Initialization

	// Using custom window procedure
	AESysInit(hInstance, nCmdShow, screenwidth, screenheight, 1, 60, true, NULL);

	// Changing the window title
	AESysSetWindowTitle("My New Demo!");

	// reset the system modules
	AESysReset();

	//set background color
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);

	// Initialization end
	/////////////////////

	////////////////////////////////
	// Creating the objects (Shapes)

	meshinit(object, pMesh);

	meshinitlevel1(object, pMesh);

	// Informing the library that we're about to start adding triangles
	AEGfxMeshStart();

	// 1 triangle at a time
	// X, Y, Color, texU, texV
	AEGfxTriAdd(
		-player.halfW, -player.halfH, 0x00FF0000, 0.0f, 1.0f,
		player.halfW, -player.halfH, 0x00FF0000, 1.0f, 1.0f,
		-player.halfW, player.halfH, 0x00FF0000, 0.0f, 0.0f);

	AEGfxTriAdd(
		player.halfW, -player.halfH, 0x0000FFFF, 1.0f, 1.0f,
		player.halfW, player.halfH, 0x0000FFFF, 1.0f, 0.0f,
		-player.halfW, player.halfH, 0x0000FFFF, 0.0f, 0.0f);

	// Saving the mesh (list of triangles) in pMesh1

	pMesh1 = AEGfxMeshEnd();
	AE_ASSERT_MESG(pMesh1, "Failed to create mesh 1!!");
	
	// Creating the objects (Shapes) end
	////////////////////////////////////

	////////////////////////////
	// Loading textures (images)

	// Texture 1: From file
	pTex1 = AEGfxTextureLoad("Assets/YellowTexture.png");
	AE_ASSERT_MESG(pTex1, "Failed to create texture1!!");

	// Loading textures (images) end
	//////////////////////////////////

	//////////////////////////////////
	// Creating Fonts	

	// Creating Fonts end
	//////////////////////////////////

	//int keypressed = 0;

	// Game Loop
	while (gGameRunning)
	{
		// Informing the system about the loop's start
		AESysFrameStart();

		//=============================================================================================
		// Input Loop
		//=============================================================================================
		
		AEInputUpdate();

		//=============================================================================================
		// Input Loop end
		//=============================================================================================


		//keypressed = passedoverobj();


		//=============================================================================================
		// Game loop update	
		//=============================================================================================
		//drawing 2 rectangles for player to choose after passing over an object
		//if (keypressed)
		//{

		int* clickx = &mousex;
		int* clicky = &mousey;
		AEInputGetCursorPosition(clickx, clicky);
		//std::cout << mousex - screenwidth/2 + player.x << '\n';
		//std::cout << - mousey + screenheight/2 + player.y   << '\n';
		truemousex = mousex - screenwidth / 2 + player.x;
		truemousey = -mousey + screenheight / 2 + player.y;

		incrementobjintializer = whichvariableincreased(incrementobjintializer,a, b, middlex, middley, optionhalfside, pMeshY1, pMeshY2, truemousex, truemousey);
		//}
		playerInputMovement(player.xvel,player.yvel,playerSpeed, jumptoken); //LOCATED IN movement.cpp

		playerGravity(player.yvel, gravity);

		playerActualMovement(player.x, player.y, player.xvel, player.yvel); //LOCATED IN movement.cpp

		//Bounding box type collision

		for (int i = 0; i < maxObj; i++)
		{
			playerCollisionSquare(player.x, player.y, object[i].x, object[i].y, player.halfW, player.halfH, object[i].halfW, object[i].halfH, player.xvel, player.yvel, jumptoken, object[i].lefttoken, object[i].righttoken); //LOCATED IN Collision.cpp
		}

		playerEasingMovement(player.xvel,player.yvel, stabliser);

		playerCollisionMapBoundary(player.x, player.y, object[0].x, object[0].y, player.halfW, player.halfH, object[0].halfW, object[0].halfH, playerSpeed + player.xvel, playerSpeed + player.yvel);

		//Viewport
		//Move the Camera

		//if(player.x<400 && player.x>-400 && player.y<400 && player.y > -300)
		{
			viewportCollision(player.x, player.y, worldX, worldY, viewporthalfw, viewporthalfh, worldhalfW, worldhalfH, playerSpeed + player.xvel, playerSpeed + player.yvel);
		}

		//=============================================================================================
		// Game loop update end
		//=============================================================================================







		//=============================================================================================
		// Game loop draw
		//=============================================================================================
		

		// Drawing object 1
		AEGfxSetRenderMode(AE_GFX_RM_COLOR);
		// Set position for object 1
		AEGfxSetPosition(player.x, player.y);
		// No texture for object 1
		AEGfxTextureSet(NULL, 0, 0);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(pMesh1, AE_GFX_MDM_TRIANGLES);


		// Drawing object 2 - (first) - No tint
		AEGfxSetRenderMode(AE_GFX_RM_COLOR);
		// Set position for object 2
		AEGfxSetPosition(object[0].x, object[0].y);
		// No tint
		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Set texture
		AEGfxTextureSet(pTex1, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(pMesh[0], AE_GFX_MDM_TRIANGLES);

		// Drawing object 3 - (first) - No tint
		AEGfxSetRenderMode(AE_GFX_RM_COLOR);
		// Set position for object 3
		AEGfxSetPosition(object[1].x, object[1].y);
		// No tint
		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Set texture
		AEGfxTextureSet(pTex1, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(pMesh[1], AE_GFX_MDM_TRIANGLES);

		// Drawing object 3 - (first) - No tint
		AEGfxSetRenderMode(AE_GFX_RM_COLOR);
		// Set position for object 3
		AEGfxSetPosition(object[2].x, object[2].y);
		// No tint
		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Set texture
		AEGfxTextureSet(pTex1, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(pMesh[2], AE_GFX_MDM_TRIANGLES);

		//=============================================================================================
		// Game loop draw end
		//=============================================================================================




		// Informing the system about the loop's end
		AESysFrameEnd();

		// check if forcing the application to quit
		if (AEInputCheckTriggered(AEVK_ESCAPE) || 0 == AESysDoesWindowExist())
			gGameRunning = 0;

	}
	// Freeing the objects and textures
	AEGfxMeshFree(pMesh1);
	AEGfxMeshFree(pMesh[0]);

	//This part later needs to be changed to meshes used
	/*for (int i = 0; i < meshMax; i++)
	{
		AEGfxMeshFree(pMesh[i]);
	}*/


	AEGfxTextureUnload(pTex1);

	// free the system
	AESysExit();
}
