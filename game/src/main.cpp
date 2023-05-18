#include "rlImGui.h"
#include "Math.h"
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720


int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sunshine");
    InitAudioDevice();

    Vector2 circlePostion = { (float)SCREEN_WIDTH / 2,(float)SCREEN_HEIGHT / 2 };
    Texture texture = LoadTexture("../game/assets/textures/enterprise.png");
    Sound yoo = LoadSound("../game/assets/audio/yoo.mp3");
    Music music = LoadMusicStream("../game/assets/audio/Omega.mp3");

    SetTargetFPS(60);

    PlaySound(yoo);
    PlayMusicStream(music);
    
    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);
        //input Functions
        if (IsKeyDown(KEY_W))
        {
            circlePostion.y -= 2.0f;
        }
        if (IsKeyDown(KEY_A))
        {
            circlePostion.x -= 2.0f;
        }
        if (IsKeyDown(KEY_S))
        {
            circlePostion.y += 2.0f;
        }
        if (IsKeyDown(KEY_D))
        {
            circlePostion.x += 2.0f;
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(texture, 0, 0, WHITE);
        DrawText("Hello World!", 16, 9, 20, RED);
        DrawCircleV(circlePostion, 50, BLUE);
        DrawLine(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, RED);
        DrawRectangle(SCREEN_WIDTH - 100, SCREEN_HEIGHT - 100, 50, 75, GREEN);



        EndDrawing();


    }

    UnloadTexture(texture);
    UnloadMusicStream(music);
    UnloadSound(yoo);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
