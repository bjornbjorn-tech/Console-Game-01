#include "Game.h"
#include "Settings.h"

#include <iostream>

void Game::Init()
{
	mLevel.CreateGrid(Settings::WIDTH, Settings::HEIGHT);
}

void Game::Update()
{
	mLevel.UpdateGrid();
}

void Game::Draw()
{
	system("cls");
	mLevel.RenderGrid();
}