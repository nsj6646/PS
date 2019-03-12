#include <cstdio>
#include <queue>
using namespace std;

int tomato[1000][1000];
int check[1000][1000];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main()
{
	int m, n;
	queue<pair<int, int>> q;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &tomato[i][j]);
			if (tomato[i][j] == 1) {
				q.push({ i,j });
				check[i][j] = 1;
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < n&&ny >= 0 && ny < m) {
				if (tomato[nx][ny] == 0 && check[nx][ny] == 0) {
					check[nx][ny] = check[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
	printf("\n");
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			printf("%d ", tomato[i][j]);
		}
		printf("\n");
	}
	int ans = -2;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			if (tomato[i][j] == 0 && check[i][j] == 0) {
				printf("-1");
				return 0;
			}
			if (check[i][j] > ans) {
				ans = check[i][j];
			}
		}
	}
	printf("%d", ans - 1);
	return 0;
}
/*
#include <cstdio>
#include <queue>
using namespace std;
int a[1000][1000];
int d[1000][1000];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main() {
	int n, m;
	scanf("%d %d", &m, &n);
	queue<pair<int, int>> q;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			scanf("%d", &a[i][j]);
			d[i][j] = -1;
			if (a[i][j] == 1) {
				q.push(make_pair(i, j));
				d[i][j] = 0;
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k<4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (a[nx][ny] == 0 && d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			if (ans < d[i][j]) {
				ans = d[i][j];
			}
		}
	}
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			if (a[i][j] == 0 && d[i][j] == -1) {
				ans = -1;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
*/