#define MAXN		2000
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;

int N, A[MAX], B[MAX];
bool visited[MAX];
vector<int> adj[MAX];

vector<int> odd;
vector<int> even;
vector<int> ans;

int a[MAXN];
int prime[MAXN] = { 1,1 };

bool dfs(int cur) {
	if (visited[cur]) return false;
	visited[cur] = true;

	for (auto &next : adj[cur]) {
		if (B[next] == -1 || dfs(B[next])) {
			B[next] = cur;
			A[cur] = next;
			return true;
		}
	}
	return false;
}
int solve(int flag) {
	int ret = 0;
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	if (flag) {
		for (int x : odd) {
			memset(visited, false, sizeof(visited));
			if (dfs(x)) ++ret;
		}
	}
	else {
		for (int x : even) {
			memset(visited, false, sizeof(visited));
			if (dfs(x)) ++ret;
		}
	}

	return ret;
}

void init() {
	for (int i = 2; i*i <= MAXN; ++i) {
		if (!prime[i]) {
			for (int j = i * i; j <= MAXN; j += i) {
				prime[j] = 1;
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	init();

	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		if (a[i] & 1) {
			odd.push_back(a[i]);
		}
		else {
			even.push_back(a[i]);
		}
	}

	if (a[0] & 1) {
		for (int i = 1; i < odd.size(); ++i) {
			int &x = odd[i];
			for (int &y : even) {
				if (!prime[x + y]) {
					adj[x].push_back(y);
				}
			}
		}

		int x = odd[0];
		for (int &y : even) {
			if (!prime[x + y]) {
				adj[x].push_back(y);
				int mf = solve(1);
				if (mf == N / 2) {
					ans.push_back(y);
				}
				adj[x].pop_back();
			}
		}
	}
	else {
		for (int i = 1; i < even.size(); ++i) {
			int &x = even[i];
			for (int &y : odd) {
				if (!prime[x + y]) {
					adj[x].push_back(y);
				}
			}
		}

		int x = even[0];
		for (int &y : odd) {
			if (!prime[x + y]) {
				adj[x].push_back(y);
				int mf = solve(0);
				if (mf == N / 2) {
					ans.push_back(y);
				}
				adj[x].pop_back();
			}
		}
	}

	if (ans.empty()) {
		cout << -1;
	}
	else {
		sort(ans.begin(), ans.end());
		for (int &x : ans) {
			cout << x << ' ';
		}
	}

	return 0;
}

//#define MAXN		2000
//#include <bits/stdc++.h>
//using namespace std;
//
//const int MAX = 1005;
//
//struct Edge {
//	int v, cap, rev;
//	Edge() {}
//	Edge(int v, int cap, int rev) : v(v), cap(cap), rev(rev) {}
//};
//int N, S, T, level[MAX], work[MAX];
//vector<Edge> adj[MAX];
//vector<int*> pcurcap;
//vector<int*> prevcap;
//bool bfs() {
//	memset(level, -1, sizeof(level));
//	queue<int> q;
//	q.push(S);  level[S] = 0;
//	while (!q.empty()) {
//		int cur = q.front();
//		q.pop();
//		for (auto &i : adj[cur]) {
//			int next = i.v;
//			int cap = i.cap;
//			if (cap > 0 && level[next] == -1) {
//				level[next] = level[cur] + 1;
//				q.push(next);
//			}
//		}
//	}
//	return level[T] != -1;
//}
//
//int dfs(int cur, int flow) {
//	if (cur == T)    return flow;
//	for (int &i = work[cur]; i < adj[cur].size(); i++) {
//		int next = adj[cur][i].v;
//		int cap = adj[cur][i].cap;
//		int rev = adj[cur][i].rev;
//		if (cap > 0 && level[next] == level[cur] + 1) {
//			int cf = dfs(next, min(flow, cap));
//			if (cf > 0) {
//				adj[cur][i].cap -= cf;
//				adj[next][rev].cap += cf;
//				pcurcap.push_back(&adj[cur][i].cap);
//				prevcap.push_back(&adj[next][rev].cap);
//
//				return cf;
//			}
//		}
//	}
//	return 0;
//}
//
//int solve() {
//	int ret = 0;
//	while (bfs()) {
//		memset(work, 0, sizeof(work));
//		while (true) {
//			int flow = dfs(S, 1e9);
//			if (flow == 0)break;
//			ret += flow;
//		}
//	}
//	return ret;
//}
//
//void addEdge(int u, int v, int cap) {
//	adj[u].emplace_back(v, cap, adj[v].size());
//	adj[v].emplace_back(u, 0, adj[u].size() - 1);
//}
//
//void backup(int u, int v) {
//	for (auto pcap : pcurcap) {
//		*pcap = 1;
//	}
//	pcurcap.clear();
//	for (auto pcap : prevcap) {
//		*pcap = 0;
//	}
//	prevcap.clear();
//	adj[u].pop_back();
//	adj[v].pop_back();
//}
//int a[MAXN];
//int prime[MAXN] = { 1,1 };
//
//void init() {
//	for (int i = 2; i*i <= MAXN; ++i) {
//		if (!prime[i]) {
//			for (int j = i * i; j <= MAXN; j += i) {
//				prime[j] = 1;
//			}
//		}
//	}
//}
//vector<int> odd;
//vector<int> even;
//vector<int> ans;
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> N;
//	init();
//	S = 0;
//	T = 1001;
//	for (int i = 0; i < N; ++i) {
//		cin >> a[i];
//		if (a[i] & 1) {
//			odd.push_back(a[i]);
//			if (a[0] & 1) {
//				addEdge(S, a[i], 1);
//			}
//			else {
//				addEdge(a[i], T, 1);
//			}
//		}
//		else {
//			even.push_back(a[i]);
//			if (a[0] & 1) {
//				addEdge(a[i], T, 1);
//			}
//			else {
//				addEdge(S, a[i], 1);
//			}
//		}
//	}
//
//
//	if (a[0] & 1) {
//		for (int i = 1; i<odd.size(); ++i) {
//			int &x = odd[i];
//			for (int &y : even) {
//				if (!prime[x + y]) {
//					addEdge(x, y, 1);
//				}
//			}
//		}
//		int x = odd[0];
//		for (int &y : even) {
//			if (!prime[x + y]) {
//				addEdge(x, y, 1);
//				int mf = solve();
//				if (mf == N / 2) {
//					ans.push_back(y);
//				}
//				backup(x, y);
//			}
//		}
//	}
//	else {
//		for (int i = 1; i<even.size(); ++i) {
//			int &x = even[i];
//			for (int &y : odd) {
//				if (!prime[x + y]) {
//					addEdge(x, y, 1);
//				}
//			}
//		}
//		int x = even[0];
//		for (int &y : odd) {
//			if (!prime[x + y]) {
//				addEdge(x, y, 1);
//				int mf = solve();
//
//				if (mf == N / 2) {
//					ans.push_back(y);
//				}
//				backup(x, y);
//			}
//		}
//	}
//
//
//	if (ans.empty()) {
//		cout << -1;
//	}
//	else {
//		sort(ans.begin(), ans.end());
//		for (int &x : ans) {
//			cout << x << ' ';
//		}
//	}
//
//
//	return 0;
//}
