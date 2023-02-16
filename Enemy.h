#pragma once

#include "Unit.h"

class Enemy : public Unit
{
public:
	void Init() override;

	char GetTile() override { return mTile; };
	int GetPositionX() { return mTilePositionX; }
	int GetPositionY() { return mTilePositionY; }

	void MoveEnemy(int x, int y);
};

