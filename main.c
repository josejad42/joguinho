#include "raylib.h"
#include "raymath.h"

int main(void)
{
    const int screenWidth = 900;
    const int screenHeight = 540;

    InitWindow(screenWidth, screenHeight, "tela com mapa bugado");

 
    Texture2D clouds01 = LoadTexture("assets/Assets/clouds_01.png"); 
    Texture2D clouds02 = LoadTexture("assets/Assets/clouds_02.png");
    Texture2D foregound = LoadTexture("assets/Assets/foregound.png");
    Texture2D light = LoadTexture("assets/Assets/light.png");
    Texture2D middleground = LoadTexture("assets/Assets/middleground.png");
    //Texture2D moon = LoadTexture("assets/Assets/moon.png");

    // Image moonimage = LoadImage("assets/Assets/moon.png");             // Load image in CPU memory (RAM)
    // ImageCrop(&moonimage, (Rectangle){ 0, 10, 190, 200 });      // Crop an image piece                              // Flip cropped image horizontally
    // ImageResize(&moonimage, 150, 200);
    //Texture2D tiles = LoadTexture("assets/Assets/tiles.png");

      // Load image data into CPU memory (RAM)
    // Texture2D moon = LoadTextureFromImage(moonimage);       // Image converted to texture, GPU memory (RAM -> VRAM)
    // UnloadImage(moonimage);                                    // Unload image data from CPU memory (RAM)                                // Unload texture from GPU memory (VRAM)


    float movcloud01 = 0.0f;
    float movcloud02 = 0.0f;
    float movforegound = 0.0f;
    float movlight = 0.0f;
    float movmidlleground = 0.0f;
    float movmoon = 0.0f;
    //float movtiles = 0.0f;
    //int troca = 0;

    SetTargetFPS(60);  


    // Main game loop
    while (!WindowShouldClose())
    {
        //altera velocidade das texturas 

        movcloud01 -= 0.7f;
        movcloud02 -= 0.5f;
        //movforegound -= 0.5f;
        movlight -= 0.1f;
        movmidlleground -= 0.5f;
        movmoon -= 0.5f;
        //movtiles -= 5.0f;

        
        // reinicia a textura OU PELO MENOS DEVERIA com *2 buga
        if (movcloud01 <= -clouds01.width*2) movcloud01 = 0;
        if (movcloud02 <= -clouds02.width*2) movcloud02 = 0;
        //if (movforegound <= -foregound.width*2) movforegound = 0;
        if (movlight <= -light.width*1) movlight = 0;
        if (movmidlleground <= -foregound.width*1) movmidlleground = 0; 
        //if (movmoon <= -moon.width*1) movmoon = 0;
        //if (movtiles <= -tiles.width*2) movtiles = 0;


        BeginDrawing();


            ClearBackground(BLACK);

            DrawTextureEx(clouds02, (Vector2){ movcloud02, 0 }, 0.0f, 2.5f, WHITE);
            DrawTextureEx(clouds02, (Vector2){ clouds02.width*2.5 + movcloud02, 0 }, 0.0f, 2.5f, WHITE);

            DrawTextureEx(clouds01, (Vector2){ movcloud01, 0}, 0.0f, 2.5f, WHITE);
            DrawTextureEx(clouds01, (Vector2){ clouds01.width*2.5 + movcloud01, 0}, 0.0f, 2.5f, WHITE);

            // DrawTextureEx(foregound, (Vector2){ movforegound, 100 }, 0.0f, 2.5f, WHITE);
            // DrawTextureEx(foregound, (Vector2){ foregound.width*2.5 + movforegound, 100 }, 0.0f, 2.5f, WHITE);

            //DrawTextureEx(light, (Vector2){ movlight, 20 }, 0.0f, 2.0f, WHITE);
            //DrawTextureEx(light, (Vector2){ light.width*2 + movlight, 20 }, 0.0f, 2.0f, WHITE);


            DrawTextureEx(middleground, (Vector2){ movmidlleground, 150 }, 0.0f, 2.5f, WHITE);
            DrawTextureEx(middleground, (Vector2){ middleground.width*2.5 + movmidlleground, 150 }, 0.0f, 2.5f, WHITE);

            
            
            // DrawTextureEx(moon, (Vector2){ movmoon, 20 }, 0.0f, 2.0f, WHITE);
            // DrawTextureEx(moon, (Vector2){ moon.width*2 + movmoon, 20 }, 0.0f, 2.0f, WHITE);
            
           

        EndDrawing();

    }

    UnloadTexture(clouds01);
    UnloadTexture(clouds02);
    UnloadTexture(foregound);
    UnloadTexture(light);
    UnloadTexture(middleground);
    // UnloadTexture(moon);

   
    CloseWindow();     
   

    return 0;
}

