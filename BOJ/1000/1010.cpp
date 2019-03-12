#include <iostream>
using namespace std;

int combi[31][31];

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;

	for (int i = 1; i <= 30; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				combi[i][j] = 1;
				continue;
			}
			combi[i][j] = combi[i - 1][j] + combi[i - 1][j - 1];
		}
	}

	for (int tc = 1; tc <= T; tc++) {
		int n, m;
		cin >> n >> m;
		cout << combi[m][n] << '\n';
	}

	return 0;
}