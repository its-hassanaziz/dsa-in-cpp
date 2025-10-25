#include<iostream>
#include<string>
#include<math.h>
#include"Stack.h"
using namespace std;

string convertExpression(string exp);
int precedence(char op) {
	if (op == '^')
		return 3;
	else if (op == '/' || op == '*')
		return 2;
	else if (op == '+' || op == '-')
		return 1;
	else
		return -1;
}

int main() {
	string exp;

	cout << "Enter your Expression: ";
	cin >> exp;
	cout << "Expression Result: " << convertExpression(exp) << endl;

	return 0;
}

string convertExpression(string exp) {

	string result;
	Stack myStack(exp.size());

	for (int i = 0; i < exp.size(); i++) {
		if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z')) {
			result += exp[i];
		}
		else if (exp[i] == '(') {
			myStack.push(exp[i]);
		}
		else if (exp[i] == ')') {
			while (myStack.isEmpty() || myStack.Top() != '(') {
				result += myStack.Top();
				myStack.pop();
			}
		}
		else {

		}


	}

	return result;
}