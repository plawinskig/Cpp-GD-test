#include "raylib.h"

const int CELL_SIZE = 100;
const int CELL_COUNT_X = 10;
const int CELL_COUNT_Y = 9;

void drawCell(int pos_x, int pos_y, Color col)
{
    DrawRectangle(pos_x * CELL_SIZE, pos_y * CELL_SIZE, CELL_SIZE, CELL_SIZE, col);
}

int main() 
{
    InitWindow(CELL_SIZE * CELL_COUNT_X, CELL_SIZE * CELL_COUNT_Y, "Game of snake");
    
    SetTargetFPS(60);

    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        Color col = {200, 100, 100, 255};
        drawCell(0, 0, col);
        drawCell(2, 1, col);
        
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}