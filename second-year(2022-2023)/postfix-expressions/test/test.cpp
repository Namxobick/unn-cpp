#include "pch.h"
#include "../PostfixExpressions/ExpressionValidator.cpp"
#include "../PostfixExpressions/PostfixExpessions.cpp"
#include "../PostfixExpressions/ExpressionSeparator.cpp"
#include "../PostfixExpressions/Table.h"
#include "../PostfixExpressions/TStack.h"

TEST(ExpressionValidator, ExpressionIsCorrect)
 {
	std::string expression = "6+4.5-ab*sin(x)/3-x";
	bool result = ExpressionValidator().IsExpressionCorrect(expression);

	EXPECT_EQ(true, result);
}

TEST(ExpressionValidator, ExpressionIsntCorrect_TwoOperationsInRow)
{
	std::string expression = "5-+a";
	bool result = ExpressionValidator().IsExpressionCorrect(expression);

	EXPECT_EQ(false, result);
}

TEST(ExpressionValidator, ExpressionIsntCorrect_ClosingBracket)
{
	std::string expression = ")5-+a)";
	bool result = ExpressionValidator().IsExpressionCorrect(expression);

	EXPECT_EQ(false, result);
}

TEST(ExpressionValidator, ExpressionIsntCorrect_OpeningBracket)
{
	std::string expression = "(f+b";
	bool result = ExpressionValidator().IsExpressionCorrect(expression);

	EXPECT_EQ(false, result);
}

TEST(ExpressionValidator, ExpressionIsntCorrect_ExtraBrackets)
{
	std::string expression = "6+4.5-a(x)/3-x";
	bool result = ExpressionValidator().IsExpressionCorrect(expression);

	EXPECT_EQ(false, result);
}

TEST(ExpressionValidator, ExpressionIsntCorrect_EmptyBrackets1)
{
	std::string expression = "()";
	bool result = ExpressionValidator().IsExpressionCorrect(expression);

	EXPECT_EQ(false, result);
}

TEST(ExpressionValidator, ExpressionIsntCorrect_EmptyBrackets2)
{
	std::string expression = "6+4.5-sin()/3-x";
	bool result = ExpressionValidator().IsExpressionCorrect(expression);

	EXPECT_EQ(false, result);
}

TEST(ExpressionValidator, ExpressionIsntCorrect_EmptyBrackets3)
{
	std::string expression = "6+4.5-sin()a/3-x";
	bool result = ExpressionValidator().IsExpressionCorrect(expression);

	EXPECT_EQ(false, result);
}

TEST(ExpressionValidator, ExpressionIsntCorrect_UnaryMinus1)
{
	std::string expression = "-a+(-5/2)";
	bool result = ExpressionValidator().IsExpressionCorrect(expression);

	EXPECT_EQ(true, result);
}

TEST(ExpressionValidator, ExpressionIsntCorrect_UnaryMinus2)
{
	std::string expression = "-sin(-5)+(-a/2)";
	bool result = ExpressionValidator().IsExpressionCorrect(expression);

	EXPECT_EQ(true, result);
}

TEST(ExpressionValidator, ExpressionIsntCorrect_UnaryMinus3)
{
	std::string expression = "-(-sin(-x)/2)";
	bool result = ExpressionValidator().IsExpressionCorrect(expression);

	EXPECT_EQ(true, result);
}


TEST(PostfixExpessions, ConvertExpression1)
{
	std::string expression = "6+4.5-ab*sin(x)/3-x";
	std::string ans = "6 4.5 + ab x sin * 3 / - x -";
	std::string result = PostfixExpessions().TryConvertExpessions(expression);

	EXPECT_EQ(ans, result);
}

TEST(PostfixExpessions, GetResult1)
{
	Table<std::string, double> table;
	table.TryInsert("ab", 24.4);
	table.TryInsert("x", 3.1);
	std::string postfixExpression = "6 4.5 + ab x sin * 3 / - x -";
	double ab = 24.4;
	double x = 3.1;
	double ans = 6+4.5-ab*sin(x)/3-x;
	double result = PostfixExpessions().TryGetResult(postfixExpression, &table);

	EXPECT_NEAR(ans, result, 0.00001);
}

TEST(PostfixExpessions, ConvertExpression2)
{
	std::string expression = "sqrt(x)-1/2*sin(x^2-2)";
	std::string ans = "x sqrt 1 2 / x 2 ^ 2 - sin * -";
	std::string result = PostfixExpessions().TryConvertExpessions(expression);

	EXPECT_EQ(ans, result);
}

TEST(PostfixExpessions, GetResult2)
{
	Table<std::string, double> table;
	table.TryInsert("x", 3.1);
	std::string postfixExpression = "x sqrt 1 2 / x 2 ^ 2 - sin * -";
	double x = 3.1;
	double ans = sqrt(3.1) - 1 / double(2) * sin(pow(3.1, 2) - 2);
	double result = PostfixExpessions().TryGetResult(postfixExpression, &table);

	EXPECT_NEAR(ans, result, 0.00001);
}

TEST(PostfixExpessions, ConvertExpression3)
{
	std::string expression = "a+(sqrt(sin(cos(x/2))+42+5/x))^(a/x)";
	std::string ans = "a x 2 / cos sin 42 + 5 x / + sqrt a x / ^ +";
	std::string result = PostfixExpessions().TryConvertExpessions(expression);

	EXPECT_EQ(ans, result);
}

TEST(PostfixExpessions, GetResult3)
{
	Table<std::string, double> table;
	table.TryInsert("x", -2.4);
	table.TryInsert("a", 4.1);
	std::string postfixExpression = "a x 2 / cos sin 42 + 5 x / + sqrt a x / ^ +";
	double x = -2.4;
	double a = 4.1;
	double ans = a + pow((sqrt(sin(cos(x/double(2)))+42+5/x)),(a/x));
	double result = PostfixExpessions().TryGetResult(postfixExpression, &table);

	EXPECT_NEAR(ans, result, 0.00001);
}

TEST(PostfixExpessions, ConvertExpression4)
{
	std::string expression = "-a+(-5/2)";
	std::string ans = "a - 5 2 / - +";
	std::string result = PostfixExpessions().TryConvertExpessions(expression);

	EXPECT_EQ(ans, result);
}

TEST(PostfixExpessions, GetResult4)
{
	Table<std::string, double> table;
	table.TryInsert("a", 4.1);
	std::string postfixExpression = "a - 5 2 / - +";
	double a = 4.1;
	double ans = -a + (-5/double(2));
	double result = PostfixExpessions().TryGetResult(postfixExpression, &table);

	EXPECT_NEAR(ans, result, 0.00001);
}

TEST(PostfixExpessions, ConvertExpression5)
{
	std::string expression = "-sin(-5)+(-a/2)";
	std::string ans = "5 - sin - a 2 / - +";
	std::string result = PostfixExpessions().TryConvertExpessions(expression);

	EXPECT_EQ(ans, result);
}

TEST(PostfixExpessions, GetResult5)
{
	Table<std::string, double> table;
	table.TryInsert("a", -4.1);
	std::string postfixExpression = "5 - sin - a 2 / - +";
	double a = -4.1;
	double ans = -sin(-5)+(-a/(double(2)));
	double result = PostfixExpessions().TryGetResult(postfixExpression, &table);

	EXPECT_NEAR(ans, result, 0.00001);
}

TEST(PostfixExpessions, ConvertExpression6)
{
	std::string expression = "-(-sin(-x)/2)";
	std::string ans = "x - sin 2 / - -";
	std::string result = PostfixExpessions().TryConvertExpessions(expression);

	EXPECT_EQ(ans, result);
}

TEST(PostfixExpessions, GetResult6)
{
	Table<std::string, double> table;
	table.TryInsert("x", 4.1);
	std::string postfixExpression = "x - sin 2 / - -";
	double x = 4.1;
	double ans = -(-sin(-x)/double(2));
	double result = PostfixExpessions().TryGetResult(postfixExpression, &table);

	EXPECT_NEAR(ans, result, 0.00001);
}

TEST(PostfixExpessions, GetResult_DivisionByZero)
{
	std::string postfixExpression = "2 0 /";

	EXPECT_THROW(PostfixExpessions().TryGetResult(postfixExpression), std::invalid_argument);
}

TEST(PostfixExpessions, GetResult_SquareRootOfNegativeNumber)
{
	Table<std::string, double> table;
	table.TryInsert("a", -2.4);
	std::string postfixExpression = "a sqrt";
	EXPECT_THROW(PostfixExpessions().TryGetResult(postfixExpression), std::invalid_argument);
}

