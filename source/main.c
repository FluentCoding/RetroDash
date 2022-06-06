// 256 x 192

#include <NEMain.h>
#include <nds.h>

#include "scene.h"

#define FPS 60

void Draw3DScene(void)
{
	NE_2DViewInit();
	NE_SpriteDrawAll();
}

int main()
{
	irqEnable(IRQ_HBLANK);
	irqSet(IRQ_VBLANK, NE_VBLFunc);
	irqSet(IRQ_HBLANK, NE_HBLFunc);

	NE_ClearColorSet(NE_Black, 31, 63);
	NE_Init3D();

	// DEBUG CONFIGURATIONS
	NE_TextureSystemReset(0, 0, NE_VRAM_AB);
	// Init console in non-3D screen
	consoleDemoInit();
	initScene();
	u32 frame = 0; // we assume 60FPS

	while(1) {
		/*scanKeys();
		uint32 keys = keysHeld();

		if (keys & KEY_A) {
			switchColor();
		}*/

		renderScene(frame);

		NE_Process(Draw3DScene);
		NE_WaitForVBL(0);

		frame++;
	}

	return 0;
}