#pragma once
#include "allheaders.hpp"
#include "collision.hpp"

/*================================================================================================================================
							THIS NAMESPACE CONTAINS THE FUNCTIONS USED TO CHECK THE BOARDERS 
							FOR THE COLLISION FUNCTION BELOW.

					USAGE:	EACH INDIVIDUAL FUNCTION CHECKS ONE SIDE OF A SQUARE PLAYER WITH ANOTHER
							SIDE OF A SQUARE OBJECT AND SEES IF ITS WITHIN ITS LIMITS

							**NOTE**
							* DON'T BOTHER LOOKING AT THESE FUNCTIONS AS THEY'RE A PAIN TO UNDERSTAND.
							THE FUNCTION NAMES SHOULD BE SELF EXPLANATORY IF YOU WANT TO TAKE A LOOK*
================================================================================================================================
*/

namespace {
	

	int playerBottomLessThanObjectTop(float playerY, float objectY, float playerSize, float objectSize)
	{
		if (playerY - playerSize <= objectY + objectSize)
		return 1;
		else return 0;
	}
	int playerBottomGreaterThanObjectBottom(float playerY, float objectY, float playerSize, float objectSize)
	{
		if (playerY - playerSize >= objectY - objectSize)
		return 1;
		else return 0;
	}
	int playerTopGreaterThanObjectBottom(float playerY, float objectY, float playerSize, float objectSize)
	{
		if (playerY + playerSize >= objectY - objectSize)
		return 1;
		else return 0;
	}
	int playerTopLessThanObjectTop(float playerY, float objectY, float playerSize, float objectSize)
	{
		if (playerY + playerSize <= objectY + objectSize)
		return 1;
		else return 0;
	}

	int playerLeftLessThanObjectRight(float playerX, float objectX, float playerSize, float objectSize)
	{
		if (playerX - playerSize <= objectX + objectSize)
		return 1;
		else return 0;
	}
	int playerLeftGreaterThanObjectLeft(float playerX, float objectX, float playerSize, float objectSize)
	{	
		if (playerX - playerSize >= objectX - objectSize)
		return 1;
		else return 0;
	}
	int playerRightGreaterThanObjectLeft(float playerX, float objectX, float playerSize, float objectSize)
	{
		if (playerX + playerSize >= objectX - objectSize)
		return 1;
		else return 0;
	}
	int playerRightLessThanObjectRight(float playerX, float objectX, float playerSize, float objectSize)
	{
		if (playerX + playerSize <= objectX + objectSize)
		return 1;
		else return 0;
	}
}


/*
==================================================================================================================================
							THIS FUNCTION ENACTS THE PLAYER COLLISION FOR ALL FOUR SIDES OF A SQUARE

					USAGE:	FUNCTION EMPLOYS THE HELPER FUNCTIONS ABOVE TO DETERMINE IF THE COLLISION OCCURS
							AND REFLECTS THE OBJECT IN ACCORDANCE WITH WHICH SIDE IS CURRENTLY COLLIDING

							**NOTE**
							* CURRENT PROBLEM IS THAT THE PLAYER FUNCTIONS RUN IN ORDER
							* EG: THE LEFT/RIGHT COLLISION WILL TRIGGER BEFORE TOP/BOTTOM THEN IT WILL
							* MOVE SLIGHTLY TO THE LEFT/RIGHT BEFORE STOPPING AND ONLY REFLECTING TOP/BOTTOM
							* MAYBE INSTEAD OF DIRECTLY MODIFYING THE PLAYER SPEED, GIVE A TOKEN INSTEAD AND
							* THEN USE THOSE TOKENS TO RUN ANOTHER FUNCTION SO ONLY ONE REFLECT IS ALLOWED AT A TIME
==================================================================================================================================
*/




	void playerCollisionSquare(float& pX, float& pY, float& oX, float& oY, float& pSizeX, float& pSizeY, float& oSizeX, float& oSizeY, float& playerSpeedX, float& playerSpeedY,int& jumptoken,int& lefttoken, int& righttoken)
	{

	// Left side collision
		if (playerTopGreaterThanObjectBottom(pY, oY, pSizeY, oSizeY) && playerBottomLessThanObjectTop(pY, oY, pSizeY, oSizeY) && playerRightGreaterThanObjectLeft(pX, oX, pSizeX, oSizeX) && playerRightLessThanObjectRight(pX, oX, pSizeX, oSizeX) && lefttoken == 1)
		{
			pX -= abs(playerSpeedX);
			playerSpeedX = 0;
		}
	// Right side collision
		if (playerTopGreaterThanObjectBottom(pY, oY, pSizeY, oSizeY) && playerBottomLessThanObjectTop(pY, oY, pSizeY, oSizeY) && playerLeftGreaterThanObjectLeft(pX, oX, pSizeX, oSizeX) && playerLeftLessThanObjectRight(pX, oX, pSizeX, oSizeX) && righttoken == 1)
		{
			pX += abs(playerSpeedX);
			playerSpeedX = 0;
		}
	// Top side collision (ONLY TOP SIDE AND BOTTOM SIDE TAKE AWAY THE TOKENS)
		if (playerLeftLessThanObjectRight(pX, oX, pSizeX, oSizeX) && playerRightGreaterThanObjectLeft(pX, oX, pSizeX, oSizeX) && playerBottomLessThanObjectTop(pY, oY, pSizeY, oSizeY) && playerBottomGreaterThanObjectBottom(pY, oY, pSizeY, oSizeY))
		{
			pY += abs(playerSpeedY);
			playerSpeedY = 0;
			lefttoken = 0;
			righttoken = 0;
			jumptoken = 1;
		}
		// Bottom side collision	
		else if (playerLeftLessThanObjectRight(pX, oX, pSizeX, oSizeX) && playerRightGreaterThanObjectLeft(pX, oX, pSizeX, oSizeX) && playerTopGreaterThanObjectBottom(pY, oY, pSizeY, oSizeY) && playerTopLessThanObjectTop(pY, oY, pSizeY, oSizeY))
		{
			pY -= abs(playerSpeedY);
			playerSpeedY = 0;
			lefttoken = 0;
			righttoken = 0;
		}
		else
		{
			lefttoken = 1;
			righttoken = 1;
		}
}

	void playerCollisionMapBoundary(float& pX, float& pY, float& oX, float& oY, float& pSizeX, float& pSizeY, float& oSizeX, float& oSizeY, float playerSpeedX, float playerSpeedY)
	{

	}