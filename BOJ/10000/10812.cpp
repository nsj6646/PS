#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = i+1;
	}
	
	while (m--) {
		int i, j, k;
		cin >> i >> j >> k;
		rotate(v.begin() + (i - 1), v.begin() + (k-1), v.begin() + j);
	}
	for (int x : v) {
		cout << x << ' ';
	}
	return 0;
}