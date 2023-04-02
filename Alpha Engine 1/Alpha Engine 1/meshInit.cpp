//==========================================================
// file		: mesInit.cpp
// 
// author   : Owen Quek
// 
// email	: o.quek@digipen.edu
//
// brief	: meshInit.cpp initializes all the meshes required
//
// Copyright © 2023 DigiPen, All rights reserved.
//==========================================================
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

void meshinit(squareObject* object1, AEGfxVertexList** pMeshPtr) {

	for (int i = 0; i < meshMax; i++)
	{
		pMeshPtr[i] = 0;

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

		pMeshPtr[i] = AEGfxMeshEnd();

		AE_ASSERT_MESG(pMeshPtr[i], "Failed to create mesh!!");

	}
}

void meshinitlevel1(squareObject* object1, AEGfxVertexList** pMeshPtr, squareObject* uiPtr, collectibleObject* collectiblePtr, squareObject playerArg, portalObject* portalPtr, hook playerHookArg, blackhole1* blackholePtr, exitDoor *exitdoorPtr) {
	
	//======================================================IMPORTANT BEFORE YOU DECLARE MESHES==========================================================
	//======================================================IMPORTANT BEFORE YOU DECLARE MESHES==========================================================
	//======================================================IMPORTANT BEFORE YOU DECLARE MESHES==========================================================
	/*
	 
-----------------------------------------------------------------Mesh 0 is for the playerArg----------------------------------------------------------------

----------------------------------------------------------Meshes 1-9 are for collidable objects----------------------------------------------------------

-------------------------------------------------------------Meshes 10-19 are for collectibles-----------------------------------------------------------

---------------------------------------------------------------Rest are for uiPtr parts but use-------------------------------------------------------------
	
-------------------------------------------------------------Meshes 30-40 are for trampolines-----------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///															Updated as of 9/3/2023 
///		meshMax 50; playerArg 0; 
///		Platforms 1,2,3,4,7,8,9; 
///		Hooks 5,6; 
///		Collectibles 10,13,14; 
///		portalPtr {11,12}; 
///		uiPtr 25; 
///		Trampoline 30;
///		blackholePtr 50; 
///		Backgorund 120; 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




	*/
	//===================================================================================================================================================
	//===================================================================================================================================================
	//===================================================================================================================================================

	AEGfxMeshStart();

	AEGfxTriAdd(
		-(playerArg.width * 3), -playerArg.halfH, 0x00FF0000, 0.0f, 1.0f,
		playerArg.width * 3, -playerArg.halfH, 0x00FF0000, 1.0f, 1.0f,
		-(playerArg.width * 3), playerArg.halfH, 0x00FF0000, 0.0f, 0.0f);

	AEGfxTriAdd(
		playerArg.width * 3, -playerArg.halfH, 0x0000FFFF, 1.0f, 1.0f,
		playerArg.width * 3, playerArg.halfH, 0x0000FFFF, 1.0f, 0.0f,
		-(playerArg.width * 3), playerArg.halfH, 0x0000FFFF, 0.0f, 0.0f);

	pMeshPtr[0] = AEGfxMeshEnd();

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

	pMeshPtr[1] = AEGfxMeshEnd();

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

	pMeshPtr[2] = AEGfxMeshEnd();

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

	pMeshPtr[3] = AEGfxMeshEnd();

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

	pMeshPtr[4] = AEGfxMeshEnd();
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

	pMeshPtr[7] = AEGfxMeshEnd();
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

	pMeshPtr[8] = AEGfxMeshEnd();
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

	pMeshPtr[9] = AEGfxMeshEnd();


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
	
	pMeshPtr[5] = AEGfxMeshEnd();
	
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
	
	pMeshPtr[6] = AEGfxMeshEnd();

	//=============== End of printing collision node ================//


	//===================================================================================================================================================
	//===================================================================================================================================================

	//Printing collectibles

	AEGfxMeshStart();

	AEGfxTriAdd(
		-collectiblePtr[0].halfW, -collectiblePtr[0].halfH, 0x00FF00FF, 0.0f, 1.0f,
		collectiblePtr[0].halfW, -collectiblePtr[0].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-collectiblePtr[0].halfW, collectiblePtr[0].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		collectiblePtr[0].halfW, -collectiblePtr[0].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		collectiblePtr[0].halfW, collectiblePtr[0].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-collectiblePtr[0].halfW, collectiblePtr[0].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	pMeshPtr[10] = AEGfxMeshEnd();

	
	AEGfxMeshStart();
	AEGfxTriAdd(
		-collectiblePtr[1].halfW, -collectiblePtr[1].halfH, 0x00FF00FF, 0.0f, 1.0f,
		collectiblePtr[1].halfW, -collectiblePtr[1].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-collectiblePtr[1].halfW, collectiblePtr[1].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		collectiblePtr[1].halfW, -collectiblePtr[1].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		collectiblePtr[1].halfW, collectiblePtr[1].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-collectiblePtr[1].halfW, collectiblePtr[1].halfH, 0x00FFFFFF, 0.0f, 0.0f);
	pMeshPtr[13] = AEGfxMeshEnd();
	
	AEGfxMeshStart();
	AEGfxTriAdd(
		-collectiblePtr[2].halfW, -collectiblePtr[2].halfH, 0x00FF00FF, 0.0f, 1.0f,
		collectiblePtr[2].halfW, -collectiblePtr[2].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-collectiblePtr[2].halfW, collectiblePtr[2].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		collectiblePtr[2].halfW, -collectiblePtr[2].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		collectiblePtr[2].halfW, collectiblePtr[2].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-collectiblePtr[2].halfW, collectiblePtr[2].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	pMeshPtr[14] = AEGfxMeshEnd();

	//===================================================================================================================================================
	//===================================================================================================================================================

	//Printing portals

	AEGfxMeshStart();

	AEGfxTriAdd(
		-portalPtr[0].halfW, -portalPtr[0].halfH, 0x00FF00FF, 0.0f, 1.0f,
		portalPtr[0].halfW, -portalPtr[0].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-portalPtr[0].halfW, portalPtr[0].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		portalPtr[0].halfW, -portalPtr[0].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		portalPtr[0].halfW, portalPtr[0].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-portalPtr[0].halfW, portalPtr[0].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	pMeshPtr[11] = AEGfxMeshEnd();

	//===============================================================

	AEGfxMeshStart();

	AEGfxTriAdd(
		-portalPtr[1].halfW, -portalPtr[1].halfH, 0x00FF00FF, 0.0f, 1.0f,
		portalPtr[1].halfW, -portalPtr[1].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-portalPtr[1].halfW, portalPtr[1].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		portalPtr[1].halfW, -portalPtr[1].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		portalPtr[1].halfW, portalPtr[1].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-portalPtr[1].halfW, portalPtr[1].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	pMeshPtr[12] = AEGfxMeshEnd();

	//===================================================================================================================================================
	//===================================================================================================================================================

	//possibly trampoline
	AEGfxMeshStart();

	AEGfxTriAdd(
		-playerHookArg.halfW, -playerHookArg.halfH, 0x00FF00FF, 0.0f, 1.0f,
		playerHookArg.halfW, -playerHookArg.halfH, 0x00FFFF00, 1.0f, 1.0f,
		-playerHookArg.halfW, playerHookArg.halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		playerHookArg.halfW, -playerHookArg.halfH, 0x00FFFFFF, 1.0f, 1.0f,
		playerHookArg.halfW, playerHookArg.halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-playerHookArg.halfW, playerHookArg.halfH, 0x00FFFFFF, 0.0f, 0.0f);

	pMeshPtr[15] = AEGfxMeshEnd();


	//===================================================================================================================================================
	//===================================================================================================================================================

	//Printing the uiPtr Parts
	AEGfxMeshStart();

	AEGfxTriAdd(
		-uiPtr[0].halfW, -uiPtr[0].halfH, 0x00FF00FF, 0.0f, 1.0f,
		uiPtr[0].halfW, -uiPtr[0].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-uiPtr[0].halfW, uiPtr[0].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		uiPtr[0].halfW, -uiPtr[0].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		uiPtr[0].halfW, uiPtr[0].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-uiPtr[0].halfW, uiPtr[0].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	// Saving the mesh (list of triangles) in pMesh2

	pMeshPtr[25] = AEGfxMeshEnd();

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

	pMeshPtr[30] = AEGfxMeshEnd();

	//===================================================================================================================================================

	AEGfxMeshStart();

	AEGfxTriAdd(
		-blackholePtr[0].halfW, -blackholePtr[0].halfH, 0x00FF00FF, 0.0f, 1.0f,
		blackholePtr[0].halfW, -blackholePtr[0].halfH, 0x00FFFF00, 1.0f, 1.0f,
		-blackholePtr[0].halfW, blackholePtr[0].halfH, 0x0000FFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		blackholePtr[0].halfW, -blackholePtr[0].halfH, 0x00FFFFFF, 1.0f, 1.0f,
		blackholePtr[0].halfW, blackholePtr[0].halfH, 0x00FFFFFF, 1.0f, 0.0f,
		-blackholePtr[0].halfW, blackholePtr[0].halfH, 0x00FFFFFF, 0.0f, 0.0f);

	// Saving the mesh (list of triangles) in pMesh2

	pMeshPtr[50] = AEGfxMeshEnd();

	//===================================================================================================================================================

	AEGfxMeshStart();

	AEGfxTriAdd(
		-exitdoorPtr[0].halfW, -exitdoorPtr[0].halfH, 0x00FF0000, 0.0f, 1.0f,
		exitdoorPtr[0].halfW, -exitdoorPtr[0].halfH, 0x00FF0000, 1.0f, 1.0f,
		-exitdoorPtr[0].halfW, exitdoorPtr[0].halfH, 0x00FF0000, 0.0f, 0.0f);

	AEGfxTriAdd(
		exitdoorPtr[0].halfW, -exitdoorPtr[0].halfH, 0x0000FFFF, 1.0f, 1.0f,
		exitdoorPtr[0].halfW, exitdoorPtr[0].halfH, 0x0000FFFF, 1.0f, 0.0f,
		-exitdoorPtr[0].halfW, exitdoorPtr[0].halfH, 0x0000FFFF, 0.0f, 0.0f);

	pMeshPtr[60] = AEGfxMeshEnd();

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

	pMeshPtr[120] = AEGfxMeshEnd();



}