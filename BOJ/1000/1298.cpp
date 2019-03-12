#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 205;
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


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; ++i) {
		int a, b;
		cin >> a >> b;
		addEdge(a, N + b, 1);
	}
	S = 0;
	T = N + N + 1;
	for (int i = 1; i <= N; ++i) {
		addEdge(S, i, 1);
	}
	for (int i = 1; i <= N; ++i) {
		addEdge(N + i, T, 1);
	}
	cout << solve();
	return 0;
}