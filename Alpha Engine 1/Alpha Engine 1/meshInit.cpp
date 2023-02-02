#pragma once
#include "allheaders.hpp"
#include "objects.hpp"

/*================================================================================================================================
							
							INTSRUCTIONS FOR PRINTING SHAPES ON THE SCREEN
							1. DECLARE & INITIALIZE OBJECT (OBJECTS ALREADY DECLARED IN 
							   objectDecs.hpp AND INITIALIZED IN objectinit()
							   
							2. SET OBJECT VARIABLES IN objectlevel1init()
							   THIS MAY NOT BE objectlevel1init() IN THE FUTURE AS EACH
							   LEVEL NEEDS ITS OWN OBJECT LOCATIONS
							3. INITIALIZE MESHES (ALREADY INITIALIZED IN meshinit()
							4. SET THE OBJECTS TO THEIR RESPECTIVE MESHES IN meshinitlevel1()
							5. SET THE OBJECT TO RENDER IN objectrender()

================================================================================================================================
*/

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

void meshinitlevel1(squareObject* object, AEGfxVertexList** pMesh, squareObject* ui,collectibleObject* collectible,squareObject player, portalObject* portal) {
	
	//======================================================IMPORTANT BEFORE YOU DECLARE MESHES==========================================================
	//======================================================IMPORTANT BEFORE YOU DECLARE MESHES==========================================================
	//======================================================IMPORTANT BEFORE YOU DECLARE MESHES==========================================================
	/*
	 
-----------------------------------------------------------------Mesh 0 is for the player----------------------------------------------------------------

----------------------------------------------------------Meshes 1-9 are for collidable objects----------------------------------------------------------

-------------------------------------------------------------Meshes 10-19 are for collectibles-----------------------------------------------------------

---------------------------------------------------------------Rest are for UI parts but use-------------------------------------------------------------
	
	*/
	//===================================================================================================================================================
	//===================================================================================================================================================
	//===================================================================================================================================================

	AEGfxMeshStart();

	AEGfxTriAdd(
		-(player.width * 3), -player.halfH, 0x00FF0000, 0.0f, 1.0f,
		player.width * 3, -player.halfH, 0x00FF0000, 1.0f, 1.0f,
		-(player.width * 3), player.halfH, 0x00FF0000, 0.0f, 0.0f);

	AEGfxTriAdd(
		player.width * 3, -player.halfH, 0x0000FFFF, 1.0f, 1.0f,
		player.width * 3, player.halfH, 0x0000FFFF, 1.0f, 0.0f,
		-(player.width * 3), player.halfH, 0x0000FFFF, 0.0f, 0.0f);

	pMesh[0] = AEGfxMeshEnd();
	
	AEGfxMeshStart();

	AEGfxTriAdd(
		-object[0].halfW, -object[0].halfH, 0x00FF00FF, 0.0f, 1.0f,
		object[0].halfW, -object[0].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-object[0].halfW, object[0].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		object[0].halfW, -object[0].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		object[0].halfW, object[0].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-object[0].halfW, object[0].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	pMesh[1] = AEGfxMeshEnd();

	//===============================================================

	AEGfxMeshStart();

	AEGfxTriAdd(
		-object[1].halfW, -object[1].halfH, 0x00FF00FF, 0.0f, 1.0f,
		object[1].halfW, -object[1].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-object[1].halfW, object[1].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		object[1].halfW, -object[1].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		object[1].halfW, object[1].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-object[1].halfW, object[1].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	pMesh[2] = AEGfxMeshEnd();

	//===============================================================

	AEGfxMeshStart();

	AEGfxTriAdd(
		-object[2].halfW, -object[2].halfH, 0x00FF00FF, 0.0f, 1.0f,
		object[2].halfW, -object[2].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-object[2].halfW, object[2].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		object[2].halfW, -object[2].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		object[2].halfW, object[2].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-object[2].halfW, object[2].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	pMesh[3] = AEGfxMeshEnd();

	//===============================================================

	AEGfxMeshStart();

	AEGfxTriAdd(
		-object[3].halfW, -object[3].halfH, 0x00FF00FF, 0.0f, 1.0f,
		object[3].halfW, -object[3].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-object[3].halfW, object[3].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		object[3].halfW, -object[3].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		object[3].halfW, object[3].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-object[3].halfW, object[3].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	pMesh[4] = AEGfxMeshEnd();

	//===================================================================================================================================================
	//===================================================================================================================================================

	//Printing collectibles

	AEGfxMeshStart();

	AEGfxTriAdd(
		-collectible[0].halfW, -collectible[0].halfH, 0x00FF00FF, 0.0f, 1.0f,
		collectible[0].halfW, -collectible[0].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-collectible[0].halfW, collectible[0].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		collectible[0].halfW, -collectible[0].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		collectible[0].halfW, collectible[0].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-collectible[0].halfW, collectible[0].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	// Saving the mesh (list of triangles) in pMesh2

	pMesh[10] = AEGfxMeshEnd();

	//===================================================================================================================================================
	//===================================================================================================================================================

	//Printing portals

	AEGfxMeshStart();

	AEGfxTriAdd(
		-portal[0].halfW, -portal[0].halfH, 0x00FF00FF, 0.0f, 1.0f,
		portal[0].halfW, -portal[0].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-portal[0].halfW, portal[0].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		portal[0].halfW, -portal[0].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		portal[0].halfW, portal[0].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-portal[0].halfW, portal[0].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	pMesh[11] = AEGfxMeshEnd();

	//===============================================================

	AEGfxMeshStart();

	AEGfxTriAdd(
		-portal[1].halfW, -portal[1].halfH, 0x00FF00FF, 0.0f, 1.0f,
		portal[1].halfW, -portal[1].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-portal[1].halfW, portal[1].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		portal[1].halfW, -portal[1].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		portal[1].halfW, portal[1].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-portal[1].halfW, portal[1].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	pMesh[12] = AEGfxMeshEnd();

	//===================================================================================================================================================
	//===================================================================================================================================================

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

	

}