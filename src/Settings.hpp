#pragma once

/**Title of the game*/
const char *const GAME_NAME = "Arkanoid 2.0";
/**Game window width*/
const int GAME_WIDTH = 600;
/**Game window height*/
const int GAME_HEIGHT = 800;
/**Game FPS limit*/
const Uint32 MAX_FPS = 100;
/**Frame delay*/
const Uint32 FRAME_DELAY = 1000 / MAX_FPS;
/**Start game in fullscreen*/
const bool START_FULLSCREEN = false;
/**How many lives you start with*/
const int MAX_LIVES = 3;
/**Destination of ball source image*/
const char *const BALL_SRC = "examples/textures/ball.png";
/**Ball texture size*/
const int BALL_SIZE = 21;
/**Destination of platform source image*/
const char *const PLATFORM_SRC = "examples/textures/paddle.png";
/**Platform texture size*/
const int PLATFORM_H = 21;
const int PLATFORM_W = 91;
/**Block texture size*/
const int BLOCK_H = 22;
const int BLOCK_W = 50;
/**Destination of block source image*/
const char *const BLOCK_SRC = "examples/textures/block.png";
/**Different game object types*/
enum GOType {
    PLATFORM, BALL, BLOCK, BONUS
};
enum BonusType {
    PLUS_LIFE, SECOND_BALL, SLOW_PLAT, SLOW_BALL, FAST_PLAT, FAST_BALL
};