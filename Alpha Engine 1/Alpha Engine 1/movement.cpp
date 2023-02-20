#pragma once
#include "allheaders.hpp"
#include "movement.hpp"

extern f64 delta;
extern f64 assumedFrameRate;
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
