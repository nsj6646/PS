#include <iostream>
#include <algorithm>
using namespace std;

int a[1001][1001];
long long d[1001][1001];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	d[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == 0) {
				continue;
			}

			int ny = j + a[i][j];
			if (ny <= n) {
				d[i][ny] += d[i][j];
			}

			int nx = i + a[i][j];
			if (nx <= n) {
				d[nx][j] += d[i][j];
			}
		}
	}
	cout << '\n';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << d[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << d[n][n];
	return 0;
}