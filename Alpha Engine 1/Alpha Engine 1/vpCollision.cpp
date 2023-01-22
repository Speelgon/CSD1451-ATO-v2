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



void viewportCollision(float& vX, float& vY, float worldX, float worldY, float& vW, float& vH, float worldhalfw, float worldhalfh, float playerSpeedX, float playerSpeedY)
{
	float camX, camY;
	//cam position follows player.x, player.y
	AEGfxSetCamPosition(vX, vY);
	if (VplayerTopGreaterThanObjectBottom(vY, worldY, vH, worldhalfh) && VplayerBottomLessThanObjectTop(vY, worldY, vH, worldhalfh) && VplayerRightGreaterThanObjectLeft(vX, worldX, vW, worldhalfw) && VplayerRightLessThanObjectRight(vX, worldX, vW, worldhalfw) && leftToken == 1)
	{
		AEGfxSetCamPosition(vX - playerSpeedX, vY);
	}
	// Right side collision
	if (VplayerTopGreaterThanObjectBottom(vY, worldY, vH, worldhalfh) && VplayerBottomLessThanObjectTop(vY, worldY, vH, worldhalfh) && VplayerLeftGreaterThanObjectLeft(vX, worldX, vW, worldhalfw) && VplayerLeftLessThanObjectRight(vX, worldX, vW, worldhalfw) && rightToken == 1)
	{
		AEGfxSetCamPosition(vX + playerSpeedX, vY);
	}
	// Top side collision (ONLY TOP SIDE AND BOTTOM SIDE TAKE AWAY THE TOKENS)
	if (VplayerLeftLessThanObjectRight(vX, worldX, vW, worldhalfw) && VplayerRightGreaterThanObjectLeft(vX, worldX, vW, worldhalfw) && VplayerBottomLessThanObjectTop(vY, worldY, vH, worldhalfh) && VplayerBottomGreaterThanObjectBottom(vY, worldY, vH, worldhalfh))
	{
		AEGfxSetCamPosition(vX, vY + playerSpeedY);
		leftToken = 0;
		rightToken = 0;
	}
	// Bottom side collision	
	else if (VplayerLeftLessThanObjectRight(vX, worldX, vW, worldhalfw) && VplayerRightGreaterThanObjectLeft(vX, worldX, vW, worldhalfw) && VplayerTopGreaterThanObjectBottom(vY, worldY, vH, worldhalfh) && VplayerTopLessThanObjectTop(vY, worldY, vH, worldhalfh))
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






	/*if (playerRightmoreThanObjectRight(vX, worldX, vW, worldhalfw))
	{
		AEGfxSetCamPosition(vX-playerSpeedY, vY);
	}*/

	//if (viewportRightlessThanRightWorld(vX, worldX, vW) && viewportLeftmoreThanLeftWorld(vX, minworldX, vW) && viewportBottommoreThanBottomWorld(vY, minworldY, vH) && viewportToplessThanTopWorld(vY, worldY, vH))
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