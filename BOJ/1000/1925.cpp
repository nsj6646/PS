#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool visited[10001];
int cnt;
int most;
void dfs(vector<vector<int>> &a,int v) {
	for (int i = 0; i<a[v].size(); i++) {
		if (!visited[a[v][i]]) {
			cnt += 1;
			visited[a[v][i]] = true;
			dfs(a, a[v][i]);
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n + 1);
	for (int i = 0; i < m; i++) {
		int v, w;
		cin >> v >> w;
		a[w].push_back(v);	
	}
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(bool)*(n + 1));
		cnt = 1;
		visited[i] = true;
		dfs(a, i);
		if (cnt > most) {
			ans.clear();
			ans.push_back(i);
			most = cnt;
		}
		else if (cnt == most) {
			ans.push_back(i);
			most = cnt;
		}
	}
	for (int x : ans) {
		cout << x << ' ';
	}
	return 0;
}