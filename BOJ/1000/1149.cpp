#include <iostream>
#include <algorithm>
#define N 1001
using namespace std;

int n;
int a[N][3];
int dp[N][3];
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			dp[i][0] = a[i][0];
			dp[i][1] = a[i][1];
			dp[i][2] = a[i][2];
			continue;
		}
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + a[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + a[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + a[i][2];
	}
	int ans = min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
	cout << ans;
	return 0;
}