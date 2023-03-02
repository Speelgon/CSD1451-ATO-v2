#pragma once
#include "allheaders.hpp"
#include "Level1_new.hpp"
#include "movement.hpp"
#include "objects.hpp"
#include "collision.hpp"
#include "IncrementVariable.hpp"
#include "vpCollision.hpp"
#include "catdeath.hpp"
#include "PlatformsDisappear.hpp"
#include "utils.h"





//char strBuffer[100];
//f32 TextWidth, TextHeight;
//==========================================================================================================================
//==========================================================================================================================


extern PlatformState platformstate[4];

//variables for normal timer
extern f64 normalElapsedTime;
extern int timer;
extern f64 interval;
extern int lasttimer;
extern int numberofplatforms;
extern f64 elapsedtime;


void Level1NEW_Load()
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

	pTexExitdoor = AEGfxTextureLoad("Assets/exitdoor.png");
	AE_ASSERT_MESG(pTexExitdoor, "Failed to create exitdoor texture!!");

	pTexBackground = AEGfxTextureLoad("Assets/background.png");
	AE_ASSERT_MESG(pTexBackground, "Failed to create background texture!!");

	pTexNode = AEGfxTextureLoad("Assets/hookpoint.png");
	AE_ASSERT_MESG(pTexNode, "Failed to create hookpoint texture!!");
}

void Level1NEW_Initialize()
{
	

	//make selected blocks disappear after a certain amount of time
	//----------------------------------------------------------------------------------------------------------------
	//enum disappearstatus { CANTDISAPPEAR = 0, CANDISAPPEAR, DISAPPEARED, TIMERSTARTED };
	elapsedtime=0;
	///fontId = AEGfxCreateFont("Assets/Roboto-Regular.ttf", 12);
	//fontId = AEGfxCreateFont("Assets/Roboto-Regular.ttf", 12);
	AEGfxSetBackgroundColor(0.81f, 0.6f, 0.46f);


	//C:\Users\Yuki\OneDrive\Documents\GitHub\CSD1451 - ATO - v2\Alpha Engine 1\Assets
	
	platformstate[1].state = CANDISAPPEAR;
	platformstate[1].timer = 3;
	platformstate[1].elapsedtime = 0.0f;
	platformstate[1].interval = 1.0f; 

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

	collectiblelevel1NEWinit(collectible);

	uiinit(ui);

	uilevel1init(ui);

	objectlevel1NEWinit(object);

	exitdoorinit(exitdoor);

	exitdoorlevel1NEWinit(exitdoor);

	textureinit(pTex);

	meshinit(object, pMesh);

	meshinitlevel1(object, pMesh, ui, collectible, player, portal, playerHook, blackhole, exitdoor);

	platformstate[2].state = CANTDISAPPEAR;
	platformstate[2].timer = 0;
	platformstate[2].elapsedtime = 0.0f;
	platformstate[2].interval = 0.0f;

	platformstate[3].state = CANTDISAPPEAR;
	platformstate[3].timer = 0;
	platformstate[3].elapsedtime = 0.0f;
	platformstate[3].interval = 0.0f;

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

	

}//end of initialisation

void Level1NEW_Update()
{
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





		//playerActualMovement(player.x, player.y, player.xvel, player.yvel); //LOCATED IN movement.cpp

		playerEasingMovement(player.xvel, player.yvel, stabliser);

		playerCollisionMapBoundary(player.x, player.y, object[0].x, object[0].y, player.halfW, player.halfH, object[0].halfW, object[0].halfH, playerSpeed + player.xvel, playerSpeed + player.yvel);

		incrementobjintializer = whichvariableincreased(incrementobjintializer, a, b, middlex, middley, optionhalfside, pMeshY1, pMeshY2, truemousex, truemousey);

		AEInputGetCursorPosition(&mouseX, &mouseY);

		//if(player.x<400 && player.x>-400 && player.y<400 && player.y > -300)
		//{
		viewportCollision(player.x, player.y, worldX, worldY, viewporthalfw, viewporthalfh, worldhalfW, worldhalfH, playerSpeed + player.xvel, playerSpeed + player.yvel);
		//}


		// Out of bounds
		if (playerOutofBounds(player.y, mapBoundary.y) == 1)
		{
			current = GS_RESTART;
		}

		if (exitCollisionDoor(player.x, player.y, exitdoor[0].x, exitdoor[0].y, player.halfW, player.halfH, exitdoor[0].halfW, exitdoor[0].halfH) == 1)
		{
			next = GS_LEVEL2;
		}


	}
    

}

void Level1NEW_Draw()
{
	backgroundrender(player, pMesh, pTexBackground);

	// Change texture base on where player is facing
	if (AEInputCheckCurr(AEVK_D))
	{
		objectrender(player, object, ui, pMesh, collectible, pTexRight, portal, pTexPortal, pTexPlatform, pTexCollectible, blackhole, nodes, pTexNode, platformstate, exitdoor, pTexExitdoor);
	}
	else if (AEInputCheckCurr(AEVK_A))
	{
		objectrender(player, object, ui, pMesh, collectible, pTexLeft, portal, pTexPortal, pTexPlatform, pTexCollectible, blackhole, nodes, pTexNode, platformstate, exitdoor, pTexExitdoor);
	}
	else
	{
		objectrender(player, object, ui, pMesh, collectible, pTexFront, portal, pTexPortal, pTexPlatform, pTexCollectible, blackhole, nodes, pTexNode, platformstate, exitdoor, pTexExitdoor);
	}

	//This is the part of your code which does the matrix translations, rotations and scaling
	kwanEuItemRender();
}

void Level1NEW_Free()
{
    for (int i = 0; i < meshMax; i++)
	{
		AEGfxMeshFree(pMesh[i]);
	}
	AEGfxMeshFree(itemMesh);
	//AEGfxDestroyFont(fontId);
}

void Level1NEW_Unload()
{
	AEGfxTextureUnload(pTexFront);
	AEGfxTextureUnload(pTexRight);
	AEGfxTextureUnload(pTexLeft);
	AEGfxTextureUnload(pTexPortal);
	AEGfxTextureUnload(pTexPlatform);
	AEGfxTextureUnload(pTexCollectible);
	AEGfxTextureUnload(pTexExitdoor);
}