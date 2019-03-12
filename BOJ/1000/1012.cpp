#include <iostream>
#include <cstring>
using namespace	std;

int map[50][50];
bool visited[50][50];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
void init(int m, int n) {
	for (int i = 0; i < n; i++) {
		memset(map[i], 0, sizeof(int)*m);
		memset(visited[i], 0, sizeof(bool)*m);
	}
}

void dfs(int x, int y, int m, int n) {
	visited[y][x] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && nx < m&&ny >= 0 && ny < n&&map[ny][nx] == 1) {
			if (!visited[ny][nx]) {
				visited[ny][nx] = true;
				dfs(nx, ny, m, n);
			}
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int m, n, k;
		cin >> m >> n >> k;
		init(m, n);
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					dfs(j, i, m, n);
					ans += 1;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}