#pragma once
#include "allheaders.hpp"
#include "movement.hpp"
#include "objects.hpp"
#include "collision.hpp"
#include "IncrementVariable.hpp"
#include "vpCollision.hpp"

extern square player;
extern square object[30];
extern square ui[5];
extern collectible1 collectible[maxCollectible];
extern rectangle item;

extern AEGfxVertexList* pMesh[30];
extern AEGfxVertexList* uiMesh[30];
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

extern int mousex;
extern int mousey;
extern int truemousex;
extern int truemousey;

extern float middlex;
extern float middley;
extern float optionside;
extern float optionhalfside;

extern int incrementobjintializer;

//viewport 
extern float viewportwidth;
extern float viewportheight;
extern float viewporthalfw;
extern float viewporthalfh;

//float camX, camY; // Used to temporary store camera position
extern float worldX;
extern float worldY;
extern float worldwidth;
extern float worldheight;
extern float worldhalfW;
extern float worldhalfH;

//MAPSIZE
extern float mapx;
extern float mapy;
extern float halfmapx;
extern float halfmapy;

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

	player.x = 0;
	player.y = 0;
	player.xvel = 0;
	player.yvel = 0;
	player.width = 10;
	player.height = 60;
	player.halfW = player.width / 2;
	player.halfH = player.height / 2;
	player.lefttoken = 0;
	player.righttoken = 0;

	item.position.x = player.x;
	item.position.y = player.y;
	item.rotation = 0;
	item.width = 8.f;
	item.height = 45.f;

	objectinit(object);

	collectibleinit(collectible);

	collectiblelevel1init(collectible);

	uiinit(ui);

	uilevel1init(ui);

	objectlevel1init(object);

	textureinit(pTex);

	meshinit(object, pMesh);

	meshinitlevel1(object, pMesh, ui, collectible, player);

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


}

// ----------------------------------------------------------------------------
// This function updates the variables used in level 1 and
// prints Level1:Update to std output
// ----------------------------------------------------------------------------

void Level1_Update()
{
	item.position.x = player.x;
	item.position.y = player.y;
	item.rotation = 0;
	item.width = 8.f;
	item.height = 45.f;

	playerInputMovement(player.xvel, player.yvel, playerSpeed, jumptoken); //LOCATED IN movement.cpp

	playerGravity(player.yvel, gravity);

	playerActualMovement(player.x, player.y, player.xvel, player.yvel); //LOCATED IN movement.cpp

	//Bounding box type collision

	for (int i = 0; i < maxObj; i++)
	{
		playerCollisionSquare(player.x, player.y, object[i].x, object[i].y, player.halfW, player.halfH, object[i].halfW, object[i].halfH, player.xvel, player.yvel, jumptoken, object[i].lefttoken, object[i].righttoken); //LOCATED IN Collision.cpp
	}

	for (int i = 0; i < maxCollectible; i++)
	{
		playerCollisionCollectible(player.x, player.y, collectible[i].x, collectible[i].y, player.halfW, player.halfH, collectible[i].halfW, collectible[i].halfH, collectible[i].visibility);
	}

	playerEasingMovement(player.xvel, player.yvel, stabliser);

	playerCollisionMapBoundary(player.x, player.y, object[0].x, object[0].y, player.halfW, player.halfH, object[0].halfW, object[0].halfH, playerSpeed + player.xvel, playerSpeed + player.yvel);

	AEInputGetCursorPosition(clickx, clicky);
	//std::cout << mousex - screenwidth/2 + player.x << '\n';
	//std::cout << - mousey + screenheight/2 + player.y   << '\n';
	truemousex = mousex - screenwidth / 2 + player.x;
	truemousey = -mousey + screenheight / 2 + player.y;

	incrementobjintializer = whichvariableincreased(incrementobjintializer, a, b, middlex, middley, optionhalfside, pMeshY1, pMeshY2, truemousex, truemousey);

	AEInputGetCursorPosition(&mouseX, &mouseY);

	if(player.x<400 && player.x>-400 && player.y<400 && player.y > -300)
	{
		viewportCollision(player.x, player.y, worldX, worldY, viewporthalfw, viewporthalfh, worldhalfW, worldhalfH, playerSpeed + player.xvel, playerSpeed + player.yvel);
	}

}


void Level1_Draw()
{

	// Change texture base on where player is facing
	if (AEInputCheckCurr(AEVK_D))
	{
		objectrender(player, object, ui, pMesh, collectible, pTexRight);
	}
	else if (AEInputCheckCurr(AEVK_A))
	{
		objectrender(player, object, ui, pMesh, collectible, pTexLeft);
	}
	else
	{
		objectrender(player, object, ui, pMesh, collectible, pTexFront);
	}



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

	item.direction.x = worldwidth / 2 + (mouseX - float(AEGetWindowWidth() / 2)) * cos(item.rotation) - (mouseY - float(AEGetWindowHeight() / 2)) * sin(item.rotation);
	item.direction.y = worldheight / 2 + (mouseX - float(AEGetWindowWidth() / 2)) * sin(item.rotation) + (mouseY - float(AEGetWindowHeight() / 2)) * cos(item.rotation);
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
}

