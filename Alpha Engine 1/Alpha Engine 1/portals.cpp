#pragma once
#include "allheaders.hpp"
#include "portals.hpp"

void portalsinit(squareObject* portals) {

	portals[0].x = 50;
	portals[0].y = 0;
	portals[0].width = 60;
	portals[0].height = 60;
	portals[0].halfW = portals[0].width / 2;
	portals[0].halfH = portals[0].height / 2;
}