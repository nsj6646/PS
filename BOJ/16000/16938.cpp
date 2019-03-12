#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
int n, l, r, x;
int a[16];
int ans;
void dfs(int idx, int cnt, int &limit, ll sum, int easy, int hard) {
	if (cnt == limit) {
		if (sum >= l && sum <= r && hard - easy >= x) {
			ans++;
		}
		return;
	}
	for (int i = idx + 1; i < n; ++i) {
		dfs(i, cnt + 1, limit, sum + a[i], min(easy, a[i]), max(hard, a[i]));
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 2; i <= n; ++i) {
		dfs(-1, 0, i, 0LL, INF, 0);
	}
	cout << ans;
	return 0;
}