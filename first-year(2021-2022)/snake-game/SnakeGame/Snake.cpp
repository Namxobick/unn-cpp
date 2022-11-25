#include "Snake.h"

Snake::Snake(int length, char headStyle, char bodyStyle, char direction)
{
	_length = length;
	_headStyle = headStyle;
	_bodyStyle = bodyStyle;
	_direction = direction;

	for (int i = 1; i <= length; i++)
		_body.push_front(std::pair<int, int>{i, 1});
}

void Snake::Move()
{
	std::pair<int, int> forwardPoint;

	switch (_direction)
	{
	case 'a':
		forwardPoint = std::make_pair(GetHead().first - 1, GetHead().second);
		break;
	case 'd':
		forwardPoint = std::make_pair(GetHead().first + 1, GetHead().second);
		break;
	case 'w':
		forwardPoint = std::make_pair(GetHead().first, GetHead().second - 1);
		break;
	case 's':
		forwardPoint = std::make_pair(GetHead().first, GetHead().second + 1);
		break;
	default:
		break;
	}

	_body.push_front(forwardPoint);
	_body.pop_back();
}

void Snake::GrowUp()
{
	_body.push_back(_body.back());
	_length++;
}

void Snake::SetDirection(char direction)
{
	switch (direction)
	{
	case 'a':
		_direction = direction;
		break;
	case 'd':
		_direction = direction;
		break;
	case 'w':
		_direction = direction;
		break;
	case 's':
		_direction = direction;
		break;

	default:
		break;
	}
}

std::pair<int, int> Snake::GetHead() const
{
	return _body.front();
}

std::deque<std::pair<int, int>> Snake::GetBody() const {
	return _body;
}

int Snake::GetLength() const
{
	return _length;
}

char Snake::GetDirection() const
{
	return _direction;
}

char Snake::GetHeadStyle() const
{
	return _headStyle;
}

char Snake::GetBodyStyle() const
{
	return _bodyStyle;
}
