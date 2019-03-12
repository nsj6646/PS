#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> edge;
int n, m;
int parent[1005];
vector<edge> v;

int Find(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = Find(parent[x]);
}
bool Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) {
		return false;
	}
	parent[y] = x;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		v.emplace_back(c, a, b);
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
	}

	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < m; ++i) {
		int w = get<0>(v[i]);
		int x = get<1>(v[i]);
		int y = get<2>(v[i]);
		if (Union(x, y)) {
			cnt++;
			ans += w;
		}
		if (cnt == n - 1) {
			break;
		}
	}
	cout << ans;
	return 0;
}