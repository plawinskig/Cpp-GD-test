#include "Game.hpp"

void Game::runGame()
{
    InitWindow(CELL_SIZE * CELL_COUNT_X, CELL_SIZE * CELL_COUNT_Y, "Game of snake");
    SetTargetFPS(60);

    resetGame();

    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(DARK_GRAY);

        drawBackground();
        
        drawSnake();

        drawFruit();

        getSnakeDirectionFromInput();

        timer_ -= GetFrameTime();

        if (timer_ <= 0)
        {
            timer_ += MOVE_TIME_DURATION_SECONDS;
            
            snake_.move(snake_new_direction_);

            snake_.wrap(CELL_COUNT_X, CELL_COUNT_Y);

            if(snake_.isColliding())
            {
                resetGame();
            }
        }

        eatFruit();

        EndDrawing();
    }

    CloseWindow();
}

void Game::setFruit()
{
    bool fruit_placed = false;
    while (!fruit_placed)
    {
        fruit_pos_.x = GetRandomValue(0, CELL_COUNT_X - 1);
        fruit_pos_.y = GetRandomValue(0, CELL_COUNT_Y - 1);

        if (!snake_.occupies(fruit_pos_)) 
        {
            fruit_placed = true;
        }
    }
}

void Game::resetGame()
{
    snake_.reset();
    snake_new_direction_ = {1, 0};
    setFruit();
    timer_ = MOVE_TIME_DURATION_SECONDS;
}

void Game::drawCell(int pos_x, int pos_y, Color col)
{
    DrawRectangle(pos_x * CELL_SIZE, pos_y * CELL_SIZE, CELL_SIZE, CELL_SIZE, col);
}

void Game::drawBackground()
{
    for (int i = 0; i < CELL_COUNT_X; ++i)
    {
        for (int j = 0; j < CELL_COUNT_Y; ++j)
        {
            if ((i + j) % 2 == 1)
            {
                drawCell(i, j, LIGHT_GRAY);
            }
        }
    }
}

void Game::drawSnake()
{
    drawCell(snake_.getHeadPos().x, snake_.getHeadPos().y, DARKGREEN);

    for (size_t i = 1; i < snake_.getSize(); ++i)
    {
        drawCell(snake_[i].x, snake_[i].y, GREEN);
    }
}

void Game::drawFruit()
{
    drawCell(fruit_pos_.x, fruit_pos_.y, RED);
}

void Game::getSnakeDirectionFromInput()
{
    if (IsKeyPressed(KEY_W)) { snake_new_direction_ = {0, -1}; }
    if (IsKeyPressed(KEY_S)) { snake_new_direction_ = {0, 1}; }
    if (IsKeyPressed(KEY_A)) { snake_new_direction_ = {-1, 0}; }
    if (IsKeyPressed(KEY_D)) { snake_new_direction_ = {1, 0}; }
}

void Game::eatFruit()
{
    if (snake_.getHeadPos().x == fruit_pos_.x &&
        snake_.getHeadPos().y == fruit_pos_.y)
    {
        setFruit();
        snake_.extendBody();
    }
}
