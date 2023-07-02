#include "ExpressionSeparator.h"

ExpressionSeparator::ExpressionSeparator()
{
	operations.TryInsert("sin", -1);
	operations.TryInsert("cos", -1);
	operations.TryInsert("sqrt", -1);
	operations.TryInsert("(", 0);
	operations.TryInsert(")", 1);
	operations.TryInsert("+", 2);
	operations.TryInsert("-", 2);
	operations.TryInsert("*", 3);
	operations.TryInsert("/", 3);
	operations.TryInsert("^", 4);
}

ExpressionSeparator::ExpressionSeparator(Table<std::string, int>& operations)
{
	this->operations = operations;
}

std::vector<Token> ExpressionSeparator::GetTokens(const std::string& expression)
{
	std::vector<Token> tokens;
	bool isLeter = false;
	std::string tempStr;

	for (size_t i = 0; i < expression.size(); i++)
	{
        char c = expression[i];  

		if (c == '-' && ((i == 0) || (expression[i - 1] == '(') || (expression[i - 2] == '(')))
		{
			Token token = Token(Operation, "-");
			tokens.push_back(token);
		}

        else if ((c <= 'z' && c >= 'a') || (c <= '9' && c >= '0') || c == '.')
        {
			if (c <= 'z' && c >= 'a')
				isLeter = true;
            tempStr += c;
			continue;
        }
		else
		{
			Token token;
			if (tempStr != "")
			{
				if (operations.Find(tempStr).second)
					token = Token(Operation, tempStr);
				else if (isLeter)
					token = Token(Letters, tempStr);
				else
					token = Token(Number, tempStr);
				tokens.push_back(token);
			}
			
			isLeter = false;
			tempStr = "";

			if (c != ' ')
				if (c == '(')
					tokens.push_back(Token(Operation, "("));
				else if (c == ')')
					tokens.push_back(Token(Operation, ")"));
				else
					tokens.push_back(Token(Operation, std::string(1, c)));
		}
	}

	if (tempStr != "")
		if (isLeter)
			tokens.push_back(Token(Letters, tempStr));
		else
			tokens.push_back(Token(Number, tempStr));

	return tokens;
}
