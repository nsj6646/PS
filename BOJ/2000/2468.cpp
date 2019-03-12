#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int, int> point;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int a[100][100];
int visited[100][100];
int n;
int ans;
void bfs(int i, int j, int h) {
	queue<point> q;
	q.push({ i,j });
	visited[i][j] = 1;
	while (!q.empty()) {
		point now = q.front();
		int x = now.first;
		int y = now.second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {
				if (a[nx][ny] > h&&visited[nx][ny] == 0) {
					q.push({ nx,ny });
					visited[nx][ny] = 1;
				}
			}
		}
	}
}
int main()
{

	cin >> n;
	int w = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			w = max(w, a[i][j]);
		}
	}

	for (int k = 0; k <= w; k++) {
		int cnt = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] > k&&visited[i][j] == 0) {
					bfs(i, j, k);
					cnt += 1;
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}