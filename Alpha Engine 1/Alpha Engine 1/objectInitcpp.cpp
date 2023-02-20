#pragma once
#include "allheaders.hpp"
#include "objects.hpp"

/*================================================================================================================================

							INTSRUCTIONS FOR PRINTING SHAPES ON THE SCREEN
							1. DECLARE & INITIALIZE OBJECT (OBJECTS ALREADY DECLARED IN
							   objectDecs.hpp AND INITIALIZED IN objectinit()

							2. SET OBJECT VARIABLES IN objectlevel1init()
							   THIS MAY NOT BE objectlevel1init() IN THE FUTURE AS EACH
							   LEVEL NEEDS ITS OWN OBJECT LOCATIONS
							3. INITIALIZE MESHES (ALREADY INITIALIZED IN meshinit()
							4. SET THE OBJECTS TO THEIR RESPECTIVE MESHES IN meshinitlevel1()
							5. SET THE OBJECT TO RENDER IN objectrender()

================================================================================================================================
*/

void objectinit(squareObject* object) {

	for (int i = 0; i < maxObj; i++)
	{
		object[i].x = 20000;
		object[i].y = -2000;
		object[i].width = 10;
		object[i].height = 10;
		object[i].halfW = object[i].width / 2;
		object[i].halfH = object[i].height / 2;
		object[i].lefttoken = 0;
		object[i].righttoken = 0;
	}
}


void collectibleinit(collectibleObject* collectible)
{
	for (int i = 0; i < maxCollectible; i++)
	{
		collectible[i].x = 20000;
		collectible[i].y = -2000;
		collectible[i].width = 10;
		collectible[i].height = 10;
		collectible[i].halfW = collectible[i].width / 2;
		collectible[i].halfH = collectible[i].height / 2;
		collectible[i].visibility = 1;
	}
}

void objectlevel1init(squareObject* object){

	object[0].x = -1000;
	object[0].y = -275;
	object[0].width = 700;
	object[0].height = 30;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;

	object[1].x = -850;
	object[1].y = -200;
	object[1].width = 200;
	object[1].height = 30;
	object[1].halfW = object[1].width / 2;
	object[1].halfH = object[1].height / 2;

	object[2].x = -650;
	object[2].y = -125;
	object[2].width = 200;
	object[2].height = 30;
	object[2].halfW = object[2].width / 2;
	object[2].halfH = object[2].height / 2;

	object[3].x = -450;
	object[3].y = -75;
	object[3].width = 100;
	object[3].height = 30;
	object[3].halfW = object[3].width / 2;
	object[3].halfH = object[3].height / 2;

}

void collectiblelevel1init(collectibleObject* object) {

	object[0].x = -450;
	object[0].y = 0;
	object[0].width = 30;
	object[0].height = 30;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;
	object[0].visibility = 1;
}

void portalinit(portalObject* portal) {

	for (int i = 0; i < maxPortal; i++)
	{
		portal[i].x = 20000;
		portal[i].y = -2000;
		portal[i].width = 10;
		portal[i].height = 10;
		portal[i].halfW = portal[i].width / 2;
		portal[i].halfH = portal[i].height / 2;
	}
}

void portallevel1init(portalObject* object) {

	object[0].x = -850;
	object[0].y = -145;
	object[0].width = 60;
	object[0].height = 80;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;
	object[0].positiontoken = 1;

	object[1].x = -1300;
	object[1].y = -220;
	object[1].width = 60;
	object[1].height = 80;
	object[1].halfW = object[1].width / 2;
	object[1].halfH = object[1].height / 2;
	object[1].positiontoken = 1;
}

void textureinit(AEGfxTexture** pTex)
{
	for (int i = 0; i < maxObj; i++)
	{
		pTex = 0;
	}
}

void hookinit(hook &playerHook)
{
	playerHook.x = 0;
	playerHook.y = 0;
	playerHook.width = 30;
	playerHook.height = 30;
	playerHook.halfW = playerHook.width/2;
	playerHook.halfH = playerHook.height/2;
	playerHook.active = 0;
}

void blackholeinit(blackhole1* object) {

	for (int i = 0; i < maxBlackhole; i++)
	{
		object[i].x = 20000;
		object[i].y = -2000;
		object[i].width = 10;
		object[i].height = 10;
		object[i].halfW = object[i].width / 2;
		object[i].halfH = object[i].height / 2;
		object[i].gravPull = 0;
		object[i].pullRadius = 0;
	}
}


void blackholelevel1init(blackhole1* object) {

		object[0].x = -1250;
		object[0].y = 0;
		object[0].width = 30;
		object[0].height = 30;
		object[0].halfW = object[0].width / 2;
		object[0].halfH = object[0].height / 2;
		object[0].gravPull = 0;
		object[0].pullRadius = 0;

}
void nodeInit(nodeObject* nodes) {
	//node 1
	nodes[0].x = { -950 };
	nodes[0].y = { -35 };
	nodes[0].width = 25;
	nodes[0].height = 25;
	nodes[0].halfW = nodes[0].width / 2;
	nodes[0].halfH = nodes[0].height / 2;
	
	//node 2
	nodes[1].x = { -1120 };
	nodes[1].y = { -15 };
	nodes[1].width = 25;
	nodes[1].height = 25;
	nodes[1].halfW = nodes[0].width / 2;
	nodes[1].halfH = nodes[0].height / 2;
}