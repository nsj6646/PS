#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef pair<int, int> edge;
int parent[100005];
int cnt[100005];

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
	cnt[x] += cnt[y];
	parent[y] = x;
	return true;
}
unordered_map<string, int> dict;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		dict.clear();
		memset(cnt, 0, sizeof(cnt));
		int f;
		cin >> f;
		int n = 1;
		for (int i = 0; i < f; ++i) {
			string a, b;
			cin >> a >> b;
			if (dict.count(a) == 0) {
				dict[a] = n;
				cnt[n] = 1;
				parent[n] = n++;
			}
			if (dict.count(b) == 0) {
				dict[b] = n;
				cnt[n] = 1;
				parent[n] = n++;
			}
			if (Union(dict[a], dict[b])) {
				cout << cnt[Find(dict[a])] << '\n';
			}
		}
	}
	return 0;
}