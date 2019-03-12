#include <bits/stdc++.h>
using namespace std;

int a[101];
int trick[101];
bool visited[101];
int n, m;
queue<int> q;
int ans;
void bfs() {
	q.push(1);
	visited[1] = true;
	while (!q.empty()) {
		ans += 1;
		int sz = q.size();
		while (sz--) {
			int x = q.front();
			q.pop();
			if (x == 100) return;

			for (int i = 1; i <= 6; ++i) {
				int nx = x + i;
				if (nx <= 100 && !visited[nx]) {
					visited[nx] = true;
					if (trick[nx]) {
						nx = trick[nx];
						visited[nx] = true;
						q.push(nx);
						continue;
					}
					q.push(nx);
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 1; i <= 100; ++i) {
		a[i] = i;
	}
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		trick[x] = y;
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		trick[u] = v;
	}

	bfs();
	cout << ans-1;
	return 0;
}