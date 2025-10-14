#include<iostream>
#include<string>

using namespace std;


class FRMS;
class FlightRoute {
private:
	string  aCode;
	string cName;
	FlightRoute* nextAdd;
public:
	FlightRoute() {
		aCode = "";
		cName = "";
		nextAdd = nullptr;
	}
	FlightRoute(string c, string n) {
		aCode = c;
		cName = n;
		nextAdd = nullptr;
	}
	void setNextAdd(FlightRoute* add) {
		nextAdd = add;
	}
	string getACode() {
		return aCode;
	}
	string getCName() {
		return cName;
	}
	FlightRoute* getNextAdd() {
		return nextAdd;
	}
}; 

void insertMenu(FRMS*);

class FRMS {
private:
	FlightRoute* head;
	FlightRoute* current;
public:
	FRMS() {
		head = nullptr;
		current = nullptr;
	}

	void insertAtLocation(int loc, string c, string n) {

		if (loc <= 0) {
			cout << "Invalid Location." << endl;
			return;
		}

		FlightRoute* newAirport = new FlightRoute(c, n);

		if (loc == 1) {

			if (head == nullptr) {
				head = newAirport;
				return;
			}

			newAirport->setNextAdd(head);
			head = newAirport;
			return;
		}
		if (head == nullptr) {
			cout << "The Route List is Empty." << endl;
			return;
		}

		current = head;

		for (int i = 1; i < loc - 1; i++) {
			if (current->getNextAdd() == nullptr) {
				cout << "Invalid Location." << endl;
				delete newAirport;
				return;
			}
			current = current->getNextAdd();
		}
		newAirport->setNextAdd(current->getNextAdd());
		current->setNextAdd(newAirport);
	}

	void insertAtEnd(string c, string n) {
		FlightRoute* newAirport = new FlightRoute(c, n);

		if (head == nullptr) {
			head = newAirport;
			return;
		}
		current = head;
		while (current->getNextAdd() != nullptr) {
			current = current->getNextAdd();
		}
		current->setNextAdd(newAirport);
	}
	void deleteAirport(string c) {

		if (head == nullptr) {
			cout << "The Route List is Empty." << endl;
			return;
		}

		current = head;
		FlightRoute* prev = head;


		while (current != nullptr) {
			if (current->getACode() == c) {

				return;
			}
			prev = current;
			current = current->getNextAdd();
		}

		if (prev->getNextAdd() == nullptr) {
			cout << "Invalid Location." << endl;
			return;
		}

		FlightRoute* temp = prev->getNextAdd();
		prev->setNextAdd(prev->getNextAdd()->getNextAdd());
		temp->setNextAdd(nullptr);
		delete temp;
	}

	void searchAirport(string c) {
		if (head == nullptr) {
			cout << "The Route List is Empty." << endl;
			return;
		}

		current = head;

		while (current != nullptr) {
			if (current->getACode() == c) {
				cout << "Airport '" << c << "' Found in the Route List. " << endl;
				cout << "Airport Code: " << current->getACode() << endl;
				cout << "Airport City Name: " << current->getCName() << endl;
				return;
			}
			current = current->getNextAdd();
		}
		cout << "Airport '" << c << "' Not Found in the Route List" << endl;
	}
	void displayFlightRoute() {
		if (head == nullptr) {
			cout << "The Route List is Empty." << endl;
			return;
		}
		current = head;
		cout << "<------ Displaying Entire Flight Route ------>\n" << endl;
		while (current != nullptr) {
			cout << current->getACode() << " ( " << current->getCName() << " ) " << " ---> ";
			current = current->getNextAdd();
		}
	}

};
int main() {
	FRMS* myRouteList = new FRMS;
	int option;
	string c;

	do {
		cout << "\n<<<===== MAIN MENU ======>>>\n " << endl;
		cout << "\n1.  Add a New Stop. " << endl;
		cout << "\n2.  Remove an Airport Stop. " << endl;
		cout << "\n3.  Search Airport." << endl;
		cout << "\n4.  Display Flight Route." << endl;
		cout << "\n5.  Exit." << endl;
		cout << "\nEnter your Choice: ";
		cin >> option;

		switch (option) {
		case 1:  insertMenu(myRouteList);
			break;
		case 2:  cout << "Enter Airport Code to delete: ";
			cin >> c;
			myRouteList->deleteAirport(c);
			break;
		case 3:  cout << "Enter Airport Code to Display its Data: ";
			cin >> c;
			myRouteList->searchAirport(c);
			break;
		case 4:   myRouteList->displayFlightRoute();
			break;
		case 5:  return 0;
			break;
		}
	} while (option > 0 && option < 5);





	return 0;
}

void insertMenu(FRMS* myList) {
	int option, location;
	string c,n;

	do {
		cout << "\n<<----- Insert Menu ----->>" << endl;
		cout << "\n1. Insert Airport at End. " << endl;
		cout << "\n2. Insert Airport at Specific Location." << endl;
		cout << "\n3. Back to Main Menu. " << endl;
		cout << "\n4. Exit Program. " << endl;
		cout << "Enter your Choice: ";
		cin >> option;

		switch (option) {
		case 1:  cout << "Enter Airport Code: ";
			cin >> c;
			cout << "Enter Airport City: ";
			cin >> n;
			myList->insertAtEnd(c,n);
			break;
		case 2:  cout << "Enter Location: ";
			cin >> location;
			cout << "Enter Airport Code: ";
			cin >> c;
			cout << "Enter Airport City: ";
			cin >> n;
			myList->insertAtLocation(location, c, n);
			break;
		case 3:  return;
			break;
		case 4:
			exit(0);
		}
	} while (option > 0 && option < 4);
}