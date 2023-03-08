#include "allheaders.hpp"
#include "objects.hpp"

extern f64 delta;
extern f64 assumedFrameRate;

void catdeath() {
	if ((timeDead += (float)delta) < deathSeconds)
	{
		player.yvel += (float)0.3;
		player.y += (f32)(player.yvel * delta * assumedFrameRate);
	}
	else 
	{
		player.yvel -= 2*gravity;
		player.y += (f32)(player.yvel * delta * assumedFrameRate);
	}
}
