#define MAXN		1000000000
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m;
ll a[22];
ll ans;
void dfs(int idx, ll milk) {
	if (milk >= n) {
		if (milk == n) {
			cout << milk;
			exit(0);
		}
		if (ans == 0 || ans > milk) {
			ans = milk;
		}
		return;
	}

	for (int i = idx + 1; i < m; ++i) {
		dfs(i, milk + a[i]);
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
	}
	dfs(-1, 0);
	if (ans) cout << ans;
	else cout << "IMPOSSIBLE";
	return 0;
}