#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

struct event
{
	string name;
	string date;
	string time;
	string description;
};

const int MAX_EVENTS = 100;
event events[MAX_EVENTS];
int eventCount = 0;

void loadEvents();
void saveEvents();
void displayMenu();

void addEvents();
void viewEvents();
void editEvents();
void deleteEvents();

int main()
{
	cout << "\n<<<---Welcome To The Event Scheduler--->>>\n\n\n";
	loadEvents();
	displayMenu();

	cout << "Your events are safe and sound, unless the computer accidentally decided to erase them... just kidding!\n";
	return 0;
}

//Function for loading events
void loadEvents() {

	ifstream eventsFile("events.txt");

	if (!eventsFile) {
		cout << "No events found. Start by adding new events.\n";
		return;
	}

	eventCount = 0;
	while (eventsFile >> ws && getline(eventsFile, events[eventCount].name)) {
		getline(eventsFile, events[eventCount].date);
		getline(eventsFile, events[eventCount].time);
		getline(eventsFile, events[eventCount].description);
		eventCount++;
	}

	eventsFile.close();
	cout << eventCount << " Events loaded successfully.\n";

}

//Function for saving events
void saveEvents() {
	ofstream outPutFile;
	outPutFile.open("events.txt");

	for (int i = 0; i < eventCount; i++)
	{
		outPutFile << endl << events[i].name << endl
			<< events[i].date << endl
			<< events[i].time << endl
			<< events[i].description << endl;
	}
	outPutFile.close();

	cout << "Events saved Successfully\n\n";

	char choice;

	cout << "Enter 'M' to add more Events\n";
	cout << "Enter 'Y' to Open the Menu\n";
	cout << "Enter 'N' to close the Program\n";
	cin >> choice;

	if (choice == 'M' || choice == 'm') {
		addEvents();
	}
	else if (choice == 'Y' || choice == 'y') {
		displayMenu();
	}
	return;
}

//Function to display the menu and call the respective function
void displayMenu() {

	int choice;

	do
	{
		cout << "Please select your choice\n\n";
		cout << "1. Add new Event\n";
		cout << "2. Edit an existing Event\n";
		cout << "3. View Events\n";
		cout << "4. Delete Events\n";
		cout << "5. Exit the program\n\n";
		cin >> choice;

		switch (choice)
		{
		case 1: addEvents();
			break;
		case 2: editEvents();
			break;
		case 3: viewEvents();
			break;
		case 4: deleteEvents();
			break;
		case 5: return;
			break;
		default: cout << "INVALID CHOICE: Try Againn\n\n";
		}
	} while (choice > 5 || choice < 1);
}

//Function for adding events
void addEvents()
{
	event e;

	cout << "Enter the Name of Event: ";
	cin.ignore();
	getline(cin, e.name);
	cout << "Enter the Date for Event (DD//MM/YYYY): ";
	getline(cin, e.date);
	cout << "Enter the Time for Event (HH/MM): ";
	getline(cin, e.time);
	cout << "Enter the Description for Event: ";
	getline(cin, e.description);

	events[eventCount++] = e;

	saveEvents();
}

//Function for viewing events
void viewEvents() {
	if (eventCount == 0) {
		cout << "No events to display. Please add some events first.\n";
		return;
	}

	cout << "\n\t\t\t<<<--- List of Events --->>>\n\n";

	cout << left << setw(5) << "No."
		<< left << setw(30) << "Name"
		<< left << setw(15) << "Date"
		<< left << setw(10) << "Time"
		<< "Description\n";
	cout << "---------------------------------------------------------------------------------------------" << endl << endl;

	for (int i = 0; i < eventCount; i++) {
		cout << left << setw(5) << i + 1
			<< left << setw(30) << events[i].name
			<< left << setw(15) << events[i].date
			<< left << setw(10) << events[i].time
			<< events[i].description << endl;
	}

	cout << endl << "---------------------------------------------------------------------------------------------" << endl;

	char choice;

	cout << "Enter 'Y' to Open the Menu\n";
	cout << "Enter 'N' to close the Program\n";
	cin >> choice;

	if (choice == 'Y' || choice == 'y') {
		displayMenu();
	}
	else
		return;

}

//Function for editing events
void editEvents() {
	if (eventCount == 0) {
		cout << "No events available to edit. Please add some events first.\n";
		return;
	}

	cout << "\n\t\t\t<<<--- List of Events --->>>\n\n";

	cout << left << setw(5) << "No."
		<< left << setw(30) << "Name"
		<< left << setw(15) << "Date"
		<< left << setw(10) << "Time"
		<< "Description\n";
	cout << "---------------------------------------------------------------------------------------------" << endl << endl;

	for (int i = 0; i < eventCount; i++) {
		cout << left << setw(5) << i + 1
			<< left << setw(30) << events[i].name
			<< left << setw(15) << events[i].date
			<< left << setw(10) << events[i].time
			<< events[i].description << endl;
	}

	cout << endl << "---------------------------------------------------------------------------------------------" << endl;

	int choice;
	cout << "\nEnter the number of the event you want to edit (1 - " << eventCount << "): ";
	cin >> choice;

	if (choice < 1 || choice > eventCount) {
		cout << "Invalid choice. Returning to the menu.\n";
		return;
	}

	int index = choice - 1;

	cout << endl << left << setw(5)
		<< left << setw(30) << events[index].name
		<< left << setw(15) << events[index].date
		<< left << setw(10) << events[index].time
		<< events[index].description << endl;

	event editedEvent;

	cout << "Enter the new Name of Event: ";
	cin.ignore();
	getline(cin, editedEvent.name);
	cout << "Enter the new Date for Event (DD//MM/YYYY): ";
	getline(cin, editedEvent.date);
	cout << "Enter the new Time for Event (HH/MM): ";
	getline(cin, editedEvent.time);
	cout << "Enter the new Description for Event: ";
	getline(cin, editedEvent.description);

	events[index] = editedEvent;
	saveEvents();
}

//Function for deleting events
void deleteEvents() {
	if (eventCount == 0) {
		cout << "No events available to edit. Please add some events first.\n";
		return;
	}

	cout << "\n\t\t\t<<<--- List of Events --->>>\n\n";

	cout << left << setw(5) << "No."
		<< left << setw(30) << "Name"
		<< left << setw(15) << "Date"
		<< left << setw(10) << "Time"
		<< "Description\n";
	cout << "---------------------------------------------------------------------------------------------" << endl << endl;

	for (int i = 0; i < eventCount; i++) {
		cout << left << setw(5) << i + 1
			<< left << setw(30) << events[i].name
			<< left << setw(15) << events[i].date
			<< left << setw(10) << events[i].time
			<< events[i].description << endl;
	}

	cout << endl << "---------------------------------------------------------------------------------------------" << endl;

	int choice;
	cout << "\nEnter the number of the event you want to delete (1 - " << eventCount << "): ";
	cin >> choice;

	if (choice < 1 || choice > eventCount) {
		cout << "Invalid choice. Try Again\n";
		deleteEvents();
	}

	int eventIndex = choice - 1;

	char confirmation;
	cout << "\nPlease confirm to delete the event ( " << events[eventIndex].name << " )? (Y/N): ";
	cin >> confirmation;

	if (confirmation == 'Y' || confirmation == 'y') {
		for (int i = eventIndex; i < eventCount - 1; i++) {
			events[i] = events[i + 1];
		}
		eventCount--;
		cout << "\nThe Event is deleted Successfully!\n";
	}
	else {
		cout << "\nDeletion Cancelled\n";
	}
	saveEvents();
}