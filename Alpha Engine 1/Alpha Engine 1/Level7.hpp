//==========================================================
// file		: Level7.hpp
// 
// author   : Owen Quek
// 
// email	: o.quek@digipen.edu
//
// brief	: Level7.hpp contains all variables for level 7
//
// Copyright � 2023 DigiPen, All rights reserved.
//==========================================================

#pragma once
#include "objects.hpp"

//==========================================================================================================================
//                                      START of declaration of variables 
//==========================================================================================================================
extern f64 delta;
extern f64 assumedFrameRate;

extern square player;
extern square object[maxObj];
extern square ui[maxUI];
extern collectible1 collectible[maxCollectible];
extern rectangle item;
extern hook playerHook;

extern s32 mousePositionX, mousePositionY; // the position of the hook
extern s32 relativeMouseX, relativeMouseY;
extern AEGfxVertexList* pMesh[meshMax];
extern AEGfxVertexList* uiMesh[maxUI];
extern AEGfxTexture* pTex[30];

extern AEGfxVertexList* itemMesh;
extern AEGfxTexture* pTexFront;
extern AEGfxTexture* pTexRight;
extern AEGfxTexture* pTexPortal;
extern AEGfxTexture* pTexPlatform;
extern AEGfxTexture* pTexCollectible;
extern AEGfxTexture* pTexExitdoor;
extern AEGfxTexture* pTexBackground;
extern AEGfxTexture* pTexNode;
extern AEGfxTexture* pTexHook;
extern AEGfxTexture* pTexStick;
extern AEGfxTexture* pTexDisappearingPlat;
extern AEGfxTexture* pTexTrampoline;
extern AEGfxTexture* pTexBlackhole;

extern float playerSpeed;
extern int jumptoken;
extern float gravity;
extern float stabliser;
extern int hookCollisionFlag;
extern float pointHookStuckX;
extern float pointHookStuckY;
extern int collidedNode;
extern float deathSeconds;
extern float timeDead;

//==========================================================================================================================
// Yuki's Variables
//==========================================================================================================================

extern AEGfxVertexList* pMeshY1;
extern AEGfxVertexList* pMeshY2;
//store mouse position coordinates 
extern s32 mouseX, mouseY;

extern int* clickx;
extern int* clicky;

//variables for passing over obj
extern int a;
extern int b;

// used for viewport
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
//                                      END of declaration of variables 
//==========================================================================================================================

void Level7_Load();

void Level7_Initialize();

void Level7_Update();

void Level7_Draw();

void Level7_Free();

void Level7_Unload();