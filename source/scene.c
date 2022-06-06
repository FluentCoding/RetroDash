#include "scene.h"

#include "player.h"
#include "ground.h"

#include "groundbmp_bin.h"

u32 x_pos, y_pos; // current camera position
Ground* ground;
Player* player;

u8 current_speed = 2;

void initScene(void) {
    ground = createGround();
    player = createPlayer();
}

// Executes every frame
void renderScene(u32 frame) {
    moveGround(ground, current_speed);

    x_pos++; // endless scrolling
}