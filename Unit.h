#pragma once
class Unit
{
public:
	virtual void Init() = 0;
	virtual char GetTile() = 0;

protected:
	int mTilePositionX;
	int mTilePositionY;
	char mTile;
};

