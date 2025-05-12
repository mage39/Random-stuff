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
	SLEFT,
	TPIECE
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
static constexpr Piece pieces[] = { // they're all SIDEWAYS. also, forgot the T piece
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
		[3] = {[3] = ORANGE, [4] = ORANGE},
		[4] = {[2] = ORANGE, [3] = ORANGE}}},
	[SLEFT] = {{
		[3] = {[2] = PINK, [3] = PINK},
		[4] = {[3] = PINK, [4] = PINK}}},
	[TPIECE] = {{
		[3] = {[2] = BEIGE, [3] = BEIGE, [4] = BEIGE},
		[4] = {[3] = BEIGE}}}
};
#pragma GCC diagnostic pop

#if 0
static void checkLine(Color board[boardWidth][boardHeight]) {
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
			Rectangle pixColor = {pixel.x + 1, pixel.y + 1,
				pixelWidth - 1, pixelWidth - 1};
			DrawRectangleRec(pixColor, board[i][j]);
			DrawRectangleLinesEx(pixel, 1, WHITE);
		}
	}
}
static void drawPiece (Image* image, Vector3 center, enum PieceIdx idx) {
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
		}
	}
	Texture2D tex = LoadTextureFromImage(*image);
	DrawTextureEx(tex, (Vector2){center.x, center.y}, center.z, 1, LIGHTGRAY);
}
static Vector3 rectifyCenter (Vector3 center) {
	return (Vector3){500, 80, 0}; // note: imageWidth is 201
}
static bool collision (const Color board[boardWidth][boardHeight],
		Vector3 center, enum PieceIdx which) {
	return false;
}
static void writeBoard (Color board[boardWidth][boardHeight],
		Vector3 center, enum PieceIdx which) {
}
static Vector3 update (Vector3 center, float speed) {
	if (IsKeyPressed(KEY_A)) center.z -= 90;
	if (IsKeyPressed(KEY_D)) center.z += 90;
	if (IsKeyDown(KEY_DOWN)) speed *= 3;
	if (IsKeyPressed(KEY_UP)) speed = 69420;
	center.y += speed * GetFrameTime();
	if (IsKeyPressed(KEY_LEFT)) center.x -= pixelWidth;
	if (IsKeyPressed(KEY_RIGHT)) center.x += pixelWidth;
	if (center.z > 300) center.z = 0;
	if (center.z < 0) center.z = 270;
	if (center.x < 80) center.x = 100;
	constexpr int leftBound = 80 * boardWidth * pixelWidth;
	if (center.x > leftBound) center.x = leftBound - 20;
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
	float speed = 0; // i'm thinking initially 40 to 80 -- 0 is for testing
	Color board[boardWidth][boardHeight] = {0};
	Image pieceImage = GenImageColor(imageWidth, imageWidth, BLANK);
	// enum PieceIdx queue[2] = {0};
	Vector3 center = {0};
	InitWindow(width, height, "tetris");
	while(!WindowShouldClose()) {
		center = update(center, speed);
		// if i allowed my functions to hold state,
		// the function signature that could replace this if statement
		// could be less than 4 things, and fit inside the 80 column limit.
		// but i don't, so that's that.
		if (collision(board, center, 0)) {
			writeBoard(board, center, 0);
			speed += 0.01;
			center = (Vector3){40, 60 + boardWidth * pixelWidth, 0};
			// also handle queue things here
		}
		// checkLine(board);
		BeginDrawing();
		ClearBackground(BLACK);
		DrawLineEx(failHeight.start, failHeight.end, 4, RED);
		DrawRectangleLinesEx(boardOutline, 1, WHITE);
		DrawRectangleLinesEx(outline, 1, WHITE);
		drawPiece(&pieceImage, rectifyCenter(center), LINE);
		drawBoard(board);
		EndDrawing();
	}
	CloseWindow();
	UnloadImage(pieceImage);
}
