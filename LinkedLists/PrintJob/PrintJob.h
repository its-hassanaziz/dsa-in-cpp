#ifndef PRINTJOB_H
#define PRINTJOB_H

#include<string>
#include"JobInfo.h"
#include<iostream>

using namespace std;

class PrintJob {
private:
	JobInfo* head;
	JobInfo* current;
	int noJ;
public:
	PrintJob() {
		head = nullptr;
		current = nullptr;
		noJ = 0;
	}
	void addJob(int id, int p, string n) {
		JobInfo* newJobInfo = new JobInfo(id, p, n);

		if (head == nullptr) {
			head = newJobInfo;
			noJ++;
			return;
		}
		current = head;
		while (current->getNextAdd() != nullptr) {
			current = current->getNextAdd();
		}
		current->setNextAdd(newJobInfo);
		noJ++;
	}
	void processJob() {
		if (head == nullptr) {
			cout << "No job to Process." << endl;
			return;
		}
		current = head;
		head = current->getNextAdd();

		cout << "\nID: "<<current->getJID() << endl;
		cout << "No. of Pages: "<<current->getnoP() << endl;
		cout << "Job Name: "<<current->getjName() << endl;

		
		current->setNextAdd(nullptr);
		delete current;
		noJ--;
	}

	void displayJob() {
		if (head == nullptr) {
			cout << "No job to display." << endl;
			return;
		}
		current = head;
		int count = 1;
		cout << "\nIndex\tJob ID\tNum Pages\tJob Name" << endl;
		cout << "----------------------------------------" << endl;
		while (current != nullptr) {
			cout << count << "\t" << current->getJID();
			cout << "\t" << current->getnoP();
			cout << "\t" << current->getjName() << endl;
			current = current->getNextAdd();
			count++;
		}
	}
	void isEmpty() {
		if (head == nullptr)
			cout << "Empty queue." << endl;
		else {
			cout << "Queue not Empty.";
		}
	}
};
#endif