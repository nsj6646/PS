#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(),v.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].second - i > ans) {
			ans = v[i].second - i;
		}
	}
	cout << ans + 1;
	return 0;
}
/*
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> a(n);
	for (int i = 0; i<n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i; // original
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i<n; i++) {
		// original - changed
		if (ans < a[i].second - i) {
			ans = a[i].second - i;
		}
	}
	printf("%d\n", ans + 1);
	return 0;
}
*/