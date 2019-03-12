#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int m;
	cin >> m;
	int d = 0;
	for (int i = 0; i < m; i++) {
		int n;
		cin >> n;
		d = d * a + n;
	}
	vector<int> v;

	while (d != 0) {
		v.push_back(d%b);
		d /= b;
	}
	reverse(v.begin(), v.end());
	for (int x : v) {
		cout << x << ' ';
	}
	return 0;
}