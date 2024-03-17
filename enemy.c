#include "raylib.h"
#include "raymath.h"
#include "enemy.h"
#include "player.h"

Enemy1 inimigo;

void init_enemy(){
    inimigo.position = (Vector2) {1000, 295};
    Image enemy_image = LoadImage("assets/lobocorrendo.png");
    ImageResize(&enemy_image, 1700, 200);
    inimigo.img = LoadTextureFromImage(enemy_image);
    inimigo.size = (Vector2) {100, 150};
 
    inimigo.currentFrame = 0;
    inimigo.framesCounter = 0;
    inimigo.framesSpeed = 10;
    inimigo.frameRec = (Rectangle) {0.0f, 0.0f, (float)inimigo.img.width/11, (float)inimigo.img.height };
    inimigo.img.width*=-1;


}

void mov_enemy(){
     inimigo.framesCounter++;
        if (inimigo.framesCounter >= (60/inimigo.framesSpeed)){
            inimigo.framesCounter = 0;
            inimigo.currentFrame++;

            if (inimigo.currentFrame > 5) inimigo.currentFrame = 0;

            inimigo.frameRec.x = (float) inimigo.currentFrame*(float)inimigo.img.width/11;
        }

        inimigo.position.x -= 2;
        if (inimigo.position.x <= -20){ 
            inimigo.position.x = 1000;
        }
        inimigo.box_enemy = (Rectangle) {inimigo.position.x+30, inimigo.position.y+50, inimigo.size.x, inimigo.size.y };
        
}

void atk_enemy(){
    Image atk = LoadImage("assets/lobo_atk.png");
    ImageResize(&atk, 1700, 200);
    inimigo.img = LoadTextureFromImage(atk);
    
}

void draw_enemy(){
    DrawTextureRec(inimigo.img, inimigo.frameRec, inimigo.position, WHITE);
    DrawRectangleRec(inimigo.box_enemy,RED);
}

void unload_enemy(){
    UnloadTexture(inimigo.img);
}