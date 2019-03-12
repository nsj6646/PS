#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define N 50001
#define M 10001
using namespace std;

int n,m;
vector<int> a[N];
int depth[N];
bool visited[N];
int parent[N];
int lca(int u,int v) {
	if (depth[u] < depth[v]) {
		swap(u, v);
	}
	while (depth[u] != depth[v]) {
		u = parent[u];
	}
	while (u != v) {
		u = parent[u];
		v = parent[v];
	}
	return u;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	
	for (int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	/*bfs*/
	depth[1] = 0;
	parent[1] = 0;
	visited[1] = true;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int y : a[x]) {
			if (!visited[y]) {
				depth[y] = depth[x] + 1;
				visited[y] = true;
				q.push(y);
				parent[y] = x;
			}
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << '\n';
	}
	return 0;
}