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



enum disappearstatus { CANTDISAPPEAR = 0, CANDISAPPEAR, DISAPPEARED, TIMERSTARTED };
//f64 elapsedtime;
//int timer;
int timer;
f64 interval;
f64 elapsedtime;
int lasttimer;

char strBuffer[100];
f32 TextWidth, TextHeight;
//==========================================================================================================================
//==========================================================================================================================
//f64 intervaltime;
int LastJump = 0;
int timerset = 0;

f64 normalElapsedTime;

struct PlatformState
{
	int state;
	int timer;
	f64 elapsedtime;
	f64 interval;
}platformstate[4] = {	CANTDISAPPEAR, 3, 0.0f, 1.0f,
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




int normalUpdateTimer(f64 * normalElapsedTime, int timer, f64 interval)
{
	*normalElapsedTime += AEFrameRateControllerGetFrameTime();
	if (*normalElapsedTime >= interval)
	{
		timer--;
		*normalElapsedTime = 0;
	}
	return timer;
}
void Level1_Load()
{
	std::cout << "GSM:Load\n";
	pTexFront = AEGfxTextureLoad("Assets/FCat_Front.png");
	AE_ASSERT_MESG(pTexFront, "Failed to create texture1!!");

	pTexRight = AEGfxTextureLoad("Assets/FCat_Right.png");
	AE_ASSERT_MESG(pTexRight, "Failed to create texture2!!");

	pTexLeft = AEGfxTextureLoad("Assets/FCat_Left.png");
	AE_ASSERT_MESG(pTexLeft, "Failed to create texture2!!");

	
	
}

// ----------------------------------------------------------------------------
// This function initialized the variables used in level 1
// prints Level1:Initialize to std output
// ----------------------------------------------------------------------------

void Level1_Initialize()
{
    ///fontId = AEGfxCreateFont("Assets/Roboto-Regular.ttf", 12);
	//fontId = AEGfxCreateFont("Assets/Roboto-Regular.ttf", 12);
	
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
	//fontId = AEGfxCreateFont("Assets/Roboto-Regular.ttf", 12);
	//-------------------------------------------------------------------------------------------------------------------------------------------------
	//make another array of max number of platforms size to keep track of which platforms cannot disappear, can disappear and have disappeared
	//enum disappearstatus { CantDisappear = 0, CanDisappear, Disappeared };
	//InitializeTimer(10, 1.0f);
	//fontId = AEGfxCreateFont("Assets/Roboto-Regular.ttf", 12);
	lasttimer = timer = 60;
	interval = 1.0f;
	elapsedtime = 0.0f;
	
	/*platformstate[0].state = CANTDISAPPEAR;
	platformstate[0].timer = 0;
	platformstate[0].elapsedtime = 0.0f;
	platformstate[0].interval = 0.0f;

	platformstate[1].state = CANDISAPPEAR;
	platformstate[1].timer = 3;
	platformstate[1].elapsedtime = 0.0f;
	platformstate[1].interval = 1.0f;

	platformstate[2].state = CANTDISAPPEAR;
	platformstate[2].timer = 0;
	platformstate[2].elapsedtime = 0.0f;
	platformstate[2].interval = 0.0f;

	platformstate[3].state = CANTDISAPPEAR;
	platformstate[3].timer = 0;
	platformstate[3].elapsedtime = 0.0f;
	platformstate[3].interval = 0.0f;*/

	
	
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

	if (timer > 0)
	{
		timer = normalUpdateTimer(&normalElapsedTime, timer, interval);
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

	//if(player.x<400 && player.x>-400 && player.y<400 && player.y > -300)
	//{
		viewportCollision(player.x, player.y, worldX, worldY, viewporthalfw, viewporthalfh, worldhalfW, worldhalfH, playerSpeed + player.xvel, playerSpeed + player.yvel);
	//}
	/*if (UpdateTimer() == 0)
	{
		next = GS_RESTART;
		timer = 10;
	}*/
	
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


}

