#pragma once
#define maxObj 30
#define meshMax 30

typedef struct squareObject {
	float x, y;
	float width, height;
	float halfW, halfH;
	float xvel, yvel;
	int lefttoken,righttoken;
}square;

void objectinit(squareObject* object);

void objectlevel1init(squareObject* object);

void meshinit(squareObject* object, AEGfxVertexList** pMesh);

void meshinitlevel1(squareObject* object, AEGfxVertexList** pMesh);