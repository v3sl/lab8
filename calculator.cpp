#include "calculator.h"

static double ForPopExpression = 0;
static char ForPopOperation = '0';
static double ForTopExpression = 0;
static char ForTopOperation = '0';

bool IsOperation(char PartOfExpression) {
	return PartOfExpression == '*' || PartOfExpression == '/' || PartOfExpression == '+' || PartOfExpression == '-'
	       || PartOfExpression == '^';
}
int Priority(char PartOfExpression) {
	if(PartOfExpression == '^') return 3;
	if(PartOfExpression == '*' || PartOfExpression == '/') return 2;
	if(PartOfExpression == '+' || PartOfExpression == '-') return 1;
	return -1;
}
double Calculate(double FirstValue, double SecondValue, char Operation) {
	if(Operation == '+') return FirstValue + SecondValue;
	if(Operation == '-') return FirstValue - SecondValue;
	if(Operation == '*') return FirstValue * SecondValue;
	if(Operation == '/') {
		if(SecondValue == 0)
			throw runtime_error("Cant' divide on 0");
		return FirstValue / SecondValue;
	}
	if(Operation == '^')
		return pow(FirstValue, SecondValue);
	return 0;
}
int CountOpenedBrackets(string Expression) {
	int CountOpenedBrackets = 0;
	for(char PartOfExpression: Expression) {
		if(PartOfExpression == ')')
			++CountOpenedBrackets;
	}
	return CountOpenedBrackets;
}
int CountClosedBrackets(string Expression) {
	int CountClosedBrackets = 0;
	for(char PartOfExpression: Expression) {
		if(PartOfExpression == '(')
			++CountClosedBrackets;
	}
	return CountClosedBrackets;
}
int CountOperations(string Expression) {
	int CountOperations = 0;
	for(int i = 0; i < Expression.size(); ++i) {
		if(IsOperation(Expression[i]) && Expression[i] != '(' && Expression[i] != ')' && i != Expression.size() - 1 &&
		   i != 0 && Expression[i - 1] != '(')
			++CountOperations;
	}
	return CountOperations;
}
void Check(string& Expression) {
	if(CountOpenedBrackets(Expression) != CountClosedBrackets(Expression))
		throw runtime_error("Incorrect expression");
}
void ResultIfNoOperations(string& Expression) {
	if(CountOperations(Expression) == 0 && CountOpenedBrackets(Expression) == 0)
		FirstAction(Expression);
	else if(CountOperations(Expression) == 0)
		SecondAction(Expression);
}
double IfMinus(string& Expression, Stack<double>& Result, int& i) {
	if(Expression[i] == '(')
		return ThirdAction(Expression);
	else
		return FourthAction(Expression);
}
double FirstAction(string& Expression) {return stod(Expression);}
double SecondAction(string& Expression) {
	string ForExpression = "";
	for(int i = 0; i < Expression.size(); ++i) {
		if(Expression[i] != '(' && Expression[i] != ')')
			ForExpression += Expression[i];
	}
	return stod(ForExpression);
}
double ThirdAction(string& Expression) {
	string ForExpressionInBrackets = "0";
	ForExpressionInBrackets += Expression;
	return CalculateExpression(ForExpressionInBrackets);
}
double FourthAction(string& Expression) {
	string ForNegativeExpression = "0";
	ForNegativeExpression += Expression;
	return CalculateExpression(ForNegativeExpression);
}
void FifthAction(string& Expression, Stack<double>& Result, Stack<char>& Operations, int& i) {
	while(!(Operations <<= 0) && Priority(Expression[i]) <= Priority(Operations >>= ForTopOperation)) {
		double SecondValue = Result >> ForPopExpression;
		double FirstValue = Result >> ForPopExpression;
		Result << Calculate(FirstValue, SecondValue, Operations >> ForPopOperation);
	}
	Operations << Expression[i];
}
void SixAction(string& Expression, Stack<double>& Result, int& i) {
	string ForExpression;
	if(Expression[i + 1] == '-') {
		if(Expression[i + 2] == '(') {
			++i;
			ForExpression = "";
			while(Expression[i] != ')')
				ForExpression += Expression[++i];
			Result << -CalculateExpression(ForExpression);
		} else {
			ForExpression = " ";
			++i;
			while((!IsOperation(Expression[i]) || Expression[i] == '-') && i != Expression.size())
				ForExpression += Expression[i++];
			--i;
			Result << stod(ForExpression);
		}
	}
}
void SeventhAction(string& Expression, Stack<double>& Result, Stack<char>& Operations, int& i) {
	string ForExpression;
	if(Expression[i + 1] == '-') {
		++i;
		ForExpression = "";
		while(Expression[i] != ')')
			ForExpression += Expression[i++];
		Result << CalculateExpression(ForExpression);
	} else
		Operations << Expression[i];
}
void EighthAction(Stack<double>& Result, Stack<char>& Operations) {
	while((Operations >>= ForTopOperation) != '(') {
		double SecondValue = Result >> ForPopExpression;
		double FirstValue = Result >> ForPopExpression;
		Result << Calculate(FirstValue, SecondValue, Operations >> ForPopOperation);
	}
	Operations >> ForPopOperation;
}
void NinthAction(string& Expression, Stack<double>& Result, int& i) {
	string ForExpression = "";
	while(!IsOperation(Expression[i]) && Expression[i] != ')' && Expression[i] != '('
	      && i != Expression.size()) {
		ForExpression += Expression[i++];
	}
	--i;
	Result << stod(ForExpression);
}
void IfNonOperation(string& Expression, Stack<double>& Result, Stack<char>& Operations, int& i) {
	if(Expression[i] == '(')
		SeventhAction(Expression, Result, Operations, i);
	else if(Expression[i] == ')')
		EighthAction(Result, Operations);
	else
		NinthAction(Expression, Result, i);
}
void FinalCalculation(Stack<double>& Result, Stack<char>& Operations) {
	while(!(Operations <<= 0)) {
		double SecondValue = Result >> ForPopExpression;
		double FirstValue = Result >> ForPopExpression;
		Result << Calculate(FirstValue, SecondValue, Operations >> ForPopOperation);
	}
}
double CalculateExpression(string Expression) {
	ResultIfNoOperations(Expression);
	Stack<char> Operations;
	Stack<double> Result;
	for(int i = 0; i < Expression.size(); ++i) {
		if(IsOperation(Expression[i])) {
			if(i == 0 && Expression[i++] == '-')
				return IfMinus(Expression, Result, i);
			FifthAction(Expression, Result, Operations, i);
			SixAction(Expression, Result, i);
		} else
			IfNonOperation(Expression, Result, Operations, i);
	}
	FinalCalculation(Result, Operations);
	return Result >>= ForTopExpression;
}