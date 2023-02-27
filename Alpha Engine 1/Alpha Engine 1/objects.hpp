#pragma once
#define maxObj 150
#define meshMax 50
#define maxBlackhole 20
#define maxUI 5
#define maxCollectible 5
#define maxPortal 10
#define maxNodes 10
#define maxTrampolines 10
#define maxDoor 5
typedef struct squareObject {
	f32 x, y;
	float width, height;
	float halfW, halfH;
	float xvel, yvel;
	int lefttoken,righttoken;
}square;

typedef struct rectangleObject {
	//AEMtx33 scale{}, rotation{}, transform{};
	f32 x, y;
	AEVec2 direction;
	float width, height;
	float rotation;
}rectangle;

typedef struct collectibleObject {
	f32 x, y;
	float width, height;
	float halfW, halfH;
	float xvel, yvel;
	int visibility;
}collectible1;

typedef struct portalObject {
	f32 x, y;
	float width, height;
	float halfW, halfH;
	float xvel, yvel;
	int positiontoken;

}portal1;

typedef struct hook1 {
	f32 x, y;
	float width, height;
	float halfW, halfH;
	int active;
}hook;

typedef struct blackhole1 {
	f32 x, y;
	float width, height;
	float halfW, halfH;
	float gravPull;
	float pullRadius;
}blackhole1;

typedef struct boundaryArea {
	f32 y;
}boundary;

typedef struct nodeObject {
	f32 x, y;
	float width, height;
	float halfW, halfH;
}node;

typedef struct trampoline1 {
	f32 x, y;
	float width, height;
	float halfW, halfH;
	int lefttoken, righttoken;
}tramp;

typedef struct exitDoor {
	f32 x, y;
	float width, height;
	float halfW, halfH;
}exits;

/*
enum that controls properties of a platform in a level.
*/
enum disappearstatus { CANTDISAPPEAR = 0, CANDISAPPEAR, DISAPPEARED, TIMERSTARTED };

/*
struct that contains all variables for the disappearing platform object.
disappearstatus state: enum value that defines characteristic of platform on each frame
int timer: Starting value of timer. Only applies to disappearing platforms
f64 elapsedtime: Total elapsed time form moment player comes into contact with platform
f64 interval: length of time between 2 values that are tracked in elapsedtime
*/
struct PlatformState
{
	disappearstatus state;
	int timer;
	f64 elapsedtime;
	f64 interval;
};


void objectinit(squareObject* object);

void uiinit(squareObject* ui);

void uilevel1init(squareObject* ui);

void objectlevel1init(squareObject* object);

void objectlevel1NEWinit(squareObject* object);

void objectlevel2init(squareObject* object);

void objectlevel3init(squareObject* object);

void meshinit(squareObject* object, AEGfxVertexList** pMesh);

void meshinitlevel1(squareObject* object, AEGfxVertexList** pMesh, squareObject* ui, collectibleObject* collectible, squareObject player, portalObject* portal, hook playerHook, blackhole1* blackhole, exitDoor* door);

void textureinit(AEGfxTexture** pTex);

void blackholeinit(blackhole1* object);

void blackholelevel1init(blackhole1* object);

void trampolineinit(tramp* object);

void trampolinelevel1init(tramp* object);

void backgroundrender(squareObject player, AEGfxVertexList** pMesh, AEGfxTexture* pTexBackground);

void objectrender(squareObject player, squareObject* object, squareObject* ui, AEGfxVertexList** pMesh, collectibleObject* collectible, AEGfxTexture* pTex, portalObject* portal, AEGfxTexture* pTexPortal, AEGfxTexture* pTextPlatform, AEGfxTexture* pTexCollectible, blackhole1* blackhole, nodeObject* nodes, AEGfxTexture* pTexNode, PlatformState* platformstate, exitDoor* exitdoor, AEGfxTexture* pTexExitdoor);

void collectibleinit(collectibleObject* object);

void collectiblelevel1init(collectibleObject* object);

void collectiblelevel1NEWinit(collectibleObject* object);

void collectiblelevel2init(collectibleObject* object);

void collectiblelevel3init(collectibleObject* object);

void portalinit(portalObject* object);

void portallevel1init(portalObject* object);

void portallevel3init(portalObject* object);

void hookinit(hook &playerHook);

void meshUpdate();

void anglePlayerToMouse();

void anglePlayerToNode(node nodes);

void kwanEuItemRender();

void hookUpdate();

void nodeInit(nodeObject *nodes);

void nodeInitlevel2(nodeObject* nodes);


void exitdoorinit(exitDoor* door);

void exitdoorlevel1init(exitDoor* door);

void exitdoorlevel1NEWinit(exitDoor* door);

void exitdoorlevel2init(exitDoor* door);

void exitdoorlevel3init(exitDoor* door);



