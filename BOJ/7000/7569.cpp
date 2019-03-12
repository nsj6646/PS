#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

typedef tuple<int, int, int> point;
//위아래+상하좌우
int dx[] = { 0,0,-1,1,0,0 };
int dy[] = { 0,0,0,0,-1,1 };
int dz[] = { -1,1,0,0,0,0 };
int a[100][100][100];
int visited[100][100][100];
int m, n, h;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n >> h;
	queue<point> q;
	int t = 0;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[k][i][j];
				if (a[k][i][j] == 1) {
					q.push({ k,i,j });
					visited[k][i][j] = 1;
				}
				else if (a[k][i][j] == 0) {
					t += 1;
				}
			}
		}
	}
	if (t == 0) {
		cout << 0;
		return 0;
	}
	int day = 0;
	while (!q.empty()) {
		day += 1;
		int qs = q.size();
		while (qs--) {
			point now = q.front();
			int z = get<0>(now);
			int x = get<1>(now);
			int y = get<2>(now);
			q.pop();
			for (int k = 0; k < 6; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				int nz = z + dz[k];
				if (nx >= 0 && nx < n&&ny >= 0 && ny < m&&nz>=0&&nz<h) {
					if (a[nz][nx][ny] == 0&&visited[nz][nx][ny] == 0) {
						q.push({ nz,nx,ny });
						visited[nz][nx][ny] = 1;
						t-=1;
					}
				}
			}
		}
	}
	if (t != 0) {
		cout << -1;
		return 0;
	}
	cout << day-1;
	return 0;
}