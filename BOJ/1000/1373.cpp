#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	string str;
	cin >> str;
	int n = str.size();
	if (n % 3 == 1) {
		cout << str[0];
	}
	else if (n % 3 == 2) {
		cout << (str[0] - '0') * 2 + str[1] - '0';
	}
	for (int i = n % 3; i < n; i += 3) {
		cout << (str[i] - '0') * 4 + (str[i + 1] - '0') * 2 + (str[i + 2] - '0');
	}
	return 0;
}
/*
#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int n = s.size();
	if (n % 3 == 1) {
		cout << s[0];
	}
	else if (n % 3 == 2) {
		cout << (s[0] - '0') * 2 + (s[1] - '0');
	}
	for (int i = n % 3; i<n; i += 3) {
		cout << (s[i] - '0') * 4 + (s[i + 1] - '0') * 2 + (s[i + 2] - '0');
	}
	cout << '\n';
	return 0;
}
*/