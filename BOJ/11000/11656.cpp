#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int n = str.size();
	vector<string> v(n);

	for (int i = 0; i < n; i++) {
		v[i] = str.substr(i);
	}
	sort(v.begin(), v.end());
	for (string x : v) {
		cout << x << '\n';
	}
	return 0;
}