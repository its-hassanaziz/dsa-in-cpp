#ifndef LIST_H
#define LIST_H

#include<iostream>
#include"Node.h"
using namespace std;

class List {
private:
	Node* head;
public:
	List() {
		head = nullptr;
	}
	void insertAtStart(int v) {
		Node* newNode = new Node(v);

		if (head == nullptr) {
			head = newNode;
			return;
		}

		newNode->setNextAdd(head);
		head = newNode;
	}
	void insertAtEnd(int v) {
		Node* newNode = new Node(v);

		if (head == nullptr) {
			head = newNode;
			return;
		}
		Node* temp = head;
		while (temp->getNextAdd() != nullptr) {
			temp = temp->getNextAdd();
		} 
		temp->setNextAdd(newNode);
	}
	void deleteAtStart() {
		if (head == nullptr) {
			cout << "The List is already Empty." << endl;
			return;
		}
		Node* temp = head;

		head = temp->getNextAdd();
		temp->setNextAdd(nullptr);
		delete temp;
		
	}
	void deleteAtEnd() {
		if (head == nullptr) {
			cout << "The List is already Empty." << endl;
			return;
		}
		if (head->getNextAdd() == nullptr) {
			deleteAtStart();
			return;
		}
		Node* temp = head;
		while (temp->getNextAdd()->getNextAdd() != nullptr) {
			temp = temp->getNextAdd();
		}
		Node* lastNode = temp->getNextAdd();
		temp->setNextAdd(nullptr);
		delete lastNode;
	}
	void insertAtLocation(int v, int loc) {
		if (loc <= 0) {
			cout << "Invalid Location." << endl;
			return;
		}
		if (loc == 1) {
			insertAtStart(v);
			return;
		}
		if (head == nullptr) {
			cout << "The List is Empty." << endl;
			return;
		}
		Node* newNode=new Node(v);
		Node* temp = head;

		for (int i = 1; i < loc-1; i++) {
			if (temp->getNextAdd() == nullptr) {
				cout << "Invalid Location." << endl;
				delete newNode;
				return;
			}
			temp = temp->getNextAdd();
		}
		newNode->setNextAdd(temp->getNextAdd());
		temp->setNextAdd(newNode);
	}
	void deleteAtLocation(int loc) {
		if (loc <= 0) {
			cout << "Invalid Location." << endl;
			return;
		}
		if (loc == 1) {
			deleteAtStart();
			return;
		}
		if (head == nullptr) {
			cout << "The List is Empty." << endl;
			return;
		}
	
		Node* prev = head;

		for (int i = 1; i < loc - 1; i++) {
			if (prev->getNextAdd() == nullptr) {
				cout << "Invalid Location." << endl;
				return;
			}
			prev = prev->getNextAdd();
		}

		if (prev->getNextAdd() == nullptr) {
			cout << "Invalid Location." << endl;
			return;
		}

		Node* temp = prev->getNextAdd();
		prev->setNextAdd(prev->getNextAdd()->getNextAdd());
		temp->setNextAdd(nullptr);
		delete temp;
	}

	void normalDisplay()  const {
		if (head == nullptr) {
			cout << "The List is Empty." << endl;
			return;
		}
		Node* temp = head;
		int count = 1;
		cout << "\nIndex\tValue"<<endl;
		cout << "------------------"<<endl;
		while (temp != nullptr) {
			cout << count << "\t" << temp->getData() << endl;
			temp = temp->getNextAdd();
			count++;
		}

	}
	void evenDisplay()  const {
		if (head == nullptr) {
			cout << "The List is Empty." << endl;
			return;
		}
		Node* temp = head;
		int count = 1;
		cout << "\nIndex\tEven Values" << endl;
		cout << "------------------" << endl;
		while (temp != nullptr) {
			if (temp->getData() % 2 == 0) {
				cout << count << "\t" << temp->getData() << endl;
			}
			temp = temp->getNextAdd();
			count++;
		}
	}
	void oddDisplay()  const {
		if (head == nullptr) {
			cout << "The List is Empty." << endl;
			return;
		}
		Node* temp = head;
		int count = 1;
		cout << "\nIndex\tOdd Values" << endl;
		cout << "------------------" << endl;
		while (temp != nullptr) {
			if (temp->getData() % 2 != 0) {
				cout << count << "\t" << temp->getData() << endl;
			}
			temp = temp->getNextAdd();
			count++;
		}
	}
	void reverseDisplay()  const {

		if (head == nullptr) {
			cout << "The List is Empty." << endl;
			return;
		}

		Node* temp = head;
		Node* current = nullptr;
		int count = 1;
		cout << "\nIndex\tReversed List" << endl;
		cout << "------------------" << endl;
		while (temp != nullptr) {
			while (temp != nullptr) {
				if (temp->getNextAdd() ==  current) {
					cout << count << "\t" << temp->getData() << endl;
					current=temp;
					count++;
				}
				temp = temp->getNextAdd();
				
			}
			temp = head;
			if (current == head)
				break;	
		}
	}
	void searchByValue(int v)  {

		if (head == nullptr) {
			cout << "The List is Empty." << endl;
			return;
		}

		Node* temp = head;

		while (temp != nullptr) {
			if (temp->getData() == v) {
				cout <<"Number '" << v << "' Found in the List. " << endl;
				return;
			}
			temp = temp->getNextAdd();
		}
		cout << "Number '" << v << "' Not Found in the List" << endl;
	}
	void advancedSearch(int v)  const {

		if (head == nullptr) {
			cout << "The List is Empty." << endl;
			return;
		}

		Node* temp = head;
		bool found = false;
		int count = 0;
		int location = 1;

		while (temp != nullptr) {
			if (temp->getData() == v) {
				cout << "Number '" << v << "' Found at Location: " << location << endl;
				count++;
				found = true;
			}
			temp = temp->getNextAdd();
			location++;
		}

		if (found) {
			cout << "Number '" << v << "' Found " <<count<<" times in the List" << endl;
		}
		if (!found) {
			cout << "Number '" << v << "' Not Found in the List" << endl;
		}
	}
	void swapByValue(int v1, int v2) {
		if (head == nullptr) {
			cout << "The List is Empty." << endl;
			return;
		}
		if (head->getNextAdd() == nullptr) {
			cout << "The List has only one node." << endl;
			return;
		}
		if (v1 == v2) {
			cout << "No need to swap values." << endl;
			return;
		}

		Node* prev1 = nullptr;
		Node* prev2 = nullptr;
		Node* node1 = head;
		Node* node2 = head;

		while (node1 != nullptr && node1->getData() != v1) {
			prev1 = node1;
			node1 = node1->getNextAdd();
		}

		while (node2 != nullptr && node2->getData() != v2) {
			prev2 = node2;
			node2 = node2->getNextAdd();
		}

		if (node1 == nullptr || node2 == nullptr) {
			cout << "ERROR: One or both values not found." << endl;
			return;
		}

		if (prev1 != nullptr) {
			prev1->setNextAdd(node2);
		}
		else {
			head = node2; 
		}

		if (prev2 != nullptr) {
			prev2->setNextAdd(node1);
		}
		else {
			head = node1; 
		}

		Node* temp = node1->getNextAdd();
		node1->setNextAdd(node2->getNextAdd());
		node2->setNextAdd(temp);
	}
	void swapByLocation(int pos1, int pos2) {
		if (pos1 <= 0 || pos2 <= 0) {
			cout << "Invalid positions." << endl;
			return;
		}
		if (head == nullptr || head->getNextAdd() == nullptr) {
			cout << "List too small to swap." << endl;
			return;
		}
		if (pos1 == pos2) {
			cout << "No need to swap same positions." << endl;
			return;
		}

		if (pos1 > pos2) {
			int tempPos = pos1;
			pos1 = pos2;
			pos2 = tempPos;
		}

		Node* prev1 = nullptr, * prev2 = nullptr;
		Node* node1 = head, * node2 = head;

		for (int i = 1; node1 != nullptr && i < pos1; i++) {
			prev1 = node1;
			node1 = node1->getNextAdd();
		}

		for (int i = 1; node2 != nullptr && i < pos2; i++) {
			prev2 = node2;
			node2 = node2->getNextAdd();
		}

		if (node1 == nullptr || node2 == nullptr) {
			cout << "ERROR: One or both positions out of range." << endl;
			return;
		}

		if (prev1 != nullptr) prev1->setNextAdd(node2);
		else head = node2;

		if (prev2 != nullptr) prev2->setNextAdd(node1);
		else head = node1;

		Node* temp = node1->getNextAdd();
		node1->setNextAdd(node2->getNextAdd());
		node2->setNextAdd(temp);
	}
	void concatenateLists(List& newList)  {

		if (head == nullptr) {
			head = newList.head;
			return;
		}


		Node* temp = head;
		while (temp->getNextAdd() != nullptr) {
			temp = temp->getNextAdd();
		}

		temp->setNextAdd(newList.head);
	}


	
};
#endif