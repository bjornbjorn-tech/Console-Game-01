#include "Level.h"
#include "Settings.h"

#include <iostream>
#include <queue>

void Level::CreateGrid(int x, int y)
{
	mPlayer.Init();
	mEnemy.Init();
	mFruit.Init();
	mScore.Init();

	mLevelGrid = mGrid.CreateGrid(x, y, Settings::NEUTRAL_TILE);
}

void Level::ResetGrid()
{
	CreateGrid(Settings::WIDTH, Settings::HEIGHT);
}

void Level::UpdateEnemy()
{
	int currentStep = 0;
	bool hasMoved = false;
	std::vector<Tile*> path = FindPath(mEnemy.GetPositionX(), mEnemy.GetPositionY(), mPlayer.GetPositionX(), mPlayer.GetPositionY());

	if (path.empty())
	{
		return;
	}

	if (currentStep == path.size())
	{
		currentStep = 0;
		hasMoved = false;
	}

	if (!hasMoved)
	{
		int nextX = path[currentStep]->x;
		int nextY = path[currentStep]->y;

		mEnemy.MoveEnemy(nextX, nextY);

		currentStep++;
		hasMoved = true; 
	}
}

void Level::UpdateGrid()
{
	UpdateTilePositions();

	if (CheckCollisionWithEnemy())
	{
		ResetGrid();
	}

	if (CheckCollisionWithFruit())
	{
		HandleFruitCollision();
	}
}

void Level::HandleFruitCollision()
{
	mLevelGrid[mEnemy.GetPositionY()][mEnemy.GetPositionX()].tile = 'x';
	mScore.UpdateScore();
	mFruit.SpawnFruit();
	mEnemy.Init();
}

void Level::UpdateTilePositions()
{
	const int lastPlayerPositionX = mPlayer.GetPositionX();
	const int lastPlayerPositionY = mPlayer.GetPositionY();
	const int lastEnemyPositionX = mEnemy.GetPositionX();
	const int lastEnemyPositionY = mEnemy.GetPositionY();

	mPlayer.MovePlayer();

	UpdateEnemy();

	mLevelGrid[lastPlayerPositionY][lastPlayerPositionX].tile = 'x';
	mLevelGrid[lastEnemyPositionY][lastEnemyPositionX].tile = 'x';
	mLevelGrid[mEnemy.GetPositionY()][mEnemy.GetPositionX()].tile = mEnemy.GetTile();
	mLevelGrid[mFruit.GetPositionY()][mFruit.GetPositionX()].tile = mFruit.GetTile();
	mLevelGrid[mPlayer.GetPositionY()][mPlayer.GetPositionX()].tile = mPlayer.GetTile();
}

bool Level::CheckCollisionWithFruit()
{
	return (mPlayer.GetPositionX() == mFruit.GetPositionX() && mPlayer.GetPositionY() == mFruit.GetPositionY());
}

bool Level::CheckCollisionWithEnemy()
{
	return (mPlayer.GetPositionX() == mEnemy.GetPositionX() && mPlayer.GetPositionY() == mEnemy.GetPositionY());
}

void Level::RenderGrid()
{
	for (int y = 0; y < Settings::HEIGHT; y++) {
		for (int x = 0; x < Settings::WIDTH; x++) {
			std::cout << mLevelGrid[y][x].tile;
		}
		std::cout << std::endl;
	}

	std::cout << "Score: " << mScore.GetScore() << std::endl;
}

std::vector<Tile*> Level::FindPath(int startX, int startY, int endX, int endY) {
	std::vector<Tile*> openList;
	std::vector<Tile*> closedList;

	Tile* startTile = &mLevelGrid[startY][startX];
	Tile* endTile = &mLevelGrid[endY][endX];

	openList.push_back(startTile);

	while (!openList.empty()) {
		Tile* currentTile = GetLowestFScoreTile(openList);

		if (currentTile->x == endX && currentTile->y == endY) {
			std::vector<Tile*> path;
			Tile* current = currentTile;
			while (current->parent != nullptr) {
				path.push_back(current);
				Tile* temp = current;
				current = current->parent;
				temp->parent = nullptr;
			}
			std::reverse(path.begin(), path.end());
			return path;
		}

		RemoveTileFromList(openList, currentTile);
		closedList.push_back(currentTile);

		std::vector<Tile*> neighbors = GetNeighbors(currentTile);
		for (Tile* neighbor : neighbors) {
			if (ContainsTile(closedList, neighbor)) {
				continue;
			}

			int cost = currentTile->g + HeuristicCostEstimate(neighbor, endTile);

			if (cost < neighbor->g || !ContainsTile(openList, neighbor)) {
				neighbor->g = cost;
				neighbor->h = HeuristicCostEstimate(neighbor, endTile);
				neighbor->f = neighbor->g + neighbor->h;
				neighbor->parent = currentTile;

				if (!ContainsTile(openList, neighbor)) {
					openList.push_back(neighbor);
				}
			}
		}
	}
	return std::vector<Tile*>();
}

std::vector<Tile*> Level::GetNeighbors(Tile* tile)
{
	std::vector<Tile*> neighbors;

	if (tile->x > 0) {
		neighbors.push_back(&mLevelGrid[tile->y][tile->x - 1]);
	}
	if (tile->x < Settings::WIDTH - 1) {
		neighbors.push_back(&mLevelGrid[tile->y][tile->x + 1]);
	}
	if (tile->y > 0) {
		neighbors.push_back(&mLevelGrid[tile->y - 1][tile->x]);
	}
	if (tile->y < Settings::HEIGHT - 1) {
		neighbors.push_back(&mLevelGrid[tile->y + 1][tile->x]);
	}

	return neighbors;
}

bool Level::ContainsTile(std::vector<Tile*>& list, Tile* tile)
{
	for (auto t : list) {
		if (t->x == tile->x && t->y == tile->y) {
			return true;
		}
	}

	return false;
}

void Level::RemoveTileFromList(std::vector<Tile*>& tiles, Tile* tile)
{
	auto it = std::find(tiles.begin(), tiles.end(), tile);
	if (it != tiles.end()) {
		tiles.erase(it);
	}
}

Tile* Level::GetLowestFScoreTile(std::vector<Tile*>& tiles)
{
	Tile* lowestFScoreTile = tiles[0];
	for (unsigned int i = 1; i < tiles.size(); i++) {
		Tile* tile = tiles[i];
		if (tile->f < lowestFScoreTile->f) {
			lowestFScoreTile = tile;
		}
	}
	return lowestFScoreTile;
}

int Level::HeuristicCostEstimate(Tile* start, Tile* end)
{
	// Calculate the Manhattan distance between two points
	int dx = abs(start->x - end->x);
	int dy = abs(start->y - end->y);
	return dx + dy;
}