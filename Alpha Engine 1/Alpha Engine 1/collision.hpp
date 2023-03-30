//==========================================================
// file		: collision.hpp
// 
// author   : Owen Quek
// co-author: Ng Wen Wen
// co-author: Kathleen Lim
// 
// email	: o.quek@digipen.edu
//			  wenwen.ng@digipen.edu
//            l.kathleenxiangxuan@digipen.edu
//
// brief	: collision.c is where our main collision checks and calculations are done
//
// Copyright © 2023 DigiPen, All rights reserved.
//==========================================================

#pragma once


void playerCollisionSquare(float& pX, float& pY, float& oX, float& oY, float& pSizeX, float& pSizeY, float& oSizeX, float& oSizeY, float& playerSpeedX, float& playerSpeedY,int& jumptoken, int& lefttoken, int& righttoken);

void playerCollisionCollectible(float& pX, float& pY, float& oX, float& oY, float& pSizeX, float& pSizeY, float& oSizeX, float& oSizeY, int& visibility, int &count);

void playerCollisionMapBoundary(float& pX, float& pY, float& oX, float& oY, float& pSizeX, float& pSizeY, float& oSizeX, float& oSizeY, float playerSpeedX, float playerSpeedY);

void playerCollisionPortal(float& pX, float& pY, float& oX, float& oY, float& pSizeX, float& pSizeY, float& oSizeX, float& oSizeY, int& positiontoken);

void playerCollisionTrampoline(float& pX, float& pY, float& oX, float& oY, float& pSizeX, float& pSizeY, float& oSizeX, float& oSizeY, float& playerSpeedX, float& playerSpeedY, int& jumptoken, int& lefttoken, int& righttoken);

int playerOutofBounds(float pY, float mY);

int playerHookCollision(node *nodes, hook *playerHook, int &collisionFlag);

int exitCollisionDoor(float& pX, float& pY, float& oX, float& oY, float& pSizeX, float& pSizeY, float& oSizeX, float& oSizeY);

int blackholeCollision(float& pX, float& pY, float& oX, float& oY, float& pSizeX, float& pSizeY, float& oSizeX, float& oSizeY);

int blackholeradiusCollision(float& pX, float& pY, float& oX, float& oY, float& pSizeX, float& pSizeY, float& oSizeX, float& oSizeY);

void blackholeCollisionResponse(float& px, float& py, float phw, float phh, float bx, float by, float bhw, float bhh);
