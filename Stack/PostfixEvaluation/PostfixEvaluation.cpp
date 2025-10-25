#include<iostream>
#include<string>
#include<math.h>
#include"Stack.h"
using namespace std;

double evaluateExpression(string exp);

int main() {
	string exp;

	cout << "Enter your Expression: ";
	cin >> exp;

	cout << "Expression Result: " << evaluateExpression(exp) << endl;

	return 0;
}

double evaluateExpression(string exp) {

	Stack myStack(exp.size());

	for (int i = 0; i < exp.size(); i++) {
		if (exp[i] >= '0' && exp[i] <= '9') {
			myStack.push(exp[i] - '0');
		}
		else {
			int op2 = myStack.Top();	
			myStack.pop();
			int op1 = myStack.Top();	
			myStack.pop();

			switch (exp[i]) {
			case '+':
				myStack.push(op1 + op2);
				break;
			case '-':
				myStack.push(op1 - op2);
				break;
			case '*':
				myStack.push(op1 * op2);
				break;
			case '/':
				myStack.push(op1 / op2);
				break;
			case '^':
				myStack.push(pow(op1,op2));
				break;
			}

		}

	}

	return myStack.Top();
}