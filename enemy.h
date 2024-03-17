#ifndef _ENEMY_H
#define _ENEMY_H

#include "raylib.h"

typedef struct {
    Vector2 position;
    float speed;
    Texture2D img;
    Rectangle frameRec;
    int currentFrame;
    int framesCounter;
    int framesSpeed;
} Enemy1;

extern Enemy1 inimigo;

void init_enemy ();
void mov_enemy ();
void draw_enemy ();
void unload_enemy ();
void atk_enemy ();
#endif