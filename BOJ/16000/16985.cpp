#include<bits/stdc++.h>
using namespace std;

struct loc {
	int x, y, z;
	int dist;
	loc(int x, int y, int z, int d) :x(x), y(y), z(z), dist(d) {}
};
int a[5][5][5];
int maze[5][5][5];
int layer[5] = { 0,1,2,3,4 };
int visited[5][5][5];
int ans = -1;
queue<loc> q;
int dx[] = { 0,-1,1,0,0,0 };
int dy[] = { 0,0,0,-1,1,0 };
int dz[] = { -1,0,0,0,0,1 };

void cyclic_roll(int &a, int &b, int &c, int &d){
	int temp = a;
	a = b;
	b = c;
	c = d;
	d = temp;
}

void rotate(int idx) {
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			cyclic_roll(maze[idx][i][j], maze[idx][4 - j][i], maze[idx][4 - i][4 - j], maze[idx][j][4 - i]);
		}
	}
}

bool safe(int x, int y, int z) {
	return (x >= 0 && x < 5 && y >= 0 && y < 5 && z >= 0 && z < 5);
}

void bfs() {
	memset(visited, 0, sizeof(visited));
	visited[0][0][0] = 0;
	q.push({ 0,0,0 ,0 });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		int d = q.front().dist;
		q.pop();
		if (x == 4 && y == 4 && z == 4) {
			if (d == 12) {
				cout << 12; //<---ÀÌ°Í¸¸ ÇØÁàµµ È® »¡¶óÁü
				exit(0);
			}
			if (ans == -1 || ans > d) {
				ans = d;
			}
		}
		for (int k = 0; k < 6; ++k) {
			int nz = z + dz[k];
			int nx = x + dx[k];
			int ny = y + dy[k];
			int nd = d + 1;
			if (safe(nx, ny, nz) && !visited[nz][nx][ny] && maze[nz][nx][ny] == 1) {
				visited[nz][nx][ny] = 1;
				q.push({ nx,ny,nz,nd });
			}

		}
	}
}
void make_maze(int cnt) {
	if (cnt == 5) {
		if (maze[4][4][4] == 1) {
			bfs();
		}
		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (maze[0][0][0] == 1) {
			make_maze(cnt + 1);
		}
		rotate(cnt);
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			for (int k = 0; k < 5; ++k) {
				cin >> a[i][j][k];
			}
		}
	}

	do {
		for (int i = 0; i < 5; ++i) {
			memcpy(maze[i], a[layer[i]], sizeof(maze[i]));
		}
		make_maze(0);
	} while (next_permutation(layer, layer + 5));

	cout << ans;

	return 0;
}