#pragma once
#include <string>
#include "Table.h"

class ExpressionValidator
{
private:
	Table<std::string, int> operations;
public:
	ExpressionValidator();
	ExpressionValidator(Table<std::string, int>& operations);
	bool IsExpressionCorrect(const std::string& expression);
};

