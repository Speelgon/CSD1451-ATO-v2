#include "allheaders.hpp"
#include "objects.hpp"

extern f64 delta;
extern f64 assumedFrameRate;

void catdeath() {
	if ((timeDead += delta) < deathSeconds)
	{
		player.yvel += 0.3;
		player.y += player.yvel * delta * assumedFrameRate;
	}
	else 
	{
		player.yvel -= 2*gravity;
		player.y += player.yvel * delta * assumedFrameRate;
	}
}
