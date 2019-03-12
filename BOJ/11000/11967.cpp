#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> point;

bool visited[101][101];
bool map[101][101];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	queue<point> s[101][101];
	for (int i = 0; i < m; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		s[x][y].push({ a,b });
	}
	queue<point> q;
	q.push({ 1,1 });
	map[1][1] = true;
	visited[1][1] = true;
	int ans = 1;

	while (!q.empty()) {
		point now = q.front();
		q.pop();
		auto &sq = s[now.first][now.second];
		while(!sq.empty()) {
			point p = sq.front();
			sq.pop();
			if (!map[p.first][p.second]) {
				map[p.first][p.second] = true;
				ans += 1;
				for (int k = 0; k < 4; k++) {
					int nx = p.first + dx[k];
					int ny = p.second + dy[k];
					if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
						if (visited[nx][ny]) {
							q.push({ nx,ny });
						}
					}
				}
			}
		}

		for (int k = 0; k < 4; k++) {
			int nx = now.first + dx[k];
			int ny = now.second + dy[k];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
				if (!visited[nx][ny] && map[nx][ny]) {
					q.push({ nx,ny });
					visited[nx][ny] = true;
				}
			}
		}
	}
	cout << ans;

	return 0;
}

//°íÇö¹Î¹æ¹ý
//#include <iostream>
//#include <queue>
//using namespace std;
//
//typedef pair<int, int> point;
//
//bool visited[101][101];
//bool map[101][101];
//bool check[101][101];
//int dx[] = { -1,1,0,0 };
//int dy[] = { 0,0,-1,1 };
//
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//	int n, m;
//	cin >> n >> m;
//	queue<point> s[101][101];
//	for (int i = 0; i < m; i++) {
//		int x, y, a, b;
//		cin >> x >> y >> a >> b;
//		s[x][y].push({ a,b });
//	}
//	queue<point> q;
//	q.push({ 1,1 });
//	map[1][1] = true;
//	visited[1][1] = true;
//	int ans = 1;
//
//	while (!q.empty()) {
//		point now = q.front();
//		q.pop();
//		auto &sq = s[now.first][now.second];
//		while (!sq.empty()) {
//			point p = sq.front();
//			sq.pop();
//			if (!map[p.first][p.second]) {
//				map[p.first][p.second] = true;
//				ans += 1;
//				if (check[p.first][p.second]) {
//					q.push({ p.first,p.second });
//				}
//			}
//		}
//
//		for (int k = 0; k < 4; k++) {
//			int nx = now.first + dx[k];
//			int ny = now.second + dy[k];
//			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
//				if (!visited[nx][ny] && map[nx][ny]) {
//					q.push({ nx,ny });
//					visited[nx][ny] = true;
//				}
//				else if (!map[nx][ny]) {
//					check[nx][ny] = true;
//				}
//			}
//		}
//	}
//	cout << ans;
//
//	return 0;
//}