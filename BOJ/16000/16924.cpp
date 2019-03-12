#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[101][101];
int state[101][101];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool check(int x,int y,int s) {
	for (int d = 0; d < 4; ++d) {
		int nx = x + dx[d] * s;
		int ny = y + dy[d] * s;
		if (nx<1 || nx>n || ny<1 || ny>m) return false;
		if (a[nx][ny] != '*') return false;
	}
	state[x][y] = 0;
	for (int d = 0; d < 4; ++d) {
		int nx = x + dx[d] * s;
		int ny = y + dy[d] * s;
		state[nx][ny] = 0;
	}
	return true;
}

bool ispossible() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (state[i][j] == 1) return false;
		}
	}
	return true;
}

vector<tuple<int, int, int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			if (a[i][j] == '*') {
				state[i][j] = 1;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == '*') {
				int k = 1;
				while (check(i, j, k)) {
					v.emplace_back(i, j, k);
					k += 1;
				}
			}
		}
	}

	if (ispossible()) {
		cout << v.size() << '\n';
		for (int i = 0; i < v.size(); ++i) {
			cout << get<0>(v[i]) << ' ' << get<1>(v[i]) << ' ' << get<2>(v[i]) << '\n';
		}
	}
	else {
		cout << -1;
	}
	return 0;
}