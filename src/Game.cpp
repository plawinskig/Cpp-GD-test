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

        Vector2 snake_new_direction = getSnakeDirectionFromInput();

        timer -= GetFrameTime();

        if (timer <= 0)
        {
            timer += move_time_duration_seconds;
            
            snake_.move(snake_new_direction);

            wrapSnake();

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

        bool touches_snake = false;

        for (size_t i = 0; i < snake_.getSize() && !touches_snake; ++i)
        {
            if (snake_[i].x == fruit_pos_.x &&
                snake_[i].y == fruit_pos_.y)
            {
                touches_snake = true;
            }
        }

        if (!touches_snake)
        {
            fruit_placed = true;
        }
    }
}

void Game::resetGame()
{
    snake_.reset();
    setFruit();
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
    drawCell(snake_[0].x, snake_[0].y, DARKGREEN);

    for (size_t i = 1; i < snake_.getSize(); ++i)
    {
        drawCell(snake_[i].x, snake_[i].y, GREEN);
    }
}

void Game::drawFruit()
{
    drawCell(fruit_pos_.x, fruit_pos_.y, RED);
}

Vector2 Game::getSnakeDirectionFromInput()
{
    if (IsKeyDown(KEY_W)) { return {0, -1}; }
    if (IsKeyDown(KEY_S)) { return {0, 1}; }
    if (IsKeyDown(KEY_A)) { return {-1, 0}; }
    if (IsKeyDown(KEY_D)) { return {1, 0}; }
}

void Game::wrapSnake()
{
    for (auto &segment : snake_)
    {
        if (segment.x >= CELL_COUNT_X) { segment.x = 0; }
        if (segment.y >= CELL_COUNT_Y) { segment.y = 0; }
        if (segment.x < 0) { segment.x = CELL_COUNT_X - 1; }
        if (segment.y < 0) { segment.y = CELL_COUNT_Y - 1; }
    }
}

void Game::eatFruit()
{
    if (snake_[0].x == fruit_pos_.x &&
        snake_[0].y == fruit_pos_.y)
    {
        setFruit();
        snake_.extendBody();
    }
}
