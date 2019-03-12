#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define N 10001
using namespace std;

int work[N];
vector<int> a[N];
int ind[N];
int dp[N];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int x = 1; x <= n; x++) {
		int m;
		cin >> work[x] >> m;
		for (int i = 0; i < m; i++) {
			int y;
			cin >> y;
			a[y].push_back(x);
			ind[x] += 1;
		}
		
		
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(i);
			dp[i] = work[i];
		}
	}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			ind[y] -= 1;

			dp[y] = max(dp[y], dp[x] + work[y]);
			if (ind[y] == 0) {			
				q.push(y);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}