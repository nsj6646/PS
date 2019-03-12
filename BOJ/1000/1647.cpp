#define N	100001
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, pair<int, int>>> adj;
int parent[N];

int n, m;

int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = find(parent[x]);
}
bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		return false;
	}
	else {
		parent[y] = x;
		return true;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj.push_back({ w,{ u,v } });
	}
	sort(adj.begin(), adj.end());
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
	}
	int cnt = 0;
	int idx = 0;
	int ans = 0;
	while (cnt != n - 2) {
		if (merge(adj[idx].second.first, adj[idx].second.second)) {
			++cnt;
			ans += adj[idx].first;
		}
		++idx;
	}
	cout << ans;
	return 0;
}