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

void meshinit(squareObject* object1, AEGfxVertexList** pMesh) {

	for (int i = 0; i < meshMax; i++)
	{
		pMesh[i] = 0;

		AEGfxMeshStart();

		AEGfxTriAdd(
			-object1[0].halfW, -object1[0].halfH, 0x00FF00FF, 0.0f, 1.0f,
			object1[0].halfW, -object1[0].halfH, 0x00FFFF00, 1.0f, 1.0f,
			-object1[0].halfW, object1[0].halfH, 0x0000FFFF, 0.0f, 0.0f);

		AEGfxTriAdd(
			object1[0].halfW, -object1[0].halfH, 0x00FFFFFF, 1.0f, 1.0f,
			object1[0].halfW, object1[0].halfH, 0x00FFFFFF, 1.0f, 0.0f,
			-object1[0].halfW, object1[0].halfH, 0x00FFFFFF, 0.0f, 0.0f);

		// Saving the mesh (list of triangles) in pMesh2

		pMesh[i] = AEGfxMeshEnd();

		AE_ASSERT_MESG(pMesh[i], "Failed to create mesh!!");

	}
}

void meshinitlevel1(squareObject* object1, AEGfxVertexList** pMesh, squareObject* ui, collectibleObject* collectible, squareObject player, portalObject* portal, hook playerHook, blackhole1* blackhole, exitDoor *exitdoor) {
	
	//======================================================IMPORTANT BEFORE YOU DECLARE MESHES==========================================================
	//======================================================IMPORTANT BEFORE YOU DECLARE MESHES==========================================================
	//======================================================IMPORTANT BEFORE YOU DECLARE MESHES==========================================================
	/*
	 
-----------------------------------------------------------------Mesh 0 is for the player----------------------------------------------------------------

----------------------------------------------------------Meshes 1-9 are for collidable objects----------------------------------------------------------

-------------------------------------------------------------Meshes 10-19 are for collectibles-----------------------------------------------------------

---------------------------------------------------------------Rest are for UI parts but use-------------------------------------------------------------
	
-------------------------------------------------------------Meshes 30-40 are for trampolines-----------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///															Updated as of 9/3/2023 
///		meshMax 50; Player 0; 
///		Platforms 1,2,3,4,7,8,9; 
///		Hooks 5,6; 
///		Collectibles 10,13,14; 
///		Portal {11,12}; 
///		UI 25; 
///		Trampoline 30;
///		Blackhole 50; 
///		Backgorund 120; 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




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

	//===============================================================
	
	AEGfxMeshStart();

	AEGfxTriAdd(
		-object1[0].halfW, -object1[0].halfH, 0x00FF00FF, 0.0f, 1.0f,
		object1[0].halfW, -object1[0].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-object1[0].halfW, object1[0].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		object1[0].halfW, -object1[0].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		object1[0].halfW, object1[0].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-object1[0].halfW, object1[0].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	pMesh[1] = AEGfxMeshEnd();

	//===============================================================

	AEGfxMeshStart();

	AEGfxTriAdd(
		-object1[1].halfW, -object1[1].halfH, 0x00FF00FF, 0.0f, 1.0f,
		object1[1].halfW, -object1[1].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-object1[1].halfW, object1[1].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		object1[1].halfW, -object1[1].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		object1[1].halfW, object1[1].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-object1[1].halfW, object1[1].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	pMesh[2] = AEGfxMeshEnd();

	//===============================================================

	AEGfxMeshStart();

	AEGfxTriAdd(
		-object1[2].halfW, -object[2].halfH, 0x00FF00FF, 0.0f, 1.0f,
		object1[2].halfW, -object1[2].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-object1[2].halfW, object1[2].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		object1[2].halfW, -object1[2].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		object1[2].halfW, object1[2].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-object1[2].halfW, object1[2].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	pMesh[3] = AEGfxMeshEnd();

	//===============================================================

	AEGfxMeshStart();

	AEGfxTriAdd(
		-object1[3].halfW, -object1[3].halfH, 0x00FF00FF, 0.0f, 1.0f,
		object1[3].halfW, -object1[3].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-object1[3].halfW, object1[3].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		object1[3].halfW, -object1[3].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		object1[3].halfW, object1[3].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-object1[3].halfW, object1[3].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	pMesh[4] = AEGfxMeshEnd();
	//===============================================================

	AEGfxMeshStart();

	AEGfxTriAdd(
		-object1[3].halfW, -object1[3].halfH, 0x00FF00FF, 0.0f, 1.0f,
		object1[3].halfW, -object1[3].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-object1[3].halfW, object1[3].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		object1[3].halfW, -object1[3].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		object1[3].halfW, object1[3].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-object1[3].halfW, object1[3].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	pMesh[7] = AEGfxMeshEnd();
	//===============================================================

	AEGfxMeshStart();

	AEGfxTriAdd(
		-object1[3].halfW, -object1[3].halfH, 0x00FF00FF, 0.0f, 1.0f,
		object1[3].halfW, -object1[3].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-object1[3].halfW, object1[3].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		object1[3].halfW, -object1[3].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		object1[3].halfW, object1[3].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-object1[3].halfW, object1[3].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	pMesh[8] = AEGfxMeshEnd();
	//===============================================================

	AEGfxMeshStart();

	AEGfxTriAdd(
		-object1[3].halfW, -object1[3].halfH, 0x00FF00FF, 0.0f, 1.0f,
		object1[3].halfW, -object1[3].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-object1[3].halfW, object1[3].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		object1[3].halfW, -object1[3].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		object1[3].halfW, object1[3].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-object1[3].halfW, object1[3].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	pMesh[9] = AEGfxMeshEnd();


	//=============== Print collision nodes ====================//
	//node 1
	AEGfxMeshStart();
	
	AEGfxTriAdd(
		-25, -25, 0x00FF00FF, 0.0f, 1.0f,
		25, -25, 0x00FFFF00, 1.0f, 1.0f,
		-25, 25, 0x0000FFFF, 0.0f, 0.0f);
	
	AEGfxTriAdd(
		25, -25, 0x00FFFFFF, 1.0f, 1.0f,
		25, 25, 0x00FFFFFF, 1.0f, 0.0f,
		-25, 25, 0x00FFFFFF, 0.0f, 0.0f);
	
	pMesh[5] = AEGfxMeshEnd();
	
	//node 2
	AEGfxMeshStart();
	
	AEGfxTriAdd(
		-25, -25, 0x00FF00FF, 0.0f, 1.0f,
		25, -25, 0x00FFFF00, 1.0f, 1.0f,
		-25, 25, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		25, -25, 0x00FFFFFF, 1.0f, 1.0f,
		25, 25, 0x00FFFFFF, 1.0f, 0.0f,
		-25, 25, 0x00FFFFFF, 0.0f, 0.0f);
	
	pMesh[6] = AEGfxMeshEnd();

	//=============== End of printing collision node ================//


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

	pMesh[10] = AEGfxMeshEnd();

	
	AEGfxMeshStart();
	AEGfxTriAdd(
		-collectible[1].halfW, -collectible[1].halfH, 0x00FF00FF, 0.0f, 1.0f,
		collectible[1].halfW, -collectible[1].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-collectible[1].halfW, collectible[1].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		collectible[1].halfW, -collectible[1].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		collectible[1].halfW, collectible[1].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-collectible[1].halfW, collectible[1].halfH, 0x00FFFFFF, 0.0f, 0.0f);
	pMesh[13] = AEGfxMeshEnd();
	
	AEGfxMeshStart();
	AEGfxTriAdd(
		-collectible[2].halfW, -collectible[2].halfH, 0x00FF00FF, 0.0f, 1.0f,
		collectible[2].halfW, -collectible[2].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-collectible[2].halfW, collectible[2].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		collectible[2].halfW, -collectible[2].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		collectible[2].halfW, collectible[2].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-collectible[2].halfW, collectible[2].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	pMesh[14] = AEGfxMeshEnd();

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

	//possibly trampoline
	AEGfxMeshStart();

	AEGfxTriAdd(
		-playerHook.halfW, -playerHook.halfH, 0x00FF00FF, 0.0f, 1.0f,
		playerHook.halfW, -playerHook.halfH, 0x00FFFF00, 1.0f, 1.0f,
		-playerHook.halfW, playerHook.halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		playerHook.halfW, -playerHook.halfH, 0x00FFFFFF, 1.0f, 1.0f,
		playerHook.halfW, playerHook.halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-playerHook.halfW, playerHook.halfH, 0x00FFFFFF, 0.0f, 0.0f);

	pMesh[15] = AEGfxMeshEnd();


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

	//===================================================================================================================================================

	AEGfxMeshStart();

	AEGfxTriAdd(
		-trampoline[0].halfW, -trampoline[0].halfH, 0x00FF00FF, 0.0f, 1.0f,
		trampoline[0].halfW, -trampoline[0].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-trampoline[0].halfW, trampoline[0].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		trampoline[0].halfW, -trampoline[0].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		trampoline[0].halfW, trampoline[0].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-trampoline[0].halfW, trampoline[0].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	// Saving the mesh (list of triangles) in pMesh2

	pMesh[30] = AEGfxMeshEnd();

	//===================================================================================================================================================

	AEGfxMeshStart();

	AEGfxTriAdd(
		-blackhole[0].halfW, -blackhole[0].halfH, 0x00FF00FF, 0.0f, 1.0f,
		blackhole[0].halfW, -blackhole[0].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-blackhole[0].halfW, blackhole[0].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		blackhole[0].halfW, -blackhole[0].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		blackhole[0].halfW, blackhole[0].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-blackhole[0].halfW, blackhole[0].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	// Saving the mesh (list of triangles) in pMesh2

	pMesh[50] = AEGfxMeshEnd();

	//===================================================================================================================================================

	AEGfxMeshStart();

	AEGfxTriAdd(
		-exitdoor[0].halfW, -exitdoor[0].halfH, 0x00FF0000, 0.0f, 1.0f,
		exitdoor[0].halfW, -exitdoor[0].halfH, 0x00FF0000, 1.0f, 1.0f,
		-exitdoor[0].halfW, exitdoor[0].halfH, 0x00FF0000, 0.0f, 0.0f);

	AEGfxTriAdd(
		exitdoor[0].halfW, -exitdoor[0].halfH, 0x0000FFFF, 1.0f, 1.0f,
		exitdoor[0].halfW, exitdoor[0].halfH, 0x0000FFFF, 1.0f, 0.0f,
		-exitdoor[0].halfW, exitdoor[0].halfH, 0x0000FFFF, 0.0f, 0.0f);

	pMesh[60] = AEGfxMeshEnd();

	//===================================================================================================================================================
	//Printing Game Background

	AEGfxMeshStart();

	AEGfxTriAdd(
		-3000, -2000, 0x00FF0000, 0.0f, 12.0f,
		3000, -2000, 0x00FF0000, 12.0f, 12.0f,
		-3000, 2000, 0x00FF0000, 0.0f, 0.0f);

	AEGfxTriAdd(
		3000, -2000, 0x0000FFFF, 12.0f, 12.0f,
		3000, 2000, 0x0000FFFF, 12.0f, 0.0f,
		-3000, 2000, 0x0000FFFF, 0.0f, 0.0f);

	pMesh[120] = AEGfxMeshEnd();



}