#include <bits/stdc++.h>
using namespace std;

const int MAX = 2*100 * 100 + 5;
const int INF = 1e9;
struct Edge {
	int v, cap, rev;
	Edge() {}
	Edge(int v, int cap, int rev) : v(v), cap(cap), rev(rev) {}
};
int N, M, S, T, level[MAX], work[MAX];
vector<Edge> adj[MAX];

bool bfs() {
	memset(level, -1, sizeof(level));
	queue<int> q;
	q.push(S);  level[S] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto &i : adj[cur]) {
			int next = i.v;
			int cap = i.cap;
			if (cap > 0 && level[next] == -1) {
				level[next] = level[cur] + 1;
				q.push(next);
			}
		}
	}
	return level[T] != -1;
}

int dfs(int cur, int flow) {
	if (cur == T)    return flow;
	for (int &i = work[cur]; i < adj[cur].size(); i++) {
		int next = adj[cur][i].v;
		int cap = adj[cur][i].cap;
		int rev = adj[cur][i].rev;
		if (cap > 0 && level[next] == level[cur] + 1) {
			int cf = dfs(next, min(flow, cap));
			if (cf > 0) {
				adj[cur][i].cap -= cf;
				adj[next][rev].cap += cf;
				return cf;
			}
		}
	}
	return 0;
}

int solve() {
	int ret = 0;
	while (bfs()) {
		memset(work, 0, sizeof(work));
		while (true) {
			int flow = dfs(S, 1e9);
			if (flow == 0)break;
			ret += flow;
		}
	}
	return ret;
}

void addEdge(int u, int v, int cap) {
	adj[u].emplace_back(v, cap, adj[v].size());
	adj[v].emplace_back(u, 0, adj[u].size() - 1);
}

char a[100][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool safe(int x, int y) {
	return (x >= 0 && x < M&&y >= 0 && y < N);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int s = (i * M + j) * 2;
			int e = (i * M + j) * 2 + 1;
			if (a[i][j] == 'K') {
				S = s;
				addEdge(S, e, INF);
			}
			else if (a[i][j] == 'H') {
				T = e;
				addEdge(s, T, INF);
			}
			else if(a[i][j]=='#'){
				continue;
			}
			else {
				addEdge(s, e, 1);
			}
			for (int k = 0; k < 4; ++k) {
				int nx = j + dx[k];
				int ny = i + dy[k];
				if (safe(nx, ny) && a[ny][nx] != '#') {
					int ns = (ny*M + nx) * 2;
					addEdge(e, ns, INF);
				}
			}
		}
	}
	int ans = solve();
	if (ans == INF) {
		cout << -1;
	}
	else {
		cout << ans;
	}
	return 0;
}