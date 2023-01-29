#pragma once
#include "objects.hpp"

void playerInputMovement(float& pX, float& pY, float playerSpeed, int& jumptoken);

void playerActualMovement(float& pX, float& pY, float& pxvel, float& pyvel);

void playerEasingMovement(float& pxvel, float& pyvel, float stabilizer);

void playerGravity(float& pY, float grav);



