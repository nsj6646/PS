#include <iostream>
#include <queue>
using namespace std;

int n, m;
int a[101][101];
typedef struct Point {
	int x, y;
}point;
point make_point(int x, int y) {
	point ret;
	ret.x = x;
	ret.y = y;
	return ret;
}
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int bfs(int x, int y) {
	int visited[101][101] = { 0 };
	queue<point> q, c;
	int cnt = 0;
	q.push(make_point(x, y));
	visited[y][x] = 1;
	while (!q.empty()) {
		point now = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = now.x + dx[k];
			int ny = now.y + dy[k];
			if (nx >= 0 && nx < m&&ny >= 0 && ny < n) {
				if (a[ny][nx]==0) {				
					if (visited[ny][nx] == 0) {
						visited[ny][nx] = 1;
						q.push(make_point(nx, ny));
					}	
				}
				else {
					visited[ny][nx] += 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) {
				cnt += 1;
				if (visited[i][j] >= 2) {
					a[i][j] = 0;
				}
			}
		}
	}
	return cnt;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	//bfs
	int hour;
	for (hour = 0;; hour++) {
		int flag = bfs(0, 0);	
		if (flag == 0) {
			break;
		}
	}
	cout << hour << '\n';


	return 0;
}
