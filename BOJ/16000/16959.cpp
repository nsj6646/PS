/*
BOJ 16959: ü���� ���� 1
copyright: nsj6646@naver.com
*/

#include <bits/stdc++.h>
using namespace std;
#define N			11

struct Unit {
	int type;		//0: ����Ʈ, 1: ���, 2: ��
	int num;		//�迭�� ���� ��
	int x, y;		//��ǥ
	int dist;		//�ɸ� �ð�
	Unit(int t, int n, int x, int y, int d) :type(t), num(n), x(x), y(y), dist(d) {}
};
int dx[3][8] = {
	{ -1,-2,-2,-1,1,2,2,1 },
{ -1,-1,1,1 },
{ -1,1,0,0 }
};
int dy[3][8] = {
	{ -2,-1,1,2,2,1,-1,-2 },
{ -1,1,-1,1 },
{ 0,0,-1,1 }
};
int n;
int a[N][N];
bool visited[3][N*N][N][N];			//[�����][����϶�][��][ǥ] �湮üũ�迭
queue<Unit> q;

bool safe(int x, int y) {
	return x >= 0 && x < n&&y >= 0 && y < n;
}

int bfs(int sx, int sy) {
	for (int i = 0; i < 3; ++i) {
		q.push({ i,1,sx,sy,0 });
		visited[i][1][sx][sy] = true;
	}

	while (!q.empty()) {
		Unit now = q.front();
		int type = now.type;
		int num = now.num;
		int x = now.x;
		int y = now.y;
		int dist = now.dist;
		q.pop();
		if (num == n * n) {
			return dist;
		}

		if (type == 0) {
			/*����Ʈ�� �̵��ϱ�*/
			for (int k = 0; k < 8; ++k) {
				int nx = x + dx[type][k];
				int ny = y + dy[type][k];
				if (safe(nx, ny)) {
					if (a[nx][ny] == num + 1) {
						visited[type][num + 1][nx][ny] = true;
						q.push({ type, num + 1,nx,ny, dist + 1 });
						break;
					}
					else if (!visited[type][num][nx][ny]) {
						visited[type][num][nx][ny] = true;
						q.push({ type, num,nx,ny, dist + 1 });
					}
				}
			}
		}
		else if (type == 1) {
			/*������� �̵��ϱ�*/
			bool found = false;
			for (int l = 1; l <= n; ++l) {
				if (found) break;
				for (int k = 0; k < 4; ++k) {
					int nx = x + dx[type][k] * l;
					int ny = y + dy[type][k] * l;
					if (safe(nx, ny)) {
						if (a[nx][ny] == num + 1) {
							visited[type][num + 1][nx][ny] = true;
							q.push({ type, num + 1,nx,ny, dist + 1 });
							found = true;
							break;
						}
						else if (!visited[type][num][nx][ny]) {
							visited[type][num][nx][ny] = true;
							q.push({ type, num,nx,ny, dist + 1 });
						}
					}
				}
			}

		}
		else {
			/*������ �̵��ϱ�*/
			bool found = false;
			for (int l = 1; l <= n; ++l) {
				if (found) break;
				for (int k = 0; k < 4; ++k) {
					int nx = x + dx[type][k] * l;
					int ny = y + dy[type][k] * l;
					if (safe(nx, ny)) {
						if (a[nx][ny] == num + 1) {
							visited[type][num + 1][nx][ny] = true;
							q.push({ type, num + 1,nx,ny, dist + 1 });
							found = true;
							break;
						}
						else if (!visited[type][num][nx][ny]) {
							visited[type][num][nx][ny] = true;
							q.push({ type, num,nx,ny, dist + 1 });
						}
					}
				}
			}
		}
		/*�� �ٲٱ�*/
		for (int i = 0; i < 3; ++i) {
			if (i == type) continue;
			if (!visited[i][num][x][y]) {
				q.push({ i,num,x,y,dist + 1 });
				visited[i][num][x][y] = true;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int sx, sy;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				sx = i, sy = j;
			}
		}
	}
	cout << bfs(sx, sy);

	return 0;
}