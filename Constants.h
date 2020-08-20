#pragma once

// Constants for the game grid size
static int const X = 8;
static int const Y = 5;

// Constants for the objects size
static float const FRAMERATE_LIMIT = 60.0;
static float const BALL_RADIUS = 5.0;
static float const WIDTH = 1.0;
static float const WIDTH_ = 2.0;
static float const WIDTH_BRICK = 80.0;
static float const HEIGHT_BRICK = 45.0;
static float const WIDTH_WINDOW = 8 * 2 * WIDTH + WIDTH_BRICK * 10;
static float const HEIGHT_WINDOW = HEIGHT_BRICK * 8 * 2 + 2 * 8 * WIDTH + 120;
static float const SPEED = 4.5; 
static float const PADDLE_FRAME = 1.0;
static float const PADDLE_WIDTH = 80.0;
static float const PADDLE_HEIGHT = 6.0;
static float const PADDLE_X = WIDTH_WINDOW / 2.0 - 4.0 * BALL_RADIUS;
static float const PADDLE_Y = HEIGHT_WINDOW - 100.0;
static float const BALL_X = PADDLE_X + 35.0;
static float const BALL_Y = PADDLE_Y + 2 - 3 * BALL_RADIUS;
static float const SIZE_FONT = 30.0;
static float const TEXT_X = 10.0;
static float const TEXT_Y = 10.0;

typedef struct speed_t {
	float vx;
	float vy;
} speed_t;

enum class STATE_GAME {
	CONTINUING_GAME,
	GAME_OVER
};
enum class COLLISION_TYPE {
	ANGLES,
	ANGLES0,
	SIDES,
	SIDES0,
	SIDES1,
	SIDES2,
	SIDES3,
	PADDLE,
	BALL,
	NO_COLLISION
};

enum class RESULT_GAME {
	WIN,
	LOSING
};


enum class TYPE_BRICK {
	MOVING,
	BONUS
};

enum class TYPE_BONUS {
	PADDLE,
	BRICK,
	SPEED,
	KEY_PRESS,
	SECOND_PADDLE,
	DIRECTION
};

enum COLOR {
	GREEN,
	YELLOW,
	RED,
	BLUE,
	WHITE,
	CYAN,
	MAGENTA,
	BLACK
};

