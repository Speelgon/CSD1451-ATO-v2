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

void objectrender(squareObject player, squareObject* object, squareObject* ui, AEGfxVertexList** pMesh, collectibleObject* collectible, AEGfxTexture* pTex, portalObject* portal)

{
	// Drawing object 1
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	// Set position for object 1
	AEGfxSetPosition(player.x, player.y);

	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Texture for player
	AEGfxTextureSet(pTex, 0.0f, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(pMesh[0], AE_GFX_MDM_TRIANGLES);

	AEGfxSetTransparency(1.0f);


	// Drawing object 2 - (first) - No tint
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	// Set position for object 2
	AEGfxSetPosition(object[0].x, object[0].y);
	// No tint
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Set texture
	// AEGfxTextureSet(pTex1, 0.0f, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(pMesh[1], AE_GFX_MDM_TRIANGLES);

	// Drawing object 3 - (first) - No tint
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	// Set position for object 3
	AEGfxSetPosition(object[1].x, object[1].y);
	// No tint
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Set texture
	// AEGfxTextureSet(pTex1, 0.0f, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(pMesh[2], AE_GFX_MDM_TRIANGLES);

	// Drawing object 3 - (first) - No tint
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	// Set position for object 3
	AEGfxSetPosition(object[2].x, object[2].y);
	// No tint
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Set texture
	// EGfxTextureSet(pTex1, 0.0f, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(pMesh[3], AE_GFX_MDM_TRIANGLES);

	// Drawing object 3 - (first) - No tint
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	// Set position for object 3
	AEGfxSetPosition(object[3].x, object[3].y);
	// No tint
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Set texture
	// EGfxTextureSet(pTex1, 0.0f, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(pMesh[4], AE_GFX_MDM_TRIANGLES);

	if(collectible[0].visibility == 1)
	{
		// Drawing object 3 - (first) - No tint
		AEGfxSetRenderMode(AE_GFX_RM_COLOR);
		// Set position for object 3
		AEGfxSetPosition(collectible[0].x, collectible[0].y);
		// No tint
		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Set texture
		// AEGfxTextureSet(pTex1, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(pMesh[10], AE_GFX_MDM_TRIANGLES);
	}

	// Drawing object 3 - (first) - No tint
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	// Set position for object 3
	AEGfxSetPosition(ui[0].x, ui[0].y);
	// No tint
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Set texture
	// AEGfxTextureSet(pTex1, 0.0f, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(pMesh[25], AE_GFX_MDM_TRIANGLES);

	//===============================================================//
	// Portal Drawing												 //
	//===============================================================//

	// Drawing object 3 - (first) - No tint
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	// Set position for object 3
	AEGfxSetPosition(portal[0].x, portal[0].y);
	// No tint
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Set texture
	// AEGfxTextureSet(pTex1, 0.0f, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(pMesh[11], AE_GFX_MDM_TRIANGLES);

	// Drawing object 3 - (first) - No tint
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	// Set position for object 3
	AEGfxSetPosition(portal[1].x, portal[1].y);
	// No tint
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Set texture
	// AEGfxTextureSet(pTex1, 0.0f, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(pMesh[12], AE_GFX_MDM_TRIANGLES);


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