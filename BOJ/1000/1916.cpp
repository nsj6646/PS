#include <bits/stdc++.h>
using namespace std;


vector<pair<int, int>> adj[1001];
int n, m;
priority_queue<pair<int, int>> pq;
int dist[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].emplace_back(w, y);
	}

	int s, e;
	cin >> s >> e;
	memset(dist, -1, sizeof(dist));

	dist[s] = 0;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int now = pq.top().second;
		int d = -pq.top().first;
		pq.pop();
		if (d > dist[now]) continue;
		for (int i = 0; i < adj[now].size(); ++i) {
			int next = adj[now][i].second;
			int nd = d+adj[now][i].first;
			if (dist[next] == -1 || dist[next] > nd) {
				dist[next] = nd;
				pq.push({ -nd,next });
			}
		}
	}
	cout << dist[e];
	return 0;
}