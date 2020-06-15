#pragma once

/**Game window size*/
static const int GAME_WIDTH = 600; //todo move to game object and include in application?
static const int GAME_HEIGHT = 800;
/**Game object sizes*/
static const int BALL_SIZE = 20;
static const int BONUS_SIZE = 25;
static const int BLOCK_HEIGHT = 22;
static const int BLOCK_WIDTH = 50;
static const int PLATFORM_H = 20;
static const int PLATFORM_W = 90;

/**Game object types*/
enum GOType {
    PLATFORM, BALL, BLOCK, BONUS
};
/**Bonus types*/
enum BonusType {
    PLUS_LIFE, SECOND_BALL, SLOW_PLAT, SLOW_BALL, FAST_PLAT, FAST_BALL, EXTRA_SCORE
};