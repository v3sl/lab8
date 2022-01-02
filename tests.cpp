#include "gtest/gtest.h"
#include "calculator.h"

TEST(testStack, size) {
	stack<int> testStack;
	ASSERT_EQ(testStack.size, 0);
	testStack << 5;
	ASSERT_EQ(testStack.size, 1);
}
TEST(testStack, capacity) {
	stack<int> testStack;
	ASSERT_EQ(testStack.capacity, 0);
	testStack << 5;
	ASSERT_EQ(testStack.capacity, 10);
	testStack << 5;
	testStack << 5;
	testStack << 5;
	testStack << 5;
	testStack << 5;
	testStack << 5;
	testStack << 5;
	testStack << 5;
	testStack << 5;
	testStack << 5;
	testStack << 5;
	ASSERT_EQ(testStack.capacity, 20);
}
TEST(testingStack, isEmpty) {
	stack<int> testStack;
	ASSERT_EQ(testStack.isEmpty(), true);
	testStack << 5;
	ASSERT_EQ(testStack.isEmpty(), false);
}
TEST(testingStack, top) {
	stack<int> testStack;
	testStack << 5;
	ASSERT_EQ(testStack.top(), 5);
	testStack << 55;
	ASSERT_EQ(testStack.top(), 55);
}
TEST(testingStack, resize) {
	stack<int> testStack;
	ASSERT_EQ(testStack.capacity, 0);
	testStack << 5;
	ASSERT_EQ(testStack.capacity, 10);
	testStack << 5;
	testStack << 5;
	testStack << 5;
	testStack << 5;
	testStack << 5;
	testStack << 5;
	testStack << 5;
	testStack << 5;
	testStack << 5;
	testStack << 5;
	testStack << 5;
	ASSERT_EQ(testStack.capacity, 20);
}
TEST(testingStack, push) {
	stack<int> testStack;
	testStack << 7;
	ASSERT_EQ(testStack.top(), 7);
	testStack << 89;
	ASSERT_EQ(testStack.top(), 89);
}
TEST(testingStack, pop) {
	stack<int> testStack;
	testStack << 7;
	ASSERT_EQ(testStack.pop(), 7);
	testStack << 89;
	ASSERT_EQ(testStack.pop(), 89);
}
TEST(testingStack, overloadedOperators) {
	stack<int> testStack;
	testStack << 33;
	testStack << 45;
	testStack << 44;
	testStack << 77;
	testStack << 98;
	testStack << 43;
	testStack << 45;
	testStack << 79;
	ASSERT_EQ(testStack[2], 44);
	ASSERT_EQ(testStack[5], 43);
	ASSERT_EQ(testStack[4] < testStack[5], false);
	ASSERT_EQ(testStack[7] > testStack[1], true);
	ASSERT_EQ(testStack[1] == testStack[6], true);
	ASSERT_EQ(testStack[1] == testStack[3], false);
	ASSERT_EQ(testStack[1] != testStack[6], false);
	ASSERT_EQ(testStack[5] != testStack[2], true);
	ASSERT_EQ(testStack[2] <= testStack[7], true);
	ASSERT_EQ(testStack[3] >= testStack[7], false);
	stack<int> newTestStack = testStack;
	ASSERT_EQ(newTestStack[4], testStack[4]);
	ASSERT_EQ(newTestStack.size, testStack.size);
	ASSERT_EQ(newTestStack.top(), testStack.top());
	ASSERT_EQ(newTestStack.capacity, testStack.capacity);
	ASSERT_EQ(testStack <<= 1, true);
	ASSERT_EQ(testStack <<= 0, false);
	ASSERT_EQ(testStack >>= 0, 79);
	ASSERT_EQ(testStack >> 0, 79);
	ASSERT_EQ(testStack >> 0, 45);
	ASSERT_EQ(testStack >> 0, 43);
}
TEST(calculator, isOperation) {
	char operations[7] = {'+', '-', '*', '/', '^', '3', '\0'};
	ASSERT_EQ(isOperation(operations[0]), true);
	ASSERT_EQ(isOperation(operations[1]), true);
	ASSERT_EQ(isOperation(operations[2]), true);
	ASSERT_EQ(isOperation(operations[3]), true);
	ASSERT_EQ(isOperation(operations[4]), true);
	ASSERT_EQ(isOperation(operations[5]), false);
	ASSERT_EQ(isOperation(operations[6]), false);
}
TEST(calculator, priority) {
	char operations[7] = {'+', '-', '*', '/', '^', '3', '\0'};
	ASSERT_EQ(priority(operations[0]), 1);
	ASSERT_EQ(priority(operations[1]), 1);
	ASSERT_EQ(priority(operations[2]), 2);
	ASSERT_EQ(priority(operations[3]), 2);
	ASSERT_EQ(priority(operations[4]), 3);
	ASSERT_EQ(priority(operations[5]), -1);
	ASSERT_EQ(priority(operations[6]), -1);
}
TEST(calculator, calculate) {
	double numbers[6] = {2, 5.5, 199, -4, 9.7, 3};
	ASSERT_EQ(calculate(numbers[0], numbers[2], '+'), 201);
	ASSERT_DOUBLE_EQ(calculate(numbers[1], numbers[3], '-'), 9.5);
	ASSERT_DOUBLE_EQ(calculate(numbers[1], numbers[4], '*'), 53.35);
	ASSERT_EQ(calculate(numbers[3], numbers[0], '/'), -2);
	ASSERT_EQ(calculate(numbers[3], numbers[5], '^'), -64);
}
TEST(calculator, binaryExpressions) {
	string expression = "9+9";
	ASSERT_EQ(calculateExpression(expression), 18);
	expression = "1-2-3-4";
	ASSERT_EQ(calculateExpression(expression), -8);
	expression = "2*3";
	ASSERT_EQ(calculateExpression(expression), 6);
	expression = "2/4";
	ASSERT_DOUBLE_EQ(calculateExpression(expression), 0.5);
	expression = "2^2";
	ASSERT_EQ(calculateExpression(expression), 4);
}
TEST(calculator, unaryExpressions) {
	string expression = "1";
	ASSERT_EQ(calculateExpression(expression), 1);
	expression = "(2)";
	ASSERT_EQ(calculateExpression(expression), 2);
	expression = "-1";
	ASSERT_EQ(calculateExpression(expression), -1);
}
TEST(calculator, combineUnaryAndBinaryExpressions) {
	string expression = "7+-5";
	ASSERT_EQ(calculateExpression(expression), 2);
	expression = "-9+9";
	ASSERT_EQ(calculateExpression(expression), 0);
	expression = "-1-2-3-4";
	ASSERT_EQ(calculateExpression(expression), -10);
	expression = "7+-8+-5+-1";
	ASSERT_EQ(calculateExpression(expression), -7);
	expression = "-2*5*-7";
	ASSERT_EQ(calculateExpression(expression), 70);
	expression = "-9*-8*-2*-1";
	ASSERT_EQ(calculateExpression(expression), 144);
	expression = "-78-32+11^2";
	ASSERT_EQ(calculateExpression(expression), 11);
	expression = "12^2+3";
	ASSERT_EQ(calculateExpression(expression), 147);
	expression = "11*3^2-9";
	ASSERT_EQ(calculateExpression(expression), 90);
	expression = "32^2-34/2";
	ASSERT_EQ(calculateExpression(expression), 1007);
	expression = "-9+-5*-3+98-2^6";
	ASSERT_EQ(calculateExpression(expression), 40);
	expression = "7.5^2+4.78/25";
	ASSERT_DOUBLE_EQ(calculateExpression(expression), 56.4412);
	expression = "5/10+23.7-6.3^2";
	ASSERT_DOUBLE_EQ(calculateExpression(expression), -15.49);
	expression = "2--2--2---2";
	ASSERT_EQ(calculateExpression(expression), 4);
}
TEST(calculator, expressionsWithBrackets) {
	string expression = "-(8+8)*3";
	ASSERT_EQ(calculateExpression(expression), -48);
	expression = "(9-89)*2/4+40";
	ASSERT_EQ(calculateExpression(expression), 0);
	expression = "(7^2+51)/100+9^2+2^4+2";
	ASSERT_EQ(calculateExpression(expression), 100);
	expression = "(9-10)*9";
	ASSERT_EQ(calculateExpression(expression), -9);
	expression = "(11-9)*28";
	ASSERT_EQ(calculateExpression(expression), 56);
	expression = "(-9+10)*2175";
	ASSERT_EQ(calculateExpression(expression), 2175);
	expression =  "(-4)^2";
	ASSERT_EQ(calculateExpression(expression), 16);
	expression = "(4.5)^3*-1+7.5/0.3";
	ASSERT_DOUBLE_EQ(calculateExpression(expression), -66.125);
	expression = "-8*65.1-43.67+(1.2)^4";
	ASSERT_DOUBLE_EQ(calculateExpression(expression), -562.3964);
	expression = "5.6+89-(6.1)^2+766.877";
	ASSERT_DOUBLE_EQ(calculateExpression(expression), 824.267);
}