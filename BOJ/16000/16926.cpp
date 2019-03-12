#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> point;
int n, m, r;
int a[300][300];
point p[151];
queue<int> q[151];

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

void find_start(int &x,int &y,int cnt, int l,int &d,int k) {
	int nx;
	int ny;
	for (int i = 0; i < l; ++i) {
		nx = x + dx[d];
		ny = y + dy[d];
		if (nx < k || nx >= m - k || ny < k || ny >= n - k) {
			d = (d + 1) % 4;
			nx = x + dx[d];
			ny = y + dy[d];
		}
		x = nx;
		y = ny;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> r;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	int depth = min(n, m) / 2;
	for (int k = 0; k < depth; ++k) {
		for (int i = k; i < m - k - 1; ++i) {
			q[k].push(a[k][i]);
		}
		for (int i = k; i < n - k - 1; ++i) {
			q[k].push(a[i][m - 1 - k]);
		}
		for (int i = k; i < m - k - 1; ++i) {
			q[k].push(a[n - 1 - k][m - 1 - i]);
		}
		for (int i = k; i < n - k - 1; ++i) {
			q[k].push(a[n - 1 - i][k]);
		}
	}

	for (int k = 0; k < depth; ++k) {
		int l = r % q[k].size();
		int x = k, y = k;
		int d = 0;
		find_start(x,y,0, l, d,k);
		d = (d + 2) % 4;
		while (!q[k].empty()) {
			a[y][x] = q[k].front();
			q[k].pop();
			
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < k || nx >= m - k || ny < k || ny >= n - k) {
				d = (d + 3) % 4;
				nx = x + dx[d];
				ny = y + dy[d];
			}
			x = nx;
			y = ny;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}