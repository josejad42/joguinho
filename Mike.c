#include "raylib.h"
#include "raymath.h"
#include "Mike.h"


    Texture2D main_charac;
    Vector2 position;
        
    Rectangle frameRec, frameRec2;
    int currentFrame = 0, framesCounter = 0, flag = 0, framesSpeed = 6;

void init_Mike ()
{
    main_charac = LoadTexture("assets/Characters/Anomaly_anim.png");
    position = (Vector2) { 350.0f, 280.0f };
        
    frameRec = (Rectangle) { 0.0f, main_charac.height/5, main_charac.width/7, main_charac.height/5 };
    frameRec2 = (Rectangle) { 0.0f, 0.0f, 900, 500};
    currentFrame = 0;

    framesCounter = 0;
    flag = 0;
    framesSpeed = 2;            // Number of spritesheet frames shown by second
}

void Mike_position ()
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

        if (flag == 1 && frameRec.width > 0) frameRec.width *= -1;
        else if (flag == 0 && frameRec.width < 0) frameRec.width *= -1;
}

void draw_Mike ()
{
    DrawTexturePro(main_charac, frameRec, frameRec2, position, 0, WHITE);
}

void unload_Mike ()
{
    UnloadTexture (main_charac);
}
