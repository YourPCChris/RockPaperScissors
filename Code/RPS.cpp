/*
 * Rock Paper Scissors game with a GUI using Raylib
 * Christopher Bennett
 * Start: 03/01/2025
 * */

#include "raylib.h"
#include <iostream>


using namespace std;


class Player
{
	public:
		int num;
		int choice;

		Player(int number)
		{
			num = number;
			choice = -1;
		}

		void Make_Rock(){choice = 0;}
		void Make_Paper(){choice = 1;}
		void Make_Scissors(){choice = 2;}
};


void DrawWindow()
{
	ClearBackground(BLACK);
	DrawText("Player One", GetScreenWidth() / 4, 10, 20, WHITE);
	DrawText("Player Two", GetScreenWidth() * 0.75, 10, 20, WHITE);
}



int main()
{
	cout << "We Ball" << endl;

	Player Pone(1);
	Player Ptwo(2);

	//cout << "Player One: " << Pone.num << "\n";
	//cout << "Player Two: " << Ptwo.num << "\n";
	
	//Setting Up window
	InitWindow(1000, 800, "RPS");
	SetWindowState(FLAG_VSYNC_HINT);
	
	
	while (!WindowShouldClose())
	{
		BeginDrawing();
			DrawWindow();
		EndDrawing();
	}
	CloseWindow();

	return 0;
}


