#include "ExpressionValidator.h"

ExpressionValidator::ExpressionValidator()
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

ExpressionValidator::ExpressionValidator(Table<std::string, int>& operations)
{
    this->operations = operations;
}

bool ExpressionValidator::IsExpressionCorrect(const std::string& expression)
 {
     bool isLastSignOperation = false;
     int bracketsCounter = 0;
     std::string tempStr;

     if (operations.Find(std::string(1, expression[0])).second)
         if (expression[0] == '(')
         {
             bracketsCounter++;
             isLastSignOperation = true;
         }
         else if (expression[0] != '-')
             return false;
         else
         {
             isLastSignOperation = true;
         }
     else
         tempStr += expression[0];

     for (size_t i = 1; i < expression.size(); i++)
     {
         char c = expression[i];
         if ((c <= 'z' && c >= 'a') || (c <= '9' && c >= '0') || c == '.')
         {
             isLastSignOperation = false;
             if (tempStr == "" && c == '.') return false;
             tempStr += c;
         }
         else
         {
             if (c == '-' && expression[i - 1] == '(')
             {
                 continue;
             }

             if (operations.Find(tempStr).second)
                 isLastSignOperation = true;

             if (c == '(')
             {
                 if (isLastSignOperation == false) return false;
                 bracketsCounter++;
             }
             else if (c == ')')
             {
                 bracketsCounter--;
                 if (isLastSignOperation) return false;
                 if (bracketsCounter < 0) return false;
             }
             else if (operations.Find(std::string(1, c)).second)
             {
                 if (isLastSignOperation) return false;
                 isLastSignOperation = true;
             }
             else
             {
                 return false;
             }
             tempStr = "";
         }
     }

     return (bracketsCounter == 0);
 }
