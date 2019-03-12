#define N		40001
#define IO_OPTIMIZE(X) 	ios::sync_with_stdio(X);cin.tie(X); cout.tie(X);

#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> node;
vector<node> adj[N];
int parent[23][N];
int depth[N];
int dist[N];

int n, m;

void dfs(int cur, int par,int d) {
	for (auto &next : adj[cur]) {
		if (next.first == par)continue;
		parent[0][next.first] = cur;
		dist[next.first] = d+next.second;
		depth[next.first] = depth[cur] + 1;
		dfs(next.first, cur,d+next.second);
	}
}

int lca(int u, int v) {
	int ret = 0;
	if (depth[u] > depth[v]) swap(u, v);
	for (int i = 22; i >= 0; --i) {
		int diff = depth[v] - depth[u];
		if (diff&(1 << i)) {
			v = parent[i][v];
		}
	}
	if (u == v) {
		return u;
	}

	for (int i = 22; i >= 0; --i) {
		if (parent[i][u]!=parent[i][v]) {
			u = parent[i][u];
			v = parent[i][v];	
		}
	}

	return parent[0][u];
}
int main()
{
	IO_OPTIMIZE(0);

	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
	}
	dfs(1, 0,0);
	for (int i = 1; i < 23; ++i) {
		for (int j = 1; j <= n; ++j) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}

	
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		
		cout << dist[u]+dist[v]-2*dist[lca(u, v)] << '\n';
	}
	return 0;
}
//#include <algorithm>
//#include <cstdio>
//#include <vector>
//#include <queue>
//#define N 40001
//#define M 10001
//using namespace std;
//
//struct edge {
//	int to, cost;
//	edge(int to, int cost) : to(to), cost(cost) {}
//};
//int parent[N];
//int depth[N];
//bool visited[N];
//int dist[N];
//vector<edge> a[N];
//
//int n, m;
//int lca(int u, int v) {
//	if (depth[u] < depth[v]) {
//		swap(u, v);
//	}
//	while (depth[u] != depth[v]) {
//		u = parent[u];
//	}
//	while (u != v) {
//		u = parent[u];
//		v = parent[v];
//	}
//	return u;
//}
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 0; i < n - 1; i++) {
//		int u, v, w;
//		scanf("%d %d %d", &u, &v, &w);
//		a[u].push_back({ v,w });
//		a[v].push_back({ u,w });
//	}
//
//	parent[1] = 0;
//	depth[1] = 0;
//	visited[1] = true;
//	queue<int> q;
//	q.push(1);
//	while (!q.empty()) {
//		int x = q.front();
//		q.pop();
//		for (edge &e : a[x]) {
//			int y = e.to;
//			if (!visited[y]) {
//				depth[y] = x + 1;
//				parent[y] = x;
//				dist[y] = dist[x]+e.cost;
//				visited[y] = true;
//				q.push(y);
//			}
//		}
//	}
//	int m;
//	scanf("%d", &m);
//	for (int i = 0; i < m; i++) {
//		int u, v;
//		scanf("%d %d", &u, &v);
//		printf("%d\n", dist[u] + dist[v] - 2 * dist[lca(u, v)]);
//	}
//	return 0;
//}