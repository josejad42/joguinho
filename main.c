#include "raylib.h"
#include "raymath.h"
#include "enemy.h"


int main(void){
    const int screenWidth = 1800;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "tela em branco");

    init_enemy();

    // Main game loop
    while (!WindowShouldClose()){

        mov_enemy();

        BeginDrawing();

            ClearBackground(WHITE);
            draw_enemy();

        EndDrawing();

    }

    unload_enemy();
    CloseWindow();     

    return 0;
}

