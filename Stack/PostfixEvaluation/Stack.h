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
			cout << "Stack Full." << endl;
			return;
		}
		arr[++top] = v;
	}
	void pop() {
		if (isEmpty()) {
			cout << "Stack Empty." << endl;
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
	void display() {
		if (isEmpty()) {
			cout << "Stack Empty." << endl;
			return;
		}
		int count = 1;
		cout << "No.\t\tValue" << endl;
		for (int i = top; i >= 0; i--) {
			cout << count++ << "\t\t" << arr[i] << endl;
		}
	}
};
#endif