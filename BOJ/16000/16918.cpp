#define N		200
#include <bits/stdc++.h>
using namespace std;

struct BOMB {
	int x, y, timer;
	BOMB(int r, int c, int t) :x(c), y(r), timer(t) {}
};
queue<BOMB> q;
char a[N][N];
int r, c, n;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
void run() {
	int sz = q.size();
	for (int i = 0; i < sz; ++i) {
		--q.front().timer;
		q.push(q.front());
		q.pop();
	}
}
void setup() {
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (a[i][j] == '.') {
				a[i][j] = 'O';
				q.push({ i,j ,3 });
			}
		}
	}
}
bool safe(int x, int y) {
	return(x >= 0 && x < c&&y >= 0 && y < r);
}
void boom() {
	int sz = q.size();
	for (int i = 0; i < sz; ++i) {
		auto now = q.front();
		q.pop();
		int x = now.x;
		int y = now.y;
		now.timer -= 1;

		if (now.timer == 0) {
			a[y][x] = '.';
			for (int k = 0; k < 4; ++k) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (safe(nx, ny)) {
					a[ny][nx] = '.';
				}
			}
			continue;
		}
		if (a[y][x] == '.') {
			continue;
		}
		q.push(now);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c >> n;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 'O') {
				q.push({ i,j ,3 });
			}
		}
	}

	for (int t = 1; t <= n; ++t) {
		if (t == 1) {
			run();
			for (int i = 0; i < r; ++i) {
				for (int j = 0; j < c; ++j) {
					cout << a[i][j];
				}
				cout << '\n';
			}
			cout << '\n';

			continue;
		}
		switch (t % 2)
		{
		case 0:
			run();
			setup();
			break;
		case 1:
			boom();
			break;
		}
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				cout << a[i][j];
			}
			cout << '\n';
		}
		cout << '\n';

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
//char a[N][N];
//int timer[N][N];
//int r, c, n;
//
//int dx[] = { 0,0,-1,1 };
//int dy[] = { -1,1,0,0 };
//void run() {
//	for (int i = 0; i < r; ++i) {
//		for (int j = 0; j < c; ++j) {
//			if (a[i][j] == 'O') {
//				timer[i][j] -= 1;
//			}
//		}
//	}
//}
//void setup() {
//	for (int i = 0; i < r; ++i) {
//		for (int j = 0; j < c; ++j) {
//			if (a[i][j] == '.') {
//				a[i][j] = 'O';
//				timer[i][j] = 3;
//			}
//		}
//	}
//}
//bool safe(int x, int y) {
//	return(x >= 0 && x < c&&y >= 0 && y < r);
//}
//void boom() {
//	for (int i = 0; i < r; ++i) {
//		for (int j = 0; j < c; ++j) {
//			if (a[i][j] == 'O') {
//				timer[i][j] -= 1;
//			}
//			if(timer[i][j]==0&&a[i][j]=='O'){
//				a[i][j] = '.';
//				for (int k = 0; k < 4; ++k) {
//					int nx = j + dx[k];
//					int ny = i + dy[k];
//					if (safe(nx, ny)) {
//						a[ny][nx] = '.';
//						timer[ny][nx] = 0;
//					}
//				}
//			}
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
//				timer[i][j] = 3;
//			}
//		}
//	}
//
//	for (int t = 1; t <= n; ++t) {
//		if (t == 1) {
//			run();
//			continue;
//		}
//		if (t % 2) {
//			boom();
//		}
//		else {
//			run();
//			setup();
//		}
//	}
//
//	for (int i = 0; i < r; ++i) {
//		for (int j = 0; j < c; ++j) {
//			cout << a[i][j];
//		}
//		cout << '\n';
//	}
//	return 0;
//}
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
//				q.push({ i,j ,3});
//			}
//		}
//	}
//
//	for (int t = 1; t <= n; ++t) {
//		if (t == 1) {
//			run();
//			continue;
//		}
//		switch (t%2)
//		{
//		case 0:
//			run();
//			setup();
//			break;
//		case 1:
//			boom();
//			break;
//		}
//	}
//
//	for (int i = 0; i < r; ++i) {
//		for (int j = 0; j < c; ++j) {
//			cout << a[i][j];
//		}
//		cout << '\n';
//	}
//	return 0;
//}