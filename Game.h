#pragma once

#include "Level.h"

class Game
{
public:
	void Init();
	void Update();
	void Draw();

private:
	Level mLevel;
};

