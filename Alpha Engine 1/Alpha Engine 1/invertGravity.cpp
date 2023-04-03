//==========================================================
// file		: invertGravity.cpp
// 
// author   : Owen Quek
// 
// email	: o.quek@digipen.edu

//
// brief	: Defines the function to invert gravity. Not implemented
// 
// Copyright © 2023 DigiPen, All rights reserved.
//==========================================================

#include "invertGravity.hpp"

extern float gravity;
extern float jumpspeed;

void invertGravity() {

	if (gravity >= 0.14)
		gravity = -gravity / 2;

	else gravity = 0.15f;

	jumpspeed = -jumpspeed;
	
}




