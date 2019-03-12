#include <iostream>
#include <cstring>
using namespace std;

int a[501][501];
int dp[501][501];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n, m;

int go(int x, int y) {
	if (x == m && y == n) {
		return 1;
	}
	if (dp[x][y]!=-1) {
		return dp[x][y];
	}
	dp[x][y] = 0;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 1 && nx <= m && ny >= 1 && ny <= n && a[nx][ny] < a[x][y]) {
			dp[x][y] += go(nx, ny); 
		}
	}
	return dp[x][y];
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << go(1, 1);

}