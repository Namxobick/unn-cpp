#pragma once
#include <deque>
class Snake
{
private:
	std::deque<std::pair<int, int>> _body;
	/*std::deque(двусторонняя очередь) — это индексированный контейнер последовательности, 
	который позволяет быстро вставлять и удалять как в начале, так и в конце. 
	Кроме того, вставка и удаление на любом конце двухсторонней очереди никогда не делает недействительными указатели или 
	ссылки на остальные элементы.
	В отличие от std::vector , элементы deque не хранятся непрерывно.
	Хранилище дека автоматически расширяется и сокращается по мере необходимости. Расширение двухсторонней очереди дешевле, 
	чем расширение std::vector , потому что оно не требует копирования существующих элементов в новое место в памяти. 
	С другой стороны, деки обычно имеют большую минимальную стоимость памяти; очередь, содержащая только один элемент, 
	должна выделить весь свой внутренний массив (например, 8-кратный размер объекта в 64-битной libstdc++; 16-кратный размер 
	объекта или 4096 байт, в зависимости от того, что больше, в 64-битной libc++).
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

