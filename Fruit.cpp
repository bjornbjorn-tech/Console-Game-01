#include "Fruit.h"
#include "Settings.h"

#include <ctime>

void Fruit::Init()
{
	mTilePositionX = Settings::GetRandomPositionX();
	mTilePositionY = Settings::GetRandomPositionY();
	mTile = Settings::FRUIT_TILE;
}

void Fruit::SpawnFruit()
{
	mTilePositionX = Settings::GetRandomPositionX();
	mTilePositionY = Settings::GetRandomPositionY();
}