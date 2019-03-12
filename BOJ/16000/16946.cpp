#include <bits/stdc++.h>
using namespace std;

char a[1000][1001];
int visited[1000][1000];
int area[1000000];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n, m;

vector<pair<int, int>> v;
queue<pair<int, int>> q;
bool safe(int x, int y) {
	return (x >= 0 && x < n&&y >= 0 && y < m);
}
void bfs(int i, int j,int num) {
	int cnt = 1;
	visited[i][j] = num;
	q.push({ i,j });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (safe(nx, ny) && a[nx][ny] == '0'&&visited[nx][ny] == 0) {
				cnt++;
				visited[nx][ny] = num;
				q.push({ nx,ny });
			}
		}
	}
	area[num] = cnt;
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '1') {
				v.push_back({ i,j });
			}
		}
	}

	int num = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '0'&&visited[i][j]==0) {
				bfs(i, j,num++);
			}
		}
	}
	set<int> s;
	for (int i = 0; i < v.size(); ++i) {
		int x = v[i].first;
		int y = v[i].second;
		int w = 1;
		s.clear();
		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (safe(nx, ny)&&s.count(visited[nx][ny])==0) {
				w += area[visited[nx][ny]];
				s.insert(visited[nx][ny]);
			}
		}
		a[x][y] = '0' + w % 10;
	}
	for (int i = 0; i < n; ++i) {
		cout << a[i] << '\n';
	}
	return 0;
}