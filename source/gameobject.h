#ifndef GameObject_H
#define GameObject_H

#include "NEMain.h"
#include "classutil.h"

typedef struct {
    NE_Sprite* ne_sprite;
    NE_Material* ne_material;
} GameObject;

typedef struct {
    int x, y;
    int sizeX, sizeY;
} GOInit;

// GameObject *createGameObject(GSInit init);
GameObject *createGameObjectFromImage(GOInit init, void* image_content);
GameObject *createGameObjectFromMaterial(GOInit init, NE_Material* material);
DESTROY_METHOD(GameObject);

#endif