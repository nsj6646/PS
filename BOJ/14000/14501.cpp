#define MAX(x,y)	(x)>(y)?(x):(y)
#include <cstdio>

int dp[21];
int t[16];
int p[16];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &t[i], &p[i]);
	}
	for (int i = 1; i <= n+1; ++i) {
		for (int j = i + t[i]; j <= n+1; ++j) {
			dp[j] = MAX(dp[j], dp[i] + p[i]);
		}
	}
	printf("%d", dp[n + 1]);
	return 0;
}