#include "raylib.h"
#include "raymath.h"
#include "player.h"
#include "enemy.h"
#define StandardFrameSpeed 15
#define StandardDesloc 5
#define gravity 21000
#define V0yjump 1500
#define Vxjump 2
#define qtdFramesHor 20
#define qtdFramesVer 25
#define X0 -450
#define Y0 -200
#define parado 0
#define correndo 1
#define pulando 2
#define atacando 3

Player player; 

void init_player ()
{
    player.texture = LoadTexture ("assets/player/SpearWoman.png");
    player.position = (Vector2) {X0, Y0};
    player.frameRec[0] = (Rectangle) {0.0f, 2 * player.texture.height/qtdFramesVer, player.texture.width/qtdFramesHor, player.texture.height/qtdFramesVer}; //Run
    player.frameRec[1] = (Rectangle) {0.0f, 0.0f, 3 * player.texture.width/qtdFramesHor, 3 * player.texture.height/qtdFramesVer}; //Tamanho dos quadros
    player.frameRec[2] = (Rectangle) {0.0f, 0.0f, player.texture.width/qtdFramesHor, player.texture.height/qtdFramesVer}; //Idle
    player.frameRec[3] = (Rectangle) {0.0f, 6 * player.texture.height/qtdFramesVer, player.texture.width/qtdFramesVer, player.texture.height/qtdFramesVer}; //Jump
    player.frameRec[4] = (Rectangle) {0.0f, 12 * player.texture.height/qtdFramesVer, player.texture.width/qtdFramesHor, player.texture.height/qtdFramesVer}; //Attack

    player.currentFrame = 0;
    player.framesCounter = 0;
    player.flag = 0; //flag do sentido do player (0 = direita; 1 = esquerda)
    player.framesSpeed = StandardFrameSpeed;
    player.state = parado;            
    player.size = (Vector2) {100, 150};
}

int tempo = 0, teste = 0;

void player_positioning ()
{
    player.framesCounter++;
    if (player.framesCounter >= (60/player.framesSpeed))
    {
        player.framesCounter = 0;
        player.currentFrame++;
        if (player.state == correndo)
        {
            if (player.currentFrame > 7) player.currentFrame = 0;

            player.frameRec[0].x = (float) player.currentFrame * (float) player.texture.width/qtdFramesHor;
        }
        else if (player.state == pulando)
        {
           if (player.currentFrame > 2) player.currentFrame = 0;

            player.frameRec[3].x = (float) player.currentFrame * (float) player.texture.width/qtdFramesHor; 
        }
        else if (player.state == atacando)
        {
            if (player.currentFrame <= 5)
            {
                player.frameRec[4].x = (float) player.currentFrame * (float) player.texture.width/qtdFramesHor; 
            }
            else if (IsKeyUp(KEY_Q))
            {
                teste = 1;
                player.state = parado;
                player.currentFrame = 0;
            }

        }
        else
        {
            if (player.currentFrame > 3) player.currentFrame = 0;

            player.frameRec[2].x = (float) player.currentFrame * (float) player.texture.width/qtdFramesHor;
        }
    }

    if (IsKeyDown (KEY_SPACE) && player.state != pulando) 
    {
        player.state = pulando;
        player.framesCounter = 0;
        player.currentFrame = 0;
        player.framesSpeed = StandardFrameSpeed;
    }
    if (IsKeyDown(KEY_A)) 
    {
        player.framesSpeed = StandardFrameSpeed;
        if (IsKeyDown(KEY_D) && player.state != pulando) player.state = parado;
        else 
        {
            if (player.state == pulando) player.position.x += Vxjump; 
            else 
            {
                player.position.x += StandardDesloc;
                player.state = correndo;
            }

            player.flag = 1;
            //player.state = correndo;
        }
    }
    else if (IsKeyDown(KEY_D)) 
    {
        player.framesSpeed = StandardFrameSpeed;
        if (IsKeyDown(KEY_A) && player.state != pulando) player.state = parado;
        else 
        {
            if (player.state == pulando) player.position.x -= Vxjump; 
            else 
            {
                player.position.x -= StandardDesloc;
                player.state = correndo;
            }

            player.flag = 0; 
            //player.state = correndo;
        }
    }
    else if (IsKeyDown(KEY_Q) && player.state != pulando && player.state != atacando)
    {
        player.framesSpeed = 9;
        player.state = atacando;
        player.currentFrame = 0;
        teste = 0;
    }
    else if (player.state != pulando && player.state != atacando)
    {

        player.state = parado;
        player.framesSpeed = 7;
    }
    

    if (player.state == pulando)
    {   
        //player.parado = 1;
        tempo++;
        player.position.y = Y0 + V0yjump*tempo/500 - (gravity * tempo * tempo) / 500000;
        if (player.position.y <= Y0 - 1)
        {
            player.position.y = Y0;
            player.currentFrame = 0;
            tempo = 0;
            if (!IsKeyDown(KEY_SPACE)) player.state = parado;
        }
    }

    if (player.flag == 1 && player.frameRec[0].width > 0) 
    {
        player.frameRec[0].width *= -1;
        player.frameRec[2].width *= -1;
        player.frameRec[3].width *= -1;
        player.frameRec[4].width *= -1;
    }
    else if (player.flag == 0 && player.frameRec[0].width < 0) 
    {
        player.frameRec[0].width *= -1;
        player.frameRec[2].width *= -1;
        player.frameRec[3].width *= -1;
        player.frameRec[4].width *= -1;
    }
    if (player.flag == 0) player.box_player = (Rectangle) {-1 * player.position.x + player.texture.width/qtdFramesHor, -1 * player.position.y + player.texture.height/qtdFramesVer + 30, player.size.x - 20,  player.size.y};
    else player.box_player = (Rectangle) {-1 * player.position.x + player.texture.width/qtdFramesHor + 50, -1 * player.position.y + player.texture.height/qtdFramesVer + 30, player.size.x - 20,  player.size.y};

}

void draw_player ()
{
    DrawText (TextFormat("PosY: %03.0f\nPosX: %03.0f", player.position.y, player.position.x), 30, 300, 20, RED);
    //if (teste == 1) DrawText (TextFormat("entrei no else if"), 30, 200, 20, RED);
    if(inimigo.colisao){
        if (player.state == correndo) DrawTexturePro(player.texture, player.frameRec[0], player.frameRec[1], player.position, 0, RED);
        else if (player.state == parado) DrawTexturePro(player.texture, player.frameRec[2], player.frameRec[1], player.position, 0, RED);
        else if (player.state == atacando) DrawTexturePro(player.texture, player.frameRec[4], player.frameRec[1], player.position, 0, RED);
        else DrawTexturePro(player.texture, player.frameRec[3], player.frameRec[1], player.position, 0, RED);
    } else{
        if (player.state == correndo) DrawTexturePro(player.texture, player.frameRec[0], player.frameRec[1], player.position, 0, WHITE);
        else if (player.state == parado) DrawTexturePro(player.texture, player.frameRec[2], player.frameRec[1], player.position, 0, WHITE);
        else if (player.state == atacando) DrawTexturePro(player.texture, player.frameRec[4], player.frameRec[1], player.position, 0, WHITE);
        else DrawTexturePro(player.texture, player.frameRec[3], player.frameRec[1], player.position, 0, WHITE);
    }
    //DrawRectangleRec(player.box_player,YELLOW);
    //DrawRectangleRec(inimigo.box_enemy,YELLOW);
}

void unload_player ()
{
    UnloadTexture (player.texture);
}