#pragma once
#include "allheaders.hpp"
#include "movement.hpp"
#include "objects.hpp"
#include "collision.hpp"
#include "IncrementVariable.hpp"
#include "vpCollision.hpp"
int normalUpdateTimer(f64* normalElapsedTime, int timer, f64 interval);
int IsAreaClicked(float area_middleX, float area_middleY, float half_width, float half_height, int click_x, int click_y);