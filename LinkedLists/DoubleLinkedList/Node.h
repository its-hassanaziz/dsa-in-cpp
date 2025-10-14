#ifndef NODE_H
#define NODE_H

class Node {
private:
	int data;
	Node* nextAdd;
	Node* prevAdd;
public:
	Node() {
		data = 0;
		nextAdd = nullptr;
		prevAdd = nullptr;
	}
	Node(int v) {
		data = v;
		nextAdd = nullptr;
		prevAdd = nullptr;
	}
	void setData(int v) {
		data = v;
	}
	void setNextAdd(Node *ptr) {
		nextAdd = ptr;
	}
	void setPrevAdd(Node *ptr) {
		prevAdd = ptr;
	}
	int getData() const{
		return data;
	}
	Node* getNextAdd() {
		return nextAdd;
	}
	Node* getPrevAdd() {
		return prevAdd;
	}
};
#endif