#include <bits/stdc++.h>
using namespace std;

int a[25];
int c, b;
int ans;
void dfs(int idx, int cal) {
	if (cal >= c) {
		if (cal == c) {
			cout << cal;
			exit(0);
		}
		return;
	}
	ans = max(ans, cal);

	for (int i = idx+1; i < b; ++i) {
		dfs(i, cal + a[i]);
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> b;
	for (int i = 0; i < b; ++i) {
		cin >> a[i];
	}
	dfs(-1,0);
	cout << ans;
	return 0;
}