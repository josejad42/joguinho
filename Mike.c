#include "raylib.h"
#include "raymath.h"
#include "Mike.h"
#define ScreenHeight 250
#define ScreenWidth 1800


    Texture2D Mike_run, Mike_attack, Mike_jump;
    Vector2 position;
        
    Rectangle frameRec, frameRec2, frameRec3, frameRec4;
    int currentFrame = 0, framesCounter = 0, flag = 0, framesSpeed = 6, parado = 1;

void init_Mike ()
{
    Mike_run = LoadTexture ("assets/Mike/Run.png");
    Mike_attack = LoadTexture ("assets/Mike/Attack 1.png");
    Mike_jump = LoadTexture ("assets/Mike/Jump.png");
    position = (Vector2) {-900, -500};
    frameRec = (Rectangle) {0.0f, 0.0f, Mike_run.width/7, Mike_run.height};
    frameRec2 = (Rectangle) {0.0f, 0.0f, Mike_run.width/7, Mike_run.height};
    frameRec3 = (Rectangle) {0.0f, 0.0f, Mike_attack.width/5, Mike_attack.height};
    frameRec4 = (Rectangle) {0.0f, 0.0f, Mike_jump.width/6, Mike_jump.height};

    currentFrame = 0;
    framesCounter = 0;
    flag = 0;
    framesSpeed = 1;            
}

void Mike_position ()
{
    if (framesCounter >= (60/framesSpeed))
    {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 6) currentFrame = 0;

        frameRec.x = (float) currentFrame * (float) Mike_run.width/7;
    }
        
    if (IsKeyDown(KEY_W)) 
    {
        position.y < 0 ? position.y += 1 : position.y; 
        framesCounter++;
        parado = 0;
    }
    else if (IsKeyDown(KEY_S)) 
    {
        position.y > -770 ? position.y -= 1 : position.y;
        framesCounter++;
        parado = 0;
    }
    else if (IsKeyDown(KEY_A)) 
    {
        if (IsKeyDown(KEY_D)) parado = 1;
        else 
        {
            position.x < 0 ? position.x += 1 : position.x;
            flag = 1;
            framesCounter++;
            parado = 0;
        }
    }
    else if (IsKeyDown(KEY_D)) 
    {
        if (IsKeyDown(KEY_A)) parado = 1;
        else 
        {
            position.x > -1700 ? position.x -= 1 : position.x;
            flag = 0; 
            framesCounter++;
            parado = 0;
        }
    }
    else if (IsKeyDown (KEY_SPACE))  ;
    else
    {
        parado = 1;
        framesCounter = 0;
    }

    if (flag == 1 && frameRec.width > 0) 
    {
        frameRec.width *= -1;
        frameRec3.width *= -1;
    }
    else if (flag == 0 && frameRec.width < 0) 
    {
        frameRec.width *= -1;
        frameRec3.width *= -1;
    }
}

void draw_Mike ()
{
    //DrawText (TextFormat("PosY: %03.0f\nPosX: %03.0f", position.y, position.x), 100, 800, 20, RED);
    if (parado == 0)DrawTexturePro(Mike_run, frameRec, frameRec2, position, 0, WHITE);
    else DrawTexturePro(Mike_attack, frameRec3, frameRec2, position, 0, WHITE);
}

void unload_Mike ()
{
    UnloadTexture (Mike_run);
    UnloadTexture (Mike_attack);
}
