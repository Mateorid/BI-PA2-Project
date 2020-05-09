#pragma once

/**Title of the game*/
const char *const GAME_NAME = "Arkanoid 2.0";
/**Game window width*/
const int GAME_WIDTH = 600;
/**Game window height*/
const int GAME_HEIGHT = 800;
/**Game FPS limit*/
const int MAX_FPS = 100;
/**Start game in fullscreen*/
const bool START_FULLSCREEN = false;
/**How many lives you start with*/
const int MAX_LIVES = 3;
/**Destination of ball source image*/
const char *const BALL_SRC = "src/textures/ball.png";
/**Ball texture size*/
const int BALL_SIZE = 21;
/**Destination of platform source image*/
const char *const PLATFORM_SRC = "src/textures/paddle.png";
/**Platform texture size*/
const int PLATFORM_H = 21;
const int PLATFORM_W = 91;
/**Block texture size*/
const int BLOCK_H = 22;
const int BLOCK_W = 50;
/**Destination of block source image*/
const char *const BLOCK_SRC = "src/textures/block.png";
///**Destination of lvl1 block source image*/
//const char *const LVL1_SRC = "src/textures/green.png";
///**Destination of lvl2 block image*/
//const char *const LVL2_SRC = "src/textures/blue.png";
///**Destination of lvl3 block image*/
//const char *const LVL3_SRC = "src/textures/pink.png";
/**Different game object types*/
enum GOType {
    PLATFORM, BALL, BLOCK, BONUS
};
