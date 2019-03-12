#include <iostream>
#include <algorithm>
using namespace std;

int alpha[26];
int main()
{
	char c;
	int cnt = 0;
	while (cin >> c) {
		if (c == ' ' || c=='\n') {
			continue;
		}
		alpha[c - 'a'] += 1;
		cnt = max(alpha[c - 'a'], cnt);
	}
	for (int i = 0; i < 26; i++) {
		if (alpha[i] == cnt) {
			cout << (char)(i + 'a');
		}
	}
	return 0;
}