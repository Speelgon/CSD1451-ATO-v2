#pragma once
#include "allheaders.hpp"
#include "objects.hpp"


void objectinit(squareObject* object) {

	for (int i = 0; i < maxObj; i++)
	{
		object[i].x = 2000;
		object[i].y = -2000;
		object[i].width = 10;
		object[i].height = 10;
		object[i].halfW = object[i].width / 2;
		object[i].halfH = object[i].height / 2;
		object[i].lefttoken = 0;
		object[i].righttoken = 0;
	}

}

void objectlevel1init(squareObject* object){

	object[0].x = 100;
	object[0].y = -100;
	object[0].width = 1000;
	object[0].height = 60;
	object[0].halfW = object[0].width / 2;
	object[0].halfH = object[0].height / 2;

	object[1].x = 400;
	object[1].y = 150;
	object[1].width = 200;
	object[1].height = 30;
	object[1].halfW = object[1].width / 2;
	object[1].halfH = object[1].height / 2;

	object[2].x = 100;
	object[2].y = 100;
	object[2].width = 400;
	object[2].height = 30;
	object[2].halfW = object[2].width / 2;
	object[2].halfH = object[2].height / 2;

	object[3].x = -300;
	object[3].y = 100;
	object[3].width = 100;
	object[3].height = 30;
	object[3].halfW = object[3].width / 2;
	object[3].halfH = object[3].height / 2;

}

void textureinit(AEGfxTexture** pTex)
{
	for (int i = 0; i < maxObj; i++)
	{
		pTex = 0;
	}
}
