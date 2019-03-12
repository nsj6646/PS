#include <iostream>
using namespace std;

int parent[1000001];
int Find(int x) {
	if (x == parent[x]) {
		return x;
	}
	else {
		return parent[x] = Find(parent[x]);
	}
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		parent[y] = x;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int cmd, a, b;
		cin >> cmd >> a >> b;
		if (cmd == 0) {
			Union(a, b);
		}
		else {
			if (Find(a) == Find(b)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
	return 0;
}