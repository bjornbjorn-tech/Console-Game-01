#pragma once

#include "Unit.h"

class Fruit : public Unit
{
public:
	void Init() override;
	char GetTile() override { return mTile; };
	
	void SpawnFruit();
	
	int GetPositionX() { return mTilePositionX; }
	int GetPositionY() { return mTilePositionY; }

private:
	int mTilePositionX;
	int mTilePositionY;
	char mTile;
};

