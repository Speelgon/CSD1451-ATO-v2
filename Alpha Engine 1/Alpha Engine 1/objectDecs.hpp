#pragma once

#include "allheaders.hpp"
#include "objects.hpp"

/*================================================================================================================================
DECLARES THE VARIABLES WE NEED TO USE
================================================================================================================================
*/

square object[30];
square ui[5];
collectible1 collectible[maxCollectible];
portal1 portal[maxPortal];
square player;

rectangle item;


AEGfxVertexList* pMesh[30];
AEGfxVertexList* uiMesh[30];
AEGfxTexture* pTex[30];

AEGfxVertexList* itemMesh = 0;
AEGfxTexture* pTexFront = 0;
AEGfxTexture* pTexRight = 0;
AEGfxTexture* pTexLeft = 0;
AEGfxTexture* pTexPortal;


float stabliser = 0.25;
float gravity = 9.81;
int jumptoken = 1;
float playerSpeed = 3;





//==========================================================================================================================
	// Yuki's Variables
	//==========================================================================================================================
	// 
	// 
	// 

AEGfxVertexList* pMeshY1 = 0;
AEGfxVertexList* pMeshY2 = 0;
//store mouse position coordinates
s32 mouseX, mouseY;
//variables for passing over obj
int a;
int b;

int mousex = 0;
int mousey = 0;
int truemousex = 0;
int truemousey = 0;

int* clickx = &mousex;
int* clicky = &mousex;

float middlex = 30;
float middley = 220;
float optionside = 50;
float optionhalfside = optionside / 2;

int incrementobjintializer = 0;

//viewport 
float viewportwidth = player.width + 100;
float viewportheight = player.width + 100;
float viewporthalfw = viewportwidth / 2;
float viewporthalfh = viewportheight / 2;

//float camX, camY; // Used to temporary store camera position
float worldX = 0;
float worldY = 0;
float worldwidth = (float)AEGetWindowWidth();
float worldheight = (float)AEGetWindowHeight();
float worldhalfW = worldwidth / 2;
float worldhalfH = worldheight / 2;

//MAPSIZE
float mapx = 800;
float mapy = 400;
float halfmapx = mapx / 2;
float halfmapy = mapy / 2;

//==========================================================================================================================
//==========================================================================================================================
