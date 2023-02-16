#include <cstdlib>
#include <ctime>

namespace Settings
{
	const static int KEY_UP = 72;
	const static int KEY_DOWN = 80;
	const static int KEY_LEFT = 75;
	const static int KEY_RIGHT = 77;

	const static int HEIGHT = 25;
	const static int WIDTH = 25;

	const static char NEUTRAL_TILE = 'x';
	const static char PLAYER_TILE = 'P';
	const static char ENEMY_TILE = 'E';
	const static char FRUIT_TILE = 'F';

// Unit
	const static int GetRandomPositionX() { return rand() % WIDTH; }
	const static int GetRandomPositionY() { return rand() % HEIGHT; }

	const static int PLAYER_LIVES = 3;
}
