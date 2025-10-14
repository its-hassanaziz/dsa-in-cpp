#include<iostream>
#include<string>
#include"PrintJob.h"

using namespace std;

int main() {
	int option, id, p;
	string n;

	PrintJob myJobList;

	do {
		cout << "<------ Main Menu ------->\n" << endl;
		cout << "1. Add Job." << endl;
		cout << "2. Process Job." << endl;
		cout << "3. Display Job." << endl;
		cout << "4. Display pending Job." << endl;
		cout << "5. Exit." << endl;
		cout << "Enter your choice: ";
		cin >> option;

		switch (option) {
		case 1:  cout << "Add Job." << endl;
			cout << "Enter ID: ";
			cin >> id;
			cout << "Enter Number of Pages: ";
			cin >> p;
			cout << "Enter Job Name: ";
			cin >> n;
			myJobList.addJob(id, p, n);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			return 0;
			break;
		}
	} while (option > 0 && option <= 5);

	return 0;
}