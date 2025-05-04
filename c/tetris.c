#include <raylib.h>

int main (void) {
	InitWindow(0, 0, "tetris");
	while(!WindowShouldClose()) {
		BeginDrawing();
		EndDrawing();
	}
	CloseWindow();
}
