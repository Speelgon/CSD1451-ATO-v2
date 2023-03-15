#include "allheaders.hpp"
#include "objects.hpp"
#include "Level1.hpp"
#include "collision.hpp"

void hookUpdate() {

	float hypotenuse = 50;
	playerHook.x = player.x + hypotenuse * cos(item.rotation);
	playerHook.y = player.y - hypotenuse * sin(item.rotation);
	if (hookCollisionFlag == 1)	{
		playerHook.x = pointHookStuckX;
		playerHook.y = pointHookStuckY;

		while (player.x - playerHook.x > item.height * 2) {
			player.x -= 0.5;
		}
		while (player.x - playerHook.x < -item.height * 2) {
			player.x += 0.5;
		}
		while (player.y - playerHook.y > item.height * 2) {
			player.y -= 0.5;
		}
		while (player.y - playerHook.y < -item.height * 2) {
			player.y += 0.5;
		}
	}

}

