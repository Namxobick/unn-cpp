#include "Food.h"

Food::Food(std::pair<int, int> position, char foodSyle)
{
	_position = position;
	_foodSyle = foodSyle;
}

std::pair<int, int> Food::GetPosition() const
{
	return _position;
}

void Food::GenerateFood(int width, int height)
{
	srand(time(0));
	_position.first = rand() % (width - 2) + 1;
	_position.second = rand() % (height - 2) + 1;
}

char Food::GetFoodStyle() const
{
	return _foodSyle;
}
