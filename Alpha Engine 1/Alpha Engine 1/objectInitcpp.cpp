//==========================================================
// file		: objectInIt.cpp
// 
// author   : Kathleen Lim
// co-author: Ng Wen Wen
// co-author: Owen Quek
// 
// email	: l.kathleenxiangxuan@digipen.edu
//			  wenwen.ng@digipen.edu
//			  o.quek@digipen.edu
//
// brief	: objectInit.cpp initializes the objects for each gamestate
//
// Copyright © 2023 DigiPen, All rights reserved.
//==========================================================

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


void objectinit(squareObject* object1) {

	for (int i = 1; i < maxObj; i++)
	{
		object1[i].x = 20000;
		object1[i].y = -2000;
		object1[i].width = 10;
		object1[i].height = 10;
		object1[i].halfW = object1[i].width / 2;
		object1[i].halfH = object1[i].height / 2;
		object1[i].lefttoken = 0;
		object1[i].righttoken = 0;
	}
}


void collectibleinit(collectibleObject* collectiblePtr)
{
	for (int i = 0; i < maxCollectible; i++)
	{
		collectiblePtr[i].x = 20000;
		collectiblePtr[i].y = -2000;
		collectiblePtr[i].width = 10;
		collectiblePtr[i].height = 10;
		collectiblePtr[i].halfW = collectiblePtr[i].width / 2;
		collectiblePtr[i].halfH = collectiblePtr[i].height / 2;
		collectiblePtr[i].visibility = 1;
	}
}

void objectlevel1init(squareObject* objectPtr) {

	objectPtr[0].x = -1000;
	objectPtr[0].y = -275;
	objectPtr[0].width = 700;
	objectPtr[0].height = 30;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;

	objectPtr[1].x = -850;
	objectPtr[1].y = -200;
	objectPtr[1].width = 200;
	objectPtr[1].height = 30;
	objectPtr[1].halfW = objectPtr[1].width / 2;
	objectPtr[1].halfH = objectPtr[1].height / 2;

	objectPtr[2].x = -650;
	objectPtr[2].y = -125;
	objectPtr[2].width = 200;
	objectPtr[2].height = 30;
	objectPtr[2].halfW = objectPtr[2].width / 2;
	objectPtr[2].halfH = objectPtr[2].height / 2;

	objectPtr[3].x = -450;
	objectPtr[3].y = -75;
	objectPtr[3].width = 100;
	objectPtr[3].height = 30;
	objectPtr[3].halfW = objectPtr[3].width / 2;
	objectPtr[3].halfH = objectPtr[3].height / 2;

}

void objectlevel2init(squareObject* objectPtr) {

	objectPtr[0].x = -1000;
	objectPtr[0].y = -275;
	objectPtr[0].width = 300;
	objectPtr[0].height = 30;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;

	/*objectPtr[1].x = -1300;
	objectPtr[1].y = -275;
	objectPtr[1].width = 200;
	objectPtr[1].height = 30;
	objectPtr[1].halfW = objectPtr[1].width / 2;
	objectPtr[1].halfH = objectPtr[1].height / 2;*/

	/*objectPtr[2].x = -850;
	objectPtr[2].y = 100;
	objectPtr[2].width = 200;
	objectPtr[2].height = 30;
	objectPtr[2].halfW = objectPtr[2].width / 2;
	objectPtr[2].halfH = objectPtr[2].height / 2;*/

	objectPtr[3].x = -600;
	objectPtr[3].y = 300;
	objectPtr[3].width = 100;
	objectPtr[3].height = 30;
	objectPtr[3].halfW = objectPtr[3].width / 2;
	objectPtr[3].halfH = objectPtr[3].height / 2;

}

void objectlevel3init(squareObject* objectPtr) {

	objectPtr[0].x = -1000;
	objectPtr[0].y = -275;
	objectPtr[0].width = 300;
	objectPtr[0].height = 30;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;

	objectPtr[1].x = -1300;
	objectPtr[1].y = -300;
	objectPtr[1].width = 300;
	objectPtr[1].height = 30;
	objectPtr[1].halfW = objectPtr[1].width / 2;
	objectPtr[1].halfH = objectPtr[1].height / 2;

	objectPtr[2].x = -850;
	objectPtr[2].y = 100;
	objectPtr[2].width = 200;
	objectPtr[2].height = 30;
	objectPtr[2].halfW = objectPtr[2].width / 2;
	objectPtr[2].halfH = objectPtr[2].height / 2;

	objectPtr[3].x = -600;
	objectPtr[3].y = 300;
	objectPtr[3].width = 100;
	objectPtr[3].height = 30;
	objectPtr[3].halfW = objectPtr[3].width / 2;
	objectPtr[3].halfH = objectPtr[3].height / 2;

}

void objectlevel4init(squareObject* objectPtr) {

	objectPtr[0].x = -900;
	objectPtr[0].y = -275;
	objectPtr[0].width = 300;
	objectPtr[0].height = 30;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;

	/*objectPtr[1].x = -1300;
	objectPtr[1].y = -275;
	objectPtr[1].width = 200;
	objectPtr[1].height = 30;
	objectPtr[1].halfW = objectPtr[1].width / 2;
	objectPtr[1].halfH = objectPtr[1].height / 2;*/

	objectPtr[2].x = -600;
	objectPtr[2].y = -100;
	objectPtr[2].width = 200;
	objectPtr[2].height = 30;
	objectPtr[2].halfW = objectPtr[2].width / 2;
	objectPtr[2].halfH = objectPtr[2].height / 2;

	objectPtr[3].x = -400;
	objectPtr[3].y = 100;
	objectPtr[3].width = 100;
	objectPtr[3].height = 30;
	objectPtr[3].halfW = objectPtr[3].width / 2;
	objectPtr[3].halfH = objectPtr[3].height / 2;

}

void objectlevel5init(squareObject* objectPtr) {

	objectPtr[0].x = -1000; //starting block
	objectPtr[0].y = -275;
	objectPtr[0].width = 300;
	objectPtr[0].height = 30;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;

	objectPtr[1].x = -1500; 
	objectPtr[1].y = 100;
	objectPtr[1].width = 200;
	objectPtr[1].height = 30;
	objectPtr[1].halfW = objectPtr[1].width / 2;
	objectPtr[1].halfH = objectPtr[1].height / 2;

	objectPtr[2].x = -600;
	objectPtr[2].y = 820;
	objectPtr[2].width = 170;
	objectPtr[2].height = 30;
	objectPtr[2].halfW = objectPtr[2].width / 2;
	objectPtr[2].halfH = objectPtr[2].height / 2;

	objectPtr[3].x = -400;
	objectPtr[3].y = 300;
	objectPtr[3].width = 100;
	objectPtr[3].height = 30;
	objectPtr[3].halfW = objectPtr[3].width / 2;
	objectPtr[3].halfH = objectPtr[3].height / 2;

}

void objectlevel6init(squareObject* objectPtr) {

	objectPtr[0].x = -1000; //starting block
	objectPtr[0].y = -275;
	objectPtr[0].width = 200;
	objectPtr[0].height = 30;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;

	objectPtr[1].x = -700;
	objectPtr[1].y = 0;
	objectPtr[1].width = 200;
	objectPtr[1].height = 30;
	objectPtr[1].halfW = objectPtr[1].width / 2;
	objectPtr[1].halfH = objectPtr[1].height / 2;

}

void objectlevel7init(squareObject* objectPtr) {

	objectPtr[0].x = -1000; //starting block
	objectPtr[0].y = -275;
	objectPtr[0].width = 200;
	objectPtr[0].height = 30;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;



	objectPtr[1].x = -1000;
	objectPtr[1].y = -450;
	objectPtr[1].width = 200;
	objectPtr[1].height = 30;
	objectPtr[1].halfW = objectPtr[1].width / 2;
	objectPtr[1].halfH = objectPtr[1].height / 2;

}

void objectlevel1NEWinit(squareObject* objectPtr){

	objectPtr[0].x = -1100;
	objectPtr[0].y = -275;
	objectPtr[0].width = 300;
	objectPtr[0].height = 30;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;

	objectPtr[1].x = -850;
	objectPtr[1].y = -200;
	objectPtr[1].width = 200;
	objectPtr[1].height = 30;
	objectPtr[1].halfW = objectPtr[1].width / 2;
	objectPtr[1].halfH = objectPtr[1].height / 2;

	objectPtr[2].x = -650;
	objectPtr[2].y = -125;
	objectPtr[2].width = 200;
	objectPtr[2].height = 30;
	objectPtr[2].halfW = objectPtr[2].width / 2;
	objectPtr[2].halfH = objectPtr[2].height / 2;

	objectPtr[3].x = -450;
	objectPtr[3].y = -75;
	objectPtr[3].width = 100;
	objectPtr[3].height = 30;
	objectPtr[3].halfW = objectPtr[3].width / 2;
	objectPtr[3].halfH = objectPtr[3].height / 2;

}

void collectiblelevel1init(collectibleObject* objectPtr) {

	objectPtr[0].x = -450;
	objectPtr[0].y = 0;
	objectPtr[0].width = 30;
	objectPtr[0].height = 30;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;
	objectPtr[0].visibility = 1;
}

void collectiblelevel1NEWinit(collectibleObject* objectPtr) {

	objectPtr[0].x = -1100;
	objectPtr[0].y = 0;
	objectPtr[0].width = 30;
	objectPtr[0].height = 30;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;
	objectPtr[0].visibility = 1;

	objectPtr[1].x = - 850;
	objectPtr[1].y = -150;
	objectPtr[1].width = 30;
	objectPtr[1].height = 30;
	objectPtr[1].halfW = objectPtr[1].width / 2;
	objectPtr[1].halfH = objectPtr[1].height / 2;
	objectPtr[1].visibility = 1;

	objectPtr[2].x = -650;
	objectPtr[2].y = -100;
	objectPtr[2].width = 30;
	objectPtr[2].height = 30;
	objectPtr[2].halfW = objectPtr[2].width / 2;
	objectPtr[2].halfH = objectPtr[2].height / 2;
	objectPtr[2].visibility = 1;
}

void collectiblelevel2init(collectibleObject* objectPtr) {

	objectPtr[0].x = -1100;
	objectPtr[0].y = 0;
	objectPtr[0].width = 30;
	objectPtr[0].height = 30;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;
	objectPtr[0].visibility = 1;

	objectPtr[1].x = -800;
	objectPtr[1].y = 300;
	objectPtr[1].width = 30;
	objectPtr[1].height = 30;
	objectPtr[1].halfW = objectPtr[1].width / 2;
	objectPtr[1].halfH = objectPtr[1].height / 2;
	objectPtr[1].visibility = 1;

	objectPtr[2].x = -950;
	objectPtr[2].y = 100;
	objectPtr[2].width = 30;
	objectPtr[2].height = 30;
	objectPtr[2].halfW = objectPtr[2].width / 2;
	objectPtr[2].halfH = objectPtr[2].height / 2;
	objectPtr[2].visibility = 1;
}

void collectiblelevel3init(collectibleObject* objectPtr) {

	objectPtr[0].x = -1050;
	objectPtr[0].y = 0;
	objectPtr[0].width = 30;
	objectPtr[0].height = 30;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;
	objectPtr[0].visibility = 1;

	objectPtr[1].x = -800;
	objectPtr[1].y = 300;
	objectPtr[1].width = 30;
	objectPtr[1].height = 30;
	objectPtr[1].halfW = objectPtr[1].width / 2;
	objectPtr[1].halfH = objectPtr[1].height / 2;
	objectPtr[1].visibility = 1;

	objectPtr[2].x = -1140;
	objectPtr[2].y = 250;
	objectPtr[2].width = 30;
	objectPtr[2].height = 30;
	objectPtr[2].halfW = objectPtr[2].width / 2;
	objectPtr[2].halfH = objectPtr[2].height / 2;
	objectPtr[2].visibility = 1;
}

void collectiblelevel4init(collectibleObject* objectPtr) {

	objectPtr[0].x = -400;
	objectPtr[0].y = 350;
	objectPtr[0].width = 30;
	objectPtr[0].height = 30;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;
	objectPtr[0].visibility = 1;

	objectPtr[1].x = -600;
	objectPtr[1].y = 0;
	objectPtr[1].width = 30;
	objectPtr[1].height = 30;
	objectPtr[1].halfW = objectPtr[1].width / 2;
	objectPtr[1].halfH = objectPtr[1].height / 2;
	objectPtr[1].visibility = 1;

	objectPtr[2].x = -800;
	objectPtr[2].y = 600;
	objectPtr[2].width = 30;
	objectPtr[2].height = 30;
	objectPtr[2].halfW = objectPtr[2].width / 2;
	objectPtr[2].halfH = objectPtr[2].height / 2;
	objectPtr[2].visibility = 1;
}

void collectiblelevel5init(collectibleObject* objectPtr) {

	objectPtr[0].x = -1740;
	objectPtr[0].y = -100;
	objectPtr[0].width = 30;
	objectPtr[0].height = 30;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;
	objectPtr[0].visibility = 1;

	objectPtr[1].x = -760;
	objectPtr[1].y = 370;
	objectPtr[1].width = 30;
	objectPtr[1].height = 30;
	objectPtr[1].halfW = objectPtr[1].width / 2;
	objectPtr[1].halfH = objectPtr[1].height / 2;
	objectPtr[1].visibility = 1;

	objectPtr[2].x = -1450;
	objectPtr[2].y = 200;
	objectPtr[2].width = 30;
	objectPtr[2].height = 30;
	objectPtr[2].halfW = objectPtr[2].width / 2;
	objectPtr[2].halfH = objectPtr[2].height / 2;
	objectPtr[2].visibility = 1;
}

void collectiblelevel6init(collectibleObject* objectPtr) {

	objectPtr[0].x = -1340;
	objectPtr[0].y = 100;
	objectPtr[0].width = 30;
	objectPtr[0].height = 30;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;
	objectPtr[0].visibility = 1;

	objectPtr[1].x = -1550;
	objectPtr[1].y = -50;
	objectPtr[1].width = 30;
	objectPtr[1].height = 30;
	objectPtr[1].halfW = objectPtr[1].width / 2;
	objectPtr[1].halfH = objectPtr[1].height / 2;
	objectPtr[1].visibility = 1;

	objectPtr[2].x = -1450;
	objectPtr[2].y = 200;
	objectPtr[2].width = 30;
	objectPtr[2].height = 30;
	objectPtr[2].halfW = objectPtr[2].width / 2;
	objectPtr[2].halfH = objectPtr[2].height / 2;
	objectPtr[2].visibility = 1;
}


void collectiblelevel7init(collectibleObject* objectPtr) {

	objectPtr[0].x = -300;
	objectPtr[0].y = 0;
	objectPtr[0].width = 30;
	objectPtr[0].height = 30;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;
	objectPtr[0].visibility = 1;

	objectPtr[1].x = -1050;
	objectPtr[1].y = -400;
	objectPtr[1].width = 30;
	objectPtr[1].height = 30;
	objectPtr[1].halfW = objectPtr[1].width / 2;
	objectPtr[1].halfH = objectPtr[1].height / 2;
	objectPtr[1].visibility = 1;

	objectPtr[2].x = -1450;
	objectPtr[2].y = 200;
	objectPtr[2].width = 30;
	objectPtr[2].height = 30;
	objectPtr[2].halfW = objectPtr[2].width / 2;
	objectPtr[2].halfH = objectPtr[2].height / 2;
	objectPtr[2].visibility = 1;
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

void portallevel1init(portalObject* objectPtr) {

	objectPtr[0].x = -850;
	objectPtr[0].y = -145;
	objectPtr[0].width = 60;
	objectPtr[0].height = 80;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;
	objectPtr[0].positiontoken = 1;

	objectPtr[1].x = -1300;
	objectPtr[1].y = -220;
	objectPtr[1].width = 60;
	objectPtr[1].height = 80;
	objectPtr[1].halfW = objectPtr[1].width / 2;
	objectPtr[1].halfH = objectPtr[1].height / 2;
	objectPtr[1].positiontoken = 1;
}

void portallevel3init(portalObject* objectPtr) {

	objectPtr[0].x = -1300;
	objectPtr[0].y = -400;
	objectPtr[0].width = 60;
	objectPtr[0].height = 80;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;
	objectPtr[0].positiontoken = 1;

	objectPtr[1].x = -850;
	objectPtr[1].y = 160;
	objectPtr[1].width = 60;
	objectPtr[1].height = 80;
	objectPtr[1].halfW = objectPtr[1].width / 2;
	objectPtr[1].halfH = objectPtr[1].height / 2;
	objectPtr[1].positiontoken = 1;
}

void portallevel5init(portalObject* objectPtr) {

	objectPtr[0].x = -1700;
	objectPtr[0].y = -200;
	objectPtr[0].width = 60;
	objectPtr[0].height = 80;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;
	objectPtr[0].positiontoken = 1;

	objectPtr[1].x = -600;
	objectPtr[1].y = 880;
	objectPtr[1].width = 60;
	objectPtr[1].height = 80;
	objectPtr[1].halfW = objectPtr[1].width / 2;
	objectPtr[1].halfH = objectPtr[1].height / 2;
	objectPtr[1].positiontoken = 1;
}


void portallevel6init(portalObject* objectPtr) {

	objectPtr[0].x = -1500;
	objectPtr[0].y = -200;
	objectPtr[0].width = 60;
	objectPtr[0].height = 80;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;
	objectPtr[0].positiontoken = 1;

	objectPtr[1].x = -600;
	objectPtr[1].y = 500;
	objectPtr[1].width = 60;
	objectPtr[1].height = 80;
	objectPtr[1].halfW = objectPtr[1].width / 2;
	objectPtr[1].halfH = objectPtr[1].height / 2;
	objectPtr[1].positiontoken = 1;
}

void portallevel7init(portalObject* objectPtr) {

	objectPtr[0].x = -450;
	objectPtr[0].y = -300;
	objectPtr[0].width = 60;
	objectPtr[0].height = 80;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;
	objectPtr[0].positiontoken = 1;

	objectPtr[1].x = -1600;
	objectPtr[1].y = 500;
	objectPtr[1].width = 60;
	objectPtr[1].height = 80;
	objectPtr[1].halfW = objectPtr[1].width / 2;
	objectPtr[1].halfH = objectPtr[1].height / 2;
	objectPtr[1].positiontoken = 1;
}


void textureinit(AEGfxTexture** pTexPtr)
{
	for (int i = 0; i < maxObj; i++)
	{
		pTexPtr = 0;
	}
}

void hookinit(hook &playerHookRef)
{
	playerHookRef.x = 0;
	playerHookRef.y = 0;
	playerHookRef.width = 30;
	playerHookRef.height = 30;
	playerHookRef.halfW = playerHookRef.width/2;
	playerHookRef.halfH = playerHookRef.height/2;
	playerHookRef.active = 0;
}

void blackholeinit(blackhole1* objectPtr) {

	for (int i = 0; i < maxBlackhole; i++)
	{
		objectPtr[i].x = 20000;
		objectPtr[i].y = -2000;
		objectPtr[i].width = 10;
		objectPtr[i].height = 10;
		objectPtr[i].halfW = objectPtr[i].width / 2;
		objectPtr[i].halfH = objectPtr[i].height / 2;
		objectPtr[i].gravPull = 0;
		objectPtr[i].pullRadius = 0;
	}
}

void blackholelevel1init(blackhole1* objectPtr) {

		objectPtr[0].x = -1050;
		objectPtr[0].y = -130;
		objectPtr[0].width = 50;
		objectPtr[0].height = 30;
		objectPtr[0].halfW = objectPtr[0].width / 2;
		objectPtr[0].halfH = objectPtr[0].height / 2;
		objectPtr[0].gravPull = 0;
		objectPtr[0].pullRadius = 0;

}

void blackholelevel6init(blackhole1* objectPtr) {

	objectPtr[0].x = -1450;
	objectPtr[0].y = 300;
	objectPtr[0].width = 50;
	objectPtr[0].height = 30;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;
	objectPtr[0].gravPull = 0;
	objectPtr[0].pullRadius = 0;

}

void blackholelevel7init(blackhole1* objectPtr) {

	objectPtr[0].x = -850;
	objectPtr[0].y = -350;
	objectPtr[0].width = 50;
	objectPtr[0].height = 30;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;
	objectPtr[0].gravPull = 0;
	objectPtr[0].pullRadius = 0;

	objectPtr[1].x = -555;
	objectPtr[1].y = -350;
	objectPtr[1].width = 50;
	objectPtr[1].height = 30;
	objectPtr[1].halfW = objectPtr[0].width / 2;
	objectPtr[1].halfH = objectPtr[0].height / 2;
	objectPtr[1].gravPull = 0;
	objectPtr[1].pullRadius = 0;



}

void trampolineinit(tramp* objectPtr) {
	for (int i = 0; i < maxTrampolines; i++)
	{
		objectPtr[i].x = 20000;
		objectPtr[i].y = -2000;
		objectPtr[i].width = 10;
		objectPtr[i].height = 10;
		objectPtr[i].halfW = objectPtr[i].width / 2;
		objectPtr[i].halfH = objectPtr[i].height / 2;
		objectPtr[i].lefttoken = 0;
		objectPtr[i].righttoken = 0;
	}
}

void trampolinelevel1init(tramp* objectPtr) {
	objectPtr[0].x = -1350;
	objectPtr[0].y = -275;
	objectPtr[0].width = 300;
	objectPtr[0].height = 10;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;
	objectPtr[0].lefttoken = 0;
	objectPtr[0].righttoken = 0;
}

void trampolinelevel4init(tramp* objectPtr) {
	objectPtr[0].x = -800;
	objectPtr[0].y = 100;
	objectPtr[0].width = 100;
	objectPtr[0].height = 20;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;
	objectPtr[0].lefttoken = 0;
	objectPtr[0].righttoken = 0;
}

void trampolinelevel5init(tramp* objectPtr) {
	objectPtr[0].x = -800;
	objectPtr[0].y = -80;
	objectPtr[0].width = 100;
	objectPtr[0].height = 20;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;
	objectPtr[0].lefttoken = 0;
	objectPtr[0].righttoken = 0;
}


void trampolinelevel7init(tramp* objectPtr) {
	objectPtr[0].x = -1400;
	objectPtr[0].y = -50;
	objectPtr[0].width = 100;
	objectPtr[0].height = 20;
	objectPtr[0].halfW = objectPtr[0].width / 2;
	objectPtr[0].halfH = objectPtr[0].height / 2;
	objectPtr[0].lefttoken = 0;
	objectPtr[0].righttoken = 0;
}

void nodeInit(nodeObject* nodesPtr) {
	//node 1
	for (int i = 0; i < maxNodes; i++) {
		////node 2
		nodesPtr[i].x = { -11200 };
		nodesPtr[i].y = { -15 };
		nodesPtr[i].width = 25;
		nodesPtr[i].height = 25;
		nodesPtr[i].halfW = nodesPtr[0].width / 2;
		nodesPtr[i].halfH = nodesPtr[0].height / 2;

	}
}

void nodeInitlevel2(nodeObject* nodesPtr) {
	

	//node 2
	nodesPtr[0].x = { -1050 };
	nodesPtr[0].y = { -15 };
	nodesPtr[0].width = 25;
	nodesPtr[0].height = 25;
	nodesPtr[0].halfW = nodesPtr[0].width / 2;
	nodesPtr[0].halfH = nodesPtr[0].height / 2;

	nodesPtr[1].x = { -850 };
	nodesPtr[1].y = { 240 };
	nodesPtr[1].width = 25;
	nodesPtr[1].height = 25;
	nodesPtr[1].halfW = nodesPtr[0].width / 2;
	nodesPtr[1].halfH = nodesPtr[0].height / 2;
}

void nodeInitlevel3(nodeObject* nodesPtr) {


	//node 2
	nodesPtr[0].x = { -1120 };
	nodesPtr[0].y = { -15 };
	nodesPtr[0].width = 25;
	nodesPtr[0].height = 25;
	nodesPtr[0].halfW = nodesPtr[0].width / 2;
	nodesPtr[0].halfH = nodesPtr[0].height / 2;

	nodesPtr[1].x = { -1100 };
	nodesPtr[1].y = { 250 };
	nodesPtr[1].width = 25;
	nodesPtr[1].height = 25;
	nodesPtr[1].halfW = nodesPtr[0].width / 2;
	nodesPtr[1].halfH = nodesPtr[0].height / 2;
}


void nodeInitlevel5(nodeObject* nodesPtr) {

	nodesPtr[0].x = { -1250 };
	nodesPtr[0].y = { -15 };
	nodesPtr[0].width = 25;
	nodesPtr[0].height = 25;
	nodesPtr[0].halfW = nodesPtr[0].width / 2;
	nodesPtr[0].halfH = nodesPtr[0].height / 2;

	nodesPtr[1].x = { -700 };
	nodesPtr[1].y = { 480 };
	nodesPtr[1].width = 25;
	nodesPtr[1].height = 25;
	nodesPtr[1].halfW = nodesPtr[0].width / 2;
	nodesPtr[1].halfH = nodesPtr[0].height / 2;
}

void nodeInitlevel6(nodeObject* nodesPtr) {

	nodesPtr[0].x = { -1250 };
	nodesPtr[0].y = { -15 };
	nodesPtr[0].width = 25;
	nodesPtr[0].height = 25;
	nodesPtr[0].halfW = nodesPtr[0].width / 2;
	nodesPtr[0].halfH = nodesPtr[0].height / 2;

}


void nodeInitlevel7(nodeObject* nodesPtr) {

	nodesPtr[0].x = { -650 };
	nodesPtr[0].y = { -350 };
	nodesPtr[0].width = 25;
	nodesPtr[0].height = 25;
	nodesPtr[0].halfW = nodesPtr[0].width / 2;
	nodesPtr[0].halfH = nodesPtr[0].height / 2;


	nodesPtr[1].x = { -450 };
	nodesPtr[1].y = { -125 };
	nodesPtr[1].width = 25;
	nodesPtr[1].height = 25;
	nodesPtr[1].halfW = nodesPtr[0].width / 2;
	nodesPtr[1].halfH = nodesPtr[0].height / 2;


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
