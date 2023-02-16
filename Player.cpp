#include "Player.h"
#include "Settings.h"

#include <conio.h>
#include <iostream>

void Player::Init()
{
	mTilePositionX = 1;
	mTilePositionY = 1;
	mTile = Settings::PLAYER_TILE;
}

void Player::MovePlayer()
{
	int key = _getch();
	if (key == 0xE0)
	{
		int key = _getch();
		switch (key)
		{
		case Settings::KEY_UP:
			mTilePositionY--;
			break;
		case Settings::KEY_DOWN:
			mTilePositionY++;
			break;
		case Settings::KEY_LEFT:
			mTilePositionX--;
			break;
		case Settings::KEY_RIGHT:
			mTilePositionX++;
			break;
		default:
			break;
		}
	}
	WrapAround();
}

void Player::WrapAround()
{
	if (mTilePositionX < 0)
	{
		mTilePositionX = Settings::WIDTH - 1;
	}
	else if (mTilePositionX > Settings::WIDTH - 1)
	{
		mTilePositionX = 0;
	}
	else if (mTilePositionY < 0)
	{
		mTilePositionY = Settings::HEIGHT - 1;
	}
	else if (mTilePositionY > Settings::HEIGHT - 1)
	{
		mTilePositionY = 0;
	}
}