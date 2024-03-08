#include "raylib.h"
#include "raymath.h"
#include "player.h"

int main(void)
{
    const int screenWidth = 1800;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "tela em branco");
    init_player  ();

    // Main game loop
    while (!WindowShouldClose())
    {
        player_position ();

        BeginDrawing();

            ClearBackground(WHITE);
            draw_player ();

        EndDrawing();

    }

    unload_player ();
    CloseWindow();     
   

    return 0;
}

