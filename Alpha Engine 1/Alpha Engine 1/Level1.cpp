#pragma once
#include "allheaders.hpp"
#include "Level1.hpp"
#include "movement.hpp"
#include "objects.hpp"
#include "collision.hpp"
#include "IncrementVariable.hpp"
#include "vpCollision.hpp"

extern f64 delta;
extern f64 assumedFrameRate;
//==========================================================================================================================
//==========================================================================================================================

void Level1_Load()
{
	std::cout << "GSM:Load\n";
}

// ----------------------------------------------------------------------------
// This function initialized the variables used in level 1
// prints Level1:Initialize to std output
// ----------------------------------------------------------------------------

void Level1_Initialize()
{

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

	objectinit(object);

	hookinit(playerHook);

	collectibleinit(collectible);

	collectiblelevel1init(collectible);

	portalinit(portal);

	portallevel1init(portal);

	uiinit(ui);

	uilevel1init(ui);

	objectlevel1init(object);

	textureinit(pTex);

	meshinit(object, pMesh);

	meshinitlevel1(object, pMesh, ui, collectible, player, portal, playerHook);

}

// ----------------------------------------------------------------------------
// This function updates the variables used in level 1 and
// prints Level1:Update to std output
// ----------------------------------------------------------------------------

void Level1_Update()
{	
	delta = AEFrameRateControllerGetFrameTime();

	if (AEInputCheckTriggered(AEVK_F))
	{
		item.height += 10.f;
		std::cout << "Printing";
	}

	playerInputMovement(player.xvel, player.yvel, playerSpeed, jumptoken); //LOCATED IN movement.cpp

	playerGravity(player.yvel, gravity);

	playerActualMovement(player.x, player.y, player.xvel, player.yvel); //LOCATED IN movement.cpp

	meshUpdate();

	hookUpdate();

	//Bounding box type collision

	for (int i = maxObj-1; i >= 0; i--)
	{
		playerCollisionSquare(player.x, player.y, object[i].x, object[i].y, player.halfW, player.halfH, object[i].halfW, object[i].halfH, player.xvel, player.yvel, jumptoken, object[i].lefttoken, object[i].righttoken); //LOCATED IN Collision.cpp
	}

	for (int i = 0; i < maxCollectible; i++)
	{
		playerCollisionCollectible(player.x, player.y, collectible[i].x, collectible[i].y, player.halfW, player.halfH, collectible[i].halfW, collectible[i].halfH, collectible[i].visibility);
	}
	if (AEInputCheckCurr(AEVK_LBUTTON))
	{
		for (int i = 0; i < maxObj; i++)
		{
			
		}
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
	

	playerEasingMovement(player.xvel, player.yvel, stabliser);

	playerCollisionMapBoundary(player.x, player.y, object[0].x, object[0].y, player.halfW, player.halfH, object[0].halfW, object[0].halfH, playerSpeed + player.xvel, playerSpeed + player.yvel);

	incrementobjintializer = whichvariableincreased(incrementobjintializer, a, b, middlex, middley, optionhalfside, pMeshY1, pMeshY2, truemousex, truemousey);

	AEInputGetCursorPosition(&mouseX, &mouseY);

	//if(player.x<400 && player.x>-400 && player.y<400 && player.y > -300)
	//{
		viewportCollision(player.x, player.y, worldX, worldY, viewporthalfw, viewporthalfh, worldhalfW, worldhalfH, playerSpeed + player.xvel, playerSpeed + player.yvel);
	//}

}

void Level1_Draw()
{

	// Change texture base on where player is facing
	if (AEInputCheckCurr(AEVK_D))
	{
		objectrender(player, object, ui, pMesh, collectible, pTexRight, portal, pTexPortal, pTexPlatform, pTexCollectible);
	}
	else if (AEInputCheckCurr(AEVK_A))
	{
		objectrender(player, object, ui, pMesh, collectible, pTexLeft, portal, pTexPortal, pTexPlatform, pTexCollectible);
	}
	else
	{
		objectrender(player, object, ui, pMesh, collectible, pTexFront, portal, pTexPortal, pTexPlatform, pTexCollectible);
	}

	//This is the part of your code which does the matrix translations, rotations and scaling
	kwanEuItemRender();
}

void Level1_Free()
{
	for (int i = 0; i < meshMax; i++)
	{
		AEGfxMeshFree(pMesh[i]);
	}
	AEGfxMeshFree(itemMesh);
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

