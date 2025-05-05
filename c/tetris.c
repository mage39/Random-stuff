#include <raylib.h>

// the A index is an 8-bit unsigned minifloat
enum Color { R, G, B, A };
enum PieceName {
	SQUARE,
	LINE,
	LRIGHT,
	LLEFT,
	SRIGHT,
	SLEFT
};

typedef struct {
	char d[4];
} Pixel;
typedef struct {
	Pixel p[5][5]; // gives a good center for rotation
} Piece;

static constexpr pieces[] {
	[SQUARE] = {[3] = {
			[3] = {[G] = 255, [A] = 0xFF00},
			[4] = {[G] = 255, [A] = 0xFF00}
		}, [4] = {
			[3] = {[G] = 255, [A] = 0xFF00},
			[4] = {[G] = 255, [A] = 0xFF00}
		}
	}, [LINE] = {[1] = {
			[3] = {[R] = 255, [A] = 0xFF00}
		}, [2] = {
			[3] = {[R] = 255, [A] = 0xFF00}
		}, [3] = {
			[3] = {[R] = 255, [A] = 0xFF00}
		}, [4] = {
			[3] = {[R] = 255, [A] = 0xFF00}
		}
	}, [LRIGHT] = { // GOD HELP ME. make it blue tho

void checkLine(Pixel board[24][10]) {
	for (int i = 0; i < 20; i++) {
		int c = 0;
		for (int k = 0; j < 10; j++) {
			if (board[i][j].d[A]) c++;
		}
		if (c > 8) memcpy(/* down one line */);
	}
}

int main (void) {
	Pixel board[24][10] = {0};
	Piece queue[2] = {0};
	InitWindow(0, 0, "tetris");
	while(!WindowShouldClose()) {
		checkLine(board);
		BeginDrawing();
		EndDrawing();
	}
	CloseWindow();
}
