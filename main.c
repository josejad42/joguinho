#include "raylib.h"
#include "raymath.h"
#include "player.h"
#include "map.h"
#include "enemy.h"

int main(void)
{
    const int screenWidth = 960;
    const int screenHeight = 540;

    InitWindow(screenWidth, screenHeight, "Joguinho");
    
    init_map();
    init_player();
    init_enemy();

    SetTargetFPS(60);  

    // Main game loop
    while (!WindowShouldClose())
    {
        map_positioning();
        player_positioning();
        mov_enemy();

        BeginDrawing();

            ClearBackground(BLACK);
            draw_map();
            draw_player();
            draw_enemy();
            atk_enemy();
           
        EndDrawing();

    }
    
    unload_map();
    unload_player();
    unload_enemy();
   
    CloseWindow();     
   
    return 0;
}
