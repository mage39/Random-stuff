#include <raylib.h>
// this is so overengineered, trash it
static constexpr int width = 1280;
static constexpr int height = 800;
typedef struct {
	int x, y;
} Vec2i;
typedef struct {
	double x, y;
} Vec2d;

static Vec2i coordLerp (Vec2d a) {
	a = (Vec2d){a.x * 0.5 + 0.5, a.y * 0.5 + 0.5};
	return (Vec2i){a.x * width, a.y * height};
}
static Rectangle makeRect (Vec2d pos, Vec2d rect) {
	Vec2i posi = coordLerp(pos);
	Vec2i recti = coordLerp(rect);
	return (Rectangle){posi.x, posi.y, recti.x, recti.y};
}
static Rectangle makeCenterRect(Vec2d pos, Vec2d rect) {
	// if (pos.x > 0) 
	rect.x = pos.x + rect.x * 0.5;
	// else rect.x = pos.x + rect.x * 0.5;
	// if (pos.y > 0)
	rect.y = pos.y + rect.y * 0.5;
	// else rect.y = pos.y + rect.y * 0.5;
	return makeRect(pos, rect);
}
static void drawLine (Vec2d start, Vec2d end, Color color) {
	Vec2i line[2] = {coordLerp(start), coordLerp(end)};
	DrawLine(line[0].x, line[0].y, line[1].x, line[1].y, color);
}

int main (void) {
	InitWindow(width, height, "pong");
	while (!WindowShouldClose()) {
		BeginDrawing();
		Vec2i ballPos = coordLerp((Vec2d){0});
		drawLine((Vec2d){0, 1}, (Vec2d){0, -1}, WHITE);
		Rectangle borders = makeRect((Vec2d){-1, -1}, (Vec2d){1, 1});
		DrawRectangleLinesEx(borders, 1, WHITE);

		// this block don't work, no idea why
		Rectangle paddleAI = makeCenterRect((Vec2d){0, .5}, (Vec2d){.002, .005});
		DrawRectangleRec(paddleAI, RED);

		DrawCircle(ballPos.x, ballPos.y, 20, WHITE);
		EndDrawing();
	}
	CloseWindow();
}
