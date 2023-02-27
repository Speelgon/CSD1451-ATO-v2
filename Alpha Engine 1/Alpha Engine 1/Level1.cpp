#pragma once
#include "allheaders.hpp"
#include "Level1.hpp"
#include "movement.hpp"
#include "objects.hpp"
#include "collision.hpp"
#include "IncrementVariable.hpp"
#include "vpCollision.hpp"
#include "utils.h"
#include "PlatformsDisappear.hpp"

extern square player, ui[5];
#include "catdeath.hpp"

extern f64 delta;
extern f64 assumedFrameRate;

extern square player;
extern square object[maxObj];
extern square ui[maxUI];
extern collectible1 collectible[maxCollectible];
extern rectangle item;
extern exits exitdoor[maxDoor];
extern portal1 portal[maxPortal];
extern boundary mapBoundary;

extern AEGfxVertexList* pMesh[meshMax];
extern AEGfxVertexList* uiMesh[maxUI];
extern AEGfxTexture* pTex[30];

extern AEGfxVertexList* itemMesh;
extern AEGfxTexture* pTexFront;
extern AEGfxTexture* pTexRight;
extern AEGfxTexture* pTexLeft;
extern float playerSpeed;
extern int jumptoken;
extern float gravity;
extern float stabliser;


//==========================================================================================================================
// Yuki's Variables
//==========================================================================================================================
// 
// 
// 

extern AEGfxVertexList* pMeshY1;
extern AEGfxVertexList* pMeshY2;
//store mouse position coordinates
extern s32 mouseX, mouseY;

extern int* clickx;
extern int* clicky;

//variables for passing over obj
extern int a;
extern int b;

extern int mousex, mousey;
extern int truemousex, truemousey;

extern float middlex, middley;
extern float optionside;
extern float optionhalfside;

extern int incrementobjintializer;

//viewport 
extern float viewportwidth, viewportheight;
extern float viewporthalfw, viewporthalfh;

//float camX, camY; // Used to temporary store camera position
extern float worldX, worldY;
extern float worldwidth, worldheight;
extern float worldhalfW, worldhalfH;

//MAPSIZE
extern float mapx;
extern float mapy;
extern float halfmapx;
extern float halfmapy;
extern f64 delta;
extern f64 assumedFrameRate;






//char strBuffer[100];
//f32 TextWidth, TextHeight;
//==========================================================================================================================
//==========================================================================================================================


//variables for normal timer
f64 normalElapsedTime;
int timer;
f64 interval;
int lasttimer;

//make selected blocks disappear after a certain amount of time
//----------------------------------------------------------------------------------------------------------------
//enum disappearstatus { CANTDISAPPEAR = 0, CANDISAPPEAR, DISAPPEARED, TIMERSTARTED };
f64 elapsedtime;
struct PlatformState platformstate[4] = {	
											CANTDISAPPEAR, 3, 0.0f, 1.0f,
											CANDISAPPEAR, 3, 0.0f, 1.0f,
											CANTDISAPPEAR, 3, 0.0f, 1.0f,
											CANDISAPPEAR, 3, 0.0f, 1.0f
										};
int numberofplatforms = 4;

int UpdateTimer(f64 elapsedtime, int timer, f64 timeinterval)
{
	for (int i = 0; i < 4; i++)
	{
		platformstate[i].elapsedtime += AEFrameRateControllerGetFrameTime();
		if (elapsedtime >= platformstate[i].interval)
		{
			timer--;
			elapsedtime = 0;
		}
	}
	return timer;
}


//-------------------------------------------------------------------------------------------------------------------



//int normalUpdateTimer(f64 * normalElapsedTime, int timer, f64 interval)
//{
//	*normalElapsedTime += AEFrameRateControllerGetFrameTime();
//	if (*normalElapsedTime >= interval)
//	{
//		timer--;
//		*normalElapsedTime = 0;
//	}
//	return timer;
//}

void Level1_Load()
{
	std::cout << "GSM:Load\n";

	// Texture 1: From file
	pTexFront = AEGfxTextureLoad("Assets/FCat_Front.png");
	AE_ASSERT_MESG(pTexFront, "Failed to create cat front texture!!");

	pTexRight = AEGfxTextureLoad("Assets/FCat_Right.png");
	AE_ASSERT_MESG(pTexRight, "Failed to create cat right texture!!");

	pTexLeft = AEGfxTextureLoad("Assets/FCat_Left.png");
	AE_ASSERT_MESG(pTexLeft, "Failed to create cat left texture!!");

	pTexPortal = AEGfxTextureLoad("Assets/portal.png");
	AE_ASSERT_MESG(pTexPortal, "Failed to create portal texture!!");

	pTexPlatform = AEGfxTextureLoad("Assets/platform.png");
	AE_ASSERT_MESG(pTexPlatform, "Failed to create platform texture!!");

	pTexCollectible = AEGfxTextureLoad("Assets/collectible.png");
	AE_ASSERT_MESG(pTexCollectible, "Failed to create collectible texture!!");

}

// ----------------------------------------------------------------------------
// This function initializes the variables used in level 1
// prints Level1:Initialize to std::output
// ----------------------------------------------------------------------------

void Level1_Initialize()
{
    ///fontId = AEGfxCreateFont("Assets/Roboto-Regular.ttf", 12);
	//fontId = AEGfxCreateFont("Assets/Roboto-Regular.ttf", 12);
	AEGfxSetBackgroundColor(0.81f, 0.6f, 0.46f);

	
//C:\Users\Yuki\OneDrive\Documents\GitHub\CSD1451 - ATO - v2\Alpha Engine 1\Assets
	player.x = -1000;
	player.y = -200;
	player.xvel = 0;
	player.yvel = 0;
	player.width = 10;
	player.height = 60;
	player.halfW = player.width / 2;
	player.halfH = player.height / 2;
	player.lefttoken = 0;
	player.righttoken = 0;

	item.rotation = 0;
	item.width = 8.f;
	item.height = 45.f;

	mapBoundary.y = -600;


	objectinit(object);

	hookinit(playerHook);

	collectibleinit(collectible);

	collectiblelevel1init(collectible);

	portalinit(portal);

	portallevel1init(portal);

	uiinit(ui);

	uilevel1init(ui);

	objectlevel1init(object);

	blackholeinit(blackhole);

	blackholelevel1init(blackhole);

	trampolineinit(trampoline);

	trampolinelevel1init(trampoline);

	exitdoorinit(exitdoor);

	exitdoorlevel1init(exitdoor);

	nodeInit(nodes);

	textureinit(pTex);

	meshinit(object, pMesh);

	meshinitlevel1(object, pMesh, ui, collectible, player, portal, playerHook, blackhole, exitdoor);

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
	// ----------------------------------------------------------------------------
	//make another array of max number of platforms size to keep track of which platforms
	//cannot disappear, can disappear and have disappeared

	lasttimer = timer = 60;
	interval = 1.0f;
	elapsedtime = 0.0f;

	// platformstate[2].state = CANTDISAPPEAR;
	// platformstate[2].timer = 0;
	// platformstate[2].elapsedtime = 0.0f;
	// platformstate[2].interval = 0.0f;

	// platformstate[3].state = CANTDISAPPEAR;
	// platformstate[3].timer = 0;
	// platformstate[3].elapsedtime = 0.0f;
	// platformstate[3].interval = 0.0f;
}

// ----------------------------------------------------------------------------
// This function updates the variables used in level 1 and
// prints Level1:Update to std output
// ----------------------------------------------------------------------------

void Level1_Update()
{
	item.rotation = 0;
	item.width = 8.f;
	item.height = 45.f;
	
		delta = AEFrameRateControllerGetFrameTime();



		if (AEInputCheckCurr(AEVK_L))
		{
			catdeath();
		}

		else
		{
			if (AEInputCheckTriggered(AEVK_F))
			{
				item.height += 10.f;
				std::cout << "Printing";
			}

			playerInputMovement(player.xvel, player.yvel, playerSpeed, jumptoken); //LOCATED IN movement.cpp

			playerGravity(player.yvel, gravity);

			if (AEInputCheckCurr(AEVK_LBUTTON))
			{
				if (playerHookCollision(nodes, &playerHook, hookCollisionFlag)) {
					std::cout << "Collision\n";
					anglePlayerToNode(nodes[collidedNode]);
					movementWhenHooked(player.xvel, player.yvel, gravity, item, nodes);
				}
				else {
					anglePlayerToMouse();
					hookCollisionFlag = 0;
				}
			}
			else {
				anglePlayerToMouse();
				hookCollisionFlag = 0;
			}

			playerActualMovement(player.x, player.y, player.xvel, player.yvel); //LOCATED IN movement.cpp

			meshUpdate();

			hookUpdate();


			//Bounding box type collision

			for (int i = maxObj - 1; i >= 0; i--)
			{
				//if (i < 4)
				//
				//	if (platformstate[i].state == 0 && LastJump == 1)
				//	{
				//		if (timerset == 0)
				//		{
				//			//InitializeTimer(15, 1.0f);
				//			timerset = 1;
				//		}
				//		
				//	}
				//}
				if (i < numberofplatforms)
				{
					// if platform set to disappear upon finishing countdown of timer, need not to check for collision
					if (platformstate[i].state != DISAPPEARED)
					{

						playerCollisionSquare(player.x, player.y, object[i].x, object[i].y, player.halfW, player.halfH, object[i].halfW, object[i].halfH, player.xvel, player.yvel, jumptoken, object[i].lefttoken, object[i].righttoken); //LOCATED IN Collision.cpp

						// set the platform that can disappear to start timer upon player first landing on the platform
						if (platformstate[i].state == CANDISAPPEAR && jumptoken && object[i].lefttoken == 0)
						{
							platformstate[i].state = TIMERSTARTED;

							std::cout << "platform " << i << "Timer started" << '\n';
						}


					}
					else
					{
						object[i].lefttoken = 1;
						object[i].righttoken = 1;
					}
				}
				else
				{
					playerCollisionSquare(player.x, player.y, object[i].x, object[i].y, player.halfW, player.halfH, object[i].halfW, object[i].halfH, player.xvel, player.yvel, jumptoken, object[i].lefttoken, object[i].righttoken); //LOCATED IN Collision.cpp
				}

			}

			// run countdown for the platforms to disappear
			for (int j = 0; j < numberofplatforms; j++)
			{
				if (platformstate[j].state == TIMERSTARTED)
				{
					platformstate[j].timer = normalUpdateTimer(&(platformstate[j]).elapsedtime, platformstate[j].timer, platformstate[j].interval);
					if (platformstate[j].timer == 0)
					{
						platformstate[j].state = DISAPPEARED;
					}
					// std::cout << "platform: " << j << "Timer: " << platformstate[j].timer << '\n';

				}

			}

			for (int i = maxTrampolines - 1; i >= 0; i--)
			{
				playerCollisionTrampoline(player.x, player.y, trampoline[i].x, trampoline[i].y, player.halfW, player.halfH, trampoline[i].halfW, trampoline[i].halfH, player.xvel, player.yvel, jumptoken, trampoline[i].lefttoken, trampoline[i].righttoken); //LOCATED IN Collision.cpp
			}


			if (timer > 0)
			{
				timer = normalUpdateTimer(&normalElapsedTime, timer, interval);
			}

			for (int i = 0; i < maxCollectible; i++)
			{
				playerCollisionCollectible(player.x, player.y, collectible[i].x, collectible[i].y, player.halfW, player.halfH, collectible[i].halfW, collectible[i].halfH, collectible[i].visibility);
			}



			playerCollisionPortal(player.x, player.y, portal[0].x, portal[0].y, player.halfW, player.halfH, portal[0].halfW, portal[0].halfH, portal[0].positiontoken);

			if (portal[0].positiontoken == 0)
			{
				player.x = portal[1].x + portal[1].halfW + 20;
				player.y = portal[1].y;
				portal[0].positiontoken = 1;
			}

			playerCollisionPortal(player.x, player.y, portal[1].x, portal[1].y, player.halfW, player.halfH, portal[1].halfW, portal[1].halfH, portal[1].positiontoken);


			if (portal[1].positiontoken == 0)
			{
				player.x = portal[0].x - portal[0].halfW - 20;
				player.y = portal[0].y;
				portal[1].positiontoken = 1;
			}

			//playerActualMovement(player.x, player.y, player.xvel, player.yvel); //LOCATED IN movement.cpp

			playerEasingMovement(player.xvel, player.yvel, stabliser);

			playerCollisionMapBoundary(player.x, player.y, object[0].x, object[0].y, player.halfW, player.halfH, object[0].halfW, object[0].halfH, playerSpeed + player.xvel, playerSpeed + player.yvel);

			incrementobjintializer = whichvariableincreased(incrementobjintializer, a, b, middlex, middley, optionhalfside, pMeshY1, pMeshY2, truemousex, truemousey);

			AEInputGetCursorPosition(&mouseX, &mouseY);

			//if(player.x<400 && player.x>-400 && player.y<400 && player.y > -300)
			//{
			viewportCollision(player.x, player.y, worldX, worldY, viewporthalfw, viewporthalfh, worldhalfW, worldhalfH, playerSpeed + player.xvel, playerSpeed + player.yvel);
			//}
			/*if (UpdateTimer() == 0)
			{
				next = GS_RESTART;
				timer = 10;
			}*/



			// Out of bounds
			//playerOutofBounds(player.x, player.y);


			// Out of bounds
			if (playerOutofBounds(player.y, mapBoundary.y) == 1)
			{
				current = GS_RESTART;
			}

			if (exitCollisionDoor(player.x, player.y, exitdoor[0].x, exitdoor[0].y, player.halfW, player.halfH, exitdoor[0].halfW, exitdoor[0].halfH) == 1)
			{
				next = GS_QUIT;
			}


		}
	}

void Level1_Draw()
{

	// Change texture base on where player is facing
	if (AEInputCheckCurr(AEVK_D))
	{
		objectrender(player, object, ui, pMesh, collectible, pTexLeft, portal, pTexPortal, pTexPlatform, pTexCollectible, blackhole, nodes, platformstate, exitdoor);
	}
	else if (AEInputCheckCurr(AEVK_A))
	{
		objectrender(player, object, ui, pMesh, collectible, pTexLeft, portal, pTexPortal, pTexPlatform, pTexCollectible, blackhole, nodes, platformstate, exitdoor);
	}
	else
	{
		objectrender(player, object, ui, pMesh, collectible, pTexLeft, portal, pTexPortal, pTexPlatform, pTexCollectible, blackhole, nodes, platformstate, exitdoor);
	}

	//This is the part of your code which does the matrix translations, rotations and scaling
	kwanEuItemRender();


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
	AEMtx33Rot(&rotate, 360 - AERadToDeg(item.rotation) * AEFrameRateControllerGetFrameTime());

	// Create a translation matrix that translates by
	// 100 in the x-axis and 100 in the y-axis
	AEMtx33 translate = { 0 };

	item.direction.x = (mouseX - worldwidth / 2) * cos(item.rotation) - (mouseY - worldheight/ 2) * sin(item.rotation);
	item.direction.y = (mouseX - worldwidth / 2) * sin(item.rotation) + (mouseY - worldheight / 2) * cos(item.rotation);
	AEVec2Normalize(&item.direction, &item.direction);

	AEMtx33Trans(&translate, 15 * item.direction.x + player.x, -15 * item.direction.y + player.y);

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

	//AEGfxSetTransparency(1.0f);
	//if (AEInputCheckCurr(AEVK_D))

	//	AEGfxTextureSet(pTex2, player.x, player.y);
	/*timer -= (1 / AEFrameRateControllerGetFrameTime());
	if (timer == 0)
	{
		std::cout << "OK" << '\n';
	}*/
	if (timer != lasttimer)
	{
		std::cout << timer << '\n';
		lasttimer = timer;
	   /*AEGfxGetPrintSize(fontId, strBuffer, 0.5f, TextWidth, TextHeight);
	   memset(strBuffer, 0, 100 * sizeof(char));
	   sprintf_s(strBuffer, "Time: %d", timer);
	   AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	   AEGfxPrint(fontId, strBuffer, 0, 0.2, 1.0f, 255, 255, 255);*/
	}

	//PRINT "PLAY" TEXT
	/*AEGfxGetPrintSize(fontId, strBufferPLAY, 0.5f, TextWidth, TextHeight);
	memset(strBufferPLAY, 0, 100 * sizeof(char));
	sprintf_s(strBufferPLAY, "Play");
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxPrint(fontId, strBufferPLAY, 0, 0.2, 1.0f, 1.f, 1.f, 1.f);*/

	
}

void Level1_Free()
{
	for (int i = 0; i < meshMax; i++)
	{
		AEGfxMeshFree(pMesh[i]);
	}
	AEGfxMeshFree(itemMesh);
	//AEGfxDestroyFont(fontId);
}

void Level1_Unload()
{
	AEGfxTextureUnload(pTexFront);
	AEGfxTextureUnload(pTexRight);
	AEGfxTextureUnload(pTexLeft);


	AEGfxTextureUnload(pTexPortal);
	AEGfxTextureUnload(pTexPlatform);
	AEGfxTextureUnload(pTexCollectible);
}

