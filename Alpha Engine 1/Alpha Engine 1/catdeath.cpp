#include "allheaders.hpp"
#include "objects.hpp"

extern f64 delta;


void catdeath() {
	if ((timeDead += delta) < deathSeconds)
	{
		player.yvel += 0.3;
		player.y += player.yvel;
	}
	else 
	{
		player.yvel -= 2*gravity;
		player.y += player.yvel;
	}
}
