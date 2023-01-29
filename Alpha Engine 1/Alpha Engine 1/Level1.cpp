#include "allheaders.hpp"
#include "objects.hpp"
#include "movement.hpp"

void Level1_Load()
{
	std::cout << "GSM:Load\n";
	square object[30];
	square ui[5];
	collectible1 collectible[maxCollectible];

	AEGfxVertexList* pMesh[30];
	AEGfxVertexList* uiMesh[30];
	AEGfxTexture* pTex[30];

}

// ----------------------------------------------------------------------------
// This function initialized the variables used in level 1
// prints Level1:Initialize to std output
// ----------------------------------------------------------------------------

void Level1_Initialize()
{
	square player;
	player.x = 0;
	player.y = 0;
	player.xvel = 0;
	player.yvel = 0;
	player.width = 10;
	player.height = 60;
	player.halfW = player.width / 2;
	player.halfH = player.height / 2;
	player.lefttoken = 0;
	player.righttoken = 0;
}

// ----------------------------------------------------------------------------
// This function updates the variables used in level 1 and
// prints Level1:Update to std output
// ----------------------------------------------------------------------------

void Level1_Update()
{
	
}

// ----------------------------------------------------------------------------
// This function draws the objects in level 1 based on the variables and
// prints Level1:Draw to std output
// ----------------------------------------------------------------------------

void Level1_Draw()
{
	std::cout << "GSM:Draw\n";
}

// ----------------------------------------------------------------------------
// This function cleans up the game object variables for reinitializaion
// prints Level1:Free to std output
// ----------------------------------------------------------------------------

void Level1_Free()
{
	std::cout << "GSM:Free\n";
}

// ----------------------------------------------------------------------------
// This function clears all the space allocated for the assets loaded in
// the load function for level 1 and prints Level1:Unload to std output
// ----------------------------------------------------------------------------

void Level1_Unload()
{
	std::cout << "GSM:Update\n";
}

