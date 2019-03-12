#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int n = str.size();
	stack<int> s;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == '(') {
			s.push(i);
		}
		else {
			if (s.top() + 1 == i) {
				s.pop();
				sum += s.size();
			}
			else {
				s.pop();
				sum += 1;
			}
		}
	}
	cout << sum;
	return 0;
}