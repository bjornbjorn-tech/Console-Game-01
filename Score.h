#pragma once
class Score
{
public:
	void Init();
	void UpdateScore();

	int GetScore() const;

private:
	int mScore;
};

