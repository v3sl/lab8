#ifndef LAB8__STACK_H_
#define LAB8__STACK_H_

#include <iostream>

using namespace std;

const int growsFactor = 10;

template<typename T>
class stack {
public:
	int size;
	int capacity;
	T* stackOnArray = new T[capacity];
	stack();
	stack(const stack<T>& inputStack);
	bool isEmpty();
	T top();
	void resizeIfNeeded();
	void push(T value);
	T pop();
	void print(ostream& out);
	~stack();
	stack& operator&=(const stack& inputStack);
	T& operator[](int index);
};
template<typename T>
stack<T>::stack(): size(0), capacity(0) {}
template<typename T>
stack<T>::stack(const stack<T>& inputStack) {
	this->size = inputStack.size;
	this->capacity = inputStack.capacity;
	delete[] this->stackOnArray;
	this->stackOnArray = new T[inputStack.size];
	for(int i = 0; i < inputStack.size; ++i)
		stackOnArray[i] = inputStack.stackOnArray[i];
}
template<typename T>
bool stack<T>::isEmpty() {return !size;}
template<typename T>
T stack<T>::top() {
	if(isEmpty())
		throw runtime_error("Stack is empty");
	return stackOnArray[size - 1];
}
template<typename T>
void stack<T>::resizeIfNeeded() {
	if(size + 1 > capacity) {
		T* newStackOnArray = new T[capacity + growsFactor];
		for(size_t i = 0; i <= size; ++i)
			newStackOnArray[i] = stackOnArray[i];
		capacity += growsFactor;
		delete[] stackOnArray;
		stackOnArray = newStackOnArray;
	}
}
template<typename T>
void stack<T>::push(T value) {
	resizeIfNeeded();
	stackOnArray[size++] = value;
}
template<typename T>
T stack<T>::pop() {
	if(isEmpty())
		throw runtime_error("stack is empty");
	T value = stackOnArray[--size];
	return value;
}
template<typename T>
void stack<T>::print(ostream& out) {
	for(int i = size - 1; i >= 0; --i)
		out << stackOnArray[i] << '\n';
}
template<typename T>
stack<T>::~stack() {
	delete[] stackOnArray;
}
template<typename T>
stack<T>& stack<T>::operator&=(const stack& inputStack) {
	stack<T> st(inputStack);
	this->size = inputStack.size;
	this->capacity = inputStack.capacity;
	delete[] this->stackOnArray;
	this->stackOnArray = new T[inputStack.size];
	for(int i = 0; i < inputStack.size; ++i)
		stackOnArray[i] = inputStack.stackOnArray[i];
	return *this;
}
template<typename T1>
bool operator==(const stack<T1>& firstInputStack, stack<T1>& secondInputStack) {
	return (firstInputStack.size == secondInputStack.size);
}
template<typename T1>
bool operator!=(const stack<T1>& firstInputStack, const stack<T1>& secondInputStack) {
	return !(firstInputStack == secondInputStack);
}
template<typename T1>
bool operator<(const stack<T1>& firstInputStack, const stack<T1>& secondInputStack) {
	return (firstInputStack.size < secondInputStack.size);
}
template<typename T1>
bool operator<=(const stack<T1>& firstInputStack, const stack<T1>& secondInputStack) {
	return (firstInputStack.size < secondInputStack.size || firstInputStack == secondInputStack);
}
template<typename T1>
bool operator>(const stack<T1>& firstInputStack, const stack<T1>& secondInputStack) {
	return (firstInputStack.size > secondInputStack.size);
}
template<typename T1>
bool operator>=(const stack<T1>& firstInputStack, const stack<T1>& secondInputStack) {
	return (firstInputStack.size > secondInputStack.size || firstInputStack == secondInputStack);
}
template<typename T>
T& stack<T>::operator[](int index) {return stackOnArray[index];}
template<typename T1>
void operator<<(stack<T1>& InputStack, T1 value) {InputStack.push(value);}
template<typename T1>
T1 operator>>(stack<T1>& inputStack, T1 forReturnPopValue) {
	forReturnPopValue = inputStack.pop();
	return forReturnPopValue;
}
template<typename T1>
bool operator<<=(stack<T1>& inputStack, bool forCompareBoolValue) {
	return !(inputStack.isEmpty() == forCompareBoolValue);
}
template<typename T1>
T1 operator>>=(stack<T1>& inputStack, double value) {
	value = inputStack.top();
	return value;
}

#endif //LAB8__STACK_H_