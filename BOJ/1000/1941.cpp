#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define N 5
using namespace std;

typedef pair<int, int> point;
vector<point> v;
vector<point> combi;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

char a[N][N];
int check[N][N];
int visited[N][N];
int ans = 0;
bool bfs(int sx,int sy) {
	memset(visited, 0, sizeof(visited));
	int cnt = 1;
	point sp = { sx,sy};
	visited[sx][sy] = 1;
	queue<point> q;
	q.push(sp);
	while (!q.empty()) {
		point now = q.front();
		q.pop();
		int x = now.first;
		int y = now.second;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && check[nx][ny] == 1 && visited[nx][ny] == 0) {
				cnt += 1;
				visited[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
	return cnt == 7;
}
void solve(int idx, int cnt,int cnt7) {
	if (cnt == 7) {
		if (cnt7 >= 4) {
			if (bfs(combi[0].first, combi[0].second)) {
				ans += 1;
			}
		}
		return;
	}
	for (int i = idx; i < v.size(); i++) {
		combi.push_back(v[i]);
		int x = v[i].first;
		int y = v[i].second;
		check[x][y] = 1;
		if (a[x][y] == 'S') {
			solve(i + 1, cnt + 1,cnt7+1);
		}
		else {
			solve(i + 1, cnt + 1,cnt7);
		}
		check[x][y] = 0;
		combi.pop_back();
	}
}
int main()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf(" %c", &a[i][j]);
			v.push_back({ i,j });
		}
	}

	solve(0,0,0);	

	printf("%d", ans);
	return 0;
}