#include <iostream>
#include <string>
using namespace std;

string ans[4];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	string str;
	cin >> n >> str;
	if (n == 1) {
		ans[1] = str;
		for (int i = 0; i < str.size(); i++) {
			if (i == 0) {
				ans[3].push_back(str[i] - ('a' - 'A'));
				ans[2].push_back(str[i]);
				continue;
			}
			if (str[i] >= 'A'&&str[i] <= 'Z') {
				ans[2].push_back('_');
				ans[2].push_back(str[i] + ('a' - 'A'));
				ans[3].push_back(str[i]);
			}
			else {
				ans[2].push_back(str[i]);
				ans[3].push_back(str[i]);
			}
		}
	}
	else if (n == 2) {
		ans[2] = str;
		for (int i = 0; i < str.size(); i++) {
			if (i == 0) {
				ans[3].push_back(str[i] - ('a' - 'A'));
				ans[1].push_back(str[i]);
				continue;
			}
			if (str[i]=='_') {
				ans[1].push_back(str[i+1] - ('a' - 'A'));
				ans[3].push_back(str[i+1] - ('a' - 'A'));
				i++;
				continue;
			}
			else {
				ans[1].push_back(str[i]);
				ans[3].push_back(str[i]);
			}
		}
	}
	else if (n == 3) {
		ans[3] = str;
		for (int i = 0; i < str.size(); i++) {
			if (i == 0) {
				ans[1].push_back(str[i] + ('a' - 'A'));
				ans[2].push_back(str[i] + ('a' - 'A'));
				continue;
			}
			if (str[i] >= 'A'&&str[i] <= 'Z') {
				ans[2].push_back('_');
				ans[2].push_back(str[i] + ('a' - 'A'));
				ans[1].push_back(str[i]);
			}
			else {
				ans[1].push_back(str[i]);
				ans[2].push_back(str[i]);
			}
		}
	}
	for (int i = 1; i <= 3; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}