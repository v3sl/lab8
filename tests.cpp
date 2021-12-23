#include "gtest/gtest.h"
#include "calculator.h"


TEST(testing_stack, test1) {
	Stack<int> stack;
	ASSERT_EQ(stack.IsEmpty(), true);
}
TEST(testing_stack, test2) {
	Stack<int> stack;
	stack << 5;
	ASSERT_EQ(stack.IsEmpty(), false);
	ASSERT_EQ(stack.Size, 1);
	ASSERT_EQ(stack.Capacity, 10);
	ASSERT_EQ(stack.pop(), 5);
}
TEST(testing_stack, test3) {
	Stack<int> stack;
	stack << 26;
	stack << 18;
	ASSERT_EQ(stack.Size, 2);
}
TEST(testing_stack, test4) {
	Stack<int> stack;
	stack << 7;
	stack << 89;
	ASSERT_EQ(stack.top(), 89);
}
TEST(testing_stack, test5) {
	Stack<int> stack;
	stack << 27;
	stack << 75;
	ASSERT_EQ(stack >> 0, 75);
	ASSERT_EQ(stack.Size, 1);
}
TEST(testing_stack, test6) {
	Stack<int> stack;
	stack << 45;
	stack << 21;
	stack << 32;
	stack >> 0;
	ASSERT_EQ(stack.top(), 21);
	ASSERT_EQ(stack.Size, 2);
}
TEST(testing_stack, test7) {
	Stack<int> stack;
	stack << 45;
	stack << 21;
	stack << 32;
	stack << 67;
	stack >> 0;
	ASSERT_EQ(stack >> 0, 32);
	ASSERT_EQ(stack.Size, 2);
}
TEST(testing_stack, test8) {
	Stack<int> stack;
	stack << 33;
	stack << 45;
	ASSERT_EQ(stack[1], 45);
}
TEST(testing_stack, test9) {
	Stack<int> stack;
	stack << 33;
	stack << 45;
	stack << 44;
	stack << 77;
	stack << 98;
	stack << 43;
	stack << 43;
	stack << 43;
	stack << 43;
	stack << 43;
	stack << 43;
	stack << 43;
	stack << 43;
	ASSERT_EQ(stack[5], 43);
	ASSERT_EQ(stack.Capacity, 20);
}
TEST(testing_stack, test10) {
	Stack<int> stack;
	stack << 33;
	stack << 45;
	stack << 44;
	stack << 77;
	stack << 98;
	stack << 43;
	stack << 45;
	stack << 79;
	ASSERT_EQ(stack[4] < stack[5], false);
	ASSERT_EQ(stack[7] > stack[1], true);
	ASSERT_EQ(stack[1] == stack[6], true);
	ASSERT_EQ(stack[1] == stack[3], false);
	ASSERT_EQ(stack[1] != stack[6], false);
	ASSERT_EQ(stack[5] != stack[2], true);
	ASSERT_EQ(stack[2] <= stack[7], true);
	ASSERT_EQ(stack[3] >= stack[7], false);
}
TEST(testing_stack, test11) {
	Stack<int> stack;
	stack << 33;
	stack << 45;
	stack << 44;
	stack << 77;
	stack << 98;
	stack << 43;
	Stack<int> stack1 = stack;
	ASSERT_EQ(stack1[4], 98);
	ASSERT_EQ(stack1.Size, 6);
	ASSERT_EQ(stack1.top(), 43);
}
TEST(testing_isOperation, test12) {
	char operations[5] = {'+', '-', '*', '/', '^'};
	ASSERT_EQ(IsOperation(operations[0]), true);
	ASSERT_EQ(IsOperation(operations[1]), true);
	ASSERT_EQ(IsOperation(operations[2]), true);
	ASSERT_EQ(IsOperation(operations[3]), true);
	ASSERT_EQ(IsOperation(operations[4]), true);
}
TEST(testing_Priority, test13) {
	char operations[5] = {'+', '-', '*', '/', '^'};
	ASSERT_EQ(Priority(operations[0]), 1);
	ASSERT_EQ(Priority(operations[1]), 1);
	ASSERT_EQ(Priority(operations[2]), 2);
	ASSERT_EQ(Priority(operations[3]), 2);
	ASSERT_EQ(Priority(operations[4]), 3);
}
TEST(testing_Calculations, test14) {
	double numbers[6] = {2, 5.5, 199, -4, 9.7, 3};
	ASSERT_EQ(Calculate(numbers[0], numbers[2], '+'), 201);
	ASSERT_DOUBLE_EQ(Calculate(numbers[1], numbers[3], '-'), 9.5);
	ASSERT_DOUBLE_EQ(Calculate(numbers[1], numbers[4], '*'), 53.35);
	ASSERT_EQ(Calculate(numbers[3], numbers[0], '/'), -2);
	ASSERT_EQ(Calculate(numbers[3], numbers[5], '^'), -64);
}
TEST(testing_CalculatingTheExpression, test15) {
	string s = "-9+9";
	ASSERT_EQ(CalculateExpression(s), 0);
}
TEST(testing_CalculatingTheExpression, test16) {
	string s = "-1-2-3-4";
	ASSERT_EQ(CalculateExpression(s), -10);
}
TEST(testing_CalculatingTheExpression, test17) {
	string s = "7+-5";
	ASSERT_EQ(CalculateExpression(s), 2);
}
TEST(testing_CalculatingTheExpression, test18) {
	string s = "7+-8+-5+-1";
	ASSERT_EQ(CalculateExpression(s), -7);
}
TEST(testing_CalculatingTheExpression, test19) {
	string s = "-2*5*-7";
	ASSERT_EQ(CalculateExpression(s), 70);
}
TEST(testing_CalculatingTheExpression, test20) {
	string s = "-(8+8)*3";
	ASSERT_EQ(CalculateExpression(s), -48);
}
TEST(testing_CalculatingTheExpression, test21) {
	string s = "(9-89)*2/4+40";
	ASSERT_EQ(CalculateExpression(s), 0);
}
TEST(testing_CalculatingTheExpression, test22) {
	string s = "-9*-8*-2*-1";
	ASSERT_EQ(CalculateExpression(s), 144);
}
TEST(testing_CalculatingTheExpression, test23) {
	string s = "(7^2+51)/100+9^2+2^4+2";
	ASSERT_EQ(CalculateExpression(s), 100);
}
TEST(testing_CalculatingTheExpression, test24) {
	string s = "-78-32+11^2";
	ASSERT_EQ(CalculateExpression(s), 11);
}
TEST(testing_CalculatingTheExpression, test25) {
	string s = "(9-10)*9";
	ASSERT_EQ(CalculateExpression(s), -9);
}
TEST(testing_CalculatingTheExpression, test26) {
	string s = "(11-9)*28";
	ASSERT_EQ(CalculateExpression(s), 56);
}
TEST(testing_CalculatingTheExpression, test27) {
	string s = "12^2+3";
	ASSERT_EQ(CalculateExpression(s), 147);
}
TEST(testing_CalculatingTheExpression, test28) {
	string s = "11*3^2-9";
	ASSERT_EQ(CalculateExpression(s), 90);
}
TEST(testing_CalculatingTheExpression, test29) {
	string s = "32^2-34/2";
	ASSERT_EQ(CalculateExpression(s), 1007);
}
TEST(testing_CalculatingTheExpression, test30) {
	string s = "(-9+10)*2175";
	ASSERT_EQ(CalculateExpression(s), 2175);
}
TEST(testing_CalculatingTheExpression, test31) {
	string s = "-9+-5*-3+98-2^6";
	ASSERT_EQ(CalculateExpression(s), 40);
}
TEST(testing_CalculatingTheExpression, test32) {
	string s = "-4^2";
	ASSERT_EQ(CalculateExpression(s), 16);
}
TEST(testing_CalculatingTheExpression, test33) {
	string s = "7.5^2+4.78/25";
	ASSERT_DOUBLE_EQ(CalculateExpression(s), 56.4412);
}
TEST(testing_CalculatingTheExpression, test34) {
	string s = "5/10+23.7-6.3^2";
	ASSERT_DOUBLE_EQ(CalculateExpression(s), -15.49);
}
TEST(testing_CalculatingTheExpression, test35) {
	string s = "(4.5)^3*-1+7.5/0.3";
	ASSERT_DOUBLE_EQ(CalculateExpression(s), -66.125);
}
TEST(testing_CalculatingTheExpression, test36) {
	string s = "-8*65.1-43.67+(1.2)^4";
	ASSERT_DOUBLE_EQ(CalculateExpression(s), -562.3964);
}
TEST(testing_CalculatingTheExpression, test37) {
	string s = "5.6+89-(6.1)^2+766.877";
	ASSERT_DOUBLE_EQ(CalculateExpression(s), 824.267);
}
