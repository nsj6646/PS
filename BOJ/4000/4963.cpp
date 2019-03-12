#include <cstdio>

int map[50][50];
bool check[50][50];
int dx[] = { 1,0,-1,1,-1,1,0,-1 };
int dy[] = { -1,-1,-1,0,0,1,1,1 };
int w, h;
void dfs(int x, int y) {
	check[x][y] = true;
	for (int k = 0; k<8; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < h && 0 <= ny && ny < w) {
			if (map[nx][ny] == 1 && !check[nx][ny]) {
				dfs(nx, ny);
			}
		}
	}
	
	
}
int main()
{
	while (true) {
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) {
			break;
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &map[i][j]);
				check[i][j] = false;
			}
		}
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && !check[i][j]) {
					dfs(i, j);
					cnt += 1;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}