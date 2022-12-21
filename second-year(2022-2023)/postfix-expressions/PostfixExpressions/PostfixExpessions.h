#pragma once
#include <string>
#include "TStack.h"
#include "Table.h"
#include "ExpressionValidator.h"
#include "ExpressionSeparator.h"

class PostfixExpessions
{
private:
	Table<std::string, int> operations;
	ExpressionValidator expressionValidator;
	ExpressionSeparator expressionSeparator;

	double TryGetResultUnaryFunction(std::string operation, double argument);
	double TryGetResultBinaryFunction(std::string operation, double firstArgument, double secondArgument);
	double TryGetValue(Token token, Table<std::string, double>* valueLetters);


public:
	PostfixExpessions();
	PostfixExpessions(Table<std::string, int>& operations);
	std::string TryConvertExpessions(const std::string& expression);

	double TryGetResult(const std::string& postExpression, Table<std::string, double>* valueLetters = nullptr);
};

