#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> l[1001];
void dfs(int x);
void bfs(int x);
bool check[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m, v;
	cin >> n >> m >> v;
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		l[a].push_back(b);
		l[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(l[i].begin(), l[i].end());
	}
	
	dfs(v);
	cout << '\n';
	memset(check, false, 1001);
	bfs(v);
	return 0;
}
void dfs(int x) {
	check[x] = true;
	cout << x << ' ';
	for (int i = 0; i < l[x].size(); i++) {
		if (!check[l[x][i]]) {
			dfs(l[x][i]);
		}
	}
}
void bfs(int x) {
	queue<int> q;	
	check[x] = true;
	q.push(x);
	while (!q.empty()) {
		int x = q.front();	
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < l[x].size(); i++) {
			if (!check[l[x][i]]) {			
				check[l[x][i]] = true;
				q.push(l[x][i]);
			}
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
vector<int> a[1001];
bool check[1001];
void dfs(int node) {
	check[node] = true;
	printf("%d ", node);
	for (int i = 0; i<a[node].size(); i++) {
		int next = a[node][i];
		if (check[next] == false) {
			dfs(next);
		}
	}
}
void bfs(int start) {
	queue<int> q;
	memset(check, false, sizeof(check));
	check[start] = true;
	q.push(start);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		printf("%d ", node);
		for (int i = 0; i<a[node].size(); i++) {
			int next = a[node][i];
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}
int main() {
	int n, m, start;
	scanf("%d %d %d", &n, &m, &start);
	for (int i = 0; i<m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}
	dfs(start);
	puts("");
	bfs(start);
	puts("");
	return 0;
}
*/