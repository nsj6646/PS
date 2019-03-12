#include <cstdio>

int a[301][301];
int dp[301][301];
int n, m, k;
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] + a[i][j] - dp[i - 1][j - 1];
		}
	}

	scanf("%d", &k);
	while (k--) {
		int i, j, x, y;
		scanf("%d %d %d %d", &i, &j, &x, &y);
		printf("%d\n",dp[x][y] - dp[i - 1][y] - dp[x][j - 1] + dp[i - 1][j - 1]);
	}
	return 0;
}