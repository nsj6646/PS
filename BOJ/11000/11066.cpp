#include <iostream>
#include <cstring>
using namespace std;

int a[501];
int s[501];
int dp[501][501];
int merge_file(int i, int j) {
	if (i == j) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	int &ans = dp[i][j];
	for (int k = i; k <= j - 1; k++) {
		int temp = merge_file(i, k) + merge_file(k + 1, j) + s[j] - s[i - 1];
		if (ans == -1 || ans > temp) {
			ans = temp;
		}
	}
	return ans;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		memset(dp, -1, sizeof(dp));
		memset(s, 0, sizeof(s)); 
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			s[i] = s[i - 1] + a[i];
		}
		cout << merge_file(1, n) << '\n';
	}

	return 0;
}