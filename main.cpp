//
//#include "raylib.h"
//#include "Paddle.h"
//#include "Ball.h"
//#include "GameMenu.h"
//#include "Manual.h"
//#include "AI.h"
//
//
//int main()
//{
//	InitWindow(800, 600, "Ping Pong Game");
//	SetWindowState(FLAG_VSYNC_HINT);
//
//	Vector2D BSpeed(300, 0);
//	Vector2D BPosition(GetScreenWidth() / 2.0, GetScreenHeight() / 2.0);
//	Ball ball(&BPosition,&BSpeed, 5);
//	GameMenu GM;
//
//	InitAudioDevice();
//	Music music = LoadMusicStream("sound.mp3");
//	PlayMusicStream(music);
//	float timePlayed = 0.0f;
//	bool pause = false;
//
//
//	RectangleShape Left(50, GetScreenHeight() / 2, 10, 100);
//	Paddle LeftPaddle(&Left, 500);
//
//	RectangleShape Right(GetScreenWidth() - 50, GetScreenHeight() / 2, 10, 100);
//	Paddle RightPaddle(&Right, 500);
//	Manual TwoPlayer;
//	AI OnePlayer;
//	while (!WindowShouldClose())
//	{
//			GM.drawMain();
//			while (!GM.GetMenu())
//			{
//				if (GM.GetPVP() == true)
//				{
//					TwoPlayer.PlayerVSPlayer(&RightPaddle, &LeftPaddle, &ball);
//				}
//
//				if (GM.GetPVC() == true)
//				{
//					OnePlayer.PlayerVSComputer(&RightPaddle, &LeftPaddle, &ball);
//				}
//				if (IsKeyPressed(KEY_BACKSPACE))
//				{
//					GM.SetMenu(true);
//				}
//			}
//
//			if (GM.GetQuit())
//			{
//				break;
//			}
//	}
//	UnloadMusicStream(music);
//	CloseAudioDevice();
//	CloseWindow();
//
//	return 0;
//}



/*******************************************************************************************
*
*   raylib [textures] example - Image loading and drawing on it
*
*   NOTE: Images are loaded in CPU memory (RAM); textures are loaded in GPU memory (VRAM)
*
*   Example originally created with raylib 1.4, last time updated with raylib 1.4
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2016-2022 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include<iostream>
using namespace std;
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [textures] example - image drawing");

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)

    Image cat = LoadImage("resources/cat.png");             // Load image in CPU memory (RAM)
    ImageCrop(&cat, (Rectangle) { 100, 10, 280, 380 });      // Crop an image piece
    ImageFlipHorizontal(&cat);                              // Flip cropped image horizontally
    ImageResize(&cat, 150, 200);                            // Resize flipped-cropped image

    Image parrots = LoadImage("resources/parrots.png");     // Load image in CPU memory (RAM)

    // Draw one image over the other with a scaling of 1.5f
    ImageDraw(&parrots, cat, (Rectangle) { 0, 0, (float)cat.width, (float)cat.height }, (Rectangle) { 30, 40, cat.width * 1.5f, cat.height * 1.5f }, WHITE);
    ImageCrop(&parrots, (Rectangle) { 0, 50, (float)parrots.width, (float)parrots.height - 100 }); // Crop resulting image

    // Draw on the image with a few image draw methods
    ImageDrawPixel(&parrots, 10, 10, RAYWHITE);
   
    ImageDrawRectangle(&parrots, 5, 20, 10, 10, RAYWHITE);

    UnloadImage(cat);       // Unload image from RAM

    // Load custom font for frawing on image
    Font font = LoadFont("resources/custom_jupiter_crash.png");

    // Draw over image using custom font
    ImageDrawTextEx(&parrots, font, "PARROTS & CAT", (Vector2) { 300, 230 }, (float)font.baseSize, -2, WHITE);

    UnloadFont(font);       // Unload custom font (already drawn used on image)

    Texture2D texture = LoadTextureFromImage(parrots);      // Image converted to texture, uploaded to GPU memory (VRAM)
    UnloadImage(parrots);   // Once image has been converted to texture and uploaded to VRAM, it can be unloaded from RAM

    SetTargetFPS(60);
    //---------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(texture, screenWidth / 2 - texture.width / 2, screenHeight / 2 - texture.height / 2 - 40, WHITE);
        DrawRectangleLines(screenWidth / 2 - texture.width / 2, screenHeight / 2 - texture.height / 2 - 40, texture.width, texture.height, DARKGRAY);

        DrawText("We are drawing only one texture from various images composed!", 240, 350, 10, DARKGRAY);
        DrawText("Source images have been cropped, scaled, flipped and copied one over the other.", 190, 370, 10, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(texture);       // Texture unloading

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}