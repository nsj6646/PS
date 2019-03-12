#include <iostream>
#include <queue>
#include <cstring>
#define N 20

using namespace std;


typedef pair<int, int> point;
typedef pair<int, point> info;

struct fish
{
	int x, y;
	int size, cnt;
	int dist;
	fish(int x = 0, int y = 0, int size = 0, int cnt = 0, int dist = 0) :x(x), y(y), size(size), cnt(cnt), dist(dist) {}
};
int n;
int a[N][N];
bool visited[N][N];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
fish gbc;			//개복치
fish target;		//먹을 물고기
int ans;
bool safe(int x, int y) {
	return (x >= 0 && x < n&&y >= 0 && y< n);
}
bool cmp(const fish &t, const fish &nt) {
	if (t.dist > nt.dist) {
		return true;
	}
	else if (t.dist == nt.dist) {
		if (t.x > nt.x) {
			return true;
		}
		else if (t.x == nt.x) {
			return t.y > nt.y;
		}
	}
	return false;
}
bool bfs(int sx,int sy) {
	memset(visited, false, sizeof(visited));
	visited[sx][sy] = true;
	queue<info> q;
	q.push({ 0,{sx,sy} });
	bool found = false;
	while (!q.empty()) {
		int qs = q.size();
		for (int t = 0; t < qs; t++) {
			info now = q.front();
			q.pop();
			int x = now.second.first;
			int y = now.second.second;
			int dist = now.first;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (safe(nx, ny) && !visited[nx][ny] && (a[nx][ny] <= gbc.size)) {
					if (a[nx][ny]!=0&&a[nx][ny] < gbc.size) {
						fish nt = { nx,ny,a[nx][ny],0,dist + 1 };
						if (target.size == 0 || cmp(target, nt)) {
							target = nt;
							found = true;
						}
					}
					visited[nx][ny] = true;
					q.push({ dist + 1,{nx,ny} });
				}
			}
		}
		if (found) {
			return true;
		}
	}
	return false;
}
void simulate() {
	while(bfs(gbc.x, gbc.y)) {
		a[gbc.x][gbc.y] = 0;
		gbc.x = target.x;
		gbc.y = target.y;
		a[gbc.x][gbc.y] = 9;
		gbc.cnt += 1;
		if (gbc.size == gbc.cnt) {
			gbc.size += 1;
			gbc.cnt = 0;
		}
		gbc.dist += target.dist;
		target = { 0,0,0,0,0 };
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 9) {
				gbc = { i,j,2,0 };
			}
		}
	}
	/*simulate*/
	simulate();
	cout << gbc.dist;
	return 0;
}