#include <iostream>
#include <string>
using namespace std;

int counting[10];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string n;
	cin >> n;

	int sum = 0;
	for (int i = 0; i < n.size(); i++) {
		int x = n[i] - '0';
		counting[x]++;
		sum += x;
	}

	if (counting[0]!=0&&sum % 3 == 0) {
		for (int i = 9; i >= 0; i--) {
			while (counting[i] != 0) {
				cout << i;
				counting[i]--;
			}
		}
	}
	else {
		cout << -1;
	}
	return 0;
}
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//bool cmp(const char &u, const char &v) {
//	return u > v;
//}
//int main()
//{
//	string n;
//	cin >> n;
//
//	int sum = 0;
//	bool iszero = false;
//	for (int i = 0; i < n.size(); i++) {
//		if (n[i] == '0') {
//			iszero = true;
//		}
//		sum += (int)(n[i] - '0');
//	}
//	if (iszero&&sum % 3 == 0) {
//		sort(n.begin(), n.end(), cmp);
//		cout << n;
//	}
//	else {
//		cout << -1;
//	}
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	string s;
//	cin >> s;
//	int sum = 0;
//	for (char c : s) {
//		sum += c - '0';
//	}
//	sort(s.begin(), s.end());
//	if (s[0] == '0'&&sum % 3 == 0) {
//		reverse(s.begin(), s.end());
//		cout << s << '\n';
//	}
//	else {
//		cout << "-1\n";
//	}
//	return 0;
//}