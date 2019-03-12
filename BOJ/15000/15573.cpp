#define MAX_SIZE		1000
#define MAX(X,Y)		(X)>(Y)?(X):(Y)
#include <cstdio>
#include <queue>
using namespace std;

int n, m, k;
typedef pair<int, int> point;

int a[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];	//Ã¤±¼ºÒ°¡´É: -1 Ã¤±¼°¡´É: 0 Ã¤±¼¿Ï·á: 1

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void init() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i == 0 || j == 0 || j == m - 1) continue;
			visited[i][j] = -1;
		}
	}
}

queue<point> q;
bool safe(int x, int y) {
	return (y >= 0 && y < n&&x >= 0 && x < m);
}
int bfs(int limit) {
	int ret = 0;
	init();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i == 0 || j == 0 || j == m - 1) {
				if (a[i][j] <= limit) {
					q.push({ i,j });
					visited[i][j] = 1;
					ret += 1;
					for (int l = 0; l < 4; ++l) {
						int lx = j + dx[l];
						int ly = i + dy[l];
						if (safe(lx, ly) && visited[ly][lx] == -1 && a[ly][lx] <= limit) {
							visited[ly][lx] = 0;
						}
					}
				}
			}
		}
	}
	while (!q.empty()) {
		point now = q.front();
		q.pop();
		int x = now.second;
		int y = now.first;
		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (safe(nx, ny) && visited[ny][nx] == 0&&a[ny][nx]<=limit) {
				q.push({ ny,nx });
				visited[ny][nx] = 1;
				ret += 1;
				for (int l = 0; l < 4; ++l) {
					int lx = nx + dx[l];
					int ly = ny + dy[l];
					if (safe(lx, ly) && visited[ly][lx] == -1 && a[ly][lx] <= limit) {
						visited[ly][lx] = 0;
					}
				}
			}
		}
	}
	return ret;
}
int main()
{
	scanf("%d %d %d", &n, &m, &k);
	int low = 1, high = 0, mid;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
			high = MAX(high, a[i][j]);
		}
	}

	init();

	while (low <= high) {
		mid = (low + high) / 2;

		int temp=bfs(mid);
		if (temp >= k) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	printf("%d", low);
	return 0;
}