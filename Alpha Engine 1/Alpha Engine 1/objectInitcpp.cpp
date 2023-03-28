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

	for (int i = 1; i < maxObj; i++)
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

void objectlevel1init(squareObject* object) {

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

void objectlevel2init(squareObject* object) {

	object[0].x = -1000;
	object[0].y = -275;
	object[0].width = 300;
	object[0].height = 30;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;

	/*object[1].x = -1300;
	object[1].y = -275;
	object[1].width = 200;
	object[1].height = 30;
	object[1].halfW = object[1].width / 2;
	object[1].halfH = object[1].height / 2;*/

	/*object[2].x = -850;
	object[2].y = 100;
	object[2].width = 200;
	object[2].height = 30;
	object[2].halfW = object[2].width / 2;
	object[2].halfH = object[2].height / 2;*/

	object[3].x = -600;
	object[3].y = 300;
	object[3].width = 100;
	object[3].height = 30;
	object[3].halfW = object[3].width / 2;
	object[3].halfH = object[3].height / 2;

}

void objectlevel3init(squareObject* object) {

	object[0].x = -1000;
	object[0].y = -275;
	object[0].width = 300;
	object[0].height = 30;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;

	object[1].x = -1300;
	object[1].y = -300;
	object[1].width = 300;
	object[1].height = 30;
	object[1].halfW = object[1].width / 2;
	object[1].halfH = object[1].height / 2;

	object[2].x = -850;
	object[2].y = 100;
	object[2].width = 200;
	object[2].height = 30;
	object[2].halfW = object[2].width / 2;
	object[2].halfH = object[2].height / 2;

	object[3].x = -600;
	object[3].y = 300;
	object[3].width = 100;
	object[3].height = 30;
	object[3].halfW = object[3].width / 2;
	object[3].halfH = object[3].height / 2;

}

void objectlevel4init(squareObject* object) {

	object[0].x = -900;
	object[0].y = -275;
	object[0].width = 300;
	object[0].height = 30;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;

	/*object[1].x = -1300;
	object[1].y = -275;
	object[1].width = 200;
	object[1].height = 30;
	object[1].halfW = object[1].width / 2;
	object[1].halfH = object[1].height / 2;*/

	object[2].x = -600;
	object[2].y = -100;
	object[2].width = 200;
	object[2].height = 30;
	object[2].halfW = object[2].width / 2;
	object[2].halfH = object[2].height / 2;

	object[3].x = -400;
	object[3].y = 100;
	object[3].width = 100;
	object[3].height = 30;
	object[3].halfW = object[3].width / 2;
	object[3].halfH = object[3].height / 2;

}

void objectlevel5init(squareObject* object) {

	object[0].x = -1000; //starting block
	object[0].y = -275;
	object[0].width = 300;
	object[0].height = 30;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;

	object[1].x = -1500; 
	object[1].y = 100;
	object[1].width = 200;
	object[1].height = 30;
	object[1].halfW = object[1].width / 2;
	object[1].halfH = object[1].height / 2;

	object[2].x = -600;
	object[2].y = 820;
	object[2].width = 170;
	object[2].height = 30;
	object[2].halfW = object[2].width / 2;
	object[2].halfH = object[2].height / 2;

	object[3].x = -400;
	object[3].y = 300;
	object[3].width = 100;
	object[3].height = 30;
	object[3].halfW = object[3].width / 2;
	object[3].halfH = object[3].height / 2;

}

void objectlevel6init(squareObject* object) {

	object[0].x = -1000; //starting block
	object[0].y = -275;
	object[0].width = 200;
	object[0].height = 30;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;

	object[1].x = -700;
	object[1].y = 0;
	object[1].width = 200;
	object[1].height = 30;
	object[1].halfW = object[1].width / 2;
	object[1].halfH = object[1].height / 2;

}

void objectlevel7init(squareObject* object) {

	object[0].x = -1000; //starting block
	object[0].y = -275;
	object[0].width = 200;
	object[0].height = 30;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;



	object[1].x = -1000;
	object[1].y = -450;
	object[1].width = 200;
	object[1].height = 30;
	object[1].halfW = object[1].width / 2;
	object[1].halfH = object[1].height / 2;

}

void objectlevel1NEWinit(squareObject* object){

	object[0].x = -1100;
	object[0].y = -275;
	object[0].width = 300;
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

void collectiblelevel1NEWinit(collectibleObject* object) {

	object[0].x = -1100;
	object[0].y = 0;
	object[0].width = 30;
	object[0].height = 30;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;
	object[0].visibility = 1;

	object[1].x = - 850;
	object[1].y = -150;
	object[1].width = 30;
	object[1].height = 30;
	object[1].halfW = object[1].width / 2;
	object[1].halfH = object[1].height / 2;
	object[1].visibility = 1;

	object[2].x = -650;
	object[2].y = -100;
	object[2].width = 30;
	object[2].height = 30;
	object[2].halfW = object[2].width / 2;
	object[2].halfH = object[2].height / 2;
	object[2].visibility = 1;
}

void collectiblelevel2init(collectibleObject* object) {

	object[0].x = -1100;
	object[0].y = 0;
	object[0].width = 30;
	object[0].height = 30;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;
	object[0].visibility = 1;

	object[1].x = -800;
	object[1].y = 300;
	object[1].width = 30;
	object[1].height = 30;
	object[1].halfW = object[1].width / 2;
	object[1].halfH = object[1].height / 2;
	object[1].visibility = 1;

	object[2].x = -950;
	object[2].y = 100;
	object[2].width = 30;
	object[2].height = 30;
	object[2].halfW = object[2].width / 2;
	object[2].halfH = object[2].height / 2;
	object[2].visibility = 1;
}

void collectiblelevel3init(collectibleObject* object) {

	object[0].x = -1050;
	object[0].y = 0;
	object[0].width = 30;
	object[0].height = 30;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;
	object[0].visibility = 1;

	object[1].x = -800;
	object[1].y = 300;
	object[1].width = 30;
	object[1].height = 30;
	object[1].halfW = object[1].width / 2;
	object[1].halfH = object[1].height / 2;
	object[1].visibility = 1;

	object[2].x = -1140;
	object[2].y = 250;
	object[2].width = 30;
	object[2].height = 30;
	object[2].halfW = object[2].width / 2;
	object[2].halfH = object[2].height / 2;
	object[2].visibility = 1;
}

void collectiblelevel4init(collectibleObject* object) {

	object[0].x = -400;
	object[0].y = 350;
	object[0].width = 30;
	object[0].height = 30;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;
	object[0].visibility = 1;

	object[1].x = -600;
	object[1].y = 0;
	object[1].width = 30;
	object[1].height = 30;
	object[1].halfW = object[1].width / 2;
	object[1].halfH = object[1].height / 2;
	object[1].visibility = 1;

	object[2].x = -800;
	object[2].y = 600;
	object[2].width = 30;
	object[2].height = 30;
	object[2].halfW = object[2].width / 2;
	object[2].halfH = object[2].height / 2;
	object[2].visibility = 1;
}

void collectiblelevel5init(collectibleObject* object) {

	object[0].x = -1740;
	object[0].y = -100;
	object[0].width = 30;
	object[0].height = 30;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;
	object[0].visibility = 1;

	object[1].x = -760;
	object[1].y = 370;
	object[1].width = 30;
	object[1].height = 30;
	object[1].halfW = object[1].width / 2;
	object[1].halfH = object[1].height / 2;
	object[1].visibility = 1;

	object[2].x = -1450;
	object[2].y = 200;
	object[2].width = 30;
	object[2].height = 30;
	object[2].halfW = object[2].width / 2;
	object[2].halfH = object[2].height / 2;
	object[2].visibility = 1;
}

void collectiblelevel6init(collectibleObject* object) {

	object[0].x = -1340;
	object[0].y = 100;
	object[0].width = 30;
	object[0].height = 30;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;
	object[0].visibility = 1;

	object[1].x = -1550;
	object[1].y = -50;
	object[1].width = 30;
	object[1].height = 30;
	object[1].halfW = object[1].width / 2;
	object[1].halfH = object[1].height / 2;
	object[1].visibility = 1;

	object[2].x = -1450;
	object[2].y = 200;
	object[2].width = 30;
	object[2].height = 30;
	object[2].halfW = object[2].width / 2;
	object[2].halfH = object[2].height / 2;
	object[2].visibility = 1;
}


void collectiblelevel7init(collectibleObject* object) {

	object[0].x = -300;
	object[0].y = 0;
	object[0].width = 30;
	object[0].height = 30;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;
	object[0].visibility = 1;

	object[1].x = -1050;
	object[1].y = -400;
	object[1].width = 30;
	object[1].height = 30;
	object[1].halfW = object[1].width / 2;
	object[1].halfH = object[1].height / 2;
	object[1].visibility = 1;

	object[2].x = -1450;
	object[2].y = 200;
	object[2].width = 30;
	object[2].height = 30;
	object[2].halfW = object[2].width / 2;
	object[2].halfH = object[2].height / 2;
	object[2].visibility = 1;
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

void portallevel3init(portalObject* object) {

	object[0].x = -1300;
	object[0].y = -400;
	object[0].width = 60;
	object[0].height = 80;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;
	object[0].positiontoken = 1;

	object[1].x = -850;
	object[1].y = 160;
	object[1].width = 60;
	object[1].height = 80;
	object[1].halfW = object[1].width / 2;
	object[1].halfH = object[1].height / 2;
	object[1].positiontoken = 1;
}

void portallevel5init(portalObject* object) {

	object[0].x = -1700;
	object[0].y = -200;
	object[0].width = 60;
	object[0].height = 80;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;
	object[0].positiontoken = 1;

	object[1].x = -600;
	object[1].y = 880;
	object[1].width = 60;
	object[1].height = 80;
	object[1].halfW = object[1].width / 2;
	object[1].halfH = object[1].height / 2;
	object[1].positiontoken = 1;
}


void portallevel6init(portalObject* object) {

	object[0].x = -1500;
	object[0].y = -200;
	object[0].width = 60;
	object[0].height = 80;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;
	object[0].positiontoken = 1;

	object[1].x = -600;
	object[1].y = 500;
	object[1].width = 60;
	object[1].height = 80;
	object[1].halfW = object[1].width / 2;
	object[1].halfH = object[1].height / 2;
	object[1].positiontoken = 1;
}

void portallevel7init(portalObject* object) {

	object[0].x = -450;
	object[0].y = -300;
	object[0].width = 60;
	object[0].height = 80;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;
	object[0].positiontoken = 1;

	object[1].x = -1600;
	object[1].y = 500;
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

		object[0].x = -1050;
		object[0].y = -130;
		object[0].width = 50;
		object[0].height = 30;
		object[0].halfW = object[0].width / 2;
		object[0].halfH = object[0].height / 2;
		object[0].gravPull = 0;
		object[0].pullRadius = 0;

}

void trampolineinit(tramp* object) {
	for (int i = 0; i < maxTrampolines; i++)
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

void trampolinelevel1init(tramp* object) {
	object[0].x = -1350;
	object[0].y = -275;
	object[0].width = 300;
	object[0].height = 10;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;
	object[0].lefttoken = 0;
	object[0].righttoken = 0;
}

void trampolinelevel4init(tramp* object) {
	object[0].x = -800;
	object[0].y = 100;
	object[0].width = 100;
	object[0].height = 20;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;
	object[0].lefttoken = 0;
	object[0].righttoken = 0;
}

void trampolinelevel5init(tramp* object) {
	object[0].x = -800;
	object[0].y = -80;
	object[0].width = 100;
	object[0].height = 20;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;
	object[0].lefttoken = 0;
	object[0].righttoken = 0;
}


void trampolinelevel7init(tramp* object) {
	object[0].x = -1400;
	object[0].y = -50;
	object[0].width = 100;
	object[0].height = 20;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;
	object[0].lefttoken = 0;
	object[0].righttoken = 0;
}

void nodeInit(nodeObject* nodes) {
	//node 1
	for (int i = 0; i < maxNodes; i++) {
		////node 2
		nodes[i].x = { -11200 };
		nodes[i].y = { -15 };
		nodes[i].width = 25;
		nodes[i].height = 25;
		nodes[i].halfW = nodes[0].width / 2;
		nodes[i].halfH = nodes[0].height / 2;

	}
}

void nodeInitlevel2(nodeObject* nodes) {
	

	//node 2
	nodes[0].x = { -1050 };
	nodes[0].y = { -15 };
	nodes[0].width = 25;
	nodes[0].height = 25;
	nodes[0].halfW = nodes[0].width / 2;
	nodes[0].halfH = nodes[0].height / 2;

	nodes[1].x = { -850 };
	nodes[1].y = { 240 };
	nodes[1].width = 25;
	nodes[1].height = 25;
	nodes[1].halfW = nodes[0].width / 2;
	nodes[1].halfH = nodes[0].height / 2;
}

void nodeInitlevel3(nodeObject* nodes) {


	//node 2
	nodes[0].x = { -1120 };
	nodes[0].y = { -15 };
	nodes[0].width = 25;
	nodes[0].height = 25;
	nodes[0].halfW = nodes[0].width / 2;
	nodes[0].halfH = nodes[0].height / 2;

	nodes[1].x = { -1100 };
	nodes[1].y = { 250 };
	nodes[1].width = 25;
	nodes[1].height = 25;
	nodes[1].halfW = nodes[0].width / 2;
	nodes[1].halfH = nodes[0].height / 2;
}


void nodeInitlevel5(nodeObject* nodes) {

	nodes[0].x = { -1250 };
	nodes[0].y = { -15 };
	nodes[0].width = 25;
	nodes[0].height = 25;
	nodes[0].halfW = nodes[0].width / 2;
	nodes[0].halfH = nodes[0].height / 2;

	nodes[1].x = { -700 };
	nodes[1].y = { 480 };
	nodes[1].width = 25;
	nodes[1].height = 25;
	nodes[1].halfW = nodes[0].width / 2;
	nodes[1].halfH = nodes[0].height / 2;
}

void nodeInitlevel6(nodeObject* nodes) {

	nodes[0].x = { -1250 };
	nodes[0].y = { -15 };
	nodes[0].width = 25;
	nodes[0].height = 25;
	nodes[0].halfW = nodes[0].width / 2;
	nodes[0].halfH = nodes[0].height / 2;

}


void nodeInitlevel7(nodeObject* nodes) {

	nodes[0].x = { -650 };
	nodes[0].y = { -350 };
	nodes[0].width = 25;
	nodes[0].height = 25;
	nodes[0].halfW = nodes[0].width / 2;
	nodes[0].halfH = nodes[0].height / 2;


	nodes[1].x = { -450 };
	nodes[1].y = { -125 };
	nodes[1].width = 25;
	nodes[1].height = 25;
	nodes[1].halfW = nodes[0].width / 2;
	nodes[1].halfH = nodes[0].height / 2;


}

void exitdoorinit(exitDoor* door) {

	for (int i = 0; i < maxDoor; i++)
	{
		door[i].x = 2000;
		door[i].y = -2000;
		door[i].width = 10;
		door[i].height = 10;
		door[i].halfW = door[i].width / 2;
		door[i].halfH = door[i].height / 2;
	}
}

void exitdoorlevel1init(exitDoor* door) {

	door[0].x = -1150;
	door[0].y = -220;
	door[0].width = 50;
	door[0].height = 80;
	door[0].halfW = door[0].width / 2;
	door[0].halfH = door[0].height / 2;

}

void exitdoorlevel1NEWinit(exitDoor* door) {

	door[0].x = -450;
	door[0].y = -10;
	door[0].width = 40;
	door[0].height = 80;
	door[0].halfW = door[0].width / 2;
	door[0].halfH = door[0].height / 2;

}

void exitdoorlevel2init(exitDoor* door) {

	door[0].x = -600;
	door[0].y = 360;
	door[0].width = 40;
	door[0].height = 80;
	door[0].halfW = door[0].width / 2;
	door[0].halfH = door[0].height / 2;

}

void exitdoorlevel3init(exitDoor* door) {

	door[0].x = -600;
	door[0].y = 360;
	door[0].width = 40;
	door[0].height = 80;
	door[0].halfW = door[0].width / 2;
	door[0].halfH = door[0].height / 2;

}

void exitdoorlevel4init(exitDoor* door) {

	door[0].x = -600;
	door[0].y = 600;
	door[0].width = 40;
	door[0].height = 80;
	door[0].halfW = door[0].width / 2;
	door[0].halfH = door[0].height / 2;

}

void exitdoorlevel5init(exitDoor* door) {

	door[0].x = -400;
	door[0].y = 360;
	door[0].width = 40;
	door[0].height = 80;
	door[0].halfW = door[0].width / 2;
	door[0].halfH = door[0].height / 2;

}

void exitdoorlevel6init(exitDoor* door) {

	door[0].x = -700;
	door[0].y = 54;
	door[0].width = 40;
	door[0].height = 80;
	door[0].halfW = door[0].width / 2;
	door[0].halfH = door[0].height / 2;

}


void exitdoorlevel7init(exitDoor* door) {

	door[0].x = -1000;
	door[0].y = -400;
	door[0].width = 40;
	door[0].height = 80;
	door[0].halfW = door[0].width / 2;
	door[0].halfH = door[0].height / 2;

}
