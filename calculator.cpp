#include "calculator.h"

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
	if(Operation == '^') {
		return pow(FirstValue, SecondValue);
	}
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
	for(size_t i = 0; i < Expression.size(); ++i) {
		if(IsOperation(Expression[i])) {
			while(!(Operations <<= 0) && Priority(Expression[i]) <= Priority(Operations >>= 0)) {
				double SecondValue = Result >> 0;
				double FirstValue = Result >> 0;
				Result << Calculate(FirstValue, SecondValue, Operations >> 0);
			}
			Operations << Expression[i];
		}
		else {
			if(Expression[i] == '(') {
				if(Expression[i + 1] == '-') {
					++i;
					ForExpression = "";
					while(Expression[i] != ')')
						ForExpression += Expression[i++];
					Result << stod(ForExpression);
				}
				else
					Operations << Expression[i];
			}
			else if(Expression[i] == ')') {
				while((Operations >>= 0) != '(') {
					double SecondValue = Result >> 0;
					double FirstValue = Result >> 0;
					Result << Calculate(FirstValue, SecondValue, Operations >> 0);
				}
				Operations >> 0;
			}
			else {
				ForExpression = "";
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
		double SecondValue = Result >> 0;
		double FirstValue = Result >> 0;
		Result << Calculate(FirstValue, SecondValue, Operations >> 0);
	}
	return Result >>= 0;
}