#include <cstdio>
#include <cstring>
#include <queue>

#define N 21
using namespace std;

typedef pair<int, int> point;		//좌표
typedef pair<int, point> info;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int map[N][N];					//방정보
int visited[N][N][1 << 11];
int w, h;

void init() {
	memset(visited, 0, sizeof(visited));
	memset(map, 0, sizeof(map));
}

bool safe(int x, int y) {
	return (x >= 0 && x < h && y >= 0 && y < w);
}

int main()
{
	while (scanf("%d %d", &w, &h)==2) {
		if (w == 0 && h == 0) {
			return 0;
		}
		/*init*/
		init();
		int cnt = 0;
		queue<info> q;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				char c;
				scanf(" %c", &c);
				if (c == '*') {
					map[i][j] = ++cnt;
				}
				else if (c == 'o') {
					q.push({ 0,{i,j} });
				}
				else if (c == 'x') {
					map[i][j] = -1;
				}
			}
		}
		//printf("\n");
		//for (int i = 0; i < h; i++) {
		//	for (int j = 0; j < w; j++) {
		//		printf("%d ", map[i][j]);
		//	}
		//	printf("\n");
		//}
		int all = (1 << cnt) - 1;
		bool check = false;
		while (!q.empty()) {
			info &now = q.front();
			int x = now.second.first;
			int y = now.second.second;
			int visit = now.first;
			q.pop();
			if (visit == all) {
				printf("%d\n", visited[x][y][visit]);
				check = true;
				break;
			}
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (safe(nx, ny) && map[nx][ny] != -1) {
					if (map[nx][ny] > 0) {
						int nvisit = visit | (1 << map[nx][ny] - 1);
						if (!visited[nx][ny][nvisit]) {
							q.push({ nvisit,{nx,ny} });
							visited[nx][ny][nvisit] = visited[x][y][visit] + 1;
						}
					}
					else if(map[nx][ny]==0){
						if (!visited[nx][ny][visit]) {
							q.push({ visit, { nx,ny } });
							visited[nx][ny][visit] = visited[x][y][visit] + 1;
						}
					}
				}
			}
		}
		if (!check) {
			printf("-1\n");
		}
	}

	return 0;
}