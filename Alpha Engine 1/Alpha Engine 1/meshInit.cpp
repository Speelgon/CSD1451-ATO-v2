#pragma once
#include "allheaders.hpp"
#include "objects.hpp"



void meshinit(squareObject* object, AEGfxVertexList** pMesh) {

	for (int i = 0; i < meshMax; i++)
	{
		pMesh[i] = 0;

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

void meshinitlevel1(squareObject* object, AEGfxVertexList** pMesh, squareObject* ui, squareObject* collectibles) {

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

	pMesh[1] = AEGfxMeshEnd();

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

	pMesh[2] = AEGfxMeshEnd();

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

	pMesh[3] = AEGfxMeshEnd();

	AEGfxMeshStart();

	AEGfxTriAdd(
		-object[3].halfW, -object[3].halfH, 0x00FF00FF, 0.0f, 1.0f,
		object[3].halfW, -object[3].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-object[3].halfW, object[3].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		object[3].halfW, -object[3].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		object[3].halfW, object[3].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-object[3].halfW, object[3].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	// Saving the mesh (list of triangles) in pMesh2

	pMesh[4] = AEGfxMeshEnd();


	//Printing the UI Parts
	AEGfxMeshStart();

	AEGfxTriAdd(
		-ui[0].halfW, -ui[0].halfH, 0x00FF00FF, 0.0f, 1.0f,
		ui[0].halfW, -ui[0].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-ui[0].halfW, ui[0].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		ui[0].halfW, -ui[0].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		ui[0].halfW, ui[0].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-ui[0].halfW, ui[0].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	// Saving the mesh (list of triangles) in pMesh2

	pMesh[25] = AEGfxMeshEnd();

	//Printing collectibles
	AEGfxMeshStart();

	AEGfxTriAdd(
		-collectibles[0].halfW, -collectibles[0].halfH, 0x00FF00FF, 0.0f, 1.0f,
		collectibles[0].halfW, -collectibles[0].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-collectibles[0].halfW, collectibles[0].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		collectibles[0].halfW, -collectibles[0].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		collectibles[0].halfW, collectibles[0].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-collectibles[0].halfW, collectibles[0].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	// Saving the mesh (list of triangles) in pMesh2

	pMesh[5] = AEGfxMeshEnd();

}