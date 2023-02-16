#include "Grid.h"

std::vector<std::vector<Tile>> Grid::CreateGrid(int width, int height, const char tile)
{
	std::vector<std::vector<Tile>> grid;

	grid.resize(height);
	for (int y = 0; y < height; y++) {
		grid[y].resize(width);
		for (int x = 0; x < width; x++) {
			grid[y][x].x = x;
			grid[y][x].y = y;
			grid[y][x].tile = tile;
		}
	}
	return grid;
}