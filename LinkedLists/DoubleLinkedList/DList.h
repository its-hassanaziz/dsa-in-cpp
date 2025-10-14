#ifndef DLIST_H
#define DLIST_H

#include<iostream>
#include<string>
#include "Node.h"

using namespace std;


class DList {
private:
	Node* head;
public:
	DList() {
		head = nullptr;
	}
	void insertAtStart(int v) {
		Node* newNode = new Node(v);
		if (head == nullptr) {
			head = newNode;
			return;
		}
		newNode->setNextAdd(head);
		head->setPrevAdd(newNode);
		head = newNode;
	}
	void insertAtEnd(int v) {

		Node* newNode = new Node(v);

		if (head == nullptr) {
			insertAtStart(v);
			return;
		}

		Node* current = head;

		while (current->getNextAdd() != nullptr) {
			current = current->getNextAdd();
		}
		current->setNextAdd(newNode);
		newNode->setPrevAdd(current);
	}
	void insertAtLocation(int v, int location) {
		int count = 1;

		Node* current = head;
		
		while (current->getNextAdd() != nullptr) {
			count++;
			current = current->getNextAdd();
		}

		if (location > count + 1 || location <= 0) {
			cout << "Invalid Location.." << endl;
			return;
		}
		if (location == 1) {
			insertAtStart(v);
			return;
		}
		if (location == count + 1) {
			insertAtEnd(v);
			return;
		}
		current = head;
		Node* newNode = new Node(v);
		for (int i = 1; i < location-1; i++) {
			current = current->getNextAdd();
		}
		newNode->setNextAdd(current->getNextAdd());
		(current->getNextAdd())->setPrevAdd(newNode);
		newNode->setPrevAdd(current);
		current->setNextAdd(newNode);
	}
	void displayData() {
		if (head == nullptr) {
			cout << "The List is Empty..." << endl;
			return;
		}
		cout << "Index\t\tData\n";
		cout << "--------------------\n";
		int count = 1;
		Node* current = head;

		while (current != nullptr) {
			cout << count << "\t\t" << current->getData() << endl;
			count++;
			current = current->getNextAdd();
		}
	}
	void deleteAtStart() {
		if (head == nullptr) {
			cout << "LIST EMPTY: No Node to delete.." << endl;
			return;
		}
		Node* current = head;
		if (head->getNextAdd() == nullptr) {
			head = nullptr;
			current->setNextAdd(nullptr);
			delete current;
			return;
		}
		
		head = current->getNextAdd();
		head->setPrevAdd(nullptr);
		current->setNextAdd(nullptr);
		delete current;
	}
	void deleteAtEnd() {
		if (head == nullptr) {
			cout << "LIST EMPTY: No Node to delete.." << endl;
			return;
		}
		Node* current = head;
		if (head->getNextAdd() == nullptr) {
			head = nullptr;
			current->setNextAdd(nullptr);
			delete current;
			return;
		}
		current = head;
		while (current->getNextAdd() != nullptr) {
			current = current->getNextAdd();
		}
		(current->getPrevAdd())->setNextAdd(nullptr);
		current->setPrevAdd(nullptr);
		delete current;
	}

	void deleteAtLocation(int location) {
		if (head == nullptr) {
			cout << "LIST EMPTY: No Node to delete.." << endl;
			return;
		}
		int count = 1;

		Node* current = head;

		while (current->getNextAdd() != nullptr) {
			count++;
			current = current->getNextAdd();
		}

		if (location > count || location <= 0) {
			cout << "Invalid Location.." << endl;
			return;
		}
		if (location == 1) {
			deleteAtStart();
			return;
		}
		if (location == count) {
			deleteAtEnd();
			return;
		}
		current = head;
		for (int i = 1; i < location-1; i++) {
			current = current->getNextAdd();
		}
		
		(current->getPrevAdd())->setNextAdd(current->getNextAdd());
		(current->getNextAdd())->setPrevAdd(current->getPrevAdd());
		current->setNextAdd(nullptr);
		current->setPrevAdd(nullptr);
		delete current;
	}
	void advancedSearch(int v) {
		if (head == nullptr) {
			cout << "The List is Empty!.." << endl;
			return;
		}
		Node* current = head;
		int count = 0;
		int location = 1;
		while (current != nullptr) {
			if (current->getData() == v) {
				cout << "Number '" << v << "' found at Loacation " << location << endl;
				count++;
			}
			location++;
			current = current->getNextAdd();
		}
		if (count == 0) {
			cout << "Number not found in th list..." << endl;
			return;
		}
		else {
			cout << "Number '" << v << "' found " << count << " times in the List..." << endl;
		}

	}
	void swapByValue(int v1, int v2) {
		if (head == nullptr) {
			cout << "The list is empty..." << endl;
			return;
		}
		if (v1 == v2) {
			cout << "Both values are same...." << endl;
			return;
		}
		Node* temp = head;
		Node* node1 = nullptr;
		Node* node2 = nullptr;

		while (temp != nullptr) {
			if (temp->getData() == v1) {
				node1 = temp;
			}
			if (temp->getData() == v2) {
				node2 = temp;
			}
			temp = temp->getNextAdd();
		}
		if (node1 == nullptr || node2 == nullptr) {
			cout << "Invalid values to swap..." << endl;
			return;
		}
		int tem = node1->getData();
		node1->setData(node2->getData());
		node2->setData(tem);
	}

	void swapByLocation(int loc1, int loc2) {
		if (head == nullptr) {
			cout << "The list is empty..." << endl;
			return;
		}

		if (loc1 == loc2) {
			cout << "Both locations are same...." << endl;
			return;
		}

		Node* temp = head;
		Node* node1 = nullptr;
		Node* node2 = nullptr;
		int location = 1;

		while (temp != nullptr) {
			if (location==loc1) {
				node1 = temp;
			}
			if (location == loc2) {
				node2 = temp;
			}
			location++;
			temp = temp->getNextAdd();
		}
		if (node1 == nullptr || node2 == nullptr) {
			cout << "Invalid values to swap..." << endl;
			return;
		}

		int tem = node1->getData();
		node1->setData(node2->getData());
		node2->setData(tem);
	}
};
#endif