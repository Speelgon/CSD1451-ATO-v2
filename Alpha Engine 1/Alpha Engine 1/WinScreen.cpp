//#include "allheaders.hpp"
//square winscreen_buttons;
//f32 winscreen_nextlevel;
//f32 winscreen_mainmenu;
//f32 winscreen_restart;
//extern int mousex;
//extern int mousey;
//extern int truemousex;
//extern int truemousey;
//AEGfxVertexList* winscreenbutton_mesh;
//
//void Winscreen_Load()
//{
//	std::cout << "GSM:Load\n";
//}
//
//void Winscreen_Initialize()
//{
//	winscreen_buttons.x = 0;
//	winscreen_buttons.y = 50;
//
//	winscreen_nextlevel = winscreen_buttons.y - 80;
//	winscreen_mainmenu = winscreen_buttons.y - 160;
//	winscreen_restart = winscreen_buttons.y - 240;
//
//	winscreen_buttons.width = 120;
//	winscreen_buttons.height = 40;
//	winscreen_buttons.halfW = winscreen_buttons.width / 2;
//	winscreen_buttons.halfH = winscreen_buttons.height / 2;
//	//fontId = AEGfxCreateFont("C:/Users/Yuki/OneDrive/Documents/GitHub/CSD1451-ATO-v2/Alpha Engine 1/Assets/Roboto-Regular.ttf", 12);
//
//	AEGfxMeshStart();
//	AEGfxTriAdd(
//		-winscreen_buttons.halfW, -winscreen_buttons.halfH, 0xFFFFFF00, 0.0f, 1.0f,
//		winscreen_buttons.halfW, -winscreen_buttons.halfH, 0xFFFFFF00, 1.0f, 1.0f,
//		-winscreen_buttons.halfW, winscreen_buttons.halfH, 0xFFFFFF00, 0.0f, 0.0f);
//
//	AEGfxTriAdd(
//		winscreen_buttons.halfW, -winscreen_buttons.halfH, 0xFFFFFFFF, 1.0f, 1.0f,
//		winscreen_buttons.halfW, winscreen_buttons.halfH, 0xFFFFFFFF, 1.0f, 0.0f,
//		-winscreen_buttons.halfW, winscreen_buttons.halfH, 0xFFFFFFFF, 0.0f, 0.0f);
//
//	// Saving the mesh (list of triangles) in pMesh1
//
//	winscreenbutton_mesh = AEGfxMeshEnd();
//	AE_ASSERT_MESG(winscreenbutton_mesh, "Failed to create playMesh!!");
//}
//
//void Winscreen_Update()
//{
//	
//}
//
//void Winscreen_Draw()
//{
//
//}
//
//void Winscreen_Free()
//{
//	AEGfxMeshFree(winscreenbutton_mesh);
//}
//
//void Winscreen_Unload()
//{
//
//}
//
//
////dont need to change state, if have if statement if true update loop is paused