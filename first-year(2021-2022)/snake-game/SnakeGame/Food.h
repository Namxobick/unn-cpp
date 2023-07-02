#pragma once
#include <iostream>
class Food
{
private:
    std::pair<int, int> _position;
    char _foodSyle;

public:
    Food(std::pair<int, int> position = { 20, 10 }, char foodSyle = '*');

    std::pair<int, int> GetPosition() const;

    void GenerateFood(int width, int height);

    char GetFoodStyle () const;
};

