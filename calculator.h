#ifndef LAB8__CALCULATOR_H_
#define LAB8__CALCULATOR_H_

#include "Stack.h"
#include <cmath>
#include <stdlib.h>

bool IsOperation(char PartOfExpression);
int Priority(char PartOfExpression);
double Calculate(double FirstValue, double SecondValue, char Operation);
double CalculateExpression(string Expression);
int CountOpenedBrackets(string Expression);
int CountClosedBrackets(string Expression);
string DeleteSpaces(string Expression);
void Check(string& Expression);
void ResultIfNoOperations(string& Expression);
double FirstAction(string &Expression);
double SecondAction(string &Expression);
double ThirdAction(string &ForExpression);
double FourthAction(string& Expression);
double IfMinus(string& Expression, Stack<double>& Result, int& i);
void FifthAction(string& Expression, Stack<double>& Result, Stack<char>& Operations, int& i);
void SixAction(string& Expression, Stack<double>& Result, int& i);
void SeventhAction(string& Expression, Stack<double>& Result, Stack<char>& Operations, int& i);
void EighthAction(Stack<char>& Operations, Stack<double>& Result);
void NinthAction(string& Expression, Stack<double>& Result, int& i);
void FinalCalculation(Stack<char>& Operations, Stack<double>& Result);
void IfNonOperation(string& Expression, Stack<char>& Operations, Stack<double>& Result, int& i);

#endif //LAB8__CALCULATOR_H_
