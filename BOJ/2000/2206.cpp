#include <cstdio>
#include <queue>
using namespace std;

struct info {
	int x, y;
	int dst;
	int cnt;
	info(int x, int y, int d, int c) :x(x), y(y), dst(d), cnt(c) {}
};
int a[1000][1000];
int visited[2][1000][1000];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, m;
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	
	int ans = -1;
	info si = { 0,0,1,0 };
	visited[0][0][0] = 1;
	queue<info> q;
	q.push(si);
	while (!q.empty()) {
		info now = q.front();
		int d = now.dst;
		int x = now.x;
		int y = now.y;
		int cnt = now.cnt;
		q.pop();
		if (x == n - 1 && y == m - 1) {
			ans = d;
			break;
		}
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			int nd = d + 1;
			if (nx >= 0 && nx < n&&ny >= 0&&ny < m) {
				if (a[nx][ny] == 0 && visited[cnt][nx][ny] == 0) {
					info ni = { nx,ny,nd,cnt };
					visited[cnt][nx][ny] = 1;
					q.push(ni);
				}
				else if (a[nx][ny] == 1 && cnt == 0) {
					visited[1][nx][ny] = 1;
					info ni = { nx,ny,nd,1 };
					q.push(ni);
				}
			}
		}
	}
	printf("%d",ans);

	return 0;
}