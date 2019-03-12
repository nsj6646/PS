#define H		1000
#define W		1000
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> point;

point sp;
priority_queue<int> pq;
queue<point> q;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

char a[H][W];
int visited[H][W];


int h, w, n;
void init() {
	while (!q.empty()) q.pop();
	memset(visited, 0, sizeof(visited));
}

bool safe(int x, int y) {
	return(x >= 0 && x < w&&y >= 0 && y < h);
}
int bfs(int l) {
	int t = 0;
	q.push(sp);
	visited[sp.second][sp.first];
	while (!q.empty()) {
		int qs = q.size();
		++t;
		for (int i = 0; i < qs; ++i) {
			point now = q.front();
			q.pop();
			int x = now.first;
			int y = now.second;
			for (int k = 0; k < 4; ++k) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (safe(nx, ny) && !visited[ny][nx] && a[ny][nx] != 'X') {
					if (a[ny][nx] == l + '0') {
						sp = { nx,ny };
						return t;
					}
					visited[ny][nx] = 1;
					q.push({ nx,ny });
				}
			}
		}
	}
}
int main()
{

	scanf("%d %d %d", &h, &w, &n);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			scanf(" %c", &a[i][j]);
			if (a[i][j] == 'S') {
				sp = { j,i };
			}
			else if (a[i][j] >= '1' && a[i][j] <= '9') {
				pq.push(-(a[i][j] - '0'));
			}
		}
	}

	int ans = 0;
	while (!pq.empty()) {
		init();
		ans+=bfs(-pq.top());
		pq.pop();
	}
	printf("%d",ans);


	return 0;
}