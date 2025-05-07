#include <raylib.h>

static constexpr int width = 1280;
static constexpr int height = 800;
static constexpr Vector2 center = {width / 2, height / 2};
static float deltaTime = 0;

typedef struct {
	Vector2 center, speed;
	int radius;
} Ball;
typedef struct {
	Rectangle paddle;
	int speed;
} Paddle;

static void updateB (Ball* ball) {
	ball->center.x += ball->speed.x * deltaTime;
	ball->center.y += ball->speed.y * deltaTime;
	if (ball->center.y + ball->radius >= height) ball->speed.y *= -1;
	if (ball->center.y - ball->radius <= 0) ball->speed.y *= -1;
	if (ball->center.x + ball->radius >= width) ball->speed.x *= -1;
	if (ball->center.x - ball->radius <= 0) ball->speed.x *= -1;
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
static bool ballPaddleCollide(Ball ball, Paddle paddle) {
	return CheckCollisionCircleRec(ball.center, ball.radius, paddle.paddle);
}

int main (void) {
	InitWindow(width, height, "pong");
	constexpr Vector2 paddle = {20, 120};
	Ball ball = {center, {60 * 7, 60 * 7}, 20};
	Paddle paddleAI = {{10, center.y - 60, paddle.x, paddle.y}, 6 * 60};
	Paddle paddlePlayer = paddleAI;
	paddlePlayer.paddle.x = width - 30;
	while (!WindowShouldClose()) {
		deltaTime = GetFrameTime();
		updateB(&ball);
		updateP(&paddlePlayer);
		updateAI(&paddleAI, ball.center.y);
		if (ballPaddleCollide(ball, paddlePlayer)) {
			ball.speed.x *= -1;
		} else if (ballPaddleCollide(ball, paddleAI)) {
			ball.speed.x *= -1;
		}
		BeginDrawing();
		ClearBackground(BLACK);
		DrawLine(center.x, 0, center.x, height, WHITE);
		Rectangle borders = {0, 0, width, height};
		DrawRectangleLinesEx(borders, 1, WHITE);
		DrawRectangleRec(paddleAI.paddle, RED);
		DrawRectangleRec(paddlePlayer.paddle, GREEN);
		DrawCircleV(ball.center, ball.radius, WHITE);
		EndDrawing();
	}
	CloseWindow();
}
