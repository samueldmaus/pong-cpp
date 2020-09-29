#pragma once

class Item
{
public:
	int score = 0;
	int lives = 3;
	int level = 1;
	int getLives();
	int subtractLife();
	int getScore();
	int addScore();
};