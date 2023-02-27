#pragma once
#include "allheaders.hpp"
#include "objects.hpp"
#include "PlatformsDisappear.hpp"
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

void backgroundrender(squareObject player, AEGfxVertexList** pMesh, AEGfxTexture* pTexBackground)
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
	AEGfxTextureSet(pTexBackground, 0.0f, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(pMesh[120], AE_GFX_MDM_TRIANGLES);
}

void DisappearingPlatformRender(PlatformState* platformstate, AEGfxTexture* pTextPlatform)
{
	if (platformstate[0].state != DISAPPEARED)
	{
		// Drawing platform 1
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		AEGfxSetBlendMode(AE_GFX_BM_BLEND);
		AEGfxSetTransparency(1.0f);

		// Set position for platform 1
		AEGfxSetPosition(object[0].x, object[0].y);

		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Texture for platform
		AEGfxTextureSet(pTextPlatform, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(pMesh[1], AE_GFX_MDM_TRIANGLES);

		AEGfxSetTransparency(1.0f);
	}


	if (platformstate[1].state != DISAPPEARED)
	{
		// Drawing platform 2
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		// Set position for platform 1
		AEGfxSetPosition(object[1].x, object[1].y);

		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Texture for platform
		AEGfxTextureSet(pTextPlatform, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(pMesh[2], AE_GFX_MDM_TRIANGLES);

		AEGfxSetTransparency(1.0f);
	}
	if (platformstate[2].state != DISAPPEARED)
	{
		// Drawing platform 3
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		// Set position for platform 1
		AEGfxSetPosition(object[2].x, object[2].y);

		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Texture for platform
		AEGfxTextureSet(pTextPlatform, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(pMesh[3], AE_GFX_MDM_TRIANGLES);

		AEGfxSetTransparency(1.0f);
	}


	if (platformstate[3].state != DISAPPEARED)
	{
		// Drawing platform 4
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		// Set position for platform 1
		AEGfxSetPosition(object[3].x, object[3].y);

		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Texture for platform
		AEGfxTextureSet(pTextPlatform, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(pMesh[4], AE_GFX_MDM_TRIANGLES);

		AEGfxSetTransparency(1.0f);
	}
}



void objectrender(squareObject player, squareObject* object, squareObject* ui, AEGfxVertexList** pMesh, collectibleObject* collectible, AEGfxTexture* pTex, portalObject* portal, AEGfxTexture* pTexPortal, AEGfxTexture* pTextPlatform, AEGfxTexture* pTexCollectible, blackhole1* blackhole, nodeObject* nodes, PlatformState* platformstate, exitDoor* exitdoor, AEGfxTexture* pTexExitdoor)
{
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
	AEGfxSetPosition(player.x, player.y);

	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Texture for player
	AEGfxTextureSet(pTex, 0.0f, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(pMesh[0], AE_GFX_MDM_TRIANGLES);


	
	//===============================================================
	// Platform Drawing												 
	//===============================================================

	DisappearingPlatformRender(platformstate, pTextPlatform);

	//===============================================================
	// Node Drawing												 
	//===============================================================

	//node 1
	AEGfxSetBlendMode(AE_GFX_BM_NONE);

	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	AEGfxSetPosition(nodes[0].x, nodes[0].y);
	AEGfxMeshDraw(pMesh[5], AE_GFX_MDM_TRIANGLES);

	//node 2
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	AEGfxSetPosition(nodes[1].x, nodes[1].y);
	AEGfxMeshDraw(pMesh[6], AE_GFX_MDM_TRIANGLES);

	//===============================================================
	// Collectible Drawing												 
	//===============================================================

	if(collectible[0].visibility == 1)
	{
		// Drawing collectible
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		// Set position for collectible
		AEGfxSetPosition(collectible[0].x, collectible[0].y);
		// No tint
		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Set texture
		 AEGfxTextureSet(pTexCollectible, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(pMesh[10], AE_GFX_MDM_TRIANGLES);
	}

	//===============================================================
	// UI Drawing												 
	//===============================================================

	// Drawing UI
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	// Set position for UI
	AEGfxSetPosition(ui[0].x, ui[0].y);
	// No tint
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Set texture
	// AEGfxTextureSet(pTex1, 0.0f, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(pMesh[25], AE_GFX_MDM_TRIANGLES);

	//===============================================================
	// Portal Drawing												 
	//===============================================================

	// Drawing portal 1
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	// Set position for portal 1
	AEGfxSetPosition(portal[0].x, portal[0].y);

	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Texture for portal 1
	AEGfxTextureSet(pTexPortal, 0.0f, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(pMesh[11], AE_GFX_MDM_TRIANGLES);

	AEGfxSetTransparency(1.0f);

	// Drawing portal 2
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	// Set position for portal 2
	AEGfxSetPosition(portal[1].x, portal[1].y);

	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Texture for portal 2
	AEGfxTextureSet(pTexPortal, 0.0f, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(pMesh[12], AE_GFX_MDM_TRIANGLES);

	//===============================================================
	// Hook Drawing												 
	//===============================================================

	// Drawing object 3 - (first) - No tint
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	AEGfxSetBlendMode(AE_GFX_BM_NONE);
	AEGfxSetPosition(playerHook.x, playerHook.y);
	// No tint
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	
	AEGfxTextureSet(NULL, 0, 0);
	AEGfxMeshDraw(pMesh[15], AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);

	AEGfxSetBlendMode(AE_GFX_BM_BLEND);


	//===============================================================
	// Blackhole Drawing												 
	//===============================================================

	// Drawing object 3 - (first) - No tint
	AEGfxSetBlendMode(AE_GFX_BM_NONE);
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	
	AEGfxSetPosition(blackhole[0].x, blackhole[0].y);
	// No tint
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);

	AEGfxTextureSet(NULL, 0, 0);
	AEGfxMeshDraw(pMesh[50], AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);

	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

	//===============================================================
	// Trampoline Drawing												 
	//===============================================================

	// Drawing object 3 - (first) - No tint
	AEGfxSetBlendMode(AE_GFX_BM_NONE);
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);

	AEGfxSetPosition(trampoline[0].x, trampoline[0].y);
	// No tint
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);

	AEGfxTextureSet(NULL, 0, 0);
	AEGfxMeshDraw(pMesh[30], AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);

	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

	//===============================================================
	// Exit Door Drawing												 
	//===============================================================
	
	// Drawing object 3 - (first) - No tint
	AEGfxSetBlendMode(AE_GFX_BM_NONE);
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);

	AEGfxSetPosition(exitdoor[0].x, exitdoor[0].y);
	// No tint
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);

	AEGfxTextureSet(pTexExitdoor, 0.0f, 0.0f);
	AEGfxMeshDraw(pMesh[60], AE_GFX_MDM_TRIANGLES);
	AEGfxSetTransparency(1.0f);

	AEGfxSetBlendMode(AE_GFX_BM_BLEND);


	//// Drawing object 3 - (first) - No tint
	//AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	//// Set position for object 3
	//AEGfxSetPosition(portal[0].x, portal[0].y);
	//// No tint
	//AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	//// Set texture
	//// AEGfxTextureSet(pTex1, 0.0f, 0.0f);
	//// Drawing the mesh (list of triangles)
	//AEGfxMeshDraw(pMesh[11], AE_GFX_MDM_TRIANGLES);

	//// Drawing object 3 - (first) - No tint
	//AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	//// Set position for object 3
	//AEGfxSetPosition(portal[1].x, portal[1].y);
	//// No tint
	//AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	//// Set texture
	//// AEGfxTextureSet(pTex1, 0.0f, 0.0f);
	//// Drawing the mesh (list of triangles)
	//AEGfxMeshDraw(pMesh[12], AE_GFX_MDM_TRIANGLES);


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
	//	AEGfxMeshDraw(pMesh[4], AE_GFX_MDM_TRIANGLES);

	//}

}

void anglePlayerToMouse() {
	item.direction.x = f32(mouseX) - f32(AEGetWindowWidth() / 2);
	item.direction.y = f32(mouseY) - f32(AEGetWindowHeight() / 2);
	AEVec2Normalize(&item.direction, &item.direction);
	item.rotation = atan2(item.direction.y, item.direction.x);

	item.direction.x = (mouseX - worldwidth / 2) * cos(item.rotation) - (mouseY - worldheight / 2) * sin(item.rotation);
	item.direction.y = (mouseX - worldwidth / 2) * sin(item.rotation) + (mouseY - worldheight / 2) * cos(item.rotation);
	AEVec2Normalize(&item.direction, &item.direction);

}

void anglePlayerToNode(node nodes) {
	item.direction.x = f32(nodes.x) - f32(player.x);
	item.direction.y = f32(nodes.y) - f32(player.y);
	AEVec2Normalize(&item.direction, &item.direction);
	item.rotation = atan2(item.direction.y, item.direction.x);

	item.direction.x = (nodes.x - player.x) * cos(item.rotation) - (nodes.y - player.y) * sin(item.rotation);
	item.direction.y = (nodes.x - player.x) * sin(item.rotation) + (nodes.y - player.y) * cos(item.rotation);
	AEVec2Normalize(&item.direction, &item.direction);
}

void kwanEuItemRender() {

	AEGfxSetRenderMode(AE_GFX_RM_COLOR);

	// Set Scale for Item
	AEMtx33 scale = { 0 };
	AEMtx33Scale(&scale, 1, 1); //set scale to 1 so object can be shown. DO NOT SET TO HIGHER VALUES UNLESS INCREASING SIZE

	// Create a rotation matrix
	AEMtx33 rotate = { 0 };
	//Replaced the dt with 1/60 so the thing object doesn't stutter every second
	AEMtx33Rot(&rotate, 360 - AERadToDeg(item.rotation) * 1/60);

	// Create a translation matrix that translates by
	// 100 in the x-axis and 100 in the y-axis
	AEMtx33 translate = { 0 };

	

	AEMtx33Trans(&translate, 12* item.direction.x + player.x, -12* item.direction.y + player.y);

	// Concat the matrices
	AEMtx33 transform = { 0 };
	AEMtx33Concat(&transform, &rotate, &scale);
	AEMtx33Concat(&transform, &translate, &transform);

	// Choose the transform to use
	AEGfxSetTransform(transform.m);
	// No texture for object 1
	AEGfxTextureSet(NULL, 0, 0);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(itemMesh, AE_GFX_MDM_TRIANGLES);

}