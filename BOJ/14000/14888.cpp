#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n;
int a[11];
int ansMin = INF;
int ansMax = -INF;
int cnt[4];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> v;
	for (int i = 1; i <= 4; ++i) {
		int op;
		cin >> op;
		for (int j = 0; j < op; ++j) {
			v.push_back(i);
		}
	}
	sort(v.begin(), v.end());
	do {
		int sum = a[0];
		for (int i = 0; i < v.size(); ++i) {
			switch (v[i]) {
			case 1:sum += a[i + 1]; break;
			case 2:sum -= a[i + 1]; break;
			case 3:sum *= a[i + 1]; break;
			case 4:sum /= a[i + 1]; break;
			}
		}
		ansMax = max(ansMax, sum);
		ansMin = min(ansMin, sum);
	} while (next_permutation(v.begin(), v.end()));
	cout << ansMax << '\n' << ansMin;
	return 0;
}