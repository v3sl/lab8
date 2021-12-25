#include "gtest/gtest.h"
#include "calculator.h"

TEST(testingStack, test1) {
	stack<int> testStack;
	ASSERT_EQ(testStack.isEmpty(), true);
}
TEST(testingStack, test2) {
	stack<int> testStack;
	testStack << 5;
	ASSERT_EQ(testStack.isEmpty(), false);
	ASSERT_EQ(testStack.size, 1);
	ASSERT_EQ(testStack.capacity, 10);
	ASSERT_EQ(testStack.pop(), 5);
}
TEST(testingStack, test3) {
	stack<int> testStack;
	testStack << 26;
	testStack << 18;
	ASSERT_EQ(testStack.size, 2);
}
TEST(testingStack, test4) {
	stack<int> testStack;
	testStack << 7;
	testStack << 89;
	ASSERT_EQ(testStack.top(), 89);
}
TEST(testingStack, test5) {
	stack<int> testStack;
	testStack << 27;
	testStack << 75;
	ASSERT_EQ(testStack >> 0, 75);
	ASSERT_EQ(testStack.size, 1);
}
TEST(testingStack, test6) {
	stack<int> testStack;
	testStack << 45;
	testStack << 21;
	testStack << 32;
	testStack >> 0;
	ASSERT_EQ(testStack.top(), 21);
	ASSERT_EQ(testStack.size, 2);
}
TEST(testingStack, test7) {
	stack<int> testStack;
	testStack << 45;
	testStack << 21;
	testStack << 32;
	testStack << 67;
	testStack >> 0;
	ASSERT_EQ(testStack >> 0, 32);
	ASSERT_EQ(testStack.size, 2);
}
TEST(testingStack, test8) {
	stack<int> testStack;
	testStack << 33;
	testStack << 45;
	ASSERT_EQ(testStack[1], 45);
}
TEST(testingStack, test9) {
	stack<int> testStack;
	testStack << 33;
	testStack << 45;
	testStack << 44;
	testStack << 77;
	testStack << 98;
	testStack << 43;
	testStack << 43;
	testStack << 43;
	testStack << 43;
	testStack << 43;
	testStack << 43;
	testStack << 43;
	testStack << 43;
	ASSERT_EQ(testStack[5], 43);
	ASSERT_EQ(testStack.capacity, 20);
}
TEST(testingStack, test10) {
	stack<int> testStack;
	testStack << 33;
	testStack << 45;
	testStack << 44;
	testStack << 77;
	testStack << 98;
	testStack << 43;
	testStack << 45;
	testStack << 79;
	ASSERT_EQ(testStack[4] < testStack[5], false);
	ASSERT_EQ(testStack[7] > testStack[1], true);
	ASSERT_EQ(testStack[1] == testStack[6], true);
	ASSERT_EQ(testStack[1] == testStack[3], false);
	ASSERT_EQ(testStack[1] != testStack[6], false);
	ASSERT_EQ(testStack[5] != testStack[2], true);
	ASSERT_EQ(testStack[2] <= testStack[7], true);
	ASSERT_EQ(testStack[3] >= testStack[7], false);
}
TEST(testingStack, test11) {
	stack<int> testStack;
	testStack << 33;
	testStack << 45;
	testStack << 44;
	testStack << 77;
	testStack << 98;
	testStack << 43;
	stack<int> TestStack1 = testStack;
	ASSERT_EQ(TestStack1[4], 98);
	ASSERT_EQ(TestStack1.size, 6);
	ASSERT_EQ(TestStack1.top(), 43);
}
TEST(testingIsOperation, test12) {
	char operations[5] = {'+', '-', '*', '/', '^'};
	ASSERT_EQ(isOperation(operations[0]), true);
	ASSERT_EQ(isOperation(operations[1]), true);
	ASSERT_EQ(isOperation(operations[2]), true);
	ASSERT_EQ(isOperation(operations[3]), true);
	ASSERT_EQ(isOperation(operations[4]), true);
}
TEST(testingPriority, test13) {
	char operations[5] = {'+', '-', '*', '/', '^'};
	ASSERT_EQ(priority(operations[0]), 1);
	ASSERT_EQ(priority(operations[1]), 1);
	ASSERT_EQ(priority(operations[2]), 2);
	ASSERT_EQ(priority(operations[3]), 2);
	ASSERT_EQ(priority(operations[4]), 3);
}
TEST(testingCalculations, test14) {
	double numbers[6] = {2, 5.5, 199, -4, 9.7, 3};
	ASSERT_EQ(calculate(numbers[0], numbers[2], '+'), 201);
	ASSERT_DOUBLE_EQ(calculate(numbers[1], numbers[3], '-'), 9.5);
	ASSERT_DOUBLE_EQ(calculate(numbers[1], numbers[4], '*'), 53.35);
	ASSERT_EQ(calculate(numbers[3], numbers[0], '/'), -2);
	ASSERT_EQ(calculate(numbers[3], numbers[5], '^'), -64);
}
TEST(testingCalculatingTheExpression, test15) {
	string s = "-9+9";
	ASSERT_EQ(calculateExpression(s), 0);
}
TEST(testingCalculatingTheExpression, test16) {
	string s = "-1-2-3-4";
	ASSERT_EQ(calculateExpression(s), -10);
}
TEST(testingCalculatingTheExpression, test17) {
	string s = "7+-5";
	ASSERT_EQ(calculateExpression(s), 2);
}
TEST(testingCalculatingTheExpression, test18) {
	string s = "7+-8+-5+-1";
	ASSERT_EQ(calculateExpression(s), -7);
}
TEST(testingCalculatingTheExpression, test19) {
	string s = "-2*5*-7";
	ASSERT_EQ(calculateExpression(s), 70);
}
TEST(testingCalculatingTheExpression, test20) {
	string s = "-(8+8)*3";
	ASSERT_EQ(calculateExpression(s), -48);
}
TEST(testingCalculatingTheExpression, test21) {
	string s = "(9-89)*2/4+40";
	ASSERT_EQ(calculateExpression(s), 0);
}
TEST(testingCalculatingTheExpression, test22) {
	string s = "-9*-8*-2*-1";
	ASSERT_EQ(calculateExpression(s), 144);
}
TEST(testingCalculatingTheExpression, test23) {
	string s = "(7^2+51)/100+9^2+2^4+2";
	ASSERT_EQ(calculateExpression(s), 100);
}
TEST(testingCalculatingTheExpression, test24) {
	string s = "-78-32+11^2";
	ASSERT_EQ(calculateExpression(s), 11);
}
TEST(testingCalculatingTheExpression, test25) {
	string s = "(9-10)*9";
	ASSERT_EQ(calculateExpression(s), -9);
}
TEST(testingCalculatingTheExpression, test26) {
	string s = "(11-9)*28";
	ASSERT_EQ(calculateExpression(s), 56);
}
TEST(testingCalculatingTheExpression, test27) {
	string s = "12^2+3";
	ASSERT_EQ(calculateExpression(s), 147);
}
TEST(testingCalculatingTheExpression, test28) {
	string s = "11*3^2-9";
	ASSERT_EQ(calculateExpression(s), 90);
}
TEST(testingCalculatingTheExpression, test29) {
	string s = "32^2-34/2";
	ASSERT_EQ(calculateExpression(s), 1007);
}
TEST(testingCalculatingTheExpression, test30) {
	string s = "(-9+10)*2175";
	ASSERT_EQ(calculateExpression(s), 2175);
}
TEST(testingCalculatingTheExpression, test31) {
	string s = "-9+-5*-3+98-2^6";
	ASSERT_EQ(calculateExpression(s), 40);
}
TEST(testingCalculatingTheExpression, test32) {
	string s = "(-4)^2";
	ASSERT_EQ(calculateExpression(s), 16);
}
TEST(testingCalculatingTheExpression, test33) {
	string s = "7.5^2+4.78/25";
	ASSERT_DOUBLE_EQ(calculateExpression(s), 56.4412);
}
TEST(testingCalculatingTheExpression, test34) {
	string s = "5/10+23.7-6.3^2";
	ASSERT_DOUBLE_EQ(calculateExpression(s), -15.49);
}
TEST(testingCalculatingTheExpression, test35) {
	string s = "(4.5)^3*-1+7.5/0.3";
	ASSERT_DOUBLE_EQ(calculateExpression(s), -66.125);
}
TEST(testingCalculatingTheExpression, test36) {
	string s = "-8*65.1-43.67+(1.2)^4";
	ASSERT_DOUBLE_EQ(calculateExpression(s), -562.3964);
}
TEST(testingCalculatingTheExpression, test37) {
	string s = "5.6+89-(6.1)^2+766.877";
	ASSERT_DOUBLE_EQ(calculateExpression(s), 824.267);
}
