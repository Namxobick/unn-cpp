#include <iostream>
#include "Table.h"
#include "PostfixExpessions.h"

int main()
{
	Table<std::string, double> table;
	table.TryInsert("a", 4.1);
	std::string expression = "a - 5 2 / - +";
	double a = 4.1;
	double ans = -a + (-5 / 2);
	double result = PostfixExpessions().TryGetResult(expression, &table);
}