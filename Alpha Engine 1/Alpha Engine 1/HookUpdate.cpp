#include "allheaders.hpp"
#include "objects.hpp"
#include "Level1.hpp"
#include "collision.hpp"

void hookUpdate() {

	playerHook.width = 30;
	playerHook.height = 30;
	playerHook.halfH = playerHook.height / 2;
	playerHook.width = playerHook.width / 2;

	float hypotenuse = 50;
	playerHook.x = player.x + hypotenuse * cos(item.rotation);
	playerHook.y = player.y - hypotenuse * sin(item.rotation);
	if (hookCollisionFlag == 1)	{
		playerHook.x = pointHookStuckX;
		playerHook.y = pointHookStuckY;
	}
}



void itemUpdate() {
	
}

