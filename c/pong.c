#include <raylib.h>

int main (void) {
	InitWindow(1280, 800, "pong");
	while (!WindowShouldClose()) {
		BeginDrawing();
		EndDrawing();
	}
	CloseWindow();
}
