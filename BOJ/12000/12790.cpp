#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int c[4], e[4];
		for (int i = 0; i < 4; i++) {
			cin >> c[i];
		}
		for (int i = 0; i < 4; i++) {
			cin >> e[i];
		}
		int w[4] = { 1,5,2,2 };
		int ans = 0;
		for (int i = 0; i < 2; i++) {
			ans += w[i] * ((c[i] + e[i]) < 1 ? 1 : c[i] + e[i]);
		}
		ans += w[2] * ((c[2] + e[2]) < 0 ? 0 : c[2] + e[2]);
		ans += w[3] * (c[3] + e[3]);
		cout << ans << '\n';
	}
	return 0;
}