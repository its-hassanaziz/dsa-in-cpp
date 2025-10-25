#ifndef STACKNODE_H
#define STACKNODE_H

#include<iostream>
#include<string>
using namespace std;

class StackNode {
private:
	int data;
	StackNode *nextAdd;
public:
	StackNode() {
		data = 0;
		nextAdd = nullptr;
	}
	StackNode(int v) {
		data = v;
		nextAdd = nullptr;
	}
	void setData(int v) {
		data = v;
	}
	void setNextAdd(StackNode* next) {
		nextAdd = next;
	}
	int getData() {
		return data;
	}
	StackNode* getNextAdd() {
		return nextAdd;
	}
};
#endif