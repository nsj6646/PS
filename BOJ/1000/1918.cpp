#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isoperand(char c) {
	if (c >= 'A'&&c <= 'Z') {
		return true;
	}
	else {
		return false;
	}
}
int priority(char op) {
	switch (op)
	{
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	}
	return -1;
}
int main()
{
	string a, b;
	cin >> a;
	int n = a.length();
	stack<char> s, op;
	for (int i = 0; i < n; i++) {
		if (isoperand(a[i])) {
			b.push_back(a[i]);
		}
		else {
			if (op.empty()) {
				op.push(a[i]);
			}
			else {
				if (a[i] == '(') {
					op.push(a[i]);
				}
				else if (a[i] == ')') {
					while (op.top() != '(') {
						b.push_back(op.top());
						op.pop();
					}
					op.pop();
				}
				else {
					while (!op.empty() && priority(a[i]) <= priority(op.top())) {
						b.push_back(op.top());
						op.pop();
					}
					op.push(a[i]);
				}
			}
		}
	}
	while (!op.empty()) {
		b.push_back(op.top());
		op.pop();
	}
	cout << b;
	return 0;
}