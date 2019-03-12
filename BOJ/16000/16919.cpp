#include <bits/stdc++.h>
using namespace std;

char a[200][200];
int bomb[200][200];

int r, c, n;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

queue<pair<int, int>> q;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> r >> c >> n;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 'O') {
				bomb[i][j] = 3;
			}
		}
	}

	n = n > 5 ? (n-1) % 4+5 : n;
	for (int t = 1; t <= n; ++t) {
		if (t == 1) {
			for (int i = 0; i < r; ++i) {
				for (int j = 0; j < c; ++j) {
					bomb[i][j] -= 1;
				}
			}
			continue;
		}
		if (t % 2) {
			for (int i = 0; i < r; ++i) {
				for (int j = 0; j < c; ++j) {
					bomb[i][j] -= 1;

					if (bomb[i][j] == 0) {
						q.push({ i,j });
					}

				}
			}
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				a[x][y] = '.';
				bomb[x][y] = 0;
				for (int k = 0; k < 4; ++k) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx >= 0 && nx < r&&ny >= 0 && ny < c) {
						a[nx][ny] = '.';
						bomb[nx][ny] = 0;
					}
				}
			}
		}
		else {
			for (int i = 0; i < r; ++i) {
				for (int j = 0; j < c; ++j) {
					bomb[i][j] -=1;
					if (a[i][j] == '.') {
						a[i][j] = 'O';
						bomb[i][j] = 3;
					}
				}
			}
		}
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cout << a[i][j];
		}
		cout << '\n';
	}
	return 0;
}




















//#define N		200
//#include <bits/stdc++.h>
//using namespace std;
//
//struct BOMB {
//	int x, y, timer;
//	BOMB(int r, int c, int t) :x(c), y(r), timer(t) {}
//};
//queue<BOMB> q;
//char a[N][N];
//int r, c, n;
//char ans[5][N][N];
//
//int dx[] = { 0,0,-1,1 };
//int dy[] = { -1,1,0,0 };
//void run() {
//	int sz = q.size();
//	for (int i = 0; i < sz; ++i) {
//		--q.front().timer;
//		q.push(q.front());
//		q.pop();
//	}
//}
//void setup() {
//	for (int i = 0; i < r; ++i) {
//		for (int j = 0; j < c; ++j) {
//			if (a[i][j] == '.') {
//				a[i][j] = 'O';
//				q.push({ i,j ,3 });
//			}
//		}
//	}
//}
//bool safe(int x, int y) {
//	return(x >= 0 && x < c&&y >= 0 && y < r);
//}
//void boom() {
//	int sz = q.size();
//	for (int i = 0; i < sz; ++i) {
//		auto now = q.front();
//		q.pop();
//		int x = now.x;
//		int y = now.y;
//		now.timer -= 1;
//
//		if (now.timer == 0) {
//			a[y][x] = '.';
//			for (int k = 0; k < 4; ++k) {
//				int nx = x + dx[k];
//				int ny = y + dy[k];
//				if (safe(nx, ny)) {
//					a[ny][nx] = '.';
//				}
//			}
//			continue;
//		}
//		if (a[y][x] == '.') {
//			continue;
//		}
//		q.push(now);
//	}
//}
//void save(int idx) {
//	for (int i = 0; i < r; ++i) {
//		for (int j = 0; j < c; ++j) {
//			ans[idx][i][j] = a[i][j];
//		}
//	}
//}
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//
//	cin >> r >> c >> n;
//	for (int i = 0; i < r; ++i) {
//		for (int j = 0; j < c; ++j) {
//			cin >> a[i][j];
//			if (a[i][j] == 'O') {
//				q.push({ i,j ,3 });
//			}
//		}
//	}
//	if (n == 1) {
//		for (int i = 0; i < r; ++i) {
//			for (int j = 0; j < c; ++j) {
//				cout << a[i][j];
//			}
//			cout << '\n';
//		}
//		return 0;
//	}
//	for (int t = 1; t <= 5; ++t) {
//		if (t == 1) {
//			run();
//			continue;
//		}
//		switch (t % 2)
//		{
//		case 0:
//			run();
//			setup();
//			break;
//		case 1:
//			boom();
//			break;
//		}
//		save((t-1)%4);
//	}
//	int idx = (n - 1) % 4;
//	for (int i = 0; i < r; ++i) {
//		for (int j = 0; j < c; ++j) {
//			cout << ans[idx][i][j];
//		}
//		cout << '\n';
//	}
//	return 0;
//}