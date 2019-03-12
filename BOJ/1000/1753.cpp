#define N	20001
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<pair<int, int>> adj[N];
priority_queue<pair<int, int>> pq;
int dist[N];
void shortest_path() {
	memset(dist, -1, sizeof(dist));
	pq.push({ 0,k });
	while (!pq.empty()) {
		auto now = pq.top();
		int d = -now.first;
		int x = now.second;
		pq.pop();
		if (dist[x]!=-1&&dist[x] < d) continue;
		for (auto &y : adj[x]) {
			int nx = d + y.second;
			if (dist[y.first]==-1||nx < dist[y.first]) {
				dist[y.first] = nx;
				pq.push({ -nx,y.first });
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v,w });
	}
	shortest_path();

	for (int i = 1; i <= n; ++i) {
		if (i == k) {
			cout << "0\n";
			continue;
		}
		int ans = dist[i];
		if (ans == -1) {
			cout << "INF\n";
			continue;
		}
		cout << ans << '\n';
	}
	return 0;
}