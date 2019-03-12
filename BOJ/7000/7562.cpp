#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> point;
int dx[] = { -1,-2,-2,-1,1,2,2,1 };
int dy[] = { -2,-1,1,2,-2,-1,1,2 };
int a[300][300];
int visited[300][300];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		memset(visited, -1, sizeof(visited));
		int n;
		cin >> n;
		int sx, sy, gx, gy;
		cin >> sx >> sy >> gx >> gy;
		queue<point> q;
		q.push({ sx,sy });
		visited[sx][sy] = 0;
		int ans=-1;
		while (!q.empty()) {
			point now = q.front();
			int x = now.first;
			int y = now.second;
			int z = visited[x][y];
			if (x == gx && y == gy) {
				ans = z;
				break;
			}
			q.pop();
			for (int k = 0; k < 8; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {
					if (visited[nx][ny] == -1) {
						q.push({ nx,ny });
						visited[nx][ny] = z+1;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}