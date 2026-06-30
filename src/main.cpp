#include "raylib.h"

const int CELL_SIZE = 100;
const int CELL_COUNT_X = 10;
const int CELL_COUNT_Y = 9;

const Color DARK_GRAY = {50, 50, 50, 255};
const Color LIGHT_GRAY = {70, 70, 70, 255};

void drawCell(int pos_x, int pos_y, Color col)
{
    DrawRectangle(pos_x * CELL_SIZE, pos_y * CELL_SIZE, CELL_SIZE, CELL_SIZE, col);
}

int main() 
{
    InitWindow(CELL_SIZE * CELL_COUNT_X, CELL_SIZE * CELL_COUNT_Y, "Game of snake");
    
    Vector2 snake_pos = {5, 5};
    Vector2 direction = {1, 0};

    SetTargetFPS(60);

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
        
        // draw snake
        drawCell(snake_pos.x, snake_pos.y, DARKGREEN);

        // move snake
        snake_pos.x += direction.x;
        snake_pos.y += direction.y;

        EndDrawing();
    }

    CloseWindow();

    return 0;
}