#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n>> m;
	vector<int> a(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		fill(a.begin() + x, a.begin() + y+1, z);
	}
	for (int i = 1; i <= n;i++) {
		cout << a[i] << ' ';
	}

	return 0;
}