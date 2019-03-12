#include <iostream>
using namespace std;

long long a[16][16];
int main()
{

	int n, m, k;
	cin >> n >> m >> k;
	if (k == 0) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i == 1 || j == 1) {
					a[i][j] = 1;
				}
				else {
					a[i][j] = a[i - 1][j] + a[i][j - 1];
				}
			}
		}
	}
	else {
		int x = (k - 1) % m + 1;
		int y = (k - 1) / m + 1;
		for (int i = 1; i <= y; i++) {
			for (int j = 1; j <= x; j++) {
				if (i == 1 || j == 1) {
					a[i][j] = 1;
				}
				else {
					a[i][j] = a[i - 1][j] + a[i][j - 1];
				}
			}
		}
		for (int i = y; i <= n; i++) {
			for (int j = x; j <= m; j++) {
				if (i == y || j == x) {
					a[i][j] = a[y][x];
				}
				else {
					a[i][j] = a[i - 1][j] + a[i][j - 1];
				}
			}
		}
	}
	cout << a[n][m];
	return 0;
}