#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> a[100001];
int dist[100001];
bool check[100001];
void dfs(int x, int y);
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n-1; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		a[x].push_back({ y,z });
		a[y].push_back({ x,z });
	}
	dfs(1, 0);
	int v = 1;
	for (int i = 2; i <= n; i++) {
		if (dist[v] < dist[i]) {
			v = i;
		}
	}
	memset(dist, 0, sizeof(dist));
	memset(check, false, sizeof(check));
	dfs(v, 0);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < dist[i]) {
			ans = dist[i];
		}
	}
	printf("%d", ans);
	return 0;
}
void dfs(int x, int y) {
	if (check[x]) {
		return;
	}
	check[x] = true;
	dist[x] = y;
	for (int i = 0; i < a[x].size(); i++) {
		if (!check[a[x][i].first]) {
			dfs(a[x][i].first, a[x][i].second + y);
		}
	}
}