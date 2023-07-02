#pragma once
#include "Table.h"
#include <string>
#include <functional>

enum TokenType 
{
	Number,
	Letters,
	Operation,
	Default,
};

struct Token {
	TokenType type;
	std::string literal;
	Token(TokenType type = Default, std::string literal = "")
	{
		this->type = type;
		this->literal = literal;
	}
};

class ExpressionSeparator
{
private:
	Table<std::string, int> operations;


public:
	ExpressionSeparator();
	ExpressionSeparator(Table<std::string, int>& operations);

	std::vector<Token> GetTokens(const std::string& expression);
};
