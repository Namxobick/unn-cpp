#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <windows.h>
#include "Snake.h"
#include "Food.h"

class GameMap
{
private:
	std::vector<std::vector<char>> _board;
	int _width;
	int _hieght;
	
public:
	GameMap(int width = 50, int hieght = 50);

	int GetWidth() const;
	int GetHeight() const;

	std::vector<std::pair<int, int>> GetWall() const;

	void Draw(const Snake& snake, const Food& food);
};

