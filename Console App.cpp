// Console App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Game.h"

int main()
{
	Game mGame;

	mGame.Init();
	mGame.Draw();

	std::cout << "\nPress to start" << std::endl;

	while (true)
	{
		mGame.Update();
		mGame.Draw();
	}

	return 0;
}