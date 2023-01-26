#pragma once
#include "allheaders.hpp"
#include "collectibles.hpp"
#include "collision.hpp"
#include "objects.hpp"







void collectiblesinit(squareObject* collectibles) {

	collectibles[0].x = 50;
	collectibles[0].y = 0;
	collectibles[0].width = 60;
	collectibles[0].height = 60;
	collectibles[0].halfW = collectibles[0].width / 2;
	collectibles[0].halfH = collectibles[0].height / 2;


}