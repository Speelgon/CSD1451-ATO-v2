#pragma once
#include "allheaders.hpp"


/*================================================================================================================================
							THIS NAMESPACE CONTAINS THE FUNCTIONS USED TO CHECK THE BOARDERS 
							FOR THE COLLISION FUNCTION BELOW.

					USAGE:	EACH INDIVIDUAL FUNCTION CHECKS ONE SIDE OF A SQUARE PLAYER WITH ANOTHER
							SIDE OF A SQUARE OBJECT AND SEES IF ITS WITHIN ITS LIMITS

							**NOTE**
							* DON'T BOTHER LOOKING AT THESE FUNCTIONS AS THEY'RE A PAIN TO UNDERSTAND.
							THE FUNCTION NAMES SHOULD BE SELF EXPLANATORY IF YOU WANT TO TAKE A LOOK*
================================================================================================================================*/

extern f64 delta;
extern f64 assumedFrameRate;
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
			pX -= abs(playerSpeedX) * assumedFrameRate * delta;
			//Making the player's speed zero caused some problems so Im temporarily removing it and now it works fine...  
			//playerSpeedX = 0;
		}
	// Right side collision
		if (playerTopGreaterThanObjectBottom(pY, oY, pSizeY, oSizeY) && playerBottomLessThanObjectTop(pY, oY, pSizeY, oSizeY) && playerLeftGreaterThanObjectLeft(pX, oX, pSizeX, oSizeX) && playerLeftLessThanObjectRight(pX, oX, pSizeX, oSizeX) && righttoken == 1)
		{
			pX += abs(playerSpeedX)* assumedFrameRate * delta;
			//Making the player's speed zero caused some problems so Im temporarily removing it and now it works fine...  
			//playerSpeedX = 0;
		}
	// Top side collision (ONLY TOP SIDE AND BOTTOM SIDE TAKE AWAY THE TOKENS)
		if (playerLeftLessThanObjectRight(pX, oX, pSizeX, oSizeX) && playerRightGreaterThanObjectLeft(pX, oX, pSizeX, oSizeX) && playerBottomLessThanObjectTop(pY, oY, pSizeY, oSizeY) && playerBottomGreaterThanObjectBottom(pY, oY, pSizeY, oSizeY))
		{
			playerSpeedY = 0;
			pY = oY + oSizeY + pSizeY;
			lefttoken = 0;
			righttoken = 0;
			jumptoken = 1;
		}
		// Bottom side collision	
		else if (playerLeftLessThanObjectRight(pX, oX, pSizeX, oSizeX) && playerRightGreaterThanObjectLeft(pX, oX, pSizeX, oSizeX) && playerTopGreaterThanObjectBottom(pY, oY, pSizeY, oSizeY) && playerTopLessThanObjectTop(pY, oY, pSizeY, oSizeY))
		{
			playerSpeedY = 0;
			pY = oY - oSizeY - pSizeY;
			lefttoken = 0;
			righttoken = 0;
		}
		else
		{
			lefttoken = 1;
			righttoken = 1;
		}
	}

	void playerCollisionCollectible(float& pX, float& pY, float& oX, float& oY, float& pSizeX, float& pSizeY, float& oSizeX, float& oSizeY, int& visibility, int &count)
	{
		if (playerTopGreaterThanObjectBottom(pY, oY, pSizeY, oSizeY) && playerBottomLessThanObjectTop(pY, oY, pSizeY, oSizeY) && playerRightGreaterThanObjectLeft(pX, oX, pSizeX, oSizeX) && playerRightLessThanObjectRight(pX, oX, pSizeX, oSizeX))
		{
			// Increment collectible count when collided and when visible
			// Added check for visibility and the counter will continue to increment when collided because of the other collision checks
			if (visibility == 1) {
				count += 1;
			}
			visibility = 0;
			collectibleHit = true;
			
			
			
		}
		// Right side collision
		if (playerTopGreaterThanObjectBottom(pY, oY, pSizeY, oSizeY) && playerBottomLessThanObjectTop(pY, oY, pSizeY, oSizeY) && playerLeftGreaterThanObjectLeft(pX, oX, pSizeX, oSizeX) && playerLeftLessThanObjectRight(pX, oX, pSizeX, oSizeX))
		{
			if (visibility == 1) {
				count += 1;
			}
			visibility = 0;
			collectibleHit = true;
			
			
		}
		// Top side collision (ONLY TOP SIDE AND BOTTOM SIDE TAKE AWAY THE TOKENS)
		if (playerLeftLessThanObjectRight(pX, oX, pSizeX, oSizeX) && playerRightGreaterThanObjectLeft(pX, oX, pSizeX, oSizeX) && playerBottomLessThanObjectTop(pY, oY, pSizeY, oSizeY) && playerBottomGreaterThanObjectBottom(pY, oY, pSizeY, oSizeY))
		{
			if (visibility == 1) {
				count += 1;
			}
			visibility = 0;
			collectibleHit = true;
			
			
		}
		// Bottom side collision	
		else if (playerLeftLessThanObjectRight(pX, oX, pSizeX, oSizeX) && playerRightGreaterThanObjectLeft(pX, oX, pSizeX, oSizeX) && playerTopGreaterThanObjectBottom(pY, oY, pSizeY, oSizeY) && playerTopLessThanObjectTop(pY, oY, pSizeY, oSizeY))
		{
			if (visibility == 1) {
				count += 1;
			}
			visibility = 0;
			collectibleHit = true;
			
			
		}
	}

/*
==================================================================================================================================
Portal Collision
==================================================================================================================================
*/

	void playerCollisionPortal(float& pX, float& pY, float& oX, float& oY, float& pSizeX, float& pSizeY, float& oSizeX, float& oSizeY, int& positiontoken)
	{
		if (playerTopGreaterThanObjectBottom(pY, oY, pSizeY, oSizeY) && playerBottomLessThanObjectTop(pY, oY, pSizeY, oSizeY) && playerRightGreaterThanObjectLeft(pX, oX, pSizeX, oSizeX) && playerRightLessThanObjectRight(pX, oX, pSizeX, oSizeX))
		{
			positiontoken = 0;
			portalled = true;
		}
		// Right side collision
		if (playerTopGreaterThanObjectBottom(pY, oY, pSizeY, oSizeY) && playerBottomLessThanObjectTop(pY, oY, pSizeY, oSizeY) && playerLeftGreaterThanObjectLeft(pX, oX, pSizeX, oSizeX) && playerLeftLessThanObjectRight(pX, oX, pSizeX, oSizeX))
		{
			positiontoken = 0;
			portalled = true;
		}
		// Top side collision (ONLY TOP SIDE AND BOTTOM SIDE TAKE AWAY THE TOKENS)
		if (playerLeftLessThanObjectRight(pX, oX, pSizeX, oSizeX) && playerRightGreaterThanObjectLeft(pX, oX, pSizeX, oSizeX) && playerBottomLessThanObjectTop(pY, oY, pSizeY, oSizeY) && playerBottomGreaterThanObjectBottom(pY, oY, pSizeY, oSizeY))
		{
			positiontoken = 0;
			portalled = true;
		}
		// Bottom side collision	
		else if (playerLeftLessThanObjectRight(pX, oX, pSizeX, oSizeX) && playerRightGreaterThanObjectLeft(pX, oX, pSizeX, oSizeX) && playerTopGreaterThanObjectBottom(pY, oY, pSizeY, oSizeY) && playerTopLessThanObjectTop(pY, oY, pSizeY, oSizeY))
		{
			positiontoken = 0;
			portalled = true;
		}
	}

	void playerCollisionMapBoundary(float& pX, float& pY, float& oX, float& oY, float& pSizeX, float& pSizeY, float& oSizeX, float& oSizeY, float playerSpeedX, float playerSpeedY)
	{

	}

	//collectibles will always have same size and width
	int playerOverCollectible(float px, float py, float cx, float cy, float cSize)
		{
		float cTopRight = cx + cSize;
		float cBottomLeft = cy + cSize;
		//float 
		return 0;
		}

	int playerHookCollision(node* nodes, hook* playerHook, int &collisionFlag) {
		
		f32 distance1{ 0 }, distance2{ 0 };

		for (int i{ 0 }; i < 2; ++i) {
			distance1 = playerHook->x - nodes[i].x;
			distance2 = playerHook->y - nodes[i].y;
			if (distance1 < 0) distance1 = -distance1;
			if (distance2 < 0) distance2 = -distance2;
			if (distance1 <= nodes[i].halfW && distance2 <= nodes[i].halfH) {
				collisionFlag = 1;
				collidedNode = i;
				pointHookStuckX = nodes[i].x;
				pointHookStuckY = nodes[i].y;
				jumptoken = 1;
				return 1;
			}
		}
		collisionFlag = 0;
		return 0;
	}

/*
==================================================================================================================================
Player out of bounds
==================================================================================================================================
*/

	int playerOutofBounds(float pY, float mY)
	{
		if (pY < mY)
		{
			std::cout << "Out-of-Bounds" << '\n';
			return 1;
		}
		return 0;
	}




	void playerCollisionTrampoline(float& pX, float& pY, float& oX, float& oY, float& pSizeX, float& pSizeY, float& oSizeX, float& oSizeY, float& playerSpeedX, float& playerSpeedY, int& jumptoken, int& lefttoken, int& righttoken)
	{

		// Left side collision
		if (playerTopGreaterThanObjectBottom(pY, oY, pSizeY, oSizeY) && playerBottomLessThanObjectTop(pY, oY, pSizeY, oSizeY) && playerRightGreaterThanObjectLeft(pX, oX, pSizeX, oSizeX) && playerRightLessThanObjectRight(pX, oX, pSizeX, oSizeX) && lefttoken == 1)
		{
			pX -= abs(playerSpeedX) * assumedFrameRate * delta;
			//Making the player's speed zero caused some problems so Im temporarily removing it and now it works fine...  
			//playerSpeedX = 0;
		}
		// Right side collision
		if (playerTopGreaterThanObjectBottom(pY, oY, pSizeY, oSizeY) && playerBottomLessThanObjectTop(pY, oY, pSizeY, oSizeY) && playerLeftGreaterThanObjectLeft(pX, oX, pSizeX, oSizeX) && playerLeftLessThanObjectRight(pX, oX, pSizeX, oSizeX) && righttoken == 1)
		{
			pX += abs(playerSpeedX) * assumedFrameRate * delta;
			//Making the player's speed zero caused some problems so Im temporarily removing it and now it works fine...  
			//playerSpeedX = 0;
		}
		// Top side collision (ONLY TOP SIDE AND BOTTOM SIDE TAKE AWAY THE TOKENS)
		if (playerLeftLessThanObjectRight(pX, oX, pSizeX, oSizeX) && playerRightGreaterThanObjectLeft(pX, oX, pSizeX, oSizeX) && playerBottomLessThanObjectTop(pY, oY, pSizeY, oSizeY) && playerBottomGreaterThanObjectBottom(pY, oY, pSizeY, oSizeY))
		{
			playerSpeedY = 10;
			lefttoken = 0;
			righttoken = 0;
			jumptoken = 1;
		}
		// Bottom side collision	
		else if (playerLeftLessThanObjectRight(pX, oX, pSizeX, oSizeX) && playerRightGreaterThanObjectLeft(pX, oX, pSizeX, oSizeX) && playerTopGreaterThanObjectBottom(pY, oY, pSizeY, oSizeY) && playerTopLessThanObjectTop(pY, oY, pSizeY, oSizeY))
		{
			playerSpeedY = 0;
			pY = oY - oSizeY - pSizeY;
			lefttoken = 0;
			righttoken = 0;
		}
		else
		{
			lefttoken = 1;
			righttoken = 1;
		}
	}


	/*
	==================================================================================================================================
	Exit Door Collision
	==================================================================================================================================
	*/

	int exitCollisionDoor(float& pX, float& pY, float& oX, float& oY, float& pSizeX, float& pSizeY, float& oSizeX, float& oSizeY)
	{
		if (playerTopGreaterThanObjectBottom(pY, oY, pSizeY, oSizeY) && playerBottomLessThanObjectTop(pY, oY, pSizeY, oSizeY) && playerRightGreaterThanObjectLeft(pX, oX, pSizeX, oSizeX) && playerRightLessThanObjectRight(pX, oX, pSizeX, oSizeX))
		{
			return 1;
		}
		// Right side collision
		if (playerTopGreaterThanObjectBottom(pY, oY, pSizeY, oSizeY) && playerBottomLessThanObjectTop(pY, oY, pSizeY, oSizeY) && playerLeftGreaterThanObjectLeft(pX, oX, pSizeX, oSizeX) && playerLeftLessThanObjectRight(pX, oX, pSizeX, oSizeX))
		{
			return 1;
		}
		// Top side collision (ONLY TOP SIDE AND BOTTOM SIDE TAKE AWAY THE TOKENS)
		if (playerLeftLessThanObjectRight(pX, oX, pSizeX, oSizeX) && playerRightGreaterThanObjectLeft(pX, oX, pSizeX, oSizeX) && playerBottomLessThanObjectTop(pY, oY, pSizeY, oSizeY) && playerBottomGreaterThanObjectBottom(pY, oY, pSizeY, oSizeY))
		{
			return 1;
		}
		// Bottom side collision	
		else if (playerLeftLessThanObjectRight(pX, oX, pSizeX, oSizeX) && playerRightGreaterThanObjectLeft(pX, oX, pSizeX, oSizeX) && playerTopGreaterThanObjectBottom(pY, oY, pSizeY, oSizeY) && playerTopLessThanObjectTop(pY, oY, pSizeY, oSizeY))
		{
			return 1;
		}
		return 0;
		
	}