//==========================================================
// file		: movement.cpp
// 
// author   : Owen Quek
// 
// email	: o.quek@digipen.edu
//
// brief	: movement.cpp defines the functions for the player movemnt
//
// Copyright © 2023 DigiPen, All rights reserved.
//==========================================================

#pragma once
#include "allheaders.hpp"
#include "movement.hpp"

extern f64 delta;
extern f64 assumedFrameRate;
extern squareObject player;
extern float jumpspeed;

void playerInputMovement(float& pX, float& pY, float playerSpeedArg,int& jumptokenRef) {

	if (AEInputCheckCurr(AEVK_W) && jumptokenRef == 1)
	{
		pY = jumpspeed;
		jumptokenRef = 0;
	}

	if (AEInputCheckCurr(AEVK_A))
	{
		pX = -playerSpeedArg;
	}
	if (AEInputCheckCurr(AEVK_D))
	{
		pX = playerSpeedArg;
	}
}

void playerActualMovement(float& pX, float& pY, float& pxvel, float& pyvel)
{
	
	/*
	==================================================================================================================================
								THIS FUNCTION ENACTS THE PLAYER MOVEMENT AND STABALISES THEM AFTER INPUT IS REMOVED

						USAGE:	

								**NOTE**
								* THE pxvel AND pyvel ARE JUST SIMPLE LINES WHICH CHANGE THE LOCATION BASED ON VELOCITY
								* THE IF STATEMENTS INVOLVING THE STABILIZER
	==================================================================================================================================
	*/

	pX += (float)(pxvel * assumedFrameRate * delta);
	pY += (float)(pyvel * assumedFrameRate * delta);

}


void playerEasingMovement(float& pxvel, float& pyvel, float stabilizer)
{
	if (pxvel > 0)
	{
		pxvel -= (float)(stabilizer * delta * assumedFrameRate);
	}
	if (pxvel < 0)
	{
		pxvel += (float)(stabilizer * delta * assumedFrameRate);
	}

	if (pxvel <= 0.5 && pxvel >= -0.5)
	{
		pxvel = 0;
	}

}

void playerGravity(float& pY, float grav)
{
	pY -= (float)(grav * assumedFrameRate * delta);
}

void movementWhenHooked(float &pXvel, float &pYvel,float grav, rectangle itemArg, node* collidingNode) {

	pXvel = 0;
	pYvel = 0;
	playerInputMovement(player.xvel, player.yvel, playerSpeed, jumptoken); //LOCATED IN movement.cpp
	player.x -= (f32)(player.xvel * sin(itemArg.rotation) * assumedFrameRate * delta);
	player.y += (f32)(player.xvel * cos(itemArg.rotation) * assumedFrameRate * delta);
	pXvel = 0;
	pYvel = 0;

}