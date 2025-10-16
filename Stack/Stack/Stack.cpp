#include<iostream>

using namespace std;


class myStack {
private:
	int A[10];
	int top;
public:
	myStack() {
		top = -1;
	}
	void push(int v) {
		A[++top] = v;
	}
	int pop() {
		return A[top--];
	}
	int peek() {
		return A[top];
	}
	bool isEmpty() {
		return top == -1;
	}
	bool isFull() {
		return top = 9;
	}
};

int main() {
	int option, value;
	myStack obj;

	do {
		system("cls");
		cout << "<<----- Main Menu ----->>\n" << endl;
		cout << "1. Push\n";
		cout << "2. Pop\n";
		cout << "3. Display Top Value\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: \n";
		cin >> option;

		switch (option) {
		case 1:
			cout << "Enter Value: ";
			cin >> value;
			if (obj.isFull()) {
				cout << "Stack Full\n";
				
				break;
			}

				obj.push(value);
				cout << "Value pushed on stack successfully." << endl;
				system("pause");
		
			break;
		case 2:
			if (obj.isEmpty()) {
				cout << "Stack Empty..." << endl;
				break;
			}
			else {
				cout << "Poped Value: " << obj.pop();
				system("pause");
			}
			break;
		case 3:
			if (obj.isEmpty()) {
				cout << "Stack Empty..." << endl;
				return 0;
			}
			else {
				cout << "Top Value: " << obj.peek();
				system("pause");
				break;
			}
		case 4:
			exit(0);
		}
	} while (option > 0 && option <= 4);

	return 0;
}