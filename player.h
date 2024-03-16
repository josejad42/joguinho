#ifndef _PLAYER_H
#define _PLAYER_H

typedef struct
{
    Texture2D texture;
    Vector2 position;
    Rectangle frameRec[5];
    int currentFrame, framesCounter, flag, parado, pulando;
    float framesSpeed;
} Player;

void init_player();
void player_positioning();
void draw_player();
void unload_player();

#endif