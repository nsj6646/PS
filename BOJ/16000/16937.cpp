#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[105];

int h, w, n;
int ans;
int x[2], y[2];

void dfs(vector<pair<int, int>> &v, int idx,int cnt) {
	if (cnt == 2) {
		int area;
		for (int i = 0; i < 2; ++i) {
			x[i] = v[i].first;
			y[i] = v[i].second;
		}
		for (int i = 0; i < 4; ++i) {
			switch (i) {
			case 1:	swap(x[1], y[1]); break;
			case 2:swap(x[0], y[0]); break;
			case 3:swap(x[1], y[1]); break;
			}
			if (x[0] <= h && x[1] <= h && y[0] + y[1] <= w) {
				area = x[0] * y[0] + x[1] * y[1];
				ans = max(ans, area);
			}
			if (x[0] + x[1] <= h && y[0] <= w && y[1] <= w) {
				area = x[0] * y[0] + x[1] * y[1];
				ans = max(ans, area);
			}
		}
		return;
	}
	for (int i = idx; i < n; ++i) {
		v.push_back(a[i]);
		dfs(v, i+1, v.size());
		v.pop_back();
	}
	
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> h >> w >> n;

	for (int i = 0; i < n; ++i) {
		int r, c;
		cin >> r >> c;
		a[i] = { r,c };
	}

	vector<pair<int, int>> v;
	dfs(v, 0, 0);
	cout << ans;
	return 0;
}