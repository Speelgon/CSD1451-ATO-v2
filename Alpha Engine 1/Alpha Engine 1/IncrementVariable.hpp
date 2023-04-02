//==========================================================
// file		: IncrementVariable.cpp
// 
// author   : Ng Yue Zhi
// co-author: Ng Wen Wen
// 
// email	: n.yuezhi@digipen.edu
//			  wenwen.ng@digipen.edu
// 
// brief	: IncrementVariable.cpp declares functions to check if an area is clicked and increasing a variable
//
// Copyright © 2023 DigiPen, All rights reserved.
//==========================================================

#pragma once

bool passedoverobj();

int whichvariableincreased(int incrementobjintializer, int& a, int& b, float middlex, float middley, float optionhalfside, AEGfxVertexList* pMesh, AEGfxVertexList* pMesh2, int mousex, int mousey);

int IsAreaClicked(float area_middleX, float area_middleY, float half_width, float half_height, int click_x, int click_y);