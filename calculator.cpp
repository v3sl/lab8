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
double CalculateExpression(string Expression) {
	string ForExpression {};
	for(char ExpressionPart: Expression) {
		if(ExpressionPart != ' ')
			ForExpression += ExpressionPart;
	}
	Expression = ForExpression;
	Stack<char> Operations;
	Stack<double> Result;
	for(int i = 0; i < Expression.size(); ++i) {
		if(IsOperation(Expression[i])) {
			if(i == 0 && Expression[i++] == '-'){
				while(!IsOperation(Expression[i]))
					ForExpression += Expression[i++];
				Result << stod(ForExpression);
			}
			while(!(Operations <<= 0) && Priority(Expression[i]) <= Priority(Operations >>= ForTopOperation)) {
				double SecondValue = Result >> ForPopExpression;
				double FirstValue = Result >> ForPopExpression;
				Result << Calculate(FirstValue, SecondValue, Operations >> ForPopOperation);
			}
			Operations << Expression[i];
			if(Expression[i + 1] == '-') {
				if(Expression[i+2] == '(') {
					++i;
					ForExpression = "";
					while(Expression[i] != ')')
						ForExpression += Expression[++i];
					Result << -CalculateExpression(ForExpression);
				}
				else {
					++i;
					ForExpression = " ";
					while(!IsOperation(Expression[i+1]) && i != Expression.size())
						ForExpression += Expression[i++];
					--i;
					Result << stod(ForExpression);
				}
			}
		} else {
			if(Expression[i] == '(') {
				if(Expression[i + 1] == '-') {
					++i;
					ForExpression = "";
					while(Expression[i] != ')')
						ForExpression += Expression[i++];
					Result << CalculateExpression(ForExpression);
					++i;
				} else
					Operations << Expression[i];
			} else if(Expression[i] == ')') {
				while((Operations >>= ForTopOperation) != '(') {
					double SecondValue = Result >> ForPopExpression;
					double FirstValue = Result >> ForPopExpression;
					Result << Calculate(FirstValue, SecondValue, Operations >> ForPopOperation);
				}
				Operations >> ForPopOperation;
			} else {
				ForExpression = " ";
				while(!IsOperation(Expression[i]) && Expression[i] != ')' && Expression[i] != '('
				      && i != Expression.size()) {
					ForExpression += Expression[i++];
				}
				--i;
				Result << stod(ForExpression);
			}
		}
	}
	while(!(Operations <<= 0)) {
		double SecondValue = Result >> ForPopExpression;
		double FirstValue = Result >> ForPopExpression;
		Result << Calculate(FirstValue, SecondValue, Operations >> ForPopOperation);
	}
	return Result >>= ForTopExpression;
}