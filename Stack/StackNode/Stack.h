#ifndef STACK_H
#define STACK_H

#include"StackNode.h"
#include<iostream>
#include<string>

using namespace std;

class Stack {
private:
	StackNode* top;
public:
	Stack() {
		top = nullptr;
	}
	void push(int v) {
		StackNode* newNode = new StackNode(v);

		newNode->setNextAdd(top);
		top = newNode;
		cout << "Value '" << v << "' pushed Successfully." << endl;
	}
	void pop() {
		if (isEmpty()) {
			cout << "Stack Empty." << endl;
			return;
		}
		cout << "Value '" << top->getData() << "' popped Successfully." << endl;
		StackNode* temp = top;
		top = top->getNextAdd();
		temp->setNextAdd(nullptr);
		delete temp;
	}
	void displayTop() {
		if (isEmpty()) {
			cout << "Stack Empty." << endl;
			return;
		}
		cout << "Top value is '" << top->getData() << "'." << endl;
	}
	bool isEmpty() {
		return top == nullptr;
	}
	void display() {
		if (isEmpty()) {
			cout << "Stack Empty." << endl;
			return;
		}
		int count = 1;
		cout << "No.\t\tValue" << endl;
		
		StackNode* temp = top;

		while (temp != nullptr) {
			cout << count++ << "\t\t" << temp->getData() << endl;
			temp = temp->getNextAdd();
		}

	}
};
#endif