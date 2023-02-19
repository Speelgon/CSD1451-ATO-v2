#include "allheaders.hpp"
#include "objects.hpp"
#include "Level1.hpp"
//Created so I could extend the item in a function

void meshUpdate()
{
	AEGfxMeshStart();
	AEGfxTriAdd(
		-item.width / 2, -item.height / 2, 0xFFFFFF00, 0.0f, 1.0f,
		item.width / 2, -item.height / 2, 0xFFFFFF00, 1.0f, 1.0f,
		-item.width / 2, item.height / 2, 0xFFFFFF00, 0.0f, 0.0f);

	AEGfxTriAdd(
		item.width / 2, -item.height / 2, 0xFFFFFFFF, 1.0f, 1.0f,
		item.width / 2, item.height / 2, 0xFFFFFFFF, 1.0f, 0.0f,
		-item.width / 2, item.height / 2, 0xFFFFFFFF, 0.0f, 0.0f);

	// Saving the mesh (list of triangles) in pMesh1

	itemMesh = AEGfxMeshEnd();
	AE_ASSERT_MESG(itemMesh, "Failed to create Item Mesh!!");
}
