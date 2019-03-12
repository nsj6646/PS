#define N		1005
#include <bits/stdc++.h>
using namespace std;

int psum[N][N];
bool visited[N][N];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n, m, h, w, sr, sc, fr, fc;
bool safe(int x, int y) {
	return (x >= 1 && x + h - 1 <= n && y >= 1 && y + w - 1 <= m);
}
bool wall(int x, int y) {
	return (psum[x + h - 1][y + w - 1] - psum[x + h - 1][y - 1] - psum[x - 1][y + w - 1] + psum[x - 1][y - 1]);
}
queue<tuple<int, int, int>> q;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int x;
			cin >> x;
			psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + x;
		}
	}

	cin >> h >> w >> sr >> sc >> fr >> fc;
	int ans = -1;
	visited[sr][sc] = true;
	q.push({ sr,sc,0 });
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int dist = get<2>(q.front());
		q.pop();
		if (x == fr && y == fc) {
			ans = dist;
			break;
		}
		for (int d = 0; d < 4; ++d) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (safe(nx, ny) && !visited[nx][ny] && !wall(nx, ny)) {
				visited[nx][ny] = true;
				q.push({ nx, ny, dist + 1 });
			}
		}
	}
	cout << ans;
	return 0;
}