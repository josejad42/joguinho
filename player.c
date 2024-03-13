#include "raylib.h"
#include "raymath.h"
#include "player.h"
#define StandardDesloc 5
#define gravity 21000
#define V0jump 1500
#define Vxjump 2
#define qtdFramesHor 20
#define qtdFramesVer 25
#define X0 -850
#define Y0 -450

Player player; 

void init_player ()
{
    player.texture = LoadTexture ("assets/player/SpearWoman.png");
    player.position = (Vector2) {X0, Y0};
    player.frameRec[0] = (Rectangle) {0.0f, 2 * player.texture.height/qtdFramesVer, player.texture.width/qtdFramesHor, player.texture.height/qtdFramesVer}; //Run
    player.frameRec[1] = (Rectangle) {0.0f, 0.0f, 3 * player.texture.width/qtdFramesHor, 3 * player.texture.height/qtdFramesVer}; //Tamanho dos quadros
    player.frameRec[2] = (Rectangle) {0.0f, 0.0f, player.texture.width/qtdFramesHor, player.texture.height/qtdFramesVer}; //Idle
    player.frameRec[3] = (Rectangle) {0.0f, 6 * player.texture.height/qtdFramesVer, player.texture.width/qtdFramesVer, player.texture.height/qtdFramesVer}; //Jump

    player.currentFrame = 0;
    player.framesCounter = 0;
    player.flag = 0; //flag do sentido do player (0 = direita; 1 = esquerda)
    player.framesSpeed = 20;
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
        if (player.pulando == 0 && player.parado == 0)
        {
            if (player.currentFrame > 7) player.currentFrame = 0;

            player.frameRec[0].x = (float) player.currentFrame * (float) player.texture.width/qtdFramesHor;
        }
        else if (player.pulando == 1)
        {
           if (player.currentFrame > 2) player.currentFrame = 0;

            player.frameRec[3].x = (float) player.currentFrame * (float) player.texture.width/qtdFramesHor; 
        }
        else
        {
            if (player.currentFrame > 3) player.currentFrame = 0;

            player.frameRec[2].x = (float) player.currentFrame * (float) player.texture.width/qtdFramesHor;
        }
    }
    if (IsKeyDown (KEY_SPACE) && player.pulando == 0) 
    {
        player.pulando = 1;
        player.framesCounter = 0;
        player.currentFrame = 0;
        player.framesSpeed = 20;
    }
    if (IsKeyDown(KEY_A)) 
    {
        player.framesSpeed = 20;
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
        player.framesSpeed = 20;
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
        player.framesCounter++;
        player.framesSpeed = 7;
    }
    

    if (player.pulando == 1)
    {   
        player.framesCounter++;
        //player.parado = 1;
        tempo++;
        player.position.y = Y0 + V0jump*tempo/500 - (gravity * tempo * tempo) / 500000;
        if (player.position.y <= Y0 - 1)
        {
            player.position.y = Y0;
            player.pulando = 0;
            player.currentFrame = 0;
            tempo = 0;
        }
    }

    if (player.flag == 1 && player.frameRec[0].width > 0) 
    {
        player.frameRec[0].width *= -1;
        player.frameRec[2].width *= -1;
        player.frameRec[3].width *= -1;
    }
    else if (player.flag == 0 && player.frameRec[0].width < 0) 
    {
        player.frameRec[0].width *= -1;
        player.frameRec[2].width *= -1;
        player.frameRec[3].width *= -1;
    }
}

void draw_player ()
{
    DrawText (TextFormat("PosY: %03.0f\nPosX: %03.0f", player.position.y, player.position.x), 30, 300, 20, RED);
   // DrawText (TextFormat("entre no else if %d vezes", cnt), 30, 200, 20, RED);
    if (player.parado == 0 && player.pulando == 0)DrawTexturePro(player.texture, player.frameRec[0], player.frameRec[1], player.position, 0, WHITE);
    else if (player.pulando == 0) DrawTexturePro(player.texture, player.frameRec[2], player.frameRec[1], player.position, 0, WHITE);
    else DrawTexturePro(player.texture, player.frameRec[3], player.frameRec[1], player.position, 0, WHITE);
}

void unload_player ()
{
    UnloadTexture (player.texture);
}