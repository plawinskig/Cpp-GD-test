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

    void runGame();
    
private:
    void setFruit();
    void resetGame();
    void drawCell(int pos_x, int pos_y, Color col);
    void drawBackground();
    void drawSnake();
    void drawFruit();
    void getMoveInput();
    void moveSnake();
    void wrapSnake();
    void detectSnakeCollision();
    void eatFruit();
    
    Vector2 fruit_pos_ = {0, 0};
    Snake snake_;

    const float move_time_duration_seconds = 0.2;
    float timer = move_time_duration_seconds;

    Vector2 snake_new_direction_;
};
