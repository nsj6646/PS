#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<int>v1, v2;
	string a, b;
	cin >> a >> b;
	for (char x : a) {
		v1.push_back(x - '0');
	}
	for (char x : b) {
		v2.push_back(x - '0');
	}
	long long ans = 0;
	for (int x : v1) {
		for (int y : v2) {
			ans += x * y;
		}
	}
	cout << ans;
	return 0;
}