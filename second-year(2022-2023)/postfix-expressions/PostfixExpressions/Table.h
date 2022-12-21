#pragma once
#include <iostream>

// АA-дерево - https://neerc.ifmo.ru/wiki/index.php?title=AA-%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE

template <typename TypeKey, typename TypeValue>
struct Node
{
	size_t level;
	Node* parent;
	Node* left;
	Node* right;

	TypeKey key;
	TypeValue value;
};

template <typename TypeKey, typename TypeValue>
class Table
{
private:

	Node<TypeKey, TypeValue>* root;

	void FreeUpMemory(Node<TypeKey, TypeValue>* root);
	void Skew(Node<TypeKey, TypeValue>*);
	bool Split(Node<TypeKey, TypeValue>*);
	void Balance(Node<TypeKey, TypeValue>*);

	bool InsertHelp(Node<TypeKey, TypeValue>*, Node<TypeKey, TypeValue>*);
	TypeValue* SearchHelp(Node<TypeKey, TypeValue>*, TypeKey, bool change = false, TypeValue* newValue = nullptr);
	bool DeleteHelp(Node<TypeKey, TypeValue>*, Node<TypeKey, TypeValue>*, TypeKey);

public:
	Table();
	Table(std::pair<TypeKey, TypeValue>* elements);
	~Table();

	bool TryInsert(TypeKey key, TypeValue value) noexcept;
	bool TryRemove(TypeKey key) noexcept;
	bool TryChangeValue(TypeKey key, TypeValue value) noexcept;

	std::pair<const TypeValue&, bool> Find(TypeKey key);

	Table<TypeKey, TypeValue>& operator=(const Table<TypeKey, TypeValue> other);

	std::pair<TypeValue&, bool> operator[](TypeKey key);
};

template<typename TypeKey, typename TypeValue>
inline Table<TypeKey, TypeValue>::Table()
{
	root = new Node<TypeKey, TypeValue>;
	root = nullptr;
}

template<typename TypeKey, typename TypeValue>
inline Table<TypeKey, TypeValue>::Table(std::pair<TypeKey, TypeValue>* elements)
{
	for (std::pair<TypeKey, TypeValue> element : elements)
		TryInsert(element.first, element.second);
}

template<typename TypeKey, typename TypeValue>
inline void Table<TypeKey, TypeValue>::FreeUpMemory(Node<TypeKey, TypeValue>* root)
{
	if (root == nullptr)
		return;
	FreeUpMemory(root->left);
	FreeUpMemory(root->right);
	delete root;
}

template<typename TypeKey, typename TypeValue>
inline Table<TypeKey, TypeValue>::~Table()
{
	FreeUpMemory(root);
}

template<typename TypeKey, typename TypeValue>
inline bool Table<TypeKey, TypeValue>::InsertHelp(Node<TypeKey, TypeValue>* temp, Node<TypeKey, TypeValue>* ins)
{
	if (root == nullptr)
	{
		ins->parent = nullptr;
		ins->left = nullptr;
		ins->right = nullptr;
		root = ins;

		return false;
	}

	if (ins->key < temp->key)
	{
		if (temp->left)
			return InsertHelp(temp->left, ins);

		temp->left = ins;
		ins->parent = temp;
		Balance(ins);
		
		return true;
	}

	if (ins->key > temp->key)
	{
		if (temp->right)
			return InsertHelp(temp->right, ins);

		temp->right = ins;
		ins->parent = temp;
		Balance(ins);
		
		return true;
	}

	delete ins;
	return false;
}

template<typename TypeKey, typename TypeValue>
bool Table<TypeKey, TypeValue>::TryInsert(TypeKey key, TypeValue value) noexcept
{
	Node<TypeKey, TypeValue>* temp = new Node<TypeKey, TypeValue>;
	temp->key = key;
	temp->value = value;
	temp->level = 1;
	temp->left = nullptr;
	temp->right = nullptr;
	temp->parent = nullptr;
	return InsertHelp(root, temp);
}

template<typename TypeKey, typename TypeValue>
bool Table<TypeKey, TypeValue>::DeleteHelp(Node<TypeKey, TypeValue>* parent, Node<TypeKey, TypeValue>* current, TypeKey key)
{
	if (!current)
		return false;

	if (current->key == key)
	{
		if (current->left == nullptr || current->right == nullptr)
		{
			Node<TypeKey, TypeValue>* temp = current->left;
			if (current->right)
				temp = current->right;

			if (parent)
				if (parent->left == current)
					parent->left = temp;
				else
					parent->right = temp;
			else
				root = temp;
		}
		else
		{
			Node<TypeKey, TypeValue>* validSubs = current->right;
			while (validSubs->left)
				validSubs = validSubs->left;

			std::swap(current->key, validSubs->key);
			return DeleteHelp(current, current->right, current->key);
		}
		delete current;
		return true;
	}
	return DeleteHelp(current, current->left, key) || DeleteHelp(current, current->right, key);
}

template<typename TypeKey, typename TypeValue>
bool Table<TypeKey, TypeValue>::TryRemove(TypeKey key) noexcept
{
	return DeleteHelp(nullptr, root, key);
}

template<typename TypeKey, typename TypeValue>
void Table<TypeKey, TypeValue>::Skew(Node<TypeKey, TypeValue>* temp)
{
	Node<TypeKey, TypeValue>* ptr = temp->left;
	if (temp->parent->left == temp)
		temp->parent->left = ptr;
	else
		temp->parent->right = ptr;

	ptr->parent = temp->parent;
	temp->parent = ptr;
	temp->left = ptr->right;

	if (temp->left != nullptr)
		temp->left->parent = temp;

	ptr->right = temp;
	temp->level = (temp->left ? temp->left->level + 1 : 1);
}

template<typename TypeKey, typename TypeValue>
bool Table<TypeKey, TypeValue>::Split(Node<TypeKey, TypeValue>* temp)
{
	Node<TypeKey, TypeValue>* ptr = temp->right;
	if (ptr && ptr->right && (ptr->right->level == temp->level))
	{
		if (temp->parent->left == temp)
			temp->parent->left = ptr;
		else
			temp->parent->right = ptr;

		ptr->parent = temp->parent;
		temp->parent = ptr;
		temp->right = ptr->left;

		if (temp->right != nullptr)
			temp->right->parent = temp;

		ptr->left = temp;
		ptr->level = temp->level + 1;
		return true;
	}
	return false;
}

template<typename TypeKey, typename TypeValue>
void Table<TypeKey, TypeValue>::Balance(Node<TypeKey, TypeValue>* temp)
{
	temp->left = nullptr;
	temp->right = nullptr;
	temp->level = 1;

	for (temp = temp->parent; temp != root; temp = temp->parent)
	{
		if (temp->level != (temp->left ? temp->left->level + 1 : 1))
		{
			Skew(temp);
			if (temp->right == nullptr)
				temp = temp->parent;
			else if (temp->level != temp->right->level)
				temp = temp->parent;
		}

		if (temp->parent != root)
			if (!Split(temp->parent))
				break;
	}
}

template<typename TypeKey, typename TypeValue>
TypeValue* Table<TypeKey, TypeValue>::SearchHelp(Node<TypeKey, TypeValue>* temp, TypeKey key, bool change, TypeValue* newValue)
{
	if (temp == nullptr)
		throw "Key not found";

	if (key == temp->key)
		switch (change)
		{
		case(false):
			return &temp->value;
		case(true):
			temp->value = *newValue;
			return &temp->value;
		}
		
	else if (key < temp->key)
		return SearchHelp(temp->left, key, change, newValue);
	else if (key > temp->key)
		return SearchHelp(temp->right, key, change, newValue);

	throw "Key not found";
}

template<typename TypeKey, typename TypeValue>
std::pair<const TypeValue&, bool> Table<TypeKey, TypeValue>::Find(TypeKey key)
{
	TypeValue* value = new TypeValue();
	try
	{
		value = SearchHelp(root, key);
	}
	catch (const char* ex)
	{
		return std::pair<const TypeValue&, bool>(*value, false);
	}
	return std::pair<const TypeValue&, bool>(*value, true);
}

template<typename TypeKey, typename TypeValue>
bool Table<TypeKey, TypeValue>::TryChangeValue(TypeKey key, TypeValue newValue) noexcept
{
	TypeValue* value = new TypeValue();
	try
	{
		value = SearchHelp(root, key, true, &newValue);
	}
	catch (const char* ex)
	{
		return false;
	}
	return true;
}

template<typename TypeKey, typename TypeValue>
Table<TypeKey, TypeValue>& Table<TypeKey, TypeValue>::operator=(Table<TypeKey, TypeValue> other)
{
	if (this == &other)
		return *this;

	FreeUpMemory(root);
	root = other.root;
	return *this;
}

template<typename TypeKey, typename TypeValue>
std::pair<TypeValue&, bool> Table<TypeKey, TypeValue>::operator[](TypeKey key)
{
	TypeValue* value = new TypeValue();
	try
	{
		value = SearchHelp(root, key);
	}
	catch (const char* ex)
	{
		return std::pair<TypeValue&, bool>(*value, false);
	}
	return std::pair<TypeValue&, bool>(*value, true);
}