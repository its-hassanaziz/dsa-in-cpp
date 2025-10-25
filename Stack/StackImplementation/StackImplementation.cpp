#include<iostream>
#include<string>
#include"Stack.h"
using namespace std;

int main() {
	int option;
	int size;
	int value;

	cout << "Enter size of Stack: ";
	cin >> size;

	Stack myStack(size);

	do {
		system("cls");
		cout << "<----- Main Menu ----->\n" << endl;
		cout << "1. Push Value.\n";
		cout << "2. Pop Value.\n";
		cout << "3. Display Top.\n";
		cout << "4. Display Data.\n";
		cout << "5. Exit Program.\n";
		cout << "Enter your Choice: ";
		cin >> option;

		switch (option) {
		case 1: cout << "Enter Value to Push: ";
			cin >> value;
			myStack.push(value);
			system("pause");
			break;
		case 2: myStack.pop();
			system("pause");
			break;
		case 3: myStack.displayTop();
			system("pause");
			break;
		case 4: myStack.display();
			system("pause");
			break;
		case 5:
			return 0;
		}
	} while (option > 0 && option <= 5);



	return 0;
}