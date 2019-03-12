#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> matrix;
matrix a[501];
int dp[501][501];
int mul_matrix(int i, int j) {
	if (i == j) return 0;
	if (i + 1 == j) {
		return dp[i][j]=a[i].first*a[i].second*a[j].second;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	int &ans = dp[i][j];
	for (int k = i; k <= j - 1; k++) {
		int temp = mul_matrix(i, k) + mul_matrix(k+1, j) + a[i].first*a[k].second*a[j].second;
		if (ans == -1 || ans > temp) {
			ans = temp;
		}
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		int r, c;
		cin >> r >> c;
		a[i] = make_pair(r, c);
	}
	cout << mul_matrix(1, n);
	return 0;
}