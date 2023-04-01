//==========================================================
// file		: catdeath.cpp
// 
// author   : Owen Quek
// 
// email	: o.quek@digipen.edu
//
// brief	: catdeath.cpp contains the death animation for the cat
//
// Copyright © 2023 DigiPen, All rights reserved.
//==========================================================


#include "allheaders.hpp"
#include "objects.hpp"

extern f64 delta;
extern f64 assumedFrameRate;


void catdeath() {
	if ((timeDead += (float)delta) < deathSeconds)
	{
		player.yvel += (float)0.3;
		player.y += (f32)(player.yvel * delta * assumedFrameRate);
	}
	else 
	{
		player.yvel -= 2*gravity;
		player.y += (f32)(player.yvel * delta * assumedFrameRate);
	}
	

}
