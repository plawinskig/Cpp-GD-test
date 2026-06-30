#include "raylib.h"

int main() 
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    
    InitWindow(screenWidth, screenHeight, "Game of snake");

    Texture2D playerTex = LoadTexture("assets/player.png");

    SetTargetFPS(60);

    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        
        ClearBackground(RAYWHITE);

        DrawTexture(playerTex, 100, 100, WHITE);
        
        DrawTextureEx(playerTex, {400.0f, 100.0f}, 0.0f, 3.0f, WHITE);

        DrawText("Player one", 100, 500, 20, DARKGRAY);

        EndDrawing();
    }

    UnloadTexture(playerTex);
    
    CloseWindow();

    return 0;
}