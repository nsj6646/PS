#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> point;
int a[1000][1000];
int visited[1000][1000];
int area[1000000];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
queue<point> q;
vector<point> v;
int n, m;

bool safe(int x, int y) {
	return(x >= 0 && x < n && y >= 0 && y < m);
}

void bfs(int x, int y, int num) {
	int cnt = 1;
	visited[x][y] = num;
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (safe(nx, ny) && a[nx][ny] == 1 && visited[nx][ny] == 0) {
				cnt += 1;
				visited[nx][ny] = num;
				q.push({ nx,ny });
			}
		}
	}
	area[num] = cnt;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 0) {
				v.push_back({ i,j });
			}
		}
	}

	int cnt = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 1 && visited[i][j] == 0) {
				bfs(i, j, cnt++);
			}

		}
	}
	set<int> check;
	int ans = 0;
	for (int i = 0; i < v.size(); ++i) {
		int x = v[i].first;
		int y = v[i].second;
		int sum = 1;
		check.clear();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (safe(nx, ny) && check.count(visited[nx][ny]) == 0) {
				check.insert(visited[nx][ny]);
				sum += area[visited[nx][ny]];
			}
		}
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}