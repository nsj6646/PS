#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		string s;
		cin >> s;
		string ans;
		if (s.back() == 'y'|| s.back() == 'Y') {
			ans = "nobody";
		}
		else if (s.back() == 'a' || s.back() == 'e' || s.back() == 'i' || s.back() == 'o' || s.back() == 'u'|| s.back() == 'A' || s.back() == 'E' || s.back() == 'I' || s.back() == 'O' || s.back() == 'U') {
			ans = "a queen";
		}
		else {
			ans = "a king";
		}
		cout << "Case #" << tc << ": " << s << " is ruled by " << ans << ".\n";
	}
	return 0;
}