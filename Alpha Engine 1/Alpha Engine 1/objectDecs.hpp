#pragma once

#include "allheaders.hpp"
#include "objects.hpp"

/*================================================================================================================================
ALL VARIABLES HERE WILL BE REQUIRED FOR EVERY LEVEL WE WILL BE USING
================================================================================================================================
*/

/*================================================================================================================================
DECLARES THE VARIABLES WE NEED TO USE
================================================================================================================================
*/

square object[maxObj];
square ui[maxUI];
collectible1 collectible[maxCollectible];
portal1 portal[maxPortal];
blackhole1 blackhole[maxBlackhole];
square player;
hook playerHook;
rectangle item;
boundary mapBoundary;
exits exitdoor[maxDoor];
node nodes[maxNodes];
tramp trampoline[maxTrampolines];

AEGfxVertexList* pMesh[meshMax];
AEGfxVertexList* uiMesh[maxUI];
AEGfxTexture* pTex[30];

AEGfxVertexList* itemMesh = 0;
AEGfxTexture* pTexFront = 0;
AEGfxTexture* pTexRight = 0;
AEGfxTexture* pTexLeft = 0;
AEGfxTexture* pTexPortal = 0;
AEGfxTexture* pTexPlatform = 0;
AEGfxTexture* pTexPlatform1 = 0;
AEGfxTexture* pTexCollectible = 0;
AEGfxTexture* pTexExitdoor = 0;
AEGfxTexture* pTexBackground = 0;
AEGfxTexture* pTexNode = 0;
AEGfxTexture* pTexHook = 0;
AEGfxTexture* pTexStick = 0;
AEGfxTexture* pTexDisappearingPlat = 0;
AEGfxTexture* pTexTrampoline = 0;
AEGfxTexture* pTexBlackhole = 0;

float stabliser = 0.25;
float gravity = 0.15;
float jumpspeed = 8;
int jumptoken = 1;
float playerSpeed = 2;
int hookCollisionFlag = 0;
int collidedNode = -1;
s32 mousePositionX, mousePositionY;
s32 relativeMouseX, relativeMouseY;
f64 delta = 1/60.0;
f64 assumedFrameRate = 60;
float pointHookStuckX = 0;
float pointHookStuckY = 0;
int collectible_count = 0;
float deathSeconds = 0.3;
float resetCheck = 0.0;
float timeDead = 0;




HWND mainWindow;
HWND currentWindow;

GS_STATES previousState = GS_MAINMENU;

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

bool portalled{ false }, collectibleHit{ false }, platformDisappear{ false }, trampolined{ false }, blackholeTouched{ false };
//==========================================================================================================================
//==========================================================================================================================
