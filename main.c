#include "raylib.h"
#include "raymath.h"
#include "player.h"
#include "map.h"

int main(void)
{
    const int screenWidth = 900;
    const int screenHeight = 540;

    InitWindow(screenWidth, screenHeight, "tela com mapa bugado");
    
    init_map();
    init_player();

    SetTargetFPS(60);  

    // Main game loop
    while (!WindowShouldClose())
    {
        map_positioning();
        player_positioning();

        BeginDrawing();

            ClearBackground(BLACK);
            draw_map();
            draw_player();
           
        EndDrawing();

    }
    
    unload_map();
    unload_player();
   
    CloseWindow();     
   
    return 0;
}