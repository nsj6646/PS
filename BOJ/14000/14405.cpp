#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (s.substr(i, 2)=="pi") {
			i += 1;
		}
		else if (s.substr(i, 2) == "ka"){
			i += 1;
		}
		else if (s.substr(i, 3) == "chu") {
			i += 2;
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}