#pragma once
#include "allheaders.hpp"
#include "movement.hpp"

extern f64 delta;
extern f64 assumedFrameRate;
extern squareObject player;
//For the movement, the variables are passed in as functions, so the extern thing isn't really necessary here, thats also why its less complicated wrt variable placement

void playerInputMovement(float& pX, float& pY, float playerSpeed,int& jumptoken) {

	if (AEInputCheckCurr(AEVK_SPACE) && jumptoken == 1)
	{
		pY = 8;
		jumptoken = 0;
	}

	if (AEInputCheckCurr(AEVK_A))
	{
		pX = -playerSpeed;
	}
	if (AEInputCheckCurr(AEVK_D))
	{
		pX = playerSpeed;
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

	pX += pxvel * assumedFrameRate * delta;
	pY += pyvel * assumedFrameRate * delta;

}


void playerEasingMovement(float& pxvel, float& pyvel, float stabilizer)
{
	if (pxvel > 0)
	{
		pxvel -= stabilizer * delta * assumedFrameRate;
	}
	if (pxvel < 0)
	{
		pxvel += stabilizer * delta * assumedFrameRate;
	}
	//if (pyvel > 0)
	//{
	//	pyvel -= stabilizer;
	//}
	//if (pyvel < 0)
	//{
	//	pyvel += stabilizer;
	//}
	if (pxvel <= 0.5 && pxvel >= -0.5)
	{
		pxvel = 0;
	}
	//if (pyvel <= 0.5 && pyvel >= -0.5)
	//{
	//	pyvel = 0;
	//}
}

void playerGravity(float& pY, float grav)
{
	pY -= grav * assumedFrameRate * delta;
}

void movementWhenHooked(float &pXvel, float &pYvel,float grav, rectangle item, node* collidingNode) {
	
	//pXvel += grav * cos(item.rotation);
	//pYvel += grav * sin(item.rotation);
	pXvel = 0;
	pYvel = 0;
	playerInputMovement(player.xvel, player.yvel, playerSpeed, jumptoken); //LOCATED IN movement.cpp
	player.x += player.xvel * sin(item.rotation);
	player.y -= player.xvel * cos(item.rotation);
	pXvel = 0;
	pYvel = 0;
	//float xdist = player.x - collidingNode->x;
	//float ydist = player.y - collidingNode->y;
	//if (player.x-collidingNode->x >= xdist)
	//{
	//	//player.x = xdist;
	//}
	//if (player.y-collidingNode->y >= ydist)
	//{
	//	//player.y = ydist;
	//}

	//AEVec2 tension;
	//tension.x = 0;
	//tension.y = 0;
	//tension.x = (grav) * cos(item.rotation);
	//tension.y = (grav) * sin(item.rotation);
	//pXvel += tension.x;
	//pYvel += tension.y;

}