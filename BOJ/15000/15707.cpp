#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAX_LL = (1ll << 63) - 1ll;

string limit;
string str1, str2;
ll a, b, r;
bool is_zero(string s) {
	return (s == "0");
}
bool is_exceed(string s) {
	if (s.size() == 19) {
		return s > limit;
	}
	return s.size() > 19;
}
int main()
{
	cin >> str1 >> str2 >> r;
	limit = to_string(MAX_LL);
	if (is_zero(str1) || is_zero(str2)) {
		cout << 0;
	}
	else if (is_exceed(str1) || is_exceed(str2)) {
		cout << "overflow";
	}
	else {
		a = stoll(str1);
		b = stoll(str2);
		if (a > (r / b)) {
			cout << "overflow";
		}
		else {
			cout << a * b;
		}
	}
	return 0;
}