#include <iostream>
#include <vector>
#include <algorithm>
using namespace	std;
#define N 21
#define INFI 0x7fffffff
vector<int> start;
bool check[21];
vector<int> link;

int n;
int a[N][N];
int ans = INFI;
int calc() {
	int st = 0;
	for (int i = 0; i < start.size(); i++) {
		for (int j = 0; j < start.size(); j++) {
			st += a[start[i]][start[j]];
		}
	}

	int lt = 0;
	for (int i = 0; i < link.size(); i++) {
		for (int j = 0; j < link.size(); j++) {
			lt += a[link[i]][link[j]];
		}
	}
	return abs(st - lt);
}
void dfs(int idx, int cnt) {
	if (cnt == n / 2) {
		for (int i = 1; i <= n; i++) {
			if (!check[i]) {
				link.push_back(i);
			}
		}

		/*°è»ê*/
		ans = min(ans, calc());
		if (ans == 0) {
			cout << 0;
			exit(0);
		}
		link.clear();
		return;
	}
	for (int i = idx; i <= n; i++) {
		start.push_back(i);
		check[i] = true;
		dfs(i + 1, cnt + 1);
		check[i] = false;
		start.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	dfs(1, 0);

	cout << ans;
	return 0;
}