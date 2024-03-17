#ifndef _PLAYER_H
#define _PLAYER_H

typedef struct
{
    Texture2D texture;
    Vector2 position;
    Rectangle frameRec[5];
    int currentFrame, framesCounter, flag, state;
    float framesSpeed;
    Vector2 size;
    Rectangle box_player;
} Player;

extern Player player;

void init_player();
void player_positioning();
void draw_player();
void unload_player();

#endif