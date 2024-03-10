#include "raylib.h"
#include "raymath.h"
#include "player.h"
#define StandardFSpeed 1
#define StandardDesloc 1
#define gravity 600
#define V0jump 300 
#define Vxjump 0.2

Player player;

void init_player ()
{
    player.run = LoadTexture ("assets/player/Run.png");
    player.attack = LoadTexture ("assets/player/Attack 1.png");
    player.jump = LoadTexture ("assets/player/Jump.png");
    player.position = (Vector2) {-900, -500};
    player.frameRec = (Rectangle) {0.0f, 0.0f, player.run.width/7, player.run.height};
    player.frameRec2 = (Rectangle) {0.0f, 0.0f, 2*player.run.width/7, 2*player.run.height};
    player.frameRec3 = (Rectangle) {0.0f, 0.0f, player.attack.width/5, player.attack.height};
    player.frameRec4 = (Rectangle) {0.0f, 0.0f, player.jump.width/6, player.jump.height};

    player.currentFrame = 0;
    player.framesCounter = 0;
    player.flag = 0; //flag do sentido do player (0 = direita; 1 = esquerda)
    player.framesSpeed = StandardFSpeed;
    player.parado = 1;
    player.pulando = 0;            
}

int tempo = 0;

void player_position ()
{
    if (player.framesCounter >= (60/player.framesSpeed))
    {
        player.framesCounter = 0;
        player.currentFrame++;
        if (player.pulando == 0)
        {
            if (player.currentFrame > 6) player.currentFrame = 0;

            player.frameRec.x = (float) player.currentFrame * (float) player.run.width/7;
        }
        else
        {
           //if (player.currentFrame == 4) player.currentFrame++; 
           if (player.currentFrame > 3) player.currentFrame = 5;

            player.frameRec4.x = (float) player.currentFrame * (float) player.jump.width/6; 
        }
    }
        
    // if (IsKeyDown(KEY_W)) 
    // {
    //     player.position.y < 0 ? player.position.y += 1 : player.position.y; 
    //     player.framesCounter++;
    //     player.parado = 0;
    // }
    // else if (IsKeyDown(KEY_S)) 
    // {
    //     player.position.y > -770 ? player.position.y -= 1 : player.position.y;
    //     player.framesCounter++;
    //     player.parado = 0;
    // }
    if (IsKeyDown (KEY_SPACE) && player.pulando == 0) 
    {
        player.pulando = 1;
        player.framesCounter = 0;
        player.currentFrame = 0;
        player.framesSpeed = 0.8;
    }
    if (IsKeyDown(KEY_A)) 
    {
        if (IsKeyDown(KEY_D)) player.parado = 1;
        else 
        {
            if (player.pulando) player.position.x += Vxjump; 
            else 
            {
                player.position.x += StandardDesloc;
                player.framesCounter++;
            }

            player.flag = 1;
            player.parado = 0;
        }
    }
    else if (IsKeyDown(KEY_D)) 
    {
        if (IsKeyDown(KEY_A)) player.parado = 1;
        else 
        {
            if (player.pulando) player.position.x -= Vxjump; 
            else 
            {
                player.position.x -= StandardDesloc;
                player.framesCounter++;
            }

            player.flag = 0; 
            player.parado = 0;
        }
    }
    else if (player.pulando == 0)
    {
        player.parado = 1;
        player.framesCounter = 0;
        player.currentFrame = 0;
    }
    

    if (player.pulando == 1)
    {   
        player.framesCounter++;
        player.parado = 1;
        tempo++;
        player.position.y = -500 + V0jump*tempo/500 - (gravity * tempo * tempo) / 500000;
        if (player.position.y <= -501)
        {
            player.position.y = -500;
            player.pulando = 0;
            player.framesSpeed = StandardFSpeed;
            player.currentFrame = 0;
            tempo = 0;
        }
    }

    if (player.flag == 1 && player.frameRec.width > 0) 
    {
        player.frameRec.width *= -1;
        player.frameRec3.width *= -1;
        player.frameRec4.width *= -1;
    }
    else if (player.flag == 0 && player.frameRec.width < 0) 
    {
        player.frameRec.width *= -1;
        player.frameRec3.width *= -1;
        player.frameRec4.width *= -1;
    }
}

void draw_player ()
{
    DrawText (TextFormat("PosY: %03.0f\nPosX: %03.0f", player.position.y, player.position.x), 100, 800, 20, RED);
   // DrawText (TextFormat("entre no else if %d vezes", cnt), 100, 700, 20, RED);
    if (player.parado == 0 && player.pulando == 0)DrawTexturePro(player.run, player.frameRec, player.frameRec2, player.position, 0, WHITE);
    else if (player.pulando == 0) DrawTexturePro(player.attack, player.frameRec3, player.frameRec2, player.position, 0, WHITE);
    else DrawTexturePro(player.jump, player.frameRec4, player.frameRec2, player.position, 0, WHITE);
}

void unload_player ()
{
    UnloadTexture (player.run);
    UnloadTexture (player.attack);
}