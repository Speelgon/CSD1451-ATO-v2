#pragma once
#include "allheaders.hpp"
#include "objects.hpp"

void objectrender(squareObject player, squareObject* object, squareObject* ui, AEGfxVertexList** pMesh)
{
	// Drawing object 1
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	// Set position for object 1
	AEGfxSetPosition(player.x, player.y);
	// No texture for object 1
	// AEGfxTextureSet(NULL, 0, 0);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(pMesh[0], AE_GFX_MDM_TRIANGLES);

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
	AEGfxSetPosition(ui[0].x, ui[0].y);
	// No tint
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Set texture
	// AEGfxTextureSet(pTex1, 0.0f, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(pMesh[25], AE_GFX_MDM_TRIANGLES);


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
	//	AEGfxMeshDraw(pMesh[3], AE_GFX_MDM_TRIANGLES);

	//}

}