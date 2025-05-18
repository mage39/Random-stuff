#include <raylib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

enum PieceIdx {
	SQUARE,
	LINE,
	LRIGHT,
	LLEFT,
	SRIGHT,
	SLEFT,
	TPIECE
};

typedef struct {
	Color p[5][5]; // gives a good center for rotation
} Piece;
typedef struct {
	Vector2 start, end;
} Line;

static constexpr float E = 1E-5f;
static constexpr int width = 800;
static constexpr int height = 1000;
static constexpr int pixelWidth = 40;
static constexpr int boardWidth = 10;
static constexpr int boardHeight = 24;
// -Wpedantic gives "these are not constants" for the colors
#pragma GCC diagnostic ignored "-Wpedantic"
static constexpr Piece pieces[] = { // they're all SIDEWAYS
	[SQUARE] = {{
		[2] = {[2] = GREEN, [3] = GREEN},
		[3] = {[2] = GREEN, [3] = GREEN}}},
	[LINE] = {{
		[1] = {[2] = MAROON},
		[2] = {[2] = MAROON},
		[3] = {[2] = MAROON},
		[4] = {[2] = MAROON}}},
	[LRIGHT] = {{
		[1] = {[1] = BLUE, [2] = BLUE},
		[2] = {[2] = BLUE},
		[3] = {[2] = BLUE}}},
	[LLEFT] = {{
		[1] = {[2] = PURPLE, [3] = PURPLE},
		[2] = {[2] = PURPLE},
		[3] = {[2] = PURPLE}}},
	[SRIGHT] = {{
		[2] = {[2] = ORANGE, [3] = ORANGE},
		[3] = {[1] = ORANGE, [2] = ORANGE}}},
	[SLEFT] = {{
		[2] = {[1] = PINK, [2] = PINK},
		[3] = {[2] = PINK, [3] = PINK}}},
	[TPIECE] = {{
		[2] = {[1] = BEIGE, [2] = BEIGE, [3] = BEIGE},
		[3] = {[2] = BEIGE}}}
};
#pragma GCC diagnostic pop
static Color board[boardWidth][boardHeight] = {0};

#if 0
static void checkLine(void) {
	for (int i = 0; i < 20; i++) {
		int c = 0;
		for (int j = 0; j < 10; j++) {
			if (board[i][j].a) c++;
		}
		if (c > 8) memcpy(/* down one line */);
	}
}
#endif
static void drawBoard (void) {
	for (int i = 0; i < boardWidth; i++) {
		for (int j = 0; j < boardHeight; j++) {
			Rectangle pixel = {80 + i * pixelWidth, 20 + j * pixelWidth,
				pixelWidth + 1, pixelWidth + 1};
			Rectangle pixColor = {pixel.x + 1, pixel.y + 1,
				pixelWidth - 1, pixelWidth - 1};
			DrawRectangleRec(pixColor, board[i][j]);
			DrawRectangleLinesEx(pixel, 1, WHITE);
		}
	}
}
static void drawTex(Texture2D tex, Vector3 center) {
	DrawTextureEx(tex, (Vector2){center.x, center.y}, center.z, 1, LIGHTGRAY);
}
static Texture2D drawPiece (Image* image, enum PieceIdx idx) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			Rectangle pixel = {i * pixelWidth, j * pixelWidth,
				pixelWidth + 1, pixelWidth + 1};
			Rectangle pixColor = {pixel.x + 1, pixel.y + 1,
				pixelWidth - 1, pixelWidth - 1};
			if (pieces[idx].p[i][j].a) {
				ImageDrawRectangleRec(image, pixColor, pieces[idx].p[i][j]);
				ImageDrawRectangleLines(image, pixel, 1, WHITE);
			}
			if (i == 2 && j == 2) {
				Vector2 c = {i * pixelWidth + pixelWidth / 2,
					j * pixelWidth + pixelWidth / 2};
				ImageDrawCircleV(image, c, 10, LIME);
			}
		}
	}
	return LoadTextureFromImage(*image);
}
static Vector3 rectifyCenter (Vector3 center) {
	if (fabsf(center.z - 0) <= E) {
		center.x -= pixelWidth * 2 + pixelWidth / 2;
		center.y -= pixelWidth * 2 + pixelWidth / 2;
	} else if (fabsf(center.z - 90) <= E) {
		center.x += pixelWidth * 2 + pixelWidth / 2;
		center.y -= pixelWidth * 2 + pixelWidth / 2;
	} else if (fabsf(center.z - 180) <= E) {
		center.x += pixelWidth * 2 + pixelWidth / 2;
		center.y += pixelWidth * 2 + pixelWidth / 2;
	} else if (fabsf(center.z - 270) <= E) {
		center.x -= pixelWidth * 2 + pixelWidth / 2;
		center.y += pixelWidth * 2 + pixelWidth / 2;
	}
	center.y = floorf(center.y / 40) * 40 + 20;
	return center;
}
#pragma GCC diagnostic ignored "-Wunused-parameter"
static void writeBoard (Vector3 center, enum PieceIdx which) {
}
static Vector3 collision (Vector3 center, enum PieceIdx which) {
	// draw collision boxes and check collision i think
	return (Vector3){-1, -1, -1};
}
#pragma GCC diagnostic pop
static Vector3 update (Vector3 center, float speed, enum PieceIdx which) {
	if (IsKeyPressed(KEY_A)) center.z -= 90;
	if (IsKeyPressed(KEY_D)) center.z += 90;
	if (IsKeyDown(KEY_DOWN)) speed *= 3;
	if (IsKeyDown(KEY_UP)) speed = 69420;
	center.y += speed * GetFrameTime();
	if (IsKeyPressed(KEY_LEFT)) center.x -= pixelWidth;
	if (IsKeyPressed(KEY_RIGHT)) center.x += pixelWidth;
	if (center.z > 300) center.z = 0;
	if (center.z < 0) center.z = 270;
	Vector3 collides = collision(center, which);
	if (collides.x > 0) center.x -= pixelWidth;
	if (collides.y > 0) center.x -= pixelWidth;
	return center;
}

int main (void) {
	constexpr Rectangle boardOutline = {80, 20,
		boardWidth * pixelWidth + 1,
		boardHeight * pixelWidth + 1};
	constexpr Line failHeight = {{80, pixelWidth * 4 - 2 + 20},
		{boardWidth * pixelWidth + 80, pixelWidth * 4 - 2 + 20}};
	constexpr Rectangle outline = {0, 0, width, height};
	constexpr int imageWidth = pixelWidth * 5 + 1;
	float speed = 0; // 80
	Image pieceImage = GenImageColor(imageWidth, imageWidth, BLANK);
	if (pieceImage.data == NULL) exit(1);
	// enum PieceIdx queue[2] = {0};
	Vector3 center = {60 + boardWidth * pixelWidth / 2, 40 * 2, 0};
	InitWindow(width, height, "tetris");
	Texture2D tex = drawPiece(&pieceImage, SQUARE);
	while(!WindowShouldClose()) {
		center = update(center, speed, SQUARE);
		if (collision(center, 0).z > 0) {
			writeBoard(center, 0);
			speed += 0.01;
			center = (Vector3){60 + boardWidth * pixelWidth / 2, 40 * 2, 0};
			tex = drawPiece(&pieceImage, SQUARE);
			// also handle queue things here
		}
		// checkLine();
		BeginDrawing();
		ClearBackground(BLACK);
		DrawLineEx(failHeight.start, failHeight.end, 4, RED);
		DrawRectangleLinesEx(boardOutline, 1, WHITE);
		DrawRectangleLinesEx(outline, 1, WHITE);
		drawTex(tex, rectifyCenter(center));
		drawBoard();
		EndDrawing();
	}
	CloseWindow();
	UnloadImage(pieceImage);
}
