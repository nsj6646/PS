#define MOD		10007
#include <cstdio>

int dp[1001][1001];

int combi(int n, int k) {
	if (n==1||n == k || k == 0) {
		return 1;
	}
	if (dp[n][k]) {
		return dp[n][k]%MOD;
	}
	return dp[n][k] = (combi(n - 1, k - 1)%MOD + combi(n - 1, k) % MOD) % MOD;
}
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", combi(n, k));
	return 0;
}