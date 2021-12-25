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
double firstAction(string& expression);
double secondAction(string& expression);
void resultIfNoOperations(string& expression);
double thirdAction(string& expression);
double fourthAction(string& expression);
double ifMinus(string& expression, int& i);
void fifthAction(string& expression, stack<double>& result, stack<char>& operations, int& i);
void sixAction(string& expression, stack<double>& result, int& i);
void seventhAction(string& expression, stack<double>& result, stack<char>& operations, int& i);
void eighthAction(stack<double>& result, stack<char>& operations);
void ninthAction(string& expression, stack<double>& result, int& i);
void ifNonOperation(string& expression, stack<double>& result, stack<char>& operations, int& i);
void finalCalculation(stack<double>& result, stack<char>& operations);

#endif //LAB8__CALCULATOR_H_
