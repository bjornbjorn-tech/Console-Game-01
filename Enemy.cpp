#include "Enemy.h"

#include "Settings.h"

void Enemy::Init()
{
	mTilePositionX = Settings::GetRandomPositionX();
	mTilePositionY = Settings::GetRandomPositionY();
	mTile = Settings::ENEMY_TILE;
}

void Enemy::MoveEnemy(int x, int y)
{
	mTilePositionX = x;
	mTilePositionY = y;
}