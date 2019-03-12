#include <iostream>
#include <algorithm>

#define N 16
#define INFI 16000000

using namespace std;


int a[N][N];
int dp[N][1<<N];

int n;

int dfs(int i, int visited) {
	if (visited == (1 << n) - 1) {
		return a[i][0] != 0 ? a[i][0] : INFI;
	}
	if (dp[i][visited] != 0) {
		return dp[i][visited];
	}
	int ans = INFI;
	for (int j = 1; j < n; j++) {
		if (a[i][j] != 0 && !(visited&(1 << j))) {
			ans = min(ans, dfs(j, visited | (1 << j)) + a[i][j]);
		}
	}
	dp[i][visited] = ans;
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	
	cout<<dfs(0, 1);
	return 0;
}