#pragma once
#include "AEEngine.h"
#include <cstdlib>
#include <iostream>

//if a player passes over an object, player can choose to increase variable 1 or 2, 
//enable the selection of an increase of variable 1 or 2
//use button press as condition for function to run 


	//detects mouse click in a rectangular space
	int IsAreaClicked(float area_middleX, float area_middleY, float half_width, float half_height, int click_x, int click_y)
	{
		/*this function detects if the mouse is clicked within a rectangle at the main menu */
		// area_middleX and area_middleY: coordinates of the centre of the rectangle (x, y)
		// area_width and area_height: the width of the rectangle, the height of the rectangle
		// click_x and click_y: the mouse coordinates (x, y)
		//float halfw = area_width / 2;
		//float halfh = area_height / 2;
		/*int mousepositionx, mousepositiony;
		mousepositionx = *click_x;
		mousepositiony = *click_y;*/



		float max_x = area_middleX + half_width;
		float max_y = area_middleY + half_height;
		float min_x = area_middleX - half_width;
		float min_y = area_middleY - half_height;


		if (AEInputCheckCurr(AEVK_LBUTTON))
		{
			std::cout << "The L mouse works   " << click_x << '\n';
			if ((click_x > min_x) && (click_x < max_x) && (click_y > min_y) && (click_y < max_y))
			{

				std::cout << "detected in area" << '\n';
				return 1;
			}
		}


		return 0;
	}


bool passedoverobj()
{
	float show = 1;
	//show the mouse cursor on screen
	AEInputShowCursor(show);
	//condition for if player has passed over an object
	if (AEInputCheckCurr(AEVK_Z))
	{
		return 1;
	}
}


//&a &b allows direct access to modify the input parameter
int whichvariableincreased(int incrementobjintializer, int& a, int& b, float middlex, float middley, float optionhalfside, AEGfxVertexList* pMesh, AEGfxVertexList* pMesh2, int mousex, int mousey)
{

	//makes left rectangle for option a
	if (AEInputCheckCurr(AEVK_X) && !incrementobjintializer)
	{
		incrementobjintializer = 1;
	}

	if (incrementobjintializer)
	{


		std::cout << mousey << '\n';

		//exit

		if (IsAreaClicked(middlex, middley, optionhalfside, optionhalfside, mousex, mousey))
		{
			a += 1;
			incrementobjintializer = 0;
			std::cout << "detected square 1" << '\n';
		}
		if (IsAreaClicked(middlex + optionhalfside + 50, middley + optionhalfside + 50, optionhalfside, optionhalfside, mousex, mousey))
		{
			b += 1;
			//incrementobjintializer = 0;
			std::cout << "detected square 2" << '\n';
		}


		//create the mesh
		AEGfxMeshStart();

		// 1 triangle at a time
		// X, Y, Color, texU, texV
		//top left, top right, bottom left
		//top right, bottom right, bottom left

		AEGfxTriAdd(
			-optionhalfside, -optionhalfside, 0x00FF0000, 0.0f, 1.0f,
			optionhalfside, -optionhalfside, 0x00FF0000, 1.0f, 1.0f,
			-optionhalfside, optionhalfside, 0x00FF0000, 0.0f, 0.0f);

		AEGfxTriAdd(
			optionhalfside, -optionhalfside, 0x0000FFFF, 1.0f, 1.0f,
			optionhalfside, optionhalfside, 0x0000FFFF, 1.0f, 0.0f,
			-optionhalfside, optionhalfside, 0x0000FFFF, 0.0f, 0.0f);

		// Saving the mesh (list of triangles) in pMesh1

		pMesh = AEGfxMeshEnd();
		AE_ASSERT_MESG(pMesh, "Failed to create meshY1!!");


		AEGfxSetRenderMode(AE_GFX_RM_COLOR);
		// Set position for object
		AEGfxSetPosition(middlex, middley);
		// No texture for object
		AEGfxTextureSet(NULL, 0, 0);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(pMesh, AE_GFX_MDM_TRIANGLES);


		//second rectangle 
		//create the mesh
		AEGfxMeshStart();

		// 1 triangle at a time
		// X, Y, Color, texU, texV
		//top left, top right, bottom left
		//top right, bottom right, bottom left

		AEGfxTriAdd(
			-optionhalfside, -optionhalfside, 0x00FF0000, 0.0f, 1.0f,
			optionhalfside, -optionhalfside, 0x00FF0000, 1.0f, 1.0f,
			-optionhalfside, optionhalfside, 0x00FF0000, 0.0f, 0.0f);

		AEGfxTriAdd(
			optionhalfside, -optionhalfside, 0x0000FFFF, 1.0f, 1.0f,
			optionhalfside, optionhalfside, 0x0000FFFF, 1.0f, 0.0f,
			-optionhalfside, optionhalfside, 0x0000FFFF, 0.0f, 0.0f);

		// Saving the mesh (list of triangles) in pMesh1

		pMesh2 = AEGfxMeshEnd();
		AE_ASSERT_MESG(pMesh2, "Failed to create meshY1!!");


		AEGfxSetRenderMode(AE_GFX_RM_COLOR);
		// Set position for object
		AEGfxSetPosition(middlex + optionhalfside + 50, middley);
		// No texture for object
		AEGfxTextureSet(NULL, 0, 0);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(pMesh2, AE_GFX_MDM_TRIANGLES);
	}


	/*AEGfxQuad(middlex - optionhalfside, middley + optionhalfside, 0x00FFFFFF, 0.0f,
			  middlex - optionhalfside, middley - optionhalfside, 0x00FFFFFF, 0.0f,
			  middlex + optionhalfside, middley + optionhalfside, 0x00FFFFFF, 0.0f,
			  middlex + optionhalfside, middley - optionhalfside, 0x00FFFFFF, 0.0f);*/



}

//make two rectangles pop up when condition is checked labled a and b on bottom right side
//check if area is mouse clicked
//if detected mouse click in area a, increment a by 1, otherwise increment b by 1

