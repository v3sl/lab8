#include "calculator.h"

static double ForPopExpression = 0;
static char ForPopOperation = '0';
static double ForTopExpression = 0;
static char ForTopOperation = '0';
static double ForExpressionInBrackets = 0;

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
			if(i == 0 && Expression[i++] == '-') {
				if(Expression[i] == '(') {
					ForExpression = "";
					while(Expression[++i] != ')' && i != Expression.size())
						ForExpression += Expression[i];
					ForExpressionInBrackets = CalculateExpression(ForExpression);
					ForExpression = to_string(-ForExpressionInBrackets);
				} else {
					while(!IsOperation(Expression[i]))
						ForExpression += Expression[i++];
				}
				Result << stod(ForExpression);
				if(i + 1 == Expression.size())
					return Result >>= ForTopExpression;
			}
			while(!(Operations <<= 0) && Priority(Expression[i]) <= Priority(Operations >>= ForTopOperation)) {
				double SecondValue = Result >> ForPopExpression;
				double FirstValue = Result >> ForPopExpression;
				Result << Calculate(FirstValue, SecondValue, Operations >> ForPopOperation);
			}
			Operations << Expression[i];
			if(Expression[i + 1] == '-') {
				if(Expression[i + 2] == '(') {
					i += 2;
					ForExpression = "";
					while(Expression[++i] != ')') {
						ForExpression += Expression[i];
					}
					ForExpressionInBrackets = CalculateExpression(ForExpression);
					Result << -ForExpressionInBrackets;
					++i;
				}
				else{
					while(!IsOperation(Expression[i]))
						ForExpression += Expression[i++];
					Result << stod(ForExpression);
					++i;
				}


			}
		} else {
			if(Expression[i] == '(') {
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
				Result << -stod(ForExpression);
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

