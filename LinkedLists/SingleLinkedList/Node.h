#ifndef NODE_H
#define NODE_H

class Node {
private:
	int data;
	Node* nextAdd;
public:
	Node() {
		data = 0;
		nextAdd = nullptr;
	}
	Node(int v) {
		data = v;
		nextAdd = nullptr;
	}
	void setNextAdd(Node* add) {
		nextAdd = add;
	}
	int getData()  const {
		return data;
	}
	Node *getNextAdd()  const {
		return nextAdd;
	}
};
#endif