#include "allheaders.hpp"
#include "objects.hpp"
#include "Level1.hpp"

void hookUpdate() {
	/*playerHook.x = player.x + 50;
	playerHook.y = player.y + 50;*/
	playerHook.width = 30;
	playerHook.height = 30;
	playerHook.halfH = playerHook.height / 2;
	playerHook.width = playerHook.width / 2;

	float hypotenuse = 50;
	playerHook.x = player.x + hypotenuse * cos(item.rotation);
	playerHook.y = player.y - hypotenuse * sin(item.rotation);

}



