#ifndef PLAYER_H
#define PLAYER_H

#include "gameobject.h"
#include "classutil.h"

typedef struct {
    GameObject* gameObject;
} Player;

Player *createPlayer(void);
DESTROY_METHOD(Player);

#endif