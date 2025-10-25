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
		cout << "Value '" << v << "' pushed Successfully." << endl;
	}
	void pop() {
		if (isEmpty()) {
			cout << "Stack Empty." << endl;
			return;
		}
		cout << "Value '" << arr[top] << "' poped Successfully." << endl;
		top--;
	}
	void displayTop() {
		if (isEmpty()) {
			cout << "Stack Empty." << endl;
			return;
		}
		cout << "Top value is '" << arr[top] << "'." << endl;
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