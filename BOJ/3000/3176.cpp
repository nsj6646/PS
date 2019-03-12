//#define N		100001
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//
//
//int n, k;
//int parent[20][N];
//int depth[N];
//long long dist[N];
//vector<pair<int,int>> adj[N];
//
//void dfs(int cur, int par, int w) {
//	for (auto &next : adj[cur]) {
//		if (next.first == par) continue;
//		parent[0][next.first] = cur;
//		depth[next.first] = depth[cur] + 1;
//		dist[next.first] = w+next.second;
//		dfs(next.first, cur, w + next.second);
//	}
//}
//
//int lca(int u, int v) {
//	if (depth[u] > depth[v]) swap(u, v);
//	for (int i = 19; i >= 0; --i) {
//		int diff = depth[v] - depth[u];
//		if (diff&(1 << i)) {
//			v = parent[i][v];
//		}
//	}
//	if (u == v) return u;
//	for (int i = 19; i >= 0; --i) {
//		if (parent[i][u] != parent[i][v]) {
//			u = parent[i][u];
//			v = parent[i][v];
//		}
//	}
//
//	return parent[0][u];
//}
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> n;
//	for (int i = 0; i < n - 1; ++i) {
//		int a, b, c;
//		cin >> a >> b >> c;
//		adj[a].push_back({ b,c });
//		adj[b].push_back({ a,c });
//	}
//	dfs(1, 0, 0);
//
//	for (int i = 1; i < 19; ++i) {
//		for (int j = 1; j <= n; ++j) {
//			parent[i][j] = parent[i - 1][parent[i - 1][j]];
//		}
//	}
//	cin >> k;
//	for (int i = 0; i < k; ++i) {
//		int d, e;
//		cin >> d >> e;
//		int mid = lca(d, e);
//		long long dd;
//		long long de;
//		if(d==1){
//			dd=
//		}
//		dd = dist[d] - dist[mid];
//		de = dist[e] - dist[mid];
//		cout << min(dd,de) << ' ' << max(dd, de) << '\n';
//	}
//
//	return 0;
//}