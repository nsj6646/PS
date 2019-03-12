#define N		50
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> point;
int n, l, r;

int a[N][N];
int visited[N][N];
int sum[N*N];
int total[N*N];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

queue<point> q;

bool safe(int x, int y) {
	return x >= 0 && x < n&&y >= 0 && y < n;
}
bool moved = true;

void bfs(int num, int i, int j) {
	visited[i][j] = num;
	q.push({ i,j });
	sum[num] = a[i][j];
	total[num] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (safe(nx, ny) && visited[nx][ny] == 0) {
				int diff = abs(a[x][y] - a[nx][ny]);
				if (diff >= l && diff <= r) {
					moved = true;
					visited[nx][ny] = num;
					q.push({ nx,ny });
					sum[num] += a[nx][ny];
					total[num]++;
				}
			}
		}
	}
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> l >> r;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}

	int ans = 0;
	while (moved) {
		moved = false;
		int num = 1;
		memset(visited, 0, sizeof(visited));
		memset(sum, 0, sizeof(sum));
		memset(total, 0, sizeof(total));

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (visited[i][j] == 0) {
					bfs(num++, i, j);
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int &u = visited[i][j];
				a[i][j] = sum[u] / total[u];
			}
		}

		if (moved) {
			ans++;
		}
	}

	cout << ans;


	return 0;
}