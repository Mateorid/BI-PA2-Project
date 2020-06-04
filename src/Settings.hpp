#pragma once

/**Title of the game*/
static const char *const GAME_NAME = "Arkanoid 2.0";
/**Game window width*/
static const int GAME_WIDTH = 600;
/**Game window height*/
static const int GAME_HEIGHT = 800;
/**Game FPS limit*/
static const int MAX_FPS = 100;
/**Frame delay*/
static const int FRAME_DELAY = 1000 / MAX_FPS;
/**Start game in fullscreen*/
static const bool START_FULLSCREEN = false;
/**How many lives you start with*/
//static const int START_LIVES = 3; //TODO doesn't work xd
/**Destination of ball source image*/
static const char *const BALL_SRC = "examples/textures/ball.png";
/**Ball texture size*/
static const int BALL_SIZE = 21;
/**Destination of platform source image*/
static const char *const PLATFORM_SRC = "examples/textures/paddle.png";
/**Platform texture size*/
static const int PLATFORM_H = 21;
static const int PLATFORM_W = 91;
/**Block texture size*/
static const int BLOCK_H = 22;
static const int BLOCK_W = 50;
/**Destination of block source image*/
static const char *const BLOCK_SRC = "examples/textures/block.png";
/**Destination of bonus source image*/
static const char *const BONUS_SRC = "examples/textures/bonus.png";
/**Different game object types*/
enum GOType {
    PLATFORM, BALL, BLOCK, BONUS
};
enum BonusType {
    PLUS_LIFE, SECOND_BALL, SLOW_PLAT, SLOW_BALL, FAST_PLAT, FAST_BALL
};