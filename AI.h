//#pragma once
//#ifndef _AI_H
//#define _AI_H
//#include "raylib.h"
//#include "Paddle.h"
//#include "Ball.h"
//#include "Court.h"
//#include"iostream"
//#include<fstream>
//using namespace std;
//
//class AI
//{
//	int PlayerOne_Score;
//	int PlayerTwo_Score;
//	Ball* ball;
//	Paddle* rightPaddle;
//	Paddle* leftPaddle;
//	Court* court;
//
//public:
//	const char* winnerText1 = nullptr;
//	const char* winnerText2 = nullptr;
//	const char* winnerText3 = nullptr;
//	float tempYL = (GetScreenHeight() / 2.0);
//	float tempYR = (GetScreenHeight() / 2.0);
//	float tempBX = (GetScreenWidth() / 2.0);
//	float tempBY = (GetScreenHeight() / 2.0);
//	float tempBSX = 300;
//	float tempBSY = 300;
//
//	AI()
//	{
//		this->ball = ball;
//		this->rightPaddle = rightPaddle;
//		this->leftPaddle = leftPaddle;
//		this->court = court;
//		PlayerOne_Score = 0;
//		PlayerTwo_Score = 0;
//	}
//
//
//	void PlayerVSComputer(Paddle* rightPaddle, Paddle* leftPaddle, Ball* ball)
//	{
//
//		if (PlayerOne_Score >= 2 && (PlayerOne_Score - PlayerTwo_Score) > 1)
//		{
//			fstream file;
//			file.open("score.txt", ios::app);
//			if (!file)
//			{
//				
//			}
//			else
//			{
//				file<< PlayerOne_Score;
//				file << PlayerTwo_Score;
//			}
//			file.close();
//			winnerText1 = "You Wins!";
//			winnerText3 = "Press Space Bar to start again";
//		}
//		if (PlayerTwo_Score >= 2 && (PlayerTwo_Score - PlayerOne_Score) > 1)
//		{
//			winnerText2 = "AI Win!";
//			winnerText3 = "Press Space Bar to Start again";
//		}
//		if (winnerText1 && IsKeyPressed(KEY_SPACE))
//		{
//			ball->SetX(GetScreenWidth() / 2.0);
//			ball->SetY(GetScreenHeight() / 2.0);
//			ball->SetSpeedX(300);
//			ball->SetSpeedY(0);
//			winnerText1 = nullptr;
//			winnerText2 = nullptr;
//			winnerText3 = nullptr;
//
//			tempBX = (GetScreenWidth() / 2.0);
//			tempBY = (GetScreenHeight() / 2.0);
//			tempBSX = 300;
//			tempBSY = 300;
//			PlayerOne_Score = 0;
//			PlayerTwo_Score = 0;
//		}
//		if (winnerText2 && IsKeyPressed(KEY_SPACE))
//		{
//			ball->SetX(GetScreenWidth() / 2.0);
//			ball->SetY(GetScreenHeight() / 2.0);
//			ball->SetSpeedX(-300);
//			ball->SetSpeedY(0);
//			winnerText1 = nullptr;
//			winnerText2 = nullptr;
//			winnerText3 = nullptr;
//
//			tempBX = (GetScreenWidth() / 2.0);
//			tempBY = (GetScreenHeight() / 2.0);
//			tempBSX = 300;
//			tempBSY = 300;
//			PlayerOne_Score = 0;
//			PlayerTwo_Score = 0;
//
//		}
//		if (!winnerText1 && !winnerText2)
//		{
//			tempBX += ball->GetSpeedX() * GetFrameTime();
//			ball->SetX(tempBX);
//			tempBY += ball->GetSpeedY() * GetFrameTime();
//			ball->SetY(tempBY);
//
//			if (ball->GetY() < 149)
//			{
//				ball->SetY(150);
//				ball->SetSpeedY(tempBSY);
//			}
//			if (ball->GetY() > 499)
//			{
//				ball->SetY(500);
//				ball->SetSpeedY(-tempBSY);
//			}
//
//			leftPaddle->SetY(tempBY);
//
//			if (IsKeyDown(KEY_UP))
//			{
//				tempYR = tempYR - (rightPaddle->GetSpeed() * GetFrameTime());
//				rightPaddle->SetY(tempYR);
//			}
//			if (IsKeyDown(KEY_DOWN))
//			{
//				tempYR = tempYR + (rightPaddle->GetSpeed() * GetFrameTime());
//				rightPaddle->SetY(tempYR);
//			}
//
//			if (CheckCollisionCircleRec(ball->Vect(), ball->GetRadius(), leftPaddle->GetRect()))
//			{
//				if (ball->GetSpeedX() < 0)
//				{
//					tempBSX *= -1.1;
//					ball->SetSpeedX(tempBSX);
//					ball->SetSpeedY(((ball->GetY() - leftPaddle->GetY()) / (leftPaddle->GetHeight() / 2) * ball->GetSpeedX()));
//				}
//			}
//			if (CheckCollisionCircleRec(ball->Vect(), ball->GetRadius(), rightPaddle->GetRect()))
//			{
//				if (ball->GetSpeedX() > 0)
//				{
//					tempBSX *= -1.1;
//					ball->SetSpeedX(tempBSX);
//					ball->SetSpeedY(((ball->GetY() - rightPaddle->GetY()) / (rightPaddle->GetHeight() / 2) * -ball->GetSpeedX()));
//				}
//			}
//
//
//
//			if (ball->GetX() < -1)
//			{
//				PlayerOne_Score = PlayerOne_Score + 1;
//				ball->SetX(GetScreenWidth() / 2.0);
//				ball->SetY(GetScreenHeight() / 2.0);
//				ball->SetSpeedX(300);
//				ball->SetSpeedY(0);
//
//				tempBX = (GetScreenWidth() / 2.0);
//				tempBY = (GetScreenHeight() / 2.0);
//				tempBSX = 300;
//				tempBSY = 300;
//
//			}
//			if (ball->GetX() > GetScreenWidth() + 1)
//			{
//				PlayerTwo_Score = PlayerTwo_Score + 1;
//
//
//				ball->SetX(GetScreenWidth() / 2.0);
//				ball->SetY(GetScreenHeight() / 2.0);
//				ball->SetSpeedX(-300);
//				ball->SetSpeedY(0);
//
//				tempBX = (GetScreenWidth() / 2.0);
//				tempBY = (GetScreenHeight() / 2.0);
//				tempBSX = 300;
//				tempBSY = 300;
//			}
//		}
//
//
//
//		BeginDrawing();
//		ClearBackground(BLACK);
//		court->Draw();
//		ball->Draw();
//		leftPaddle->Draw();
//		rightPaddle->Draw();
//
//		DrawText(TextFormat("Player Score: %d", PlayerOne_Score), 600, 550, 20, WHITE);
//		DrawText(TextFormat("AI Score: %d", PlayerTwo_Score), 40, 550, 20, WHITE);
//
//
//		if (winnerText1)
//		{
//			int textWidth1 = MeasureText(winnerText1, 60);
//			int textWidth2 = MeasureText(winnerText2, 60);
//			int textWidth3 = MeasureText(winnerText3, 60);
//			DrawText(winnerText1, 250, 50, 30, BLUE);
//			DrawText(winnerText2, 250, 50, 30, BLUE);
//			DrawText(winnerText3, 175, 90, 25, BLUE);
//		}
//		if (winnerText2)
//		{
//			int textWidth1 = MeasureText(winnerText1, 60);
//			int textWidth2 = MeasureText(winnerText2, 60);
//			int textWidth3 = MeasureText(winnerText3, 60);
//			DrawText(winnerText1, 250, 50, 30, BLUE);
//			DrawText(winnerText2, 250, 50, 30, BLUE);
//			DrawText(winnerText3, 175, 90, 25, BLUE);
//
//		}
//		EndDrawing();
//
//	}
//
//};
//#endif