#include "raylib.h"

const int cell_size = 100;
const int cell_count_x = 10;
const int cell_count_y = 10;

void drawCell(int pos_x, int pos_y, Color col)
{
    DrawRectangle(pos_x * cell_size, pos_y * cell_size, cell_size, cell_size, col);
}

int main() 
{
    const int screen_width = 800;
    const int screen_height = 600;

    InitWindow(screen_width, screen_height, "Game of snake");
    
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