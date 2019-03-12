#include <bits/stdc++.h>
using namespace std;

char a[50][50];
bool visited[50][50];
int n, m;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

bool safe(int x, int y) {
	return (x >= 0 && x < n&&y >= 0 && y < m);
}
int sx, sy;
void dfs(int x, int y, char color, int cnt) {
	if (cnt >= 4 && x == sx && y == sy) {
		cout << "Yes";
		exit(0);
	}
	for (int k = 0; k < 4; ++k) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (safe(nx, ny) && !visited[nx][ny] && a[nx][ny] == color) {
			visited[nx][ny] = true;
			dfs(nx, ny, color, cnt + 1);
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			sx = i, sy = j;
			memset(visited, 0, sizeof(visited));
			dfs(i, j, a[i][j], 1);
		}
	}
	cout << "No";


	return 0;
}