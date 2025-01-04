/*
 * Rock Paper Scissors game with a GUI using Raylib
 * Christopher Bennett
 * Start: 03/01/2025
 * */

#include "raylib.h"
#include <iostream>
#include <string>
#include <cmath>


using namespace std;


class Player
{
	public:
		int num;
		string choice;

		Player(int number)
		{
			num = number;
			choice = "";
		}

		void Make_Rock(){choice = "ROCK";}
		void Make_Paper(){choice = "PAPER";}
		void Make_Scissors(){choice = "SCISSORS";}
		void MakeRandomChoice() 
		{
		       int num = rand() % 3;
		       switch (num)
		       {
			       case 0:
				       choice = "ROCK";
				       break;
			       case 1:
				       choice = "PAPER";
				       break;
			       case 2:
				       choice = "SCISSORS";
				       break;				       
		       }
		}
};


void DrawWindow(int screenWidth, int screenHeight, string P1, string P2, int winner)
{
	ClearBackground(BLUE);
	DrawText("Player One", GetScreenWidth() / 4, 10, 20, WHITE);
	DrawText("Player Two", GetScreenWidth() * 0.75, 10, 20, WHITE);
	DrawText(P1.c_str(), screenWidth/4, screenHeight/2, 50, RED);
	DrawText(P2.c_str(), screenWidth*0.75, screenHeight/2, 50, RED);
	
	switch (winner)
	{
		case 0:
			DrawText("DRAW", screenWidth/5, screenHeight*0.2, 70, YELLOW);
			break;
		case 1:
			DrawText("Winner : Player One", screenWidth/5, screenHeight*0.2, 70, YELLOW);
			break;
		case 2:
			DrawText("Winner : Player TWO", screenWidth/5, screenHeight*0.2, 70, YELLOW);
			break;
	}
}

void TakeInputs(Player* Pone, Player* Ptwo)
{
	if (IsKeyDown(KEY_Q)){
		Pone->Make_Rock();
		Ptwo->MakeRandomChoice();
	}else if (IsKeyDown(KEY_W)){
		Pone->Make_Paper();
		Ptwo->MakeRandomChoice();
	}else if (IsKeyDown(KEY_E)){
		Pone->Make_Scissors();
		Ptwo->MakeRandomChoice();
	}
}	

//Decising the winner
int Battle(string* playerOne, string* playerTwo)
{
	string one = *playerOne;
	string two = *playerTwo;
	
	//Draw
	if (one == two){return 0;}
	//Player One Wins
	if (one == "ROCK" && two == "SCISSORS"){return 1;}
	if (one == "PAPER" && two == "ROCK"){return 1;}
	if (one == "SCISSORS" && two == "PAPER"){return 1;}
	//Player Two Wins
	
	return 2;
}


int main()
{
	cout << "We Ball" << endl;

	const int screenWidth = 1000;
	const int screenHeight = 800;
	srand(time(0));

	Player Pone(1);
	Player Ptwo(2);

	//cout << "Player One: " << Pone.num << "\n";
	//cout << "Player Two: " << Ptwo.num << "\n";
	
	//Setting Up window
	InitWindow(screenWidth, screenHeight, "RPS");
	SetWindowState(FLAG_VSYNC_HINT);


	while (!WindowShouldClose())
	{
		TakeInputs(&Pone, &Ptwo);
		BeginDrawing();
			DrawWindow(
					screenWidth, 
					screenHeight, 
					Pone.choice, 
					Ptwo.choice,
					Battle(&Pone.choice, &Ptwo.choice)
				  );
		EndDrawing();
	}
	CloseWindow();

	return 0;
}


