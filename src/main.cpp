#include "raylib.h"

int main() 
{
    const int screen_width = 800;
    const int screen_height = 600;

    const int cell_size = 100;
    const int cell_count_x = 10;
    const int cell_count_y = 10;
    
    InitWindow(screen_width, screen_height, "Game of snake");

    Texture2D player_tex = LoadTexture("assets/player.png");

    SetTargetFPS(60);

    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        
        ClearBackground(RAYWHITE);

        DrawTexture(player_tex, 100, 100, WHITE);
        
        DrawTextureEx(player_tex, {400.0f, 100.0f}, 0.0f, 3.0f, WHITE);

        DrawText("Player one", 100, 500, 20, DARKGRAY);

        EndDrawing();
    }

    UnloadTexture(player_tex);
    
    CloseWindow();

    return 0;
}