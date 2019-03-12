#define INF 0x7fffffff
#include <bits/stdc++.h>
using namespace std;

int a[1001][1001];
bool visited[1001][1001][11];
int n, m, k;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool day = true;
struct point {
	int x, y, w, dist;
	point(int x, int y, int w,int d) :x(x), y(y), w(w),dist(d) {}
};
queue<point> q;

bool safe(int x, int y) {
	return (x > 0 && x <= n&&y > 0 && y <= m);
}
int ans = -1;

void bfs() {
	q.push({ 1,1,0,1 });
	visited[1][1][0] = true;

	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			point now = q.front();
			q.pop();

			int x = now.x;
			int y = now.y;
			int w = now.w;
			int dist = now.dist;

			if (x == n && y == m) {
				ans = dist;
				return;
			}
			for (int d = 0; d < 4; ++d) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				int ndist = dist + 1;

				if (safe(nx, ny)) {
					if (a[nx][ny] == 1 && w < k&&visited[nx][ny][w + 1] == 0) {
						if (day) {
							visited[nx][ny][w + 1] = true;
							q.push({ nx,ny,w + 1 ,ndist });
						}
						else {
							q.push({ x,y,w ,dist + 1 });
						}
					}
					else if (a[nx][ny] == 0 && visited[nx][ny][w] == 0) {
						visited[nx][ny][w] = true;
						q.push({ nx,ny,w,ndist });
					}
				}
			}
		}
		day = !day;
	}
}
int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%1d", &a[i][j]);
		}
	}

	bfs();

	printf("%d", ans);
	return 0;
}
