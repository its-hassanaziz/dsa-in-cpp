#include<iostream>
using namespace std;
#define SIZE 10

class ParkingStack {
private:
	int slots[SIZE];
	int topEven;
	int topOdd;
public:
	ParkingStack() {
		for (int i = 0; i < SIZE; i++) {
			slots[i] = -1;
		}
		topEven = -2;
		topOdd = -1;
	}

	bool isFullEven() {
		return topEven == 8;
	}
	bool isFullOdd() {
		return topEven == 9;
	}
	bool isEmptyEven() {
		return topEven == -2;
	}
	bool isEmptyOdd() {
		return topEven == -1;
	}

	void push(int v) {
		if (v % 2 == 0) {
			if (isFullEven()) {
				cout << "Even Stack Full.." << endl;
				return;
			}
			topEven = topEven + 2;
			slots[topEven] = v;
			cout << "Car " << v << " parked at even slot.." << endl;
			
		}
		else {
			if (isFullOdd()) {
				cout << "Odd Stack Full.." << endl;
				return;
			}
			topOdd = topOdd + 2;
			slots[topOdd] = v;
			cout << "Car " << v << " parked at odd slot.." << endl;
		}
	}

	void pop() {
		int choice;

		cout << "1. Even Car" << endl;
		cout << "1. Odd Car" << endl;
		cout << "Enter your choice...." << endl;
		cin >> choice;

		if (choice == 1) {
			if (isEmptyEven()) {
				cout << "Even Stack Empty.." << endl;
				return;
			}
			slots[topEven]=-1;
			topEven -= 2;

		}
		else if (choice == 2) {
			if (isEmptyOdd()) {
				cout << "Odd Stack Empty.." << endl;
				return;
			}
			slots[topOdd]=-1;
			topOdd -= 2;
		}
		else {
			cout << "Invalid Choice..." << endl;
		}
	}
	void display() {
		cout << "<<------ Car Parikng Status ------>>\n" << endl;
		for (int i = 0; i < SIZE; i++) {
			if (slots[i] == -1) {
				cout << "Slot Empty..." << endl;
			}
			else {
				cout << "Slot " << i << " Car Number " << slots[i] << endl;
			}
		}
	}

};

int main() {

	int option, value;
	ParkingStack obj;

	do {
		cout << "<<----- Main Menu ----->>\n" << endl;
		cout << "1. Park a Car\n";
		cout << "2. Remove a Car\n";
		cout << "3. Display entire Parking Slots\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: \n";
		cin >> option;

		switch (option) {
		case 1:
			cout << "Enter Car Registration Number: ";
			cin >> value;
			obj.push(value);
			system("pause");
			break;
		case 2:
			obj.pop();
			system("pause");
			break;
		case 3:
			obj.display();
			system("pause");
			break;
		case 4:
			return 0;
		}
		system("cls");
	} while (option > 0 && option <= 4);



	return 0;
}