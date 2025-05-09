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

static constexpr Piece pieces[] = {
	[SQUARE] = {{
		[3] = {[3] = GREEN, [4] = GREEN},
		[4] = {[3] = GREEN, [4] = GREEN}}},
	[LINE] = {{
		[1] = {[3] = RED},
		[2] = {[3] = RED},
		[3] = {[3] = RED},
		[4] = {[3] = RED}}},
	[LRIGHT] = {{
		[2] = {[2] = BLUE, [3] = BLUE},
		[3] = {[3] = BLUE},
		[4] = {[3] = BLUE}}},
	[LLEFT] = {{
		[2] = {[3] = PURPLE, [4] = PURPLE},
		[3] = {[3] = PURPLE},
		[3] = {[3] = PURPLE}}},
	[SRIGHT] = {{
		[3] = {[3] = YELLOW, [4] = YELLOW},
		[4] = {[2] = YELLOW, [3] = YELLOW}}},
	[SLEFT] = {{
		[3] = {[2] = PINK, [3] = PINK},
		[4] = {[3] = PINK, [4] = PINK}}},
};

void checkLine(Color board[24][10]) {
	for (int i = 0; i < 20; i++) {
		int c = 0;
		for (int j = 0; j < 10; j++) {
			if (board[i][j].a) c++;
		}
		if (c > 8) memcpy(/* down one line */);
	}
}

int main (void) {
	Color board[24][10] = {0};
	Piece queue[2] = {0};
	InitWindow(0, 0, "tetris");
	while(!WindowShouldClose()) {
		checkLine(board);
		BeginDrawing();
		EndDrawing();
	}
	CloseWindow();
}
