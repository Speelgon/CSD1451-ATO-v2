#pragma once


void playerCollisionSquare(float& pX, float& pY, float& oX, float& oY, float& pSizeX, float& pSizeY, float& oSizeX, float& oSizeY, float& playerSpeedX, float& playerSpeedY,int& jumptoken, int& lefttoken, int& righttoken);

void playerCollisionMapBoundary(float& pX, float& pY, float& oX, float& oY, float& pSizeX, float& pSizeY, float& oSizeX, float& oSizeY, float playerSpeedX, float playerSpeedY);

int playerOverCollectible(float px, float py, float cx, float cy);

