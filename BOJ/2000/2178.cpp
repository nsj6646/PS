#include <cstdio>
#include <queue>
using namespace std;


int maze[100][100];
int check[100][100];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int n, int m) {
	queue < pair<int, int>> q;
	q.push({0, 0});
	check[0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x+dx[k]; 
			int ny = y+dy[k];
			if ((nx >= 0 && nx < n)&&(ny >= 0 && ny < m)) {
				if (maze[nx][ny] == 1 && check[nx][ny] == 0) {
					q.push({ nx,ny });
					check[nx][ny] = check[x][y] + 1;
				}
			}
		}		
	}
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}
	bfs(n, m);
	printf("%d", check[n-1][m-1]);
	return 0;
}