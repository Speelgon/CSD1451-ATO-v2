#include "allheaders.hpp"
//Variables Declaration 
AEGfxVertexList* pMesh_logo = nullptr;
AEGfxTexture* Tex_logo;
f32 alpha{}, max_alpha{ 1.0f };
double rate{ 0.01 };
int loops{};



void SplashScreen_Load()
{
    //Load Textures here
    std::cout << "SplashScreen:Load\n";
    Tex_logo = AEGfxTextureLoad("Assets/DigiPen_Singapore_WEB_RED.png");
    AE_ASSERT_MESG(Tex_logo, "Failed to create texture_logo!!");
}

void SplashScreen_Initialize()
{


    AEGfxSetBackgroundColor( 0,  0, 0);
    // Informing the library that we're about to start adding triangles
    AEGfxMeshStart();

    // This shape has 2 triangles
    AEGfxTriAdd(
        -screenwidth/2, -screenwidth/2*0.3, 0x00FF00FF, 0.0f, 1.0f,
        screenwidth /2, -screenwidth /2*0.3, 0x00FFFF00, 1.0f, 1.0f,
        -screenwidth /2, screenwidth/2*0.3, 0x0000FFFF, 0.0f, 0.0f);

    AEGfxTriAdd(
        screenwidth /2, -screenwidth/2*0.3, 0x00FFFFFF, 1.0f, 1.0f,
        screenwidth /2, screenwidth /2*0.3, 0x00FFFFFF, 1.0f, 0.0f,
        -screenwidth /2, screenwidth/2*0.3, 0x00FFFFFF, 0.0f, 0.0f);

    // Saving the mesh (list of triangles) in pMesh2

    pMesh_logo = AEGfxMeshEnd();
    AE_ASSERT_MESG(pMesh_logo, "Failed to create mesh!");





}

void SplashScreen_Update()
{
    {//Logic of Splash Screen
        

        //if mouse clicked/ spacebar/ enter is clicked also jump to the next game state 
        if (AEInputCheckCurr(AEVK_LBUTTON) || AEInputCheckCurr(AEVK_SPACE))
        {
            next = GS_MAINMENU;
        }

        // jumps after logo reaches full opacity
        if (loops == 1)
        {
            next = GS_MAINMENU;
        }
    } // end of Logic of Splash Screen

    {//alpha update
       alpha += (f32)rate;

       //repeats fade but we not using it
       if (alpha >= 1)
       {
           alpha = 0;
           ++loops;
       }

        
    }

    
}

void SplashScreen_Draw()
{

    // Drawing object 
    AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
    // Set position
    AEGfxSetPosition(0.0f, 0.0f);
   // set color
    AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
    //merge background and set transparency
    AEGfxSetBlendMode(AE_GFX_BM_BLEND);
    AEGfxSetTransparency(alpha);
    // Set texture
    AEGfxTextureSet(Tex_logo, 0.0f, 0.0f);
    // Drawing the mesh (list of triangles)
    AEGfxMeshDraw(pMesh_logo, AE_GFX_MDM_TRIANGLES);
    

}

void SplashScreen_Free()
{
    AEGfxMeshFree(pMesh_logo);
    AEGfxTextureUnload(Tex_logo);

}

void SplashScreen_Unload()
{

}