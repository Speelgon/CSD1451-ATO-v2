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

void objectinit(squareObject* object);

void uiinit(squareObject* ui);

void uilevel1init(squareObject* ui);

void objectlevel1init(squareObject* object);

void meshinit(squareObject* object, AEGfxVertexList** pMesh);

void meshinitlevel1(squareObject* object, AEGfxVertexList** pMesh, squareObject* ui, squareObject* collectibles);

void textureinit(AEGfxTexture** pTex);

void objectrender(squareObject player, squareObject* object, squareObject* ui, AEGfxVertexList** pMesh, squareObject* collectibles);