//==========================================================
// file		: utils.h
// 
// author   : Ng Yue Zhi
// co-author: Ng Wen Wen
// 
// email	: n.yuezhi@digipen.edu
//			  wenwen.ng@digipen.edu
// 
// brief	: utils.h contains declarations of a function to implement a generic timer
//
// Copyright © 2023 DigiPen, All rights reserved.
//==========================================================
#pragma once
#include "allheaders.hpp"

int normalUpdateTimer(f64* normalElapsedTime, int timer, f64 interval);
//int IsAreaClicked(float area_middleX, float area_middleY, float half_width, float half_height, int click_x, int click_y);
//void quit_confirmation_prompt(bool& quit_confirm);
float PortalTimer(f64* normalElapsedTime, int timer, f64 interval);