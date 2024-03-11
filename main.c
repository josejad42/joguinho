#include "raylib.h"
#include "raymath.h"
#include "player.h"

int main(void)
{
    const int screenWidth = 850;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "tela com mapa bugado");
    init_player();
 
    Texture2D clouds01 = LoadTexture("assets/Assets/clouds_01.png"); 
    Texture2D clouds02 = LoadTexture("assets/Assets/clouds_02.png");
    Texture2D foregound = LoadTexture("assets/Assets/foregound.png");
    Texture2D light = LoadTexture("assets/Assets/light.png");
    Texture2D middleground = LoadTexture("assets/Assets/middleground.png");
    Texture2D moon = LoadTexture("assets/Assets/moon.png");
    //Texture2D tiles = LoadTexture("assets/Assets/tiles.png");


    float movcloud01 = 0.0f;
    float movcloud02 = 0.0f;
    float movforegound = 0.0f;
    float movlight = 0.0f;
    float movmidlleground = 0.0f;
    float movmoon = 0.0f;
    //float movtiles = 0.0f;


    SetTargetFPS(60);  


    // Main game loop
    while (!WindowShouldClose())
    {
        //altera velocidade das texturas 

        movcloud01 -= 0.7f;
        movcloud02 -= 0.5f;
        movforegound -= 0.5f;
        movlight -= 0.1f;
        movmidlleground -= 0.5f;
        movmoon -= 0.5f;
        //movtiles -= 5.0f;

        
        // reinicia a textura OU PELO MENOS DEVERIA com *2 buga
        if (movcloud01 <= -clouds01.width*1) movcloud01 = 0;
        if (movcloud02 <= -clouds02.width*1) movcloud02 = 0;
        //if (movforegound <= -foregound.width*2) movforegound = 0;
        if (movlight <= -light.width*1) movlight = 0;
        if (movmidlleground <= -foregound.width*1) movmidlleground = 0;
        if (movmoon <= -moon.width*1) movmoon = 0;
        //if (movtiles <= -tiles.width*2) movtiles = 0;
         
        player_position();

        BeginDrawing();


            ClearBackground(WHITE);

            DrawTextureEx(clouds02, (Vector2){ movcloud02, 20 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(clouds02, (Vector2){ clouds02.width*2 + movcloud02, 20 }, 0.0f, 2.0f, WHITE);

            DrawTextureEx(clouds01, (Vector2){ movcloud01, 20 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(clouds01, (Vector2){ clouds01.width*2 + movcloud01, 20 }, 0.0f, 2.0f, WHITE);

            //DrawTextureEx(foregound, (Vector2){ movforegound, 20 }, 0.0f, 2.0f, WHITE);
            //DrawTextureEx(foregound, (Vector2){ foregound.width*2 + movforegound, 20 }, 0.0f, 2.0f, WHITE);

            //DrawTextureEx(light, (Vector2){ movlight, 20 }, 0.0f, 2.0f, WHITE);
            //DrawTextureEx(light, (Vector2){ light.width*2 + movlight, 20 }, 0.0f, 2.0f, WHITE);

            DrawTextureEx(middleground, (Vector2){ movmidlleground, 20 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(middleground, (Vector2){ middleground.width*2 + movmidlleground, 20 }, 0.0f, 2.0f, WHITE);

            //DrawTextureEx(moon, (Vector2){ movmoon, 20 }, 0.0f, 2.0f, WHITE);
            //DrawTextureEx(moon, (Vector2){ moon.width*2 + movmoon, 20 }, 0.0f, 2.0f, WHITE);
            draw_player ();
           

        EndDrawing();

    }
    
    unload_player ();

    UnloadTexture(clouds01);
    UnloadTexture(clouds02);
    UnloadTexture(foregound);
    UnloadTexture(light);
    UnloadTexture(middleground);
    UnloadTexture(moon);

   
    CloseWindow();     
   

    return 0;
}

