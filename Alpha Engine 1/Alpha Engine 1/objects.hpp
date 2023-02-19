#pragma once
#define maxObj 150
#define meshMax 50
#define maxUI 5
#define maxCollectible 5
#define maxPortal 2

typedef struct squareObject {
	f32 x, y;
	float width, height;
	float halfW, halfH;
	float xvel, yvel;
	int lefttoken,righttoken;
}square;

typedef struct rectangleObject {
	//AEMtx33 scale{}, rotation{}, transform{};
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
}blackhole;

void objectinit(squareObject* object);

void uiinit(squareObject* ui);

void uilevel1init(squareObject* ui);

void objectlevel1init(squareObject* object);

void meshinit(squareObject* object, AEGfxVertexList** pMesh);

void meshinitlevel1(squareObject* object, AEGfxVertexList** pMesh, squareObject* ui, collectibleObject* collectible, squareObject player, portalObject* portal, hook playerHook);

void textureinit(AEGfxTexture** pTex);

void objectrender(squareObject player, squareObject* object, squareObject* ui, AEGfxVertexList** pMesh, collectibleObject* collectible, AEGfxTexture* pTex, portalObject* portal, hook playerHook);

void collectibleinit(collectibleObject* object);

void collectiblelevel1init(collectibleObject* object);

void portalinit(portalObject* object);

void portallevel1init(portalObject* object);

void hookinit(hook &playerHook);

void meshUpdate();

void kwanEuItemRender();

void hookUpdate();