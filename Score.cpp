#include "Score.h"

void Score::Init()
{
	mScore = 0;
}

void Score::UpdateScore()
{
	mScore += 1;
}

int Score::GetScore() const 
{
	return mScore;
}