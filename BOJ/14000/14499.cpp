#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[20][20];
int dice[4][3];	//À­¸é:1,1 ¹Ù´Ú¸é:1,3
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };
void f() {}
void east() {
	int temp = dice[1][1];
	dice[1][1] = dice[1][0];
	dice[1][0] = dice[3][1];
	dice[3][1] = dice[1][2];
	dice[1][2] = temp;
}
void west() {
	int temp = dice[1][1];
	dice[1][1] = dice[1][2];
	dice[1][2] = dice[3][1];
	dice[3][1] = dice[1][0];
	dice[1][0] = temp;
}
void north() {
	int temp = dice[0][1];
	for (int i = 0; i < 3; ++i) {
		dice[i][1] = dice[i+1][1];
	}
	dice[3][1] = temp;
}
void south() {
	int temp = dice[3][1];
	for (int i = 0; i < 3; ++i) {
		dice[3 - i][1] = dice[2 - i][1];
	}
	dice[0][1] = temp;
}
void (*fp[5])() = { f,east,west,north,south };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x,y,k;
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < k; ++i) {
		int d;
		cin >> d;
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx >= 0 && nx < n&&ny >= 0 && ny < m) {
			fp[d]();
			cout << dice[1][1] << '\n';
			if (a[nx][ny]) {
				dice[3][1] = a[nx][ny];
				a[nx][ny] = 0;
			}
			else {
				a[nx][ny] = dice[3][1];
			}
			x = nx;
			y = ny;
		}
	}


	return 0;
}
