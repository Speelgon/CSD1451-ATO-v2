//==========================================================
// file		: movement.hpp
// 
// author   : Owen Quek
// 
// email	: o.quek@digipen.edu
//
// brief	: movement.hpp declares
//
// Copyright © 2023 DigiPen, All rights reserved.
//==========================================================

#pragma once
#include "objects.hpp"


void playerInputMovement(float& pX, float& pY, float playerSpeed, int& jumptoken);

void playerActualMovement(float& pX, float& pY, float& pxvel, float& pyvel);

void playerEasingMovement(float& pxvel, float& pyvel, float stabilizer);

void playerGravity(float& pY, float grav);

void movementWhenHooked(float &pXvel, float &pYvel, float grav, rectangle item, node* collidingNode);

