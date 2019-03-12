#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

char map[100][101];
int visited[100][100];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

typedef struct Point {
	int x, y;
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
}point;

int main()
{
	int w, h;
	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		cin >> map[i];
	}

	vector<point> v;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 'C') {
				v.push_back(point(i, j));
			}
		}
	}

	queue<point> q;
	q.push(v[0]);
	visited[v[0].x][v[0].y] = 1;
	while (!q.empty()) {
		point now = q.front();
		q.pop();
		int x = now.x; int y = now.y;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k]; int ny = y + dy[k];
			while (nx >= 0 && nx < h&&ny >= 0 && ny < w && map[nx][ny] != '*') {
				if (visited[nx][ny] == 0) {
					q.push(point(nx, ny));
					visited[nx][ny] = visited[x][y] + 1;
				}
				nx += dx[k]; ny += dy[k];
			}
		}
	}
	point t = v[1];
	int ans = visited[t.x][t.y];
	cout << ans - 2;
	return 0;
}