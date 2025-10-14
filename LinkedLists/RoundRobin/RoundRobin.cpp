#include<iostream>
using namespace std;

class ProcessScheduler {
private:
	int processID;
	int bestTime;
	int remainingTime;
	ProcessScheduler* next;
	ProcessScheduler* prev;
public:
	ProcessScheduler() {
		processID = 0;
		bestTime = 0;
		remainingTime = 0;
		next = nullptr;
		prev = nullptr;
	}
	void setPID(int id){
		processID = id;
	}
	void setBT(int t){
		bestTime = t;
	}
	void setRT(int t){
		remainingTime = t;
	}
	void setNextAdd(ProcessScheduler* n){
		next = n;
	}
	void setPrevAdd(ProcessScheduler* p){
		prev = p;
	}
	int getPID(){
		return processID;
	}
	int getBT(){
		return bestTime;
	}
	int getRT(){
		return remainingTime;
	}
	ProcessScheduler* getNextAdd(){
		return next;
	}
	ProcessScheduler* getPrevAdd(){
		return prev;
	}

};

class RoundRobinScheduler {
private:
	ProcessScheduler* head;
	int timeQuantum;
public:
	RoundRobinScheduler() {
		head = nullptr;
		timeQuantum = 0;
	}
	void setQuantum(int t) {
		timeQuantum = t;
	}
	void addProcess(int id, int burst) {
		ProcessScheduler* newProcess = new ProcessScheduler;
		newProcess->setPID(id);
		newProcess->setBT(burst);

		if (head == nullptr) {

			newProcess->setNextAdd(newProcess);
			newProcess->setPrevAdd(newProcess);
			head = newProcess;
		}
		else {
			head->getPrevAdd()->setNextAdd(newProcess);
			newProcess->setPrevAdd(head->getPrevAdd());
			newProcess->setNextAdd(head);
			head->setPrevAdd(newProcess);
		}
	}

	void display() {

		if (head == nullptr) {
			cout << "Empty......." << endl;
			return;
		}

		cout << "Dislaying Processes.......\n" << endl;
		ProcessScheduler* temp = head;
		int count = 1;

		while (temp->getNextAdd()!= head) {
			cout << "<<---- Process #" << count << endl;
			cout << "Process Time: " << temp->getPID() << endl;
			cout << "Burst Time: " << temp->getBT() << endl;
			cout << endl;

			temp = temp->getNextAdd();
			count++;

			if (temp->getNextAdd() == head) {
				cout << "<<---- Process #" << count << endl;
				cout << "Process Time: " << temp->getPID() << endl;
				cout << "Burst Time: " << temp->getBT() << endl;
				cout << endl;
			}

			
		}


	}
	void executeProcess() {
		if (head == nullptr) {
			cout << "No process to execute....." << endl;
			return;
		}

		if (timeQuantum <= 0) {
			cout << "Invalid Time Quantum." << endl;
			return;
		}

		cout << "\n<<---- Executing Round Robin Scheduling ---->>\n" << endl;

		ProcessScheduler* current = head;
		bool allDone = false;
		int timeElapsed = 0;

		// Initialize remaining time for each process if not already set
		ProcessScheduler* tempInit = head;
		do {
			tempInit->setRT(tempInit->getBT());
			tempInit = tempInit->getNextAdd();
		} while (tempInit != head);

		while (!allDone) {
			allDone = true;
			ProcessScheduler* temp = head;

			do {
				if (temp->getRT() > 0) {
					allDone = false;

					cout << "Processing P" << temp->getPID() << " | ";

					if (temp->getRT() > timeQuantum) {
						timeElapsed += timeQuantum;
						temp->setRT(temp->getRT() - timeQuantum);
						cout << "Executed for " << timeQuantum
							<< " units | Remaining: " << temp->getRT()
							<< " | Time Elapsed: " << timeElapsed << endl;
					}
					else {
						timeElapsed += temp->getRT();
						cout << "Executed for " << temp->getRT()
							<< " units | Completed at: " << timeElapsed << endl;
						temp->setRT(0);
					}
				}
				temp = temp->getNextAdd();
			} while (temp != head);
		}

		cout << "\nAll processes have been executed successfully!\n";
	}

};


int main() {

	int option, pId, bTime, time;

	RoundRobinScheduler myList;

	do {
		cout << "<<---- Menu ---->>\n" << endl;
		cout << "1. Add Process\n";
		cout << "2. Display Process\n";
		cout << "3. Enter Quantum Time\n";
		cout << "4. Execute Process\n";
		cout << "5. Exit\n";
		cout << "Enter your choice\n";
		cin >> option;

		switch (option) {
		case 1:
			cout << "Enter Process ID: ";
			cin >> pId;
			cout << "Enter Burst Time: ";
			cin >> bTime;
			myList.addProcess(pId, bTime);
			break;
		case 2:
			myList.display();
			break;
		case 3:
			cout << "Enter Quantum Time: ";
			cin >> time;
			myList.setQuantum(time);
			break;
		case 4:  myList.executeProcess();
			break;
		case 5:
			return 0;
		}

	} while (option > 0 && option <= 5);



	return 0;
}