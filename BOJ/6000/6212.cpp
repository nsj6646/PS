#include <bits/stdc++.h>
using namespace std;

int cnt[10];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = n; i <= m; ++i) {
		int k = i;
		while (k) {
			cnt[k % 10]++;
			k /= 10;
		}
	}
	for (int i = 0; i < 10; ++i) {
		cout << cnt[i] << ' ';
	}
	return 0;
}