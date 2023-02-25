//#include "allheaders.hpp"
//square pause_buttons;
//f32 pause_mainmenu;
//f32 pause_quit;
//AEGfxVertexList* pausebutton_mesh;
//void Pausemenu_Load()
//{
//	std::cout << "GSM:Load\n";
//}
//
//void Pausemenu_Initialize()
//{
//	pause_buttons.x = 0;
//	pause_buttons.y = 50;
//	pause_mainmenu = pause_buttons.y - 80;
//	pause_quit = pause_buttons.y - 160;
//	pause_buttons.width = 120;
//	pause_buttons.height = 40;
//	pause_buttons.halfW = pause_buttons.width / 2;
//	pause_buttons.halfH = pause_buttons.height / 2;
//	//fontId = AEGfxCreateFont("C:/Users/Yuki/OneDrive/Documents/GitHub/CSD1451-ATO-v2/Alpha Engine 1/Assets/Roboto-Regular.ttf", 12);
//
//	AEGfxMeshStart();
//	AEGfxTriAdd(
//		-pause_buttons.halfW, -pause_buttons.halfH, 0xFFFFFF00, 0.0f, 1.0f,
//		pause_buttons.halfW, -pause_buttons.halfH, 0xFFFFFF00, 1.0f, 1.0f,
//		-pause_buttons.halfW, pause_buttons.halfH, 0xFFFFFF00, 0.0f, 0.0f);
//
//	AEGfxTriAdd(
//		pause_buttons.halfW, -pause_buttons.halfH, 0xFFFFFFFF, 1.0f, 1.0f,
//		pause_buttons.halfW, pause_buttons.halfH, 0xFFFFFFFF, 1.0f, 0.0f,
//		-pause_buttons.halfW, pause_buttons.halfH, 0xFFFFFFFF, 0.0f, 0.0f);
//
//	// Saving the mesh (list of triangles) in pMesh1
//
//	pausebutton_mesh = AEGfxMeshEnd();
//	AE_ASSERT_MESG(pausebutton_mesh, "Failed to create playMesh!!");
//
//}
//
//void Pausemenu_Update()
//{
//
//}
//
//void Pausemenu_Draw()
//{
//
//}
//
//void Pausemenu_Free()
//{
//	AEGfxMeshFree(pausebutton_mesh);
//}
//
//void Pausemenu_Unload()
//{
//
//}