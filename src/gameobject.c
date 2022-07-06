#include "gameobject.h"

GameObject* createGameObject(GOInit init) {
    CONSTRUCT_STRUCT(GameObject, sprite);
    sprite->ne_sprite = NE_SpriteCreate();
	NE_SpriteSetPos(sprite->ne_sprite, init.x, init.y);
	NE_SpriteSetSize(sprite->ne_sprite, init.sizeX, init.sizeY);
	NE_SpriteSetPriority(sprite->ne_sprite, 0);
	// NE_SpriteSetMaterial(ne_sprite, Material);

    return sprite;
}

GameObject *createGameObjectFromImage(GOInit init, void* image_content) {
    GameObject* sprite = createGameObject(init);

    sprite->ne_material = NE_MaterialCreate();

	NE_MaterialTexLoadBMPtoRGBA(sprite->ne_material, image_content, 0);
    NE_SpriteSetMaterial(sprite->ne_sprite, sprite->ne_material);

    return sprite;
}

GameObject *createGameObjectFromMaterial(GOInit init, NE_Material* material) {
    GameObject* sprite = createGameObject(init);
    NE_SpriteSetMaterial(sprite->ne_sprite, material);

    return sprite;
}