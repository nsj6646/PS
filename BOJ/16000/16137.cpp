#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define INFI 0x7fffffff
using namespace std;

typedef pair<int, int> point;
typedef pair<int, point> info;
vector<point> cliff;
int n, m;
int a[10][10];
bool visited[10][10];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int ans = INFI;
bool iscross(point p) {
	int x = p.first;
	int y = p.second;
	int x2 = x + dx[2];
	int y2 = y + dy[2];
	int x3 = x + dx[3];
	int y3 = y + dy[3];
	for (int k = 0; k < 2; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if ((nx >= 0 && nx < n&&ny >= 0 && ny < n) && (a[nx][ny] == 0 || a[nx][ny] >= 2)) {
			if ((x2 >= 0 && x2 < n&&y2 >= 0 && y2 < n)&& (a[x2][y2] == 0 || a[x2][y2] >= 2)) {
				return true;
			}
			if ((x3 >= 0 && x3 < n&&y3 >= 0 && y3 < n) && (a[x3][y3] == 0 || a[x3][y3] >= 2)) {
				return true;
			}
		}
	}
	return false;
}

void solve() {
	memset(visited, false, sizeof(visited));
	point sp = { 0,0 };
	info si = { 0,sp };

	queue<info> q;
	visited[0][0] = true;
	q.push(si);
	while (!q.empty()) {
		int qs = q.size();
		for (int t = 0; t < qs; t++) {
			info now = q.front();
			int T = now.first;
			point p = now.second;
			int x = p.first;
			int y = p.second;
			q.pop();
			if (x == n - 1 && y == n - 1) {
				ans = min(ans, T);
				continue;
			}
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if ((nx >= 0 && nx < n&&ny >= 0 && ny < n) && !visited[nx][ny]) {
					if (a[nx][ny] == 1) {
						visited[nx][ny] = true;
						q.push({ T + 1, { nx,ny } });
					}
					else if (a[nx][ny] >= 2) {
						if (a[x][y] >= 2) {	//연속으로 건널 수 없음.
							continue;
						}
						if ((T+1)%a[nx][ny] == 0) {	//주기에 맞으면 이동
							visited[nx][ny] = true;
							q.push({ T + 1,{ nx,ny } });
						}
						else {		//존버
							q.push({ T + 1,{ x,y } });
						}
					}
				}
			}
		}
		//cout << '\n';
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < n; j++) {
		//		cout << visited[i][j] << ' ';
		//	}
		//	cout << '\n';
		//}
	}

}
int main()
{
	cin >> n >> m;
	cliff.push_back({ 0,0 });
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) {
				cliff.push_back({ i,j });
			}
		}
	}
	for (int i = 0; i < cliff.size(); i++) {
		point p = cliff[i];
		if (iscross(p)) {
			continue;
		}
		a[p.first][p.second] = m;
		solve();
		a[p.first][p.second] = 0;
	}

	cout << ans;
	return 0;
}