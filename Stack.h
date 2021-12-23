#ifndef LAB8__STACK_H_
#define LAB8__STACK_H_

#include <iostream>
#include <string>

using namespace std;

const int GrowsFactor = 10;

template<typename T>
class Stack {
public:
	int Capacity;
	T* StackOnArray = new T[Capacity];
	int Size;
	Stack();
	bool IsEmpty();
	T top();
	void ResizeIfNeeded();
	void push(T Value);
	T pop();
	void print(ostream& Out);
	~Stack();
	Stack& operator&=(const Stack& InputStack);
	T& operator[](int Index);
};
template<typename T>
Stack<T>::Stack(): Size(0), Capacity(0) {}
template<typename T>
bool Stack<T>::IsEmpty() {return !Size;}
template<typename T>
T Stack<T>::top() {
	if(IsEmpty())
		throw runtime_error("Stack is empty");
	return StackOnArray[Size-1];
}
template<typename T>
void Stack<T>::ResizeIfNeeded() {
	if(Size + 1 > Capacity) {
		T* NewStackOnArray = new T[Capacity + GrowsFactor];
		for(size_t i = 0; i <= Size; ++i)
			NewStackOnArray[i] = StackOnArray[i];
		Capacity += GrowsFactor;
		delete[] StackOnArray;
		StackOnArray = NewStackOnArray;
	}
}
template<typename T>
void Stack<T>::push(T Value) {
	ResizeIfNeeded();
	StackOnArray[Size++] = Value;
}
template<typename T>
T Stack<T>::pop() {
	if(IsEmpty())
		throw runtime_error("Stack is empty");
	T Value = StackOnArray[--Size];
	return Value;
}
template<typename T>
void Stack<T>::print(ostream& Out) {
	for(int i = Size-1; i >= 0; --i)
		Out << StackOnArray[i] << '\n';
}
template<typename T>
Stack<T>::~Stack() {delete[] StackOnArray;}
template<typename T>
Stack<T>& Stack<T>::operator&=(const Stack& InputStack) {
	this->Size = InputStack.size;
	delete[] this->stackBase;
	this->stackBase = new T[InputStack.size];
	int temp;
	for(int i = 0; i < InputStack.size; ++i) {
		temp = InputStack.stackBase[i];
		StackOnArray[i] = temp;
	}
	InputStack.stackBase = nullptr;
	return *this;
}
template<typename T1>
bool operator==(const Stack<T1>& FirstInputStack, Stack<T1>& SecondInputStack) {
	return (FirstInputStack.size == SecondInputStack.size);
}
template<typename T1>
bool operator!=(const Stack<T1>& FirstInputStack, const Stack<T1>& SecondInputStack) {
	return !(FirstInputStack == SecondInputStack);
}
template<typename T1>
bool operator<(const Stack<T1>& FirstInputStack, const Stack<T1>& SecondInputStack) {
	return (FirstInputStack.size < SecondInputStack.size);
}
template<typename T1>
bool operator<=(const Stack<T1>& FirstInputStack, const Stack<T1>& SecondInputStack) {
	return (FirstInputStack.size < SecondInputStack.size || FirstInputStack == SecondInputStack);
}
template<typename T1>
bool operator>(const Stack<T1>& FirstInputStack, const Stack<T1>& SecondInputStack) {
	return (FirstInputStack.size > SecondInputStack.size);
}
template<typename T1>
bool operator>=(const Stack<T1>& FirstInputStack, const Stack<T1>& SecondInputStack) {
	return (FirstInputStack.size > SecondInputStack.size || FirstInputStack == SecondInputStack);
}
template<typename T>
T& Stack<T>::operator[](int Index) {return StackOnArray[Index];}
template<typename T1>
void operator<<(Stack<T1>& InputStack, T1 Value) {InputStack.push(Value);}
template<typename T1>
T1 operator>>(Stack<T1>& InputStack, T1 Value) {
	Value = InputStack.pop();
	return Value;
}
template<typename T1>
bool operator<<=(Stack<T1>& InputStack, bool Value) {return !(InputStack.IsEmpty() == Value);}
template<typename T1>
T1 operator>>=(Stack<T1>& InputStack, double Value) {
	Value = InputStack.top();
	return Value;
}

#endif //LAB8__STACK_H_