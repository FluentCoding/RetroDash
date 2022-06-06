#include "ground.h"
#include "groundbmp_bin.h"
#include "color.h"

Ground* createGround(void) {
    CONSTRUCT_STRUCT(Ground, ground);

    TBGInit init = { .x = 0, .y = GROUND_Y, .sizeX = GROUND_SIZE, .sizeY = GROUND_SIZE };
    ground->tiledBackground = createTiledBackgroundFromImage(init, (void*) groundbmp_bin);
    colorTiledBackground(ground->tiledBackground, RGB(47,131,255));

    return ground;
}

void moveGround(Ground* self, s8 right) {
    scrollTiledBackground(self->tiledBackground, -right);
}