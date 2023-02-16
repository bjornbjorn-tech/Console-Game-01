#pragma once

#include <vector>

#include "Player.h"
#include "Enemy.h"
#include "Fruit.h"
#include "Score.h"
#include "Grid.h"
#include "Tile.h"

class Level
{
public:
	void CreateGrid(int x, int y);
	void UpdateGrid();
	void RenderGrid();
	void ResetGrid();
	void HandleFruitCollision();

	std::vector<Tile*> FindPath(int startX, int startY, int endX, int endY);

private:
	std::vector<std::vector<Tile>> mLevelGrid;

	Player mPlayer;
	Enemy mEnemy;
	Fruit mFruit;
	Score mScore;
	Grid mGrid;

	void UpdateTilePositions();
	bool CheckCollisionWithFruit();
	bool CheckCollisionWithEnemy();
	void UpdateEnemy();

	int HeuristicCostEstimate(Tile* start, Tile* end);
	Tile* GetLowestFScoreTile(std::vector<Tile*>& tiles);
	void RemoveTileFromList(std::vector<Tile*>& tiles, Tile* tile);
	std::vector<Tile*> GetNeighbors(Tile* tile);
	bool ContainsTile(std::vector<Tile*>& list, Tile* tile);
};

