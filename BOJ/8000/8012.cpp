#define N		30001
#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[N];
int parent[20][N];
int depth[N];
int n, m;

void dfs(int cur, int par) {
	for (int &next : adj[cur]) {
		if (next == par) continue;
		parent[0][next] = cur;
		depth[next] = depth[cur] + 1;
		dfs(next, cur);
	}
}
int lca(int u, int v) {
	if (depth[u] > depth[v]) swap(u, v);
	for (int i = 19; i >= 0; --i) {
		int diff = depth[v] - depth[u];
		if (diff&(1 << i)) {
			v = parent[i][v];
		}
	}
	if (u == v) {
		return u;
	}
	for (int i = 19; i >= 0; --i) {
		if (parent[i][u] != parent[i][v]) {
			u = parent[i][u];
			v = parent[i][v];
		}
	}

	return parent[0][u];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);

	for (int i = 1; i <= 19; ++i) {
		for (int j = 1; j <= n; ++j) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}
	cin >> m;
	int from, to;
	cin >> from;
	int ans = 0;
	for (int i = 1; i < m; ++i) {
		cin >> to;
		ans+=depth[from]+depth[to]-2*depth[lca(from, to)];
		from = to;
	}
	cout << ans << '\n';
	return 0;
}