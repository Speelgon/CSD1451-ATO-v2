#include <chrono> 
#include "allheaders.hpp"
#include "SplashScreen.hpp"
//Variables Declaration 
auto start_time{std::chrono::high_resolution_clock::now()}; //get the start time 
double duration{};
const double splash_duration{ 5.0 }; //splashscreen duration 5s 
AEGfxVertexList* pMesh_logo = 0;


void SplashScreen_Load()
{
    //Load Textures here
}

void SplashScreen_Initialize()
{
    
    
    // Informing the library that we're about to start adding triangles
    AEGfxMeshStart();

    // This shape has 2 triangles
    AEGfxTriAdd(
        -30.0f, -30.0f, 0x00FF00FF, 0.0f, 1.0f,
        30.0f, -30.0f, 0x00FFFF00, 1.0f, 1.0f,
        -30.0f, 30.0f, 0x0000FFFF, 0.0f, 0.0f);

    AEGfxTriAdd(
        30.0f, -30.0f, 0x00FFFFFF, 1.0f, 1.0f,
        30.0f, 30.0f, 0x00FFFFFF, 1.0f, 0.0f,
        -30.0f, 30.0f, 0x00FFFFFF, 0.0f, 0.0f);

    // Saving the mesh (list of triangles) in pMesh2

    pMesh_logo = AEGfxMeshEnd();
    AE_ASSERT_MESG(pMesh_logo, "Failed to create mesh!");
    
   
   


}

void SplashScreen_Update()
{
    {//Logic of Splash Screen
        //wait for splash screen duration to elaspe
        while (duration < splash_duration)
        {
            auto end_time = std::chrono::high_resolution_clock::now();
            // duration will contain the time difference between the end time and start time 
            //std::chrono::duration<double>(end_time-start_time) creates
            //a std::chrono::duration object of type std::chrono::duration<double> from the duration 
            // This specifies that the duration is to be represented as a floating-point value.
            duration = std::chrono::duration<double>(end_time-start_time).count();
        
        }

        // after the elaspe 
        if (duration >= splash_duration)
        {
            //jump to the next game state
            next = GS_MAINMENU;
        
        }

        //if mouse clicked/ spacebar/ enter is clicked also jump to the next game state 
        //jump release from the hook automatically
        if (AEInputCheckCurr(AEVK_LBUTTON) || AEInputCheckCurr(AEVK_SPACE) )
        {
            next = GS_MAINMENU;
        }
    } // end of Logic of Splash Screen
}

void SplashScreen_Draw()
{
    // Drawing object 2 - (first)
    AEGfxSetRenderMode(AE_GFX_RM_COLOR);
    // Set position for object 2
    AEGfxSetPosition(100.0f, -60.0f);
    AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
    // No texture for object 2
    AEGfxTextureSet(NULL, 0, 0);
    // Drawing the mesh (list of triangles)
    AEGfxMeshDraw(pMesh_logo, AE_GFX_MDM_TRIANGLES);

}

void SplashScreen_Free()
{
    AEGfxMeshFree(pMesh_logo);
}

void SplashScreen_Unload()
{

}