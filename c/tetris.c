#include <raylib.h>
#include <string.h>
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
constexpr int pixelWidth = 40;
constexpr int boardWidth = 10;
constexpr int boardHeight = 24;
// -Wpedantic gives "these are not constants" for the colors
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-const-variable"
static constexpr Piece pieces[] = {
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

int main (void) {
	constexpr Rectangle boardOutline = {80, 20,
		boardWidth * pixelWidth + 1,
		boardHeight * pixelWidth + 1};
	constexpr Line failHeight = {{80, pixelWidth * 4 - 2 + 20},
		{boardWidth * pixelWidth + 80, pixelWidth * 4 - 2 + 20}};
	constexpr Rectangle outline = {0, 0, width, height};
	Color board[boardWidth][boardHeight] = {0};
	board[3][3] = MAROON;
	// Piece queue[2] = {0};
	InitWindow(width, height, "tetris");
	while(!WindowShouldClose()) {
		// checkLine(board);
		BeginDrawing();
		ClearBackground(BLACK);
		DrawLineEx(failHeight.start, failHeight.end, 4, RED);
		DrawRectangleLinesEx(boardOutline, 1, WHITE);
		DrawRectangleLinesEx(outline, 1, WHITE);
		drawBoard(board);
		EndDrawing();
	}
	CloseWindow();
}
