#define N		500005
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
ull a[N];
ull psum[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		psum[i] = psum[i - 1] + a[i];
	}

	ull ans = 0;
	int l = 0, r = n - 1;
	while (l < r) {
		if (a[l] < a[r]) {
			ans += a[l] * (psum[r] - psum[l]);
			l++;
		}
		else {
			ans += a[r] * (psum[r - 1] - psum[l - 1]);
			r--;
		}
	}
	cout << ans;
	return 0;
}