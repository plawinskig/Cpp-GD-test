#include "raylib.h"

int main() 
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "GD test window");

    SetTargetFPS(60);

    while (!WindowShouldClose()) 
    { 
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("The Raylib programmer", 150, 280, 20, DARKGRAY);

        DrawCircle(400, 350, 30, RED);
        
        EndDrawing();
    }

    CloseWindow(); 

    return 0;
}
