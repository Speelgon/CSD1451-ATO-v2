
#include "allheaders.hpp"


//Timer
int normalUpdateTimer(f64* normalElapsedTime, int timer, f64 interval)
{
	*normalElapsedTime += AEFrameRateControllerGetFrameTime();
	if (*normalElapsedTime >= interval)
	{
		timer--;
		*normalElapsedTime = 0;
	}
	return timer;
}
//put below code in your update
//if (timer > 0)
//{
//	timer = normalUpdateTimer(&normalElapsedTime, timer, interval);
//}

//put below code in your draw to print to std::cout
//if (timer != lasttimer)
//{
//	std::cout << timer << '\n';
//	lasttimer = timer;

//}


//int IsAreaClicked(float area_middleX, float area_middleY, float half_width, float half_height, int click_x, int click_y)
//{
//	/*this function detects if the mouse is clicked within a rectangle at the main menu */
//	// area_middleX and area_middleY: coordinates of the centre of the rectangle (x, y)
//	// area_width and area_height: the width of the rectangle, the height of the rectangle
//	// click_x and click_y: the mouse coordinates (x, y)
//	//float halfw = area_width / 2;
//	//float halfh = area_height / 2;
//	/*int mousepositionx, mousepositiony;
//	mousepositionx = *click_x;
//	mousepositiony = *click_y;*/
//
//
//
//	float max_x = area_middleX + half_width;
//	float max_y = area_middleY + half_height;
//	float min_x = area_middleX - half_width;
//	float min_y = area_middleY - half_height;
//
//
//	if (AEInputCheckCurr(AEVK_LBUTTON))
//	{
//		std::cout << "The L mouse works   " << click_x << '\n';
//		if ((click_x > min_x) && (click_x < max_x) && (click_y > min_y) && (click_y < max_y))
//		{
//
//			std::cout << "detected in area" << '\n';
//			return 1;
//		}
//	}
//
//
//	return 0;
//}