#pragma once
#define maxObj 30
#define meshMax 30
#define maxUI 5
typedef struct squareObject {
	float x, y;
	float width, height;
	float halfW, halfH;
	float xvel, yvel;
	int lefttoken,righttoken;
}square;

typedef struct rectangleObject {
	//AEMtx33 scale{}, rotation{}, transform{};
	AEVec2 position, direction;
	float width, height;
	float rotation;
}rectangle;

void objectinit(squareObject* object);

void uiinit(squareObject* ui);

void uilevel1init(squareObject* ui);

void objectlevel1init(squareObject* object);

void meshinit(squareObject* object, AEGfxVertexList** pMesh);

void meshinitlevel1(squareObject* object, AEGfxVertexList** pMesh, squareObject* ui);

void textureinit(AEGfxTexture** pTex);

void objectrender(squareObject player, squareObject* object, squareObject* ui, AEGfxVertexList** pMesh);