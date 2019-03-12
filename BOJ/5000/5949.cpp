#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int i = 0;
	if (s.size() % 3) {
		for (i = 0; i < s.size() % 3; ++i) {
			cout << s[i];
		}
		if(s.size()>3) cout << ',';
	}
	for (int j=0; i < s.size(); ++i) {
		if (j&&(j % 3 == 0)) {
			cout << ',';
		}
		cout << s[i];
		++j;
	}
	return 0;
}