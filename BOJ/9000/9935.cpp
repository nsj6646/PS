#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool erased[1000001];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string a, b;
	cin >> a >> b;
	int n = a.size();
	int m = b.size();
	if (m == 1) {
		bool printed = false;
		for (char c : a) {
			if (c != b[0]) {
				printed = true;
				cout << c;
			}
		}
		if (!printed) {
			cout << "FRULA";
		}
		return 0;
	}
	else {
		stack<pair<int, int>> s;
		for (int i = 0; i < n; i++) {
			if (a[i] == b[0]) {
				s.push({ i,0 });
			}
			else {
				if (!s.empty()) {
					auto p = s.top();
					if (a[i] == b[p.second + 1]) {
						s.push({ i, p.second + 1 });
						if (p.second + 1 == m - 1) {
							for (int k = 0; k < m; k++) {
								auto p = s.top();
								erased[p.first] = true;
								s.pop();
							}
						}
					}
					else {
						while (!s.empty()) {
							s.pop();
						}
					}
				}
			}
		}
	}
	bool printed = false;
	for (int i = 0; i < n; i++) {
		if (erased[i]) continue;
		cout << a[i];
		printed = true;
	}
	if (!printed) {
		cout << "FRULA";
	}
	return 0;
}