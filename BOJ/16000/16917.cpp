#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, x, y;
	int ans = 0;
	cin >> a >> b >> c >> x >> y;
	if (a + b > 2 * c) {
		int m = min(x, y);
		ans += m * 2 * c;
		x -= m;
		y -= m;
		if (x) {
			ans += (a > 2 * c) ? 2 * c*x : a * x;
		}
		else {
			ans += (b > 2 * c) ? 2 * c*y : b * y;
		}
	}
	else {
		ans = a * x + b * y;
	}
	cout<<ans;
	return 0;
}