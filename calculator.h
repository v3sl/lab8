#ifndef LAB8__CALCULATOR_H_
#define LAB8__CALCULATOR_H_

#include "stack.h"
#include <cmath>
#include <stdlib.h>

bool isOperation(char partOfExpression);
int priority(char partOfExpression);
double calculate(double firstValue, double secondValue, char operation);
double calculateExpression(string expression);
int countOpenedBrackets(string expression);
int countClosedBrackets(string expression);
int countOperations(string expression);
void check(string& expression);
string convertExpression(string expression);
double ifNoOperationsAndBrackets(string& expression);
double ifNoOperations(string& expression);
void resultIfNoOperations(string& expression);
double forNegativeExpressionInBrackets(string& expression);
double forNegativeExpression(string& expression);
double ifMinus(string& expression, int& i);
void forDefaultOperations(string& expression, stack<double>& result, stack<char>& operations, int& i);
void forNegativeValuesIfNeeded(string& expression, stack<double>& result, int& i);
void forOpenedBracket(string& expression, stack<double>& result, stack<char>& operations, int& i);
void forClosedBracket(stack<double>& result, stack<char>& operations);
void forDefaultValue(string& expression, stack<double>& result, int& i);
void ifNonOperation(string& expression, stack<double>& result, stack<char>& operations, int& i);
void finalCalculation(stack<double>& result, stack<char>& operations);

#endif //LAB8__CALCULATOR_H_
