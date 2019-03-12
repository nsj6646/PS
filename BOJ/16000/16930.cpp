#include <bits/stdc++.h>
using namespace std;
#define MAXN	1001
char a[MAXN][MAXN];
bool visited[MAXN][MAXN];

typedef pair<int, int> point;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, m, k;

queue<point> q;

bool safe(int x, int y) {
	return(x > 0 && x <= n && y > 0 && y <= m);
}

int bfs(int x1, int y1, int x2, int y2) {
	visited[x1][y1] = true;
	q.push({ x1,y1 });
	int res = 0;
	while (!q.empty()) {
		int sz = q.size();
		res += 1;
		while (sz--) {
			point now = q.front();
			int x = now.first;
			int y = now.second;
			q.pop();

			if (x == x2 && y == y2) {
				return res - 1;
			}

			for (int d = 0; d < 4; ++d) {
				int nx = x;
				int ny = y;
				for (int i = 1; i <= k; ++i) {
					nx += dx[d];
					ny += dy[d];
					if (safe(nx, ny) && a[nx][ny] == '.') {
						if (!visited[nx][ny]) {
							visited[nx][ny] = true;
							q.push({ nx,ny });
						}
					}
					else {
						break;
					}
				}
			}
		}
	}

	return -1;
}

int main()
{
	freopen("in.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << bfs(x1, y1, x2, y2);
	return 0;
}