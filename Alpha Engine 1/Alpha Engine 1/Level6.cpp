//==========================================================
// file		: Level6.cpp
// 
// author   : Owen Quek
// 
// email	: o.quek@digipen.edu
//
// brief	: Level6.cpp is where level 6 functions are defined
//
// Copyright © 2023 DigiPen, All rights reserved.
//==========================================================

#pragma once
#include "allheaders.hpp"
#include "Level6.hpp"
#include "movement.hpp"
#include "objects.hpp"
#include "collision.hpp"
#include "IncrementVariable.hpp"
#include "vpCollision.hpp"
#include "catdeath.hpp"
#include "utils.h"
#include "objects.hpp"


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
extern int collectible_count;
extern GS_STATES previousState;
extern int previouslyPaused;

extern float portal_timer;
extern f64 portal_elapsedtime;
extern f64 portal_interval;

extern float t;


void Level6_Load()
{
	std::cout << "GSM:Load\n";

	pTexFront = AEGfxTextureLoad("Assets/FCat_Front.png");
	AE_ASSERT_MESG(pTexFront, "Failed to create cat front texture!!");

	pTexRight = AEGfxTextureLoad("Assets/FCat_Right.png");
	AE_ASSERT_MESG(pTexRight, "Failed to create cat right texture!!");

	pTexLeft = AEGfxTextureLoad("Assets/FCat_Left.png");
	AE_ASSERT_MESG(pTexLeft, "Failed to create cat left texture!!");

	pTexPortal = AEGfxTextureLoad("Assets/portal.png");
	AE_ASSERT_MESG(pTexPortal, "Failed to create portal texture!!");

	pTexPlatform1 = AEGfxTextureLoad("Assets/platformMetal.png");
	AE_ASSERT_MESG(pTexPlatform1, "Failed to create platform texture!!");

	pTexCollectible = AEGfxTextureLoad("Assets/collectible.png");
	AE_ASSERT_MESG(pTexCollectible, "Failed to create collectible texture!!");

	pTexExitdoor = AEGfxTextureLoad("Assets/exitdoor.png");
	AE_ASSERT_MESG(pTexExitdoor, "Failed to create exitdoor texture!!");

	pTexBackground = AEGfxTextureLoad("Assets/background.png");
	AE_ASSERT_MESG(pTexBackground, "Failed to create background texture!!");

	pTexNode = AEGfxTextureLoad("Assets/hookpoint.png");
	AE_ASSERT_MESG(pTexNode, "Failed to create hookpoint texture!!");

	pTexHook = AEGfxTextureLoad("Assets/pickaxe_hook.png");
	AE_ASSERT_MESG(pTexHook, "Failed to create hook texture!!");

	pTexStick = AEGfxTextureLoad("Assets/pickaxe_stick.png");
	AE_ASSERT_MESG(pTexStick, "Failed to create stick texture!!");

	pTexDisappearingPlat = AEGfxTextureLoad("Assets/disappearingplat.png");
	AE_ASSERT_MESG(pTexDisappearingPlat, "Failed to create disappearing platform texture!!");

	pTexTrampoline = AEGfxTextureLoad("Assets/trampoline.png");
	AE_ASSERT_MESG(pTexTrampoline, "Failed to create trampoline texture!!");

	pTexBlackhole = AEGfxTextureLoad("Assets/blackhole.png");
	AE_ASSERT_MESG(pTexBlackhole, "Failed to create blackhole texture!!");
}

void Level6_Initialize()
{

	previousState = GS_LEVEL6;
	if (previouslyPaused)
	{
		previouslyPaused = 0;
		RestorePlayerPosition();
		platformstate[1].state = CANTDISAPPEAR;
		platformstate[1].timer = 3;
		platformstate[1].elapsedtime = 0.0f;
		platformstate[1].interval = 1.0f;

		portal_timer = 0;
		portal_elapsedtime = 0.0f;
		portal_interval = 1.0f;

		item.rotation = 0;
		item.width = 8.f;
		item.height = 45.f;

		mapBoundary.y = -600;

		initAudioList();

		objectinit(object);

		objectlevel6init(object);

		hookinit(playerHook);

		portalinit(portal);

		portallevel6init(portal);

		blackholeinit(blackhole);

		exitdoorlevel6init(exitdoor);

		textureinit(pTex);

		meshinit(object, pMesh);

		nodeInit(nodes);

		nodeInitlevel6(nodes);

		trampolineinit(trampoline);

		meshinitlevel1(object, pMesh, ui, collectible, player, portal, playerHook, blackhole, exitdoor);

		platformstate[2].state = CANTDISAPPEAR;
		platformstate[2].timer = 0;
		platformstate[2].elapsedtime = 0.0;
		platformstate[2].interval = 0.0f;

		platformstate[3].state = CANTDISAPPEAR;
		platformstate[3].timer = 0;
		platformstate[3].elapsedtime = 0.0f;
		platformstate[3].interval = 0.0f;

		timer = 0;
		t = 0;
	}
	else
	{

		elapsedtime = 0;
		blackholeTouched = 0;
		timeDead = 0;

		platformstate[1].state = CANTDISAPPEAR;
		platformstate[1].timer = 3;
		platformstate[1].elapsedtime = 0.0f;
		platformstate[1].interval = 1.0f;

		portal_timer = 0;
		portal_elapsedtime = 0.0f;
		portal_interval = 1.0f;

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

		collectible_count = 0;

		initAudioList();

		objectinit(object);

		objectlevel6init(object);

		hookinit(playerHook);

		blackholeinit(blackhole);

		blackholelevel6init(blackhole);

		collectibleinit(collectible);

		collectiblelevel6init(collectible);

		portalinit(portal);

		portallevel6init(portal);

		uiinit(ui);

		uilevel1init(ui);

		exitdoorinit(exitdoor);

		exitdoorlevel6init(exitdoor);

		textureinit(pTex);

		meshinit(object, pMesh);

		nodeInit(nodes);

		nodeInitlevel6(nodes);

		trampolineinit(trampoline);

		meshinitlevel1(object, pMesh, ui, collectible, player, portal, playerHook, blackhole, exitdoor);

		platformstate[2].state = CANTDISAPPEAR;
		platformstate[2].timer = 0;
		platformstate[2].elapsedtime = 0.0;
		platformstate[2].interval = 0.0f;

		platformstate[3].state = CANTDISAPPEAR;
		platformstate[3].timer = 0;
		platformstate[3].elapsedtime = 0.0f;
		platformstate[3].interval = 0.0f;

		timer = 0;
		t = 0;
	}

	

}

void Level6_Update()
{
	delta = AEFrameRateControllerGetFrameTime();

	if (blackholeTouched)
	{

		catdeath();
		hookUpdate();
		if (playerOutofBounds(player.y, mapBoundary.y) == 1)
		{
			current = GS_RESTART;
		}

	}

	else
	{

		playerInputMovement(player.xvel, player.yvel, playerSpeed, jumptoken); //LOCATED IN movement.cpp

		playerGravity(player.yvel, gravity);

		if (AEInputCheckCurr(AEVK_LBUTTON))
		{
			if (!AEInputCheckCurr(AEVK_W))
			{
				if (playerHookCollision(nodes, &playerHook, hookCollisionFlag)) {
					anglePlayerToNode(nodes[collidedNode]);
					movementWhenHooked(player.xvel, player.yvel, gravity, item);
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
					platformDisappear = true;
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
			playerCollisionCollectible(player.x, player.y, collectible[i].x, collectible[i].y, player.halfW, player.halfH, collectible[i].halfW, collectible[i].halfH, collectible[i].visibility, collectible_count);
		}



		playerCollisionPortal(player.x, player.y, portal[0].x, portal[0].y, player.halfW, player.halfH, portal[0].halfW, portal[0].halfH, portal[0].positiontoken);
		playerCollisionPortal(player.x, player.y, portal[1].x, portal[1].y, player.halfW, player.halfH, portal[1].halfW, portal[1].halfH, portal[1].positiontoken);

		if (portal[0].positiontoken == 0)
		{
			player.x = portal[1].x + portal[1].halfW + 20;
			player.y = portal[1].y;

			float camTargetX = portal[1].x;
			float camTargetY = portal[1].y;
			float camStartX = portal[0].x;
			float camStartY = portal[0].y;

			float camX = portal[0].x;
			float camY = portal[0].y;

			t = portal_timer / 3;
			camX = camStartX + t * (camTargetX - camStartX);
			camY = camStartY + t * (camTargetY - camStartY);

			AEGfxSetCamPosition(camX, camY);
			/*AEGfxSetCamPosition(portal[1].x, portal[1].y);*/
			portal_timer = PortalTimer(&portal_elapsedtime, int(portal_timer), portal_interval);

			player.yvel = 0;
			if (portal_timer == 4)
			{

				player.x = portal[1].x + portal[1].halfW + 20;
				player.y = portal[1].y;
				portal[0].positiontoken = 1;
				portal_timer = 0;
			}
		}

		else if (portal[1].positiontoken == 0)
		{
			player.x = portal[0].x - portal[0].halfW - 20;
			player.y = portal[0].y;
			float camTargetX = portal[0].x;
			float camTargetY = portal[0].y;
			float camStartX = portal[1].x;
			float camStartY = portal[1].y;

			float camX = portal[1].x;
			float camY = portal[1].y;


			t = portal_timer / 3;
			camX = camStartX + t * (camTargetX - camStartX);
			camY = camStartY + t * (camTargetY - camStartY);

			AEGfxSetCamPosition(camX, camY);
			/*AEGfxSetCamPosition(portal[1].x, portal[1].y);*/
			portal_timer = PortalTimer(&portal_elapsedtime, int(portal_timer), portal_interval);

			player.yvel = 0;
			if (portal_timer == 4)
			{
				player.x = portal[0].x - portal[0].halfW - 20;
				player.y = portal[0].y;
				portal[1].positiontoken = 1;
				portal_timer = 0;
			}


		}
		else
		{
			viewportCollision(player.x, player.y, worldX, worldY, viewporthalfw, viewporthalfh, worldhalfW, worldhalfH, playerSpeed + player.xvel, playerSpeed + player.yvel);
		}


		//playerActualMovement(player.x, player.y, player.xvel, player.yvel); //LOCATED IN movement.cpp

		playerEasingMovement(player.xvel, stabliser);

		/*playerCollisionMapBoundary*/(player.x, player.y, object[0].x, object[0].y, player.halfW, player.halfH, object[0].halfW, object[0].halfH, playerSpeed + player.xvel, playerSpeed + player.yvel);

		incrementobjintializer = whichvariableincreased(incrementobjintializer, a, b, middlex, middley, optionhalfside, pMeshY1, pMeshY2, truemousex, truemousey);

		AEInputGetCursorPosition(&mouseX, &mouseY);

		//if(player.x<400 && player.x>-400 && player.y<400 && player.y > -300)
		//{
		/*viewportCollision(player.x, player.y, worldX, worldY, viewporthalfw, viewporthalfh, worldhalfW, worldhalfH, playerSpeed + player.xvel, playerSpeed + player.yvel);*/
		//}


		// Out of bounds
		if (playerOutofBounds(player.y, mapBoundary.y) == 1)
		{
			current = GS_RESTART;
		}

		if (exitCollisionDoor(player.x, player.y, exitdoor[0].x, exitdoor[0].y, player.halfW, player.halfH, exitdoor[0].halfW, exitdoor[0].halfH) == 1)
		{
			next = GS_WINSCREEN;
		}

		if (AEInputCheckTriggered(AEVK_ESCAPE))
		{
			next = GS_PAUSEMENU;
		}
		SavePlayerPostion();

		for (int i{ 0 }; i < maxBlackhole; ++i)
		{
			blackholeCollision(player.x, player.y, blackhole[i].x, blackhole[i].y, player.halfW, player.halfH, blackhole[i].halfW, blackhole[i].halfH);
			blackholeCollisionResponse(player.x, player.y, player.halfW, player.halfH, blackhole[i].x, blackhole[i].y, blackhole[i].halfW, blackhole[i].halfH);
		}

		updateSound();
	}
}

void Level6_Draw()
{
	// Draw background
	backgroundrender(pMesh, pTexBackground);

	// Draw platforms
	DisappearingPlatformRender(object, platformstate, pMesh, pTexPlatform1, pTexDisappearingPlat);

	// Change texture base on where player is facing
	if (AEInputCheckCurr(AEVK_D))
	{
		objectrender(player, ui, pMesh, collectible, pTexRight, portal, pTexPortal, pTexCollectible, blackhole, nodes, pTexNode, exitdoor, pTexExitdoor, pTexHook, pTexTrampoline, pTexBlackhole);
	}
	else if (AEInputCheckCurr(AEVK_A))
	{
		objectrender(player, ui, pMesh, collectible, pTexLeft, portal, pTexPortal, pTexCollectible, blackhole, nodes, pTexNode, exitdoor, pTexExitdoor, pTexHook, pTexTrampoline, pTexBlackhole);
	}
	else
	{
		objectrender(player, ui, pMesh, collectible, pTexFront, portal, pTexPortal, pTexCollectible, blackhole, nodes, pTexNode, exitdoor, pTexExitdoor, pTexHook, pTexTrampoline, pTexBlackhole);
	}

	//This is the part of your code which does the matrix translations, rotations and scaling
	kwanEuItemRender(pTexStick);

	// Print number of collectible collected
	char strBufferCollectible[100];
	memset(strBufferCollectible, 0, 100 * sizeof(char));
	sprintf_s(strBufferCollectible, "Coins:  %d", collectible_count);

	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

	f32 TextWidth, TextHeight;
	AEGfxGetPrintSize(fontId, strBufferCollectible, 1.0f, TextWidth, TextHeight);
	AEGfxPrint(fontId, strBufferCollectible, -0.90f, 0.8f, 1, 1.f, 1.f, 1.f);
}

void Level6_Free()
{
	for (int i = 0; i < meshMax; i++)
	{
		AEGfxMeshFree(pMesh[i]);
	}
	AEGfxMeshFree(itemMesh);
	freeSound();
}

void Level6_Unload()
{
	AEGfxTextureUnload(pTexFront);
	AEGfxTextureUnload(pTexRight);
	AEGfxTextureUnload(pTexLeft);
	AEGfxTextureUnload(pTexPortal);
	AEGfxTextureUnload(pTexPlatform1);
	AEGfxTextureUnload(pTexCollectible);
	AEGfxTextureUnload(pTexExitdoor);
	AEGfxTextureUnload(pTexBackground);
	AEGfxTextureUnload(pTexNode);
	AEGfxTextureUnload(pTexHook);
	AEGfxTextureUnload(pTexStick);
	AEGfxTextureUnload(pTexDisappearingPlat);
	AEGfxTextureUnload(pTexTrampoline);
	AEGfxTextureUnload(pTexBlackhole);

}