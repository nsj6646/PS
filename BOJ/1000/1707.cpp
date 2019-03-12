#include <iostream>
#include <vector>
using namespace std;

void dfs(int x,int color);
int check[20001];
vector<int> a[20001];
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int v, e;
		cin >> v >> e;
		for (int i = 1; i <= v; i++) {
			a[i].clear();
			check[i] = 0;
		}
		for (int i = 0; i < e; i++) {
			int x, y;
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		for (int i = 1; i <= v; i++) {
			if (check[i] == 0) {
				dfs(i, 1);
			}
		}
		bool ok = true;
		for (int i = 1; i <= v; i++) {
			for (int j = 0; j < a[i].size(); j++) {
				if (check[i] == check[a[i][j]]) {
					ok = false;
				}
			}
		}
		ok ? cout << "YES\n" : cout << "NO\n";
	}
	
	return 0;
}
void dfs(int x, int color) {
	check[x] = color;
	for (int i = 0; i < a[x].size(); i++) {
		if (check[a[x][i]] == 0) {
			dfs(a[x][i], 3 - color);
		}
	}
}
/*
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector<int> a[20001];
int color[20001];
void dfs(int node, int c) {
	color[node] = c;
	for (int i = 0; i<a[node].size(); i++) {
		int next = a[node][i];
		if (color[next] == 0) {
			dfs(next, 3 - c);
		}
	}
}
int main() {
	int t;
	scanf("%d\n", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			a[i].clear();
			color[i] = 0;
		}
		for (int i = 0; i<m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for (int i = 1; i <= n; i++) {
			if (color[i] == 0) {
				dfs(i, 1);
			}
		}
		bool ok = true;
		for (int i = 1; i <= n; i++) {
			for (int k = 0; k<a[i].size(); k++) {
				int j = a[i][k];
				if (color[i] == color[j]) {
					ok = false;
				}
			}
		}
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}
*/