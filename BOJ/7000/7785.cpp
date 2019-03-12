#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	set<string> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name, what;
		cin >> name >> what;
		if (what == "enter") {
			s.insert(name);
		}
		else {
			s.erase(name);
		}
	}
	for (auto it = s.rbegin(); it != s.rend(); ++it) {
		cout << *it << '\n';
	}
	return 0;
}