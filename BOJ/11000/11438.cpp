#define N		100001
#include <iostream>
#include <vector>
using namespace std;

int n, m;

vector<int> adj[N];
int parent[20][N];
int depth[N];

void dfs(int cur, int par) {
	for (auto &next : adj[cur]) {
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
	if (u == v) return u;
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
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);

	for (int i = 1; i < 19; ++i) {
		for (int j = 1; j <= n; ++j) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << '\n';
	}
	return 0;
}

//#include <iostream>
//#include <cstring>
//#include <queue>
//#define N 10
//
//using namespace std;
//typedef pair<int, int> point;
//typedef pair<char, point> info;
//int n, m;
//char a[N][N];
//char save[N][N];
//int dx[] = { -1,0,1,0 };
//int dy[] = { 0,1,0,-1 };
//int ans = -1;
//bool bf = false;
//vector<int> dir;
//bool safe(int x, int y) {
//	return ((x >= 1 && x < n - 1 && y >= 1 && y < m - 1) && ((save[x][y] == '.') || save[x][y] == 'O'));
//}
//bool move(queue<info> &q, int d) {
//	bool r = false;
//	bool b = false;
//	while (!q.empty()) {
//		info now = q.front();
//		q.pop();
//		char data = now.first;
//		int x = now.second.first;
//		int y = now.second.second;
//		int nx = x + dx[d];
//		int ny = y + dy[d];
//		bool escape = false;
//		while (safe(nx, ny)) {
//			if (a[nx][ny] == 'O') {
//				if (data == 'R') {
//					r = true;
//				}
//				else if (data == 'B') {
//					b = true;
//				}
//				escape = true;
//				break;
//			}
//			x = nx;
//			y = ny;
//			nx = x + dx[d];
//			ny = y + dy[d];
//		}
//		if (!escape) {
//			save[x][y] = data;
//		}
//	}
//	if (!r&&b) {
//		bf = true;
//	}
//	return (r && !b);
//}
//bool go(int d) {
//	bool goal = false;
//	queue<info> q;
//	int total = 2;
//	if (d == 0) {
//		for (int j = 1; j < m - 1; j++) {
//			if (total == 0) {
//				break;
//			}
//			for (int i = 1; i < n - 1; i++) {
//				if (save[i][j] == 'R' || save[i][j] == 'B') {
//					total -= 1;
//					q.push({ save[i][j],{ i,j } });
//					save[i][j] = '.';
//				}
//			}
//			if (!q.empty() && !goal) {
//				goal = move(q, d);
//			}
//		}
//	}
//	else if (d == 1) {
//		for (int i = 1; i <n - 1; i++) {
//			if (total == 0) {
//				break;
//			}
//			for (int j = m - 2; j >= 1; j--) {
//				if (save[i][j] == 'R' || save[i][j] == 'B') {
//					total -= 1;
//					q.push({ save[i][j],{ i,j } });
//					save[i][j] = '.';
//				}
//			}
//			if (!q.empty() && !goal) {
//				goal = move(q, d);
//			}
//		}
//	}
//	else if (d == 2) {
//		for (int j = 1; j < m - 1; j++) {
//			if (total == 0) {
//				break;
//			}
//			for (int i = n - 2; i >= 1; i--) {
//				if (save[i][j] == 'R' || save[i][j] == 'B') {
//					total -= 1;
//					q.push({ save[i][j],{ i,j } });
//					save[i][j] = '.';
//				}
//			}
//			if (!q.empty() && !goal) {
//				goal = move(q, d);
//			}
//		}
//	}
//	else if (d == 3) {
//		for (int i = 1; i <n - 1; i++) {
//			if (total == 0) {
//				break;
//			}
//			for (int j = 1; j <m - 1; j++) {
//				if (save[i][j] == 'R' || save[i][j] == 'B') {
//					total -= 1;
//					q.push({ save[i][j],{ i,j } });
//					save[i][j] = '.';
//				}
//			}
//			if (!q.empty() && !goal) {
//				goal = move(q, d);
//			}
//		}
//	}
//	return goal;
//}
//void dfs(int cnt) {
//	if (cnt == 10) {
//		memcpy(save, a, sizeof(a));
//		bf = false;
//
//		for (int i = 0; i < dir.size(); i++) {
//			if (bf) {
//				break;
//			}
//			if (go(dir[i])) {
//				int t = i + 1;
//				if (ans == -1 || ans > t) {
//					ans = t;
//				}
//				return;
//			}
//
//		}
//		return;
//	}
//	for (int i = 0; i < 4; i++) {
//		if (!dir.empty() && (i == dir.back())) {
//			continue;
//		}
//		dir.push_back(i);
//		dfs(cnt + 1);
//		dir.pop_back();
//	}
//}
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> a[i][j];
//		}
//	}
//
//	dfs(0);
//	cout << ans;
//
//	return 0;
//}