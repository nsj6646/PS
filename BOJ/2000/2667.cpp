#include <cstdio>
#include <queue>
using namespace std;

typedef pair<int, int> point;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n;
int a[25][25];
int visited[25][25];

int bfs(int sx, int sy) {
	int cnt = 1;
	queue<point> q;
	q.push({ sx,sy });
	visited[sx][sy] = 1;
	while (!q.empty()) {
		point now = q.front();
		int x = now.first;
		int y = now.second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {
				if (a[nx][ny] == 1 && visited[nx][ny] == 0) {
					cnt += 1;
					q.push({ nx,ny });
					visited[nx][ny] = 1;
				}
			}
		}
	}
	return cnt;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	int cnt = 0;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 && visited[i][j] == 0) {
				cnt += 1;
				pq.push(-bfs(i, j));
			}
		}
	}
	printf("%d\n", cnt);
	while (!pq.empty()) {
		printf("%d\n", -pq.top());
		pq.pop();
	}
	return 0;
}
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//
//int map[25][25];
//int check[25][25];
//int ans[25];
//
//void dfs(int x, int y, int c,int n) {
//	if (x < 0 || y < 0 || x >= n || y >= n) {
//		return;
//	}
//	if (check[x][y]==0) {
//		return;
//	}
//	check[x][y] = 0;
//	map[x][y] = c;
//	ans[c] += 1;
//	dfs(x - 1, y, c,n);
//	dfs(x + 1, y, c, n);
//	dfs(x, y - 1, c, n);
//	dfs(x, y + 1, c, n);
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			scanf("%1d", &check[i][j]);
//		}
//	}
//	int color = 1;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (check[i][j] == 1) {
//				dfs(i, j, color, n);
//				color += 1;
//			}
//		}
//	}
//	printf("%d\n", color - 1);
//	sort(ans + 1, ans + color);
//	for (int i = 1; i < color; i++) {
//		printf("%d\n", ans[i]);
//	}
//	return 0;
//}
///*bfs
//#include <cstdio>
//#include <algorithm>
//#include <queue>
//using namespace std;
//int a[30][30];
//int group[30][30];
//int dx[] = { 0,0,1,-1 };
//int dy[] = { 1,-1,0,0 };
//int n;
//int ans[25 * 25];
//void bfs(int x, int y, int cnt) {
//	queue<pair<int, int>> q;
//	q.push(make_pair(x, y));
//	group[x][y] = cnt;
//	while (!q.empty()) {
//		x = q.front().first;
//		y = q.front().second;
//		q.pop();
//		for (int k = 0; k<4; k++) {
//			int nx = x + dx[k];
//			int ny = y + dy[k];
//			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
//				if (a[nx][ny] == 1 && group[nx][ny] == 0) {
//					q.push(make_pair(nx, ny));
//					group[nx][ny] = cnt;
//				}
//			}
//		}
//	}
//}
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i<n; i++) {
//		for (int j = 0; j<n; j++) {
//			scanf("%1d", &a[i][j]);
//		}
//	}
//	int cnt = 0;
//	for (int i = 0; i<n; i++) {
//		for (int j = 0; j<n; j++) {
//			if (a[i][j] == 1 && group[i][j] == 0) {
//				bfs(i, j, ++cnt);
//			}
//		}
//	}
//	printf("%d\n", cnt);
//	for (int i = 0; i<n; i++) {
//		for (int j = 0; j<n; j++) {
//			ans[group[i][j]] += 1;
//		}
//	}
//	sort(ans + 1, ans + cnt + 1);
//	for (int i = 1; i <= cnt; i++) {
//		printf("%d\n", ans[i]);
//	}
//	return 0;
//}
//*/
///*dfs
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//int a[30][30];
//int d[30][30];
//int dx[] = { 0,0,1,-1 };
//int dy[] = { 1,-1,0,0 };
//int n;
//int ans[25 * 25];
//void dfs(int x, int y, int cnt) {
//	d[x][y] = cnt;
//	for (int k = 0; k<4; k++) {
//		int nx = x + dx[k];
//		int ny = y + dy[k];
//		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
//			if (a[nx][ny] == 1 && d[nx][ny] == 0) {
//				dfs(nx, ny, cnt);
//			}
//		}
//	}
//}
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i<n; i++) {
//		for (int j = 0; j<n; j++) {
//			scanf("%1d", &a[i][j]);
//		}
//	}
//	int cnt = 0;
//	for (int i = 0; i<n; i++) {
//		for (int j = 0; j<n; j++) {
//			if (a[i][j] == 1 && d[i][j] == 0) {
//				dfs(i, j, ++cnt);
//			}
//		}
//	}
//	printf("%d\n", cnt);
//	for (int i = 0; i<n; i++) {
//		for (int j = 0; j<n; j++) {
//			ans[d[i][j]] += 1;
//		}
//	}
//	sort(ans + 1, ans + cnt + 1);
//	for (int i = 1; i <= cnt; i++) {
//		printf("%d\n", ans[i]);
//	}
//	return 0;
//}
//*/