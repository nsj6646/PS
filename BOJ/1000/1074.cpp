#include <iostream>

using namespace std;

int n, r, c;
int ans;
void solve(int n, int x, int y) {
	if (x == c && y == r) {
		return;
	}
	int m = n / 2;
	int w = n * n / 4;
	if (c < x+m&&r<y+m) {
		solve(m, x, y);
	}
	else if (c >= x + m && r < y + m) {
		ans += w;
		solve(m, x + m, y);
	}
	else if (c < x + m && r >= y + m) {
		ans += 2 * w;
		solve(m, x, y+m);
	}
	else if (c >= x + m && r >= y + m) {
		ans += 3 * w;
		solve(m, x + m, y+m);
	}
}
int main()
{
	cin >> n >> r >> c;
	n = 1<<n;
	solve(n, 0, 0);
	cout << ans;
	return 0;
}