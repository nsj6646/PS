#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<char> op;
	stack<int> s;

	int idx = 1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (s.empty()) {
			op.push_back('+');
			s.push(idx++);
		}
		if (s.top()<x) {
			while(s.top()!=x){
				op.push_back('+');
				s.push(idx++);
			}
			op.push_back('-');
			s.pop();
		}
		else {
			if (x == s.top()) {
				op.push_back('-');
				s.pop();
			}
			else {
				cout << "NO";
				return 0;
			}
		}
	}
	for (char c : op) {
		cout << c << '\n';
	}
	return 0;
}