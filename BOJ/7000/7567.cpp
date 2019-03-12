#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int n = str.size();
	int ans = 10;
	for (int i = 1; i < n; i++) {
		if (str[i - 1] == str[i]) {
			ans += 5;
		}
		else {
			ans += 10;
		}
	}
	cout << ans;

	return 0;
}