#include "GameMap.h"
void ClearScreen()
{
	COORD cursorPosition;   
	cursorPosition.X = 0;   
	cursorPosition.Y = 0;   
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

GameMap::GameMap(int width, int hieght)
{
	_width = width;
	_hieght = hieght;
	_board = std::vector<std::vector<char>>(_hieght, std::vector<char>(_width, ' '));
}

int GameMap::GetWidth() const
{
	return _width;
}

int GameMap::GetHeight() const
{
	return _hieght;
}

std::vector<std::pair<int, int>> GameMap::GetWall() const
{
	/*std::vector::at - в отличие от operator[], автоматически проверяет, находится ли i в пределах допустимых элементов в векторе,
	и выдает исключение out_of_range , если это не так. */
	std::vector<std::pair<int, int>> wallPoints;
	
	for (int i = 0; i < _board.size(); i++)
		for (int j = 0; j < _board.at(0).size(); j++)
			if ((i == 0 || i == _board.size() - 1) || (j == 0 || j == _board[0].size() - 1))
				wallPoints.push_back(std::make_pair(j, i));

	return wallPoints;
}

void GameMap::Draw(const Snake& snake, const Food& food)
{
	ClearScreen();
	auto foodPos = food.GetPosition();
	auto snakeBody = snake.GetBody();

	for (int i = 0; i < _board.size(); i++)
		for (int j = 0; j < _board[0].size(); j++) 
		{
			if ((i == 0 || i == _board.size() - 1) || (j == 0 || j == _board[0].size() - 1))
				_board.at(i).at(j) = '#';
			else
				_board.at(i).at(j) = ' ';
		}

	_board.at(foodPos.second).at(foodPos.first) = food.GetFoodStyle();

	for (const auto& point : snakeBody)
		_board.at(point.second).at(point.first) = snake.GetBodyStyle();
	_board.at(snake.GetHead().second).at(snake.GetHead().first) = snake.GetHeadStyle();

	for (const auto& row : _board) {
		for (const auto& point : row)
			std::cout << point;

		std::cout << std::endl;
	}
	std::cout << "Score = " << snake.GetLength() - 5 << std::endl;
}
