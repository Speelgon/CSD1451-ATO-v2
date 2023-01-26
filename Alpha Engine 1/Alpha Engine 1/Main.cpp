// ---------------------------------------------------------------------------
// includes
#pragma once
#include "allheaders.hpp"
#include "objects.hpp"
#include "movement.hpp"
#include "vpCollision.hpp"
#include "collision.hpp"
#include "collectibles.hpp"
#include <math.h>
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

	AEGfxVertexList* itemMesh = 0;
	AEGfxVertexList* pMeshY1 = 0;
	AEGfxVertexList* pMeshY2 = 0;	
	square object[30];
	square ui[5];
	square collectibles[5];
	AEGfxVertexList* pMesh[30];
	AEGfxVertexList* uiMesh[30];
	AEGfxTexture* pTex[30];

	AEGfxTexture* pTex1 = 0;


	objectinit(object);

	uiinit(ui);

	uilevel1init(ui);

	objectlevel1init(object);

	collectiblesinit(collectibles);
	

	textureinit(pTex);


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

	/*object.x = 100;
	object.y = -100;
	object.width = 1000;
	object.height = 60;
	object.halfW = object.width / 2;
	object.halfH = object.height / 2;*/

	rectangle item;
	item.position.x = player.x;
	item.position.y = player.y;
	item.rotation = 0;
	item.width = 8.f;
	item.height = 45.f;

	//store mouse position coordinates
	s32 mouseX, mouseY;

	float playerSpeed = 3;

	
	//==================================================================
	// Yuki's Variables
	//==================================================================
	// 
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

	//==================================================================
	//==================================================================
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

	meshinitlevel1(object, pMesh, ui, collectibles);

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

	pMesh[0] = AEGfxMeshEnd();
	AE_ASSERT_MESG(pMesh[0], "Failed to create mesh 1!!");
	

	AEGfxMeshStart();
	AEGfxTriAdd(
		-item.width / 2, -item.height / 2, 0xFFFFFF00, 0.0f, 1.0f,
		item.width / 2, -item.height / 2, 0xFFFFFF00, 1.0f, 1.0f,
		-item.width / 2, item.height / 2, 0xFFFFFF00, 0.0f, 0.0f);

	AEGfxTriAdd(
		item.width / 2, -item.height / 2, 0xFFFFFFFF, 1.0f, 1.0f,
		item.width / 2, item.height / 2, 0xFFFFFFFF, 1.0f, 0.0f,
		-item.width / 2, item.height / 2, 0xFFFFFFFF, 0.0f, 0.0f);

	// Saving the mesh (list of triangles) in pMesh1

	itemMesh = AEGfxMeshEnd();
	AE_ASSERT_MESG(itemMesh, "Failed to create Item Mesh!!");
	
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


	//===============================================================

	//TEMPORARY TESTING VARIABLES

	//===============================================================

	int trigger = 0;



	//===============================================================




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

		AEInputGetCursorPosition(&mouseX, &mouseY);

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


		//------------------------------------------------------------------------------------------------------------------------------------------------------------
		//------------------------------------------------------------------------------------------------------------------------------------------------------------
		//------------------------------------------------------------------------------------------------------------------------------------------------------------


		//=============================================================================================
		// Game loop draw
		//=============================================================================================
		
<<<<<<< HEAD

		objectrender(player, object, ui, pMesh, collectible);
=======
		objectrender(player, object, ui, pMesh, collectibles);
>>>>>>> parent of 32a4c43 (Deconflicted collectibles code)

		// Drawing object 1

		AEGfxSetRenderMode(AE_GFX_RM_COLOR);

		item.direction.x = f32(mouseX) - f32(AEGetWindowWidth() / 2);
		item.direction.y = f32(mouseY) - f32(AEGetWindowHeight() / 2);
		AEVec2Normalize(&item.direction, &item.direction);
		item.rotation = atan2(item.direction.y, item.direction.x);

		// Set Scale for Item
		AEMtx33 scale = { 0 };
		AEMtx33Scale(&scale, 1, 1); //set scale to 1 so object can be shown. DO NOT SET TO HIGHER VALUES UNLESS INCREASING SIZE

		// Create a rotation matrix
		AEMtx33 rotate = { 0 };
		AEMtx33Rot(&rotate, 360 - AERadToDeg(item.rotation) * 0.025);

		// Create a translation matrix that translates by
		// 100 in the x-axis and 100 in the y-axis
		AEMtx33 translate = { 0 };

		item.direction.x = worldwidth/2 + (mouseX - float(AEGetWindowWidth() / 2)) * cos(item.rotation) - (mouseY - float(AEGetWindowHeight() / 2)) * sin(item.rotation);
		item.direction.y = worldheight/2 + (mouseX - float(AEGetWindowWidth() / 2)) * sin(item.rotation) + (mouseY - float(AEGetWindowHeight() / 2)) * cos(item.rotation);
		AEVec2Normalize(&item.direction, &item.direction);

		AEMtx33Trans(&translate, 30 * item.direction.x + player.x, 30 * item.direction.y + player.y);

		// Concat the matrices
		AEMtx33 transform = { 0 };
		AEMtx33Concat(&transform, &rotate, &scale);
		AEMtx33Concat(&transform, &translate, &transform);

		// Choose the transform to use
		AEGfxSetTransform(transform.m);
		// No texture for object 1
		AEGfxTextureSet(NULL, 0, 0);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(itemMesh, AE_GFX_MDM_TRIANGLES);

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

	AEGfxMeshFree(pMesh[0]);
	AEGfxMeshFree(pMesh[1]);
	AEGfxMeshFree(pMesh[2]);
	AEGfxMeshFree(pMesh[3]);
	AEGfxMeshFree(itemMesh);
	//This part later needs to be changed to meshes used
	/*for (int i = 0; i < meshMax; i++)
	{
		AEGfxMeshFree(pMesh[i]);
	}*/


	AEGfxTextureUnload(pTex1);

	// free the system
	AESysExit();
}
