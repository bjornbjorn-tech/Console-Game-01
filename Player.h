#pragma once

#include "Unit.h"

class Player : public Unit
{
public:
	void Init() override;

	char GetTile() override { return mTile; };
	int GetPositionX() { return mTilePositionX; }
	int GetPositionY() { return mTilePositionY; }

	void MovePlayer();
	void WrapAround();

private:

};

