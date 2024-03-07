#include "raylib.h"
#include "raymath.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "tela em branco");



    // Main game loop
    while (!WindowShouldClose())
    {

        BeginDrawing();

            ClearBackground(WHITE);

        EndDrawing();

    }

   
    CloseWindow();     
   

    return 0;
}

