#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	map<long long, int> m;
	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		m[num] += 1;
	}
	int most = 0;
	long long ans;
	for (auto &x : m) {
		if (x.second > most) {
			most = x.second;
			ans = x.first;
		}
		else if (x.second == most && x.first < ans) {
			ans = x.first;
		}
	}
	cout << ans;
	return 0;
}
/*(sort)
#include <cstdio>
#include <algorithm>
using namespace std;
long long a[1000000];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a, a + n);
	long long ans = a[0];
	int ans_cnt = 1;
	int cnt = 1;
	for (int i = 1; i<n; i++) {
		if (a[i] == a[i - 1]) {
			cnt += 1;
		}
		else {
			cnt = 1;
		}
		if (ans_cnt < cnt) {
			ans_cnt = cnt;
			ans = a[i];
		}
	}
	printf("%lld\n", ans);
	return 0;
}
*/