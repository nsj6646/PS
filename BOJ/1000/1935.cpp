#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
using namespace std;

int a[26];

double calc(double x, double y, char oper) {
	switch (oper) {
	case '+': return x + y;
	case '-': return x - y;
	case '*': return x * y;
	case '/': return x / y;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string input;
	cin >> input;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	stack<double> stk;
	for (char c : input) {
		if (c >= 'A'&&c <= 'Z') {
			stk.push(a[c - 'A']);
		}
		else {
			double op2 = stk.top(); stk.pop();
			double op1 = stk.top(); stk.pop();
			stk.push(calc(op1, op2, c));
		}
	}
	cout << fixed << setprecision(2) << stk.top();

	return 0;
}