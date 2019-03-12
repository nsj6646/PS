#include <bits/stdc++.h>
using namespace std;

char a[10][11];

bool solve(int x, int y) {
	int cnt;
	int i, j;
	//세로
	cnt = 1;
	i = x - 1, j = x + 1;
	while (i >= 0 && a[i][y] == 'X') {
		cnt++;
		i--;
	}
	while (j < 10 && a[j][y] == 'X') {
		cnt++;
		j++;
	}
	if (cnt >= 5) {
		return true;
	}
	//가로
	cnt = 1;
	i = y - 1, j = y + 1;
	while (i >= 0 && a[x][i] == 'X') {
		cnt++;
		i--;
	}
	while (j < 10 && a[x][j] == 'X') {
		cnt++;
		j++;
	}
	if (cnt >= 5) {
		return true;
	}
	//좌상우하대각선
	cnt = 1;
	i = x - 1, j = y - 1;
	while (i >= 0 && j >= 0 && a[i][j] == 'X') {
		cnt++;
		i--; j--;
	}
	i = x + 1, j = y + 1;
	while (i < 10 && j < 10 && a[i][j] == 'X') {
		cnt++;
		i++; j++;
	}
	if (cnt >= 5) {
		return true;
	}
	//우상좌하대각선
	cnt = 1;
	i = x + 1, j = y - 1;
	while (i < 10 && j >= 0 && a[i][j] == 'X') {
		cnt++;
		i++; j--;
	}
	i = x - 1, j = y + 1;
	while (i >= 0 && j < 10 && a[i][j] == 'X') {
		cnt++;
		i--; j++;
	}
	if (cnt >= 5) {
		return true;
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 10; ++i) {
		cin >> a[i];
	}
	bool res = false;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (a[i][j] == '.') {
				res = solve(i, j);
				if (res) {
					cout << 1;
					return 0;
				}
			}
		}
	}
	cout << 0;
	return 0;
}