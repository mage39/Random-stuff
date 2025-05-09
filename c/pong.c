#include <raylib.h>
#include <stdio.h>

static constexpr int width = 1280;
static constexpr int height = 800;
static constexpr Vector2 center = {width / 2, height / 2};
static constexpr int ballSpeed = 420;
static float deltaTime = 0;

typedef struct {
	Vector2 center, speed;
	int radius;
} Ball;
typedef struct {
	Rectangle paddle;
	int speed;
} Paddle;

static bool ballPaddleCollide(Ball ball, Paddle paddle) {
	// this function exist purely to avoid hitting the 80 column limit
	return CheckCollisionCircleRec(ball.center, ball.radius, paddle.paddle);
}
static int updateB (Ball* ball, Paddle paddleAI, Paddle paddlePlayer) {
	ball->center.x += ball->speed.x * deltaTime;
	ball->center.y += ball->speed.y * deltaTime;
	if (ball->center.y + ball->radius >= height) ball->speed.y = -ballSpeed;
	if (ball->center.y - ball->radius <= 0) ball->speed.y = ballSpeed;
	if (ball->center.x + ball->radius >= width) {
		ball->speed.x = -ballSpeed;
		return 1;
	} else if (ball->center.x - ball->radius <= 0) {
		ball->speed.x = ballSpeed;
		return 2;
	}
	if (ballPaddleCollide(*ball, paddlePlayer)) {
		ball->speed.x = -ballSpeed;
	} else if (ballPaddleCollide(*ball, paddleAI)) {
		ball->speed.x = ballSpeed;
	}
	return 0;
}
static void collideEdgeP (Paddle* paddle) {
	if (paddle->paddle.y <= 5) paddle->paddle.y = 5;
	if (paddle->paddle.y + paddle->paddle.height + 5 >= height) {
		paddle->paddle.y = height - paddle->paddle.height - 5;
	}
}
static void updateP (Paddle* paddle) {
	if (IsKeyDown(KEY_UP)) paddle->paddle.y -= paddle->speed * deltaTime;
	if (IsKeyDown(KEY_DOWN)) paddle->paddle.y += paddle->speed * deltaTime;
	collideEdgeP(paddle);
}
static void updateAI (Paddle* paddle, int ballY) {
	if (paddle->paddle.y + paddle->paddle.height / 2 > ballY) {
		paddle->paddle.y -= paddle->speed * deltaTime;
	} else if (paddle->paddle.y + paddle->paddle.height / 2 < ballY) {
		paddle->paddle.y += paddle->speed * deltaTime;
	}
	collideEdgeP(paddle);
}
static void drawScore(const char* text, Vector2 loc, int size) {
	// missed the 80 column limit by 1
	DrawText(text, loc.x, loc.y, size, WHITE);
}

int main (void) {
	InitWindow(width, height, "pong");
	constexpr Vector2 paddle = {20, 120};
	constexpr Rectangle borders = {0, 0, width, height};
	constexpr Vector2 AIscoreLoc = {width / 4 - 20, 20};
	constexpr Vector2 playerScoreLoc = {3 * width / 4 - 20, 20};
	constexpr int fontSize = 50;
	Ball ball = {center, {ballSpeed, ballSpeed}, 20};
	Paddle paddleAI = {{10, center.y - 60, paddle.x, paddle.y}, 360};
	Paddle paddlePlayer = paddleAI;
	paddlePlayer.paddle.x = width - 30;
	int playerScore = 0, AIscore = 0;
	char scores[2][64] = {0};
	int shouldDrawFPS = 0;
	char FPS[64] = {0};
	while (!WindowShouldClose()) {
		deltaTime = GetFrameTime();
		updateP(&paddlePlayer);
		updateAI(&paddleAI, ball.center.y);
		int score = updateB(&ball, paddleAI, paddlePlayer);
		if (score == 1) AIscore++;
		else if (score == 2) playerScore++;
		sprintf(scores[0], "%d", AIscore);
		sprintf(scores[1], "%d", playerScore);
		shouldDrawFPS++;
		if (shouldDrawFPS > 20'000) {
			sprintf(FPS, "%d FPS", GetFPS());
			shouldDrawFPS = 0;
		}
		BeginDrawing();
		ClearBackground(BLACK);
		DrawLine(center.x, 0, center.x, height, WHITE);
		DrawRectangleLinesEx(borders, 1, WHITE);
		drawScore(scores[0], AIscoreLoc, fontSize);
		drawScore(scores[1], playerScoreLoc, fontSize);
		DrawText(FPS, 3, 3, 20, GREEN);
		DrawRectangleRec(paddleAI.paddle, RED);
		DrawRectangleRec(paddlePlayer.paddle, GREEN);
		DrawCircleV(ball.center, ball.radius, WHITE);
		EndDrawing();
	}
	CloseWindow();
}
