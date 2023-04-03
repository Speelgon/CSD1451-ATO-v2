//==========================================================
// file		: uiInit.cpp
// 
// author   : Owen Quek
// 
// email	: o.quek@digipen.edu
//
// brief	: uiInit.cpp was supposed to initialize all th emeshes required for the UI
// 
// Copyright © 2023 DigiPen, All rights reserved.
//==========================================================

#pragma once
#include "allheaders.hpp"
#include "objects.hpp"

void uiinit(squareObject* uiPtr)
{
	for (int i = 0; i < maxUI; i++)
	{
		uiPtr[i].x = 2000;
		uiPtr[i].y = -2000;
		uiPtr[i].width = 0;
		uiPtr[i].height = 0;
		uiPtr[i].halfW = uiPtr[i].width / 2;
		uiPtr[i].halfH = uiPtr[i].height / 2;
		uiPtr[i].lefttoken = 0;
		uiPtr[i].righttoken = 0;
	}
}

void uilevel1init(squareObject* uiPtr)
{
	uiPtr[0].x = 20000;
	uiPtr[0].y = 200;
	uiPtr[0].width = 200;
	uiPtr[0].height = 50;
	uiPtr[0].halfW = uiPtr[0].width / 2;
	uiPtr[0].halfH = uiPtr[0].height / 2;
	uiPtr[0].lefttoken = 0;
	uiPtr[0].righttoken = 0;
}