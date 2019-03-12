#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int w[11][11];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> w[i][j];
			if (w[i][j] == 0) {
				w[i][j] = 10000001;
			}
		}
	}
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = i + 1;
	}
	long long ans = 10000000LL;
	do {
		long long sum = 0;
		for (int i = 0; i < n - 1; i++) {
			sum += w[v[i]][v[i + 1]];
		}
		sum += w[v[n - 1]][v[0]];
		ans = min(ans, sum);
	} while (next_permutation(v.begin() + 1, v.end()));
	cout << ans;
	return 0;
}