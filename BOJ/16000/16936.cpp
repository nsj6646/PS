#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int n;
ull a[100];
bool visited[100];
void dfs(vector<ull> &v, int cnt) {
	if (cnt == n) {
		for (int i = 0; i < n; ++i) {
			cout << v[i] << ' ';
		}
		exit(0);
	}

	for (int i = 0; i < n; ++i) {
		if (visited[i]) continue;
		if (v.back() * 2 == a[i] || (v.back() % 3 == 0 && v.back() / 3 == a[i])) {
			v.push_back(a[i]);
			visited[i] = true;
			dfs(v, cnt + 1);
			v.pop_back();
			visited[i] = false;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<ull> v;
	for (int i = 0; i < n; ++i) {
		v.push_back(a[i]);
		visited[i] = true;
		dfs(v, 1);
		v.pop_back();
		visited[i] = false;
	}
	return 0;
}