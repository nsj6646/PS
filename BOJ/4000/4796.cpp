#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int l, p, v;

	int tc = 1;
	int ans;
	while (true) {
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0) {
			break;
		}
		int k = v / p;
		int d = v % p;
		ans = k * l;
		ans += d > l ? l : d;
		cout << "Case " << tc << ": " << ans << '\n';
		tc += 1;
	}
	return 0;
}
