#define N		1000
#include <bits/stdc++.h>
using namespace std;

int a[N];
int n, k;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = 1001;
	for (int a1 = 1; a1 <= N; ++a1) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			cout << a1 + i * k << ' ';

			if (a1 + i * k != a[i]) {
				cnt++;
			}
		}
		cout << '\n';
		ans = min(ans, cnt);
	}
	cout << ans;
	return 0;
}