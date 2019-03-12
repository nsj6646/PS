#include <iostream>
#include <algorithm>
using namespace std;
#define N 501

int n;
int a[N][N];
int dp[N][N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	dp[1][1] = a[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				dp[i][j] = dp[i - 1][j] + a[i][j];
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j-1] + a[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j-1],dp[i-1][j])+a[i][j];
			}
		}
	}
	int ans = dp[n][1];
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[n][i]);
	}
	cout << ans;
	return 0;
}