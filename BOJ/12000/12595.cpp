#include <bits/stdc++.h>
using namespace std;

set<int> s;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		s.clear();
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			int c;
			cin >> c;
			if (s.count(c) == 0) {
				s.insert(c);
			}
			else {
				s.erase(c);
			}
		}
		cout << "Case #" << tc << ": " << *s.begin() << '\n';
	}
	return 0;
}