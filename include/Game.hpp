#pragma once

#include "Snake.hpp"

class Game
{
public:
    const int CELL_SIZE = 100;
    const int CELL_COUNT_X = 10;
    const int CELL_COUNT_Y = 9;

    const Color DARK_GRAY = {50, 50, 50, 255};
    const Color LIGHT_GRAY = {70, 70, 70, 255};

    const float MOVE_TIME_DURATION_SECONDS = 0.2f;

    void runGame();
    
private:
    void setFruit();
    void resetGame();
    void drawCell(int pos_x, int pos_y, Color col);
    void drawBackground();
    void drawSnake();
    void drawFruit();
    void getSnakeDirectionFromInput();
    void eatFruit();
    
    Vector2 fruit_pos_;
    Vector2 snake_new_direction_;
    Snake snake_;

    float timer_;
};
