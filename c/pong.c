#include <raylib.h>

constexpr int width = 1280, height = 800;
typedef struct {
	int x, y;
} Vec2i;
typedef struct {
	double x, y;
} Vec2d;

Vec2i coordToRaylib (Vec2d a) {
	// something, probably a lerp
}

int main (void) {
	InitWindow(width, height, "pong");
	while (!WindowShouldClose()) {
		BeginDrawing();
		Vec2i ballPos = coordToRaylib((Vec2d){0});
		DrawCircle(ballPos.x, ballPos.y, 20, WHITE);
		EndDrawing();
	}
	CloseWindow();
}
