#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001];
int a[101];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i <= k; i++) {
		dp[i] = -1;
	}
	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j - a[i] >= 0 && dp[j - a[i]] != -1) {
				if (dp[j] == -1 || dp[j] > dp[j - a[i]] + 1) {
					dp[j] = dp[j - a[i]] + 1;
				}
			}
		}
	}
	cout << dp[k];
	return 0;
}