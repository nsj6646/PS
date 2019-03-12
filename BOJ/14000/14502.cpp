#include <iostream>
#include <queue>
#include <cstring>
#define N 8
#define INFI 0x7fffffff
using namespace std;

typedef pair<int, int> point;

vector<point> virus;
vector<point> space;

int a[N][N];
int visited[N][N];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n, m;
int total;
int ans;

bool safe(int x, int y) {
	return (x >= 0 && x < n&&y >= 0 && y < m);
}
int bfs() {
	int v_cnt = 0;
	queue<point> q;
	for (auto &x : virus) {
		q.push(x);
		visited[x.first][x.second] = 1;
	}

	while (!q.empty()) {
		point now = q.front();
		q.pop();
		int x = now.first;
		int y = now.second;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (safe(nx,ny)&&a[nx][ny]==0&&visited[nx][ny]==0) {
				visited[nx][ny] = 1;
				q.push({ nx,ny });
				v_cnt += 1;
			}
		}
	}
	return v_cnt;
}
void dfs(int idx, int cnt) {
	if (cnt == 3) {
		memset(visited, 0, sizeof(visited));
		int t = total - bfs() - 3;
		ans = ans > t ? ans : t;
		return;
	}
	for (int i = idx; i < space.size(); i++) {
		int x = space[i].first; 
		int y = space[i].second;
		a[x][y] = 1;
		dfs(i + 1, cnt + 1);
		a[x][y] = 0;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	total = n * m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) {
				space.push_back({ i,j });
			}
			else{
				total -= 1;
				if (a[i][j] == 2) {
					virus.push_back({ i,j });
				}		
			}
		}
	}

	dfs(0, 0);
	cout << ans;
	return 0;
}