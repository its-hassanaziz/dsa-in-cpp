#include<iostream>
#include"DList.h"

void insertMenu(DList*);
void deleteMenu(DList*);
void swapMenu(DList*);

using namespace std;

int main() {
	DList* myList = new DList;
	int option, value;

	do {
		cout << "\n<<<===== MAIN MENU ======>>>\n " << endl;
		cout << "\n1.  Insert Menu " << endl;
		cout << "\n2.  Delete Menu " << endl;
		cout << "\n3.  Display Menu" << endl;
		cout << "\n4.  Search Menu " << endl;
		cout << "\n5.  Swap Menu " << endl;
		cout << "\n6.  Exit " << endl;
		cout << "\nEnter your Choice: ";
		cin >> option;

		switch (option) {
		case 1:  insertMenu(myList);
			break;
		case 2:  deleteMenu(myList);
			break;
		case 3:  myList->displayData();
			break;
		case 4:  cout << "Enter Value: ";
				cin >> value;
				myList->advancedSearch(value);
			break;
		case 5:  /* swapMenu(myList);*/
			break;
		case 6:  return 0;
			break;
		}
	} while (option > 0 && option < 6);


	return 0;
}

void insertMenu(DList* myList) {
	int option, value, location;

	do {
		cout << "\n<<----- Insert Menu ----->>" << endl;
		cout << "\n1. Insert at Start " << endl;
		cout << "\n2. Insert at End " << endl;
		cout << "\n3. Insert at Specific Location" << endl;
		cout << "\n4. Back to Main Menu " << endl;
		cout << "\n5. Exit Program " << endl;
		cout << "Enter your Choice: ";
		cin >> option;

		switch (option) {
		case 1:  cout << "Enter Value: ";
			cin >> value;
			myList->insertAtStart(value);
			break;
		case 2:  cout << "Enter Value: ";
			cin >> value;
			myList->insertAtEnd(value);
			break;
		case 3:  cout << "Enter Value: ";
			cin >> value;
			cout << "Enter Location: ";
			cin >> location;
			myList->insertAtLocation(value, location);
			break;
		case 4:  return;
			break;
		case 5:;
			exit(0);
		}
	} while (option > 0 && option < 5);
}
void deleteMenu(DList* myList) {
	int option, location;

	do {
		cout << "\n<<----- Delete Menu ----->>" << endl;
		cout << "\n1. Delete at Start " << endl;
		cout << "\n2. Delete at End " << endl;
		cout << "\n3. Delete at Specific Location" << endl;
		cout << "\n4. Back to Main Menu " << endl;
		cout << "\n5. Exit Program " << endl;
		cout << "Enter your Choice: ";
		cin >> option;

		switch (option) {
		case 1:  myList->deleteAtStart();
			break;
		case 2:  myList->deleteAtEnd();
			break;
		case 3:  cout << "Enter Location: ";
			cin >> location;
			myList->deleteAtLocation(location);
			break;
		case 4:  return;
			break;
		case 5:;
			exit(0);
		}
	} while (option > 0 && option < 5);
}

void swapMenu(DList* myList) {
	int option, value1, value2;

	do {
		cout << "\n<<----- Swap Menu ----->>" << endl;
		cout << "\n1. Swap by Value " << endl;
		cout << "\n2. Swap by Location " << endl;
		cout << "\n3. Back to Main Menu " << endl;
		cout << "\n4. Exit Program " << endl;
		cout << "\nEnter your Choice: ";
		cin >> option;

		switch (option) {
		case 1:  cout << "Enter two Values to Swap." << endl;
			cout << "Value 1: ";
			cin >> value1;
			cout << "Value 2: ";
			cin >> value2;
			myList->swapByValue(value1, value2);
			break;
		case 2: cout << "Enter two Locations to Swap." << endl;
			cout << "Location 1: ";
			cin >> value1;
			cout << "Location 2: ";
			cin >> value2;
			myList->swapByLocation(value1, value2);
			break;
		case 3:  return;
			break;
		case 4:;
			exit(0);
		}
	} while (option > 0 && option < 4);
}