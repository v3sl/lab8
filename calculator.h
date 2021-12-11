#ifndef LAB8__CALCULATOR_H_
#define LAB8__CALCULATOR_H_

#include "Stack.h"

bool IsOperation(char PartOfExpression);
int Priority(char PartOfExpression);
double Calculate(double FirstValue, double SecondValue, char Operation);
double CalculateExpression(string Expression);

#endif //LAB8__CALCULATOR_H_
