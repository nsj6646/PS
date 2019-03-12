#include <iostream>
using namespace std;

int a[101];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int l = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		for (int j = l; j < l + x; j++) {
			a[j] = y;
		}
		l += x;
	}

	l = 0;
	int ans = 0;
	for (int j = 0; j < m; j++) {
		int x, y;
		cin >> x >> y;
		for (int j = l; j < l + x; j++) {
			if (y - a[j] >= 0)
				if (y - a[j] > ans) {
					ans = y - a[j];
				}
		}
		l +=x;
	}

	cout << ans;
	return 0;
}