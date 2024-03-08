#include "raylib.h"
#include "raymath.h"
#include "player.h"
#define ScreenHeight 250
#define ScreenWidth 1800

Player player;

void init_player ()
{
    player.run = LoadTexture ("assets/player/Run.png");
    player.attack = LoadTexture ("assets/player/Attack 1.png");
    player.jump = LoadTexture ("assets/player/Jump.png");
    player.position = (Vector2) {-900, -500};
    player.frameRec = (Rectangle) {0.0f, 0.0f, player.run.width/7, player.run.height};
    player.frameRec2 = (Rectangle) {0.0f, 0.0f, player.run.width/7, player.run.height};
    player.frameRec3 = (Rectangle) {0.0f, 0.0f, player.attack.width/5, player.attack.height};
    player.frameRec4 = (Rectangle) {0.0f, 0.0f, player.jump.width/6, player.jump.height};

    player.currentFrame = 0;
    player.framesCounter = 0;
    player.flag = 0;
    player.framesSpeed = 2;            
}

void player_jumping (Vector2 initialPosition)
{
    player.position.y = initialPosition.y;
}

void player_position ()
{
    if (player.framesCounter >= (60/player.framesSpeed))
    {
        player.framesCounter = 0;
        player.currentFrame++;

        if (player.currentFrame > 6) player.currentFrame = 0;

        player.frameRec.x = (float) player.currentFrame * (float) player.run.width/7;
    }
        
    if (IsKeyDown(KEY_W)) 
    {
        player.position.y < 0 ? player.position.y += 1 : player.position.y; 
        player.framesCounter++;
        player.parado = 0;
    }
    else if (IsKeyDown(KEY_S)) 
    {
        player.position.y > -770 ? player.position.y -= 1 : player.position.y;
        player.framesCounter++;
        player.parado = 0;
    }
    else if (IsKeyDown(KEY_A)) 
    {
        if (IsKeyDown(KEY_D)) player.parado = 1;
        else 
        {
            player.position.x < 0 ? player.position.x += 1 : player.position.x;
            player.flag = 1;
            player.framesCounter++;
            player.parado = 0;
        }
    }
    else if (IsKeyDown(KEY_D)) 
    {
        if (IsKeyDown(KEY_A)) player.parado = 1;
        else 
        {
            player.position.x > -1700 ? player.position.x -= 1 : player.position.x;
            player.flag = 0; 
            player.framesCounter++;
            player.parado = 0;
        }
    }
    else if (IsKeyDown (KEY_SPACE)) player_jumping (player.position);
    else
    {
        player.parado = 1;
        player.framesCounter = 0;
    }

    if (player.flag == 1 && player.frameRec.width > 0) 
    {
        player.frameRec.width *= -1;
        player.frameRec3.width *= -1;
    }
    else if (player.flag == 0 && player.frameRec.width < 0) 
    {
        player.frameRec.width *= -1;
        player.frameRec3.width *= -1;
    }
}

void draw_player ()
{
    //DrawText (TextFormat("PosY: %03.0f\nPosX: %03.0f", position.y, position.x), 100, 800, 20, RED);
    if (player.parado == 0)DrawTexturePro(player.run, player.frameRec, player.frameRec2, player.position, 0, WHITE);
    else DrawTexturePro(player.attack, player.frameRec3, player.frameRec2, player.position, 0, WHITE);
}

void unload_player ()
{
    UnloadTexture (player.run);
    UnloadTexture (player.attack);
}
