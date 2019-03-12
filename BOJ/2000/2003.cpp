#include <bits/stdc++.h>
using namespace std;

int a[10005];
int n, m;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int l = 0, sum = 0, ans = 0;
	for (int r = 0; r < n; ++r) {
		sum += a[r];
		while (sum >= m && l <= r) {
			if (sum == m) {
				ans += 1;
			}
			sum -= a[l++];
		}
	}
	cout << ans;
	return 0;
}