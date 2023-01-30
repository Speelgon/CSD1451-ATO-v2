#pragma once
#include "allheaders.hpp"
#include "objects.hpp"

void uiinit(squareObject* ui)
{
	for (int i = 0; i < maxUI; i++)
	{
		ui[i].x = 2000;
		ui[i].y = -2000;
		ui[i].width = 0;
		ui[i].height = 0;
		ui[i].halfW = ui[i].width / 2;
		ui[i].halfH = ui[i].height / 2;
		ui[i].lefttoken = 0;
		ui[i].righttoken = 0;
	}
}

void uilevel1init(squareObject* ui)
{
	ui[0].x = 20000;
	ui[0].y = 200;
	ui[0].width = 200;
	ui[0].height = 50;
	ui[0].halfW = ui[0].width / 2;
	ui[0].halfH = ui[0].height / 2;
	ui[0].lefttoken = 0;
	ui[0].righttoken = 0;
}