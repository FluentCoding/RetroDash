#include "player.h"
#include "ground.h"
#include "cubebmp_bin.h"

#define PLAYER_SIZE 20

Player* createPlayer(void) {
    CONSTRUCT_STRUCT(Player, player);

    GOInit player_init = {
        .x = 50,
        .y = GROUND_Y - PLAYER_SIZE,
        .sizeX = PLAYER_SIZE,
        .sizeY = PLAYER_SIZE
    };
    player->gameObject = createGameObjectFromImage(player_init, (void*) cubebmp_bin);

    return player;
}
