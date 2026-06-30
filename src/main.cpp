#include <vector>
#include "raylib.h"

const int CELL_SIZE = 100;
const int CELL_COUNT_X = 10;
const int CELL_COUNT_Y = 9;

const Color DARK_GRAY = {50, 50, 50, 255};
const Color LIGHT_GRAY = {70, 70, 70, 255};

std::vector<Vector2> snake;
Vector2 fruit_pos = {0, 0};

void setFruit()
{
    bool fruit_placed = false;
    while (!fruit_placed)
    {
        fruit_pos.x = GetRandomValue(0, CELL_COUNT_X - 1);
        fruit_pos.y = GetRandomValue(0, CELL_COUNT_Y - 1);

        bool touches_snake = false;

        for (auto it = snake.begin(); it != snake.end() && !touches_snake; ++it)
        {
            Vector2 segment_pos = *it;
            if (segment_pos.x == fruit_pos.x &&
                segment_pos.y == fruit_pos.y)
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

void drawCell(int pos_x, int pos_y, Color col)
{
    DrawRectangle(pos_x * CELL_SIZE, pos_y * CELL_SIZE, CELL_SIZE, CELL_SIZE, col);
}

int main() 
{
    InitWindow(CELL_SIZE * CELL_COUNT_X, CELL_SIZE * CELL_COUNT_Y, "Game of snake");
    SetTargetFPS(60);

    Vector2 snake_direction = {1, 0};

    const float move_time_duration_seconds = 0.2;
    float timer = move_time_duration_seconds;

    snake.push_back({5,5});

    setFruit();

    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(DARK_GRAY);

        // background
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
        
        // snake
        drawCell(snake[0].x, snake[0].y, DARKGREEN);

        for (auto it = snake.begin() + 1; it != snake.end(); ++it)
        {
            Vector2 segment = *it;
            drawCell(segment.x, segment.y, GREEN);
        }

        // fruit
        drawCell(fruit_pos.x, fruit_pos.y, RED);

        // input
        if (IsKeyDown(KEY_W)) { snake_direction = {0, -1}; }
        if (IsKeyDown(KEY_S)) { snake_direction = {0, 1}; }
        if (IsKeyDown(KEY_A)) { snake_direction = {-1, 0}; }
        if (IsKeyDown(KEY_D)) { snake_direction = {1, 0}; }

        // move snake
        timer -= GetFrameTime();

        if (timer <= 0)
        {
            timer += move_time_duration_seconds;
            
            for (int i = snake.size() - 1; i > 0; --i)
            {
                snake[i] = snake[i - 1];
            }

            snake[0].x += snake_direction.x;
            snake[0].y += snake_direction.y;
        }

        // wrapper
        for (auto &segment : snake)
        {
            if (segment.x >= CELL_COUNT_X) { segment.x = 0; }
            if (segment.y >= CELL_COUNT_Y) { segment.y = 0; }
            if (segment.x < 0) { segment.x = CELL_COUNT_X - 1; }
            if (segment.y < 0) { segment.y = CELL_COUNT_Y - 1; }
        }

        // eat
        if (snake[0].x == fruit_pos.x &&
            snake[0].y == fruit_pos.y)
        {
            setFruit();
            snake.push_back(snake[snake.size() - 1]);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}