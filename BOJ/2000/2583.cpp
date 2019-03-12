#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> point;
int a[100][100];
int visited[100][100];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int m, n, k;
priority_queue<int> pq;
void bfs(int x, int y) {
	queue<point> q;
	q.push({ x,y });
	visited[x][y] = 1;
	int cnt = 1;
	while (!q.empty()) {
		point now = q.front();
		int x = now.first;
		int y = now.second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < m&&ny >= 0 && ny < n) {
				if (a[nx][ny] == 0 && visited[nx][ny] == 0) {
					q.push({ nx,ny });
					visited[nx][ny] = 1;
					cnt += 1;
				}
			}
		}
	}
	pq.push(-cnt);
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int y = y1; y < y2; y++) {
			for (int x = x1; x < x2; x++) {
				a[y][x] = 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0 && visited[i][j] == 0) {
				ans += 1;
				bfs(i, j);
			}
		}
	}
	cout << ans << '\n';
	while (!pq.empty()) {
		cout << -pq.top() << ' ';
		pq.pop();
	}
	return 0;
}