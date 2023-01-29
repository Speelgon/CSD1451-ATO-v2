#include "pickaxe.hpp"
#include "allheaders.hpp"
#include "objects.hpp"

void handleItem(rectangle* item, s32 mouseX, s32 mouseY) {
	

	item->direction.x = f32(mouseX) - f32(screenwidth / 2);
	item->direction.y = f32(mouseY) - f32(screenheight / 2);

	AEVec2Normalize(&item->direction, &item->direction);
	item->rotation = atan2(item->direction.y, item->direction.x);
	
	//Scale the object x and y by 1
	AEMtx33Scale(&item->scaleMatrix, 1, 1);

	//rotate object by degrees
	AEMtx33Rot(&item->rotateMatrix, 360 - AERadToDeg(item->rotation) * AEFrameRateControllerGetFrameTime());

	item->direction.x = (mouseX - screenwidth / 2) * cos(item->rotation) - (mouseY - screenheight / 2) * sin(item->rotation);
	item->direction.y = (mouseX - screenwidth / 2) * sin(item->rotation) + (mouseY - screenheight / 2) * cos(item->rotation);
	//AEVec2Normalize(&item->direction, &item->direction);

	AEMtx33Trans(&item->translateMatrix, item->direction.x, item->direction.y);
	AEMtx33Concat(&item->transformMatrix, &item->rotateMatrix, &item->scaleMatrix);
	AEMtx33Concat(&item->transformMatrix, &item->translateMatrix, &item->transformMatrix);
}

//AEGfxSetRenderMode(AE_GFX_RM_COLOR);
//AEMtx33 transform = { 0 };
//
//item.direction.x = f32(mouseX) - f32(screenwidth / 2);
//item.direction.y = f32(mouseY) - f32(screenheight / 2);
//AEVec2Normalize(&item.direction, &item.direction);
//item.rotation = atan2(item.direction.y, item.direction.x);
//
//// Set Scale for Item
//AEMtx33 scale = { 0 };
//AEMtx33Scale(&scale, 1, 1); //do not set to higher values
//
//// Create a rotation matrix
//AEMtx33 rotate = { 0 };
//
//AEMtx33Rot(&rotate, 360 - AERadToDeg(item.rotation) * 0.016);
//
//AEMtx33 translate = { 0 };
//
//item.direction.x = (mouseX - screenwidth / 2) * cos(item.rotation) - (mouseY - screenheight / 2) * sin(item.rotation);
//item.direction.y = (mouseX - screenwidth / 2) * sin(item.rotation) + (mouseY - screenheight / 2) * cos(item.rotation);
//AEVec2Normalize(&item.direction, &item.direction);
//
//item.direction.x = player.x;
//item.direction.y = player.y;
//AEMtx33Trans(&translate, item.direction.x, item.direction.y);
//
///*item.position.x = player.x;
//item.position.y = player.y;
//AEMtx33Trans(&translate, item.position.x, item.position.y);*/
//
//AEMtx33Concat(&transform, &rotate, &scale);
//AEMtx33Concat(&transform, &translate, &transform);
//
//AEGfxSetTransform(transform.m);
//AEGfxTextureSet(NULL, 0, 0);
//AEGfxMeshDraw(itemMesh, AE_GFX_MDM_TRIANGLES);