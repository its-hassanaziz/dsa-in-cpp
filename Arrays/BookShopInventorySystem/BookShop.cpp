#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

#include"Book.h"
#include"Inventory.h"
#include"User.h"
#include"SalesMan.h"

void loginSalesMan();

int Inventory::booksCount = 0;

using namespace std;

int main()
{
	int choice;
	cout << "<<===== Showing Menu =====>>\n" << endl;
	cout << "Enter your Choice." << endl;
	cout << "1. Login" << endl;
	cout << "2. Exit" << endl;
	cin >> choice;

	switch (choice) {
	case 1:  loginSalesMan();
		break;
	case 2: cout << "Quiting Program." << endl;
		return 0;
	default:
		cout << "Invalid Choice." << endl;
		return 0;
	}

	return 0;
}

void loginSalesMan() {

	string name, sMName, password;

	cout << "\n<<===== Login Page =====>>\n" << endl;
	cout << "Enter Your Name: ";
	cin >> sMName;
	cout << "Enter User Name: ";
	cin >> name;
	cout << "Enter User Password: ";
	cin >> password;

	User* currentUser = new SalesMan(sMName, name, password);
	if (currentUser->loginCheck()) {
		currentUser->showMenu();
	}
	else
	{
		cout << "Invalid User Name or Password." << endl;
		cout << "Login Again." << endl;
		loginSalesMan();
	}
	delete currentUser;
}