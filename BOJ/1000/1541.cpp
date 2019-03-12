#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	string str;
	cin >> str;
	queue<int> q;
	int num = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != '-' && str[i] != '+') {
			num = 10 * num + (str[i] - '0');
		}
		else {
			q.push(num);
			num = 0;
		}
	}
	q.push(num);
	int ans = q.front();
	q.pop();
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+') {
			ans += q.front();
			q.pop();
		}
		else if (str[i] == '-') {
			while (!q.empty()) {
				ans -= q.front();
				q.pop();
			}
			break;
		}
	}
	cout << ans;
	return 0;
}
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	string s;
	cin >> s;
	vector<int> num;
	vector<int> sign;
	bool minus = false;
	int cur = 0;
	sign.push_back(1);
	for (int i = 0; i<s.size(); i++) {
		if (s[i] == '+' || s[i] == '-') {
			if (s[i] == '+') {
				sign.push_back(1);
			}
			else {
				sign.push_back(-1);
			}
			num.push_back(cur);
			cur = 0;
		}
		else {
			cur = cur * 10 + (s[i] - '0');
		}
	}
	num.push_back(cur);
	int ans = 0;
	minus = false;
	for (int i = 0; i<num.size(); i++) {
		if (sign[i] == -1) {
			minus = true;
		}
		if (minus) {
			ans -= num[i];
		}
		else {
			ans += num[i];
		}
	}
	cout << ans << '\n';
	return 0;
}
*/