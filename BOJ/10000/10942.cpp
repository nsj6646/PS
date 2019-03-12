#include <iostream>
using namespace std;

int a[2001];
int d[2001][2001];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i][i] = 1;
		if (i > 1) {
			if (a[i] == a[i - 1]) {
				d[i - 1][i] = 1;
			}
		}
	}
	for (int k = 3; k <= n; k++) {
		for (int i = 1; i <= n - k + 1; i++) {
			int j = i + k - 1;
			if (a[i] == a[j] && d[i + 1][j - 1]) {
				d[i][j] = 1;
			}
		 }
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		cout << d[s][e] << '\n';
	}

	return 0;
}