#include <iostream>
#include <queue>
using namespace std;

int w, h;
int a[101][101];
typedef struct Point {
	int x, y;
}point;
point make_point(int x, int y) {
	point ret;
	ret.x = x;
	ret.y = y;
	return ret;
}
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int bfs(int x, int y) {
	bool visited[101][101] = { false };
	queue<point> q;
	int cnt = 0;
	q.push(make_point(x, y));
	visited[y][x] = true;
	while (!q.empty()) {
		point now = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = now.x + dx[k];
			int ny = now.y + dy[k];
			if (nx >= 0 && nx < w&&ny >= 0 && ny < h) {
				if (!visited[ny][nx]) {
					visited[ny][nx] = true;
					if (a[ny][nx] == 0) {
						q.push(make_point(nx, ny));			
					}
					else{
						a[ny][nx] = 0;
						cnt += 1;
					}
				}
			}
		}
	}
	return cnt;
}
int main()
{
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}

	//bfs
	int hour;
	int c=0;
	for (hour = 0;; hour++) {
		int flag = bfs(0, 0);
		if (flag == 0) {
			break;
		}
		c = flag;
	}
	cout << hour << '\n' << c;
	//cout << '\n';
	//for (int i = 0; i < h; i++) {
	//	for (int j = 0; j < w; j++) {
	//		cout << a[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	return 0;
}
