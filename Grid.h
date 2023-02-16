#pragma once

#include "Tile.h"

#include <vector>

class Grid
{
public:
	std::vector<std::vector<Tile>> CreateGrid(int width, int height, const char tile);
};

