#ifndef LAB8__STACK_H_
#define LAB8__STACK_H_

#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Stack {
private:
	enum {MAX = INT_MAX};
	int Top;
	T* StackOnArray = new T[MAX];
public:
	int Size;
	Stack();
	bool IsEmpty();
	T top();
	void push(T Value);
	T pop();
	void print(ostream& Out);
	~Stack();
	Stack& operator=(const Stack& InputStack);
	template<typename T1>
	friend T1 operator<<(Stack<T1>& InputStack, T1 Value);
	template<typename T1>
	friend T1 operator>>(Stack<T1>& InputStack, int Value);
	template<typename T1>
	friend T1 operator<<=(Stack<T1>& InputStack, int Value);
	template<typename T1>
	friend T1 operator>>=(Stack& InputStack, int Value);
	friend bool operator==(const Stack<T>& FirstInputStack, Stack<T>& SecondInputStack);
	friend bool operator!=(const Stack<T>& FirstInputStack, const Stack<T>& SecondInputStack);
	friend bool operator<(const Stack<T>& FirstInputStack, const Stack<T>& SecondInputStack);
	friend bool operator<=(const Stack<T>& FirstInputStack, const Stack<T>& SecondInputStack);
	friend bool operator>(const Stack<T>& FirstInputStack, const Stack<T>& SecondInputStack);
	friend bool operator>=(const Stack<T>& FirstInputStack, const Stack<T>& SecondInputStack);
	T& operator[](const int Index);
};
template<typename T>
Stack<T>::Stack(): Top(0), Size(0) {}
template<typename T>
bool Stack<T>::IsEmpty() {return !Size;}
template<typename T>
T Stack<T>::top() {
	if(IsEmpty())
		throw runtime_error("Stack is empty");
	return StackOnArray[Top];
}
template<typename T>
void Stack<T>::push(T Value) {
	StackOnArray[++Top] = Value;
	++Size;
}
template<typename T>
T Stack<T>::pop() {
	if(IsEmpty())
		throw runtime_error("Stack is empty");
	T Value = StackOnArray[Top];
	--Top;
	--Size;
	return Value;
}
template<typename T>
void Stack<T>::print(ostream& Out) {
	for(size_t i = Top; i > 0; --i)
		Out << StackOnArray[i] << '\n';
}
template<typename T>
Stack<T>::~Stack() {delete[] StackOnArray;}
template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& InputStack) {
	this->size = InputStack.size;
	this->Top = InputStack.Top;
	for(size_t i = 1; i <= Size; ++i) {
		StackOnArray[i] = InputStack.st[i];
	}
	return *this;
}
template<typename T>
bool operator==(const Stack<T>& FirstInputStack, Stack<T>& SecondInputStack) {
	return (FirstInputStack.size == SecondInputStack.size);
}
template<typename T>
bool operator!=(const Stack<T>& FirstInputStack, const Stack<T>& SecondInputStack) {
	return !(FirstInputStack == SecondInputStack);
}
template<typename T>
bool operator<(const Stack<T>& FirstInputStack, const Stack<T>& SecondInputStack) {
	return (FirstInputStack.size < SecondInputStack.size);
}
template<typename T>
bool operator<=(const Stack<T>& FirstInputStack, const Stack<T>& SecondInputStack) {
	return (FirstInputStack.size < SecondInputStack.size || FirstInputStack == SecondInputStack);
}
template<typename T>
bool operator>(const Stack<T>& FirstInputStack, const Stack<T>& SecondInputStack) {
	return (FirstInputStack.size > SecondInputStack.size);
}
template<typename T>
bool operator>=(const Stack<T>& FirstInputStack, const Stack<T>& SecondInputStack) {
	return (FirstInputStack.size > SecondInputStack.size || FirstInputStack == SecondInputStack);
}
template<typename T>
T& Stack<T>::operator[](const int Index) {return StackOnArray[Index];}
template<typename T1>
T1 operator<<(Stack<T1>& InputStack, T1 Value) {InputStack.push(Value);}
template<typename T1>
T1 operator>>(Stack<T1>& InputStack, int Value) {InputStack.pop();}
template<typename T1>
T1 operator<<=(Stack<T1>& InputStack, int Value) {InputStack.IsEmpty();}
template<typename T1>
T1 operator>>=(Stack<T1>& InputStack, int Value) {InputStack.top();}

#endif //LAB8__STACK_H_