#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100][100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	int ans = 2 * n*m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		int height = 0;
		int sum = 0;
		for (int j = 0; j < m; ++j) {
			if (a[i][j] - height > 0) {
				sum += a[i][j] - height;
			}
			height = a[i][j];
		}
		ans += sum * 2;
	}

	for (int i = 0; i < m; ++i) {
		int height = 0;
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			if (a[j][i] - height > 0) {
				sum += a[j][i] - height;
			}
			height = a[j][i];
		}
		ans += sum * 2;
	}
	cout << ans;
	return 0;
}