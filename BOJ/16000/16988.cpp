#define MAXN		20
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> point;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n, m;
int a[MAXN][MAXN];
bool visited[MAXN][MAXN];
vector<point> blank;
queue<point> q;
set<point> s;

bool safe(int x, int y) {
	return x >= 0 && x < n&&y >= 0 && y < m;
}

int bfs(int i, int j) {
	bool sur = true;
	int cnt = 1;
	q.push({ i,j });
	visited[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (safe(nx, ny) && a[nx][ny] != 1 && !visited[nx][ny]) {
				if (a[nx][ny] == 0) {
					sur = false;
				}
				else if (a[nx][ny] == 2) {
					q.push({ nx,ny });
					visited[nx][ny] = 1;
					cnt++;

				}
			}
		}
	}
	return sur ? cnt : 0;
}

int ans;

void dfs(int idx, int cnt) {
	if (cnt == 2) {
		int cnt = 0;
		memset(visited, 0, sizeof(visited));
		for (point p : s) {
			int x = p.first;
			int y = p.second;
			if (!visited[x][y]) {
				cnt += bfs(x, y);
			}
		}
		ans = max(ans, cnt);
		return;
	}

	for (int i = idx; i < blank.size(); ++i) {
		int x = blank[i].first;
		int y = blank[i].second;
		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (safe(nx, ny) && a[nx][ny] == 2) {
				s.insert({ nx,ny });
			}
		}
		a[x][y] = 1;
		dfs(i + 1, cnt + 1);
		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (safe(nx, ny) && a[nx][ny] == 2) {
				s.erase({ nx,ny });
			}
		}
		a[x][y] = 0;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 0) {
				blank.emplace_back(i, j);
			}
		}
	}

	dfs(0, 0);
	cout << ans;

	return 0;
}