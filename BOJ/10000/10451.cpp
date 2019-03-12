#include <iostream>
using namespace std;

bool check[1001];
int a[1001];
void dfs(int x) {
	if (check[x]) {
		return;
	}
	check[x] = true;
	dfs(a[x]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			check[i] = false;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!check[i]) {
				dfs(i);
				cnt += 1;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}