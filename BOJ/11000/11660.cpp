#define N		1025
#define M		100000
#include <cstdio>

int dp[N][N];
int n, m;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int x;
			scanf("%d", &x);
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + x;
		}
	}

	for (int q = 1; q <= m; ++q) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1]);
	}


	return 0;
}