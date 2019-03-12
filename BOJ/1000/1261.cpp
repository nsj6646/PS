#include <cstdio>
#include <queue>
#define INF	100000
using namespace std;

typedef pair<int, int> point;
typedef pair<int, point> info;
int n, m;
int a[100][100];
int dist[100][100];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };


int main()
{
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d",&a[i][j]);
			dist[i][j] = INF;
		}
	}

	int ans;
	priority_queue<info> pq;
	dist[0][0] = 0;
	pq.push({ 0,{ 0,0 } });

	while (!pq.empty()) {
		info now = pq.top();
		int x = now.second.first;
		int y = now.second.second;
		int z = -now.first;
		pq.pop();
		if (x == n - 1 && y == m - 1) {
			ans = z;
			break;
		}
		if (z > dist[x][y]) {
			continue;
		}
		printf("\n");
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m; j++) {
		//		printf("%d ",dist[i][j]);
		//	}
		//	printf("\n");
		//}
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < n&&ny >= 0 && ny < m) {
				int &nz = dist[nx][ny];
				if (nz>z+a[nx][ny]) {
					nz = z + a[nx][ny];
					pq.push({ -nz,{nx,ny} });
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}