//==========================================================
// file		: vpCollision.cpp
// 
// author   : Ng Yue Zhi
// 
// email	: n.yuezhi@digipen.edu
//			  
// brief	: vpCollision.cpp contains definitions for the viewport collision
//
// Copyright © 2023 DigiPen, All rights reserved.
//==========================================================

#pragma once
#include "allheaders.hpp"
#include "vpCollision.hpp"
namespace {

	int leftToken = 1, rightToken = 1;

	//World boundary collision
	int VplayerBottomLessThanObjectTop(float playerY, float objectY, float playerSize, float objectSize)
	{
		if (playerY - playerSize <= objectY - objectSize)
		{
			return 1;
		}
		else return 0;
	}
	int VplayerBottomGreaterThanObjectBottom(float playerY, float objectY, float playerSize, float objectSize)
	{
		if (playerY - playerSize >= objectY + objectSize)
		{
			return 1;
		}
		else return 0;
	}
	int VplayerTopGreaterThanObjectBottom(float playerY, float objectY, float playerSize, float objectSize)
	{
		if (playerY + playerSize >= objectY + objectSize)
		{
			return 1;
		}
		else return 0;
	}
	int VplayerTopLessThanObjectTop(float playerY, float objectY, float playerSize, float objectSize)
	{
		if (playerY + playerSize <= objectY - objectSize)
		{
			return 1;
		}
		else return 0;
	}

	int VplayerLeftLessThanObjectRight(float playerX, float objectX, float playerSize, float objectSize)
	{
		if (playerX - playerSize <= objectX + objectSize)
		{
			return 1;
		}
		else return 0;
	}
	int VplayerLeftGreaterThanObjectLeft(float playerX, float objectX, float playerSize, float objectSize)
	{
		if (playerX - playerSize >= objectX - objectSize)
		{
			return 1;
		}
		else return 0;
	}
	int VplayerRightGreaterThanObjectLeft(float playerX, float objectX, float playerSize, float objectSize)
	{
		if (playerX + playerSize >= objectX - objectSize)
		{
			return 1;
		}
		else return 0;
	}
	int VplayerRightLessThanObjectRight(float playerX, float objectX, float playerSize, float objectSize)
	{
		if (playerX + playerSize <= objectX + objectSize)
		{
			return 1;
		}
		else return 0;
	}


	/*int playerRightmoreThanObjectRight(float playerX, float objectX, float playerSize, float objectSize)
	{
		if (playerX + playerSize >= objectX + objectSize)
		{
			return 1;
		}
		else return 0;
	}


	int playerTopMoreThanObjectTop(float playerY, float objectY, float playerSize, float objectSize)
	{
		if (playerY + playerSize >= objectY + objectSize)
		{
			return 1;
		}
		else return 0;
	}*/


}



void viewportCollision(float& vX, float& vY, float worldXarg, float worldYarg, float& vW, float& vH, float worldhalfw, float worldhalfh, float playerSpeedX, float playerSpeedY)
{
	//float camX, camY;
	//cam position follows player.x, player.y
	AEGfxSetCamPosition(vX, vY);
	if (VplayerTopGreaterThanObjectBottom(vY, worldYarg, vH, worldhalfh) && VplayerBottomLessThanObjectTop(vY, worldYarg, vH, worldhalfh) && VplayerRightGreaterThanObjectLeft(vX, worldXarg, vW, worldhalfw) && VplayerRightLessThanObjectRight(vX, worldXarg, vW, worldhalfw) && leftToken == 1)
	{
		AEGfxSetCamPosition(vX - playerSpeedX, vY);
	}
	// Right side collision
	if (VplayerTopGreaterThanObjectBottom(vY, worldYarg, vH, worldhalfh) && VplayerBottomLessThanObjectTop(vY, worldYarg, vH, worldhalfh) && VplayerLeftGreaterThanObjectLeft(vX, worldXarg, vW, worldhalfw) && VplayerLeftLessThanObjectRight(vX, worldXarg, vW, worldhalfw) && rightToken == 1)
	{
		AEGfxSetCamPosition(vX + playerSpeedX, vY);
	}
	// Top side collision (ONLY TOP SIDE AND BOTTOM SIDE TAKE AWAY THE TOKENS)
	if (VplayerLeftLessThanObjectRight(vX, worldXarg, vW, worldhalfw) && VplayerRightGreaterThanObjectLeft(vX, worldXarg, vW, worldhalfw) && VplayerBottomLessThanObjectTop(vY, worldYarg, vH, worldhalfh) && VplayerBottomGreaterThanObjectBottom(vY, worldYarg, vH, worldhalfh))
	{
		AEGfxSetCamPosition(vX, vY + playerSpeedY);
		leftToken = 0;
		rightToken = 0;
	}
	// Bottom side collision	
	else if (VplayerLeftLessThanObjectRight(vX, worldXarg, vW, worldhalfw) && VplayerRightGreaterThanObjectLeft(vX, worldXarg, vW, worldhalfw) && VplayerTopGreaterThanObjectBottom(vY, worldYarg, vH, worldhalfh) && VplayerTopLessThanObjectTop(vY, worldYarg, vH, worldhalfh))
	{
		AEGfxSetCamPosition(vX, vY - playerSpeedY);
		leftToken = 0;
		rightToken = 0;
	}
	else
	{
		leftToken = 1;
		rightToken = 1;
	}






	/*if (playerRightmoreThanObjectRight(vX, worldXarg, vW, worldhalfw))
	{
		AEGfxSetCamPosition(vX-playerSpeedY, vY);
	}*/

	//if (viewportRightlessThanRightWorld(vX, worldXarg, vW) && viewportLeftmoreThanLeftWorld(vX, minworldX, vW) && viewportBottommoreThanBottomWorld(vY, minworldY, vH) && viewportToplessThanTopWorld(vY, worldYarg, vH))
	//{
	//	AEGfxSetCamPosition(vX, vY);
	//}
	////cam position halts
	//else 
	//{
	//	AEGfxGetCamPosition(&camX, &camY);
	//	AEGfxSetCamPosition(camX, camY);
	//}
}