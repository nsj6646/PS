#include <bits/stdc++.h>
using namespace std;

bool alpha[26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	if (s == "zyxwvutsrqponmlkjihgfedcba") {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < s.size(); ++i) {
		alpha[s[i]-'a'] = true;
	}
	int len = s.size();
	string a(s);
	for (int i = len; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			if (!alpha[j]) {
				a.push_back('a'+j);
				alpha[j] = true;
				break;
			}
		}
	}
	if (len < 26) {
		for (int i = 0; i < len+1; ++i) {
			cout << a[i];
		}
	}
	else {
		next_permutation(a.begin(), a.end());
		for (int i = 0; i < 26; ++i) {
			if (s[i] == a[i]) {
				cout << a[i];
			}
			else {
				cout << a[i];
				break;
			}
		}
	}
	return 0;
}