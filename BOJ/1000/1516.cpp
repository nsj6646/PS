#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define N 501
using namespace std;

typedef pair<int, int> bt;		//건설시간, 건물번호
int ind[N];
vector<int> a[N];
bt build[N];	
int dp[N];
int main()
{
	int n;
	cin>>n;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		build[i] = { -t,i };		//최소힙을 위해 -붙임
		while (true) {
			int j;
			cin >> j;
			if (j == -1)break;
			ind[i] += 1;
			a[j].push_back(i);
		}
	}

	priority_queue<bt> q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(build[i]);
			dp[i] = -build[i].first;
		}
	}

	while (!q.empty()) {
		bt x = q.top();
		q.pop();
		for (int i = 0; i < a[x.second].size(); i++) {
			int y = a[x.second][i];
			ind[y] -= 1;
			if (ind[y] == 0) {
				dp[y] = max(dp[y], dp[x.second] + -build[y].first);
				build[y] = { -dp[y],y };
				q.push(build[y]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << dp[i] << '\n';
	}
	return 0;
}