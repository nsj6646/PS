#include <cstdio>
#include <algorithm>
using namespace std;
int a[50001];
int dp[4][50001];
int n, m;
int ans;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		a[i] = a[i - 1] + x;
	}
	scanf("%d", &m);

	for (int i = 1; i <= 3; i++) {
		for (int j = i*m; j <= n; j++) {
			dp[i][j]=max(dp[i][j-1],)
		}
	}
	printf("%d", ans);
	return 0;
}