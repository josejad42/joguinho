#include "raylib.h"
#include "raymath.h"
#include "Mike.h"

int main(void)
{
    const int screenWidth = 1800;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "tela em branco");
    init_Mike ();

    // Main game loop
    while (!WindowShouldClose())
    {
        Mike_position ();

        BeginDrawing();

            ClearBackground(WHITE);
            draw_Mike ();

        EndDrawing();

    }

    unload_Mike ();
    CloseWindow();     
   

    return 0;
}

