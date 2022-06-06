#include "tiledbg.h"

#define CEILING_POS(X) ((X-(int)(X)) > 0 ? (int)(X+1) : (int)(X))
#define FOREACH_GAMEOBJECT for (u8 i = 0; i < self->amount; i++)

#define SCREEN_WIDTH 256
#define SCREEN_HEIGHT 192

TiledBackground *createTiledBackgroundFromImage(TBGInit init, void* image_content) {
    // e.g. if two sprites fill up the screen completely and the screen moves a bit to the right, 3 sprites have to be rendered
    // so adding another potential sprite is important
    // this is only for horizontal moving tiled backgrounds at the moment
    const u8 spriteAmount = CEILING_POS(SCREEN_WIDTH / (float)init.sizeX) + 1;

    GameObject* gameObjects[spriteAmount];

    NE_Material* mat = NE_MaterialCreate();
	NE_MaterialTexLoadBMPtoRGBA(mat, image_content, 0);

    // Initialise each game sprite so that they are positioned next to each other
    GOInit gsInit = { .x = init.x, .y = init.y, .sizeX = init.sizeX, .sizeY = init.sizeY };
    for (u8 i = 0; i < spriteAmount; i++) {
        gameObjects[i] = createGameObjectFromMaterial(gsInit, mat); // TODO shared ne_material
        gsInit.x += gsInit.sizeX;
    }

    CONSTRUCT_STRUCT_ADDITIONAL_SPACE(TiledBackground, tiledBackground, sizeof(*gameObjects));
    tiledBackground->amount = spriteAmount;
    tiledBackground->sizeX = init.sizeX;
    swiFastCopy(gameObjects, tiledBackground->gameObjects, sizeof gameObjects); // TODO figure out if it is any faster than memcpy

    return tiledBackground;
}

void scrollTiledBackground(TiledBackground* self, s8 right) {
    self->lastX += right;

    s16 newX = (self->lastX % self->sizeX) - self->sizeX;
    FOREACH_GAMEOBJECT {
        NE_Sprite* current = self->gameObjects[i]->ne_sprite;
        NE_SpriteSetPos(current, newX + (i * self->sizeX), current->y);
    }
}

void colorTiledBackground(TiledBackground* self, u32 color) {
    FOREACH_GAMEOBJECT {
        NE_Sprite* current = self->gameObjects[i]->ne_sprite;
        NE_SpriteSetParams(current, current->alpha, current->id, color);
    }
}