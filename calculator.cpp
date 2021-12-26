#include "calculator.h"

static double forPopExpression = 0;
static char forPopOperation = '0';
static double forTopExpression = 0;
static char forTopOperation = '0';

bool isOperation(char partOfExpression) {
	return partOfExpression == '*' || partOfExpression == '/' || partOfExpression == '+' || partOfExpression == '-'
	       || partOfExpression == '^';
}
int priority(char partOfExpression) {
	if(partOfExpression == '^') return 3;
	if(partOfExpression == '*' || partOfExpression == '/') return 2;
	if(partOfExpression == '+' || partOfExpression == '-') return 1;
	return -1;
}
double calculate(double firstValue, double secondValue, char operation) {
	if(operation == '+') return firstValue + secondValue;
	if(operation == '-') return firstValue - secondValue;
	if(operation == '*') return firstValue * secondValue;
	if(operation == '/') {
		if(secondValue == 0)
			throw runtime_error("Cant' divide on 0");
		return firstValue / secondValue;
	}
	if(operation == '^')
		return pow(firstValue, secondValue);
	return 0;
}
int countOpenedBrackets(string expression) {
	int counter = 0;
	for(char partOfExpression: expression) {
		if(partOfExpression == '(')
			++counter;
	}
	return counter;
}
int countClosedBrackets(string expression) {
	int counter = 0;
	for(char partOfExpression: expression) {
		if(partOfExpression == ')')
			++counter;
	}
	return counter;
}
int countOperations(string expression) {
	int counter = 0;
	for(int i = 0; i < expression.size(); ++i) {
		if(isOperation(expression[i]) && expression[i] != '(' && expression[i] != ')' && i != expression.size() - 1 &&
		   i != 0 && expression[i - 1] != '(')
			++counter;
	}
	return counter;
}
void check(string& expression) {
	if(countOpenedBrackets(expression) != countClosedBrackets(expression))
		throw runtime_error("Incorrect expression");
}
double ifNoOperationsAndBrackets(string& expression) {return stod(expression);}
double ifNoOperations(string& expression) {
	string forNewExpression = "";
	for(int i = 0; i < expression.size(); ++i) {
		if(expression[i] != '(' && expression[i] != ')')
			forNewExpression += expression[i];
	}
	return stod(forNewExpression);
}
void resultIfNoOperations(string& expression) {
	if(countOperations(expression) == 0 && countOpenedBrackets(expression) == 0)
		ifNoOperationsAndBrackets(expression);
	else if(countOperations(expression) == 0)
		ifNoOperations(expression);
}
double forNegativeExpressionInBrackets(string& expression) {
	string forExpressionInBrackets = "0";
	forExpressionInBrackets += expression;
	return calculateExpression(forExpressionInBrackets);
}
double forNegativeExpression(string& expression) {
	string forNegativeExpression = "0";
	forNegativeExpression += expression;
	return calculateExpression(forNegativeExpression);
}
double ifMinus(string& expression, int& i) {
	if(expression[i] == '(')
		return forNegativeExpressionInBrackets(expression);
	else
		return forNegativeExpression(expression);
}
void forDefaultOperations(string& expression, stack<double>& result, stack<char>& operations, int& i) {
	while(!(operations <<= 0) && priority(expression[i]) <= priority(operations >>= forTopOperation)) {
		double secondValue = result >> forPopExpression;
		double firstValue = result >> forPopExpression;
		result << calculate(firstValue, secondValue, operations >> forPopOperation);
	}
	operations << expression[i];
}
void forNegativeValuesIfNeeded(string& expression, stack<double>& result, int& i) {
	string forNewExpression;
	if(expression[i + 1] == '-') {
		if(expression[i + 2] == '(') {
			++i;
			forNewExpression = "";
			while(expression[i] != ')')
				forNewExpression += expression[++i];
			result << -calculateExpression(forNewExpression);
		} else {
			forNewExpression = " ";
			++i;
			while((!isOperation(expression[i]) || expression[i] == '-') && i != expression.size())
				forNewExpression += expression[i++];
			--i;
			result << stod(forNewExpression);
		}
	}
}
void forOpenedBracket(string& expression, stack<double>& result, stack<char>& operations, int& i) {
	string forNewExpression;
	if(expression[i + 1] == '-') {
		++i;
		forNewExpression = "";
		while(expression[i] != ')')
			forNewExpression += expression[i++];
		result << calculateExpression(forNewExpression);
	} else
		operations << expression[i];
}
void forClosedBracket(stack<double>& result, stack<char>& operations) {
	while((operations >>= forTopOperation) != '(') {
		double SecondValue = result >> forPopExpression;
		double FirstValue = result >> forPopExpression;
		result << calculate(FirstValue, SecondValue, operations >> forPopOperation);
	}
	operations >> forPopOperation;
}
void forDefaultValue(string& expression, stack<double>& result, int& i) {
	string forNewExpression = "";
	while(!isOperation(expression[i]) && expression[i] != ')' && expression[i] != '('
	      && i != expression.size())
		forNewExpression += expression[i++];
	--i;
	result << stod(forNewExpression);
}
void ifNonOperation(string& expression, stack<double>& result, stack<char>& operations, int& i) {
	if(expression[i] == '(')
		forOpenedBracket(expression, result, operations, i);
	else if(expression[i] == ')')
		forClosedBracket(result, operations);
	else
		forDefaultValue(expression, result, i);
}
void finalCalculation(stack<double>& result, stack<char>& operations) {
	while(!(operations <<= 0)) {
		double SecondValue = result >> forPopExpression;
		double FirstValue = result >> forPopExpression;
		result << calculate(FirstValue, SecondValue, operations >> forPopOperation);
	}
}
double calculateExpression(string expression) {
	resultIfNoOperations(expression);
	stack<char> operations;
	stack<double> result;
	for(int i = 0; i < expression.size(); ++i) {
		if(isOperation(expression[i])) {
			if(i == 0 && expression[i++] == '-')
				return ifMinus(expression, i);
			forDefaultOperations(expression, result, operations, i);
			forNegativeValuesIfNeeded(expression, result, i);
		} else
			ifNonOperation(expression, result, operations, i);
	}
	finalCalculation(result, operations);
	return result >>= forTopExpression;
}