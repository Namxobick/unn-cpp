#pragma once
#include <iostream>

template <typename Type>
class TStack
{
private:
	size_t top;
	size_t memSize;
	Type* data;
	bool isEmpty;

public:
	TStack(size_t size = 10);
	TStack(const TStack& stack);
	~TStack();
	TStack(TStack&& stack);

	void Resize();
	void Push(const Type& element);

	Type Pop();
	Type Top();

	bool IsEmpty() { return isEmpty; }
};

template<typename Type>
inline TStack<Type>::TStack(size_t size):memSize(size), top(0), isEmpty(true)
{
	if (size == 0)
		throw "The size must be positive";
	data = new Type[size];
	if (data == nullptr)
		throw "Memory was not allocated";
}

template<typename Type>
inline TStack<Type>::TStack(const TStack& stack) : memSize(stack.size), top(stack.top), isEmpty(stack.isEmpty)
{
	std::copy(stack.data, stack.data + stack.memSize, data);
}

template<typename Type>
inline TStack<Type>::~TStack()
{
	if (data != nullptr)
		delete[] data;
}

template<typename Type>
inline TStack<Type>::TStack(TStack&& stack): memSize(stack.size), top(stack.top), isEmpty(stack.isEmpty), data(nullptr)
{
	data = stack.data;
	stack.data = nullptr;
	stack.memSize = 0;
	stack.top = 0;
	stack.isEmpty = true;
}

template<typename Type>
inline void TStack<Type>::Resize()
{
	Type* newdata = new Type[memSize * 2]();
	std::copy(data, data + memSize, newdata);
	memSize *= 2;
	delete[] data;
	data = newdata;
}

template<typename Type>
inline void TStack<Type>::Push(const Type& element)
{
	if (!isEmpty && ++top == memSize)
		this->Resize();

	data[top] = element;
	isEmpty = false;
}

template<typename Type>
inline Type TStack<Type>::Pop()
{
	if (isEmpty) 
		throw "Stack is empty";
	if (top == 0) 
	{
		isEmpty = true;
		return data[top];
	}
	return data[top--];
}

template<typename Type>
inline Type TStack<Type>::Top()
{
	if (isEmpty == true) throw "Stack is empty";
	return data[top];
}