#ifndef _PLAYER_H
#define _PLAYER_H

typedef struct
{
    Texture2D run, attack, jump;
    Vector2 position;
    Rectangle frameRec, frameRec2, frameRec3, frameRec4;
    int currentFrame, framesCounter, flag, parado, pulando;
    float framesSpeed;
} Player;

void init_player ();
void player_position ();
void draw_player ();
void unload_player ();

#endif
