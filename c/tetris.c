#include <raylib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

enum PieceIdx {
	SQUARE,
	LINE,
	LRIGHT,
	LLEFT,
	SRIGHT,
	SLEFT
};

typedef struct {
	Color p[5][5]; // gives a good center for rotation
} Piece;
typedef struct {
	Vector2 start, end;
} Line;

static constexpr int width = 800;
static constexpr int height = 1000;
static constexpr int pixelWidth = 40;
static constexpr int boardWidth = 10;
static constexpr int boardHeight = 24;
// -Wpedantic gives "these are not constants" for the colors
#pragma GCC diagnostic ignored "-Wpedantic"
static constexpr Piece pieces[] = { // they're all SIDEWAYS
	[SQUARE] = {{
		[3] = {[3] = GREEN, [4] = GREEN},
		[4] = {[3] = GREEN, [4] = GREEN}}},
	[LINE] = {{
		[1] = {[3] = MAROON},
		[2] = {[3] = MAROON},
		[3] = {[3] = MAROON},
		[4] = {[3] = MAROON}}},
	[LRIGHT] = {{
		[2] = {[2] = BLUE, [3] = BLUE},
		[3] = {[3] = BLUE},
		[4] = {[3] = BLUE}}},
	[LLEFT] = {{
		[2] = {[3] = PURPLE, [4] = PURPLE},
		[3] = {[3] = PURPLE},
		[4] = {[3] = PURPLE}}},
	[SRIGHT] = {{
		[3] = {[3] = YELLOW, [4] = YELLOW},
		[4] = {[2] = YELLOW, [3] = YELLOW}}},
	[SLEFT] = {{
		[3] = {[2] = PINK, [3] = PINK},
		[4] = {[3] = PINK, [4] = PINK}}}
};
#pragma GCC diagnostic pop

#if 0
static void checkLine(Color board[24][10]) {
	for (int i = 0; i < 20; i++) {
		int c = 0;
		for (int j = 0; j < 10; j++) {
			if (board[i][j].a) c++;
		}
		if (c > 8) memcpy(/* down one line */);
	}
}
#endif
static void drawBoard (Color board[boardWidth][boardHeight]) {
	for (int i = 0; i < boardWidth; i++) {
		for (int j = 0; j < boardHeight; j++) {
			Rectangle pixel = {80 + i * pixelWidth, 20 + j * pixelWidth,
				pixelWidth + 1, pixelWidth + 1};
			DrawRectangleLinesEx(pixel, 1, WHITE);
			Rectangle pixColor = {pixel.x + 1, pixel.y + 1,
				pixelWidth - 1, pixelWidth - 1};
			DrawRectangleRec(pixColor, board[i][j]);
		}
	}
}
static void drawPiece (Image* image, Vector3 center, enum PieceIdx idx) {
	// Vector2 boardOrigin = {80, 20};
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			Rectangle pixel = {i * pixelWidth, j * pixelWidth,
				pixelWidth + 1, pixelWidth + 1};
			Rectangle pixColor = {pixel.x + 1, pixel.y + 1,
				pixelWidth - 1, pixelWidth - 1};
			if (pieces[idx].p[i][j].a) {
				ImageDrawRectangleLines(image, pixel, 1, WHITE);
				ImageDrawRectangleRec(image, pixColor, pieces[idx].p[i][j]);
			}
		}
	}
	Texture2D tex = LoadTextureFromImage(*image);
	DrawTextureEx(tex, (Vector2){center.x, center.y}, center.z, 1, WHITE);
}
static Vector3 updateCenter (Vector3 center, float speed, bool collided) {
	// static Vector2 trueCenter = {80 + boardWidth / 2 * pixelWidth, 40};
	// if (collided) trueCenter = {80 + boardWidth / 2 * pixelWidth, 40};
	return (Vector3){280, 20, 90}; // note: imageWidth is 200
}
static bool collision (Vector3 center, enum PieceIdx which) {
	return false;
}

int main (void) {
	constexpr Rectangle boardOutline = {80, 20,
		boardWidth * pixelWidth + 1,
		boardHeight * pixelWidth + 1};
	constexpr Line failHeight = {{80, pixelWidth * 4 - 2 + 20},
		{boardWidth * pixelWidth + 80, pixelWidth * 4 - 2 + 20}};
	constexpr Rectangle outline = {0, 0, width, height};
	constexpr int imageWidth = pixelWidth * 5;
	Color board[boardWidth][boardHeight] = {0};
	Image pieceImage = GenImageColor(imageWidth + 1, imageWidth + 1, BLANK);
	// Piece queue[2] = {0}; // note: this should be PieceIdx
	Vector3 center = {0};
	bool collided = false;
	InitWindow(width, height, "tetris");
	while(!WindowShouldClose()) {
		collided = collision(center, 0);
		center = updateCenter(center, 0, collided);
		// checkLine(board);
		BeginDrawing();
		ClearBackground(BLACK);
		DrawLineEx(failHeight.start, failHeight.end, 4, RED);
		DrawRectangleLinesEx(boardOutline, 1, WHITE);
		DrawRectangleLinesEx(outline, 1, WHITE);
		drawPiece(&pieceImage, center, LINE);
		drawBoard(board);
		EndDrawing();
	}
	CloseWindow();
	UnloadImage(pieceImage);
}
