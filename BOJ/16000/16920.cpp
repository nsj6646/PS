#define MAXN		1005
#include <bits/stdc++.h>
using namespace std;

char a[MAXN][MAXN];
bool visited[MAXN][MAXN];
int s[10];
int ans[10];
int n, m, p;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

queue<pair<int, int>> q[10];
int bfs(int player) {
	for (int t = 0; t < s[player]; ++t) {
		if (q[player].empty()) {
			return true;
		}
		int sz = q[player].size();
		while (sz--) {
			int x = q[player].front().first;
			int y = q[player].front().second;
			q[player].pop();
			for (int k = 0; k < 4; ++k) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx >= 0 && nx < n&&ny >= 0 && ny < m&&a[nx][ny] == '.' && !visited[nx][ny]) {
					visited[nx][ny] = true;
					a[nx][ny] = player + '0';
					q[player].push({ nx,ny });
					ans[player] += 1;
				}
			}
		}
	}

	return q[player].empty();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> p;
	for (int i = 1; i <= p; ++i) {
		cin >> s[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			if (a[i][j] >= '1' && a[i][j] <= '9') {
				q[a[i][j] - '0'].push({ i,j });
				visited[i][j] = true;
				ans[a[i][j] - '0'] += 1;
			}
		}
	}

	int all = (1 << p) - 1;
	int bit = 0;
	while (all^bit) {
		for (int i = 1; i <= p; ++i) {
			if (bit&(1 << (i - 1))) continue;
			if (bfs(i)) {
				bit |= 1 << (i - 1);
			}
		}		
	}

	for (int i = 1; i <= p; ++i) {
		cout << ans[i] << ' ';
	}
	return 0;
}





















//
//#define N		1000
//#include <bits/stdc++.h>
//using namespace std;
//
//struct CASTLE {
//	int x, y;
//	CASTLE(int r, int c) :x(c), y(r) {}
//};
//
//queue<CASTLE> q[10];
//
//char a[N][N];
//bool visited[N][N];
//
//int n, m, p;
//
//int s[10];
//int ans[10];
//
//int dx[] = { 0,0,-1,1 };
//int dy[] = { -1,1,0,0 };
//
//bool safe(int x, int y) {
//	return(x >= 0 && x < m&&y >= 0 && y < n);
//}
//
//bool play(int player) {
//	for (int i = 0; i < s[player]; ++i) {
//		if (q[player].empty()) {
//			return true;
//		}
//		int sz = q[player].size();
//		while (sz--) {
//			auto now = q[player].front();
//			q[player].pop();
//			int x = now.x;
//			int y = now.y;
//			for (int k = 0; k < 4; ++k) {
//				int nx = x + dx[k];
//				int ny = y + dy[k];
//				if (safe(nx, ny) && a[ny][nx] == '.' && !visited[ny][nx]) {
//					a[ny][nx] = player + '0';
//					visited[ny][nx] = true;
//					q[player].push({ ny,nx });
//					ans[player] += 1;
//				}
//			}
//		}
//	}
//	return q[player].empty();
//}
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> n >> m >> p;
//	for (int i = 1; i <= p; ++i) {
//		cin >> s[i];
//	}
//
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			cin >> a[i][j];
//			if (a[i][j] >= '1'&&a[i][j] <= '9') {
//				int idx = a[i][j] - '0';
//				q[idx].push({ i,j });
//				visited[i][j] = true;
//				ans[idx] += 1;
//			}
//		}
//	}
//
//
//	int bit = 0;
//	int all = ((1 << p) - 1);
//
//	while (bit ^ all) {
//		for (int k = 1; k <= p; ++k) {
//			if (bit ^ (1 << (k - 1))) {
//				if (play(k)) {
//					bit = bit | (1 << (k - 1));
//				}
//			}
//		}
//
//	}
//
//	for (int i = 1; i <= p; ++i) {
//		cout << ans[i] << ' ';
//	}
//	return 0;
//}