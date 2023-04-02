#include "invertGravity.hpp"

extern float gravity;
extern float jumpspeed;

void invertGravity() {

	if (gravity >= 0.14)
		gravity = -gravity / 2;

	else gravity = 0.15f;

	jumpspeed = -jumpspeed;
	
}




