#include "PostfixExpessions.h"
#include <cassert>

double PostfixExpessions::TryGetResultUnaryFunction(std::string operation, double argument)
{
	if (operation == "-") return -argument;
	if (operation == "+") return +argument;
	if (operation == "cos") return cos(argument);
	if (operation == "sin") return sin(argument);
	if (operation == "sqrt")
	{
		if (argument < 0) throw std::invalid_argument("Taking the square root of a negative number is not possible");
		return sqrt(argument);
	}
}

double PostfixExpessions::TryGetResultBinaryFunction(std::string operation, double firstArgument, double secondArgument)
{
	if (operation == "+") return (firstArgument + secondArgument);
	if (operation == "-") return (firstArgument - secondArgument);
	if (operation == "*") return (firstArgument * secondArgument);
	if (operation == "/")
	{
		if (secondArgument == 0) throw std::invalid_argument("Division by zero is not possible");
		return (firstArgument / secondArgument);
	}
	if (operation == "^") return (std::pow(firstArgument, secondArgument));
}

double PostfixExpessions::TryGetValue(Token token, Table<std::string, double>* valueLetters)
{
	if (token.type == Letters)
	{
		if (!valueLetters->Find(token.literal).second) throw "No value for letters";
		return valueLetters->Find(token.literal).first;
	}
	else
		return std::stod(token.literal);
}

PostfixExpessions::PostfixExpessions()
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

PostfixExpessions::PostfixExpessions(Table<std::string, int>& operations)
{
	this->operations = operations;
}

std::string PostfixExpessions::TryConvertExpessions(const std::string& expression)
{
	TStack<std::string> tStack;
	std::string postfixExpression = "";


	if (!expressionValidator.IsExpressionCorrect(expression))
		throw "Expression isnt correct";
	std::vector<Token> tokens = expressionSeparator.GetTokens(expression);

	for (Token token : tokens)
	{
		if (token.type == Number || token.type == Letters)
			postfixExpression += (token.literal + " ");
		else
		{
			if (token.literal == ")")
			{
				while (tStack.Top() != "(")
					postfixExpression += tStack.Pop() + " ";
				tStack.Pop();
			}
			else if (token.literal == "(")
				tStack.Push("(");
			else
			{
				int priority = operations.Find(token.literal).first;
				if (priority < 0)
					tStack.Push(token.literal);
				else
				{
					while (!tStack.IsEmpty() && (operations.Find(tStack.Top()).first < 0 || operations.Find(tStack.Top()).first >= priority))
						postfixExpression += tStack.Pop() + " ";
					tStack.Push(token.literal);
				}
			}
		}
	}
	while (!tStack.IsEmpty())
		if (tStack.Top() == "(")
			tStack.Pop();
		else
			postfixExpression += tStack.Pop() + " ";
	postfixExpression.erase(postfixExpression.size() - 1);
	return postfixExpression;
}

double PostfixExpessions::TryGetResult(const std::string& postExpression, Table<std::string, double>* valueLetters)
{
	TStack<Token> tStack;
	std::vector<Token> tokens = expressionSeparator.GetTokens(postExpression);
	for (Token token : tokens)
	{
		if (token.type == Letters || token.type == Number)
			tStack.Push(token);
		else
		{
			double argument = TryGetValue(tStack.Pop(), valueLetters);
			if (tStack.IsEmpty() || operations.Find(token.literal).first < 0)
				tStack.Push(Token(Number, std::to_string(TryGetResultUnaryFunction(token.literal, argument))));
			else
			{
				double secondArgument = argument;
				double firstArgument = TryGetValue(tStack.Pop(), valueLetters);
				tStack.Push(Token(Number, std::to_string(TryGetResultBinaryFunction(token.literal, firstArgument, secondArgument))));
			}
		}
	}
	return std::stod(tStack.Pop().literal);
}