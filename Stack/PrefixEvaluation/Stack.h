#ifndef STACK_H
#define STACK_H
#include<iostream>
#include<string>
using namespace std;

class Stack {
private:
	int* arr;
	int top;
	int size;
public:
	Stack(int s) {
		arr = new int[s];
		top = -1;
		size = s;
	}
	void push(int v) {
		if (isFull()) {
			return;
		}
		arr[++top] = v;
	}
	void pop() {
		if (isEmpty()) {
			return;
		}
		top--;
	}
	int Top() {
		if (isEmpty()) {
			return -1;
		}
		return arr[top];
	}
	bool isEmpty() {
		return top == -1;
	}
	bool isFull() {
		return top == size - 1;
	}
	
};
#endif