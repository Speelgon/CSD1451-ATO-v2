//==========================================================
// file		: objectRender.cpp
// 
// author   : Owen Quek
// co-author: Ng Wen Wen
// co-author: Kathleen Lim
// co-author: Tham Kwan Eu
// 
// email	: o.quek@digipen.edu
//			  wenwen.ng@digipen.edu
//            l.kathleenxiangxuan@digipen.edu
//			  t.kwaneu@digipen.edu
//
// brief	: objectRender.cpp allows draws all the objects required for each gamestate
//
// Copyright © 2023 DigiPen, All rights reserved.
//==========================================================

#pragma once
#include "allheaders.hpp"
#include "objects.hpp"
/*================================================================================================================================

							INTSRUCTIONS FOR PRINTING SHAPES ON THE SCREEN
							1. DECLARE & INITIALIZE OBJECT (OBJECTS ALREADY DECLARED IN
							   objectDecs.hpp AND INITIALIZED IN objectinit()

							2. SET OBJECT VARIABLES IN objectlevel1init()
							   THIS MAY NOT BE objectlevel1init() IN THE FUTURE AS EACH
							   LEVEL NEEDS ITS OWN OBJECT LOCATIONS
							3. INITIALIZE MESHES (ALREADY INITIALIZED IN meshinit()
							4. SET THE OBJECTS TO THEIR RESPECTIVE MESHES IN meshinitlevel1()
							5. SET THE OBJECT TO RENDER IN objectrender()

================================================================================================================================
*/


void backgroundrender( AEGfxVertexList** pMeshPtr, AEGfxTexture* pTexBackgroundptr)
{
	// Drawing object 1
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	// Set position for object 1
	// 
	//Blend mode necessary to remove black backgound
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxSetTransparency(1.0f);
	AEGfxSetPosition(-1000, -200);

	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Texture for player
	AEGfxTextureSet(pTexBackgroundptr, 0.0f, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(pMeshPtr[120], AE_GFX_MDM_TRIANGLES);
}

void DisappearingPlatformRender(squareObject* objectptr,PlatformState* platformstate, AEGfxVertexList** pMeshPtr, AEGfxTexture* pTexPlatformPtr, AEGfxTexture* pTexDisappearingPlatPtr)
{
	if (platformstate[0].state != DISAPPEARED && platformstate[0].state == CANTDISAPPEAR)
	{
		// Drawing platform 1
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		AEGfxSetBlendMode(AE_GFX_BM_BLEND);
		AEGfxSetTransparency(1.0f);

		// Set position for platform 1
		AEGfxSetPosition(objectptr[0].x, objectptr[0].y);

		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Texture for platform
		AEGfxTextureSet(pTexPlatformPtr, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(pMeshPtr[1], AE_GFX_MDM_TRIANGLES);

		AEGfxSetTransparency(1.0f);
	}
	else if (platformstate[0].state != DISAPPEARED )
	{
		// Drawing platform 1
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		AEGfxSetBlendMode(AE_GFX_BM_BLEND);
		AEGfxSetTransparency(1.0f);

		// Set position for platform 1
		AEGfxSetPosition(objectptr[0].x, objectptr[0].y);

		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Texture for platform
		AEGfxTextureSet(pTexDisappearingPlatPtr, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(pMeshPtr[1], AE_GFX_MDM_TRIANGLES);

		AEGfxSetTransparency(1.0f);
	}


	if (platformstate[1].state != DISAPPEARED && platformstate[1].state == CANTDISAPPEAR)
	{
		// Drawing platform 2
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		AEGfxSetBlendMode(AE_GFX_BM_BLEND);
		// Set position for platform 1
		AEGfxSetPosition(objectptr[1].x, objectptr[1].y);

		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Texture for platform
		AEGfxTextureSet(pTexPlatformPtr, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(pMeshPtr[2], AE_GFX_MDM_TRIANGLES);

		AEGfxSetTransparency(1.0f);
	}
	else if (platformstate[1].state != DISAPPEARED )
	{
		// Drawing platform 2
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		AEGfxSetBlendMode(AE_GFX_BM_BLEND);
		// Set position for platform 1
		AEGfxSetPosition(objectptr[1].x, objectptr[1].y);

		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Texture for platform
		AEGfxTextureSet(pTexDisappearingPlatPtr, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(pMeshPtr[2], AE_GFX_MDM_TRIANGLES);

		AEGfxSetTransparency(1.0f);
	
	}

	if (platformstate[2].state != DISAPPEARED && platformstate[2].state == CANTDISAPPEAR)
	{
		// Drawing platform 3
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		AEGfxSetBlendMode(AE_GFX_BM_BLEND);
		// Set position for platform 1
		AEGfxSetPosition(objectptr[2].x, objectptr[2].y);

		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Texture for platform
		AEGfxTextureSet(pTexPlatformPtr, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(pMeshPtr[3], AE_GFX_MDM_TRIANGLES);

		AEGfxSetTransparency(1.0f);
	}

	else if (platformstate[2].state != DISAPPEARED)
	{
		// Drawing platform 3
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		AEGfxSetBlendMode(AE_GFX_BM_BLEND);
		// Set position for platform 1
		AEGfxSetPosition(objectptr[2].x, objectptr[2].y);

		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Texture for platform
		AEGfxTextureSet(pTexDisappearingPlatPtr, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(pMeshPtr[3], AE_GFX_MDM_TRIANGLES);

		AEGfxSetTransparency(1.0f);
	}


	if (platformstate[3].state != DISAPPEARED && platformstate[3].state == CANTDISAPPEAR)
	{
		// Drawing platform 4

		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		AEGfxSetBlendMode(AE_GFX_BM_BLEND);
		// Set position for platform 1
		AEGfxSetPosition(objectptr[3].x, objectptr[3].y);

		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Texture for platform
		AEGfxTextureSet(pTexPlatformPtr, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(pMeshPtr[4], AE_GFX_MDM_TRIANGLES);

		AEGfxSetTransparency(1.0f);
	}
	else if (platformstate[3].state != DISAPPEARED)
	{
		// Drawing platform 4
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		AEGfxSetBlendMode(AE_GFX_BM_BLEND);
		// Set position for platform 1
		AEGfxSetPosition(objectptr[3].x, objectptr[3].y);

		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Texture for platform
		AEGfxTextureSet(pTexDisappearingPlatPtr, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(pMeshPtr[4], AE_GFX_MDM_TRIANGLES);

		AEGfxSetTransparency(1.0f);
	}
}



void objectrender(squareObject playerArg,  squareObject* uiPtr, AEGfxVertexList** pMeshPtr, collectibleObject* collectiblePtr, AEGfxTexture* pTexPtr, portalObject* portalPtr, AEGfxTexture* pTexPortalPtr, AEGfxTexture* pTexCollectiblePtr, blackhole1* blackholePtr, nodeObject* nodesPtr, AEGfxTexture* pTexNodePtr, exitDoor* exitdoorPtr, AEGfxTexture* pTexExitdoorPtr, AEGfxTexture* pTexHookPtr, AEGfxTexture* pTexTrampolinePtr, AEGfxTexture* pTexBlackholePtr)
{
	
	//===============================================================
	// Platform Drawing												 
	//===============================================================

	/*DisappearingPlatformRender(object, platformstate, pMeshPtr, pTexPlatformPtr, pTexDisappearingPlatPtr);*/

	//===============================================================
	// Node Drawing												 
	//===============================================================

	//node 1
	AEGfxSetBlendMode(AE_GFX_BM_NONE);

	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetPosition(nodesPtr[0].x, nodesPtr[0].y);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(pTexNodePtr, 0.0f, 0.0f);
	AEGfxMeshDraw(pMeshPtr[5], AE_GFX_MDM_TRIANGLES);

	//node 2
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetPosition(nodesPtr[1].x, nodesPtr[1].y);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	AEGfxTextureSet(pTexNodePtr, 0.0f, 0.0f);
	AEGfxMeshDraw(pMeshPtr[6], AE_GFX_MDM_TRIANGLES);

	//===============================================================
	// Collectible Drawing												 
	//===============================================================

	if (collectiblePtr[0].visibility == 1)
	{
		// Drawing collectible
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		// Set position for collectible
		AEGfxSetPosition(collectiblePtr[0].x, collectiblePtr[0].y);
		// No tint
		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Set texture
		AEGfxTextureSet(pTexCollectiblePtr, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(pMeshPtr[10], AE_GFX_MDM_TRIANGLES);

	}

	if (collectiblePtr[1].visibility == 1)
	{

		// Drawing collectible
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		// Set position for collectible
		AEGfxSetPosition(collectiblePtr[1].x, collectiblePtr[1].y);
		// No tint
		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Set texture
		AEGfxTextureSet(pTexCollectiblePtr, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(pMeshPtr[13], AE_GFX_MDM_TRIANGLES);
	}

	if (collectiblePtr[2].visibility == 1)
	{
		// Drawing collectible
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		// Set position for collectible
		AEGfxSetPosition(collectiblePtr[2].x, collectiblePtr[2].y);
		// No tint
		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Set texture
		AEGfxTextureSet(pTexCollectiblePtr, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(pMeshPtr[14], AE_GFX_MDM_TRIANGLES);
	}
	

	//===============================================================
	// UI Drawing												 
	//===============================================================

	// Drawing UI
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	// Set position for UI
	AEGfxSetPosition(uiPtr[0].x, uiPtr[0].y);
	// No tint
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Set texture
	// AEGfxTextureSet(pTex1, 0.0f, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(pMeshPtr[25], AE_GFX_MDM_TRIANGLES);

	//===============================================================
	// Portal Drawing												 
	//===============================================================

	// Drawing portal 1
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	// Set position for portal 1
	AEGfxSetPosition(portalPtr[0].x, portalPtr[0].y);

	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Texture for portal 1
	AEGfxTextureSet(pTexPortalPtr, 0.0f, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(pMeshPtr[11], AE_GFX_MDM_TRIANGLES);

	AEGfxSetTransparency(1.0f);

	// Drawing portal 2
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	// Set position for portal 2
	AEGfxSetPosition(portalPtr[1].x, portalPtr[1].y);

	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Texture for portal 2
	AEGfxTextureSet(pTexPortalPtr, 0.0f, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(pMeshPtr[12], AE_GFX_MDM_TRIANGLES);

	//===============================================================
	// Hook Drawing												 
	//===============================================================

	// Drawing object 3 - (first) - No tint
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

	AEGfxSetPosition(playerHook.x, playerHook.y);
	// No tint
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	
	AEGfxTextureSet(pTexHookPtr, 0, 0);

	AEGfxMeshDraw(pMeshPtr[15], AE_GFX_MDM_TRIANGLES);

	AEGfxSetTransparency(1.0f);


	//===============================================================
	// Blackhole Drawing												 
	//===============================================================

	// Drawing object 3 - (first) - No tint
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	
	AEGfxSetPosition(blackholePtr[0].x, blackholePtr[0].y);
	// No tint
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);

	AEGfxTextureSet(pTexBlackholePtr, 0, 0);
	AEGfxMeshDraw(pMeshPtr[50], AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);

	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

	// Drawing object 3 - (first) - No tint
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

	AEGfxSetPosition(blackholePtr[1].x, blackholePtr[1].y);
	// No tint
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);

	AEGfxTextureSet(pTexBlackholePtr, 0, 0);
	AEGfxMeshDraw(pMeshPtr[50], AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);

	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

	//===============================================================
	// Trampoline Drawing												 
	//===============================================================

	// Drawing object 3 - (first) - No tint
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

	AEGfxSetPosition(trampoline[0].x, trampoline[0].y);
	// No tint
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);

	AEGfxTextureSet(pTexTrampolinePtr, 0.0f, 0.0f);
	AEGfxMeshDraw(pMeshPtr[30], AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);

	//===============================================================
	// Exit Door Drawing												 
	//===============================================================
	
	// Drawing object 3 - (first) - No tint
	AEGfxSetBlendMode(AE_GFX_BM_NONE);
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);

	AEGfxSetPosition(exitdoorPtr[0].x, exitdoorPtr[0].y);
	// No tint
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);

	AEGfxTextureSet(pTexExitdoorPtr, 0.0f, 0.0f);
	AEGfxMeshDraw(pMeshPtr[60], AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);

	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

	//===============================================================
	// Player Drawing												 
	//===============================================================

	// Drawing object 1
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	// Set position for object 1
	// 
	//Blend mode necessary to remove black backgound
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxSetTransparency(1.0f);
	AEGfxSetPosition(playerArg.x, playerArg.y);

	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Texture for player
	AEGfxTextureSet(pTexPtr, 0.0f, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(pMeshPtr[0], AE_GFX_MDM_TRIANGLES);





	//if (AEInputCheckCurr(AEVK_T))
	//{
	//	trigger = 1;
	//}

	//if (trigger)
	//{
	//	// Drawing object 3 - (first) - No tint
	//	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	//	// Set position for object 3
	//	AEGfxSetPosition(object[3].x, object[3].y);
	//	// No tint
	//	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	//	// Set texture
	//	AEGfxTextureSet(pTex1, 0.0f, 0.0f);
	//	// Drawing the mesh (list of triangles)
	//	AEGfxMeshDraw(pMeshPtr[4], AE_GFX_MDM_TRIANGLES);

	//}

}

void anglePlayerToMouse() {
	item.direction.x = f32(mouseX) - f32(AEGetWindowWidth() / 2);
	item.direction.y = f32(mouseY) - f32(AEGetWindowHeight() / 2);
	AEVec2Normalize(&item.direction, &item.direction);
	item.rotation = atan2(item.direction.y, item.direction.x);

}

void anglePlayerToNode(node nodesArg) {
	item.direction.x = f32(nodesArg.x) - f32(player.x);
	item.direction.y = f32(nodesArg.y) - f32(player.y);
	AEVec2Normalize(&item.direction, &item.direction);
	item.rotation = atan2(item.direction.y, item.direction.x);

	item.direction.x = (nodesArg.x - player.x) * cos(item.rotation) - (nodesArg.y - player.y) * sin(item.rotation);
	item.direction.y = (nodesArg.x - player.x) * sin(item.rotation) + (nodesArg.y - player.y) * cos(item.rotation);
	AEVec2Normalize(&item.direction, &item.direction);
}

void kwanEuItemRender(AEGfxTexture* pTexStickPtr) {

	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

	// Set Scale for Item
	AEMtx33 scale = { 0 };
	AEMtx33Scale(&scale, 1, 1);

	// Create a rotation matrix
	AEMtx33 rotate = { 0 };
	
	AEMtx33Rot(&rotate, 360 - AERadToDeg(item.rotation) /60);

	// Create a translation matrix that translates by
	// 100 in the x-axis and 100 in the y-axis
	AEMtx33 translate = { 0 };

	AEMtx33Trans(&translate, 12* item.direction.x + player.x, -14* item.direction.y + player.y);

	// Concat the matrices
	AEMtx33 transform = { 0 };
	AEMtx33Concat(&transform, &rotate, &scale);
	AEMtx33Concat(&transform, &translate, &transform);

	// Choose the transform to use
	AEGfxSetTransform(transform.m);
	// No texture for object 1
	AEGfxTextureSet(pTexStickPtr, 0, 0);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(itemMesh, AE_GFX_MDM_TRIANGLES);

}