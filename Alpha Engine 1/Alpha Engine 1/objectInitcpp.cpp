#pragma once
#include "allheaders.hpp"
#include "objects.hpp"



void meshinit(squareObject* object, AEGfxVertexList** pMesh) {

	for (int i = 0; i < meshMax; i++)
	{
		AEGfxMeshStart();

		AEGfxTriAdd(
			-object[0].halfW, -object[0].halfH, 0x00FF00FF, 0.0f, 1.0f,
			object[0].halfW, -object[0].halfH, 0x00FFFF00, 1.0f, 1.0f,
			-object[0].halfW, object[0].halfH, 0x0000FFFF, 0.0f, 0.0f);

		AEGfxTriAdd(
			object[0].halfW, -object[0].halfH, 0x00FFFFFF, 1.0f, 1.0f,
			object[0].halfW, object[0].halfH, 0x00FFFFFF, 1.0f, 0.0f,
			-object[0].halfW, object[0].halfH, 0x00FFFFFF, 0.0f, 0.0f);

		// Saving the mesh (list of triangles) in pMesh2

		pMesh[i] = AEGfxMeshEnd();
		AE_ASSERT_MESG(pMesh[i], "Failed to create mesh!!");
	}
}

void meshinitlevel1(squareObject* object, AEGfxVertexList** pMesh) {

	AEGfxMeshStart();

	AEGfxTriAdd(
		-object[0].halfW, -object[0].halfH, 0x00FF00FF, 0.0f, 1.0f,
		object[0].halfW, -object[0].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-object[0].halfW, object[0].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		object[0].halfW, -object[0].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		object[0].halfW, object[0].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-object[0].halfW, object[0].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	// Saving the mesh (list of triangles) in pMesh2

	pMesh[0] = AEGfxMeshEnd();

	AEGfxMeshStart();

	AEGfxTriAdd(
		-object[1].halfW, -object[1].halfH, 0x00FF00FF, 0.0f, 1.0f,
		object[1].halfW, -object[1].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-object[1].halfW, object[1].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		object[1].halfW, -object[1].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		object[1].halfW, object[1].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-object[1].halfW, object[1].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	// Saving the mesh (list of triangles) in pMesh2

	pMesh[1] = AEGfxMeshEnd();

	AEGfxMeshStart();

	AEGfxTriAdd(
		-object[2].halfW, -object[2].halfH, 0x00FF00FF, 0.0f, 1.0f,
		object[2].halfW, -object[2].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-object[2].halfW, object[2].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		object[2].halfW, -object[2].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		object[2].halfW, object[2].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-object[2].halfW, object[2].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	// Saving the mesh (list of triangles) in pMesh2

	pMesh[2] = AEGfxMeshEnd();

}

void objectinit(squareObject* object) {

	for (int i = 0; i < maxObj; i++)
	{
		object[i].x = 2000;
		object[i].y = -2000;
		object[i].width = 10;
		object[i].height = 10;
		object[i].halfW = object[i].width / 2;
		object[i].halfH = object[i].height / 2;
		object[i].lefttoken = 0;
		object[i].righttoken = 0;
	}

}

void objectlevel1init(squareObject* object){

	object[0].x = 100;
	object[0].y = -100;
	object[0].width = 1000;
	object[0].height = 60;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;

	object[1].x = 400;
	object[1].y = 150;
	object[1].width = 200;
	object[1].height = 30;
	object[1].halfW = object[1].width / 2;
	object[1].halfH = object[1].height / 2;

	object[2].x = 100;
	object[2].y = 100;
	object[2].width = 400;
	object[2].height = 30;
	object[2].halfW = object[2].width / 2;
	object[2].halfH = object[2].height / 2;

	object[3].x = -300;
	object[3].y = 100;
	object[3].width = 100;
	object[3].height = 30;
	object[3].halfW = object[3].width / 2;
	object[3].halfH = object[3].height / 2;

}

void textureinit(AEGfxTexture** pTex)
{
	for (int i = 0; i < maxObj; i++)
	{
		pTex = 0;
	}
}
