#pragma once
#include "objects.hpp"
extern square player;
extern square object[maxObj];
extern square ui[5];
extern collectible1 collectible[maxCollectible];
extern portal1 portal[maxPortal];
extern blackhole1 blackhole[maxBlackhole];
extern rectangle item;
extern hook playerHook;
extern node nodes[maxNodes];

extern s32 mousePositionX, mousePositionY;
extern s32 relativeMouseX, relativeMouseY;
extern AEGfxVertexList* pMesh[30];
extern AEGfxVertexList* uiMesh[30];
extern AEGfxTexture* pTex[30];

extern AEGfxVertexList* itemMesh;
extern AEGfxTexture* pTexFront;
extern AEGfxTexture* pTexRight;
extern AEGfxTexture* pTexLeft;

extern AEGfxTexture* pTexPortal;
extern AEGfxTexture* pTexPlatform;
extern AEGfxTexture* pTexCollectible;

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

void Level1_Load();

void Level1_Initialize();

void Level1_Update();

void Level1_Draw();

void Level1_Free();

void Level1_Unload();
