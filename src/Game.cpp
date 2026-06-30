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

        getMoveInput();

        timer -= GetFrameTime();

        if (timer <= 0)
        {
            timer += move_time_duration_seconds;
            
            moveSnake();

            wrapSnake();

            detectSnakeCollision();
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

        for (auto it = snake_.begin(); it != snake_.end() && !touches_snake; ++it)
        {
            Vector2 segment_pos = *it;
            if (segment_pos.x == fruit_pos_.x &&
                segment_pos.y == fruit_pos_.y)
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
    snake_ = std::vector<Vector2>();
    snake_.push_back({5,5});
    snake_.push_back({5,4});

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

    for (auto it = snake_.begin() + 1; it != snake_.end(); ++it)
    {
        Vector2 segment = *it;
        drawCell(segment.x, segment.y, GREEN);
    }
}

void Game::drawFruit()
{
    drawCell(fruit_pos_.x, fruit_pos_.y, RED);
}

void Game::getMoveInput()
{
    if (IsKeyDown(KEY_W)) { snake_new_direction = {0, -1}; }
    if (IsKeyDown(KEY_S)) { snake_new_direction = {0, 1}; }
    if (IsKeyDown(KEY_A)) { snake_new_direction = {-1, 0}; }
    if (IsKeyDown(KEY_D)) { snake_new_direction = {1, 0}; }
}

void Game::moveSnake()
{
    for (int i = snake_.size() - 1; i > 0; --i)
    {
        snake_[i] = snake_[i - 1];
    }

    if(snake_new_direction.x == -snake_direction.x &&
        snake_new_direction.y == -snake_direction.y)
    {
        snake_new_direction = snake_direction;
    }

    snake_direction = snake_new_direction;

    snake_[0].x += snake_direction.x;
    snake_[0].y += snake_direction.y;
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

void Game::detectSnakeCollision()
{
    for(size_t i = 1; i < snake_.size(); ++i)
    {
        if (
            snake_[0].x == snake_[i].x &&
            snake_[0].y == snake_[i].y
        )
        {
            resetGame();
        }
    }
}

void Game::eatFruit()
{
    if (snake_[0].x == fruit_pos_.x &&
        snake_[0].y == fruit_pos_.y)
    {
        setFruit();
        snake_.push_back(snake_[snake_.size() - 1]);
    }
}
