#pragma once
class Tile
{
public:
	int x;
	int y;
	int g;
	int h; 
	int f;
	char tile;
	Tile* parent;
};

