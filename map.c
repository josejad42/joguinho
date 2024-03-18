#include "raylib.h"
#include "raymath.h"
#include "map.h"

Texture2D clouds01, clouds02, foregound, light, middleground, moon, caminho, caminho01, caminho02;
float movcloud01, movcloud02, movforegound, movlight, movmidlleground, movmoon, movcaminho, movcaminho01, movcaminho02;

void init_map()
{
    clouds01 = LoadTexture("assets/Assets/clouds_01.png"); 
    clouds02 = LoadTexture("assets/Assets/clouds_02.png");
    foregound = LoadTexture("assets/Assets/foregound.png");
    light = LoadTexture("assets/Assets/light.png");
    middleground = LoadTexture("assets/Assets/middleground.png");
    moon = LoadTexture("assets/Assets/moon.png");
    caminho = LoadTexture("assets/Assets/caminho.png");
    caminho01 = LoadTexture("assets/Assets/caminho1.png");
    caminho02 = LoadTexture("assets/Assets/caminho2.png");


    movcloud01 = 0.0f;
    movcloud02 = 0.0f;
    movforegound = .0f;
    movlight = 0.0f;
    movmidlleground = 0.0f;
    movmoon = 0.0f;
    movcaminho = 0.0f;
    movcaminho01 = 0.0f;
    movcaminho02 = 0.0f;

}

void map_positioning()
{
    //altera velocidade das texturas 

    movcloud01 -= 0.7f;
    movcloud02 -= 0.5f;
    movforegound -= 0.5f;
    movlight -= 0.1f;
    movmidlleground -= 0.5f;
    movmoon -= 0.5f;
    movcaminho -= 0.7f;
    movcaminho01 -= 0.7;
    movcaminho02 -= 0.7;

    
        
    // reinicia a textura
    if (movcloud01 <= -clouds01.width*2) movcloud01 = 0;
    if (movcloud02 <= -clouds02.width*2) movcloud02 = 0;
    if (movforegound <= -foregound.width*2) movforegound = 0;
    if (movlight <= -light.width*1) movlight = 0;
    if (movmidlleground <= -middleground.width*2) movmidlleground = 0; 
    if (movmoon <= -moon.width*10) movmoon = 0;
    if (movcaminho <= -caminho.width*18) movcaminho= 0;
    if (movcaminho01 <= -caminho01.width*18) movcaminho01 = 0;
    if (movcaminho02 <= -caminho02.width*18) movcaminho02 = 0;

    
}

void draw_map()
{
    DrawTextureEx(clouds02, (Vector2){ movcloud02, 0 }, 0.0f, 2.5f, WHITE);
    DrawTextureEx(clouds02, (Vector2){ clouds02.width*2.5 + movcloud02, 0 }, 0.0f, 2.5f, WHITE);

    DrawTextureEx(moon, (Vector2){ movmoon, 10 }, 0.0f, 2.0f, WHITE);
    DrawTextureEx(moon, (Vector2){ moon.width*10 + movmoon, 10}, 0.0f, 2.0f, WHITE);

    DrawTextureEx(clouds01, (Vector2){ movcloud01, 0}, 0.0f, 2.5f, WHITE);
    DrawTextureEx(clouds01, (Vector2){ clouds01.width*2.5 + movcloud01, 0}, 0.0f, 2.5f, WHITE);


    DrawTextureEx(light, (Vector2){ movlight, 0 }, 0.0f, 2.0f, WHITE);
    DrawTextureEx(light, (Vector2){ light.width*2 + movlight, 0 }, 0.0f, 2.0f, WHITE);


    DrawTextureEx(middleground, (Vector2){ movmidlleground, 150 }, 0.0f, 2.5f, WHITE);
    DrawTextureEx(middleground, (Vector2){ middleground.width*2.5 + movmidlleground, 150 }, 0.0f, 2.5f, WHITE);

    DrawTextureEx(caminho, (Vector2){ caminho.width*2 + movcaminho, 380 }, 0.0f, 2.0f, WHITE);

    DrawTextureEx(caminho02, (Vector2){ ((caminho02.width*2 + caminho.width*2) -20 ) + movcaminho02, 390 }, 0.0f, 2.0f, WHITE);
    
    DrawTextureEx(caminho01, (Vector2){ ((caminho01.width*2 + caminho.width*2 + caminho02.width*2) -40 ) + movcaminho01, 380 }, 0.0f, 2.0f, WHITE);
    
   

    DrawTextureEx(foregound, (Vector2){ movforegound, 90 }, 0.0f, 2.5f, WHITE);
    DrawTextureEx(foregound, (Vector2){ foregound.width*2.5 + movforegound, 90 }, 0.0f, 2.5f, WHITE);

}

void unload_map()
{
    UnloadTexture(clouds01);
    UnloadTexture(clouds02);
    UnloadTexture(foregound);
    UnloadTexture(light);
    UnloadTexture(middleground);
    UnloadTexture(moon);
    UnloadTexture(caminho);
    UnloadTexture(caminho01);
    UnloadTexture(caminho02);

}
