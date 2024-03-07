#include "raylib.h"
#include "raymath.h"

int main(void)
{
    const int screenWidth = 1800;
    const int screenHeight = 1000;
    Vector2 position = { 350.0f, 280.0f };

    InitWindow(screenWidth, screenHeight, "tela em branco");
    Texture2D main_charac = LoadTexture("assets/Characters/Anomaly_anim.png");
    
    Rectangle frameRec = { 0.0f, (float) main_charac.height/5, (float) main_charac.width/7, (float) main_charac.height/5 };
    Rectangle frameRec2 = { 0.0f, 0.0f, 900, 500};
    int currentFrame = 0;

    int framesCounter = 0, flag = 0;
    int framesSpeed = 6;            // Number of spritesheet frames shown by second
    SetTargetFPS(60);  


    // Main game loop
    while (!WindowShouldClose())
    {
        
         framesCounter++;

        if (framesCounter >= (60/framesSpeed))
        {
            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 6) currentFrame = 0;

            frameRec.x = (float)currentFrame*(float)main_charac.width/7;
        }
        
        if (IsKeyDown(KEY_W)) position.y += 3;
        else if (IsKeyDown(KEY_S)) position.y -= 3;
        else if (IsKeyDown(KEY_A)) {position.x += 3; flag = 1;}
        else if (IsKeyDown(KEY_D)) {position.x -= 3; flag = 0;}

        BeginDrawing();

            ClearBackground(WHITE);
            if (flag == 1 && frameRec.width > 0)
            {
                frameRec.width *= -1;
            }
            else if (flag == 0 && frameRec.width < 0)
            {
                frameRec.width *= -1;
            }
    DrawTexturePro(main_charac, frameRec, frameRec2, position, 0, WHITE); 
        EndDrawing();

    }

    UnloadTexture (main_charac);
    CloseWindow();     
   

    return 0;
}

