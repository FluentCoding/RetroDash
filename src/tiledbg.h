#ifndef TILEDBG_H
#define TILEDBG_H

#include "gameobject.h"
#include "classutil.h"

typedef struct {
    u8 amount;
    u8 sizeX;
    u32 lastX;
    GameObject** gameObjects; // array of game object pointers
} TiledBackground;

typedef struct {
    int x, y;
    int sizeX, sizeY;
} TBGInit;

TiledBackground *createTiledBackgroundFromImage(TBGInit init, void* image_content);
void scrollTiledBackground(TiledBackground* self, s8 x);
void colorTiledBackground(TiledBackground* self, u32 color);
DESTROY_METHOD(TiledBackground);

#endif