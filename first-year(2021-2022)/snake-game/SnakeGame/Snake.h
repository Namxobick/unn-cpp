#pragma once
#include <deque>
class Snake
{
private:
	std::deque<std::pair<int, int>> _body;
	/*std::deque(������������ �������) � ��� ��������������� ��������� ������������������, 
	������� ��������� ������ ��������� � ������� ��� � ������, ��� � � �����. 
	����� ����, ������� � �������� �� ����� ����� ������������� ������� ������� �� ������ ����������������� ��������� ��� 
	������ �� ��������� ��������.
	� ������� �� std::vector , �������� deque �� �������� ����������.
	��������� ���� ������������� ����������� � ����������� �� ���� �������������. ���������� ������������� ������� �������, 
	��� ���������� std::vector , ������ ��� ��� �� ������� ����������� ������������ ��������� � ����� ����� � ������. 
	� ������ �������, ���� ������ ����� ������� ����������� ��������� ������; �������, ���������� ������ ���� �������, 
	������ �������� ���� ���� ���������� ������ (��������, 8-������� ������ ������� � 64-������ libstdc++; 16-������� ������ 
	������� ��� 4096 ����, � ����������� �� ����, ��� ������, � 64-������ libc++).
	*/

	int _length;

	char _headStyle;
	char _bodyStyle;
	char _direction;

public:
	Snake(int length = 1, char headStyle = 'O', char bodyStyle = 'o', char direction = 'd');

	void Move();
	void SetDirection(char direction);
	void GrowUp();

	std::pair<int, int> GetHead() const;

	std::deque<std::pair<int, int>> GetBody() const;

	int GetLength() const;

	char GetDirection() const;
	char GetHeadStyle() const;
	char GetBodyStyle() const;
};

