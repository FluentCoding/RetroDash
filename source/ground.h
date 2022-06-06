#ifndef GROUND_H
#define GROUND_H

#include "tiledbg.h"
#include "classutil.h"

#define GROUND_SIZE 64
#define GROUND_Y 192 - (GROUND_SIZE / 2)

typedef struct {
    TiledBackground* tiledBackground;
} Ground;

Ground *createGround(void);
void moveGround(Ground* self, s8 x);
DESTROY_METHOD(Ground);

#endif