#pragma once


void playerCollisionSquare(float& pX, float& pY, float& oX, float& oY, float& pSizeX, float& pSizeY, float& oSizeX, float& oSizeY, float& playerSpeedX, float& playerSpeedY,int& jumptoken, int& lefttoken, int& righttoken);

void playerCollisionCollectible(float& pX, float& pY, float& oX, float& oY, float& pSizeX, float& pSizeY, float& oSizeX, float& oSizeY, int& visibility);

void playerCollisionMapBoundary(float& pX, float& pY, float& oX, float& oY, float& pSizeX, float& pSizeY, float& oSizeX, float& oSizeY, float playerSpeedX, float playerSpeedY);

void playerCollisionPortal(float& pX, float& pY, float& oX, float& oY, float& pSizeX, float& pSizeY, float& oSizeX, float& oSizeY, int& positiontoken);

void playerCollisionTrampoline(float& pX, float& pY, float& oX, float& oY, float& pSizeX, float& pSizeY, float& oSizeX, float& oSizeY, float& playerSpeedX, float& playerSpeedY, int& jumptoken, int& lefttoken, int& righttoken);

int playerOutofBounds(float pY, float mY);

int playerHookCollision(node *nodes, hook *playerHook, int &collisionFlag);

int exitCollisionDoor(float& pX, float& pY, float& oX, float& oY, float& pSizeX, float& pSizeY, float& oSizeX, float& oSizeY);
